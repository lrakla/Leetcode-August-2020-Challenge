class Trie{
    Trie *children[26];
    bool endofWord;
public:
    Trie():endofWord(false){
        for (int i=0; i<26; i++)
            children[i] = nullptr;
    }
    void insert(string s){
        Trie *t = this;
        for(char c:s){
            if(t->children[c - 'a'] == nullptr) 
                t->children[c - 'a'] = new Trie();
            t = t->children[c - 'a'];
        }
        t->endofWord = true;
    }
    bool search(deque<char>& s){
        Trie *t =  this;
        for(char c : s){
            if(t->children[c - 'a'] == nullptr) return false;
            t = t->children[c - 'a'];
            if(t->endofWord) return true;
        }
        return false;
    } 
};

class StreamChecker{
    Trie t;
    deque<char> stream;
public:
    StreamChecker(vector<string>& words) {
        for(auto& w : words){
            reverse(w.begin(),w.end());
            t.insert(w);
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        return t.search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */