/*
lc_386
https://leetcode.com/problems/lexicographical-numbers/description/
*/





#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

class Solution {
    public:
        vector<int> result;
        void f(int i, int n) {
            if (i > n)
                return;
    
            if (i != 0)
                result.push_back(i);
    
            for (int j = (i == 0) ? 1 : 0; j <= 9; j++)
                f(10 * i + j, n);
        }
        vector<int> lexicalOrder(int n) {
            result.clear();
            f(0, n);
            return result;
        }
    };
         


int main(){     SETUP_IO;
   int n;
   cin >> n;

      f(0,13);
    return 0;
}