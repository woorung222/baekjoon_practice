#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int main(){
    int total;
    cin >> total;
    vector <int> ans(total);
    vector<pair<int,int>> stash;
    long long answ = 0;
    for(int i = 0; i < total; i++){
        int a,b;
        cin >> a >> b;
        stash.emplace_back(a,b);
    }
    sort(stash.begin(),stash.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < total; i++){
        int D = stash[i].first;
        int R = stash[i].second;

        pq.push(R);
        if((int)pq.size() > D){
            pq.pop();
        }
    }
    while (!pq.empty()){
        answ += pq.top();
        pq.pop();
    }
    cout << answ;
    return 0;
}