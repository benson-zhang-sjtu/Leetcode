#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> PII;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<PII> extn;
        vector<int> count;
        for (int i = 0; i<n; i++) {
            extn.push_back(make_pair(i, nums[i]));
            count.push_back(0);
        }

        mergeSort(extn, count, 0, n - 1);
        for (int i = 0; i<n; i++)
            cout << count[i] << endl;
        return count;
    }

    void mergeSort(vector<PII>& nums, vector<int>& count, int l, int r) {
        if (l < r) {
            int mid = (l + r) >> 1;
            mergeSort(nums, count, l, mid);
            mergeSort(nums, count, mid + 1, r);
            merge(nums, count, l, mid, r);
        }
    }

    void merge(vector<PII>& nums, vector<int>& count, int l, int mid, int r) {
        int i = l, j = mid + 1;
        vector<PII> c;
        while (i <= mid && j <= r) {
            if (nums[i].second > nums[j].second) {
                c.push_back(nums[i]);
                count[nums[i++].first] += r - j + 1;
            }
            else
                c.push_back(nums[j++]);
        }
        while (i <= mid)
            c.push_back(nums[i++]);
        while (j <= r)
            c.push_back(nums[j++]);
        for (int i = l; i <= r; i++)
            nums[i] = c[i - l];
    }
};

int main() {
    Solution s;
    vector<int> a1 = { 5, 2, 6, 1 }, a2 = { 3,4,-1,1 }, b1, b2;
    b1 = s.countSmaller(a1);
    system("pause");
    return 0;
}