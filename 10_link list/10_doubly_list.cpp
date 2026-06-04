#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }

};
class DoublyList {
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = tail = NULL;

    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;

        }
        cout << endl;
    }
    void pop_back() {
        Node* temp = tail;
        tail = tail->prev;
        if(tail != NULL) {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }
    void pop_front() {
        Node* temp = head;
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        temp->next = NULL;
        temp = NULL;
    }
    
};
int main()  {
    DoublyList dl;
    dl.push_front(10);
    dl.push_front(20);
    dl.push_front(30);
    dl.push_front(40);
    dl.pop_back();
    dl.pop_front();

    
    dl.printList(); 
    return 0;

}