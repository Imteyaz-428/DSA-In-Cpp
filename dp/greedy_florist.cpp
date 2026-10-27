#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i]  ;

    }
    int curr =0;
    int a = k;
    long long sum =0;
    for(int i=0; i<n; i++) {
        sum = sum+ arr[i]*(curr+1);
        a--;
        if(a==0) {
            curr++;
            a = k;
            
        }
    }
    cout << sum << endl;

}