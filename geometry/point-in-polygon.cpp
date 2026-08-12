#include <bits/stdc++.h>

#define ll long long
#define P complex<ll>
#define X real()
#define Y imag()
#define INF (ll) 1e9+10

using namespace std;

ll cross(P a, P b) {
    return (b * conj(a)).Y;
}

ll sig_point(P a, P b, P c) {
    ll result = cross(c - a, c - b);

    return (result > 0) - (result < 0);

}

bool segment(P a, P b, P c) {
    return c.X >= min(a.X, b.X) && c.X <= max(a.X, b.X) &&
           c.Y >= min(a.Y, b.Y) && c.Y <= max(a.Y, b.Y);
}

ll intersection(P a, P b, P c, P d) {

    ll cpa = sig_point(c, d, a);
    ll cpb = sig_point(c, d, b);
    ll cpc = sig_point(a, b, c);
    ll cpd = sig_point(a, b, d);

    if (cpa * cpb < 0 && cpc * cpd < 0) return 1;
    if (cpa == 0 && segment(c, d, a) && cpb < 0) return 1;
    if (cpb == 0 && segment(c, d, b) && cpa < 0) return 1;
 
    return 0;

}

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<P> polygon(n);

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        polygon[i] = {a, b};
    }

    polygon.push_back(polygon[0]);

    for (int i = 0; i < m; i++)  {
        ll a, b;
        cin >> a >> b;
        P point = {a, b}, ref = {INF, INF};

        bool bound = 0;
        ll cont = 0;

        for (int j = 0; j < n; j++) {
            if (!sig_point(polygon[j], polygon[j + 1], point) && segment(polygon[j], polygon[j+1], point)) {
                bound = 1;
                break;
            }

            cont += intersection(polygon[j], polygon[j + 1], point, ref);
        }

        if (bound) cout << "BOUNDARY\n";
        else cout << (cont & 1 ? "INSIDE\n" : "OUTSIDE\n");

    }


    return 0;
}