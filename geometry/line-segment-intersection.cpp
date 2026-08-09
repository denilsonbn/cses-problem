#include <bits/stdc++.h>
 
#define P complex<long long>
#define X real()
#define Y imag()
 
using namespace std;
 
long long dot(P u, P v) {
    return (u.X * v.Y) - (v.X * u.Y);
}

bool segment(P a, P b, P c) {
    return c.X >= min(a.X, b.X) && c.X <= max(a.X, b.X) &&
           c.Y >= min(a.Y, b.Y) && c.Y <= max(a.Y, b.Y);
}
 
void solve() {
 
    vector<P> p;
 
    for (int i = 0; i < 4; i++) {
        long long a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
 
    if (p[0] == p[2] || p[0] == p[3] || p[1] == p[2] || p[1] == p[3]) {
        cout << "YES\n";
        return;
    }

    P a = p[0], b = p[1], c = p[2], d = p[3];
 
    if ((dot(c - a, c - b) == 0 && segment(a, b, c)) || (dot(d - a, d - b) == 0 && segment(a, b, d)) || 
        (dot(a - c, a - d) == 0 && segment(c, d, a)) || (dot(b - c, b - d) == 0 && segment(c, d, b))) {
        cout << "YES\n";
        return;
    }
 
    if ( (dot(c - a, c - b) < 0 && dot(d - a, d - b) > 0) || 
         (dot(c - a, c - b) > 0 && dot(d - a, d - b) < 0)) {
            if ((dot(a - c, a - d) < 0 && dot(b - c, b - d) > 0) || 
                (dot(a - c, a - d) > 0 && dot(b - c, b - d) < 0)) {
                    cout << "YES\n";
                    return;
                }
         }
    
    cout << "NO\n";
    
}
 
int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
 
    while(t--) {
        solve();
 
    }
    
    
    return 0;
}