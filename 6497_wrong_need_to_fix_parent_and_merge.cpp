#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
    int length;
    int x;
    int y;
};

void set(node &a){
    if (a.x > a.y) swap(a.x,a.y);
};

bool cmp(const node &a,const node &b){
    return a.length < b.length;
};

int main(){
    int house,way;
    cin >> house >> way;
    vector<node>waylst(way);
    vector<int>parentlst(house);
    for (int i = 0; i < house; i ++){
        parentlst[i] = i;
    }
    //리스트에 받으면서 x<y 로 만든 후 넣기. parent는 항상 x로. 
    for(int i = 0; i < way; i++){
        cin >> waylst[i].x >> waylst[i].y >> waylst[i].length;
        set(waylst[i]);
    }
    int end1,end2;
    cin >>end1>>end2;

    sort(waylst.begin(),waylst.end(),cmp);

    int mark = 0;
    int ans = 0;
    for (int i = 0; i < way; i++){
        if (parentlst[waylst[i].x] == parentlst[waylst[i].y]){
            continue;
        }
        mark ++;
        parentlst[waylst[i].y] = parentlst[waylst[i].x];
        ans += waylst[i].length;
        if (mark > house) break;
    }
    cout << ans;
}