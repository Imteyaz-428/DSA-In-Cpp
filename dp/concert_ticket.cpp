#include <iostream>
#include <vector>
#include <set>
using namespace std;



int main() {
    int n,m;
    cin >> n >> m;
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int>price(m);
    for(int i=0; i<m; i++) {
        cin >> price[i];
    }
   
    
    multiset<int>s;
    for(int i=0; i<n; i++) {
        s.insert(arr[i]);
    }
    for(int i=0; i<m; i++) {
        auto it = s.lower_bound(price[i]);
        if(it != s.end() && *(it) == price[i]) {
            cout << *(it) << endl;
            s.erase(it);
        
        } else if(it != s.begin()) {
            --it; 
            cout << *(it) << endl;
            s.erase(it);
        }
         else {
            cout << -1 << endl;
        }

    }

    

}
