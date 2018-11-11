#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int N;
int number[11];
int op[10];
int opnum[4];
int result;
int min = 1000000000;
int max = -1000000000;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> number[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> opnum[i];
    }
    for(int i = 0; i < N-1; i++){
        if(opnum[0] > 0){
            op[i] = 0;
            opnum[0]--;
        } else if(opnum[1] > 0){
            op[i] = 1;
            opnum[1]--;
        } else if(opnum[2] > 0){
            op[i] = 2;
            opnum[2]--;
        } else if(opnum[3] > 0){
            op[i] = 3;
            opnum[3]--;
        }
    }
    do {
        result = number[0];
        for(int i = 0; i < N-1; i++){
            if(op[i] == 0) result += number[i+1];
            else if(op[i] == 1) result -= number[i+1];
            else if(op[i] == 2) result *= number[i+1];
            else if(op[i] == 3) result /= number[i+1];
        }
        if(result > max) max = result;
        if(result < min) min = result;
    } while ( next_permutation(op,op+N-1) );
    cout << max << '\n';
    cout << min << '\n';
}