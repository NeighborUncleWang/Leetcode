class Solution {
private:
    unordered_map<char, char> hashMap;
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 4; ++i) {
            result <<= 8;
            char temp = (n >> (i * 8)) & 0xFF;
            //需要加上&0xFF，否则getReverse返回值会被转化成int
            //即使所有char 类型都改成unsigned char这里也会被转成int
            //所以必须加 & 0xFF;
            result |= getReverse(temp) & 0xFF;
        }
        return result;
    }
    char getReverse(char byte) {
        if (hashMap.find(byte) != hashMap.end()) {
            return hashMap[byte];
        }
        char reverseByte = 0;;
        for (int i = 0; i < 8; ++i) {
            reverseByte <<= 1;
            reverseByte |= (byte >> i) & 1;
        }
        hashMap[byte] = reverseByte;
        cout << hashMap.size() << endl;
        return reverseByte;
    }
};