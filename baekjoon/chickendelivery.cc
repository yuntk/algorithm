#include <iostream>
#include <cmath>
int N,M;
int min_dist = 9999;
int map[50][50];

using namespace std;

int cal_chicken(){
    int num = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 2){
                num++;
            }
        }
    }
    return num;
}

int cal_dist(int y, int x){
    int min = 100;
    int tmp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 2){
                tmp = abs(i-y) + abs(j-x);
                min = tmp < min ? tmp : min; 
            }
        }
    }
    return min;
}
int cal_dist_sum(){
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                sum += cal_dist(i,j);
            }
        }
    }
    return sum;
}
void select(int selected_number, int idx_y, int idx_x){
    if(selected_number == M){
        int tmp = cal_dist_sum();
        min_dist = tmp < min_dist ? tmp : min_dist;
        return;
    }
    for(int i = idx_y; i < N; i++){
        if(i == idx_y){
            for(int j = idx_x; j < N; j++){
                if(map[i][j] == 2){
                    map[i][j] = 0;
                    select(selected_number - 1, i, j+1);
                    map[i][j] = 2;
                }
            }
        } else {
            for(int j = 0; j < N; j++){
                if(map[i][j] == 2){
                    map[i][j] = 0;
                    select(selected_number - 1, i, j);
                    map[i][j] = 2;
                }
            }
        } 
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    select(cal_chicken(), 0, 0);
    cout << min_dist << '\n';

}