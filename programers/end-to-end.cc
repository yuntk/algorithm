#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    vector<string> CompareSet(0);
    CompareSet.push_back(words[0]);
    for(int i = 1; i < words.size(); i++) {
        if(find(CompareSet.begin(), CompareSet.end(), words[i]) != CompareSet.end()
        || (CompareSet[i-1][CompareSet[i-1].size() - 1] != words[i][0])) {
            answer[0] = (i)%n + 1;            
            answer[1] = (i)/n + 1;
            break;
        } else {
            CompareSet.push_back(words[i]);
        }
    }
    return answer;
}

int main(){
    string arr[] = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    vector<string> s(arr, arr + sizeof(arr)/sizeof(std::string));
    vector<int> answer(2, 0);
    answer = solution(3,s);
    cout << answer[0] << ", " << answer[1] << endl;

}