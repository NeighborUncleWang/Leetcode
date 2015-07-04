001.cpp:
Time complexity: O(n)
Space complexity: O(1)(I think the space complexity is O(1), since the size of hash set will never be larger than 256(size of char is 1byte)
002.cpp:
Time complexity: O(n)
Space complexity: O(1)
Since the char is an int type value(it can be converted an integer), so we can use this as a hash function to construct an array as a hashtable, the key is the value of the char, and the value is the index of this char.
