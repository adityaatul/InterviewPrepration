/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

/*
MY APPROACH 
very simple approch to the problem is to keep adding element to the SUM variable and checking it with MAX_SUM , and when it get 
negative we can reintialise it to 0 and start afresh from that point of iteration !
*/

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
