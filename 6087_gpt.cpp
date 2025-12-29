#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;
//간선 가중치 직선의 경우 0
//간선 가중치 직각인 경우 1

//구조체 먼저
struct State{
    int y;
    int x;
    int dir;
};
//왼,오 방향 set
int leftDir(int dir) {return ((dir + 3) % 4); }
int rightDir(int dir) {return ((dir + 1) % 4); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W,H;
    cin >> W >> H;

    vector<string> grid(H);
    for (int i = 0; i < H ; i ++){
        cin >> grid[i];
    }

    vector<pair<int,int>> cpos; //C 모아둘 포지션
    cpos.reserve(2);
    
    //C 포지션 찾기 ㅇㅇ
    for (int y = 0; y < H; y ++){
        for (int x = 0; x < W; x ++){
            if (grid[y][x] == 'C') {
                cpos.push_back({y,x});
            }
        }
    }
    int sy = cpos[0].first;
    int sx = cpos[0].second;
    int ey = cpos[1].first;
    int ex = cpos[1].second;

    int dy[4] = {-1, 0 ,1 ,0};
    int dx[4] = {0 , 1 , 0 , -1};

    const int INF = 100000000;
    //dist [H][W][4] => dist [y][x][4]
    vector<vector<vector<int>>>dist (H ,vector<vector<int>>( W,vector<int> (4,INF)));
    // 0-1 BF 용 queue
    deque<State> dq;

    /* 시작점 초기화
    처음에는 직진으로 시작하기 때문에 맨 처음에는 모든 방향이 전부 0 이어야 함
    */
   for(int dir = 0; dir < 4; dir ++){
    dist[sy][sx][dir] = 0;
    dq.push_back({sy,sx,dir});
   }

   //이제 알고리즘 시작
   while(!dq.empty()){
    State cur = dq.front(); //현재 상태는 가장 앞 q 상태
    dq.pop_front(); // 꺼냈으니까 맨 앞 pop
    
    int y = cur.y; //현재 y
    int x = cur.x; //dd
    int dir = cur.dir; // dd
    int curCost = dist[y][x][dir]; // 현재 최소 cost. 나머지는 INF로 채워져있음

    //다음 방향 후보 3개
    int ndirs[3];
    ndirs[0] = dir; //직진
    ndirs[1] = leftDir(dir); //left
    ndirs[2] = rightDir(dir); //right

    for (int i = 0; i < 3; i++){
        int ndir = ndirs[i]; // 어느 방향으로 나아갈지 결정(i가 3개니까 ㅇㅇ)
        int ny = y + dy[ndir]; // y 방향 미리 세팅해둔대로 증가
        int nx = x + dx[ndir]; // x 방향 미리 세팅해둔대로 증가

        if (ny < 0 || ny >= H || nx < 0 || nx >= W){
            continue;
        }
        if(grid[ny][nx] == '*'){
            continue;
        }

        int addCost; //거울 추가 여부
        if (ndir == dir ){
            addCost = 0;
        }
        else addCost = 1; //위치 바뀌면 +1

        int nextCost = curCost + addCost;

        if (nextCost < dist[ny][nx][ndir]){
            dist[ny][nx][ndir] = nextCost; // 더 좋은 경로면 이걸로 변경

            if(addCost == 0){
                dq.push_front({ny,nx,ndir}); //addCost 가 0이면 앞에 추가
            }
            else {
                dq.push_back({ny,nx,ndir}); // addcost 가 1이면 뒤에 추가
            }
        }

    }

   }

   int answer = INF;
   for (int dir = 0; dir < 4; dir ++){
    answer = min(answer,dist[ey][ex][dir]);
   }
   cout << answer;
   return 0;


}
