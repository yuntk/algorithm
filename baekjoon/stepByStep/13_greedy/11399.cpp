/*
 * https://www.acmicpc.net/problem/11399
 * ATM
 */

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long sum = 0;
    sum += arr[0];
    for (int i = 0; i < n-1; ++i) {
        arr[i+1] = arr[i+1]+arr[i];
        sum += arr[i+1];
    }
    cout << sum;
}