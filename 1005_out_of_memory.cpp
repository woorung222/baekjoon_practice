#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct building{
    long long val;
    bool isMade = false;
    queue<long long> needed;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long testcase;
    cin >> testcase;
    while(testcase--){
        //N => 건물 M => way
        long long N,M;
        cin >> N >> M;
        vector<building>buildings(N+1);
        for(long long i = 1; i <= N; i++){   
            cin >> buildings[i].val;
        }
        for(long long i = 0; i < M; i++ ){
            long long x,y;
            cin >> x >> y;
            buildings[y].needed.push(x);
            buildings[y].isMade = true;
        }
        //지금까지 건물들의 value와 각 건물들과 연결된 건물들을 표기함.
        long long goal;
        cin >> goal;
        if (buildings[goal].isMade == false){
            cout << buildings[goal].val << "\n";
            continue;
        }

        //이제부터 모든 경우의 수를 queue 에 넣을 예정.
        queue<vector<long long>>Q;
        Q.push({goal});
        queue<vector<long long>>ansQ;
        while(!Q.empty()){
            vector<long long>current;
            current = Q.front(); //{7,5}
            long long currentSize = current.size(); //2
            long long currentEndElement = current.back(); //5
            queue<long long>currentNeededQ = buildings[currentEndElement].needed; //|2|
            long long loopTry = currentNeededQ.size(); //1
            for(int i = 0; i < loopTry; i ++){ //1
                vector<long long>tmplst(currentSize+1);//리스트 한칸 추가,3
                //tmplst = current; //{7,5}
                for (int k = 0; k < currentSize; k ++){
                    tmplst[k] = current[k];
                }
                long long tmpFront = currentNeededQ.front(); //2
                tmplst[currentSize] = tmpFront;// {7,5,2}
                if (buildings[tmpFront].isMade == false){ //만약 방금 추가한 엘리멘트가 초기 건물이면
                    ansQ.push(tmplst); //정답 후보군에 삽입
                }
                else{ //아니라면
                    Q.push(tmplst); //후보군 큐에 삽입
                }
                currentNeededQ.pop();//needed q pop
            } //지금 그럼 2번 돌았으니까 {(7,6),(7,5,2)} 상태 이후 7 pop
            Q.pop();
        }
        long long Val = 0;
        long long ansQlength = ansQ.size();
        for(int i = 0; i < ansQlength; i ++){
            vector<long long>tmpV = ansQ.front();
            long long vecSize = tmpV.size();
            long long tmpVal = 0;
            for (int j = 0; j < vecSize; j ++){
                tmpVal += buildings[tmpV[j]].val;
            }
            if (tmpVal > Val) Val = tmpVal;
            ansQ.pop();
        }
        cout << Val << "\n";
    }
}