#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node (int val) {
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

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void printfn() {
        Node* temp = head;
        while( temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next ;
        }
        cout << endl;
    }
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* Nextt = NULL;

        while( curr != NULL) {
            Nextt = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = Nextt;
            
        }
        cout << prev << endl;
    }
};

int main() {
    List ll;
    ll.push_front(5);
    ll.push_front(6);
    ll.push_front(8);
    ll.push_front(2);

    ll.printfn();
    ll.reverse();
    return 0;
}