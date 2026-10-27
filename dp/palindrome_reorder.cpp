#include <iostream>        // For standard input/output streams (cin, cout)

#include <vector>          // For dynamic arrays (std::vector)
#include <string>          // For string objects (std::string)
#include <unordered_map>
using namespace std;
bool isPelendrome(string s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++; 
        j--;
    }
    return true;
}

int main() {
    string n ;
    getline(cin, n);
    unordered_map<char, int> m;
    for(int i=0; i<n.length(); i++) {
        m[n[i]]++;
    }
    string temp = "";
    for(auto it = m.begin(); it != m.end(); it++) {
       if(it->second %2 != 0) {
            temp += it->first;
       }
    }
    string ans = "";
    for(auto it = m.begin(); it != m.end(); it++) {
        char a = it->first;
        
        for(int i=0; i<it->second/2; i++) {
            ans += a;
        }
    }
    string temp1 = ans;
    reverse(temp1.begin(), temp1.end());
    string ans1 = ans + temp + temp1;
    int i=0; 
    int j= ans1.length()-1;
    if(isPelendrome(ans1, i, j)) {
        cout << ans1 << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }
    

}