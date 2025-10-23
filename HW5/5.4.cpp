#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        int freq[10] = {0};

        istringstream in(line);
        int x;
        while (in >> x) {
            if (0 <= x && x <= 9) freq[x]++;
        }

        int mx = 0;
        for (int d = 0; d < 10; ++d) mx = max(mx, freq[d]);

        bool first = true;
        if (mx >= 2) {
            for (int d = 0; d < 10; ++d) {
                if (freq[d] == mx) {
                    if (!first) cout << ' ';
                    cout << d;
                    first = false;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
