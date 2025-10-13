// Code for finding the second highest element of the array using sorting method. TC >= O(nlogn)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Second_largest(vector<int> & arr){
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for(int i=n-2; i>=0; i--){
        if(arr[i]!= arr[n-1]){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    vector <int> arr = {2,5,9,66,34,13};

    int s_large = Second_largest(arr);
    cout<<"Second largest: "<<s_large<<endl;

    return 0;
    

}