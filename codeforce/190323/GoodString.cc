#include <iostream>


using namespace std;
int main(){
    int n;
    cin >> n;
    int tmp;
    int is_one;
    char tmpch;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        is_one = 0;
        for(int j = 0; j < tmp; ++j){
            cin >> tmpch;
            if(tmpch == '>' && j == 0) break;
            if(tmpch == '>') is_one = 1;
            if(tmpch == '<') is_one = 0;
        }
        cout << is_one << endl;
    }
}