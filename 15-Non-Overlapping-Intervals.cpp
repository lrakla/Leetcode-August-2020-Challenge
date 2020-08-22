class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& itv) {
        if(itv.size()<2) return 0;
        sort(itv.begin(),itv.end(), []( vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });
        int count=0,last_incl=0;
        for(int i=1; i<itv.size(); i++){
            if(itv[i][0] < itv[last_incl][1]){
                count++;
                if(itv[i][1] < itv[last_incl][1]) last_incl=i;
            }
            else
                last_incl=i;
        }
        return count;
        
    }
};