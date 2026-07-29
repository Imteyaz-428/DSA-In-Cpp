#include <iostream>
#include <vector>
using namespace std;
 
int main() {
 
    int T;
    cin >> T;
 
    while(T--) {
 
        int n;
        cin >> n;
 
        vector<int> arr(n);
 
        for(int i=0;i<n;i++)
            cin>>arr[i];
 
        // Remove consecutive duplicates
        vector<int> b;
 
        for(int x:arr){
 
            if(b.empty() || b.back()!=x)
                b.push_back(x);
        }
 
        int m=b.size();
 
        int ans=0;
 
        if(m==1){
            cout<<1<<endl;
            continue;
        }
 
        // First element
        if(b[0]>b[1])
            ans++;
 
        // Middle elements
        for(int i=1;i<m-1;i++){
 
            if(b[i]>b[i-1] && b[i]>b[i+1])
                ans++;
        }
 
        // Last element
        if(b[m-1]>b[m-2])
            ans++;
 
        cout<<ans<<endl;
    }
}