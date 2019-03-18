/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.34%)
 * Total Accepted:    489.2K
 * Total Submissions: 2.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //return bruteForce(nums);
        return doublePointers(nums);
    }
    // T: O(n^3) S: O(n)
    // Time Limit Exceeded
    vector<vector<int>> bruteForce(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet{nums[i], nums[j], nums[k]};
                        if (s.insert(triplet).second) {
                            res.push_back(triplet);
                        }
                    }
                }
            }
        }
        return res;
    }
    // T: O(n^2) S: O(1)
    vector<vector<int>> doublePointers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int k = nums.size() - 1; k >= 2; --k) {
            if (nums[k] < 0) {
                break;
            }
            int i = 0;
            int j = k - 1;
            int target = -nums[k];
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++i;
                    --j;
                    for (; i < j && nums[i] == nums[i - 1]; ++i);
                    for (; i < j && nums[j] == nums[j + 1]; --j);
                } else if (nums[i] + nums[j] < target) {
                    ++i;
                } else {
                    --j;
                }
            }
            for (; k >= 3 && nums[k] == nums[k - 1]; --k);
        }
        return res;
    }
};

