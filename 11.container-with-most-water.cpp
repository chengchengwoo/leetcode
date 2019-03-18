/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (42.48%)
 * Total Accepted:    322.7K
 * Total Submissions: 755.5K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        //return bruteForce(height);
        return doublePointers(height);
    }
    // T: O(n^2) S: O(1)
    int bruteForce(vector<int>& height) {
        int max_val = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i; j < height.size(); ++j) {
                max_val = max(max_val, min(height[i], height[j]) * (j - i));
            }
        }
        return max_val;
    }
    // T: O(n) S: O(1)
    int doublePointers(vector<int>& height) {
        int maxVal = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            maxVal = max(maxVal, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return maxVal;
    }
};

