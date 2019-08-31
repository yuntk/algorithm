#include <iostream>
#include <set>
using namespace std;
int main(){
    int n;
    int arr[10000];
    set<int> se;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 0; i < n; ++i){
        se.insert(arr[i]);
        se.erase(i+1);
        if(se.empty()) count++;
    }
    cout << count;

}
