//  this program is basically the naive approach of finding the subset 
// It is using n*m TC , bcz of nested looping.
#include<iostream>
#include<vector>
using namespace std;

bool isSubset(vector<int> &a, vector<int> &b){
    int m = a.size();
    int n = b.size();
    for(int i=0; i<n ;i++){
        bool found = false;
        for(int j=0; j<m; j++){
            if(b[i] == a[j]){
                found = true;       
            }

        }
        if( !found ) return false;

    }
    return true;
}

int main() {
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};
  
    if (isSubset(a, b)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}