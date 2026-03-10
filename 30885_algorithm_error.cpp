#include <iostream>
#include <queue>

using namespace std;

int main (){
    int N;
    cin >> N;
    queue<pair<int,int>>ansq;
    ansq.push({-1,-1});
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        ansq.push({tmp,i});
    }
    ansq.push({-2,-2}); // end of day

    // 1. 현재 상태 -1 ㅁ ㅁ ㅁ ㅁ ㅁ -2(end)
    // 2. 아니 근데 진짜 3개씩 볼 필요가 없음 2개만 보면 됌 end 조건이랑 start 조건만 잘 정해주자
    // 3. -1 이 들어오면 시작 신호
    // 4. 그럼 이렇게 하자 리스트 또는 대기열 버퍼 ㅁㅁ 확인 검문소 ㄴ
    // 5. 그럼 이제 ㄴ에 -1,-2 가 들어오면
    // 5-1. -1일 때는 맨 앞에 0,0 삽입(먹어도 상관 없는거) 두번째에 하나 팝업
    // 6. 이후 알고리즘 계속 진행
    // 7. a,b 비교, a 가 크다 -> 앞에가 뒤에보다 크다 -> 바로 먹음, 먹고 나서 맨 뒤로 보내기, 상태 변경 0,두개 가져오기
    // 8. a,b 비교, b가 크다 -> 앞에가 뒤보다 작다 -> 먹고 b를 a로 변경, 상태 변경 1 ,하나 가져오기 
    // 진행 하다가 -2가 나온다면 ->  상태 a일 때 -> -2 -2 맨 뒤에 붙히고 종료; 상태 b일 때 -> a 맨 뒤 -2 -2 종료
    // 버퍼 크기 확인 -> 크기가 3이면 끝 (-1,ㅁ,-2)
    pair<int,int> A,B,curr;
    curr = {0,0};
    bool cond,loop = 0; //0 == A>=B 1 == A<B
    while (loop == 0){ //무조건 curr 거치기 무조건
        //일단 맨 앞에를 확인 이게 제일 먼저
        curr = ansq.front();
        //-1,-1 만 starter, 예외처리
        if (curr.first == -1){
            if (ansq.size() == 3){ 
                loop = 1;
                break;
            } // 앤드 조건 확인
            ansq.pop(); // -1, -1 제거
            cond = 1; // condition 1로 지정( 즉 다음 사이클에서는 B에 삽입 후 사이클 돌리기)
            ansq.push(curr); // -1, -1 맨 뒤에 삽입
            A = ansq.front(); //A 맨 앞에 것으로 삽입
            ansq.pop(); //하나 제거
            cout << "Debug: starter\n";
        }
        else if(curr.first == -2){//finisher
            if (cond == 0){
                ansq.push(curr); // 맨 뒤에 -2 -2 삽입
                ansq.pop(); //그냥 끝내기
                cout << "Debug -2 cond 0\n";
            }
            else { // cond == 1, 즉 A에 남아있음
                ansq.push(A); // A 맨 뒤에 삽입
                ansq.push(curr); // curr 삽입
                ansq.pop(); //팝
                cout << "Debug -2 cond 1\n";
            }
        }
        else{
            if (cond == 1){
                B = curr;
                ansq.pop();
                //알고리즘 돌리기
                if (A.first >= B.first){
                    A.first = A.first + B.first;
                    ansq.push(A);
                    cond = 0;
                }
                else{
                    A.first = A.first + B.first;
                    A.second = B.second;
                    cond = 1;

                }
                cout << "Debug cond 1  " << A.first << " " << A.second << "\n";
            }
            else{ // 리스트 비어있음, cond == 0;
                A = curr; // A에 하나 넣고
                ansq.pop(); //팝
                cond = 1; //컨디션 변경 사이클 다시
                cout << "Debug cond 0 "<< A.first << " " << A.second << "\n";
            }
        }
    }
    int ans1,ans2;
    ansq.pop();
    ans1 = ansq.front().first;
    ans2 = ansq.front().second;
    cout << ans1 << "\n" << ans2;
    return 0;
}