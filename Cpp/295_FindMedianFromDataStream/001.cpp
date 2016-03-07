class MedianFinder {
private:
    //maxHeap stores the smaller half
    priority_queue<int> maxHeap;
    //minHeap stores the larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        //必须是先push到一个heap里，然后再pop出来push到另一个heap里
        //也就是说一个num必须在两个heap里都待过
        //具体是哪个heap先哪个heap后无所谓
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        //因为maxHeap在前面三行code中只是起了个过渡作用
        //所以最开始肯定是maxHeap会比minHeap的size小一些
        //但是经过这个调整之后，maxHeap size一定>=minHeap
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return maxHeap.top() + (minHeap.top() - maxHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();