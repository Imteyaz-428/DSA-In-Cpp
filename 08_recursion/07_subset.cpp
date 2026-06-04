#include <iostream>
#include <vector>
using namespace std;


void printSubset(vector<int> arr, vector<int> ans, int i) {
    if(i == arr.size()) {
        for(int i : ans) {
            cout << i << " " ;

        }
        cout << endl;
        return;
    }
    // inclusion
    ans.push_back(arr[i]) ;
    printSubset(arr, ans, i+1);

    //backtracking
    ans.pop_back();

    // exclusion
    printSubset(arr, ans , i+1);
}

int main() {
    vector<int> arr= {1,2,3};
    vector<int> ans;
    printSubset(arr, ans, 0);
    return 0;

}