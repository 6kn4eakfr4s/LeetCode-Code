/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
  vector<int> ufs;
  vector<double> weights;
public:
  int find(int x){
    if(ufs[x] < 0){
      return x;
    }
    int temp = ufs[x];
    ufs[x] = find(ufs[x]);
    weights[x] *= weights[temp];
    return ufs[x];
  }
  void uni(int a, int b, double val){//a / b = val
    int rootA = find(a);
    int rootB = find(b);
    cout<<"uni"<<endl;
    cout<<a<<" "<<b<<" "<<val<<endl;
    if(a == b){
      return;
    }
    if(abs(ufs[rootA]) < abs(ufs[rootB])){//merge a into b
      int temp = ufs[rootA];
      ufs[rootA] = rootB;
      weights[rootA] = val / weights[a] * weights[b];
      ufs[rootB] += temp;
      cout<<"A: "<<weights[rootA]<<endl;
    }
    else{
      int temp = ufs[rootB];
      ufs[rootB] = rootA;
      ufs[rootA] += temp;
      weights[rootB] = val / weights[b] * weights[a];
      cout<<"B: "<<weights[rootB]<<endl;
    }
    return;
  }
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unsigned int cnt = 1;
    unordered_map<string, int> mp;
    for(int i = 0; i < equations.size(); i ++){
      for(int j = 0; j < 2; j ++){
        if(mp.find(equations[i][j]) == mp.end()){
          mp.insert({equations[i][j], cnt++});
        }
      }
    }
    ufs = vector<int>(mp.size() + 1, -1);
    weights = vector<double>(mp.size() + 1, 1);
    for(int i = 0; i < equations.size(); i ++){
      uni(mp[equations[i][0]], mp[equations[i][1]], values[i]);
    }
    vector<double> ans(queries.size(), -1);
    for(int i = 0; i < mp.size() + 1; i ++){
      cout<<weights[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < queries.size(); i ++){
      if(mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end()){
        ans[i] = -1;
      }
      else if(find(mp[queries[i][0]]) != find(mp[queries[i][1]])){
        ans[i] = -1;
      }
      else{
        ans[i] = weights[mp[queries[i][0]]] / weights[mp[queries[i][1]]];
      }
    }
    return ans;
  }
}class Solution {
  vector<int> ufs;
  vector<double> weights;
public:
  int find(int x){
    if(ufs[x] < 0){
      return x;
    }
    int temp = ufs[x];
    ufs[x] = find(ufs[x]);
    weights[x] *= weights[temp];
    return ufs[x];
  }
  void uni(int a, int b, double val){//a / b = val
    int rootA = find(a);
    int rootB = find(b);
    cout<<"uni"<<endl;
    cout<<a<<" "<<b<<" "<<val<<endl;
    if(a == b){
      return;
    }
    if(abs(ufs[rootA]) < abs(ufs[rootB])){//merge a into b
      int temp = ufs[rootA];
      ufs[rootA] = rootB;
      weights[rootA] = val / weights[a] * weights[b];
      ufs[rootB] += temp;
      cout<<"A: "<<weights[rootA]<<endl;
    }
    else{
      int temp = ufs[rootB];
      ufs[rootB] = rootA;
      ufs[rootA] += temp;
      weights[rootB] = val / weights[b] * weights[a];
      cout<<"B: "<<weights[rootB]<<endl;
    }
    return;
  }
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unsigned int cnt = 1;
    unordered_map<string, int> mp;
    for(int i = 0; i < equations.size(); i ++){
      for(int j = 0; j < 2; j ++){
        if(mp.find(equations[i][j]) == mp.end()){
          mp.insert({equations[i][j], cnt++});
        }
      }
    }
    ufs = vector<int>(mp.size() + 1, -1);
    weights = vector<double>(mp.size() + 1, 1);
    for(int i = 0; i < equations.size(); i ++){
      uni(mp[equations[i][0]], mp[equations[i][1]], values[i]);
    }
    vector<double> ans(queries.size(), -1);
    for(int i = 0; i < mp.size() + 1; i ++){
      cout<<weights[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < queries.size(); i ++){
      if(mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end()){
        ans[i] = -1;
      }
      else if(find(mp[queries[i][0]]) != find(mp[queries[i][1]])){
        ans[i] = -1;
      }
      else{
        ans[i] = weights[mp[queries[i][0]]] / weights[mp[queries[i][1]]];
      }
    }
    return ans;
  }
};
// @lc code=end

