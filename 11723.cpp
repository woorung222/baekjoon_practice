#include <iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int len;
    cin >> len;
    bool flag[20] = {};
    for (int i = 0 ; i < len ; i ++){
        string tmp;
        cin >> tmp;
        if (tmp == "add"){
            int x; cin >> x;
            flag[x-1] = true;
        }
        if (tmp == "remove"){
            int x; cin >> x;
            flag[x-1] = false;
        }
        if (tmp == "check"){
            int x; cin >> x;
            cout << flag[x-1] <<"\n";
        }
        if (tmp == "toggle"){
            int x; cin >> x;
            flag[x-1] = !flag[x-1];
        }
        if (tmp == "all"){
            for (int i = 0; i < 20; i++) flag[i] = 1;
        }
        if (tmp == "empty"){
            for (int i = 0; i < 20; i ++) flag[i] = 0;
        }
    }
}