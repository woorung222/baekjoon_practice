#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 1,stp = 1;
    if ( n == 1){
        cout << "1";
        return 0;
    }
    while (n > stp){
        stp = stp + (6 * cnt);
        cnt ++;
    }
    cout << cnt;
    return 0;
}