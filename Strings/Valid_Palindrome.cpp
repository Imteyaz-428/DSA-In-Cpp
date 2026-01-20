//check validpelindrome
// ignoring special charachers
// case insenstive approach
// uses two pointer approach with ignoring special charaters 
// change upper case letter to lower case letter using ascii concept
// Time coplexity :- O(n) and space complexity is O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isAlphaNum(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}
bool ispelindrome(string str) {
    int i =0; 
    int j= str.length() -1;
    while(i < j) {
        if(!isAlphaNum(str[i])) {
            i++;
        } else if(!isAlphaNum(str[j])) {
            j--;
        } else {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
            if(str[j] >= 'A' && str[j] <= 'Z') {
                str[j] = str[j] + 32;
            }
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
    }
    return true;
}

int main() {
    
    string str;
    cout << "please enter your input :";
    getline(cin, str);
    bool pelindrome = ispelindrome(str);
    if(pelindrome) {
        cout << "this is pelindrome string" << endl;
    } else {
        cout << "this is not a pelindrome string" << endl;
    }
}
