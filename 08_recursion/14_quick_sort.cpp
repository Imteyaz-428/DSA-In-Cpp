#include <iostream>
#include <vector>
using namespace std;

int piviot(vector<int> &arr, int st, int end) {
    int piviot = arr[end];
    int idx =  st -1;
    for(int i =st; i< end; i++) {
        if(arr[i] <= piviot) {
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quick_sort(vector<int> &arr, int st, int end) {
    if( st >= end) {
        return;
    }
    int piviotIndex = piviot(arr, st, end);

    quick_sort(arr, st,piviotIndex -1); // left part
    quick_sort(arr, piviotIndex +1, end);


}
int main() {
    vector<int> arr = {1,5,2,3,8};
    quick_sort(arr, 0,arr.size()-1);
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}