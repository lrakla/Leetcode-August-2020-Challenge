class Solution {
    vector<vector<int>> rects;
    int pt_count;
    vector<int> cum_pt_count;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        pt_count =0;
        for(auto &rect : rects){
            pt_count+=(rect[3] - rect[1] +1 )*(rect[2] - rect[0] +1 );
            cum_pt_count.push_back(pt_count);
        }
        
    }
    
    vector<int> pick() {
        int idx = rand() % pt_count;
        int l =0 ,r = rects.size() -1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(cum_pt_count[mid] <= idx ) l = mid +1; //l = rectangle idx
            else r = mid;
        }
        vector<int>& rect = rects[l];
        int x_pts = rect[2] - rect[0] +1;
        int y_pts = rect[3] - rect[1] +1;
        int pts = x_pts * y_pts;
        int pt_start = cum_pt_count[l] - pts;
        int offset = idx - pt_start;
        return {rect[0] + offset % x_pts, rect[1] + offset/x_pts};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */