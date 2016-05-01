class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size()==0)
			return 0;
		int index = 0;
		for(int i = 1;i!=nums.size();i++)
		{
			if(nums[index]!=nums[i])
				nums[++index] = nums[i];
		}

		return index+1;
	}
};
/* class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int temp = nums[0];
		auto it = nums.begin()+1;
		while(it!=nums.end())
		{
			if(*it==temp)
				it = nums.erase(it);
			else
			{
				temp = *it;
				it++;
			}
			if(it==nums.end())
				return nums.size();
		}

		return nums.size();

	}
}; */