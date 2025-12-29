#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(){
    int total;
    cin >> total;
    vector <pair<int,int>> stash;
    stash.reserve(total);
    for(int i = 0; i < total; i++){
        int F,S;
        cin >> F >> S;
        stash.push_back({F,S});
    }
    sort(stash.begin(),stash.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i < total; i++){
        int D,R;
        D = stash[i].first;
        R = stash[i].second;
        pq.push(R);
        if((int)pq.size() > D){
            pq.pop();
        }
    }
    long long answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
    return 0;
}