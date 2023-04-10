#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int balance = 0;
        int len=0;
        int tmplen=0;
        char flag = '0';
        for(int i = 0;i<s.length();i++){
            if(s[i]=='0') {
                if(flag=='0') balance++;
                else {
                    tmplen = 0;
                    balance =1;//重新开始计数
                }
                flag='0';
            }
            else if(s[i]=='1'){
                if(balance>0){
                    tmplen ++;
                    balance--;
                    len = max(len,tmplen);
                    flag = s[i];
                }
            }
        }
        return len*2;
    }
};

int main(){
    Solution so;
    string s = "00111";
    int res = so.findTheLongestBalancedSubstring(s);
    cout << res;
    return 0;
}