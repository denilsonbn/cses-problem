#include <bits/stdc++.h>

#define ll long long
#define  P complex<ll>
#define X real()
#define Y imag()

using namespace std;

vector<P> hull;

ll cross(P a, P b) {
    return (conj(b) * a).Y;
}

ll sig_point(P a, P b, P c) {
    ll res = cross(b - c, a - c);

    return (res > 0) - (res < 0);
}

P plast(vector<P>& vetor) {
    int n = vetor.size();

    return vetor[n - 2];
}

bool comp(P& a, P& b) {
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}

void convex_hull(vector<P>& points) {

    sort(points.begin(), points.end(), comp);

    int n = points.size();

    if (n <= 2) {
        hull = points;
        return;
    }

    hull.push_back(points[0]);
    hull.push_back(points[1]);

    // parte de cima

    for (int i = 2; i < n; i++) {
        
        while(hull.size() > 1 && sig_point(points[i], hull.back(), plast(hull)) < 0) {
            hull.pop_back();
        }

        hull.push_back(points[i]);

    }

    // parte de baixo

    int lower_hull = hull.size();

    for (int i = n - 2; i >= 0; i--) {

        while(hull.size() > lower_hull && sig_point(points[i], hull.back(), plast(hull)) < 0) {
            hull.pop_back();
        }

        hull.push_back(points[i]);

    }

    hull.pop_back();

}

int main() {

    int n;
    cin >> n;

    vector<P> points(n);

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        points[i] = {a, b};
    }

    convex_hull(points);

    cout << hull.size() << "\n";

    for (auto& e : hull) cout << e.X << " " << e.Y << "\n";


    return 0;
}