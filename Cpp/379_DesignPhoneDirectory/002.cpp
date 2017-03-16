class PhoneDirectory {
private:
    vector<bool> available;
    vector<int> list;
    int size;
    int count;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : available(maxNumbers, true), 
    list(maxNumbers), size(maxNumbers), count(maxNumbers) {
        iota(list.begin(), list.end(), 0);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (size == 0) return -1;
        int result = list[--size];
        available[result] = false;
        return result;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 || number >= count) return false;
        return available[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= count || available[number]) return;
        list[size++] = number;
        available[number] = true;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */