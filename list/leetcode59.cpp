#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int row = 0,column = 0;
        //难点在于如何拐弯
        int val = 1;
        for(int i = n;i>=1;i-=2){
            if(i!=1){
                for(int j=0;j<4;j++){//四条边
                    for(int k = 1;k<=i-1;k++){//每条边走的格子数
                        mat[row][column]=val++;
                        if(j%4==0)column++;
                        else if(j%4==1)row++;
                        else if(j%4==2)column--;
                        else if(j%4==3&&k!=i-1)row--;//刨除最后一步
                        else column++;//最后一步
                    }
                }
            }
            else{
                mat[row][column]=val;
            }
        }
        return mat;
    }
};

int main(){
    freopen("leetcode59.txt","r",stdin);

    int n;
    cin >> n;

    vector<vector<int>> mat;
    Solution so;
    mat = so.generateMatrix(n);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) cout << mat[i][j]<<"\t";
        cout <<endl;
    }
    return 0;
}