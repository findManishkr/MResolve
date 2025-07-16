#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX

vector<int> get_digits( int n){
	   vector<int>d;
	    while( n > 0){

	    	 if( n % 10 != 0)
	    	   d.push_back(n %10);
	    	   	n /= 10;
	    }
    return d;
}

//   vector<int>memo(1e6+5,-1);
// int f( int n){
// 	   if( n == 0) return 0;
// 	   if( n <= 9) return 1;

//            if( memo[n] != -1) return memo[n];
//        vector<int>d = get_digits(n);
//         int res = inf;

//        for( int i = 0; i < d.size(); i++){
//        	 res =   min(res, f( n - d[i]) );
//        }

//           return memo[n] =  1 +  res;

//        }

 int bottumUp( int n){
         
             if( n == 0) return 0 ;
             if( n >= 1 && n <= 9) return 1;
         vector<int>tab(n+1,inf);
           tab[0] = 0;
          for(int i = 1; i<= 9;i++) tab[i] = 1;
             
                 
           
          	 for( int i = 10; i <= n;i++ ){

             	  vector<int>d = get_digits(i);
             	     
                    for( int j = 0; j < d.size(); j++)
                     tab[i] =   min( tab[i],  tab[i - d[j] ]);
                  
                  tab[i]  = 1 + tab[i];
             }

                 

       return tab[n]  ;
 }      
int main(){

int n;
cin >> n;

    
  cout << bottumUp(n) <<'\n';



	return 0;
}