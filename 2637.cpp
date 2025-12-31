#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    int to;
    int amount;
};

struct storage{
    long long total = 0;
    bool isBasic = true;
};

int main(){
    int N;
    cin >> N;
    int M;
    cin >> M;

    vector<vector<edge>> graph(N+1);
    //vector edge(to, amount)를 저장하는 벡터를 만들거에요. N+1인 이유는 0번 안쓸거에요
    //대충 이렇게 생겼어요. N에 5가 들어갔다면
    //graph[0]~graph[5] 가 생기고 예를 들어 graph[3] = {{2,3},{1,5}}이런식으로 생겼어요.

    //위상 정렬용 indeg를 만들거에여
    vector<int> indeg(N+1,0);

    vector<storage> ans(N+1);

    //rules
    for (int i = 0; i < M; i++){
        int X,Y,K;
        cin >> X >> Y >> K;

        graph[X].push_back({Y,K});
        indeg[Y]++; //X가 Y를 필요로 하니까 Y ++

        ans[X].isBasic = false;
    }

    vector<long long> needCount(N+1,0); //최종 정답 저장 벡터
    needCount[N] = 1; // 완제품은 무조건 1 고정
    
    queue<int> q;

    //완제품부터 사용할거니까 얘네 먼저 push
    for(int i = 1; i <= N ; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < (int)graph[x].size();i++){
            int y = graph[x][i].to;
            int k = graph[x][i].amount;

            needCount[y] += needCount[x] * (long long)k;

            indeg[y] --;
            if (indeg[y] == 0) q.push(y);
        }
    }

    for(int i = 1; i <= N; i ++){
        if (ans[i].isBasic == true) {
            cout <<i << " "<< needCount[i] << "\n";
        }
    }
    
    return 0;
}