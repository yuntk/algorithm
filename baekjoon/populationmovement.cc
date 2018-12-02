#include <iostream>
#include <vector>

int N, L, R;
int map[50][50];
bool visited[50][50];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool movement = true;
int count = 0;
int sum;

struct NODE {
    int y;
    int x;
};
std::vector<NODE> union_list;

using namespace std;

int clear_visit(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = false;
        }
    }
}

int abs(int x){
    return x >= 0 ? x : -x;
}

int search(int y, int x){
    if(visited[y][x]) return 0;
    visited[y][x] = true;
    sum += map[y][x];
    union_list.push_back({y,x});
    int tmpy,tmpx;
    for(int i = 0; i < 4; i++) {
        tmpy = y + dy[i];
        tmpx = x + dx[i];
        if(tmpy >= 0 && tmpy < N && tmpx >= 0 && tmpx < N){
            int tmp = abs(map[y][x] - map[tmpy][tmpx]);
            if(tmp >= L && tmp <= R){
                search(tmpy, tmpx);
            }
        }
    }
}

int main(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    NODE tmp;
    while(movement){
        movement = false;
        clear_visit();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                sum = 0;
                union_list.clear();
                search(i,j);
                int length = union_list.size();
                if(length > 1){
                    int avg = sum / length;
                    movement = true;
                    for(int k = 0; k < length; k++){
                        tmp = union_list.back();
                        union_list.pop_back();
                        map[tmp.y][tmp.x] = avg;
                    }
                }
            }
        }
        if(movement) count++;
    }
    cout << count << '\n';
    
}
