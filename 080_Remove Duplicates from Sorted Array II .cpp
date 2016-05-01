class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int index = 0;
        int occur = 1;
        for(int i = 1;i!=nums.size();i++)
        {
            if(nums[index]!=nums[i])
            {
                occur = 1;
                nums[++index] = nums[i];
            }
            else //相等情况
            {
                if(occur<2)
                {
                    nums[++index] = nums[i];
                    ++occur;
                }
            }
        }
        return index+1;
    }
};
/* class Solution {
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
}; */