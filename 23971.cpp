#include <iostream>
using namespace std;
int main(){
    int H,W,N,M;
    //세로로 N칸 가로로 M 칸 가로 W 세로 H
    cin >> H >> W >> N >> M;
    N++;
    M++;
    int side = 0;
    int hei = 0;
    //세로
    for (int i = 0 ; i < H; i = i + N){
        hei++;
    }
    //가로
    for (int i = 0 ; i < W ; i = i + M){
        side++;
    }
    int ans = hei*side;
    cout << ans;
    return 0;

}