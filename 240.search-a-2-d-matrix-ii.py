#
# @lc app=leetcode id=240 lang=python
#
# [240] Search a 2D Matrix II
#
# https://leetcode.com/problems/search-a-2d-matrix-ii/description/
#
# algorithms
# Medium (40.23%)
# Total Accepted:    160.3K
# Total Submissions: 398.5K
# Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
#
# Write an efficient algorithm that searches for a value in an m x n matrix.
# This matrix has the following properties:
# 
# 
# Integers in each row are sorted in ascending from left to right.
# Integers in each column are sorted in ascending from top to bottom.
# 
# 
# Example:
# 
# Consider the following matrix:
# 
# 
# [
# ⁠ [1,   4,  7, 11, 15],
# ⁠ [2,   5,  8, 12, 19],
# ⁠ [3,   6,  9, 16, 22],
# ⁠ [10, 13, 14, 17, 24],
# ⁠ [18, 21, 23, 26, 30]
# ]
# 
# 
# Given target = 5, return true.
# 
# Given target = 20, return false.
# 
#
class Solution(object):
    def binary_search(self, array, target):
        left, right = 0, len(array) - 1
        while left <= right:
            mid = left + (right - left) / 2
            mid_value = array[mid]
            if mid_value == target:
                return True
            elif array[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False            

    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        for i in range(len(matrix)):
            if matrix[i][0] <= target:
                if self.binary_search(matrix[i], target):
                    return True
            else:
                break
        return False
                

