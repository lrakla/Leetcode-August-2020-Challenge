class Solution {
public :
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int r=grid.size(), c = grid[0].size() , fresh =0, time =0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==2) rotten.push({i,j});
                if(grid[i][j]==1) fresh++;   
            }
        }
        while(!rotten.empty()){
            int n = rotten.size();
            for(int i=0;i<n;i++){
                int x = rotten.front().first,y = rotten.front().second;
                rotten.pop();

                if(x>0 && grid[x-1][y] ==1) { rotten.push({x-1,y}); fresh--; grid[x-1][y] =2;};
                if(x<r-1 && grid[x+1][y] ==1) { rotten.push({x+1,y}); fresh--; grid[x+1][y] =2;}; 
                if(y>0 && grid[x][y -1] ==1) { rotten.push({x,y-1}); fresh--; grid[x][y-1] =2;}; 
                if(y < c-1 && grid[x][y+1] ==1) { rotten.push({x,y+1}); fresh--; grid[x][y+1] =2;}; 
                
                
            }
            if(!rotten.empty()) time++;
        }
    
        return (fresh==0) ? time:-1;
    }    
};