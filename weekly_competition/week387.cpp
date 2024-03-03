#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;


/**
 * 100243. 将元素分配到两个数组中 I
*/

vector<int> resultArray(vector<int>& nums) {

    vector<int> arr1;
    vector<int> arr2;
    int len = nums.size();
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);   

    int index1 = 0;
    int index2 = 0;
    for(int i = 2;i<len;i++) {
        if(arr1[index1] > arr2[index2]) {
            arr1.push_back(nums[i]);
            index1++;
        }else{
            arr2.push_back(nums[i]);
            index2++;
        }
    }

    for(int i = 0;i<arr2.size();i++) {
        arr1.push_back(arr2[i]);
    }

    return arr1;
}

/**
 * 100237. 元素和小于等于 k 的子矩阵的数目
*/
int countSubmatrices(vector<vector<int>>& grid, int k) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<long long>> arr(row,vector<long long>(col,0));
    arr[0][0] = grid[0][0];
    int ans = 0;
    if(arr[0][0] > k) {
        return ans;
    }
    ans = 1;
    int row1 = row;
    int col1 = col;
    for(int i = 1;i<row;i++) {
        arr[i][0] = arr[i-1][0] + grid[i][0];
        if(arr[i][0] <= k) {
            ans++;
        }else{
            row1 = i;
            break;
        }
    }

    for(int i = 1;i<col;i++) {
        arr[0][i] = arr[0][i-1] + grid[0][i];
        if(arr[0][i] <= k) {
            ans++;
        }else{
            col1 = i;
            break;
        }
    }

    for(int i = 1;i<row1;i++) {
        for(int j = 1;j<col1;j++) {
            arr[i][j] = arr[i][j-1] + arr[i-1][j] + grid[i][j] - arr[i-1][j-1];
            if(arr[i][j] <= k) {
                ans++;
            }
        }
    }
    return ans;
}


/**
 * 100234. 在矩阵上写出字母 Y 所需的最少操作次数
*/
int minimumOperationsToWriteY(vector<vector<int>>& grid) {
    unordered_map<int,int> yhash;
    unordered_map<int,int> hash;
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> visited(row,vector<int>(col,0));

    int t = row/2;
    for(int i = 0;i<= t;i++) {
        for(int j = 0;j<= t;j++) {
            if(i == j) {
                yhash[grid[i][j]]++;
            }else{
                hash[grid[i][j]]++;
            }
        }
    }
    for(int i = 0;i<=t;i++) {
        for(int j = t+1;j<col;j++) {
            if(i+j == row-1) {
                yhash[grid[i][j]]++;
            }else{
                hash[grid[i][j]]++;
            }
        }
    }

    for(int i = t+1;i<row;i++) {
        for(int j = 0;j<col;j++) {
            if(j == t) {
                yhash[grid[i][j]]++;
            }else{
                hash[grid[i][j]]++;
            }
        }
    }
    int ycnt = 3*(t+1) - 2;
    int cnt = row*col - ycnt;
    int ans = INT_MAX;
    for(int i = 0;i<3;i++) {
        int t = ycnt - yhash[i];
        for(int j = 0;j<3;j++) {
            if(i == j) {
                continue;
            }
            int t1 = cnt - hash[j];
            ans = min(ans,t+t1);
        }
    }
    return ans;
}