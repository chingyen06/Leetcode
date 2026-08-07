/*
Runtime:
0ms
Beats
100.00%

Memory:
62.96MB
Beats
49.76%
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0, area;

        while (left < right) {
            if (height[left] < height[right]) {
                area = height[left] * (right - left);
                left++;
            }
            else {
                area = height[right] * (right - left);
                right--;
            }

            if (max_area < area)
                max_area = area;
        }

        return max_area;
    }
};