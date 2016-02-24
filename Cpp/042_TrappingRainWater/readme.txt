001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/16171/sharing-my-simple-c-code-o-n-time-o-1-space
heigt[left],height[right]，想象两个值哪个大水就从哪边往另一边灌，另一边扫过的最大值可以帮助接水。
比如height[left] > height[right]，那么水从左边往右边灌，然后算上当前bar的maxRight用来接水。