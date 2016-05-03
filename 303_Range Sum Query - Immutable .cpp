class NumArray {
public:
    vector<int> preTre;
    NumArray(vector<int> &nums) {
        if(nums.size()==0) 
        {
            preTre.push_back(0);
            return;
        }
		//���аѵ�0Ԫ��push��ȥ
        int sum = nums[0];
        preTre.push_back(sum);
        for(int i = 1;i!=nums.size();i++)
        {
            sum+=nums[i];
            preTre.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
	//�ֿ��ж�
        if(i==0) 
            return preTre[j];
        else 
            return preTre[j] - preTre[i-1]; 
    }
};
