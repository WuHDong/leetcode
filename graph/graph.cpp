#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/**
 * LCR 105. 岛屿的最大面积
*/
int x1[4] = {1,-1,0,0};
int y1[4] = {0,0,-1,1};
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int ans = 0;

    for(int i = 0;i < row; i++) {
        for(int j = 0;j<col; j++) {
            if(grid[i][j] != 0) {
                ans = max(ans,dfsMaxAreaOfIsland(grid,i,j));
            }
        }
    }     
    return ans; 
}

int dfsMaxAreaOfIsland(vector<vector<int>>& grid,int x,int y) {
    if(x >= grid.size() || x < 0 || y < 0 || y >= grid[0].size() || grid[x][y] == 0 ) {
        return 0;
    }
    int temp = 1;
    grid[x][y] = 0;
    for(int i = 0;i<4;i++) {
        temp += dfsMaxAreaOfIsland(grid,x+x1[i],y+y1[i]);
    }
    return temp;
}

/**
 * LCR 106. 判断二分图
*/
bool ans = true;
bool isBipartite(vector<vector<int>>& graph) {
    int len = graph.size();
    vector<int> arr(len,0);
    for(int i = 0;i<len;i++) {
        if(arr[i] == 0) {
            bfsIsBipartite(graph,arr,i,1);
        }
    }
    return ans;
}

void bfsIsBipartite(vector<vector<int>>& graph,vector<int>& arr,int index,int cnt) {
    arr[index] = cnt;
    int cn = (cnt == 1 ? 2 : 1);
    for(int i : graph[index]) {
        if(arr[i] == 0) {
            bfsIsBipartite(graph,arr,i,cn);
            if(!ans) {
                return;
            }
        }else if(arr[i] != cn) {
            ans = false;
            return;
        }
    }
}
/**
 * LCR 107. 01 矩阵
*/
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> ans(row,vector<int>(col,-1));
    vector<vector<int>> visited(row,vector<int>(col,0));
    queue<pair<int,int>> q;
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) {
            if(mat[i][j] == 0) {
                q.emplace(i,j);
                ans[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }

    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    
    while (!q.empty()) {
        pair t= q.front();
        q.pop();
        int curx = t.first;
        int cury = t.second;

        for(int i = 0;i<4;i++) {
            int tx = curx + x[i];
            int ty = cury + y[i];
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && visited[tx][ty] == 0) {
                ans[tx][ty] = ans[curx][cury] + 1;
                visited[tx][ty] = 1;
                q.emplace(tx,ty);
            }
        }
    }
    return ans;
}

/**
 * LCR 108. 单词接龙
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> hashset;

    for(string s:wordList) {
        hashset.emplace(s);
    }

    if(!hashset.count(endWord)) {
        return 0;
    }

    queue<string> q;
    q.push(beginWord);

    int len = 0;
    while(!q.empty()) {
        int sz = q.size();
        len++;
        while(sz--) {
            string cur = q.front();
            q.pop();
            hashset.erase(cur);
            if(cur == endWord) {
                return len;
            }
            
            bfsLadderLength(cur,hashset,q);
        }
    }
    return 0;
}

void bfsLadderLength(string& word,unordered_set<string>& hashset,queue<string>& q) {

    for(int i = 0;i<word.size();i++) {
        char temp = word[i];
        for(char j = 'a'; j<='z';j++) {
            word[i] = j;
            if(j != temp && !hashset.count(word)) {
                hashset.emplace(word);
            }
            word[i] = temp;
        }
    }
}

