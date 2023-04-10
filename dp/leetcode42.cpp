#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        
        //从左往右遍历1次，从右往左遍历1次，二者的重合部分就是可疑装的数量
        int leftMax = 0;
        for(int i = 0;i<height.size();i++){
            left[i] = max(leftMax-height[i],0);
            if(height[i]>leftMax) leftMax = height[i];
        }
        int rightMax = 0;
        for(int i =height.size()-1;i>=0;i--){
            right[i] = max(rightMax-height[i],0);
            if(height[i]>rightMax) rightMax = height[i];
        }

        //更新最终结果
        int res = 0;
        for(int i = 0;i<height.size();i++){
            left[i] = min(left[i],right[i]);
            res += left[i];
        }
        return res;
    }
};

int main(){
    freopen("leetcode42.txt","r",stdin);
    string line;
    getline(cin,line);
    stringstream ss(line);

    string str;
    vector<int> height;
    while(getline(ss,str,',')){
        height.push_back(stoi(str));
    }

    Solution so;
    int res = so.trap(height);
    cout << res;
    return 0;
}