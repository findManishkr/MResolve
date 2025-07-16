

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
vector < string > ans;
void f( int i, int j, string &s, string &t,string &str){
          
     if( i >= s.size() || j >= t.size() ) {
          ans.push_back(str);
         return ;  }
         
       if(s[i] == s[j]){
            str.push_back(s[i]);
           f(i+1,j+1,s,t,str);
           str.pop_back();
       }else{
           f( i+1,j,s,t,str);
           f(i,j+1,s,t,str);
       }
      
}


int main() {  SETUP_IO;
string s, t;
cin >> s >> t;
       string str = "";
    f(0,0,s,t,str);
  for(auto &str: ans)
      cout << str <<'\n';
    return 0;
}
