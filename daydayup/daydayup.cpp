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