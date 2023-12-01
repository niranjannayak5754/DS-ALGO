/*
    Pascal's Triangle

    Example: Input = 5, Output = [[1], [1,1], [1,2,1], [1,3,3,1]]
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> res;
    for(int i = 0; i<n; i++){
        vector<int> temp;
        for(int j = 0; j<=i;j++){
            if(j==0 || j==i)
                temp.push_back(1);
            else
                temp.push_back(res[i-1][j] + res[i-1][j-1]);
        }
        res.push_back(temp);
    }
    return res;
}

int main(){
    int n = 5;
    vector<vector<int>> res = pascalTriangle(n);
    for(auto v : res){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}