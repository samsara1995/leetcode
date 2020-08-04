class Solution {
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5

*/
public:
    int ans=0;
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        vector<int> aux(len, 0);
        merge_sort(nums, aux, 0, len-1);
        return ans;
    }

    void merge(vector<int>& nums, vector<int>& aux, int low, int mid, int high){
        int i = low;
        int j = mid + 1;
        int k = low;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                aux[k++] = nums[i++];
                ans += j - mid - 1;     //******
            }
            else{
                aux[k++] = nums[j++];
            }
        }
        while(i <= mid){
            aux[k++] = nums[i++];
            ans += j - mid - 1;  //******
        }
        while(j <= high){
            aux[k++] = nums[j++];
        }
        for(int p = low; p <= high; p++){
            nums[p] = aux[p];
        }
    }

    void merge_sort(vector<int>& nums, vector<int>& aux, int low, int high){
        if(low >= high) return;
        int mid = low + (high - low) / 2;
        int len = nums.size();
        merge_sort(nums, aux, low, mid);
        merge_sort(nums, aux, mid+1, high);
        merge(nums, aux, low, mid, high);
    }
};
