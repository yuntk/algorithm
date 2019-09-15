/*
 * https://algospot.com/judge/problem/read/PACKING
 * 짐싸기 문제,
 * 어떤 짐을 포함하는지 찾기 위해서 실행결과를 다시 추적함, 경우가 짐을 포함한다. 안한다 두가지 밖에 없다.
 * 때문에 다음 상태와 비교해 짐을 포함하는지 역추적 할 수 있다. LIS(Longest Increase Sequence)에서 답을 추적하기 위해서는
 * 해당 상태에서 어떤 선택을 했었는지 기록을 해야하는 것과는 조금 다름, LIS는 선택지가 많기때문에 답안이 된 케이스가
 * 어떤 선택을 따랐는지 기록해야함
 * 역 추적시에 DP를 다시 사용하는데 이미 cache 를 이용해서 값을 다 저장해놨기 때문에 재귀 호출 없이 해결됨
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int TC, N, W;
string name[100];
int capacity[100];
int value[100];
int cache[1001][100];

int dp(int weight, int item) {
    if (item == N) return 0;
    int &ret = cache[weight][item];
    if (ret != -1) return ret;
    ret = dp(weight, item + 1);
    if (weight >= capacity[item]) {
        return ret = max(ret, dp(weight - capacity[item], item + 1) + value[item]);
    }
    return ret;
}

void search(int weight, int item, vector<int> &list) {
    if (item == N)return;
    if(dp(weight,item) == dp(weight,item+1)){
        search(weight,item+1, list);
    }else{
        list.push_back(item);
        search((weight-capacity[item]),item+1,list);
    }
}

int main() {
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        memset(cache, -1, sizeof(cache));
        cin >> N >> W;
        for (int j = 0; j < N; ++j) {
            cin >> name[j] >> capacity[j] >> value[j];
        }
        vector<int> packlist;
        cout << dp(W,0);
        search(W,0,packlist);
        cout << " " << packlist.size() << "\n";
        for(int i : packlist){
            cout << name[i] << "\n";
        }
    }
}