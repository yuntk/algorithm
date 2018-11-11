#include <iostream>
#include <string.h>

using namespace std;

int rowSize = 0;
int colSize = 0;
int board[100][100];
int cache[100][100];

int myJump(int y, int x) {
    if(y >= rowSize || x >= colSize) return 0;
    int& ret = cache[y][x];
    if(ret > 0) return cache[y][x];
    if(board[y][x] == 0) return 1;
    return ret = (myJump(y + board[y][x], x) || myJump(y, x + board[y][x]));
}

int main() {
    cin >> rowSize >> colSize;
    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < colSize; j++) {
            cin >> board[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << myJump(0,0) << endl;
}