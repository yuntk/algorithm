#include <iostream>


using namespace std;
int main(){
    int ball_W,ball_H;
    int stone_W,stone_H;
    int stone_two_W, stone_two_H;
    cin >> ball_W >> ball_H >> stone_W >> stone_H >> stone_two_W >> stone_two_H;
    for(int i = ball_H; i >= 0; i--){
        
        ball_W += i;
        //cout << ball_W << endl;
        if(i == stone_H) ball_W = ball_W >= stone_W ? ball_W - stone_W : 0;
        
        if(i == stone_two_H) ball_W = ball_W >= stone_two_W ? ball_W - stone_two_W : 0;
        //cout << ball_W << endl;
    }
    cout << ball_W;
}