#include <bits/stdc++.h>
using namespace std;


 int f( int idx , vector<int>&cost ){
          int n = cost.size();
          int minCost = 0;
           bool chek = false;
               
             int i = idx ;
              minCost += cost[idx];

              while( i < n - 1){
                  if( cost[i+1] >= cost[i+2]){
                       minCost += cost[i+2];
                        i += 2;
                  }else{
                      minCost += cost[i+i];
                       i++;
                  }
              }  
              return minCost;
    }
    int main(){
         vector<int>cost;
           for(int el : cost)
             cin >> el;

           cout <<f(0,cost);

         cout << "manish";


      return 0;
    }