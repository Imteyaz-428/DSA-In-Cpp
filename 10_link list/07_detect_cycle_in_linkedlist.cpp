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

class List {
    Node* head1;
  
    Node* tail1;
   
public:

    List() {
        head1 = tail1 = NULL;
        
    }

    void Push_back(int val) {
        Node* newNode1 = new Node(val);
        if(head1 == NULL) {
            head1 = tail1= newNode1;

        }
        tail1->next = newNode1;
        tail1 = newNode1;
       
    }

    void display() {
        Node* temp = head1;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

    }
};


int main() {
    List ll;
    List l2;
    ll.Push_back(3);
    ll.Push_back(5);
    ll.Push_back(6);
    ll.Push_back(9);
    l2.Push_back(4);
    l2.Push_back(6);
    l2.Push_back(8);

    ll.display();
    l2.display();
    



    return 0;
}