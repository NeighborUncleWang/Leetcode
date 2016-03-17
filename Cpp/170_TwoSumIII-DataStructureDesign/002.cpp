class TwoSum {
public:
    //add takes O(n)
    //find takes O(1)
    //this can't pass since there is a test case has many add operations
	void add(int number) {
	    if (numSet.find(number) != numSet.end()) {
	        sumSet.insert(number * 2);
	    } else {
	        for (int num : numSet) {
	            sumSet.insert(num + number);
	        }
	        numSet.insert(number);
	    }
	}

	bool find(int value) {
	    return sumSet.find(value) != sumSet.end();
	}
private:
    unordered_set<int> sumSet;
    unordered_set<int> numSet;
};