//https://www.acmicpc.net/problem/11866
//조세퍼스 문제 0

#include <iostream>
#include <list>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    int n,m;

    cin >> n >> m;
    list<int> lst;
    for(int i = 0; i < n; ++i) lst.push_back(i+1);
    list<int>::iterator itr = next(lst.begin(),m-1);
    int count = 0;
    cout << '<';
    while(lst.size() != 1){
        if(count++ % m == 0){
            cout << *itr << ", ";
            lst.erase(itr--);
        } 
        if(itr == --lst.end()) itr = lst.begin();
        else itr++;
    }
    cout << *lst.begin() << '>';
}