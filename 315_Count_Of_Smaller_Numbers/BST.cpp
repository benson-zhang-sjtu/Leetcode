#include<iostream>
#include<vector>
using namespace std;

struct node{
	int val, copy, leftCnt;
	node *left, *right;
	node(int x){val=x; copy=1; leftCnt=0;left=NULL; right=NULL;}
};

int insert(node* root, int x){
	if (root->val == x){
		root->copy++;
		return root->leftCnt;
	} else if (root->val > x){
		root->leftCnt++;
		if (root->left == NULL){
			root->left = new node(x);
			return 0;
		} else return insert(root->left, x);
	} else {
		if (root->right == NULL){
			root->right = new node(x);
			return root->leftCnt + root->copy;
		} else return root->leftCnt + root->copy + insert(root->right, x);
	}

}

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
	    int sz=nums.size();
	    vector<int> res(sz,0);
	    if (sz<=1) return res;
	    node *root = new node(nums[sz-1]);
	    for (int i=sz-2; i>=0; i--){
	    	res[i] = insert(root, nums[i]);
	    }
	    for (int i = 0; i<sz; i++)
            cout << res[i] << endl;
	    return res;
	}
};

int main() {
    Solution s;
    vector<int> a1 = { 5, 2, 6, 1 }, a2 = { 3,4,-1,1 }, b1, b2;
    b1 = s.countSmaller(a1);
    system("pause");
    return 0;
}