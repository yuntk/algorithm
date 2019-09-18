#include <string>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>

using namespace std;

int n = 0;
vector<vector<int>> v;
int ans = -1;



class Pos
{
public:
	int y1;
	int x1;
	int y2;
	int x2;
	Pos(int y1_, int x1_, int y2_, int x2_) {
		if (y1_ == y2_) {
			y1 = y1_;
			x1 = x1_ > x2_ ? x2_  : x1_;
			y2 = y2_;
			x2 = x1_ < x2_ ? x2_ : x1_;
		} else
		if (x1_ == x2_) {
			y1 = y1_ > y2_ ? y2_ : y1_;
			y2 = y1_ < y2_ ? y2_ : y1_;
			x1 = x1_;
			x2 = x2_;
		}
		else {
			y1 = y1_;
			x1 = x1_;
			y2 = y2_;
			x2 = x2_;
		}
	}
	bool operator == (Pos& p) {
		if (y1 == p.y1 && x1 == p.x1 && y2 == p.y2 && x2 == p.x2) return true;
		if (y1 == p.y2 && x1 == p.x2 && y2 == p.y1 && x2 == p.x1) return true;
		return false;
	}
	bool operator < (const Pos& p) const {
		if (y1 == p.y1 && x1 == p.x1 && y2 == p.y2 && x2 == p.x2) return false;
		if (y1 == p.y2 && x1 == p.x2 && y2 == p.y1 && x2 == p.x1) return false;
		if (y1 < p.y1) return true;
		if (y1 > p.y1) return false;
		if (x1 < p.x1) return true;
		if (x1 > p.x1) return false;
		if (y2 < p.y2) return true;
		if (y2 > p.y2) return false;
		if (x2 < p.x2) return true;
		if (x2 > p.x2) return false;
		return false;
	}
private:

};

list<pair<Pos, int>> q;
set<Pos> visit;

void bfs(Pos pos, int step) {
	if (pos.x1 < 0 || pos.x1 >= n) return;
	if (pos.x2 < 0 || pos.x2 >= n) return;
	if (pos.y1 < 0 || pos.y1 >= n) return;
	if (pos.y2 < 0 || pos.y2 >= n) return;
	if (v[pos.y1][pos.x1] == 1) return;
	if (v[pos.y2][pos.x2] == 1) return;
	if (visit.find(pos) != visit.end()) return;
	if (pos.x1 == n - 1 && pos.y1 == n - 1) ans = step;
	if (pos.x2 == n - 1 && pos.y2 == n - 1) ans = step;
	q.push_back(make_pair(pos, step));
	visit.insert(pos);
}

int solution(vector<vector<int>> board) {
	n = board.size();
	v = board;
	
	q.push_back(make_pair(Pos(0, 0, 0, 1),0));
	int y1, x1, y2, x2;
	int step;
	while (!q.empty())
	{
		y1 = q.front().first.y1;
		x1 = q.front().first.x1;
		y2 = q.front().first.y2;
		x2 = q.front().first.x2;
		step = q.front().second;
		q.pop_front();
		bfs(Pos(y1, x1 - 1, y2, x2 - 1), step + 1);
		bfs(Pos(y1, x1 + 1, y2, x2 + 1), step + 1);
		bfs(Pos(y1 - 1, x1, y2 - 1, x2), step + 1);
		bfs(Pos(y1 + 1, x1, y2 + 1, x2), step + 1);
		if (y1 == y2) { //가로일때
			if (y1 - 1 >= 0) {
				if (v[y1 - 1][x1] != 1 && v[y2 - 1][x2] != 1) {//자리있어서 회전가능
					bfs(Pos(y1 - 1, x1 + 1, y2, x2), step + 1);
					bfs(Pos(y2 - 1, x2 - 1, y1, x1), step + 1);
				}
			}
			if (y1 + 1 < n) {
				if (v[y1 + 1][x1] != 1 && v[y2 + 1][x2] != 1) {//자리있어서 회전가능
					bfs(Pos(y2, x2, y1 + 1, x1 + 1), step + 1);
					bfs(Pos(y1, x1, y2 + 1, x2 - 1), step + 1);
				}
			}
		}
		else { //세로일때
			if (x1 - 1 >= 0) {
				if (v[y1][x1-1] != 1 && v[y2][x2-1] != 1) {//자리있어서 회전가능
					bfs(Pos(y1 + 1, x1 -1, y2, x2), step + 1);
					bfs(Pos(y2 - 1, x2 - 1, y1, x1), step + 1);
				}
			}
			if (x1 + 1 < n) {
				if (v[y1][x1 + 1] != 1 && v[y2][x2 + 1] != 1) {//자리있어서 회전가능
					bfs(Pos(y2, x2, y1+1, x1+1), step + 1);
					bfs(Pos(y1, x1, y2-1, x2+1), step + 1);
				}
			}
		}
		
		if (ans >= 0) return ans;

	}
	return 0;
}


//int main() {
//	vector<vector<int>> in = {{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}};
//	
//	int ans = solution(in);
//	cout << ans;
//	//for (auto a:ans) cout << a << "\n";
//}