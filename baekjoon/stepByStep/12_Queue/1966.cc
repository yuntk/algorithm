//https://www.acmicpc.net/problem/1966
//프린터 큐

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    int num_doc;
    int pos;
    int arr[100];
    int count;
    for(int i = 0; i < num; ++i){
        cin >> num_doc;
        cin >> pos;
        count = 0;
        fill_n(arr,100,-1);
        for(int j = 0; j < num_doc; ++j){
            cin >> arr[j];
        }
        for(int j = 0; j < num_doc*9; ++j){
            if(arr[j%num_doc] == *max_element(arr,arr+num_doc)) {
                if(j%num_doc == pos){
                    cout << ++count << '\n';
                    break;
                } 
                else {
                    arr[j%num_doc] = -1;
                    ++count;
                }
            }
        }
    }
}
