// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        //read4(char *buf) 是指从文件中读4个字符存到buf所指的内存空间，而不是从buf这个指针指向的空间读字符
        //网上有些解答用了 auto buffer = new char[5];其实是错的，他们都没有用OJ测试过代码（没有买书）
        //OJ最后会测试buf所指向内存的内容是什么，所以新开一个数组没有任何卵用
        int total = 0;
        while (total < n) {
            int actualRead = read4(buf + total);
            if (actualRead == 0) {
                return total;
            }
            total += actualRead;
        }
        return n;
    }
};
