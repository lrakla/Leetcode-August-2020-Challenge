class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int c_upper=0,c_lower=0;
        for(int i=0;i<n;i++){
            if(isupper(word[i])) c_upper++;
            else c_lower++;
        }
        if(isupper(word[0]) && c_lower == n-1) return true;
        if(c_upper == n) return true;
        if(c_lower ==n) return true;
    
        return false;
    }
};