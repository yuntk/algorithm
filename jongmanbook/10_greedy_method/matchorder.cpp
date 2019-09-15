/*
 * https://algospot.com/judge/problem/read/MATCHORDER
 *
 * * multiset 다루기
 * * 가장 큰 원소를 찾으려면 rbegin()을 쓸 것 end()는 끝원소+1을 가리킨다.
 * * rbegin()과 rend()를 통해서 역순으로 출력도 가능하다 for문에 iterator 를 초기화 시켜서 사용함, 이때 reverse_iterator 가 따로 있다.
 * * ex)
 * * for(multiset<int>::reverse_iterator iter = mset.rbegin(); iter != mset.rend(); ++iter){
 * *     cout << *iter << endl;
 * * }
 * * lower_bound(x)에서 x가 해당 셋에 없을 경우 x 보다 큰 첫 번째 iter를 반환 : x보다 크거나 같은 첫번째 값
 * * upper_bound(x) x보다 큰 첫번째 위치
 *
 *
 * 전세계 최대의 프로그래밍 대회 알고스팟 컵의 결승전이 이틀 앞으로 다가왔습니다. 각 팀은 n명씩의 프로 코더들로 구성되어 있으며,
 * 결승전에서는 각 선수가 한 번씩 출전해 1:1 경기를 벌여 더 많은 승리를 가져가는 팀이 최종적으로 우승하게 됩니다.
 * 각 팀의 감독은 대회 전날, 주최측에 각 선수를 출전시킬 순서를 알려 주어야 합니다.
 */

#include <iostream>
#include <set>

using namespace std;

int russian[100];
int korean[100];
int pn;

int main() {
    int tcn;
    cin >> tcn;
    for (int i = 0; i < tcn; ++i) {
        cin >> pn;
        for (int j = 0; j < pn; ++j) {
            cin >> russian[j];
        }
        for (int j = 0; j < pn; ++j) {
            cin >> korean[j];
        }
        int win = 0;
        multiset<int> ko(korean, korean + pn);
        for (int j = 0; j < pn; ++j) {
            if (russian[j] > *ko.rbegin()) ko.erase(ko.begin()); // 남은 한국선수중 가장 큰점수가 러시아 선수보다 낮으면 가장 낮은 선수 보내고 짐
            else {
                ++win;
                //cout << "russian[j] : " << russian[j] << " lower_bound : " << *ko.lower_bound(russian[j]) << endl;
                ko.erase(ko.lower_bound(russian[j]));
            }
        }
        cout << win << endl;
    }
}