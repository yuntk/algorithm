//수 정렬하기 2
//https://www.acmicpc.net/problem/2751

#include <iostream>

int arr[1000000] = {0,};
int tmp[1000000] = {0,};

using namespace std;
void divide(int start, int end)
{
    if(end - start == 0) return;
    int mid = start + (end-start)/2;
    divide(start, mid);
    divide(mid + 1, end);
    int a = start;
    int b = mid + 1;
    for(int i = start; i <= end; ++i)
    {
        if(a > mid){
            tmp[i] = arr[b]; 
            b++;
        }else if(b > end){
            tmp[i] = arr[a];
            a++;
        }else{
            if(arr[a] >= arr[b]){
                tmp[i] = arr[b];
                b++;
            }else{
                tmp[i] = arr[a];
                a++;
            }
        }
    }
    for(int i = start; i <= end; ++i){
        arr[i] = tmp[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    divide(0,n-1);
    for(int i = 0; i < n; ++i) cout << arr[i] << '\n';
}