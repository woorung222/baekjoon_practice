#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int B,R,D;
    cin >> B >> R >> D;
    priority_queue <long long> pq;
    for (int i = 0; i < R; i ++){
        int start,end,m;
        cin >> start >> end >> m;
        for (int j = start; j <= end; j += m){
            if (pq.size() == D && j > pq.top()) break;
            pq.push(j);
            if ((int)pq.size() > D ){
                pq.pop();
            }
        }
    }
    cout << pq.top();

}