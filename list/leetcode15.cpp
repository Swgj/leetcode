//双指针
# include<iostream>
# include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        //排序
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0;i<nums.size()-2;i++){
            //与上一次数不同
            if(i>0 && nums[i]==nums[i-1]) continue;
            int third = nums.size()-1;
            for(int second = i +1; second < nums.size()-1;second++){
                //与上一次数不同
                if(second>i+1 && nums[second]==nums[second-1]) continue;
                while (second < third && nums[second]+nums[third]>(-nums[i]))
                {
                    third --;
                }
                if(second == third) break;
                else if(nums[second] + nums[third] == (-nums[i])) {
                    res.push_back({nums[i],nums[second],nums[third]});
                }
            }
        }
        return res;
    }
};
