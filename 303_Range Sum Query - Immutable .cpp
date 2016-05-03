class NumArray {
public:
    vector<int> preTre;
    NumArray(vector<int> &nums) {
        if(nums.size()==0) 
        {
            preTre.push_back(0);
            return;
        }
		//先行把第0元素push进去
        int sum = nums[0];
        preTre.push_back(sum);
        for(int i = 1;i!=nums.size();i++)
        {
            sum+=nums[i];
            preTre.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
	//分开判断
        if(i==0) 
            return preTre[j];
        else 
            return preTre[j] - preTre[i-1]; 
    }
};
