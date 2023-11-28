#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);
        else
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals{{1, 3}, {2, 4}, {4, 4}, {4, 5}, {6, 12}, {11, 14}, {15, 19}};
    vector<vector<int>> res = mergeIntervals(intervals);
    for(auto it : res){
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}
