class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n==0) return 0;
        int a=0;
        int a_prev=INT_MIN;
        int h=INT_MIN;
        sort(c.begin(),c.end());
        for(int i =n-1;i>=0;--i){
            a = min(c[i],n-i);
            if(a_prev > a) 
                break;
            h = max(h,a);
            a_prev = a;           
        }
        return h;
    }
};