/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot robot.moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool robot.move();
 *
 *     // Robot will stay in the same cell after calling robot.turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void robot.turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        dfs(visited, robot, 0, 0, 0);
    }
private:
    // better to use x and y to indicate the input location here
    // use i and j will cause conflict in the for loop for variable i 
    void dfs(unordered_set<string>& visited, Robot& robot, int x, int y, int direction) {
        robot.clean();
        visited.insert(to_string(x) + "," + to_string(y));
        for (int i = 0; i < 4; ++i) {
            int ii = x, jj = y;
            switch (direction) {
                case 0:
                ++jj;
                break;
                case 90:
                ++ii;
                break;
                case 180:
                --jj;
                break;
                case 270:
                --ii;
                break;
                default:
                break;
            }
            string newLoc = to_string(ii) + "," + to_string(jj);
            if (visited.find(newLoc) == visited.end() && robot.move()) {
                dfs(visited, robot, ii, jj, direction);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
            direction = (direction + 90) % 360;
        }
    }
};
