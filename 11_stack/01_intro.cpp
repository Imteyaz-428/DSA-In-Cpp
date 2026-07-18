#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;
public:
    void push(int val) {
        v.push_back(val);
    } 
    void pop() {
        v.pop_back() ;

    }
    int top() {
        return v[v.size()-1];
    }

    bool isempty() {
        return v.size() == 0;
    }

};

int main() {
    Stack s;
    s.push(6);
    s.push(2);
    s.push(8);
    while(s.isempty() != true) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}