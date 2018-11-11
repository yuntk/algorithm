#include <iostream>
#include <algorithm>

using namespace std;
int child[9];

int swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int permutation(int n, int r){
    if(r == 0){
        int sum = 0;
        for(int i = 0; i < 7; i++){
            sum += child[i];
        }
        if(sum == 100){
            sort(child,child+7);
            for(int i = 0; i < 7; i++){
                cout << child[i] << endl;
            }
            exit(0);
        }
        
    }

    for(int i = n-1; i >= 0; i--){
        swap(&child[i], &child[n-1]);
        permutation(n-1, r-1);
        swap(&child[i], &child[n-1]);
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        cin >> child[i];
    }
    permutation(9,9);
    
}