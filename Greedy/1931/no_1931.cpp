#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int meeting_number, meeting_start, meeting_end, max_meeting=0, current_meeting, current_index, candidate_index, next_index;
    long min_end_time = 2^32 - 1;

    bool isLast = false;
    cin >> meeting_number;

    vector<pair<int, int>> meetings;

    for (int i=0; i < meeting_number; i++){
        cin >> meeting_start >> meeting_end;
        meetings.push_back(pair<int, int>(meeting_start, meeting_end));
    }

    sort(meetings.begin(), meetings.end());

    for (int header_index = 0; header_index < meeting_number; header_index++){
        if (header_index > 0)
            if (min_end_time > meetings[header_index - 1].second)
                min_end_time = meetings[header_index - 1].second;
            
        
        if (meetings[header_index].first >= min_end_time){
            cout << max_meeting;
            return 0;
        }
        

        current_meeting = 1;
        current_index = header_index;

        while(true){
            isLast = true;

            for (candidate_index = current_index+1; candidate_index < meeting_number; candidate_index++){
                if(meetings[current_index].second <= meetings[candidate_index].first){
                    
                    int minimun_end_time = 100000;

                    for (int i = candidate_index; i < meeting_number; i++){
                        if (meetings[i].second < minimun_end_time){
                            next_index = i;
                            minimun_end_time = meetings[i].second;
                        }
                    }


                    current_meeting++;
                    current_index = next_index;
                    isLast = false;
                    break;
                }
            }
            if (isLast)
                break;
        }

        if (current_meeting > max_meeting)
            max_meeting = current_meeting;

    }

    cout << max_meeting;
    return 0;
}