class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); ++i) {
        	//many people use i >= citation[i] here
        	// I use i + 1 instead since I think index i
        	// represents paper at position i + 1
        	// this can be from wikipedia for H index in Chinese
            //这里必须返回index而不是citation值
            //比如返回citations[i - 1]是错的
            //A scientist has index h if h of his/her N papers have at least h citations each...
            //"h of his/her N papers"，表面一定有一个index和h相等
            //"have at least h citations each"，表面不一定有一篇paper的citation数和H-index相等
            if (i + 1 > citations[i]) return i;
        }
        return citations.size();
    }
};