#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x,y,z;
    string ans;
    cin >> x >> y >> z;
    while(!(x == 0 && y == 0 && z == 0)){
        //Equilateral, Isosceles, Scalene, Invalid
        int tmp[] = {x,y,z};
        sort(tmp,tmp+3);
        if (tmp[2] >= tmp[1] + tmp [0]) ans.append("Invalid\n");
        else if (tmp [0] == tmp [1] && tmp[1] == tmp[2]) ans.append("Equilateral\n");
        else if (tmp[0] == tmp [1] || tmp[1] == tmp[2]) ans.append("Isosceles\n");
        else ans.append("Scalene\n");

        cin >> x >> y >> z;
    }
    cout << ans;
    return 0;
}