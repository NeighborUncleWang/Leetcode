001.cpp:
Time complexity: O(nlogn)
Space complexity: O(n)
std::set is implemented by red black tree. So we can use it the store the results. The set can only store elements with unique key.我感觉这个特性导致这种解法有问题，因为假设只有一对elment满足要求，比如nums = [1, 5, 10, 5, 7, 19], t = 2, k = 2. 好像没问题，因为两个元素相等又在k范围里面的话这一对相等的元素肯定满足小于等于t了。还是要多睡觉啊，否则就脑残了。
