#include<iostream>
#include<vector>
using namespace std;

int count_the_number(vector<int> & arr,int x){
    int count =0; 
    for(int i=0; i<arr.size(); i++){
        if( x >= arr[i]){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {5,78,3,5,73,45};
    int x = 50;

    cout<<"Number less than or equal to "<< x << ": "<< count_the_number(arr,x)<<endl;
    return 0;

}