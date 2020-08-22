class Solution {
    void dfs(int num, int K, int N, vector<int>& res){
        if(N == 0){
            res.push_back(num);
            return;
        }
        int last_digit = num%10;
        if(last_digit -K >= 0) dfs(num*10 + last_digit - K, K, N-1, res);
        if(K>0 && last_digit + K < 10) dfs(num*10 + last_digit + K, K, N-1, res);
     
    }
public:
     vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if(N==1) res.push_back(0);
        for(int i=1;i<10;i++)
            dfs(i,K,N-1,res);
         return res;
    }
};