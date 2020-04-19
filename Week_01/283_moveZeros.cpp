//	200419 pimg
//	283、移动零：数组中的0移到末尾，并保持非零元素的原始顺序
//	锁定数组下标


class Solution {
public:
	void moveZeros(vector<int>& nums) {
		int index = 0;
		for(int i = 0; i < nums.size(); ++i) {
			if(nums[i] != 0) {
				nums[index] = nums[i];
				if(index != i) {
					nums[i] = 0;
				}
				index++;
			}
		}
	}
}