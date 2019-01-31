#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int arr[n];
    int count[8001] = {-9999,};
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        count[arr[i] + 4000]++;
        sum += arr[i];
    }
    float avg = sum > 0 ? (float)sum/(float)n + 0.5 : (float)sum/(float)n - 0.5;
    cout << (int)avg;
    
    sort(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout << endl << arr[n/2] << endl;
    int max = -9999;
    bool duplicate = false;
    for(int i = 0; i < 8001; ++i){
        if(count[i] > max){
            max = count[i];
            duplicate = false;
        }else if(count[i] == max) duplicate = true;
    }
    for(int i = 0; i< 8001; ++i){
        if(duplicate && count[i] == max){
            duplicate = false;
        }else if(count[i] == max){
            cout << i - 4000 << endl;
            break;
        }
    }
    cout << arr[n-1] - arr[0];


}