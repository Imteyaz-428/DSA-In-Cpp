#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &arr) {
    for(int i=1; i<arr.size(); i++) {
        int prev = i-1;
        int curr = arr[i];
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void printA(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {6,3,7,2,9};
    insertion_sort(arr);
    printA(arr);
}
 






