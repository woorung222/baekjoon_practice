#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct sr{
    int cost,cli;
    float val;
};
bool cmp(const sr& a, const sr& b){
    return a.val < b.val;
};

int main(){
    int total;
    int goal;
    cin >> goal >> total;
    vector<sr>lst(total);
    for (int i = 0; i < total; i++){
        cin >> lst[i].cost >> lst[i].cli;
        lst[i].val = (float)lst[i].cost / (float)lst[i].cli ;
    }
    sort(lst.begin(),lst.end(),cmp);
    //진행 상황 -> value를 구한 후 value가 적은(즉 명당 가격이 제일 싼 사람부터) 나열 완료.
    //이후 진행해야 할 것. goal - cli(가장 큰 것) 이 안될때 까지 빼기
    int tc = 0;
    while (goal > lst[0].cli){
        tc += lst[0].cost;
        goal -= lst[0].cli;
    }
    //이후 무조건 가장 효율 좋은 것 보다는 cli 가 작은 무언가가 남음. / 또는 0임
    //만약 0이면 그대로 출력 complete
    //아니라면 가장 효율이 좋은 것을 뽑아야하는데
    //어차피 지금 sort가 효율 좋은 순으로 되어있으니까
    //0또는 - 될 때 까지 사면 됌
    //그 중 가장 가격이 작은 것을 더해서
    //tc출력
    if (goal == 0) {
        cout << tc;
        return 0;
    }

    int fiadd = lst[0].cost; //마지막에 더할거.

    for (int i = 1; i < total; i++){
        int tmp = 0; //fiadd 랑 비교할거
        int tmpGoal = goal;
        while (tmpGoal > 0){
            tmp += lst[i].cost;
            tmpGoal -= lst[i].cli;
        }
        if (fiadd > tmp) fiadd = tmp;
    }

    tc += fiadd;

    cout << tc;
    return 0;

}