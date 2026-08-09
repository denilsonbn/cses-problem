#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define ll long long
#define pii pair<ll, ll>
#define X first
#define Y second

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pii> point(n);

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        point[i] = {a, b};
    }

    point.push_back(point[0]);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += point[i].X * point[i + 1].Y;
        ans -= point[i].Y * point[i + 1].X;
    }

    cout << abs(ans) << "\n";

}