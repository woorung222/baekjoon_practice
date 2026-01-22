#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,M; // N = 손님의 수 M = 흙탕물이 되는 시간
    cin >> N >> M;
    vector<long long>customerTime(N);
    long long highest = 0;
    for(long long i = 0; i < N; i++){
        cin >> customerTime[i];
        if (customerTime[i] > highest) highest = customerTime[i];
        if (customerTime[i] == 0 || customerTime[i] == 1){
            cout << "fail";
            return 0;
        }
    }
    vector<long long>timeLst(highest+1,0);
    //1. 서빙해야 하는 시간을 2로 바꾸기
    for (long long i = 0; i < N; i++){
        timeLst[customerTime[i]] = 2;
    }

    //2. 서빙하기 적어도 M 전에는 커피를 따라야 함. 가장 마지막부터 시작해서 뒤로 거슬러 가며 
    //1) 2를 찾음
    //2) 2 본인을 포함 M칸 내에 0이 있나 차례대로 확인
    //3) 0 이 있으면 1로 변경, countinue
    //4) 다음 2로 넘어감
    //5) 시간이 없으면 fail 출력
    for (long long i = highest ; i >= 0; i--){
        if (timeLst[i] == 2){
            bool condition = false;
            for(long long j = 0; j < M; j++){
                if(i-j-1 >= 0 && timeLst[i-j-1]==0 && condition == false ){
                    timeLst[i-j-1] = 1;   
                    condition = true;
                }
            }
            if (condition == false){
                cout << "fail";
                return 0;
            }
        }
    }
    //3. 커피를 담기 위한 토기를 만들 시간이 필요함
    //토기에는 시간 제한이 없으니, 토기를 만들 시간이 존재하기만 하면 됌.
    //그러나 어쨌든 커피가 나가려면 토기가 있어야 함
    //그럼 처음부터 시작해서
    // 0 을 3 으로 변경
    // 토기 ++
    // 1을 만나면
    // 토기 --
    // 만약 토기 < 0 && timeLst[i] == 1 -> fail
    
    long long togi = 0;
    for(long long i = 0; i < highest+1; i++) {
        if (timeLst[i] == 0){
            togi++;
            continue;
        }
        if (timeLst[i] == 1){
            if(togi == 0){
                cout<< "fail";
                return 0;
            }
            else togi--;
        }

    }
    cout << "success" ;

    return 0;
}