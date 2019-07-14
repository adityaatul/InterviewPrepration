class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,max_sum=-INT_MAX,current=0;
        int sz = nums.size();
          for(int i=0;i<sz;++i ){
                sum+=nums[i];
                if(sum>max_sum)
                    max_sum=sum;
                if(sum<0)
                    sum=0;
            }
        return max_sum;
    }
};
