class StringIterator {
private:
    int count = 0;
    istringstream s;
    char cur;
public:
    StringIterator(string compressedString) : s(compressedString) {}

    char next() {
        if (hasNext()) {
            --count;
            return cur;
        } else {
            return ' ';
        }
    }

    bool hasNext() {
        //count == 0的情况在hasNext()里处理比较好
        //因为初始化的时候count也是0,这样能够同时处理刚刚初始化和
        //后来count变成0的情况
        if (count == 0) {
            s >> cur >> count;
        }
        return count > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
