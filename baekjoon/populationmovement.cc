#include <iostream>
#include <vector>

int N, L, R;
int map[50][50];
bool visited[50][50];
//visit으로 방문한 지역인지 아닌지 확인
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
    
    if(visited[y][x]) return 0;//방문한 곳이면 이미 인구 이동이 있었거나 현재 연합에 추가된 상태이기 때문에 함수 종료
    visited[y][x] = true;//방문안한곳이면 
    sum += map[y][x];//값을 sum에 누적해주고
    union_list.push_back({y,x});//연합리스트에 추가
    int tmpy,tmpx;
    for(int i = 0; i < 4; i++) {//여기서 포문을 네번도는데 상하좌우 좌표값을 전부 search
        tmpy = y + dy[i];
        tmpx = x + dx[i];
        if(tmpy >= 0 && tmpy < N && tmpx >= 0 && tmpx < N){ //해당좌표가 테이블범위내이면
            int tmp = abs(map[y][x] - map[tmpy][tmpx]); //값을 현재 받은 값이랑 인접값이랑 절대값 계산해서 연합인지 확인하고
            //연합이면 서치함수를 다시불러서
            if(tmp >= L && tmp <= R){
                search(tmpy, tmpx);//search 함수 내에서 방문 안한곳이면 연합 리스트에 추가 하게 됨
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
    //여기까지 input 받는 부분입니다

    NODE tmp; //연합리스트에서 pop한 값을 임시로 저장하기 위한 변수
    while(movement){
        movement = false;//얘는 인구이동이 있었는지 확인하는 변수인데
        clear_visit();//여기서 방문기록을 다 0으로 초기화 해주고
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){ //이중포문으로 테이블에있는 모든 좌표에 대해서 연합이 있는지 확인을 해줘요
                sum = 0;
                union_list.clear();//연합리스트를 여기에 저장해줄거라서 초기화해주고
                search(i,j);//해당좌표에 대해 연합을 찾기 시작해줘요
                //함수가 끝나면 리스트에 연합이 다 추가되고 추가된 연합은 visited에 체크가 되기때문에
                //for문 다 돌때까지는 해당 연합은 다시 계산하는 일을 막아서 인구 이동을 마친 연합이 재이동을 하지 않도록
                int length = union_list.size(); //이제 아래쪽은 연합크기 계산해서 평균값내고 값 갱신해주는 부분이에요
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
        if(movement) count++; //인구이동이 있었으면 카운트 증가해서 몇번의 이동이 있었는지 
    }
    cout << count << '\n';
    
}
