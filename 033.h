
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.size()==0) return -1;
		int left = 0,right = nums.size();

		while(left!=right)
		{
			const int mid =(left+right)/2;
			if(nums[mid]==target) return mid;
			if(nums[mid] >= nums[left])//中间数大于左数
			{
				if(nums[left] <= target && target<nums[mid])
					right = mid;
				else
					left = mid +1;
			}
			else//中间数小于左数
			{
				if(nums[mid]<target && target <=nums[right-1])
					left = mid +1;
				else
					right = mid;
			}
		}

		return -1;
	}
};