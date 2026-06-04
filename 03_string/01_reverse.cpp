#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    cout << str << endl;
    cout << str.length() << endl;
    int st =0;
    int end = str.length()-1;
    while(st < end) {
        swap(str[st], str[end]);
        st++;
        end--;
    }
    cout << str << endl;


}