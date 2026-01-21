

#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //1. test case input
    int T;
    cin >> T;
    //2. loop until testcase
    for (int TC = 0; TC < T; TC++){
        //3. input area. n = number of repeat s = texting time c = copy time
        long long n,s,c;
        cin >> n;
        cin >> s >> c;
        //이제부터 알고리즘. 
        long long total = 0; //여기에 저장하며 나아갈것.
        while (n > 1){ //1 되면 끝
            if ( n%2 == 1){
                total += s;
                n --;
            }
            else {
                long long m = n / 2;
                if (c / s < m ){
                    total += c;
                    n = m;
                }
                else{
                    total = total + (s*n);
                    break;
                }
            }
        }
        if (n == 1) total += s;
        cout << total <<"\n";
    }

}