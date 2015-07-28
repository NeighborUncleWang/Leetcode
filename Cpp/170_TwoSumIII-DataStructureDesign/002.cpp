class TwoSum {
public:
    //add takes O(n)
    //find takes O(1)
    //this can't pass since there is a test case has many add operations
	void add(int number) {
	    for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
	        if (hashSet.find(it->first + number) == hashSet.end()) {
	            hashSet.insert(it->first + number);
	        }
	    }
	    ++hashMap[number];
	}

	bool find(int value) {
	    return hashMap.find(value) != hashMap.end();
	}
private:
    unordered_set<int> hashSet;
    unordered_map<int, int> hashMap;
};
