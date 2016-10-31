#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()){
        	if (nums[i] == i+1 || nums[i] <= 0 || nums[i] > nums.size()) i++;
        	else if (nums[nums[i]-1] != nums[i]) swap(nums, i, nums[i]-1);
        	else i++;
        }
        i = 0;
        while (i < nums.size()){
        	if (nums[i] != i+1) 
        		return i+1;
        }
        return i+1;
    }

    void swap(vector<int>& nums, int i1, int i2){
    	int temp = nums[i1];
    	nums[i1] = nums[i2];
    	nums[i2] = temp;
    }
};

int main() {
    Solution s;
	vector<int> a1={1,2,0}, a2={3,4,-1,1};
	cout << s.firstMissingPositive(a1) << endl;
	cout << s.firstMissingPositive(a2) << endl;
	system("pause");
	return 0;
}