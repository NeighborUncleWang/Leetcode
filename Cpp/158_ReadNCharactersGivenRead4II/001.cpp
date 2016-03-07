// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    int bufferPtr = 0;
    int bufferCount = 0;
    char buffer[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ptr = 0;
        while (ptr < n) {
            if (bufferPtr == 0) {
                //use read4(buffer) not read4(buf)
                bufferCount = read4(buffer);
                if (bufferCount == 0) break;
            }
            while (ptr < n && bufferPtr < bufferCount) {
                buf[ptr++] = buffer[bufferPtr++];
            }
            //it means we've read all chars from internal buffer
            if (bufferPtr == bufferCount) {
                bufferPtr = 0;
            }
        }
        return ptr;
    }
};