#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        int smallestIndex = i;
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
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
    selection_sort(arr);
    printA(arr);
}
 