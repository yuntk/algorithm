#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector<char> Parenthesis(0);
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            Parenthesis.push_back('(');
        } else {
            if(Parenthesis.empty()) return false;
            else Parenthesis.pop_back();
        }
    }
    if(Parenthesis.empty()) return true;
    else return false;
}

int main(){
    cout << solution("((()))") << endl;
    string k = "abcdef";
    cout << k[k.size()-1];
}