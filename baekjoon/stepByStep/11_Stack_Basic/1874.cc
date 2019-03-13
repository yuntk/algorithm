//스택수열
//https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<int> st;
    queue<int> input;
    char result[200000];

    int num = 0;
    int tmp = 0;
    cin >> num;
    for(int i = 0; i < num; ++i){
        cin >> tmp;
        input.push(tmp);
    }
    
    int p = 0;
    for(int i = 1; i <= num; ++i){
        st.push(i);
        result[p] = '+';
        ++p;
        while(!input.empty() && !st.empty() && st.top() == input.front()){
            result[p] = '-';
            ++p;
            st.pop();
            input.pop();
        }
    }
    if(st.empty() && input.empty()) {
        for(int i = 0; i < num*2; ++i){
            cout << result[i] << '\n';
        }
    }else cout << "NO";
}

