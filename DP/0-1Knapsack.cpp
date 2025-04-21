#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

void print(vector<int> & v, int n){
    for(int i=0; i< n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void sortbyWeight(vector<int> &w, vector<int> &p ,int n){
    for(int i=0; i< n; i++){
        for(int j=0; j<n-i-1;j++){
            if(w[j] > w[j+1]){
                swap(w[j],w[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }
}
void printing(int** mat, int n, int W){
    for(int i=0; i<= n ;i ++){
        for(int j=0; j <= W; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Knapsac(vector<int> & w, vector<int> &p, int n,int W){

    int **mat = new int *[n+1];
    for(int i=0; i<n+1 ; i++){
        mat[i] = new int [W+1];
    }
    sortbyWeight(w,p,n);
    cout << "Sorted weights: ";
    print(w, n);
    cout << "Sorted profits: ";
    print(p, n);
    for(int i=0 ; i<n+1; i++){
        mat[i][0] = 0;
    }
    for(int j=0 ; j<W+1; j++){
        mat[0][j] = 0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1 ; j++){
            if(i>0) {
                mat[i][j] = mat[i-1][j];
            }
            if(j>=w[i-1]){
                mat[i][j] = max(mat[i-1][j], p[i-1] + mat[i-1][j-w[i-1]]);
            }
        }
    }
    cout<<endl;
    cout<<"DP Matrix: "<<endl;
    printing(mat,n,W);

    cout<<"Max profit "<<mat[n][W]<<endl;
    
    vector<int> arr(n, 0);
    int i = n, j = W;
    while(i > 0 && j > 0){
        if(mat[i][j] != mat[i-1][j]){
            arr[i-1] = 1;  
            j = j - w[i-1];
        }
        i--;
    }

    cout << "Selected Items (1 means included): ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout<<"Selected weights and profits: "<<endl;
    int totalW =0, totalP =0 ;
    for(int i=0; i<n ;i++){
        if(arr[i]){
            cout<<"Weights: "<<w[i]<<", Profit: "<<p[i]<<endl;
            totalW += w[i];
            totalP += p[i];
        }
    }
    cout<<"Total selected Weight: "<<totalW<<endl;
    cout<<"Total selected Profit: "<<totalP<<endl;
}

int main(){

    int W =16;
    int n=5;
   
    cout<<"Enter the weight and profit associated with them "<<endl;
    vector<int> w={3, 4, 7, 5, 8};
    vector<int> p= {30, 60, 40, 50, 80};
    
    print(w,n);
    print(p,n);

    Knapsac(w,p,n,W);
    return 0;
}