//단어정렬
//https://www.acmicpc.net/problem/1181

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> vec;

bool compare(string a, string b){
    if(a.length() < b.length()) return true;
    else if(a.length() > b.length()) return false;
    else {
        for(int i = 0; i < a.length(); ++i){
            if(a[i] < b[i]) return true;
            else if(a[i] > b[i]) return false;
        }
        //return true; (X)
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(),compare);
    //중복 문자열 제거
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(auto str : vec){
        cout << str << '\n';
    }
}