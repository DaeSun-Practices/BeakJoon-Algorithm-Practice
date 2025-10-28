import requests
import json
from typing import List, Dict, Tuple

# API 설정
BASE_URL = "https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod"
X_AUTH_TOKEN = "d119a3cde4edba0033370313"

class GameMatchingSystem:
    def __init__(self, problem: int):
        self.problem = problem
        self.auth_key = None
        self.current_time = 0
        self.user_grades = {}  # 유저별 등급 저장
        self.user_stats = {}   # 유저별 통계 (승/패 등)
        
    def start(self):
        """게임 시작 및 auth_key 발급"""
        url = f"{BASE_URL}/start"
        headers = {
            "X-Auth-Token": X_AUTH_TOKEN,
            "Content-Type": "application/json"
        }
        data = {"problem": self.problem}
        
        response = requests.post(url, headers=headers, json=data)
        result = response.json()
        
        self.auth_key = result["auth_key"]
        self.current_time = result["time"]
        print(f"Started problem {self.problem}, auth_key: {self.auth_key}, time: {self.current_time}")
        
        return result
    
    def get_waiting_line(self) -> List[Dict]:
        """대기 중인 유저 목록 조회"""
        url = f"{BASE_URL}/waiting_line"
        headers = {
            "Authorization": self.auth_key,
            "Content-Type": "application/json"
        }
        
        response = requests.get(url, headers=headers)
        result = response.json()
        
        return result.get("waiting_line", [])
    
    def get_game_result(self) -> List[Dict]:
        """게임 결과 조회"""
        url = f"{BASE_URL}/game_result"
        headers = {
            "Authorization": self.auth_key,
            "Content-Type": "application/json"
        }
        
        response = requests.get(url, headers=headers)
        result = response.json()
        
        return result.get("game_result", [])
    
    def get_user_info(self) -> List[Dict]:
        """모든 유저 정보 조회"""
        url = f"{BASE_URL}/user_info"
        headers = {
            "Authorization": self.auth_key,
            "Content-Type": "application/json"
        }
        
        response = requests.get(url, headers=headers)
        result = response.json()
        
        return result.get("user_info", [])
    
    def match(self, pairs: List[List[int]]) -> Dict:
        """유저 매칭 및 시간 진행"""
        url = f"{BASE_URL}/match"
        headers = {
            "Authorization": self.auth_key,
            "Content-Type": "application/json"
        }
        data = {"pairs": pairs}
        
        response = requests.put(url, headers=headers, json=data)
        result = response.json()
        
        self.current_time = result.get("time", self.current_time + 1)
        
        return result
    
    def change_grade(self, commands: List[Dict]):
        """유저 등급 변경"""
        if not commands:
            return
        
        url = f"{BASE_URL}/change_grade"
        headers = {
            "Authorization": self.auth_key,
            "Content-Type": "application/json"
        }
        data = {"commands": commands}
        
        response = requests.put(url, headers=headers, json=data)
        return response.json()
    
    def get_score(self) -> Dict:
        """최종 점수 조회"""
        url = f"{BASE_URL}/score"
        headers = {
            "Authorization": self.auth_key,
            "Content-Type": "application/json"
        }
        
        response = requests.get(url, headers=headers)
        result = response.json()
        
        return result
    
    def initialize_grades(self):
        """초기 등급 설정 (모든 유저 동일 등급으로 시작)"""
        user_info = self.get_user_info()
        for user in user_info:
            user_id = user["id"]
            self.user_grades[user_id] = 5000  # 초기 등급 5000
            self.user_stats[user_id] = {"wins": 0, "losses": 0, "games": 0}
    
    def update_grade_elo(self, winner_id: int, loser_id: int, k_factor: float = 32):
        """ELO 레이팅 시스템으로 등급 업데이트"""
        winner_grade = self.user_grades.get(winner_id, 5000)
        loser_grade = self.user_grades.get(loser_id, 5000)
        
        # 예상 승률 계산
        expected_winner = 1 / (1 + 10 ** ((loser_grade - winner_grade) / 400))
        expected_loser = 1 / (1 + 10 ** ((winner_grade - loser_grade) / 400))
        
        # 등급 업데이트
        self.user_grades[winner_id] = winner_grade + k_factor * (1 - expected_winner)
        self.user_grades[loser_id] = loser_grade + k_factor * (0 - expected_loser)
        
        # 등급 범위 제한 (0 ~ 9999)
        self.user_grades[winner_id] = max(0, min(9999, self.user_grades[winner_id]))
        self.user_grades[loser_id] = max(0, min(9999, self.user_grades[loser_id]))
        
        # 통계 업데이트
        self.user_stats[winner_id]["wins"] += 1
        self.user_stats[winner_id]["games"] += 1
        self.user_stats[loser_id]["losses"] += 1
        self.user_stats[loser_id]["games"] += 1
    
    def find_best_matches(self, waiting_users: List[Dict]) -> List[List[int]]:
        """최적의 매칭 찾기"""
        if len(waiting_users) < 2:
            return []
        
        # 대기 시간과 등급을 고려한 정렬
        # 대기 시간이 긴 유저를 우선 매칭
        waiting_users_sorted = sorted(
            waiting_users,
            key=lambda x: (self.current_time - x["from"], -self.user_grades.get(x["id"], 5000))
        )
        
        pairs = []
        matched = set()
        
        for i, user1 in enumerate(waiting_users_sorted):
            if user1["id"] in matched:
                continue
            
            user1_id = user1["id"]
            user1_grade = self.user_grades.get(user1_id, 5000)
            user1_wait_time = self.current_time - user1["from"]
            
            best_match = None
            best_score = float('inf')
            
            for j, user2 in enumerate(waiting_users_sorted[i+1:], start=i+1):
                if user2["id"] in matched:
                    continue
                
                user2_id = user2["id"]
                user2_grade = self.user_grades.get(user2_id, 5000)
                user2_wait_time = self.current_time - user2["from"]
                
                # 매칭 점수 계산
                # 1. 등급 차이 (작을수록 좋음)
                grade_diff = abs(user1_grade - user2_grade)
                
                # 2. 대기 시간 고려 (둘 다 오래 기다렸으면 더 좋음)
                wait_penalty = -min(user1_wait_time, user2_wait_time)
                
                # 3. 대기 시간이 14분 이상이면 긴급 매칭
                if user1_wait_time >= 14 or user2_wait_time >= 14:
                    grade_diff *= 0.3  # 등급 차이 페널티 감소
                elif user1_wait_time >= 10 or user2_wait_time >= 10:
                    grade_diff *= 0.6
                
                match_score = grade_diff + wait_penalty * 10
                
                if match_score < best_score:
                    best_score = match_score
                    best_match = user2_id
            
            if best_match:
                pairs.append([user1_id, best_match])
                matched.add(user1_id)
                matched.add(best_match)
        
        return pairs
    
    def run_simulation(self):
        """전체 시뮬레이션 실행"""
        self.start()
        self.initialize_grades()
        
        # 1턴부터 595턴까지 실행
        for turn in range(1, 596):
            print(f"\n=== Turn {turn} ===")
            
            # 게임 결과 확인 및 등급 업데이트
            game_results = self.get_game_result()
            if game_results:
                print(f"Game results: {len(game_results)} games finished")
                grade_changes = []
                
                for result in game_results:
                    winner_id = result["win"]
                    loser_id = result["lose"]
                    
                    # ELO 등급 업데이트
                    self.update_grade_elo(winner_id, loser_id)
                    
                    grade_changes.append({
                        "id": winner_id,
                        "grade": int(self.user_grades[winner_id])
                    })
                    grade_changes.append({
                        "id": loser_id,
                        "grade": int(self.user_grades[loser_id])
                    })
                
                # 등급 변경 적용
                if grade_changes:
                    self.change_grade(grade_changes)
            
            # 555턴까지만 매칭 가능
            if turn <= 555:
                # 대기 중인 유저 확인
                waiting_users = self.get_waiting_line()
                print(f"Waiting users: {len(waiting_users)}")
                
                if waiting_users:
                    # 최적 매칭 찾기
                    pairs = self.find_best_matches(waiting_users)
                    print(f"Matches: {len(pairs)} pairs")
                    
                    # 매칭 실행
                    self.match(pairs)
                else:
                    # 매칭할 유저가 없어도 시간은 진행
                    self.match([])
            else:
                # 555턴 이후에는 빈 매칭으로 시간만 진행
                self.match([])
        
        # 최종 점수 확인
        print("\n=== Final Score ===")
        score_result = self.get_score()
        print(json.dumps(score_result, indent=2))
        
        return score_result


def main():
    """메인 실행 함수"""
    # 시나리오 1 실행
    print("=" * 50)
    print("Running Scenario 1")
    print("=" * 50)
    system1 = GameMatchingSystem(problem=1)
    score1 = system1.run_simulation()
    
    # 시나리오 2 실행
    print("\n" + "=" * 50)
    print("Running Scenario 2")
    print("=" * 50)
    system2 = GameMatchingSystem(problem=2)
    score2 = system2.run_simulation()
    
    print("\n" + "=" * 50)
    print("SUMMARY")
    print("=" * 50)
    print(f"Scenario 1 Score: {score1.get('score', 0):.2f}")
    print(f"Scenario 2 Score: {score2.get('score', 0):.2f}")


if __name__ == "__main__":
    main()