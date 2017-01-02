class MovingAverage {
private:
    queue<int> q;
    int sum = 0;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size(size) {
        
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum * 1.0 / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */