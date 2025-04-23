#include<iostream>
#include<algorithm>
#include<array>
#include<iterator>
#include<string>

using namespace std;

void print(int **mat, int n,int sum ){
    cout<<"Internal working - "<<endl;
    cout<<"DP matrix "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<=sum; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int SubsetSum(int arr[] ,int n,  int sum){

    int **mat = new int *[n];
    for(int i=0; i<n ;i++){
        mat[i] = new int[sum+1];
    }
    for(int i=0; i<n; i++){
        mat[i][0]= 1;
    }
    for(int j=1; j<= sum ; j++){
        if(j== arr[0]){
            mat[0][j] = 1;
        }
        else{
            mat[0][j] = 0;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            if(i>0) {
                mat[i][j] = mat[i-1][j];
            }
            if(j == arr[i]){
                mat[i][j]= 1;
            }
            if(mat[i-1][j] == 1){
                mat[i][j] = 1;
            }
            if(j>arr[i] && mat[i-1][j] == 0){
                mat[i][j] = mat[i-1][j-arr[i]];
            }
        }
    }
    print(mat,n,sum);
    return mat[n-1][sum];

}

int main(){
    int arr[6] = {1, 4, 6, 9, 13, 7};
    int sum = 20;

    int n = sizeof(arr)/sizeof(arr[0]);
    int val = SubsetSum(arr,n,sum);
    cout<<"Will the subset from this array will make a sum = "<<sum<<" ? "<<endl;
    if(val == 1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}