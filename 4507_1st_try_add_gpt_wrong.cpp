#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <queue>

using namespace std;

struct State {
    int pos = 0;              // 현재 word에서 매칭된 위치
    long long sum = 0;        // 사용한 elements 인덱스 합(여기서는 k+1을 더함)
    vector<int> used;         // 사용한 elements 인덱스 기록
};

// used 벡터를 사전식으로 비교 (sum이 같을 때 결정용)
bool lexSmaller(const vector<int> &a, const vector<int> &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    int L = (n < m ? n : m);
    for (int i = 0; i < L; i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return n < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total;
    cin >> total;

    for (int tc = 0; tc < total; tc++) {
        int eLen;
        cin >> eLen;

        vector<string> elements(eLen);
        vector<string> elementsUpper(eLen);

        // elements 입력 + 대문자 변환
        for (int i = 0; i < eLen; i++) {
            cin >> elements[i];
            elementsUpper[i] = elements[i];
            for (int k = 0; k < (int)elementsUpper[i].size(); k++) {
                elementsUpper[i][k] = toupper((unsigned char)elementsUpper[i][k]);
            }
        }

        int wordLen;
        cin >> wordLen;

        vector<string> words(wordLen);
        vector<string> wordsUpper(wordLen);

        // words 입력 + 대문자 변환
        for (int i = 0; i < wordLen; i++) {
            cin >> words[i];
            wordsUpper[i] = words[i];
            for (int k = 0; k < (int)wordsUpper[i].size(); k++) {
                wordsUpper[i][k] = toupper((unsigned char)wordsUpper[i][k]);
            }
        }

        // word 하나씩 처리
        for (int w = 0; w < wordLen; w++) {
            int W = (int)wordsUpper[w].size();

            queue<State> q;
            State start;
            q.push(start);

            bool foundAnswer = false;  // 전체적으로 해답을 찾았는지
            State best;               // 최소 lv 레벨에서 sum이 최소인 해답 1개

            // BFS를 "레벨 단위"로 진행
            while (!q.empty()) {
                int sz = (int)q.size();      // 현재 레벨의 상태 수
                bool foundThisLevel = false; // 이번 레벨에서 완성된 해답이 있었는지

                State bestThisLevel;         // 이번 레벨에서의 최적 해답
                bool hasBestThisLevel = false;

                // 현재 레벨의 상태들을 전부 처리
                for (int t = 0; t < sz; t++) {
                    State cur = q.front();
                    q.pop();

                    // 모든 element 시도
                    for (int k = 0; k < eLen; k++) {
                        int len = (int)elementsUpper[k].size();
                        int st = cur.pos;

                        // 길이 초과면 매칭 불가
                        if (st + len > W) continue;

                        // 부분 비교 (substr 생성 없이)
                        if (wordsUpper[w].compare(st, len, elementsUpper[k]) == 0) {
                            State nxt = cur;
                            nxt.pos = st + len;
                            nxt.sum = cur.sum + (long long)(k + 1); // "합" 기준 (원하면 여기만 바꾸면 됨)
                            nxt.used.push_back(k);

                            // 완성(끝까지 매칭)
                            if (nxt.pos == W) {
                                foundThisLevel = true;

                                // 이번 레벨에서 sum 최소인 1개만 고르기
                                if (!hasBestThisLevel) {
                                    bestThisLevel = nxt;
                                    hasBestThisLevel = true;
                                } else {
                                    if (nxt.sum < bestThisLevel.sum) {
                                        bestThisLevel = nxt;
                                    } else if (nxt.sum == bestThisLevel.sum) {
                                        // sum까지 같으면 사전식으로 하나 고정(출력 안정성)
                                        if (lexSmaller(nxt.used, bestThisLevel.used)) {
                                            bestThisLevel = nxt;
                                        }
                                    }
                                }
                            } else {
                                // 아직 완성이 아니면 다음 레벨 후보로
                                // 단, 이번 레벨에서 이미 완성 해답이 발견된 경우
                                // 더 깊은 레벨은 최소 lv가 아니므로 굳이 쌓을 필요 없음
                                if (!foundThisLevel) {
                                    q.push(nxt);
                                }
                            }
                        }
                    }
                }

                // 이번 레벨에서 완성 해답이 나왔으면, 그 레벨이 "최소 lv"
                if (foundThisLevel) {
                    best = bestThisLevel;
                    foundAnswer = true;
                    break;
                }
                // 아니면 다음 레벨로 계속
            }

            // 출력
            if (!foundAnswer) {
                cout << "Too Obvious\n";
            } else {
                for (int i = 0; i < (int)best.used.size(); i++) {
                    cout << "[" << elements[best.used[i]] << "] ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
