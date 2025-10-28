import requests
import json

BASE_URL = "https://7zszxecwra.execute-api.ap-northeast-2.amazonaws.com/api/"  # 실제 시험 시 API 엔드포인트로 변경
TOKEN = "bf9105602703003d1e5c8bd1"

HEADERS = {
    "X-Auth-Token": TOKEN,
    "Content-Type": "application/json"
}


# -------------------------------
# 시나리오 관리 (API 호출 모듈)
# -------------------------------
class Scenario:
    def __init__(self, problem: int):
        self.problem = problem
        self.auth_key = None

    def start(self):
        url = f"{BASE_URL}/start"
        res = requests.post(url, headers=HEADERS, json={"problem": self.problem})
        res_json = res.json()
        self.auth_key = res_json["auth_key"]
        print(f"[START] problem={self.problem}, auth_key={self.auth_key}")
        return res_json

    def new_requests(self):
        url = f"{BASE_URL}/new_requests"
        res = requests.get(url, headers={"Authorization": self.auth_key})
        return res.json()["reservations_info"]

    def reply(self, replies):
        url = f"{BASE_URL}/reply"
        body = {"replies": replies}
        res = requests.post(url, headers={"Authorization": self.auth_key}, json=body)
        return res.json()

    def simulate(self, assigns):
        url = f"{BASE_URL}/simulate"
        body = {"room_assign": assigns}
        res = requests.put(url, headers={"Authorization": self.auth_key}, json=body)
        return res.json()

    def score(self):
        url = f"{BASE_URL}/score"
        res = requests.get(url, headers={"Authorization": self.auth_key})
        return res.json()


# -------------------------------
# 호텔 객실 관리 (배정 알고리즘)
# -------------------------------
class MotelManager:
    def __init__(self, floors, rooms_per_floor):
        self.floors = floors
        self.rooms_per_floor = rooms_per_floor
        # 각 층별 빈 객실 구간 리스트
        self.free_segments = {
            floor: [(1, rooms_per_floor)] for floor in range(1, floors + 1)
        }
        self.allocations = {}  # id -> (floor, start, count, checkout_day)

    def can_assign(self, rooms_needed):
        """배정 가능한 층과 시작 위치를 찾는다"""
        for floor in range(1, self.floors + 1):
            for idx, (start, end) in enumerate(self.free_segments[floor]):
                if end - start + 1 >= rooms_needed:
                    return floor, idx, start
        return None

    def assign(self, req_id, rooms_needed, checkout_day):
        """객실 배정"""
        found = self.can_assign(rooms_needed)
        if not found:
            return False

        floor, idx, start = found
        start_seg, end_seg = self.free_segments[floor][idx]
        new_start = start + rooms_needed

        # 세그먼트 업데이트
        if new_start <= end_seg:
            self.free_segments[floor][idx] = (new_start, end_seg)
        else:
            self.free_segments[floor].pop(idx)

        # 예약 정보 저장
        self.allocations[req_id] = (floor, start, rooms_needed, checkout_day)
        return True

    def checkout(self, today):
        """오늘 체크아웃하는 손님 반납 처리"""
        finished = []
        for req_id, (floor, start, cnt, checkout_day) in self.allocations.items():
            if checkout_day == today:
                finished.append(req_id)
                segs = self.free_segments[floor]
                segs.append((start, start + cnt - 1))
                segs.sort()
                merged = []
                cur_s, cur_e = segs[0]
                for s, e in segs[1:]:
                    if s == cur_e + 1:
                        cur_e = e
                    else:
                        merged.append((cur_s, cur_e))
                        cur_s, cur_e = s, e
                merged.append((cur_s, cur_e))
                self.free_segments[floor] = merged
        for rid in finished:
            del self.allocations[rid]

    def get_room_number(self, floor, start_idx):
        """층과 시작 인덱스로 객실번호 계산 (예: 3층 5호 → 305)"""
        return floor * 1000 + start_idx


# -------------------------------
# 메인 시뮬레이션
# -------------------------------
def main():
    # 시나리오 선택 (1 또는 2)
    scenario = Scenario(problem=1)
    info = scenario.start()

    motel = MotelManager(floors=3, rooms_per_floor=20)

    # 전체 날짜 시뮬레이션
    for day in range(1, 201):  # 실제 시험에서는 end_day 정보로 반복
        print(f"\n=== Day {day} ===")
        motel.checkout(day)

        # 1️⃣ 새로운 요청 받기
        new_req = scenario.new_requests()
        if not new_req:
            print("No new requests today")
            continue

        # 2️⃣ 우선순위 정렬 (객실 많은 요청 우선)
        new_req.sort(key=lambda x: -x["amount"])

        replies = []
        today_assigns = []

        for req in new_req:
            rid = req["id"]
            amount = req["amount"]
            check_in = req["check_in_date"]
            check_out = req["check_out_date"]

            # 단순 정책: 바로 배정 가능한 경우만 승낙
            if motel.can_assign(amount):
                replies.append({"id": rid, "reply": "accepted"})
                if check_in == day:
                    motel.assign(rid, amount, check_out)
                    floor, start, cnt, _ = motel.allocations[rid]
                    today_assigns.append(
                        {"id": rid, "room_number": motel.get_room_number(floor, start)}
                    )
            else:
                replies.append({"id": rid, "reply": "refused"})

        # 3️⃣ 응답 전송
        scenario.reply(replies)

        # 4️⃣ 체크인 고객 시뮬레이션 호출
        if today_assigns:
            result = scenario.simulate(today_assigns)
            print(f"Simulate result: {result}")

    # 최종 점수 확인
    score = scenario.score()
    print("Final Score:", score)


if __name__ == "__main__":
    main()
