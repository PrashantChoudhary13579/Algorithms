#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<Windows.h>
using namespace std;

void print(const vector<vector<int>>& arr,const vector<vector<string>>& b,int m, int n){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout<<arr[i][j]<<b[i][j] <<" ";
        }
        cout<<endl;
    }
}
void printLCS(const vector<vector<string>>& b,string str1,int m , int n){
    
    if( m == 0 || n == 0) return;
    if(b[m][n] == u8"↖") {
        printLCS(b,str1,m-1,n-1);
        cout<<str1[m-1];
    }
    else if(b[m][n] == u8"⬆"){
        printLCS(b,str1,m-1,n);
    }
    else printLCS(b,str1,m,n-1);
}
void LCS(string str1,string str2){
    int m = str1.length();
    int n = str2.length();

    vector<vector<string>> b(m+1,vector<string>(n+1));
    vector<vector<int>> c(m+1,vector<int>(n+1));

    for(int i=0; i<= m; i++){
        c[i][0]= 0;
        b[i][0] = ' ';
    }
    for(int j=0; j<=n; j++){
        c[0][j] = 0;
        b[0][j] = ' ';
    }
    for(int i =1;i<=m ; i++){
        for(int j=1;j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                c[i][j] = 1 + c[i-1][j-1];
                b[i][j] = u8"↖";
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = u8"⬆";
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = u8"⬅";
            }
        }
    }
    print(c,b,m,n);
    cout<<endl;

    printLCS(b,str1,m,n);
}

int main(){
    string str1;
    string str2;
    cout<<"Enter the two string"<<endl;
    cin>>str1;
    cin>>str2;
    
    SetConsoleOutputCP(CP_UTF8);
    
    LCS(str1,str2);

}