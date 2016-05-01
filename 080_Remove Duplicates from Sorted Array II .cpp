class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int flag = 0;
        int temp = nums[0];
        auto it = nums.begin()+1;
        while(it!=nums.end())
        {
            if(*it == temp)
            {
                if(flag==0)
                {
                    flag=1;
                    ++it;
                }
                else if(flag==1)
                {
                    it = nums.erase(it);
                }
            }
            else
            {
                flag = 0;
                temp = *it;
                ++it;        
            }
        }
        
        return nums.size();
    }
};