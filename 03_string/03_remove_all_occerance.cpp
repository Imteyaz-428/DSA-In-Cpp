#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "dabcbabc";
    string s = "abc";
    
    while(str.length()> 0 && str.length()> s.length()){
      str.erase(str.find(s),s.length());
    }
    cout << str << endl;



}