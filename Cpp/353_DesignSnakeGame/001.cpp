class SnakeGame {
private:
    deque<pair<int, int>> bodyq;
    unordered_set<pair<int, int>, function<int(pair<int, int>)>> bodyset;
    int width, height, index = 0;
    vector<pair<int, int>> food;
    unordered_map<string, pair<int, int>> map{
        {"U", {-1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"D", {1, 0}}
    };
public:
    /** Initialize your data structure here.
     @param width - screen width
     @param height - screen height
     @param food - A list of food positions
     E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        bodyq = deque<pair<int, int>>{{0, 0}};
        // bodyset的声明或者可以写成这样:
        // auto hash = [=](pair<int, int> position) {
        //         return position.first * width + position.second;
        // };
        // bodyset = unordered_set<pair<int, int>, function<int(pair<int, int>)>>({{0, 0}}, 10, hash);
        bodyset = unordered_set<pair<int, int>, function<int(pair<int, int>)>>(
            {{0, 0}}, 10, [=](pair<int, int> position) {
                return position.first * width + position.second;
            });
    }
    
    /** Moves the snake.
     @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     @return The game's score after the move. Return -1 if game over.
     Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = bodyq.front();
        auto next = make_pair(head.first + map[direction].first, head.second + map[direction].second);
        if (next.first < 0 || next.first >= height || next.second < 0 || next.second >= width) {
            return -1;
        }
        //这里要先从bodyset里删除back再检查是否吃到自己
        //因为贪吃蛇向前移动的时候尾巴会跟着移动
        //只要删除bodyset里的back就行了
        //bodyq不需要删除
        bodyset.erase(bodyq.back());
        if (bodyset.find(next) != bodyset.end()) {
            return -1;
        }
        bodyset.insert(next);
        bodyq.push_front(next);
        if (index < food.size() && next == food[index]) {
            ++index;
            bodyset.insert(bodyq.back());
        } else {
            bodyq.pop_back();
        }
        return bodyq.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */