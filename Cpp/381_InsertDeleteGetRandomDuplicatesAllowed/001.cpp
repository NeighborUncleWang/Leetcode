class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool rv = false;
        if (locations.find(val) == locations.end()) {
            rv = true;
        }
        locations[val].insert(nums.size());
        nums.push_back(val);
        return rv;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (locations.find(val) == locations.end()) {
            return false;
        }

        int index = *(locations[val].begin());
        //必须把locations[val].erase(index);放在if statement前面，否则
        //["RandomizedCollection","insert","insert","insert","insert","insert","insert"
        //,"remove","remove","remove","remove","getRandom","getRandom","getRandom",
        //"getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
        //[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]
        //这个case通不过，因为不先erase再insert的话当val和last相同时
        //会导致locations[last].insert(index)失败
        int last = nums.back();
        //这里要先insert再erase,否则
        //["RandomizedCollection","insert","remove","insert","remove","getRandom",
        //"getRandom","getRandom","getRandom","getRandom","getRandom","getRandom",
        //"getRandom","getRandom","getRandom"]
        //[[],[0],[0],[-1],[0],[],[],[],[],[],[],[],[],[],[]]
        //这个case过不去,因为会locations[0].erase(0)两次，第二次时locations[0]已经empty
        //其实主要就是要考虑nums.back() == val的情况
        locations[val].erase(index);
        locations[last].insert(index);
        locations[last].erase(nums.size() - 1);
        //这三行的顺序只能这么写
        // locations[last].erase(nums.size() - 1);
        // locations[last].insert(index);
        // locations[val].erase(index);
        // 这样写也不行，因为当val和last相等时，第一次locations[last].insert(index);
        // 会失败，因为没有移除已经存在的index
        // 就看看
        // locations[val].erase(nums.size() - 1);
        // locations[val].insert(index);
        // locations[val].erase(index);
        // 和
        // locations[val].erase(index);
        // locations[val].insert(index);
        // locations[val].erase(nums.size() - 1);
        // 这两种情况哪个会出错(把last对应的位置都换成val)
        nums[index] = last;
        nums.pop_back();
        if (locations[val].empty()) {
            locations.erase(val);
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    //这里必须用unordered_set<int>来存indices而不是vector<int>
    //因为后面要locations[last].erase(nums.size() - 1)，vector<int>不能定向删除
    unordered_map<int, unordered_set<int>> locations;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
