#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define INF 1000  


#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

int f(string &s, string &t, int i, int j) {
    if (i >= s.size()) return INF;  
    if (j >= t.size()) return 1;    

   
    int k;
    for (k = j; k < t.size(); k++) {
        if (t[k] == s[i]) break;
    }

    if (k == t.size()) return 1;  

    return min(1 + f(s, t, i + 1, k + 1), f(s, t, i + 1, j));
}

int main() { SETUP_IO
    string s, t;
    cin >> s >> t;

    int result = f(s, t, 0, 0);
    if (result >= INF) result = -1;  

    cout << result << '\n';
    return 0;
}
