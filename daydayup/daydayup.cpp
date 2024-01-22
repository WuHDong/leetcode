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