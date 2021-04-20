import sys

def solve():
    max_meeting_number = 0

    meeting_number = int(input())
    meetings = list()

    for _ in range(meeting_number):
        input_string =  sys.stdin.readline()
        meetings.append(map(int, input_string.split()))

    meetings.sort(key=lambda x: (x[0], x[1]))

    for head_index in range(0, meeting_number):
        for previous_head_index in range(0, head_index):
            if meetings[head_index][0] >= meetings[previous_head_index][1]:
                print(max_meeting_number)
                return 0

        current_meeting = 1
        current_index = head_index

        while True:
            isLast = True

            for candidate_index in range(current_index + 1, meeting_number):
                if meetings[current_index][1] <= meetings[candidate_index][0]:
                    next_index = meetings.index(min(meetings[candidate_index:], key= lambda x: x[1]))

                    current_meeting += 1
                    current_index = next_index
                    isLast = False
                    break

            if isLast:
                break

        if current_meeting > max_meeting_number:
            max_meeting_number = current_meeting
        
    print(max_meeting_number)
    return 0

if __name__ == '__main__':
    solve()