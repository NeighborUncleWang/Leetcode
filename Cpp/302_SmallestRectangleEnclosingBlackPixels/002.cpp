class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int rowSize = image.size();
        int columnSize = rowSize ? image[0].size() : 0;
        //top means the smaller row index boundary
        int smallRowIndex = search(image, 0, x, columnSize, true, true);
        int largeRowIndex = search(image, x, rowSize - 1, columnSize, true, false) - 1;
        int smallColumnIndex = search(image, 0, y, rowSize, false, true);
        int largeColumnIndex = search(image, y, columnSize - 1, rowSize, false, false) - 1;
        return (largeRowIndex - smallRowIndex + 1) * (largeColumnIndex - smallColumnIndex + 1);
    }
private:
    bool isWhite(vector<vector<char>>& image, int mid, int k, bool isRow) {
        return (isRow ? image[mid][k] : image[k][mid]) == '0';
    }
    int search(vector<vector<char>>& image, int smallBoundary, int largeBoundary, 
    int size, bool isRow, bool tag) {
        while (smallBoundary <= largeBoundary) {
            int mid = smallBoundary + (largeBoundary - smallBoundary) / 2;
            int k = 0;
            while (k < size && isWhite(image, mid, k, isRow)) ++k;
            if (k < size == tag) {
                largeBoundary = mid - 1;
            } else {
                smallBoundary = mid + 1;
            }
        }
        return smallBoundary;
    }
};