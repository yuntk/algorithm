//https://programmers.co.kr/learn/courses/30/lessons/42888

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<int,string>> inout;
	map<string, string> idmap;
	string id, nickname;
	string tmp;
	int sppos;

	for (string a : record){
		if (a[0] == 'E'){
			tmp = a.substr(a.find(" ") + 1);
			sppos = tmp.find(" ");
			id = tmp.substr(0, sppos);
			nickname = tmp.substr(sppos + 1);
			idmap[id] = nickname;
			inout.push_back(make_pair(1, id));
		}
		else if (a[0] == 'L'){
			tmp = a.substr(a.find(" ") + 1);
			inout.push_back(make_pair(0, tmp));
		}
		else{
			tmp = a.substr(a.find(" ") + 1);
			sppos = tmp.find(" ");
			id = tmp.substr(0, sppos);
			nickname = tmp.substr(sppos + 1);
			idmap[id] = nickname;
		}
	}
	for (pair<int, string> p : inout){
		if (p.first == 0){
			answer.push_back(idmap[p.second] + "님이 나갔습니다.");
		}
		else
			answer.push_back(idmap[p.second] + "님이 들어왔습니다.");
	}
	return answer;
}

int main(){
	vector<string> str = {
		"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"
	};
	vector<string> ans = solution(str);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << "\n";
}

