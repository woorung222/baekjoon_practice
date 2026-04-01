#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 접시의 수 N , 초밥의 가짓수 d , 연속해서 먹는 접시의 수 k , 쿠폰 번호 c
    long long N,d,k,c;
    cin >> N >> d >> k >> c;
    vector<long long>dishes(N+k-1); // 최소로 필요한 리스트
    for (int i = 0; i < N; i++){
        cin >> dishes[i];
    }
    //계산의 편의를 위해 + k - 1 만큼 리스트 연장
    for (int i = 1; i < k; i++ ){
        dishes[i+N -1] = dishes[i-1];
    }

    // 쿠폰 번호 확인용 테이블 제작. 1부터 d 까지 써야하니까 0번은 안쓸 예정. 즉
    vector<long long>mapping_table(d+1,0);
    
    // 초기 값 세팅. k만큼 사용하기, 쿠폰은 기본적으로 포함되있다고 생각 
    long long curr = 0;
    long long ans = 0;
    for(int i = 0; i < k; i++){
        long long tmp = dishes[i];
        mapping_table[tmp]++;
        if (mapping_table[tmp] == 1){
            curr ++;
        }
        long long candidate = curr;
        if(mapping_table[c] == 0){
            candidate++;
        }
        if (candidate > ans) ans = candidate;
    }

    //초기 값 세팅 이후부터는 N - 1번만큼 확인할거임
    //0번은 빼고 k는 더하기 하면서 조건 하나하나 확인 
    for ( int i = 0; i < N - 1; i++){
        //일단 앞이랑 뒤를 가져와서 변수로 제작
        long long fr,bc;
        fr = dishes[i];  // 0번
        bc = dishes[i+k]; // 3번
        // 앞에 먼저 빼기. 빼면서 테이블과 비교
        mapping_table[fr]--;
        if(mapping_table[fr] == 0) curr--;
        mapping_table[bc]++;
        if(mapping_table[bc] == 1) curr++;
        
        long long candidate = curr;
        if(mapping_table[c] == 0){
            candidate++;
        }
        if (candidate > ans) ans = candidate;
        
    }

    cout << ans;
}


