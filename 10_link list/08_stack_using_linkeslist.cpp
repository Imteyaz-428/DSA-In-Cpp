#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* top;  // Pointer to top node

public:
    Stack() { top = NULL; }

    // Push operation
    void push(int x) {
        Node* temp = new Node();
        if (!temp) {
            cout << "Heap Overflow\n";
            return;
        }
        temp->data = x;
        temp->next = top;
        top = temp;
        cout << x << " pushed into stack\n";
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    // Peek operation
    int peek() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if empty
    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.peek() << endl;
    s.pop();
    s.pop();
    cout << "Stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}


