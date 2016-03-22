class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0) {
            return -1;
        }
        int sum = 0;
        int startPoint = 0;
        int total = 0;
        for (int i = 0; i < cost.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                startPoint = i + 1;
            }
        }
        //这里一定要total >= 0, total > 0不行
        //想象test case [2] [2]
        return total >= 0 ? startPoint : -1;
    }
};
