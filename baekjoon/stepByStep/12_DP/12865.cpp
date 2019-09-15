//https://www.acmicpc.net/problem/12865
//평범한 배낭
//
//이 문제는 아주 평범한 배낭에 관한 문제이다.
//
//한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.
//
//준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K무게까지의 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

#include <iostream>
#include <cstring>

using namespace std;

int N;
int K;
int w[100];
int v[100];
int cache[100001][100];

int dp(int capacity, int item){
    if(item == N) return 0;
    int &ret = cache[capacity][item];
    if(ret != -1) {
        return ret;
    }

    ret = dp(capacity, item+1);
    if(capacity >= w[item])
        return ret = max(ret, dp(capacity-w[item], item+1) + v[item]);
    return ret;
}

int main(){
    cin >> N >> K;
    memset(cache,-1,sizeof(cache));
    for(int i = 0; i < N; ++i){
        cin >> w[i] >> v[i];
    }
    cout << dp(K,0);
}