class Solution {
public:


    void dfs(vector<vector<string>> &ans,vector<string> temp,unordered_map<string,int> m,int steps,string word,string beginWord,int ms)
    {
        if(word==beginWord)
        {
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<ms;i++)
        {
            string original=word;
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(m.find(word)!=m.end() && m[word]==steps-1)
                {
                    temp.push_back(word);
                    dfs(ans,temp,m,steps-1,word,beginWord,ms);
                    temp.pop_back();
                }
            }
            word=original;
        }
    }




    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_map<string,int> mpp;
        queue<string> q;
        mpp[beginWord]=1;
        int m=beginWord.size();
        q.push(beginWord);
        st.erase(beginWord);
        while(!q.empty())
        {
            string check=q.front();
            int steps=mpp[check];
            q.pop();
            if(check==endWord) break;
            for(int i=0;i<m;i++)
            {
                string original=check;
                
                for(char ch='a';ch<='z';ch++)
                {
                    check[i]=ch;
                    if(st.count(check))
                    {
                        q.push(check);
                        st.erase(check);
                        mpp[check]=steps+1;
                    }
                }
                check=original;
            }
        }
        vector<vector<string>> ans;
        if(mpp.find(endWord)!=mpp.end()){
            int steps=mpp[endWord];
            vector<string> temp;
            temp.push_back(endWord);
            dfs(ans,temp,mpp,steps,endWord,beginWord,m);
        }
        
        return ans;
    }
};
