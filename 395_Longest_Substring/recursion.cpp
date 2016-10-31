#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) 
	{
		map<char, int> count;
		for (string::iterator it = s.begin(); it != s.end(); ++it)
		{
			if (count.find(*it) != count.end())
				count[*it]++;
			else
				count[*it] = 1;
		}
		for (map<char, int>::iterator it = count.begin(); it != count.end(); ++it)
		{
			if (it->second < k)
			{
				vector<string> x = split(s, it->first);
				int max_num = -1;
				for (vector<string>::iterator it = x.begin(); it != x.end(); ++it)
				{
					max_num = max(max_num, longestSubstring(*it, k));
				}
				return max_num;
			}
		}

		return s.size();
	}

	// String Split Function from Evan Teran. http://stackoverflow.com/questions/236129/split-a-string-in-c
	void split(const string &s, char delim, vector<string> &elems)
	{
		stringstream ss;
		ss.str(s);
		string item;
		while (getline(ss, item, delim))
		{
			elems.push_back(item);
		}
	}

	vector<string> split(const string &s, char delim)
	{
		vector<string> elems;
		split(s, delim, elems);
		return elems;
	}
};

int main()
{
	Solution s;
	cout << s.longestSubstring("aaabb", 3) << endl;
	cout << s.longestSubstring("ababbc", 2) << endl;
	system("pause");
	return 0;
}