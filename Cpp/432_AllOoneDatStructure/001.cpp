class AllOne {
private:
    struct Bucket{
        int val;
        unordered_set<string> keys;
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucket_of_key;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!bucket_of_key.count(key)) {
            bucket_of_key[key] = buckets.insert(buckets.begin(), {0, {key}});
        }
        auto next = bucket_of_key[key], current = next++;
        if (next == buckets.end() || next->val > current->val + 1) {
            next = buckets.insert(next, {current->val + 1, {}});
        }
        next->keys.insert(key);
        bucket_of_key[key] = next;
        current->keys.erase(key);
        if (current->keys.empty()) {
            buckets.erase(current);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!bucket_of_key.count(key)) return;
        auto previous = bucket_of_key[key], current = previous--;
        bucket_of_key.erase(key);
        //这里记得用current->val而不要用bucket_of_key[key]->val
        //因为 bucket_of_key.erase(key)已经把key erase掉了
        if (current->val > 1) {
            if (current == buckets.begin() || previous->val < current->val - 1) {
                previous = buckets.insert(current, {current->val - 1, {}});
            }
            previous->keys.insert(key);
            bucket_of_key[key] = previous;
        }
        current->keys.erase(key);
        if (current->keys.empty()) {
            buckets.erase(current);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */