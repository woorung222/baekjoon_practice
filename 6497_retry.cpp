#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int x,y,val;
};

//재귀함수를 이용한 parent find 알고리즘
int findParent(vector<int> &parent, int i){
    if (parent[i] == i) return i;
    return parent[i] = (findParent(parent, parent[i]));
}

bool unionNodes(vector<int> &parent, int a, int b){
    a = findParent(parent,a);
    b = findParent(parent,b);
    if (a != b){
        parent[b] = a;
        return true;
    }
    return false;
};

bool cmp(const node& a, const node& b){
    return a.val < b.val;
};

int main(){
    while (true){
        //집의 수 m 길의 수 n
        int m,n;
        cin >> m >> n;
        //길을 저장할 노드리스트
        if (m == 0 && n == 0) break;
        vector<node>wayLst(n);
        //집 부모 리스트
        vector<int>parentLst(m);

        //집 부모부터 맞추기
        for (int i = 0; i < m; i++) parentLst[i] = i;
        //totalCost 생성
        long long totalCost = 0;
        //길 노드 넣기
        for (int i = 0; i < n; i ++){
            int tmpx,tmpy;
            cin >> tmpx >> tmpy >> wayLst[i].val;
            if (tmpx > tmpy) swap(tmpx,tmpy);
            wayLst[i].x = tmpx;
            wayLst[i].y = tmpy;
            totalCost += wayLst[i].val;
        }
        //정렬, val 기준 오름차순, 위에 cmp 제작해둠
        sort(wayLst.begin(),wayLst.end(),cmp);

        //이후 알고리즘 시작. 
        //total 가격 저장 
        long long totalDisCost = 0;
        int wayCount = 0;
        for (int i = 0; i < n; i++){
            if (unionNodes(parentLst,wayLst[i].x,wayLst[i].y)) {
                totalDisCost += wayLst[i].val;
                wayCount++;
            }
            if (wayCount == m - 1) break;
        }

        cout << totalCost - totalDisCost;

    }
}