001.cpp:
Time complexity: O(n)
Space complexity: O(n)
Reference:
https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
Here is a good article to understand this algorithm:
http://eli.thegreenplace.net/2010/05/28/the-intuition-behind-fisher-yates-shuffling/

A proof:
For any element in the array, the probability to be selected to the (n - 1)th position is 1/n. The probability to be selected to the (n - 2)th posistion is: 
(1)Not chosen to position (n - 1) : (1 - 1/n)
(2)Chosen to position n - 2: 1/(n - 1)
So the total probability is: (1 - 1/n) * (1/(n - 1)) = 1/n
For all other positions, we can use the same way to prove it.