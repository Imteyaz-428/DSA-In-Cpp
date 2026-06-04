#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> chars  = {'a','a','b','b','b'};
    
    int index =0;
    reverse(chars.begin(), chars.end());
    int st =0;
    int end = chars.size() -1;
    for(int i =0; i< chars.size(); i++) {
        char ch = chars[i];
        int count =0;
        while( i<=end &&  chars[i] == ch) {
            i++;
            count++;
        }
        if(count == 1) {
            chars[index] = ch;
            index++;

        } else {
            chars[index] = ch;
            index++;
            
            string str = to_string(count); 
            for(int dig : str) {
                chars[index]=dig;
                index++;
            }
            
        }
        i--;

        
    }
    for(int i =0; i<chars.size(); i++) {
        cout << i << endl;
    }

    


}