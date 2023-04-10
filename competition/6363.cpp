#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> record(nums.size(),0);//记录是否已使用
        int count = nums.size();//还剩多少数

        vector<vector<int>> res;
        while(count!=0){
            map<int,int> diction;
            vector<int> line(0);
            for(int i = 0;i<nums.size();i++){
                if(record[i]==0&&diction.count(nums[i])==0){
                    diction[nums[i]]=1;
                    record[i]=1;
                    line.push_back(nums[i]);
                    count --;
                }
            }
            res.push_back(line);
        }

        return res;
    }
};

int main(){
    vector<int> nums={1,3,4,1,2,3,1};
    Solution so;
    vector<vector<int>> res = so.findMatrix(nums);
    for(int i = 0;i<res.size();i++){
        for(int j = 0;j<res[i].size();j++){
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }

    return 0;
}