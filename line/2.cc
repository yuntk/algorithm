#include <iostream>
#include <queue>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int pos = 0;
    queue<string> str;
    queue<int> num;
    for( ; pos < s.length(); ++pos){
        if('0' <= s[pos] && '9' >= s[pos]) break;
        if(s[pos] >= 'A' && s[pos] <= 'Z') {
            if(pos+1 < s.length()) {
                if(s[pos+1] >= 'a' && s[pos+1] <= 'z'){
                    str.push(s.substr(pos,2));
                }else str.push(s.substr(pos,1));
            }else str.push(s.substr(pos,1));
        }
    }
    for( ; pos < s.length(); ++pos){
        if('2' <= s[pos] && '9' >= s[pos]){
            num.push((int)s[pos] - 48);
        }else if(s[pos] == '1'){
            if(pos+1 < s.length()) {
                if(s[pos+1] == '0'){
                    num.push(10);
                }else num.push(1);
            }else num.push(1);
        }
    }
    if(str.size() == num.size()) {
        while(!str.empty()){
            cout << str.front();
            if(num.front() != 1) cout << num.front();
            str.pop();
            num.pop();
        }
    }else cout << "error";
}
