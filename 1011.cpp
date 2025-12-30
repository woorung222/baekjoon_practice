#include <iostream>
using namespace std;

int main(){
    int ttl;
    cin >> ttl;
    for (int i = 0; i < ttl ;i ++){
        int start,end;
        cin >> start >> end;
        int move = end - start;
        int cnt = 0;
        int min = 1;
        move -= min;
        while (move > 0){
            cnt ++;
            if (cnt % 2 == 0) min ++;
            move -= min;
        }
        if (move <= 0) cnt++;
        else cnt += 2;
        cout <<cnt<<"\n";
    }

}