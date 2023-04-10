#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //双指针
        int i = 0, j = 0;
        while(j<nums.size()){
            if(nums[j]==val){
                j++;
                continue;
            }
            nums[i] = nums[j];
            i++;
            j++;
        }
        return nums.size()-(j-i);
    }
};

int main(){
    vector<int> nums;
    int val;
    freopen("t27.txt","r",stdin);
    string line;
    cin >> val;
    cin.ignore();
    getline(cin,line);
    stringstream ss(line);
    string s;
    while (getline(ss,s,',')){
        nums.push_back(stoi(s));
    }
    Solution so;
    int size = so.removeElement(nums,val);
    for(int i = 0;i<size;i++){
        cout << nums[i]<< " ";
    }
    return 0;
}