// huaweiexample.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//**************************************************************************
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//
//
//int main()
//{
//	string str;
//	int n;
//	map<int, int> counter;
//	vector<int> kinds;
//
//	while (1)
//	{
//		getline(cin, str);
//		str += ' ';
//		n = str.length();
//		kinds.clear();
//		counter.clear();
//
//		int one = -1;
//		bool startFlag = false;
//		for (int index = 0; index < n; index++)
//		{
//			if (str[index] == ' ')
//			{
//				if (startFlag)
//				{
//					if (one != -1)
//					{
//						vector<int>::iterator findRes = find(kinds.begin(), kinds.end(), one);
//						if (findRes == kinds.end())
//						{
//							kinds.push_back(one);
//							counter[one] = 1;
//						}
//						else
//						{
//							counter[one]++;
//						}
//					}
//				}
//				one = -1;
//				continue;
//			}
//			else
//			{
//				startFlag = true;
//				if (one == -1)
//				{
//					one = str[index] - '0';
//				}
//				else
//				{
//					one = one * 10 + str[index] - '0';
//				}
//			}
//		}
//
//		sort(kinds.begin(), kinds.end(), less<int>());
//
//		bool fristFlag = true;
//		for (vector<int>::iterator iter = kinds.begin(); iter != kinds.end(); iter++)
//		{
//			if (fristFlag)
//			{
//				cout << *iter << " " << counter[*iter];
//				fristFlag = false;
//			}
//			else
//			{
//				cout << " " << *iter << " " << counter[*iter];
//			}
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

//**************************************************************************
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//
//int main()
//{
//	string path1, path2;
//	vector<char> pathv1, pathv2;
//	int len1, len2;
//
//	while (1)
//	{
//		getline(cin, path1);
//		getline(cin, path2);
//
//		len1 = path1.length();
//		for (int index = 0; index < len1; index++)
//		{
//			if (path1[index] != '-')
//			{
//				pathv1.push_back(path1[index]);
//			}
//		}
//		len2 = path2.length();
//		for (int index = 0; index < len2; index++)
//		{
//			if (path2[index] != '-')
//			{
//				pathv2.push_back(path2[index]);
//			}
//		}
//
//		len1 = pathv1.size();
//		len2 = pathv2.size();
//		char same;
//		int i, j;
//		for (i = 0; i < len1; i++)
//		{
//			for (j = 0; j < len2; j++)
//			{
//				if (pathv1[i] == pathv2[j])
//				{
//					same = pathv1[i];
//					goto end;
//				}
//			}
//		}
//end:
//		cout << same << " " << (((len1 - i) > (len2 - j)) ? (len1 - i - 1) : (len2 - j - 1)) << endl;
//	}
//
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//
//int main()
//{
//	string path1, path2;
//	vector<string> pathv1, pathv2;
//	int len1, len2;
//	string temp;
//
//	while (1)
//	{
//		getline(cin, path1);
//		getline(cin, path2);
//		path1 += "-";
//		path2 += "-";
//
//		len1 = path1.length();
//		for (int index = 0; index < len1; index++)
//		{
//			//if (path1[index] != '-')
//			//{
//			//	pathv1.push_back(path1[index]);
//			//}
//
//			if (path1[index] == '-')
//			{
//				if (temp != "")
//				{
//					pathv1.push_back(temp);
//				}
//				temp = "";
//			}
//			else
//			{
//				temp += path1[index];
//			}
//		}
//		len2 = path2.length();
//		for (int index = 0; index < len2; index++)
//		{
//			if (path2[index] == '-')
//			{
//				if (temp != "")
//				{
//					pathv2.push_back(temp);
//				}
//				temp = "";
//			}
//			else
//			{
//				temp += path2[index];
//			}
//		}
//
//		len1 = pathv1.size();
//		len2 = pathv2.size();
//		string same;
//		int i, j;
//		bool noFlag = false;
//		for (i = 0; i < len1; i++)
//		{
//			for (j = 0; j < len2; j++)
//			{
//				if (pathv1[i] == pathv2[j])
//				{
//					same = pathv1[i];
//					goto end;
//				}
//			}
//		}
//		noFlag = true;
//	end:
//		if (noFlag)
//		{
//			cout << "0 0" << endl;
//		}
//		else
//		{
//			cout << same << " " << (((len1 - i) > (len2 - j)) ? (len1 - i - 1) : (len2 - j - 1)) << endl;
//		}
//	}
//
//
//	return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;


int main()
{
	string source, target, trans;
	char chtarget, chtrans;;
	vector<int> local;
	int n;

	while (1)
	{
		cin >> source >> target >> trans;

		chtarget = target[0];
		chtrans = trans[0];

		n = source.length();

		for (int index = 0; index < n; index++)
		{
			if (source[index] == chtarget)
			{
				local.push_back(index);
			}
		}

		int changeNum = pow(2, local.size());
		int changeBit = local.size();
		string temp;
		bool fristFlage = true;
		for (int index = 0; index < changeNum; index++)
		{
			for (int i = 0; i < changeBit; i++)
			{
				temp = source;
				if (index & (1 << i))
				{
					temp = temp.substr(0, i) + chtrans + temp.substr(i + 1, temp.length());
					if (fristFlage)
					{
						cout << temp;
						fristFlage = false;
					}
					else
					{
						cout << "," << temp;
					}
				}
			}
		}
		cout << endl;

	}

	return 0;
}









