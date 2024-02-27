#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

/**
 * 77. 组合
*/
vector<vector<int>> combine(int n, int k) {
    vector<int> ls;
    vector<vector<int>> ans;
    backTrackCombine(ans,ls,1,k,n);
    return ans;
}
void backTrackCombine(vector<vector<int>> &ans,vector<int> &ls,int cur,int k,int n) {
    if(ls.size() == k) {
        ans.push_back(ls);
        return;
    }
    for(int i = cur;i<n;i++) {
        ls.push_back(i);
        backTrackCombine(ans,ls,i+1,k,n);
        ls.pop_back();
    }
}

/**
 * 46. 全排列
*/
vector<vector<int>> permute(vector<int>& nums) {
    vector<int> ls;
    vector<vector<int>> ans;
    vector<int> visited(nums.size());
    backTrackPermute(ls,ans,visited,nums);
    return ans;

}

void backTrackPermute(vector<int> &ls,vector<vector<int>> &ans,vector<int> &visited,vector<int>& nums) {
    if(ls.size() == nums.size()) {
        ans.push_back(ls);
        return;
    }

    for(int i = 0;i<nums.size();i++) {
        if(visited[i] != 1) {
            ls.push_back(nums[i]);
            visited[i] = 1;
            backTrackPermute(ls,ans,visited,nums);
            ls.pop_back();
            visited[i] = 0;
        }
    }
}