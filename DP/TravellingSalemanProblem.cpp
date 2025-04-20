#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

int TravellingSalesman(vector<vector<int>> & Weight, int n, int source,set<int> S){

    if(S.empty()) return 0;

    int minDist = INT_MAX;

    for(int next :S){
        set<int> remaining = S;
        remaining.erase(next);
        int dist = Weight[source][next] + TravellingSalesman(Weight, n, next, remaining);
        minDist = min(minDist, dist);
    }
    return minDist;
}
int main(){
    int num = 4;

    vector<vector<int>> Weight ={
        {0,16,11,6},
        {8,0,13,16},
        {4,7 , 0,9},
        {5,12,2 ,0}
    };

    set<int> S = {0,1,2,3};

    int source ;
    cout<<"Enter the source vertex (0 to 3)"<<endl;
    cin>> source;

    if(source <0 || source >= num ){
        cout<<"Invalid source vertex";
        return 1;
    }
    S.erase(source);
    int distance = TravellingSalesman(Weight,num,source,S);
    cout<<"Minimum path distance: "<<distance<<endl;

    return 0;
}