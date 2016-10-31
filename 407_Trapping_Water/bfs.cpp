#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int num_of_row =  heightMap.size(), num_of_col = heightMap[1].size();
        for (int i=0; i<num_of_row; i++)
        	for (int j=0; j<num_of_col; j++)
        		cout<<heightMap[i][j]<<endl;

        return 0;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> p;
	p.push_back({1,4,3,1,3,2});
	p.push_back({3,2,1,3,2,4});
	p.push_back({2,3,3,2,3,1});

	vector<vector<int>> q{{1,4,3,1,3,2},
						  {3,2,1,3,2,4},
						  {2,3,3,2,3,1}};

	cout << s.trapRainWater(p) << endl;
	cout << s.trapRainWater(q) << endl;
	system("pause");
	return 0;
}