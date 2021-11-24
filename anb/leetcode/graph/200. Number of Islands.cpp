class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i, j, k, n = grid.size(), m = grid[0].size(), dy[]={0,0,1,-1}, dx[]={1,-1,0,0}, ans = 0;
        bool vi[300][300] = {};
        queue<pair<int ,int>> q;
        
        for(i=0;i<n;i++) for(j=0;j<m;j++)
            if(grid[i][j] == '1' && !vi[i][j]) {
                ans += 1;
                vi[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    auto u = q.front(); q.pop();
                    for(k=0;k<4;k++){
                        int ty = u.first + dy[k], tx = u.second + dx[k];
                        if(0 <= ty && ty < n && 0 <= tx && tx < m && !vi[ty][tx] && grid[ty][tx] == '1') {
                            vi[ty][tx] = 1;
                            q.push({ty, tx});
                        }
                    }
                }
            }
        return ans;
    }
};