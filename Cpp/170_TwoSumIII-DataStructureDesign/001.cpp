class TwoSum {
public:
	void add(int number) {
	    ++hashMap[number];
	}

	bool find(int value) {
	    for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
	        auto target = value - it->first;
	        //先检查target是否等于it->first，而不是temp = hashMap.find(target)之后再来看temp == it
	        //这样可以省下一些情况的搜索时间，否则会TLE
			//其实即使AC也非常接近TLE了（1540ms）
			//有时候再次提交会TLE，这网站坑爹啊
	        if (target == it->first) {
	            if (it->second > 1) {
	                return true;
	            }
	        } else {
	            if (hashMap.find(target) != hashMap.end()) {
	                return true;
	            }
	        }
	    }
	    return false;
	}
private:
    unordered_map<int, int> hashMap;
};
