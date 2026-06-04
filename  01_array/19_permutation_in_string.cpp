#include <iostream>
#include <vector>
using namespace std;

bool isSame(int freq[26], int freq2[26]) {
    for(int i=0; i<26; i++) {
        if(freq[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}
bool isPermuatation(string s1, string s2) {
    int freq1[26]  = {0};
    for(int i=0; i<s1.length(); i++) {
        freq1[s1[i] - 'a']++;

    }
    int windSize = s1.length();
    for(int i=0; i<s2.length(); i++) {
        int idx =i;
        int windIdx =0;
        int freq2[26] = {0};
        while(windIdx < windSize && idx < s2.length()) {
            freq2[s2[idx] - 'a']++;
            idx++;
            windIdx++;
        }
        if(isSame(freq1, freq2)) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaoo";
    if(isPermuatation(s1, s2)) {
        cout << "permutation exist" << endl;
    } else {
        cout << "permuatation not exist" << endl;
    }
}