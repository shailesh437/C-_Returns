bool cmp(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second > b.second;
}
string sort1(map<string,int> &m){
    vector<pair<string,int>> V;
    for (auto& it : m) {
        V.push_back(it);
    }    
    sort(V.begin(), V.end(), cmp);
    int cnt=0;
    for (auto& it : V) {
      if(cnt==1){
          return it.first;
      }
      cnt++;
    }
    return "";
}
string secFrequent (string arr[], int n)
{
    //code here.
    map<string,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    return sort1(m);
}
