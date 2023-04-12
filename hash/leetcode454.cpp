# include<iostream>
# include<vector>
# include<unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        /**
         * 拆分成1，2和3，4两部分
         * 分别用两个map记录两个数组不同组合的和
         * 时间复杂度降低为O(n^2)
         */
        //1和2
        unordered_map<int,int> umap1;
        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                int sum = nums1[i]+nums2[j];
                if(umap1.count(sum)!=0) umap1[sum]++;
                else umap1.emplace(sum,1);
            }
        }
        //2和3
        int count = 0;
        for(int i = 0;i<nums3.size();i++){
            for(int j = 0;j<nums4.size();j++){
                int sum = 0-nums3[i]-nums4[j];
                if(umap1.count(sum)!=0) count+=umap1[sum];
            }
        }
        return count;
    }
};