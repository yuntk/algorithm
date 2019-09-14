/*
 * https://www.acmicpc.net/problem/1463
 * 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
 * X가 3으로 나누어 떨어지면, 3으로 나눈다.
 * X가 2로 나누어 떨어지면, 2로 나눈다.
 * 1을 뺀다.
 * 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

queue<pair<int,int>> q;
short isVisit[1000001];
int result = -1;
void bfs(int num, int step){
    if(num == 1) {
        result = step;
        return;
    }
    if(num < 1) return;
    if(num > 1000000) return;
    if(isVisit[num] ==-1){
        isVisit[num] = 1;
    }else return;
    if(num%3 == 0) q.push(make_pair(num/3,step+1));
    if(num%2 == 0) q.push(make_pair(num/2, step+1));
    q.push(make_pair(num-1,step+1));

}

int main(){
    memset(isVisit,-1,sizeof(isVisit));
    int n;
    cin >> n;
    q.push(make_pair(n,0));
    int num,step;
    while(!q.empty()){
        num = q.front().first;
        step = q.front().second;
        q.pop();
        bfs(num,step);
        if(result != -1) break;
    }
    cout << result;
    return 0;
}
