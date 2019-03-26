//https://www.acmicpc.net/problem/10845
//큐

#include <iostream>
#include <list>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    string tmp;
    int tmpn;
    list<int> lst;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp == "push") {
            cin >> tmpn;
            lst.push_back(tmpn);
        } else if (tmp == "pop") {
            if(lst.empty()) cout << -1 << '\n';
            else {
                cout << lst.front() << '\n';
                lst.pop_front();
            }
        } else if(tmp == "size") {
            cout << lst.size() << '\n';
        } else if(tmp == "empty"){
            cout << lst.empty() << '\n';
        } else if(tmp == "front") {
            if(lst.empty()) cout << -1 << '\n';
            else cout << lst.front() << '\n';
        } else if(tmp == "back") {
            if(lst.empty()) cout << -1 << '\n';
            else cout << lst.back() << '\n';
        }
    }
}
