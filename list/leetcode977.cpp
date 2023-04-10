#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //难点在于O(n)的复杂度--双指针
        vector<int> res(nums.size(),0);
        int left = 0, right = nums.size()-1,count = nums.size()-1;
        while(count>=0){
            int left2 = nums[left]*nums[left];
            int right2 = nums[right]*nums[right];
            if(left2>right2) {
                res[count] = left2;
                left++;
            }
            else {
                res[count] = right2;
                right--;
            }
            count--;
        }
        return res;
    }
};

int main(){
    freopen("t977.txt","r",stdin);
    string line;
    getline(cin,line);
    stringstream ss(line);
    string str;
    vector<int> arr;
    while (getline(ss,str,','))
    {
        arr.push_back(stoi(str));
    }
    Solution so;
    vector<int> res = so.sortedSquares(arr);
    for(int i = 0;i<res.size();i++) cout<< res[i]<<" ";
    return 0;
}