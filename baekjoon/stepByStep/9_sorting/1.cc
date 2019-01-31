#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i]; 
    }
    int tmp;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for(int i = 0; i < n; ++i) cout << arr[i];
}