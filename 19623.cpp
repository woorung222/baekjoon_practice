#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting{
    long long member;
    long long start_time;
    long long end_time;
};

bool cmp(const meeting& a, const meeting& b){
    if (a.end_time != b.end_time){
        return a.end_time < b.end_time;
    }
    else return a.start_time < b.end_time;
};

long long binary_search_for_meeting(const vector<meeting>& meeting_list,long long index){
    long long low = 0;
    long long high = index - 1;
    long long answer = -1; // 전부 겹치면 -1 나옴
    // 이제부터 이진탐색 시작. 현재 위치 = index. 내가 원하는 것 = 0~index - 1 까지의 모든 요소 중에 .endtime < [i].starttime 을 찾는 것
    // 제일 먼저 mid 를 구한 후에 meeting_list[mid].endtime 과 [i].starttime을 비교
    //   1. endtime > starttime -> 겹치는 회의. 더 앞 회의 찾아봐야 함 -> high = mid - 1 로 변경 
    //   2. endtime < starttime -> 안 겹침. 이게 정답일 수도 있고 아닐 수도 있음. 뒤의 회의도 확인 해봐야함
    //      그렇기에 일단 ans = mid 로 바꿔놓고 low = mid + 1로 변경
    // low <= high 일 때 무한 반복
    while (low <= high){
        long long mid = (high+low)/2; //먼저 미드 계산
        if (meeting_list[mid].end_time <= meeting_list[index].start_time){
            answer = mid;
            low = mid+1;
        }
        else {
            high = mid - 1;
        }
    }
    return answer;
};

int main(){
    int N;
    cin >> N;
    vector<meeting>meeting_list(N);
    for(long long i = 0; i < N; i++){        
        long long mem,start,end;
        cin >> start >> end >> mem;
        meeting_list[i].member = mem;
        meeting_list[i].start_time = start;
        meeting_list[i].end_time = end;
    }
    sort(meeting_list.begin(),meeting_list.end(),cmp);
    // 하나씩 집어넣으면서 이득 or 이득 아님 판단 할 예정
    // 각 회의 i 마다 가장 이득인 인원
    vector<long long>dp(N);
    dp[0] = meeting_list[0].member; // 0번은 0번 그대로 삽입
    for(long long i = 1; i < N; i++){ // 모든 경우의 수에 따라
        //1번 경우의 수 -> exclude
        long long exclude = dp[i-1];
        //2번 경우의 수 -> include. 
        long long include = meeting_list[i].member;
        long long j = binary_search_for_meeting(meeting_list,i);
        if (j != -1){
            include += dp[j];
        }

        dp[i] = max(include,exclude);
        
    }

    cout << dp[N-1];

    return 0;

}