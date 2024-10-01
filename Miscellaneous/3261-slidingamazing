/*
We cant simply take prefix[high]-prefix[low]
coz it will give substrings that end between low and high but the substring should also start in this range thats why it will give wrong answer.
It will be add those substrings as well that started before the given low and hence give the wrong answer.

On this Our solution will be based on , first from given low index we find the max valid index till which we get substrings , and now from this validind we apply prefix[high] - prefix[validind];
This works because we have calculated that on a given index low , till where the valid window/substring exists , lets call it validind, now remaining part is calculated using prefix[high]-prefix[low] ,
the first part will always be from low , but in this prefix part we count those substring that end in range validind to high , now u will be wondering why this 
doesnt count those substrings that start before low , thats because we made sure every window that starts from low or before low will end at validind and in this prefix part we calculated from validind. 
So in this part we may get substrings that start before validind but it will never start before low and also these 2 parts count separate substrings.
Adding both of these we get our answer.
*/



class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int left=0,right=0,n=s.size();
        int ones=0;
        int zeros=0;
        vector<int> leftmost(n,0),rightmost(n,0);
        while(right<n)
        {
            if(s[right]=='0') zeros++;
            else ones++;
            while(ones>k && zeros>k)
            {
                if(s[left]=='0') zeros--;
                else ones--;
                left++;
            }
            leftmost[right]=left;
            right++;
        }
        ones=0,zeros=0;
        left=n-1,right=n-1;
        while(right>=0)
        {
            if(s[right]=='0') zeros++;
            else ones++;
            while(ones>k && zeros>k)
            {
                if(s[left]=='0') zeros--;
                else ones--;
                left--;
            }
            rightmost[right]=left;
            right--;
        }
        
        vector<long long> prefix(n,0);
        long long cnt=0;
        for(int j=0;j<n;j++)
        {
            cnt+=j-leftmost[j]+1;
            prefix[j]=cnt;
        }
        vector<long long> result;
        for(int i=0;i<queries.size();i++)
        {
            int low=queries[i][0];
            int high=queries[i][1];

            int validlow=min(rightmost[low],high);
            long long total=1LL*(validlow-low+1)*(validlow-low+2)/2;
            total+=prefix[high]-prefix[validlow];
            result.push_back(total);
        }


        return result;
        
    }
};
