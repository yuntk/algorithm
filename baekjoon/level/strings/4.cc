//https://www.acmicpc.net/problem/1157

#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    string tmp;
    int arr[26] = {0,};
    cin >> tmp;
    for(int i = 0; i < tmp.length(); ++i){
        if(tmp[i] >= 'a' && tmp[i] <= 'z') ++arr[tmp[i]-97];
        else ++arr[tmp[i]-65];
    }
    int max = -1, idx = -1;
    for(int i = 0; i < 26; ++i){
        if(arr[i] > max){
            max = arr[i];
            idx = i;
        }
    }
    sort(arr,&arr[26]);
    if(arr[24] == arr[25]) cout << "?";
    else cout << (char)((int)'A' + idx);
}