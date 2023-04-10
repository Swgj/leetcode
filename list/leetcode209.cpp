#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;//窗口起始位置
        int sum = 0;
        int res = INT32_MAX;
        for(int j = 0;j<nums.size();j++){
            sum += nums[j];
            while(sum>=target){
                res = min(res,j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        if(res==INT32_MAX)return 0;
        else return res;
    }
};

int main(){
    freopen("t209.txt","r",stdin);
    int target;
    cin >> target;
    cin.ignore();

    string line;
    getline(cin,line);
    stringstream ss(line);
    string str;
    vector<int> arr;
    while(getline(ss,str,',')){
        arr.push_back(stoi(str));
    }
    
    Solution so;
    int res = so.minSubArrayLen(target,arr);
    cout << res;
    return 0;
}