#include <string>
#include <vector>
#include <set>

#include <iostream>
using namespace std;

vector<vector<int>> keylist;
vector<vector<int>> candikeylist;
int rownum, colnum;

void dfs(int start, int picknum, vector<int> vec){
	if (picknum == 0){
		keylist.push_back(vec);
	}
	for (int i = start; i < colnum; ++i){
		vec.push_back(i);
		dfs(i + 1, picknum - 1, vec);
		vec.pop_back();
	}
}

bool isSubSet(vector<int> as, vector<int> bs){ //subset찾기
	bool isSubSet = true;
	bool isFind = false;
	for (int a : as){
		isFind = false;
		for (int b : bs){
			if (a == b) isFind = true;
		}
		if (!isFind) isSubSet = false;
	}
/*	if (isSubSet){
		cout << "as:";
		for (int a : as) cout << a << ' ';
		cout << "\nbs:";
		for (int b : bs) cout << b << ' ';
		cout << "\n";
	}
	*/
	return isSubSet;
}

int solution(vector<vector<string>> relation) {
	rownum = relation.size();
	colnum = relation[0].size();
	for (int i = 1; i <= colnum; ++i){ //combination list
		vector<int> vec;
		dfs(0, i, vec);
	}
	bool iscandi;
	for (auto v : keylist){
		set<string> tmpset;
		iscandi = true;
		for (int i = 0; i < rownum; ++i){
			string tmpstr = "";
			for (auto a : v){
				tmpstr += relation[i][a];
			}
			if (tmpset.find(tmpstr) != tmpset.end()){//중복이면
				iscandi = false;
			}
			else tmpset.insert(tmpstr);
		}
		if (iscandi) candikeylist.push_back(v);
	}
	/*
	for (vector<int> keys : candikeylist){
		for (int key : keys) cout << key << " ";
		cout << "\n";
	}
	*/
	for (int i = 0; i < candikeylist.size(); ++i){ //subset지우기, i 변화가 저게 맞는지 점검 필요
		for (int j = 0; j < candikeylist.size(); ++j){
			if (i != j){
				if (isSubSet(candikeylist[i], candikeylist[j])){
					candikeylist.erase(candikeylist.begin() +j);
					j--;
				}
			}
		}
	}

	
	int answer = candikeylist.size();
	return answer;
}



int main(){
	vector<vector<string>> in = {
		{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}
	};
	int ans = solution(in);
	cout << ans;
	//for (auto a:ans) cout << a << "\n";
}