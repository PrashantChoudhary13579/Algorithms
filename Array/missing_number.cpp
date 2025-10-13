#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v ){
    for(int i=0 ;i< v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> arr ={1,2,3,5};
    int size = arr.size();
    vector<int> count(size+2, 0) ;
    count[0] = 1;
    for(int i=0 ; i< size+1 ;i++){
        count[arr[i]] =1 ;
    }

    print(count);

    for (int i = 1; i <= size + 1; i++) {
    if (count[i] == 0) {
        cout << "Missing number: " << i << endl;
        break;
    }
}

        
}