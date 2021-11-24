class Solution {
private:
    int dy[4]{0,0,1,-1}, dx[4]{1,-1,0,0}, n, m;
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, bool vi[200][200]) {
        while(!q.empty()){
            auto u = q.front(); q.pop();
            vi[u.first][u.second] = 1; // init queue data
            for(int i=0;i<4;i++){
                int ty = u.first + dy[i], tx = u.second + dx[i];
                if(0 <= ty && ty < n && 0 <= tx && tx < m && !vi[ty][tx] && heights[ty][tx] >= heights[u.first][u.second]) {
                    vi[ty][tx] = 1;
                    q.push({ty, tx});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int i, j;
        n = heights.size(), m = heights[0].size();
        bool vi_p[200][200]={}, vi_a[200][200]={};
        queue<pair<int, int>> q;
        
        for(i=0;i<n;i++) q.push({i, 0});
        for(i=0;i<m;i++) q.push({0, i});
        bfs(heights, q, vi_p);
        
        for(i=0;i<n;i++) q.push({i, m-1});
        for(i=0;i<m;i++) q.push({n-1, i});
        bfs(heights, q, vi_a);
        
        vector<vector<int>> ans;
        for(i=0;i<n;i++) for(j=0;j<m;j++)
            if(vi_p[i][j] && vi_a[i][j])
                ans.push_back({i, j});
        return ans;
    }
};