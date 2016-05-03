
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if(nums.size()<3)
			return 0;
		vector<int> src(nums);
		std::sort(src.begin(),src.end());
		int left =0,right = src.size()-1,closest = INT_MAX/2,sum = 0;
		for(int i = 0;i<=src.size()-3;i++)
		{
			left = i +1;
			right = src.size()-1;
			while(left<right)
			{
				sum = src[i]+src[left]+src[right];
				if(sum == target)
					return sum;
				else if(sum>target)
					--right;
				else if(sum<target)
					++left;

				closest = abs(sum-target)<abs(closest-target)?sum:closest;
			}


		}
		return closest;
	}
};