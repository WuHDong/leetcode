#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

/**
 * 2369. 检查数组是否存在有效划分
*/
bool validPartition(vector<int>& nums) {
    int len = nums.size();

    if(len < 2) {
        return false;
    }
    vector<int> dp(len+1);
    dp[0] = 1;
    for(int i = 1;i<=len;i++) {
        if(i >= 2 ) {
            dp[i+1] = dp[i] && nums[i-2] == nums[i-1];
        }

        if(i >= 3) {
            dp[i+1] = dp[i] &&((nums[i-2] == nums[i-1] && nums[i-3] == nums[i-1]) || (nums[i-1] == nums[i-2]+1 && nums[i-2] == nums[i-3]+1));
        }
    }
    
    return dp[len];
}   