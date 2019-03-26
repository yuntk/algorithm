//괄호의 값
//https://www.acmicpc.net/problem/2504

#include <iostream>
#include <stack>

using namespace std;
int find_pair(string s);
int cal_brackets_val(string str);
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
    //정상이면 괄호 값 계산
    cout << cal_brackets_val(str);
}

int find_pair(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == s[0]) st.push(s[i]);
        else if(s[i] == s[0]+2 || s[i] == s[0]+1 ) st.pop();
        if(st.empty()) return i;
    }
}

int cal_brackets_val(string str){
    int result = 0;
    int tmp = 0;
    for(int i = 0; i < str.length(); ++i){
        tmp = find_pair(str.substr(i,str.length()-i));
        if(tmp == 1){
            if(str[i] == '(') result += 2;
            else result += 3;
            ++i;
        }else{
            if(str[i] == '(') result += 2 * cal_brackets_val(str.substr(i+1, tmp-1));
            else result += 3 * cal_brackets_val(str.substr(i+1, tmp-1));
            i += tmp;
        }
    }
    return result;
}