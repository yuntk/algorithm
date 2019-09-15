#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[300];
int two[300];
int one[300];
int main() {
    cin >> n;
    memset(arr,0,sizeof(arr));

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    if(n == 1){
        cout << arr[0];
    }
    if(n == 2){
        cout << arr[0]+arr[1];
    }
    two[0] = arr[0];
    one[0] = arr[0];
    two[1] = arr[0]+arr[1];
    one[1] = arr[1];
    for(int i = 2; i < n; ++i){
        two[i] = one[i-1] + arr[i];
        one[i] = arr[i] + (one[i-2] > two[i-2] ? one[i-2] : two[i-2]);
    }
    cout << (one[n-1] > two[n-1] ? one[n-1] : two[n-1]);
}