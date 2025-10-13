// Code for  finding the second highest using the complete scaning first to find out the largest and then again scanning for finding the second highest.
#include<iostream>
#include<vector>
using namespace std;

int secondhighest(vector<int> &arr){
    int n = arr.size();
    int largest = -1;
    int second_largest = -1;
    for(int i =0 ;i <n ;i++){
        if(arr[i]> largest){
            largest = arr[i];
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i]> second_largest && arr[i]!= largest){

            second_largest =arr[i];
        }
    }
    return second_largest;

}
int main(){
    vector<int> v = {2,3,5,8,9,76,4,34,66,12};
    int second = secondhighest(v);
    cout<<"Second highest: "<<second<<endl;
    return 0;
}