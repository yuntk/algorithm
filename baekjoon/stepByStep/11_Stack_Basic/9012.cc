//괄호
//https://www.acmicpc.net/problem/9012

#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int num = 0;
    cin >> num;
    string parenthesis;
    int count = 0;
    for(int i = 0; i < num; ++i){
        cin >> parenthesis;
        for(int j = 0; j < parenthesis.length(); ++j){
            if(count < 0){
                break;
            }
            if(parenthesis[j] == '('){
                ++count;
            }else{
                --count;
            }
        }
        if(count == 0){
            cout << "YES" << '\n';
        }else cout << "NO" << '\n';
        count = 0;
    }
}
