#include <iostream>
#include <vector>
using namespace std;
 
int merge(vector<int> &arr, int st, int end, int mid) {
    vector<int> temp;
    int i = st;
    int j = mid+1;
    int inversion_count = 0;
    while( i <= mid && j<=end) {
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else{
            temp.push_back(arr[j]);
            inversion_count += mid-i+1;
            j++;
        }
    }
    while(i<=mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx = 0; idx< temp.size(); idx++) {
        arr[idx+st] = temp[idx];
    }
    return inversion_count;
}

int merged_sort(vector<int> &arr, int st, int end) {
    if( st < end) {
        int mid = st + (end-st)/2;

        // left half
        int leftcount =merged_sort(arr, st, mid);
        // right half
        int rightcount=merged_sort(arr, mid+1, end);
    
        //backtracking
        int count = merge(arr, st, end, mid);
        
        return count+ leftcount+ rightcount;
        
       
    }
    return 0;


    
}

int main() {
    vector<int> arr = {1,3,5,10,2,6,8,9};
    int ans= merged_sort(arr, 0, arr.size()-1);
    cout << "inversion cout :" << ans << endl;
    return 0;
}