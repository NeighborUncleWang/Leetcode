class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int lowBound = INT_MIN;
        for (int val : preorder) {
            if (val < lowBound) {
                return false;
            }
            //这一步就是我们从left subtree trace back回去
            //找到合适的节点作为当前节点的父节点，这个父节点就是之后所有值的low bound
            //当前节点作为父节点的右子节点
            //while loop是为了找到最小的lowBound
            //这样的原因是为了更容易满足val >= lowBound这个条件
            //也就是尽最大的努力找到一个preorder满足当前sequence的树
            while (!st.empty() && st.top() < val) {
                lowBound = st.top();
                st.pop();
            }
            st.push(val);
        }
        return true;
    }
};