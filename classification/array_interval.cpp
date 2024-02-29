#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

/**
 * 数组区间题目
*/

/**
 * 2008. 出租车的最大盈利
 * 
 * 你驾驶出租车行驶在一条有 n 个地点的路上。这 n 个地点从近到远编号为 1 到 n ，你想要从 1 开到 n ，
 * 通过接乘客订单盈利。你只能沿着编号递增的方向前进，不能改变方向。
 * 乘客信息用一个下标从 0 开始的二维数组 rides 表示，其中 rides[i] = [starti, endi, tipi] 表示
 * 第 i 位乘客需要从地点 starti 前往 endi ，愿意支付 tipi 元的小费。
 * 每一位 你选择接单的乘客 i ，你可以 盈利 endi - starti + tipi 元。你同时 最多 只能接一个订单。
 * 给你 n 和 rides ，请你返回在最优接单方案下，你能盈利 最多 多少元。
 * 你可以在一个地点放下一位乘客，并在同一个地点接上另一位乘客。
 * 
*/

static bool cmp(vector<int> &a,vector<int>& b) {
    return a[1] < b[1];
}

long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    long long ans = 0;
    int len = rides.size();
    vector<long long> dp(len+1);
    sort(rides.begin(),rides.end(),cmp);

    for(int i = 0;i<len; i++) {
        int j = findBinary(rides,i,rides[i][0]);

        dp[i+1] = max(dp[i],dp[j]+rides[i][1] - rides[i][0] + rides[i][2]);
    }
    return dp[len];
}

int findBinary(vector<vector<int>>& rides,int high,int target) {
    int low = 0;
    while(low < high) {
        int mid = (high+low)/2;
        if(rides[mid][1] > target) {
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return low;
}

/**
 * 1235. 规划兼职工作 
 * 
 * 你打算利用空闲时间来做兼职工作赚些零花钱。
 * 这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。
 * 给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组
 * 请你计算并返回可以获得的最大报酬。
 * 注意，时间上出现重叠的 2 份工作不能同时进行。
 * 如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。
*/

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int len = startTime.size();
    vector<vector<int>> arr(len,vector<int>(3));

    for(int i = 0;i<len;i++) {
        arr[i][0] = startTime[i];
        arr[i][1] = endTime[i];
        arr[i][2] = profit[i];
    }

    sort(arr.begin(),arr.end(),cmp);

    vector<int> dp(len+1);
    for(int i = 0;i<len;i++) {
        int j = findBinary(arr,i,arr[i][0]);
        dp[i+1] = max(dp[i],dp[j]+arr[i][2]);
    }

    return dp[len];
}