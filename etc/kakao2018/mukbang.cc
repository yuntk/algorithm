//실패

#include <string>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


bool mycmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first < b.first) return true; //첫원소 오름차순
	else if (a.first == b.first) {
		return a.second < b.second; //첫원소 같으면 둘째원소 오름차순
	}
	return false;
}

int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> timeNidx;
	int remainlist[200000];
	int remainelm = food_times.size();
	int answer = 0;
	bool find = false;
	memset(remainlist, -1, 200000);
	for (int i = 0; i < remainelm; ++i) {
		timeNidx.push_back(make_pair(food_times[i], i));
	}
	sort(timeNidx.begin(), timeNidx.end(), mycmp);

	for (int i = 0; i < timeNidx.size(); ++i) {
		if (i == 0) {
			if (k = remainelm * timeNidx[i].first) {
				k -= remainelm * timeNidx[i].first;
				remainelm--;
				remainlist[timeNidx[i].second]++;
			}
			else {
				 
				int idx = k - ((k / remainelm * timeNidx[i].first) * remainelm * timeNidx[i].first);
				for (int i = 0; i < food_times.size(); ++i) {
					if (remainlist[i] == -1) {
						if (find) {
							answer = i+1; break;
						}
						if (idx == 0) {
							find = true;
						}
						else idx--;
					}
				}
				break;



			}
		}
		else {
			if (k = remainelm * (timeNidx[i].first - timeNidx[i-1].first)) {
				k -= remainelm * (timeNidx[i].first - timeNidx[i - 1].first);
				remainelm--;
				remainlist[timeNidx[i].second]++;
			}
			else {

				int idx = k - ((k / remainelm * (timeNidx[i].first - timeNidx[i - 1].first)) * remainelm * (timeNidx[i].first - timeNidx[i - 1].first));
				for (int i = 0; i < food_times.size(); ++i) {
					if (remainlist[i] == -1) {
						if (find) {
							answer = i+1; break;
						}
						if (idx == 0) {
							find = true;
						}
						else idx--;
					}
				}
				break;



			}
		}



		
	}
	


	return answer;
}

int main() {
	vector<int> in = {
		3,1,2
	};
	
	int ans = solution(in,5);
	cout << ans;
	//for (auto a:ans) cout << a << "\n";
}