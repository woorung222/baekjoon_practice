#include <iostream>
#include <vector>
using namespace std;
int main(){
    int len;
    cin >> len;
    vector<long long> chanel(len);
    for(int i = 0 ; i < len; i++){
        string tmp;
        cin >> tmp;
        if (tmp == "KBS1") chanel [i] = 1;
        else if (tmp == "KBS2") chanel [i] = 2;
        else chanel [i] = 0;
    }
    int flag = 0;
    while (chanel[flag] != 1){
        cout << "1";
        flag++;
    } 

    for (int i = flag; i != 0 ; i -- ){
        int tmp;
        tmp = chanel[i];
        chanel[i] = chanel [i-1];
        chanel[i-1] = tmp;
        cout <<"4";
    }

    flag = 0;
    while (chanel[flag] != 2){
        cout << "1";
        flag++;
    } 
    for (int i = flag; i != 1 ; i -- ){
        int tmp;
        tmp = chanel[i];
        chanel[i] = chanel [i-1];
        chanel[i-1] = tmp;
        cout << "4";
    }
    return 0;
}