class PhoneDirectory {
private:
    unordered_set<int> available;
    int n;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        n = maxNumbers;
        for (int i = 0; i < n; ++i) {
            available.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (available.empty()) return -1;
        int res = *available.begin();
        available.erase(available.begin());
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return available.find(number) != available.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        available.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */