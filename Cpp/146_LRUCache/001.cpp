class LRUCache{
private:
    unordered_map<int, list<pair<int, int>>::iterator> hashMap;
    list<pair<int, int>> keyList;
    int capacity;
    void moveToHead(int key) {
        keyList.emplace_front(key, hashMap[key]->second);
        keyList.erase(hashMap[key]);
        hashMap[key] = keyList.begin();
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    //each time we set, insert, modify an element, we move it to the head of the list
    //the doubly-linked list is the data structure actually store the cache nodes, 
    //the hashMap maps the iterator of the list with the key
    int get(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            moveToHead(key);
            return hashMap[key]->second;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            hashMap[key]->second = value;
            moveToHead(key);
        } else {
            //delete the element at the tail of the list, that is the LRU element
            if (hashMap.size() == capacity) {
                hashMap.erase(keyList.back().first);
                keyList.pop_back();
            }
            keyList.emplace_front(key, value);
            hashMap[key] = keyList.begin(); 
        }
    }
};