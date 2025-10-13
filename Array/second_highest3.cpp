// Code for finding the second highest element from the array, by assigning the second largest and the largest element simultaneously.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// using this we can find out the highest as well as second highest also ...

int second_largest(vector<int> & arr){
    int n = arr.size();
    int largest = -1;
    int second_largest = -1;

    for(int i =0; i<n; i++){
        if(arr[i]> largest ){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i]> second_largest && arr[i]!=largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main(){
    vector<int> arr = {6,4,3,77,65,43,32};
    int second_value = second_largest(arr);
    cout<<"Second largest: "<<second_value<<endl;
    return 0;
}