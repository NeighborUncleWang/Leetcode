class LFUCache {
private:
    int cap;
    int size;
    int min_freq;
    unordered_map<int, pair<int, int>> map_value_freq;//map key to {value, frequence}
    unordered_map<int, list<int>::iterator> map_iter;
    unordered_map<int, list<int>> map_freq;//map frequence to a list of key
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!map_value_freq.count(key)) return -1;
        int freq = map_value_freq[key].second;
        map_freq[freq].erase(map_iter[key]);
        ++freq;
        map_iter[key] = map_freq[freq].insert(map_freq[freq].begin(), key);
        ++map_value_freq[key].second;
        if (map_freq[min_freq].empty()) {
            ++min_freq;
        }
        return map_value_freq[key].first;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        //这里必须要检查get(key)而不是map_iter.count(key)
        //因为有frequence update
        //还有题目说是在插入新元素之前按照LFU规则把老元素踢掉
        //而不是先插入再按照LFU规则来踢掉元素,那样的话新插入的元素可能经常被踢掉
        //因为刚插入进去frequence都是1
        if (get(key) != -1) {
            map_value_freq[key].first = value;
            return;
        }
        if (map_iter.size() == cap) {
            int evicted_key = map_freq[min_freq].back();
            map_freq[min_freq].pop_back();
            map_value_freq.erase(evicted_key);
            map_iter.erase(evicted_key);
        }
        map_value_freq[key] = {value, 1};
        map_iter[key] = map_freq[1].insert(map_freq[1].begin(), key);
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */