#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//전역변수 map 하나 선언
map<long long, long long>memo;
//전역변수 S,T 선언
long long S, T;

long long solve_dp(long long n){
    if (n == 0) return 0;
    if (n == 1) return S;
    if (memo.count(n)) return memo[n];
    if ( n % 2 == 0){ //짝수면
        return memo[n] = min(solve_dp(n-1)+S,solve_dp(n/2)+T);    
    }
    else{
        return memo[n] = solve_dp(n-1) + S;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >>t;
    while (t--){
        long long n;
        cin >> n >> S >>T;
        memo.clear();
        cout << solve_dp(n)<<"\n";
    }
    return 0;
}