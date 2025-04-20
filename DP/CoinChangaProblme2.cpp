#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define INT_MAX 

void print(int **mat, int n, int w){
    for(int i =0; i<n; i++){
        for(int j=0; j<w+1; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void CoinProblem(vector<int> coins, int n, int w){
    int **mat = new int *[n];
    for(int i=0 ; i< n; i++){
        mat[i] = new int [w+1];
    } 
    // Initializing
    for(int i=0; i <n; i++){
        for(int j=0; j <=w; j++){
            mat[i][j] = INT_MAX -1;
        }
    }

    for(int i=0; i<n; i++){
        mat[i][0] =0;
    }
    // filling first row
    for(int j=1; j<=w ;j++){
        if(j%coins[0] == 0){
            mat[0][j] = j /coins[0];
        }
    }
   
    for(int i=1; i <n; i++){
        for(int j=1; j <=w; j++){
            
            if(j>=coins[i]){
                mat[i][j] = min(mat[i-1][j],1+ mat[i][j-coins[i]] );
            }
            else{
                mat[i][j] = mat[i-1][j];
            }
        }
    }
    print(mat,n,w);

    cout<<"Minimum coins required to make "<<w<<" is : ";
    if(mat[n-1][w] == INT_MAX -1){cout<<"Not possible";}
    else{
        cout<<mat[n-1][w];
    }
    
}
int main(){
    int w,n ,val;
    cout<<"Enter the amount of the weight "<<endl;
    cin>>w;
    cout<<"Enter the number of coins "<<endl;
    cin>>n;
    cout<<"Enter coins "<<endl;
    vector<int> coins;
    int temp = n;
    while(temp != 0 ){
        cin>>val;
        coins.push_back(val);
        temp--;
    }
    CoinProblem(coins,n,w);
}