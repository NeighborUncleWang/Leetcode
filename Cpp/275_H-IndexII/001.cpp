class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int low = 0;
        int high = size - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            //如果size - middle是一个valid H-index
            //那么表示citations[middle] >= size - middle
            //因为表示有size - middle篇论文citations>= size - middle
            //因为size - middle篇论文citations都>=citations[middle]
            //所以citations[middle]>= size - middle
            //这表明size - middle可以是一个valid h-index
            //然后我们让middle变小，来看是否能增大h-index
            //最后一定是low和high两个index分别满足citations[index] >= size - index
            //和citations[index] < size - index
            //然后根据把citations画成图像可以知道index越大越容易满足citations[index] >= size - index
            //所以一定是citations[low] >= size - low
            //citations[high] < size - high
            if (citations[middle] >= size - middle) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        return size - low;
    }
};