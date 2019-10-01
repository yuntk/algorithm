#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> s;
    vector<int> v;
    v.reserve(200000);
    int n,k,size, tmp;
    cin >> n >> k;
    size = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if(size != k){
            if(s.find(tmp) == s.end()) {
                v.push_back(tmp);
                s.insert(tmp);
                ++size;
            }
        }else{
            if(s.find(tmp) == s.end()){
                v.push_back(tmp);
                s.insert(tmp);
                tmp = *v.begin();
                v.erase(v.begin());
                s.erase(tmp);
            }
        }
    }
    cout << size << endl;
    for(int i = size-1; i >= 0; --i){
        cout << v[i] << ' ';
    }

}
