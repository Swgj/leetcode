#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k){
        // if(s.size()<2*k) return s;
        for(int i = 0;i<s.size()/(2*k);i++){
            int j = i*2*k;
            int m = j+k-1;
            while(j<=m){
                char tmp = s[j];
                s[j]=s[m];
                s[m]=tmp;
                j++;
                m--;
            }
        }
        //剩下的字符
        int i = s.size()-s.size()%(2*k);
        int j = s.size()-1;
        if (s.size()%(2*k)>k)
        {
            //反转前k个字符
            j = i+k-1;
        }
        while (i<j)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        
        return s;
    }
};

int main(){
    string s = "abcd";
    int k = 3;
    Solution so;

    string res = so.reverseStr(s,k);
    cout<< res;
    return 0;
}