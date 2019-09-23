#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n,e;
    int a,b;
    cin >> n >> e;
    if(n<= 6){ cout << e; return 0;}

    vector<vector<int>> vertex(7);
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        vertex[a-1].push_back(b-1);
    }

    int tmp,max = 0;
    int numbering[7];
    set<pair<int,int>> se;
    for(int i = 0; i < 7; ++i){
        for(int j = i+1; j < 7; ++j){
            se.clear();
            tmp = 1;
            for (int k = 0; k < 7; ++k) {
                if(k == i || k == j) {
                    numbering[k] = 0;
                }else {
                    numbering[k] = tmp;
                    tmp++;
                }
            }
            for(int k = 0; k < 7; ++k){
                for(auto v : vertex[k]){
                    if(numbering[k] > numbering[v]) se.insert(make_pair(numbering[v],numbering[k]));
                    else se.insert(make_pair(numbering[k],numbering[v]));
                }
            }
            if(se.size() > max) max = se.size();

        }
    }
    cout << max;
}