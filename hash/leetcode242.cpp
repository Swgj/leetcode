# include<iostream>
# include<string>
# include<unordered_map>

using namespace std;

class Solution {
    public:
        bool isAnagram(string s,string t){
            if(s.length()!=t.length()) return false;
            unordered_map<char,int> umap;
            for(int i = 0;i<s.length();i++){
                if(umap.count(s[i])==0) umap.emplace(s[i],1);
                else if(umap.count(s[i])>0) umap[s[i]]++;
            }
            for(int j = 0;j<t.length();j++){
                if(umap.count(t[j])==0) return false;
                else if(umap.count(t[j])>0) {
                    if(umap[t[j]]==0) return false;
                    else umap[t[j]]--;
                }
            }
            return true;
        }
};

int main(){
    freopen("leetcode242.txt","r",stdin);
    string a="12345";
    for(int i = 0;i<a.length();i++) cout<< a[i]<<endl;
    return 0;
}
