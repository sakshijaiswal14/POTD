class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        bool dp[len][len]; //whether the substring between start and end is palindromic
        
        if(s.length()==1)
            return s; //Base case if length of string =1
        
        int start = 0; int long_len = 1;
        
        for(int i=0; i<s.length(); i++)
            dp[i][i] = 1;
        
        for(int i = len-1; i>=0; i--)
        {
            for(int dist = 1; dist<len-i; dist++)
            {
                int j = dist + i;
                dp[i][j]= (dist==1)? s[i]==s[j] : (s[i]==s[j] && dp[i+1][j-1]);
                if(dp[i][j] && j-i+1 >long_len)
                {    
                    long_len = j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start, long_len);
    }
};