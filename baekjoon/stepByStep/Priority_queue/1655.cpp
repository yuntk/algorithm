/*
 * https://www.acmicpc.net/problem/1655
 * 가운데를 말해요
 *
 * 우선순위 큐 문제
 *
 * 가운데 숫자를 출력하는 문제, 작은 부분 큰 부분으로 나누어주었고 큰 부분은 제일 작은 숫자가 탑으로 오도록
 * 작은 부분은 제일 큰 숫자가 탑으로 오도록했다. 새로 입력 받은 숫자 나머지 두 컨테이너의 top()들을 정렬하여
 * 적절히 다시 넣어주면 계속 균형있게 나누어진 두 개의 그룹으로 유지할 수 있다. 시간초과 문제가 있었는데
 * sync_with_stdio 문제였다. 받아서 바로 출력하는 경우 생각보다 많이 발생하니까 그냥 달아놓는게 좋을듯.. clion 매크로로 만들어놔야겠다다
*/


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> big_top, small_top;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b;
    cin >> a;
    cout << a << "\n";
    if (n == 1) return 0;
    cin >> b;
    big_top.push(-max(a, b));
    small_top.push(min(a, b));
    cout << min(a, b) << "\n";
    if (n == 2) return 0;
    int arr[3];
    for (int i = 2; i < n; ++i) {
        cin >> arr[2];
        arr[0] = small_top.top();
        arr[1] = -big_top.top();
        small_top.pop();
        big_top.pop();
        sort(arr, arr + 3);
        if (i % 2 == 0) {
            small_top.push(arr[0]);
            small_top.push(arr[1]);
            big_top.push(-arr[2]);
            cout << small_top.top() << "\n";
        } else {
            small_top.push(arr[0]);
            big_top.push(-arr[1]);
            big_top.push(-arr[2]);
            cout << min(small_top.top(), -big_top.top()) << "\n";
        }
    }
}