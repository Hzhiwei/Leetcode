// LongestPalindromicSubstring.cpp: 定义控制台应用程序的入口点。
//


/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/



#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Solution 
{
public:

	/*
	描述：
	最小的回文为两个字符。
	回味字符有两种，单数，双数
	单数：从下标x=1开始，以x为对称中心向两边扩展找回文，结束位置不是倒数第二个字符，实际是根据前面算出的最长长度决定的。
	双数：与单数差不多
	*/
	string longestPalindrome(string s) 
	{
		int n = s.length();
		int median;
		int max1 = 1, max2 = 1;
		int maxStart1 = 0, maxEnd1 = 0, maxStart2 = 0, maxEnd2 = 0;

		for (int median = 1; median <= n - (max1 + 1) / 2; median++)
		{
			bool flag = true;
			for (int expand = 1; expand <= median; expand++)
			{
				if (s[median - expand] != s[median + expand])
				{
					flag = false;
					break;
				}
				else
				{
					if (flag)
					{
						if (max1 < expand + expand + 1)
						{
							max1 = expand + expand + 1;
							maxStart1 = median - expand;
							maxEnd1 = median + expand;
						}
					}
				}
			}
		}

		for (int median = 1; median <= n - max2 / 2; median++)
		{
			bool flag = true;
			for (int expand = 1; expand <= median; expand++)
			{
				if (s[median - expand] != s[median + expand - 1])
				{
					flag = false;
					break;
				}
				else
				{
					if (flag)
					{
						if (max2 < expand + expand)
						{
							max2 = expand + expand;
							maxStart2 = median - expand;
							maxEnd2 = median + expand - 1;
						}
					}
				}
			}
		}

		if (max1 == 1 && max2 == 1)
		{
			return s.substr(0, 1);
		}
		else
		{
			if (max1 > max2)
			{
				return s.substr(maxStart1, maxEnd1 - maxStart1 + 1);
			}
			else
			{
				return s.substr(maxStart2, maxEnd2 - maxStart2 + 1);
			}
		}
	}
};


int main()
{
	string str;
	Solution sol;

	while (true)
	{
		cin >> str;
		cout << sol.longestPalindrome(str) << endl;
	}

    return 0;
}

