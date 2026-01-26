#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

void method(){
    long long N,K; //N => building amount K => way rule
    cin >> N >> K;
    vector<long long>timeLst(N+1); //building - time save vector
    for(long long i = 1; i <= N; i++) cin >> timeLst[i];
    // 이제 위상정렬
    // 필요한 queue : 총 준비해야 하는 건물의 갯수 => layer, 이 건물을 필요로 하는 건물들 => prepared , 현재까지 계산된 시간 => CTime
    vector<long long>layer(N+1,0); // 1~N번 까지, 일단 0으로 초기화
    vector<vector<long long>>adj(N+1); //건물을 필요로 하는 건물 안에 여러개 들어갈꺼니까 2차원으로
    vector<long long>CTime(N+1,0); //걸린 시간. 


    //위상정렬에 사용될 queue 제작
    queue<long long>q;
    
    //way 규칙 받아오기
    for (long long i = 0; i < K; i++){
        long long x,y;
        cin >> x >> y;
        layer[y]++;
        adj[x].push_back(y);
    }

    // goal building
    long long goal;
    cin >> goal;

    //위상정렬 시작
    // 1. 초기값 설정. q 에 layer 0인 것 모두 삽입.
    for(long long i = 1; i <= N; i++){
        if(layer[i] == 0){
            q.push(i);
            CTime[i] = timeLst[i];
        }
    }

    //이제 q 빌 때 까지 전부 돌리면서
    while(!q.empty()){
        long long curr = q.front(); // 큐 상위 숫자 가져오기 ( 현재 건물 )
        q.pop(); // pop 해주고
        for(long long i: adj[curr]){ //i 를 adj[curr] 안에 있는 모든 요소들로 만들어서 한번씩 넣어라 즉 1 안에 있는 2랑3을 i 에 넣었음.
            layer[i]--; //layer -1
            CTime[i] = max(CTime[i],CTime[curr]+timeLst[i]); // 가장 긴 시간은 => 이미 들어가있던 시간 또는 현재까지 사용한 시간 + 건물 건축 시간
            if (layer[i] == 0) q.push(i); // 차수 0 이면 추가해주기
        }
    }
    cout << CTime[goal] << "\n";
}

int main(){
    long long testcase;
    cin >> testcase;
    while (testcase--){
        method();
    }
    return 0;
}