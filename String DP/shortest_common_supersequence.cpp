class Solution {
    public:
        int dp[1005][1005];
        int M , N;
        int f( int i , int j, string &s, string &t){
              if( i >= M || i >= N) return 0;
    
                if( dp[i][j] != -1)  return dp[i][j];
    
          return dp[i][j] =    ( s[i] == s[j] )+ max({ f(i+1,j,s,t),f(i,j+1,s,t), f(i+1,j+1,s,t) });
        }
        string shortestCommonSupersequence(string str1, string str2) {
               M = str1.size();
               N = str2.size();
               memset(dp,-1,sizeof(dp));
               // construct the lcs from dp table
                 string lcs = "";
                 int i = M -1, j  = N -1;
    
                while( i>= 0 || j >= 0){
                     if( str1[i] == str2[j]){
                          i--;
                          j--;
                          lcs += str1[i];
                     }else if(dp[i-1][j] >= dp[i][j-1] ){
                        i--;
                     }else{
                        j--;
                     }
    
                }
                    
                cout << lcs ;
                return "";
        }
    };