#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    // N M (손님 수 / 흙탕물 시간 ) 받아옴
    int N,M;
    cin >> N >> M;
    vector<long long>custmTime(N);
    int top = 0;
    for(long long i = 0; i < N; i++){
        cin >> custmTime[i];
        if (custmTime[i] > top) top = custmTime[i];
    }

    sort(custmTime.begin(),custmTime.end());
    vector<long long>timeTable(top+1,0);

    for(long long i = 0; i < N; i ++){
        timeTable[custmTime[i]] = -1;
    }
    //초기상태 구현
    queue<long long>q;

    long long coffee = 0;
    //버퍼는 항상 +1
    for (long long i = 0; i < M + 1; i ++){
        if (i <= top){
        q.push(timeTable[i]);
        }
        if(timeTable[i] == -1) coffee++;
    }

    long long qf = M + 1;
    long long togi = 0;
    long long ready = 0;
    //M부터 끝까지
    while(!q.empty()){
        if(q.front() == 0){
            if (coffee - ready == 0){
                togi++;
                q.pop();
            }
            else{
                if (togi > 0){
                    togi --;
                    ready++;
                    q.pop();
                }
                else{
                    togi ++;
                    q.pop();
                }
            }
        }
        else{
            ready--;
            if (ready < 0){
                cout << "fail";
                return 0;
            }
            coffee--;
            q.pop();
        }

        if(qf <= top){
            q.push(timeTable[qf]);
            qf++;
            if (q.back() == -1) coffee++; 
        }
    }
    cout<< "success";
}