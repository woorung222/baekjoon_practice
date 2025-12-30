/*오답. 반례로는 1,3,4 가 기본부품이지만 2가 기본부품이 아닐수도 있음. 여기서는 그런 가능성을 배제하고
내침차순으로 정렬함. 정답은 위상정렬 그래프를 사용해야 함.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct storage{
    int total = 0;
    bool isBasic = true;
};

struct rule{
    int target;
    int need;
    int amount;
};

bool cmp(const rule &x, const rule &y){
    return x.target > y.target;
}

int main(){
    int ttl;
    cin >> ttl;
    int ruleno;
    cin >> ruleno;
    vector<rule> rules(ruleno);
    for ( int i = 0; i < ruleno; i ++){
        int A,B,C;
        cin >> A >> B >> C;
        rules[i].target = A;
        rules[i].need = B;
        rules[i].amount = C;
    }
    sort(rules.begin(),rules.end(),cmp);
    vector <storage> ans(ttl);
    ans[ttl-1].total = 1;
    ans[ttl-1].isBasic = false;
    for ( int i = 0; i < ruleno; i++) {
        int cTargetTotal;
        cTargetTotal = ans[rules[i].target-1].total;
        ans[rules[i].need-1].total += cTargetTotal * rules[i].amount;
        ans[rules[i].target-1].isBasic = false;
    }
    for (int i = 0; i < ttl; i ++){
        if (ans[i].isBasic == true) cout << i+1<< " "<<ans[i].total << "\n";
    }
    return 0;
 }