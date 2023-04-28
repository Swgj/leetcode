#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldsize = s.size();

        for(int i = 0;i<s.size();i++){
            if(s[i]==' ') count ++;
        }
        s.resize(s.size()+count*2);
        
        int newsize = s.size();
        for(int i = s.size()-1, j = oldsize-1;i>=0;j--){
            if(s[j]==' '){
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i-=3;
            }else{
                s[i] = s[j];
                i -=1;
            }
        }
        return s;
    }
};

int main() {
    string s = "we are happy.";
    Solution so;
    cout << so.replaceSpace(s)<<endl;
    char a;
    cin >> a; 
    cout << a <<endl;
    return 0;
}