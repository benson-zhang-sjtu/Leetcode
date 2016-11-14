## 2016/11/6 ##
我的思路是类似于逆序对的求法，在归并排序中修改函数。

	while (i <= mid && j <= r) {
	if (nums[i].second > nums[j].second) {
	    c.push_back(nums[i]);
	    count[nums[i++].first] += r - j + 1;
	}
	else
	    c.push_back(nums[j++]);
	}
当num[i] > num[j]时，则表明有r-j+1个数小于num[i], 则添加至count中，代码时间复杂度是O(nlogn)

## Update ##
看了discuss之后，另一种方法是使用BST, 从后往前插入x, 判断x比当前bst中大的元素的个数，并将x插入正确位置上。
算法分析上，最坏情况是O(n^2), 最好情况是O(??) wait to be updated

另一种更简单的思路是，从后往前维护一个sorted_array, 对于每个x，利用二分搜索寻找x在sorted_array中位置。这里是算法[algorithm](https://discuss.leetcode.com/topic/31173/my-simple-ac-java-binary-search-code)
