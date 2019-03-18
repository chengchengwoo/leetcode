/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.23%)
 * Total Accepted:    184.9K
 * Total Submissions: 556.5K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //return usingDP(obstacleGrid);
        return usingDPOneArray(obstacleGrid);
    }
    // T: O(m*n) S: O(m*n)
    int usingDP(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < m; ++i) {
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
        }
        for (int i = 1; i < n; ++i) {
            dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    // T: O(m*n) S: O(min(m, n))
    int usingDPOneArray(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
       
        bool rollByRow = true;
        int dpSize = n;
        if (m < n) {
            rollByRow = false;
            dpSize = m;
        }
        vector<long long> dp(dpSize, 0);
        dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < (rollByRow ? m : n); ++i) {
            if (rollByRow) {
                dp[0] = obstacleGrid[i][0] == 1 ? 0 : dp[0];
            } else {
                dp[0] = obstacleGrid[0][i] == 1 ? 0 : dp[0];
            }
            for (int j = 1; j < (rollByRow ? n : m); ++j) {
                if (rollByRow) {
                    dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j - 1] + dp[j];
                } else {
                    dp[j] = obstacleGrid[j][i] == 1 ? 0 : dp[j - 1] + dp[j];
                }
            }
        }
        return dp[dpSize - 1];
    }
};

