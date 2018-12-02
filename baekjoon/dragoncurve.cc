#include <iostream>
#include <vector>
#include <algorithm>


int coord[101][101];

int endpoint_y = 0;
int endpoint_x = 0;

int move_y[] = {0, -1, 0, 1};
int move_x[] = {1, 0, -1, 0};

using namespace std;

int curve(vector<int> &st){
    int size_of_curve = st.size();
    for(int i = 0; i < size_of_curve; i++){
        int next = (st[size_of_curve-i-1] + 1) % 4;
        st.push_back(next);
        coord[endpoint_y += move_y[next]][endpoint_x += move_x[next]] = 1;
    }
}

int main(){

    int N = 0;
    vector<int> stack;

    cin >> N;

    int x, y, d, g;
    for(int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        coord[y][x] = 1;
        endpoint_y = y + move_y[d];
        endpoint_x = x + move_x[d];
        coord[endpoint_y][endpoint_x] = 1;
        stack.clear();
        stack.push_back(d);
        for(int i = 0; i < g; i++){
            curve(stack);
        }
    }

    int result = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(coord[i][j] && coord[i][j+1] && coord[i+1][j] && coord[i+1][j+1]){
                result++;
            }
        }
    }

    cout << result << "\n";
}