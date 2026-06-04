#include <iostream>
#include <vector>
#include <string>
using namespace std;
// time comp :- )(n* 2^n)
bool ispalindrom(string part) {
    string a = part;
    reverse(part.begin(), part.end());
    return a == part;
}

void palindrome(string str, vector<vector<string>> &ans, vector<string> &parti) {
    if( str.size() == 0) {
        ans.push_back(parti);
        return;
    }
    for(int i =0; i< str.size(); i++) {
        string part = str.substr(0, i+1);
        
        if(ispalindrom(part)) {
            parti.push_back(part);
            palindrome(str.substr(i+1), ans, parti);

            // backtrack
            parti.pop_back();
        }
    }
}

int main() {
    string str = "aab";
    vector<vector<string>> ans;
    vector<string> parti;
    palindrome(str, ans, parti);
    for(auto val : ans) {
        for(auto i : val) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}