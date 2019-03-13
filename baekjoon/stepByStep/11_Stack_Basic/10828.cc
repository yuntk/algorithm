//스택
//https://www.acmicpc.net/problem/10828

#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string cmd_fir = "";
    int cmd_sec = 0;
    int stack_p = 0;
    int arr[10000];
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> cmd_fir;
        if(cmd_fir == "push"){
            cin >> cmd_sec;
            arr[stack_p] = cmd_sec;
            ++stack_p;
        }else if(cmd_fir == "pop"){
            --stack_p;
            if(stack_p != -1) cout << arr[stack_p] << "\n";
            else {
                ++stack_p;
                cout << -1 << "\n";
            }
        }else if(cmd_fir == "size"){
            cout << stack_p << "\n";
        }else if(cmd_fir == "empty"){
            if(stack_p == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else if(cmd_fir == "top"){
            if(stack_p != 0) cout << arr[stack_p-1] << "\n";
            else cout << -1 << "\n";
        }
    }
}
