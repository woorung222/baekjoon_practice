#include <iostream>
#include <vector>


using namespace std;

long long isIn(long long sx, long long dx, long long sy, long long dy){
    return(((sx-dx)*(sx-dx))+((sy-dy)*(sy-dy)));
};

void calculate(){
    long long sx,sy,ex,ey;
    cin >> sx >> sy >> ex >> ey;
    long long planet;
    cin >> planet;
    long long ans = 0;
    for(int i = 0; i < planet; i ++){
        long long midx,midy,r;
        cin >> midx >> midy >> r;
        int isS,isE;
        // 원 안에 들어가려면 x,y가 원 안에 있어야 함.
        // 시작점부터 시작.
        // 하나라도 원 밖에 있으면 밖. 둘 다 안에 있어야 안.
        if(isIn(sx,midx,sy,midy) < r*r) isS = 1;
        else isS= -1;
        if(isIn(ex,midx,ey,midy) < r*r) isE = 1;
        else isE= -1;
        if(isS * isE != 1){
            ans++;
        }

    }
    cout << ans << "\n";

};

int main(){
    long long testcase;
    cin >> testcase;
    while(testcase--) calculate();
    return 0;
}