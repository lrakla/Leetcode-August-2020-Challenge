class MyHashSet {
    int bucket_size;
    vector<vector<int>> bucket;
    int hash(int key){
        return (key % bucket_size);
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        bucket_size = 15000;
        bucket = vector<vector<int>>(bucket_size, vector<int>{});
    }
    
    void add(int key) {
        int i = hash(key);
        if(find(bucket[i].begin(), bucket[i].end(),key) == bucket[i].end())
            bucket[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = find(bucket[i].begin(), bucket[i].end(),key);
        if(it != bucket[i].end())
            bucket[i].erase(it);     
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i = hash(key);
        if(find(bucket[i].begin(), bucket[i].end(),key) == bucket[i].end())
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */