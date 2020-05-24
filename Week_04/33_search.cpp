// 200524 pimg
//33、搜索旋转排序数组：搜索半升序数组的值，返回索引
//使用二分查找：由于半单调性，二分后的比较改为比较中值和左右边界的大小
//利用二分先判断出有序的一边，通过左右边界判断是否在这一有序区域

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = nums.size();
        if(count == 0)  return -1;
        int left = 0;
        int right = count - 1;
        while (left <= right) {
            int mid = left/2 + right - right/2;
            if(nums[mid] == target)
                return mid;
            else if (nums[left] <= nums[mid]) {                    //说明左边是有序的，右边可能是有序的
                if(nums[left] > target || nums[mid] < target) {    //左侧有序但是不在这个范围，就直接跳过
                    left = mid + 1;
                    continue;
                }
                else {                                //在左侧这个有序范围
                    right = mid - 1;
                    continue;
                }
            }
            else {                                                    //说明右边是有序的，左边可能是
                if(nums[mid] >target || nums[right] < target) {       //右侧有序，但是不在这个范围
                    right = mid - 1;
                    continue;
                }
                else {                               //在右侧这个有序范围
                    left = mid + 1;
                    continue;
                }
            }
        }
        return -1;
    }
};