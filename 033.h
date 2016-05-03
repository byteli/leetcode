
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.size()==0) return -1;
		int left = 0,right = nums.size();

		while(left!=right)
		{
			const int mid =(left+right)/2;
			if(nums[mid]==target) return mid;
			if(nums[mid] >= nums[left])//�м�����������
			{
				if(nums[left] <= target && target<nums[mid])
					right = mid;
				else
					left = mid +1;
			}
			else//�м���С������
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