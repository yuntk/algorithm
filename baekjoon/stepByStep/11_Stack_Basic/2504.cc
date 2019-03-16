//괄호의 값
//https://www.acmicpc.net/problem/2504

#include <iostream>
#include <stack>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    stack<int> a;
    for(int i = 0; i < str.length(); ++i){//괄호가 정상인지 확인
        if(str[i] == '('){
            a.push(2);
        }else if(str[i] == ')'){
            if(a.empty()) {
                a.push(-1);
                break;
            }
            if(a.top() == 2){
                a.pop();
            }else break;
        }else if(str[i] == '['){
            a.push(3);
        }else{
            if(a.empty()) {
                a.push(-1);
                break;
            }
            if(a.top() == 3){
                a.pop();
            }else break;
        }
    }
    if(!a.empty()) {
        cout << 0;
        return 0;
    }

}