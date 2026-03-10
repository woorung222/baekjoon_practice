#include <iostream>
#include <queue>

using namespace std;

int main (){
    int N;
    cin >> N;
    if (N == 1){
        long long tmp1;
        cin >> tmp1;
        cout << tmp1 << "\n1" ;
        return 0;
    }
    deque<pair<long long,long long>>ansq;
    ansq.push_back({-1,-1});
    for (long long i = 0; i < N; i++){
        long long tmp;
        cin >> tmp;
        ansq.push_back({tmp,i});
    }
    ansq.push_back({-2,-2}); // end of day   
    pair<long long,long long>A = {-3,-3};
    pair<long long,long long>B = {-3,-3};
    pair<long long,long long>C = {-3,-3};
    while (1){
        if (ansq.size() == 3) break;
        // 0. check
        // 0_1 : A
        A = ansq.front();
        if(A.first == -2){
            ansq.push_back(A);
            A = {-3,-3};
            ansq.pop_front();
            continue;
        }
        ansq.pop_front();
        //0_2 : B
        B = ansq.front();
        if(B.first == -2){
            ansq.push_back(A);
            ansq.push_back(B);
            A,B = {-3,-3};
            ansq.pop_front();
            continue;
        }
        ansq.pop_front();
        //0_3 : C
        C = ansq.front();
        ansq.pop_front();
        // 대기열 생성 ( 더할꺼 )
        long long pending = 0;
        // 1. A,B compare
        // 1_1 : -1
        if (A.first == -1){
            ansq.push_back(A);
            A = {-3,-3};
        }
        // 1_2 : A > B => 유지
        else if (A.first > B.first){
        }
        // 1_3 : A <= B => 먹힘
        else {
            pending += A.first;
            A = {-3,-3};
        }
        // 2. B,C compare
        // 2_1 : C = -2
        if (C.first == -2){
            ansq.push_front(C);
            C = {-3,-3};
        }
        // 2_2 : B <= C = 유지
        else if (B.first < C.first){}
        //2_3 : B > C => 먹기
        else{
            pending += C.first;
            C = {-3,-3};
        }
        // --- 이제 다부터 보면서 밀어넣기---
        if (C.first != -3){
            ansq.push_front(C);
            C = {-3,-3};
        }
        B.first = B.first+pending;
        ansq.push_front(B);
        B = {-3,-3};
        if (A.first != -3){
            ansq.push_back(A);
            A = {-3,-3};
        }
    }
    pair<long,long>answer = {-1,-1};
    while (answer.first == -1 || answer.first == -2){
        answer = ansq.front();
        ansq.pop_front();
    }
    cout << answer.first << "\n" << answer.second + 1;
    return 0;
}