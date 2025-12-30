#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rule{
    int start;
    int end;
    int m;
};

int R; //Rule 갯수
long long D; //도토리 갯수
vector<rule>Rules;

long long Count_upto(int x){
    long long cnt = 0;

    //모든 규칙 순회하면서
    for (int i = 0; i < R; i ++){   
        int S = Rules[i].start;
        int E = Rules[i].end;
        int M = Rules[i].m;

        if (x < S) continue; //start 가 x 보다 크면 그 규칙은 애초에 x 에 영향을 못 줌

        //어차피 x 까지만 볼거니까 x랑 End 랑 min 함수 사용
        int t = min(x,E);

        //이후 x 까지의 카운트 추가
        cnt += ((t - S)/M)+1;

        //만약 cnt 가 D 보다 커지면 굳이 더 안해도 됌
        if (cnt >= D) return cnt;
    }
    return cnt;
}

int main(){
    int B;
    cin >> B >> R >> D;
    Rules.resize(R);
    for (int i = 0; i < R; i ++){
        cin >> Rules[i].start >> Rules[i].end >> Rules[i].m;

    }
    //여기서부터 이분탐색
    int low = 1;
    int high = B;

    while (low < high){
        int mid = low + (high - low)/2;
        
        if(Count_upto(mid) < D){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    cout << low;
    return 0;
}