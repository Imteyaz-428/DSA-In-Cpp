#include <iostream>
#include <string>
using namespace std;

bool issamfreq(int freq[],int freq2[]) {
    for(int i=0; i<26; i++) {
        if(freq[i] != freq2[i]) {
           return false;
        }
    }
    return true;
}
bool permutation(string str, string s) {
    int freq1[26] = {0};
    for(int i=0; i<str.length(); i++) {
        int index = s[i] -'a';
        freq1[index]++;
     }
     int windsize = s.length();
     for(int i=0;i <str.length(); i++) {
        int index =i;
        int windindex=0;
        int windfreq[26] ={0};
        while(windindex < windsize && index < s.length()) {
             int idx = s[index] - 'a';
             windfreq[idx]++;
        }
         if(issamfreq(freq1, windfreq)) {
            cout << "permutation is found" << endl;
            return true;
        } 
          
    }
    return false;
 
}

int main() {
    string str = "dadfba";  
    string s = "ab";
    cout << permutation(str, s) << endl;
    


}
