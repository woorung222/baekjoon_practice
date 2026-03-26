#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting{
    long long member;
    long long start_time;
    long long end_time;
    float value;
};

bool cmp(const meeting& a, const meeting& b){
    if(a.value != b.value) {
        return a.value > b.value;
    }
    else {
        return a.member > b.member;
    }
};

int main(){
    int N;
    cin >> N;
    vector<meeting>meeting_list(N);
    long long last_meeting = 0; 
    for(long long i = 0; i < N; i++){        
        long long mem,start,end;
        cin >> start >> end >> mem;
        if (end > last_meeting) last_meeting = end;
        meeting_list[i].member = mem;
        meeting_list[i].start_time = start;
        meeting_list[i].end_time = end;
        meeting_list[i].value = (float)mem/(float)(end-start);
    }

    sort(meeting_list.begin(),meeting_list.end(),cmp);
    vector<meeting>time_table;
    long long occupied_time = 0;

    for (long long i = 0; i < N; i ++){ //meeting list 에 있는 수 만큼
        bool isPass = true;
        for(int j = 0; j < occupied_time; j++){ //occupied time은 모두 확인
            // 시작시간, 끝시간 확인 확인
            if (meeting_list[i].start_time < time_table[j].end_time && meeting_list[i].end_time > time_table[j].start_time){ //시작 시간은 기존 종료 시간보다 
                isPass = false;
                break;
            }
        }
        if (isPass == true){ //안 걸렸다 = 들어가도 됌
            time_table.push_back(meeting_list[i]);
            occupied_time++;
        }
    }
    long long answer = 0;
    for(long long i = 0; i < occupied_time; i ++){
        answer += time_table[i].member;
        }
    cout << answer;

    return 0;

}