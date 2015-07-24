class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (hashMap.find(key) == hashMap.end()) {
            return -1;
        } else {
            MoveToHead(key);
            return hashMap[key]->value;
        }
    }
    
    void set(int key, int value) {
        //each time we set, insert, modify an element, we move it to the head of the list
        //the doubly-linked list is the data structure actually store the cache nodes, 
        //the hashMap maps the iterator of the list with the key
        if (hashMap.find(key) != hashMap.end()) {
            hashMap[key]->value = value;
            MoveToHead(key);
        } else {
            //delete the element at the tail of the list, that is the LRU element
            if (cacheList.size() == capacity) {
                hashMap.erase(cacheList.back().key);
                cacheList.pop_back();
                cacheList.push_front(CacheEntry(key, value));
                hashMap[key] = cacheList.begin();
            } else {
                cacheList.push_front(CacheEntry(key, value));
                hashMap[key] = cacheList.begin();
            }
        }
    }
private:
    struct CacheEntry{
        int key;
        int value;
        CacheEntry(int key, int value) : key(key), value(value) {}
    };
    int capacity;
    list<CacheEntry> cacheList;
    unordered_map<int, list<CacheEntry>::iterator> hashMap;
    void MoveToHead(int key) {
        cacheList.push_front(*hashMap[key]);
        cacheList.erase(hashMap[key]);
        hashMap[key] = cacheList.begin();
    }
};
