//그룹 단어 체커
//https://www.acmicpc.net/problem/1316
#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    string word;
    int count = 0;
    int alpb[26] = {0,};
    bool newchar = true;
    bool groupword = true;
    char prevchar = ' ';
    for(int i = 0; i < n; ++i) 
    {
        cin >> word;
        groupword = true;
        newchar = true;
        prevchar = ' ';
        for(auto &a : alpb) a = 0;
        for(char ch : word){
            if(prevchar == ch) newchar = false;
            else newchar = true;
            prevchar = ch;
            if(newchar && alpb[ch-'a'] != 0)
            {
                groupword = false;
                break;
            }
            else if(newchar) alpb[ch-'a']++;
        }
        if(groupword)count++;
    }
    cout << count;
    
}
