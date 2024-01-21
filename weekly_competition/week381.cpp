#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/**
 * 100191. 输入单词需要的最少按键次数 I
*/
int minimumPushes(string word) {
    int len = word.size();
    int ans = 0;
    int cnt = 1;
    while (len >= 8)
    {
        ans += cnt * 8;
        cnt++;
        len -= 8;
    }
    
    ans += len * cnt;
    return ans;
}

/**
 * 100188. 按距离统计房屋对数目 I
*/
vector<int> countOfPairs(int n, int x, int y) {
    vector<int> ans(n,0);
    vector<vector<int>> graph (n,vector<int>(n,INT_MAX));

    graph[x-1][y-1] = 1;
    graph[y-1][x-1] = 1;
    for(int i = 0;i<n-1;i++) {
        graph[i][i+1] = 1;
        graph[i+1][i] = 1;
    }

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            for(int k = 0;k<n;k++) {
                if(graph[i][j] != INT_MAX && graph[j][k] != INT_MAX) {
                    graph[i][k] = min(graph[i][k],graph[i][j] + graph[j][k]);
                    graph[k][i] = graph[i][k];
                }
            }
        }
    }


    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(graph[i][j] != INT_MAX) {
                ans[graph[i][j] -1]++;
            }
        }
    }
    for(int i = 0;i<n;i++) {
        ans[i] = ans[i]*2;
    }
    return ans;
}

/**
 * 100192. 输入单词需要的最少按键次数 II
*/

static bool cmp(const pair<char,int>& a,const pair<char,int>& b) {
    return a.second > b.second;
}

int minimumPushes(string word) {
    unordered_map<char,int> hash;
    int len = word.size();

    for(int i = 0;i<len;i++) {
        hash[word[i]]++;
    }

    vector<pair<char,int>> arr(hash.begin(),hash.end());
    sort(arr.begin(),arr.end(),cmp);
    int len = arr.size();
    int ans = 0;
    int cnt = 1;
    
    while(len >= 8) {
        for(int i = 0;i<8;i++) {
            ans += arr[i + (cnt - 1) * 8].second * cnt;
        }
        len -= 8;
        cnt++;
    }

    int sz = arr.size();
    for(int i = sz-1;i >= sz - len;i--) {
        ans += arr[i].second*cnt;
    }
    return ans;
}