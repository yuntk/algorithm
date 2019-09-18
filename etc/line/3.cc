#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main()
{
    map<int,vector<string>> t1;
    map<int,vector<string>> t2;

    int t1num;
    vector<string> t1header;
    cin >> t1num;
    string str;
    cin.ignore(256,'\n');
    getline(cin, str);
    int pos = 0;
    for(int i = 0; i <= str.length(); ++i){
        if(str[i] == ' ' || i == str.length()) {
            t1header.push_back(str.substr(pos,i-pos));
            pos = i + 1;
        }
    }
    vector<string> tmpvec;
    string tmpstr;
    int tmpid;
    for(int i = 0; i < t1num -1; ++i){
        cin >> tmpid;
        for(int j = 1; j < t1header.size(); ++j){
            cin >> tmpstr;
            tmpvec.push_back(tmpstr);
        }
        t1.insert(make_pair(tmpid,tmpvec));
        tmpvec.clear();
    }
    int t2num;
    vector<string> t2header;
    cin >> t2num;
    cin.ignore(256,'\n');
    getline(cin, str);
    pos = 0;
    for(int i = 0; i <= str.length(); ++i){
        if(str[i] == ' ' || i == str.length()) {
            t2header.push_back(str.substr(pos,i-pos));
            pos = i + 1;
        }
    }
    for(int i = 0; i < t2num -1; ++i){
        cin >> tmpid;
        for(int j = 1; j < t2header.size(); ++j){
            cin >> tmpstr;
            tmpvec.push_back(tmpstr);
        }
        t2.insert(make_pair(tmpid,tmpvec));
        tmpvec.clear();
    }
    for(int i = 0; i < t1header.size(); ++i) cout << t1header[i] << ' ';
    for(int i = 1; i < t2header.size(); ++i) cout << t2header[i] << ' ';
    cout << '\n';

    for(auto it = t1.begin(); it != t1.end(); it++){
        cout << it->first << ' ';
        for(int j = 0; j < t1header.size()-1; ++j) cout << it->second[j] << ' ';
        if(t2.find(it->first) == t2.end()){
            for(int j = 1; j < t2header.size(); ++j) cout << "NULL" << ' ';
        }else{
            for(int j = 0; j < t2header.size()-1; ++j) cout << t2.find(it->first)->second[j] << ' ';
        }
        
        cout << '\n';
    }
}
