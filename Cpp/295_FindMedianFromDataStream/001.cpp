class MedianFinder {
private:
    //maxHeap stores the smaller half
    priority_queue<int> maxHeap;
    //minHeap stores the larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
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