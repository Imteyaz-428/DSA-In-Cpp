#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public :
    List() {
        head = tail = NULL;
    }

    void pop_back() {
        if(head == NULL ) {
            cout << "our linklist is empty \n";
            return;
        }

        Node* temp = head;
        while(temp->next !=  tail) {
            temp= temp->next;

        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void pop_front() {
        if(head == NULL) {
            cout << "out linklist is empty \n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }


    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;

        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL ) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insert_in_middle(int val, int pos) {
        if(pos <0) {
            cout << "invalid pos" << endl;
            return;
        }
        if(pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i=0; i<pos-1; i++) {
            if(temp == NULL) {
                cout << "invalid pos \n";
                return ;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

    }
    void search(int val) {
        Node* temp = head;
        int index =0;
        while( temp != NULL) {
            if(temp->data == val) {
                cout << index << endl;

                return;
                break;
            }
            temp= temp->next;
            index++;
        }
    }

};

int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.pop_front();
    ll.pop_back();
  

    ll.insert_in_middle(8,1);
    ll.printLL();
    ll.search(8);

    return 0;

}