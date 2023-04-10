# include<iostream>

using namespace std;

class Solution {
public:
    int add(int a,int b){
        return a+b;
    }
};

int main()
{
    cout << "hello" <<endl;
    int a = 1,b = 2;
    Solution s;
    cout << s.add(a,b);
    return 0;
}