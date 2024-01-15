#include<algorithm>
#include<vector>
#include<iostream>
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

