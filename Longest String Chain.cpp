class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        unordered_map<string,int>mp;
        int maxlength=1;
        for(const string &word : words){
            int length=1;
            for(int i=0;i<word.size();i++){
                string pred=word.substr(0,i) + word.substr(i+1);
                if(mp.find(pred)!=mp.end())
                length=max(length,mp[pred]+1);
            }
            mp[word]=length;
            maxlength=max(maxlength,length);
        }
        return maxlength;
        
    }
};
