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
        int readTotal = 0;
        //indicates whether the end of file is reached
        bool eof = false;
        while (!eof && readTotal < n) {
            if (bufferSize == 0) {
                bufferSize = read4(buffer);
                eof = bufferSize < 4;
            }
            int bytes = min(n - readTotal, bufferSize);
            memmove(buf + readTotal, buffer + offset, bytes);
            readTotal += bytes;
            offset = (offset + bytes) % 4;
            bufferSize -= bytes;
        }
        return readTotal;
    }
private:
    char buffer[4];
    int offset = 0;
    int bufferSize = 0;
};
