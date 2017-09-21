// oj1.cpp: 定义控制台应用程序的入口点。
//

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2 :
	nums1 = [1, 2]
	nums2 = [3, 4]

	The median is(2 + 3) / 2 = 2.5
*/


#include "stdafx.h"

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int num1StartIndex = 0, num1EndIndex = nums1.size(), num2StartIndex = 0, num2EndIndex = nums2.size();
		int last1, last2;

		last1 = num1EndIndex - num1StartIndex;
		last2 = num2EndIndex - num2StartIndex;
		while (last1 + last2 > 2)
		{
			if (last1 && last2)
			{
				if (nums1[num1StartIndex] < nums2[num2StartIndex])
				{
					num1StartIndex++;
					last1--;
				}
				else
				{
					num2StartIndex++;
					last2--;
				}
			}
			else if (last1)
			{
				num1StartIndex++;
				last1--;
			}
			else
			{
				num2StartIndex++;
				last2--;
			}


			if (last1 && last2)
			{
				if (nums1[num1EndIndex - 1] > nums2[num2EndIndex - 1])
				{
					num1EndIndex--;
					last1--;
				}
				else
				{
					num2EndIndex--;
					last2--;
				}
			}
			else if (last1)
			{
				num1EndIndex--;
				last1--;
			}
			else
			{
				num2EndIndex--;
				last2--;
			}
		}

		if (last1 && last2)
		{
			return (nums1[num1StartIndex] + nums2[num2StartIndex]) / 2.0;
		}
		else if (last1 == 1 && last2 == 0)
		{
			return nums1[num1StartIndex];
		}
		else if (last1 == 2 && last2 == 0)
		{
			return (nums1[num1StartIndex] + nums1[num1StartIndex + 1]) / 2.0;
		}
		else if (last1 == 0 && last2 == 1)
		{
			return nums2[num2StartIndex];
		}
		else if (last1 == 0 && last2 == 2)
		{
			return (nums2[num2StartIndex] + nums2[num2StartIndex + 1]) / 2.0;
		}
	}
};


int main()
{
	vector<int> a = vector<int>();
	vector<int> b = vector<int>();
	Solution sol;

	b.push_back(2);
	b.push_back(3);

	while (true)
	{
		getchar();
		cout << sol.findMedianSortedArrays(a, b) << endl;
	}
	return 0;
}

