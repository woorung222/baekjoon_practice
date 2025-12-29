#include <iostream>
#include <vector>
using namespace std;

int main(){
    int len;
    cin >> len;
    vector<int> S(20);
    for(int i = 0; i < len; i++){
        string order;
        int flag;
        cin >> order;
        if (order == "add" || order == "remove" || order == "check"|| order == "toggle"){
            cin >> flag;
            flag --;
        }
        if (order == "add"){
            S[flag] = 1;
        }
        else if (order == "remove"){
            S[flag] = 0;
        }
        else if(order == "check"){
            cout << S[flag] << "\n" ;
        }
        else if(order == "toggle"){
            if (S[flag] == 1) S[flag] = 0;
            else S[flag] = 1;
        }
        else if(order == "all"){
            for(int i = 0; i < 20; i++) S[i] = 1;
        }
        else if(order == "empty"){
            for(int i = 0; i < 20; i++) S[i] = 0;
        }
    }

    return 0;
}