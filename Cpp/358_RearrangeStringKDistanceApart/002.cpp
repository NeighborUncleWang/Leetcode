class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;
        unordered_map<char, int> map;
        for (char ch : str) {
            map[ch]++;
        }
        //pq必须是最大堆，必须让count最大的char最先被插入结果中
        //否则"abb",2这个case过不去
        priority_queue<pair<int, char>> pq;
        for (auto it : map) {
            pq.emplace(it.second, it.first);
        }
        vector<pair<int, char>> temp;
        string result;
        int length = str.size();
        while (!pq.empty()) {
            int size = min(length, k);
            for (int i = 0; i < size; ++i) {
                if (pq.empty()) return "";
                result.push_back(pq.top().second);
                auto top = pq.top();
                pq.pop();
                if(--top.first > 0) {
                    temp.push_back(move(top));
                }
                --length;
            }
            //这里结束之后不用把pq清空
            for (auto it : temp) {
                pq.push(it);
            }
            temp.clear();
        }
        return result;
    }
};