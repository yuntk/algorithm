/*
 * https://www.acmicpc.net/problem/11657
 * 벨만포드 문제,
 * 일단 두 정점사이에 중복 간선이 존재할 수 있다는 점과 입력 순서대로 들어온 간선을 처리하는경우
 * 거대한 음의 사이클이 만들어져서 종만북에 나온 방법인 'INF - 적당한M 보다 작은 경우만 방문 정점으로 처리한다' 라는 방법으로 풀이가 어려워진다.
 * 나는 long long에 엄청 큰 INF값을 잡아서 해결을하고 또 추가로 문제의 조건인 1번 도시에서 출발해서 만날 수 있는 음의 사이클이 존재하는 경우만
 * -1을 출력한다는 부분을 해결하기 위해 마지막 갱신이 일어난 지점을 다 기록하고 해당 정점들이 1과 연결된 지점인지 확인하는 방법을 택했다.
 *  이 경우는 정점과 간선의 갯수가 증가하면 조금 어려울 것 같다.
 *
 * 문제를 해결하고 다른 풀이를 보니 대부분 upper를 갱신해주는 시기에 start지점이 INF인지 확인을 하였다.
 * 이렇게 해주면 출발지점에서 닿지 않는 부분은 아예 갱신이 일어나지 않는다. 대신 출발지점과 관계가 없는 음의 사이클을 탐지하지 못한다.
 *
 * 정리하자면
 * 1. 출발지점에서 발생한 갱신만 기록하는 경우 -> 출발지점에서 시작된 음의 사이클 탐지가능, 도달 불가능 지점 탐지 쉬움
 * 2. INF체크를 하지 않아서 출발지점이 아닌 음의 간선을 가지는 모든 경우를 계속 업데이트 하는 경우
 *    -> 출발지와 상관 없는 음수 사이클도 발견 가능, 도달 불가능 지점 가능하나 INF와 M값을 적절히 잘 찾아줘야함
 *
 *
 * 문제 :
 * N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다. 각 버스는 A, B, C로 나타낼 수 있는데,
 * A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 경우가 있다. C = 0인 경우는
 * 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.
 * 1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.
 */


#include <iostream>
#include <vector>

#define INF 2000000000000000

using namespace std;

long long vn, en;
long long upper[501];
vector<vector<pair<long long,long long>>> vertex(501);

int main(){
    cin >> vn >> en;
    long long start, dest, len;
    for (long long i = 0; i < en; ++i) {
        cin >> start >> dest >> len;
        vertex[start].push_back(make_pair(dest, len));
    }

    fill_n(upper, 501, INF);
    upper[1] = 0;
    bool updated = false;
    vector<long long> cycle;
    for(long long i = 0; i < vn; ++i){
        updated = false;
        for (long long j = 1; j <= vn; ++j) {
            for(pair<long long,long long> v : vertex[j]){
                start = j;
                dest = v.first;
                len = v.second;
                if(upper[dest] > upper[start] + len){
                    if(i == vn -1){
                        cycle.push_back(start);
                        cycle.push_back(dest);
                    }
                    upper[dest] = upper[start] + len;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) {
        bool connected_cycle = false;
        for(long long v : cycle){
            if(upper[v] < INF - (long long)10000*500*6000) connected_cycle = true;
        }
        if(connected_cycle){
            cout << -1;
            return 0;
        }
    }
    for (long long i = 2; i <= vn; ++i) {
        if(upper[i] < INF - (long long)10000*500*6000) cout << upper[i] << "\n";
        else cout << -1 << "\n";
    }
}