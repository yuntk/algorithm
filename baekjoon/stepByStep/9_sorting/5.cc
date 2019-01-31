//소트인사이드
//https://www.acmicpc.net/problem/1427

#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n = 0;
    int arr[10] = {0,};
    cin >> n;
    do{
        arr[n%10]++;
    }while((n=n/10) != 0);
    for(int i = 9; i >= 0; --i) if(arr[i] > 0){
        cout << i;
        arr[i]--;
        i++;
    }
}