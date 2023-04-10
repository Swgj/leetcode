#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //找极大联通子图数量--并查集
        vector<int>tree (isConnected.size(),-1);

        for(int i = 0;i<isConnected.size();i++){
            for(int j = i+1;j<isConnected.size();j++){
                if(isConnected[i][j]==1) {
                    int* ptr1 = &tree[j];
                    while(*ptr1!=-1) ptr1 = &tree[*ptr1];
                    int* ptr2 = &tree[i];
                    while(*ptr2!=-1) ptr2 = &tree[*ptr2];

                    if(ptr1!=ptr2) *ptr1 = i;
                }
            }
        }

        int count = 0;
        for(int i = 0;i<tree.size();i++) {
            if(tree[i]==-1) count++;
        }
        return count;
    }
};

int main(){
    freopen("leetcode547.txt","r",stdin);
    string line;
    vector<vector<int>> isConnected;
    while (getline(cin,line))
    {
        stringstream ss(line);
        string str;
        vector<int> vec;
        while(getline(ss,str,',')){
            vec.push_back(stoi(str));
        }
        isConnected.push_back(vec);
    }
    
    Solution so;
    int res = so.findCircleNum(isConnected);
    cout << res;
    return 0;
}