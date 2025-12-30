#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long ttl;
    cin >> ttl;
    vector<long long> way(ttl);
    for(long long i = 0; i < ttl; i++){
        cin >> way[i];
    }
    bool flag = 0;
    long long ans = 0;
    int start = -1;
    for (long long i = 0; i < ttl; i++){
        if(way[i] > 0){
            start = i;
            break;
        }
    }

    if (start == -1) {
    cout << (ttl / 2);
    return 0;
    }

    for(long long step = 0; step  < ttl; step++){
        long long i = (start + step) % ttl;
        if (way[i] > 0){
            ans += way[i];
            flag = 1;
        }
        else{
            if (flag == 1){
                ans += 1;
                flag = 0;
            }
            else{
                flag = 1;
            }
        }
    }
    cout << ans;
    return 0;
}