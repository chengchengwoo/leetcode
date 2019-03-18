/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (34.76%)
 * Total Accepted:    310.2K
 * Total Submissions: 889.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // T: O(n*logn) S: O(n)
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;

        sort(intervals.begin(), intervals.end(),
            [](const Interval& lhs, const Interval& rhs) {
                return lhs.start < rhs.start;
            });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > res[res.size() - 1].end) {
                res.push_back(intervals[i]);
            } else if (intervals[i].end > res[res.size() - 1].end) {
                res[res.size() - 1].end = intervals[i].end;
            }
        }
        return res;
    }
};

