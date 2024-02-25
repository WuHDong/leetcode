#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;


/**
 * 2788. 按分隔符拆分字符串
*/
vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> ans;

    
    for(int i = 0;i<words.size();i++) {
        string temp="";
        for(int j = 0;j<words[i].size();j++) {
            if(words[i][j] == separator) {
                if(temp != "") {
                    ans.push_back(temp);
                }
                temp= "";
            }else{
                temp += words[i][j];
            }
        }
        if(temp != "") {
            ans.push_back(temp);
        }
    }
    return ans;
}

/**
 * 670. 最大交换
*/
int maximumSwap(int num) {
    string s = to_string(num);
    int len = s.size();

    int maxV = -1;
    for(int i = 0;i<len;i++) {
        for(int j = i+1;j<len;j++) {
            if(s[j] > s[i]) {
                string st = s;
                char t = st[i];
                st[i] = st[j];
                st[j] = t;

                if(maxV < stoi(st)) {
                    maxV = stoi(st);
                }
            }
        }
    }
    if(maxV == -1) {
        return num;
    }
    return maxV;
}

/**
 * 15. 三数之和
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    if(nums[0] > 0) {
        return ans;
    }

    int len = nums.size();
    for(int i = 0;i<len;i++) {
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int target = -nums[i];
        int third = len-1;
        for(int j = i+1;j<len;j++) {
            if(j > i+1 && nums[j] == nums[j-1]) {
                continue;
            }
            while(third > j && nums[j] + nums[third] > target) {
                third--;
            }

            if(third == j) {
                break;
            }
            if(nums[j] + nums[third] == target) {
                ans.push_back({nums[i],nums[j],nums[third]});
            }
        }
    }
    return ans;
}

/**
 * 135. 分发糖果
*/
int candy(vector<int>& ratings) {
    int ans = 1;
    int pre = 1;
    int dec = 0;
    int inc = 1;
    for(int i = 1;i<ratings.size();i++) {
        if(ratings[i] >= ratings[i-1]) {
            dec = 0;
            pre = ratings[i] == ratings[i-1] ? 1 : pre +1;
            ans += pre;
            inc = pre;
        }else{
            dec++;
            if(dec == inc) {
                dec++;
            }
            ans += dec;
            pre = 1;
        }
    }
    return ans;
}

/**
 * LCR 183. 望远镜中最高的海拔
*/
vector<int> maxAltitude(vector<int>& heights, int limit) {
    
    deque<int> dq;
    vector<int> ans;
    int len = heights.size();
    if(len == 0) {
        return ans;
    }
    for(int i = 0;i<limit;i++) {
        while(!dq.empty() && heights[dq.back()] < heights[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(heights[dq.front()]);
    for(int i = limit; i < len; i++) {
        while(!dq.empty() && heights[dq.back()] < heights[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        while(dq.front() <= i - limit) {
            dq.pop_front();
        }
        ans.push_back(heights[dq.front()]);
    }
    return ans;
} 

/**
 * 1944. 队列中可以看到的人数
*/
vector<int> canSeePersonsCount(vector<int>& heights) {
    int len = heights.size();
    vector<int> ans(len,0);
    vector<int> st;

    for(int i = len -1;i>=0;i--) {
        int t = 0;
        while(!st.empty() && heights[i] > st.back()) {
            st.pop_back();
            t++;
        }
        if(!st.empty()) {
            t++;
        }
        ans[i] = t;
        st.push_back(heights[i]);
    }
    return ans;
}