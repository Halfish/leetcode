## 无重复字符的最长子串

链接：[无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/)

给定一个字符串 `s`，请你找出其中不含有重复字符的最长子串的长度。

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

## 思路

遍历字符串，遇到重复的就跳过，从重复的地方重新遍历。

## 题解
双指针，滑动窗口

