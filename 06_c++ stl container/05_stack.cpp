#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    stack<int> s ;
    s.emplace(5);
    s.push(6);
    s.push(8);
    s.emplace(9);
    while( ! s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

}