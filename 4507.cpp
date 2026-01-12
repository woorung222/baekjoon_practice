#include <iostream>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

struct storage{
    int lv = 0;
    int pos = 0;
    int value = 0;
    vector<int> ell;
};

int main(){
    //1. case total input
    int caseTotal;
    cin >> caseTotal;
    for (int ct = 0; ct < caseTotal; ct++){
        // 원소 갯수/ 단어 갯수
        int elN,woN;
        cin >> elN;
        //원소 저장 리스트
        vector<string>el(elN+1);
        //원소 Upper 저장 리스트/ 알고리즘에 사용
        //원소의 경우 번호 1번부터 저장해야 하기 때문에 1부터 시작
        vector<string>elC(elN+1);
        for (int i = 1; i <= elN; i++){
            cin >> el[i];
            elC[i] = el[i];
            //Upper 변환 후 저장
            for (int k = 0; k < (int)elC[i].size();k++){
                elC[i][k] = (unsigned char)toupper(elC[i][k]);
            }
        }
        //단어 갯수
        cin >> woN;
        vector<string>wo(woN);
        vector<string>woC(woN);

        //단어 리스트에 저장. 애네는 0번부터 저장 가능
        for(int i = 0; i < woN; i++){
            cin >> wo[i];
            woC[i] = wo[i];
            //Upper 변환 후 저장
            for (int k = 0; k < (int)woC[i].size();k++){
                woC[i][k] = (unsigned char)toupper(woC[i][k]);
            }
        }
        //여기부터 알고리즘 작성할거임
        //얼마나 할꺼면 woN만큼 할거임
        for (int i = 0; i < woN; i ++){
            //자 일단 queue 를 작성해
            queue<storage> q;
            //맨 처음 초기 단어 push
            storage first;
            q.push(first);
            //flag 설정
            bool isEnd = false;
            //cur level 과 pos 설정
            int curLevel;
            int curPos;
            //q 가 비거나 isEnd가 false일 때 까지
            while(!q.empty() && isEnd == false){
                //맨 처음 tmp 가져오기
                storage tmp = q.front();
                curLevel = tmp.lv;
                curPos = tmp.pos;
                for (int elCount = 1; elCount <= elN; elCount++){
                    int ellen = elC[elCount].size();
                    if (curPos + ellen <=(int) woC[i].size() && woC[i].compare(curPos,ellen,elC[elCount]) == 0){
                        storage add = tmp;
                        add.ell.push_back(elCount);
                        add.pos += ellen;
                        add.value += elCount;
                        add.lv++;
                        q.push(add);
                        if((int)add.pos >(int) woC[i].size()) isEnd = true;
                    }
                }
                q.pop();
            }
            storage answer;
            if(q.empty()){
                cout << "END \n";
            }
            else{
                answer = q.front();
                q.pop();
                while (!q.empty()){
                    if(q.front().value < answer.value){
                        answer = q.front();
                    }
                    q.pop();
                }
            }
            
            for(int pri = 0; pri < (int)answer.ell.size(); pri++){
                cout <<"[" <<answer.ell[pri] <<"]";
            }
            cout << "\n";
        }
    }
}