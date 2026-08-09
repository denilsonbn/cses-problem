#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
ll dot(pair<ll, ll> u, pair<ll, ll> v) {
    return (u.first * v.second) - (v.first * u.second);
}
 
void solve() {
    pair<ll, ll> p1, p2, p3;
    
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
    
    pair<ll, ll> u = {p3.first - p1.first, p3.second - p1.second};
    pair<ll, ll> v = {p3.first - p2.first, p3.second - p2.second};
    
    ll ans = dot(u, v);
    if (ans > 0) cout << "LEFT\n";
    else if (ans < 0) cout << "RIGHT\n";
    else cout << "TOUCH\n";
    
}
 
int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
 
    return 0;
}