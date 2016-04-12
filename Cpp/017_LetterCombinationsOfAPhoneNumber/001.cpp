class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> result;
        string combination;
        dfs(digits, 0, result, combination);
        return result;
    }
private:
    void dfs(string& digits, int index, vector<string>& result, string& combination) {
        static vector<string> dictionary{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }
        /*main block, 很多回溯（backtracking）的题目都是一个for循环，然后里面三行代码，
         * 第一行push_back predecessor节点，第二行递归进入下一个搜索区域，第三行pop_back()。
         * 仔细回想，之所以回溯叫DFS，其实这个block和CLRS书上DFS的过程是一致的：
         * 对于图里面的每一个节点，如果color是white（代表没被访问过），
         * 则进行DFS（这个代码里相当于有一棵树，用“23”作为input的话，这棵树有一个根节点，
         * 处在deep = 0位置，三个deep = 1的节点，9个leaves。
         * 所以在letterCombinations里调用的generateCombinations就相当于ghosh课件40页的主函数里的DFS_VISIT1(s)，
         * 相当于是对source节点开始了DFS。这个题目里因为永远只有一棵树，不可能是forests，
         * 所以在letterCombinations函数体里只会调用一次generateCombinations，
         * 不会用for或者while循环体里面放generateCombinations来执行很多次。
         *
         *  sequence这个vector其实可以看成DFS中用来存储已经变成grey的node的stack，
         *  每次递归调用generateCombinations相当于是去访问和其相连的node了，所以在这之前sequence进行一次push_back(),
         *  相当于是DFS中把node染成grey，然后push到stack中。当generateCombinations（deep + 1）执行完，
         *  相当于相连的节点访问结束，所以把当前stack中的grey node pop出来。
        DFS过程：
        1.先把这个node color变成grey，然后push到一个stack中
        2.对于每一个和上述node相连的节点，call DFS_VISIT1.
        */
        for (char ch : dictionary[digits[index] - '0']) {
            //先把char push_back到sequence中
            combination.push_back(ch);
            dfs(digits, index + 1, result, combination);
            //回溯过程，把之前push_back进的char pop_back()掉，
            //所以整个过程只用了一个sequence的reference，没有生成多个拷贝
            combination.pop_back();
        }
    }
};