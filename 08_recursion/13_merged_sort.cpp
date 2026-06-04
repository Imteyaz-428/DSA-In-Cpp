#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int end, int mid) {
    vector<int> temp;
    int i = st, j = mid+1;
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while( i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int index =0; index< temp.size(); index++) {
        arr[st + index] = temp[index];
    }
}
void merged_sort(vector<int> &arr, int st, int end) {
    if(st >= end) {
        return;
    }
    int mid = st+ (end-st)/2;
    //left
    merged_sort(arr,st, mid);
    
    //right
    merged_sort(arr, mid+1, end);

    merge(arr, st, end, mid);
}
int main() {
    vector<int> arr = {4,5,23,1,3,53,2};
    merged_sort(arr, 0, arr.size()-1);
    for(int i =0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}