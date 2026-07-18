#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class cicularqueue{
    int* arr;
    int currsize, cap;
    int f, r;
public:
    cicularqueue(int size) {
        cap = size;
        arr =new  int[cap];
        r = -1;
        f = 0;
        currsize =0;
    }
    void push(int data) {
        if(currsize == cap) {
            cout << "arr is already full" << endl;
            return;
        }
        r = (r+1)%cap;
        arr[r] = data;
        currsize++;
    }
    void pop() {
        if(currsize == 0) {
            cout << "circular queue is empty" << endl;
            return;
        }
        f = (f+1)%cap;
        currsize--;
    }
    void front() {
        if(currsize== 0) {
            cout << "circular queue is empty" << endl;
            return;
        }
        cout << "front :" <<  arr[f] << endl;
    }
    bool empty() {
        return (currsize == 0);
    }
    void display() {
        int temp = currsize;
        int i= f;
        while(temp != 0) {
            cout << arr[i] << endl;
            i = (i+1)%cap;
            temp --;
        }
    }

};

int main() {
    cicularqueue arr(6);
    arr.push(5);
    arr.push(8);
    arr.push(2);
    arr.push(9);
    arr.push(8);
    arr.push(1);
    arr.push(0);
    arr.pop();
    arr.pop();
    arr.push(3);

    
    
    arr.display();
   
    arr.front();
    
}