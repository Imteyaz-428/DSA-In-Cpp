#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {

        data= val;
        next =NULL;
    }

};
class Queue {
    Node* head;
    Node* tail;
public:
    Queue() {
        head = tail = NULL;
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        } 
        tail->next = newNode;
        tail = newNode;
    }
    void pop_back() {
        if(head == NULL) {
            cout << "queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next=NULL;
    }
    void display() {
        if(head == NULL) {
            cout << "queue is empty" << endl;
            return;
        }

        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data;
            temp = temp->next;
            cout << endl;
        }
    }
    void front() {
        if(head == NULL) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "front:" << head->data;
        cout << endl;
    }

    bool empty() {
        return (head ==NULL);
    }
};

int main() {
    Queue ll;
    ll.push_back(6);
    ll.push_back(4);
    ll.push_back(9);
    ll.push_back(2);
    ll.front();
    ll.pop_back();
    ll.display();
    ll.front();
    ll.pop_back();
    ll.pop_back();
    ll.pop_back(); 
    ll.display();
    ll.pop_back(); 

    cout << ll.empty() << endl;
    
}
