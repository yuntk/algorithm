//https://www.acmicpc.net/problem/11053
//LIS
//수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
//
//예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[1000];
int cache[1000];

int search(int num, int pos) {
    if (pos < 0) return 0;
    int &ret = cache[pos];

    for (int i = 0; i < pos; ++i) {
        if (arr[i] < num) {
            if (cache[i] > ret) ret = cache[i];
        }
    }
    return ret = ret+1;
}

int main() {
    cin >> n;
    memset(cache,0,sizeof(cache));
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int max = 1;
    int tmp;
    for (int i = 0; i < n; ++i) {
        tmp = search(arr[i],i);
        if(tmp > max) max = tmp;
    }
    cout << max;

}
