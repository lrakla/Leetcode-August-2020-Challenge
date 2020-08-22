class Solution{
public:
    vector<int> findPermutation(string s){
        stack<int> x;
        int n = s.length(), index=0;
        vector<int> ans(n+1);
        for(int i-0;i<n;i++){
            if(s[i]== 'I'){
                x.push(i+1);
                while(!x.empty()){
                    ans[index++] = x.pop();
                }
            }
            else{
                x.push(i+1);
            }
        }
        x.push(n+1);
        while(!x.empty())
            ans[index++] = x.pop();
        return ans; 
    }
}