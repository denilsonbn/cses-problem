#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

int knight(int t, int c) {
    if (t == 2) {
        ans[c]++;
    }   



}

int main() {
    int n;
    cin >> n;

    ans.assign(n+1, 0);

    for (int i = 1; i <= n; i++) {
        knight(0, i);
    }


    return 0;
}