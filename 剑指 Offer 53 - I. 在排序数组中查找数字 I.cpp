class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        输入: nums = [5,7,7,8,8,10], target = 8  
        输出: 2
        统计一个数字在排序数组中出现的次数。
        思路：因为是排序数组，所以使用二分查找。
        */
        int left=0;
        int right=nums.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(target<=nums[mid])
            {
                right=mid-1;
            }
            else if(target>nums[mid])
            {
                left=mid+1;
            }
        }
        int count=0;
        cout<<left<<right<<endl;
        while(left<nums.size()&&nums[left++]==target)
        {
            count++;
        }
        return count;
    }
};
