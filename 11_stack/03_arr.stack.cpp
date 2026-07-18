#include <iostream>
#include <vector>
using namespace std;
#define MAX 5

class Stack {
    int arr[MAX];
    int top;
public:

    Stack() {
        top = -1;
    }
    void push(int val) {
        if(top == MAX-1) {
            cout << "stack is overflow" << endl;
        } else {
            top = top+1;
            arr[top] = val;
        }
        cout << arr[top] << "is pushed" << endl;

    }
    void pop() {
        if(top == -1) {
            cout << "stack is underflow" << endl;
        }  else {
            top = top -1;
        }
    }
    int peek() {
        return arr[top];
    }
    bool isempty() {
        return top != -1;
    }
    void display() {
        while(top != -1) {
            cout << arr[top] << " ";
            top = top-1;
        }
        cout << endl;
    }
    // void dis() {
    //     for(int i = top; i>=0; i--) {
    //         cout << arr[i] << " ";
            
    //     }
    //     cout << endl;
    // }


};

int main() {
    Stack s;
    s.push(6);
    s.push(7);
    s.push(4);
   
    s.display();
}