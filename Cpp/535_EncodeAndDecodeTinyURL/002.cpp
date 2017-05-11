class Solution {
private:
    vector<string> urls;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls.push_back(longUrl);
        return "http://tinyurl.com/" + to_string(urls.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index = stoi(shortUrl.substr(shortUrl.rfind('/') + 1));
        return urls[index];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));