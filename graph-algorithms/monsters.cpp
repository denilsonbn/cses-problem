#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

const pii NOTFIND = {-1, -1};

char grid[1010][1010];
int times[1010][1010];
int times_copy[1010][1010];
map<pii, pii> parent;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string dict = "DRUL";

bool vef(int a, int b, int n, int m) {
    if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] != '#') {
        return 1;
    }
    return 0;
}

void bfs(int n, int m, vector<pii>& mons) {

    queue<pair<int, pii>> fila;

    for (auto& e : mons) {
        fila.push({0, e});
    }

    while(!fila.empty()) {
        pair<int, pii> curr = fila.front();
        fila.pop();
        int t = curr.first;
        pii pos = curr.second;

        for (int k = 0; k < 4; k++) {
            int n_a = pos.first + dx[k];
            int n_b = pos.second + dy[k];
            if (vef(n_a, n_b, n, m)) {
                if (times[n_a][n_b] == -1 || t + 1 < times[n_a][n_b]) {
                    times[n_a][n_b] = t + 1;
                    fila.push({t+1, {n_a, n_b}});
                }
            }
        }

    }
}

// bool ans = 0;

// string dfs(pii pos, int t, string path, int n, int m) {
//     if (pos.first - 1 < 0 || pos.first + 1 >= n || pos.second - 1 < 0 || pos.second + 1 >= m) {
//         ans = 1;
//         return path;
//     }

//     for (int k = 0; k < 4; k++) {
//         int n_a = pos.first + dx[k];
//         int n_b = pos.second + dy[k];
//         pii curr = {n_a, n_b};
//         if (vef(n_a, n_b, n, m)) {
//             if (times[n_a][n_b] - t > 0 || times[n_a][n_b] == -1) {
//                 path.push_back(dict[k]);
//                 times[pos.first][pos.second] = 0;
//                 string result = dfs(curr, t+1, path, n, m);
//                 if (!result.empty()) return result;
//                 path.pop_back();
//             }
//         }
//     }

//     return "";
// }

pii escape(pii pos, int n, int m) {

    queue<pair<int, pii>> fila;
    fila.push({1, pos});

    parent[pos] = pos;

    while(!fila.empty()) {
        pair<int, pii> curr = fila.front();
        fila.pop();

        int t = curr.first;
        pii p = curr.second;

        if (p.first - 1 < 0 || p.first + 1 >= n || p.second - 1 < 0 || p.second + 1 >= m) {
            return {p};
        }

        for (int k = 0; k < 4; k++) {
            int n_a = p.first + dx[k];
            int n_b = p.second + dy[k];
            pii n_pos = {n_a, n_b};
            if (vef(n_a, n_b, n, m)) {
                if (times[n_a][n_b] - t > 0 || times[n_a][n_b] == -1) {
                    parent[n_pos] = p;
                    times[p.first][p.second] = 0;
                    fila.push({t+1, n_pos});
                }
            }
        }
    }

    return NOTFIND;

}

string build_path(pii s, pii f) {

    pii up = parent[f];
    string path = "";

    while(f != s) {
        string next = "";

        for (int k = 0; k < 4; k++) {
            if (f.first - up.first == dx[k] && f.second - up.second == dy[k]) {
                next = dict[k];
            }
        }
        path += next;

        f = up;
        up = parent[f];

    }

    reverse(path.begin(), path.end());

    return path;

}

int main() {
    int n, m;
    pii start;
    cin >> n >> m;
    vector<pii> mons;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') mons.push_back({i, j});
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == '.') times[i][j] = -1;
        }
    }

    bfs(n, m, mons);

    pii ans = escape(start, n, m);

    if (ans != NOTFIND) {
        string path = build_path(start, ans);
        cout << "YES\n" << path.size() << "\n" << path << "\n";
    } else cout << "NO\n";

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << times[i][j];
    //     }
    //     cout << "\n";
    // }

    return 0;
}