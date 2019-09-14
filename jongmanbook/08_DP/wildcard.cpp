/* https://algospot.com/judge/problem/read/WILDCARD
 *
 *
 *
 */


#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;
int tcn;
string wcs;
int fn;
string filename[50];
string fns;
int cache[101][101];

bool match(int wcpos, int fnpos){
    int& ret = cache[wcpos][fnpos];
    if(ret != -1) return ret;
    while(wcpos < wcs.size() && fnpos < fns.size()){
        if(wcs[wcpos] == '?' || fns[fnpos] == wcs[wcpos]){
            ++wcpos;
            ++fnpos;
        }else break;
    }
    if(wcpos == wcs.size()) return ret = (fnpos == fns.size());
    if(wcs[wcpos] == '*'){
        return ret = (match(wcpos+1,fnpos) || match(wcpos,fnpos+1));
    }
    return ret = false;
}


int main() {
    cin >> tcn;
    for(int j = 0; j < tcn; ++j){
        vector<string> matchlist;
        cin >> wcs;
        cin >> fn;
        for(int i = 0; i < fn; ++i){
            memset(cache,-1, sizeof(cache));
            cin >> fns;
            if(match(0,0)) matchlist.push_back(fns);
        }
        sort(matchlist.begin(),matchlist.end());
        for(auto s : matchlist) {
            cout << s << "\n";
        }
    }
    return 0;
}