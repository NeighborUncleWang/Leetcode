class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); ++i) {
        	//many people use i >= citation[i] here
        	// I use i + 1 instead since I think index i
        	// represents paper at position i + 1
        	// this can be from wikipedia for H index in Chinese
            if (i + 1 > citations[i]) return i;
        }
        return citations.size();
    }
};