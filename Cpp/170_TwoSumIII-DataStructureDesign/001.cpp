class TwoSum {
private:
    unordered_map<int, int> hashMap;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    ++hashMap[number];
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto iter : hashMap) {
	        int target = value - iter.first;
	        if (target == iter.first && iter.second > 1 
	        || target != iter.first && hashMap.find(target) != hashMap.end()) {
	            return true;
	        }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);