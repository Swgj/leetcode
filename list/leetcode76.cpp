#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int left = 0, right = INT32_MAX;//分别指向当前窗口最佳位置
        int count = t.length();//统计t中尚未匹配的数量
        bool flag = false;//用于标识是否曾匹配成功过
        

        //将t转为hash map
        map<char,int> diction;
        for(int i = 0;i<t.length();i++){
            if(diction.count(t[i])==0) diction[t[i]]=1;
            else diction[t[i]]+=1;
        }

        //滑动窗口
        for(int j = 0;j<s.length();j++){
            if(diction.count(s[j])==0) continue;
            else{
                if(count>0){
                    diction[s[j]]-=1;
                    if(diction[s[j]]>=0) count--;
                }
            }

            while (count==0)
            {
                flag = true;
                if((right-left)>(j-i)) right=j,left=i;
                if(diction.count(s[i])==1){
                    if(++diction[s[i]]>0) count++;
                }
                i++;
            }
        }
        
        if(flag) return s.substr(left,right-left+1);
        else return "";
    }
};

int main()
{
    freopen("leetcode76.txt","r",stdin);
    string s,t;
    getline(cin,s);
    getline(cin,t);

    Solution so;
    string res = so.minWindow(s,t);
    cout << res;

    return 0;
}