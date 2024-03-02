#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;

/**
 * LCR 087. 复原 IP 地址
*/
vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<string> ls;

    backTrackRestoreIpAddresses(ans,ls,0,s);
    return ans;
}

void backTrackRestoreIpAddresses(vector<string>& ans,vector<string>& ls,int cur,string s) {
    if(cur == s.size() && ls.size() == 4) {
        string temp;
        for(int i = 0;i<3;i++) {
            temp.append(ls[i]);
            temp.append(".");
        }
        temp.append(ls[3]);
        ans.push_back(temp);
        return;
    }

    if(s.size() - cur > (4-ls.size())*3) {
        return;
    }

    for(int i = cur;i<s.size();i++) {
        string temp = s.substr(cur,i-cur+1);
        if(isRight(temp)) {
            ls.push_back(temp);
            backTrackRestoreIpAddresses(ans,ls,i+1,s);
            ls.pop_back();
        }
    }
    
}

bool isRight(string str) {

    if(str.size() == 1 && str != "0") {
        return true;
    }
    if(str.size() != 1 && str[0] == '0') {
        return false;
    }
    if(str.size() > 3) {
        return false;
    }
    if(stoi(str) > 255) {
        return false;
    }
    return true;
}

