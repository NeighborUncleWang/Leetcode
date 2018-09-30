001.cpp
Time compelxity: O(N)
Space complexity: O(N)
N is the size of the word list
Reference:
https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison
002.cpp
Time compelxity: O(N^2)
Space complexity: O(N^2)
N is the size of the word list
Reference:
https://leetcode.com/problems/guess-the-word/solution/
https://leetcode.com/problems/guess-the-word/discuss/134251/Optimal-MinMax-Solution-(+-extra-challenging-test-cases)
Minimax做法，第二个链接的解释详细很多。
For each word, we compute a histogram of its distance from every word in the candidate set,
and then select the word whose histogram peak (max) is smallest (min).
That property guarantees that the selected word partitions the candidate set well
by distance and that it has the potential to eliminate the maximum number of elements.
histogram peak是最糟糕的情况，peak histogram的高度决定了下一个possible vector的size。
path里存的是已经猜过的词
Minimax是在最坏的情况下选最好的结果
