#include <iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    
    int arr[8];
    bool order = true;
    for(int i = 0; i < 8; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < 7; ++i){
        if(order && i == 0){
            if(arr[i] > arr[i+1]) order = false;
        }else if(order){
            if(arr[i] > arr[i+1]){
                cout << "mixed";
                return 0;
            }
        }else{
            if(arr[i] < arr[i+1]){
                cout << "mixed";
                return 0;
            }
        }
    }
    cout << (order ? "ascending" : "descending");

}