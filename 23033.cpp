#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long INF = 9223372036854775800;

struct way{
    long long destination;
    long long usetime;
    long long waittime;
};

int main(){
    long long N,M;
    cin >> N >> M;

    vector<vector<way>>dj(N+1);

    for(long long i = 0; i < M; i++){
        long long tmp;
        way ttmp;
        cin >> tmp >> ttmp.destination >> ttmp.usetime >> ttmp.waittime;
        dj[tmp].push_back(ttmp);
    }

    vector<long long>dist(N+1,INF);
    dist[1] = 0;
    priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q; //시간 노드
    q.push({0 , 1});
    // 다익스트리 시작
    while(!q.empty()){
        pair <long long, long long>tmp;
        tmp = q.top();
        q.pop();
        long long curstation = tmp.second;
        long long curtime = tmp.first;
        long long count = dj[curstation].size();
        if (curtime > dist[curstation]) continue;
        for(long long i = 0; i < count; i++){
            way tmpway = dj[curstation][i];
            //대기시간 계산
            long long HTWait;
            if (curtime%tmpway.waittime == 0) HTWait = 0;
            else{
                HTWait = tmpway.waittime - (curtime % tmpway.waittime);
            }
            long long cal_time = curtime + HTWait + tmpway.usetime;
            // 이제 cal time과 기존 dist 를 비교하여 더 적은 쪽으로 넣기.
            long long origin = dist[tmpway.destination];
            if (cal_time < origin){
                dist[tmpway.destination] = cal_time;
                q.push({cal_time,tmpway.destination});
            }
        }
    }
    cout << dist[N];
  
}