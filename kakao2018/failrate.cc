#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <functional> //greater<> 사용가능

#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	int useratstage[502];
	int useracc[502];
	double failrate[502];
	multimap<double, int, greater<double>> map;
	memset(useratstage, 0, sizeof(useratstage));
	memset(useracc, 0, sizeof(useracc));
	for (int i : stages){
		useratstage[i]++;
	}
	useracc[N + 1] = useratstage[N + 1];
	for (int i = N; i >= 1; --i){
		useracc[i] = useracc[i + 1] + useratstage[i];
		failrate[i] = (double)useratstage[i] / (double)useracc[i];
	}

	for (int i = 1; i <= N; ++i)map.insert(make_pair(failrate[i], i)); //stable sort, 배열에 담고 sort에 비교 함수 주는게 더 확실 sort 함수 점검해보기
	
	vector<int> answer;
	for (auto a : map){
		answer.push_back(a.second);
	}
	
	return answer;
}

int main(){
	vector<int> stages = {
		2, 1, 2, 6, 2, 4, 3, 3
	};
	vector<int> ans = solution(5, stages);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << "\n";
}