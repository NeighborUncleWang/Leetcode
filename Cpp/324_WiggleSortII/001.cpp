class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        shuffle(nums);
        int size = nums.size();
        //slect the (size / 2 + 1)th element
        //实际上c++有nth_element这个函数，不过这里我自己实现了一下
        //median当数组size为偶数的时候选index为n/2或者n/2-1都行
        int median = selection(nums, 0, size - 1, size / 2 + 1);
        //好像只有这种virtualIndex map的方法比较容易找到对应逻辑
        //其他逻辑很难想
        //这个match的方法具体例子:
        //将nums数组的下标x通过函数idx()从[0, 1, 2, ... , n - 1, n] 映射到 
        //[1, 3, 5, ... , 0, 2, 4, ...], 得到新下标ix
        //以中位数mid为界,将大于mid的元素排列在ix的较小部分,而将小于mid的元素排列在ix的较大部分
        //这里quick-selection只是为了找到median的值,找到之后导致以median将nums partial sorted
        //这个结果没有用，也就是说int median = selection(nums, 0, size - 1, size / 2 + 1);之后
        //再加shuffle(nums)也能通过OJ
        //可以这么想，正常的three-way-partition结果是要让index[0, 1, 2, 3]对应的数比index[4, 5, 6, 7]大
        //这里wiggle sort的结果是要让index[1,3,5,7]对应的数比index[0, 2, 4, 6]大
        //所以要找一个函数把[0,1,2,3,4,5,6,7]映射到[1,3,5,7,0,2,4,6]
        //然后three-way-partition的时候就假设自己在做正常的partition,然后有index映射的缘故
        //原来想让index[0]的值最大，经过映射之后就让index[1]最大了
        //后面的index依此类推
        auto virtualIndex = [size](int i) { return (2 * i + 1) % (size | 1); };
        int large = -1;
        int small = size;
        for (int i = 0; i < small;) {
            if (nums[virtualIndex(i)] > median) {
                swap(nums[virtualIndex(++large)], nums[virtualIndex(i++)]);
            } else if (nums[virtualIndex(i)] < median) {
                swap(nums[virtualIndex(--small)], nums[virtualIndex(i)]);
            } else {
                ++i;
            }
        }
    }
private:
    void shuffle(vector<int>& nums) {
        int size = nums.size();
        for (int i = size - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(nums[i], nums[j]);
        }
    }
    int selection(vector<int>& nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }
        int pivotIndex = partition(nums, start, end);
        int order = pivotIndex - start + 1;
        if (order == k) {
            return nums[pivotIndex];
        } else if (order < k) {
            return selection(nums, pivotIndex + 1, end, k - order);
        } else {
            return selection(nums, start, pivotIndex - 1, k);
        }
    }
    int partition(vector<int>& nums, int start, int end) {
        int val = nums[end];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (nums[j] <= val) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[end]);
        return i + 1;
    }
};