#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {-2,-1,-1,1,1,2,2};
    int size = arr.size();
    vector<int> ans;
    sort(arr.begin(), arr.end());
    for(int i =0; i<size; i++) {
        for(int j =i+1;j <size; j++) {
            int st = j+1;
            int end = size-1;
            while(st < end) {
                int sum = arr[i] + arr[j] + arr[st] + arr[end]; 
                if( sum == 0) {
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[st]);
                    ans.push_back(arr[end]);
                    st++;
                    end--;

                } else if(sum > 0) {
                    end--;
                } else {
                    st++;
                }
            }
        }
    }
    for(int i =0; i<4; i++) {
        cout << ans[i] << endl;
    }
}