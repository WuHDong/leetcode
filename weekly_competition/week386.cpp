#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/**
 * 100224. 分割数组
*/
bool isPossibleToSplit(vector<int>& nums) {
    unordered_map<int,int> hash;

    for(int i = 0;i<nums.size();i++) {
        if(hash.count(nums[i])) {
            hash[nums[i]]++;
            if(hash[nums[i]] > 2) {
                return false;
            }
        }else{
            hash[nums[i]]++;
        }
    }
    return true;
}

/**
 * 100225. 求交集区域内的最大正方形面积
*/
long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    int len = bottomLeft.size();
    long long maxArea = LONG_MIN;
    for(int i = 0; i < len; i++) {
        for(int j = i+1;j<len;j++) {
            long long x1 = max(bottomLeft[i][0],bottomLeft[j][0]);
            long long y1 = max(bottomLeft[i][1],bottomLeft[j][1]);

            long long x2 = min(topRight[i][0],topRight[j][0]);
            long long y2 = min(topRight[i][1],topRight[j][1]);

            long long x = x2 -x1;
            long long y = y2 - y1;

            if(x <= 0 || y <= 0) {
                continue;
            }
            long long t = max(x,y);
            maxArea = max(maxArea,t*t);
        }
    }

    if(maxArea == LONG_MIN) {
        return 0;
    }
    return maxArea;
}