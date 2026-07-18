#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void display() {
        if(head == NULL) {
            cout << "queue is empty" << endl;
        }
        Node* temp = head;
        while(temp!= NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        
    }
    void pop() {
        if( head == NULL) {
            cout << "queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);
    }
};

int main() {
    List ll;
    ll.push(5);
    ll.push(2);
    ll.push(8);
    ll.display();
    ll.pop();
    cout << "after the pop element" << endl;
    ll.display();

}