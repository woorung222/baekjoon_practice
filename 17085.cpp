#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// x, y 좌표와 reach를 명확히 구분
bool check_valid(const vector<int>& arr, int W, int x, int y, int reach) {
    int me = y * W + x;
    if (arr[me] == 1) return false;

    for (int i = 1; i <= reach; i++) {
        // 상하좌우 체크
        if (arr[me + i] == 1 || arr[me - i] == 1 || 
            arr[me + (W * i)] == 1 || arr[me - (W * i)] == 1) 
            return false;
    }
    return true;
}

struct nominate {
    int x, y, CLength;
};

bool cmp(nominate &x,nominate &y){
    return x.CLength > y.CLength;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    if (!(cin >> H >> W)) return 0; // H=5, W=6

    vector<int> arr(W * H);
    for (int i = 0; i < W * H; i++) {
        char tmp;
        cin >> tmp;
        if (tmp == '#') arr[i] = 0;      // 가능
        else if (tmp == '.') arr[i] = 1; // 불가능
    }

    // 십자가는 상하좌우 모두 필요하므로 작은 변 기준
    int max_cross = min(W, H);
    if (max_cross == 2) {
        cout << "1";
        return 0;
    }
    if (max_cross % 2 == 0) max_cross--;
    int max_reach = (max_cross - 1) / 2;

    queue<nominate> q;

    while (max_reach > 0) {
        // 십자가 중심점이 존재할 수 있는 경계 계산
        int sW = max_reach;         // x 시작
        int eW = W - 1 - max_reach; // x 끝
        int sH = max_reach;         // y 시작
        int eH = H - 1 - max_reach; // y 끝

        // y(행)를 먼저 돌고, x(열)를 안에서 도는 것이 논리적/효율적
        for (int j = sH; j <= eH; j++) {
            for (int i = sW; i <= eW; i++) {
                if (check_valid(arr, W, i, j, max_reach)) {
                    q.push({i, j, max_reach});
                }
            }
        }
        max_reach--;
    }
    /* debug start
    while (!q.empty()) {
        nominate t = q.front();
        cout << "length:" << t.CLength << " position x:" << t.x << " y:" << t.y << "\n";
        q.pop();
    }
    debug end */

    // vector 로 빼온 후 CLength 기준 정렬
    int qsize = q.size();
    vector<nominate>NLst(qsize);
    for (int i = 0; i < qsize; i ++){
        nominate tp = q.front();
        NLst[i] = tp;
        q.pop();
    }

    sort(NLst.begin(),NLst.end(),cmp);

    // 이후 이중문 돌면서 체크할건데 새로운 좌표평면 만든다음에 돌면서 확인
    // 그럼 첫번째 for 마다 만들고 ㅇㅇ
    // 만약 2개 겹치는거 없으면
    // 가장 큰거 *1 
    int Big = 1;
    for(int i = qsize - 1; i >= 0; i-- ){
        // 처음 만들어 질 때 하나 만듦.
        vector<int> compArr(W * H,0);
        int me = NLst[i].y*W+NLst[i].x;
        compArr[me] = 1;
        for(int R = 1; R <= NLst[i].CLength; R++){
            //상하좌우 모두 1로 변경
            /*arr[me + i] == 1 || arr[me - i] == 1 || 
            arr[me + (W * i)] == 1 || arr[me - (W * i)*/
            compArr[me + R] = 1;
            compArr[me - R] = 1;
            compArr[me + (W * R)] = 1;
            compArr[me - (W * R)] = 1;
        }
        //이후 이중 루프. 
        for(int j = qsize - 1; j >= i; j--){
            int U = NLst[j].y*W+NLst[j].x;
            bool flag = check_valid(compArr,W,NLst[j].x,NLst[j].y,NLst[j].CLength);
            if (flag){
                int tmpAns = (NLst[i].CLength * 4 + 1) * (NLst[j].CLength * 4 + 1);
                Big = max(Big,tmpAns);
            }
        }
    }
    cout << Big;
    return 0;

}