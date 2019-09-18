#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	int counter = 0;
	bool isMatched = false;
	for (string query : queries) {
		counter = 0;
		for (string word : words) {
			isMatched = true;
			if (query.length() == word.length()) {
				for (int i = 0; i < query.length(); ++i) {
					if (query[i] != '?')
						if (query[i] != word[i]) isMatched = false;
				}
			}
			else isMatched = false;
			if (isMatched) counter++;
		}
		answer.push_back(counter);
	}


	return answer;
}

//int main() {
//	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao"
//
//	};
//	vector<string> queries = {
//		"fro??", "????o", "fr???", "fro???", "pro?"
//	};
//	
//	vector<int> ans = solution(words,queries);
//	//cout << ans;
//	for (auto a:ans) cout << a << "\n";
//}