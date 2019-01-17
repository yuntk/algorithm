//다이얼
//https://www.acmicpc.net/problem/5622
#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    int sum = 0;
    for(auto ch : a)
    {
        if(ch < 'P') sum += (ch-'A')/3 + 3;
        else if(ch < 'T') sum += 8;
        else if(ch < 'W') sum += 9;
        else sum += 10; 
    }
    cout << sum;
}
