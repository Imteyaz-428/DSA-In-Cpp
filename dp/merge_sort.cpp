#include <iostream> 
#include <vector>
using namespace std;

void merge(vector<int>&arr,int mid, int left, int right) {
    vector<int>temp1;
    vector<int> temp2;
    
}

void mergesort(vector<int> &arr, int n,int l, int r) {
    if(r < l) {
        return;
    }
    int mid = (r + l)/2;
    mergesort(arr,n,l, mid);
    mergesort(arr, n, l, r);
    merge(arr,mid,l, r);


}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n); 
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }


}