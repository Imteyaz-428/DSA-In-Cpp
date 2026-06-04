#include <iostream>
#include <string>
using namespace std;

int main() {
    string str  = "racecar";
    bool ispelndrome = true;
    int st =0;
    int end= str.length();
    while(st < end) {
        if(str[st] != str[end-1]){
            ispelndrome = false;
            break;
        }
        st++;
        end--;
    }
    if(ispelndrome == true) {
        cout << "this is a pelendrome" << endl;
    } else{
        cout << "this is not a pelindrom" << endl;
    }
}