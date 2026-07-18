#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Stack {
    list<int> ll;
public:
    void push(int val) {
        ll.push_front(val);
    }
    void pop() {
        ll.pop_front();
    }
    int top() {
        return ll.front();
    }

    bool isempty() {
        return ll.size() == 0;
    }

};

int main() {
    Stack s;
    s.push(5);
    s.push(9);
    s.push(3);
    s.push(0);
    while(s.isempty() != true) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}