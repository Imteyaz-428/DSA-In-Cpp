#include <iostream>
#include <vector>
using namespace std;

// time complexity :- O(n)
// space complexity :- O(n)

int main() {
    vector<int> arr = {6,8,0,1,3};
    stack<int> s;
    vector<int> ans;


    for(int i=arr.size()-1; i>=0; i--) {
        //remove the smaller element from the stack
        while(s.size() >0 && s.top() <= arr[i]) {
            s.pop();
        }

        // if no greater element is present
        if(s.empty()) {
            ans.push_back(-1);
        } else{
            ans.push_back(s.top());
        }

        // at the end we push the into the stack
        s.push(arr[i]);


    }

    // print the answer
    for(int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}