//크로아티아 알파벳
//https://www.acmicpc.net/problem/2941
#include <iostream>
#include <string>

using namespace std;

void replace_all(string &str, string from, string to){
    size_t pos = 0;
    while((pos = str.find(from,pos)) != string::npos){
        str.replace(pos,from.size(),to);
        pos += to.size();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    replace_all(str, "c=", "a");
    replace_all(str, "c-", "a");
    replace_all(str, "dz=", "a");
    replace_all(str, "d-", "a");
    replace_all(str, "lj", "a");
    replace_all(str, "nj", "a");
    replace_all(str, "s=", "a");
    replace_all(str, "z=", "a");
    cout << str.size();
}
