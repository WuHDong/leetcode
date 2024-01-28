#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


/**
 * 100215. 按键变更的次数
*/
int countKeyChanges(string s) {
    int len = s.size();
    int ans = 0;
    char t = s[0];

    for(int i = 1; i < len; i++) {
        if(abs(t - s[i]) == 32 || t = s[i]) {
            continue;
        }
        ans++;
        t = s[i];
    }
    return ans;
}

/**
 * 100206. 子集中元素的最大数量
*/
int maximumLength(vector<int>& nums) {
    unordered_map<long long,int> hashmap;
    int len = nums.size();
    for(int i = 0;i<len;i++) {
        hashmap[nums[i]]++;
    }

    sort(nums.begin(),nums.end());

    int ans = 0;
    int oneCnt = 0;
    for(int i = 0;i<len;i++) {
        long long t = nums[i];
        int cnt = 1;
        if(t == 1) {
            oneCnt++;
            continue;
        }
        
        while(hashmap.count(t * t)) {
            if(hashmap[t] >= 2) {
                hashmap[t] -= 2;
                cnt++;
                t = t*t;
            }else{
                break;
            }
            
        }
        ans = max(ans,cnt);
    }
    
    ans = ans * 2 - 1;
    if(oneCnt % 2 == 0) {
        oneCnt--;
    }
    ans = max(ans,oneCnt);
    return ans;
}

/**
 * 100195. Alice 和 Bob 玩鲜花游戏
*/
long long flowerGame(int n, int m) {
    long long ans = 0;

    long long t1 = n % 2 == 0 ? n/2 : n/2+1;
    long long t2 = n/2;

    long long t3 = m % 2 == 0 ? m/2 : m/2 + 1;
    long long t4 = m/2;

    ans = t1*t4 + t2*t3;
    return ans;
}