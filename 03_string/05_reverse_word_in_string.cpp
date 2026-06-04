#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = " my name is imteyaz alam";

    int st = 0; int end = str.length()-1;
    while(st < end) {
        swap(str[st], str[end]);
        st++;
        end--;
    }

    cout << str << endl;
    string ans = "";
    
    int n = str.length();
    for(int i =0; i<str.length(); i++) {
        string word ="";
    
        while(i < n && str[i] != ' ') {
            word = word + str[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if(word.length() > 0) {

            ans += " " + word;
        }

    }
    cout << ans << endl;
}