#include <iostream>
#include <vector>
using namespace std;
void print(int **mat, int n, int W)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void CoinChange(vector<int> v, int W, int n)
{
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[W+1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            mat[i][j] = 0;
        }
    }
    print(mat, n, W);
    for(int i=0; i< n; i++){
        mat[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i > 0)
            {
                mat[i][j] = mat[i-1][j];
            }
            if(j >= v[i])
            {
                mat[i][j] += mat[i][j - v[i]];
            }
        }
    }
    cout << "After value filling" << endl;
    print(mat, n, W);
    cout<<"Number of ways to make change for "<<W<<" is "<<mat[n-1][W]<< endl;

    // cleanup
    for(int i=0; i<n; i++){
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    int amt;
    cout << "Enter the total amount " << endl;
    cin >> amt;
    vector<int> vec;
    cout << "Enter the number of coins you are having " << endl;
    int n;
    cin >> n;
    int temp = n;
    cout << "Enter the coins you are having";
    int v;
    while (temp != 0)
    {
        cin >> v;
        vec.push_back(v);
        temp--;
    }

    CoinChange(vec, amt, n);
}