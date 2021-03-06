class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans=0;
        for (int i=0;i<n-1;i++){
            ans += ((int)pow(26,n-i-1))*(s[i] - 'A' + 1) ;
        }
        ans += s[n-1] - 'A' + 1;
        return ans;
    }
};