class Solution {
public:
    bool check(string s,int i,int j  ){
       
       while(i<=j){
          if(s[i++]!=s[j--]){
            return false;
          }
       }
       return true;
    }
    void f(vector<vector<string>>&ans,vector<string>&temp,int n,int ind,string s){
       if(ind==n){
         ans.push_back(temp);
        return;
       }
       for(int i = ind;i<n;i++){
        if(check(s,ind,i)){
        temp.push_back(s.substr(ind,i-ind+1));
        f(ans,temp,n,i+1,s);
        temp.pop_back();
       }
    }}
    vector<vector<string>> partition(string s) {
      vector<vector<string>>ans;
      vector<string>temp;   
       int n = s.size();
       f(ans,temp,n,0,s);
       return ans;
    }
    
    
};
