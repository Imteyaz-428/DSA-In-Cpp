#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }

};
class List{
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    void push_back(int val)  {
        Node* newNode = new Node(val);
        if(head == NULL) {
            
            head = tail = newNode;
        }
        
        tail->next = newNode;
        tail = newNode;
    }
    void printff() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void middle() {
        Node* slow= head;
        Node* fast= head;

        while( fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << endl;
    }
};
int main() {
    List ll;
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(8);
    ll.push_back(1);
    ll.push_back(3);
    ll.printff();
    ll.middle();
}