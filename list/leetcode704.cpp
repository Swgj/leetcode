#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i =0, j= nums.size()-1;
        int mid;
        while(i<j){
            mid = (i+j)>>1;
            if(nums[mid]>=target) j=mid;
            else i = mid+1;
        }
        if(nums[i]==target) return i;
        else return -1;
    }
};

int main(){
    vector<int> a = {-1,0,3,5,9,12};
    Solution s;
    int res = s.search(a,9);
    cout << res;
    return 0;
}
