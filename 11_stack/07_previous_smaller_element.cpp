#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> arr= {3,1,0,8,6};
   stack<int> s;

   vector<int> temp(arr.size(), 0);

    for(int i =0; i<arr.size(); i++) {
      while(s.size() >0 && s.top() >= arr[i]) {
         s.pop();
      }
      
      if(s.empty()) {
        temp[i] = -1;
      } else {
        temp[i] = s.top();
      }

      s.push(arr[i]);

    }
    for(int i : temp) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}