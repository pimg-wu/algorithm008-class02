//200419 pimg
//26、删除排序数组中的重复项：使每个元素只出现一次，返回删除后的新长度
//有序、可用变量为数组下标

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size() < 2) return nums.size();
		int index = 0;
		for(int i = 1; i < nums.size(); ++i) {
			if(nums[index] != nums[i]) {
				index++;
				nums[index] = nums[i];
			}
		}
		return ++index;
	}
}