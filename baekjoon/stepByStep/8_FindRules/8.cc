//방 번호
//https://www.acmicpc.net/problem/1475

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int tmp;
    int arr[10] = {0,};
    do{
        arr[n%10]++;
    }while((n=n/10) != 0);
    arr[6] = (arr[6]+arr[9])/2 + (arr[6]+arr[9])%2;
    arr[9] = 0;
    sort(arr,arr+10);
    cout << arr[9];
}