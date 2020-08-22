class CombinationIterator {
    queue<string> q;
    string s;
    void getCombo(int start,int length, string txt){
        if(length == 0){
            q.push(txt);
            return;
        }
        for(int i =start; i <= s.length() -1; i++)
            getCombo(i+1,length -1 , txt + s[i]);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        string txt = "";
        getCombo(0,combinationLength, txt);
    }
    
    string next() {
        string ans = q.front();
        q.pop();
        return ans;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */