/*
  https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

    processed queries , then taken prefix sum
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 1e18

#define S second
#define F first
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}

int main(){ setupIO();
   int N;
   cin >> N;
    int M;
    cin >> M;

    vector<int>box(N+10,0);
    
    while( M--){
        int L, R;
        cin >> L >> R;
            box[L] += 1;
            box[R+1] += -1;
    }
       
    // now taking prefix sum
       for( int i = 1; i <= N;i++)
         box[i] = box[i] + box[i-1];
       
           vector<int>c(1000005,0);          // stores of (i)th coin how many boxes are there(c[i]);
           for( int i = 0; i <= N; i++){
                    // in i th box how many coins are there
                    int coin = box[i];       
                     c[ coin]++;
           }

           // now taking suffix of c array
           for ( int i = c.size()-2; i >= 0; i--){
                  c[i] = c[i] + c[i+1];
           }         // now c[i] represents at no of boxes that has atleast i coins

            // now process each query in o(1) time
    int Q;
    cin >> Q;
     while(Q--){

             int X;
             cin >> X;

             cout << c[X] << endl;
     }
    return 0;
}