#include <bits/stdc++.h>

using namespace std;

string s;

const int N = 1e5 + 5;

int rA[2 * N], rB[2 * N], G, sA[2 * N], n;

bool cmp(int x, int y) {
    if(rA[x] != rA[y]) return rA[x] < rA[y];
    return rA[x + G] < rA[y + G];
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> s;
    n = (int)( s.length() );
    s = "+" + s;
    for(int i = 1; i <= n; i++) {
        sA[i] = i;
        rA[i] = s[i];
    }
    for(G = 1; G <= n; G *= 2) {
        sort(sA + 1, sA + n + 1, cmp);
        for(int i = 1; i <= n; i++)
            rB[ sA[i] ] = rB[ sA[ i - 1 ] ] + cmp( sA[i - 1], sA[i] );
        for(int i = 1; i <= n; i++)
            rA[ sA[i] ] = rB[ sA[i] ];
        if( rA[ sA[n] ] == n )
            break;
    }
    for(int i = 1; i <= n; i++)
        cout << sA[i] - 1 << "\n";
}
