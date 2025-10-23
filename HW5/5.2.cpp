#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <random>
#include <climits>
#include <iomanip>
using namespace std;

struct Instance {
    int n;
    vector<vector<int>> menPref;      
    vector<vector<int>> womenRank;    
};

static void make_random_pref(vector<int>& v, mt19937& rng) {
    int n = (int)v.size();
    iota(v.begin(), v.end(), 0);
    uniform_int_distribution<int> dist(0, n - 1);
    for (int t = 0; t < 100; ++t) {
        int i = dist(rng), j = dist(rng);
        swap(v[i], v[j]);
    }
}

static Instance make_instance(int n, mt19937& rng) {
    Instance I;
    I.n = n;
    I.menPref.assign(n, vector<int>(n));
    vector<vector<int>> womenPref(n, vector<int>(n));
    for (int m = 0; m < n; ++m) make_random_pref(I.menPref[m], rng);
    for (int w = 0; w < n; ++w) make_random_pref(womenPref[w], rng);

    I.womenRank.assign(n, vector<int>(n, 0));
    for (int w = 0; w < n; ++w)
        for (int rank = 0; rank < n; ++rank)
            I.womenRank[w][womenPref[w][rank]] = rank;

    return I;
}

static long long gale_shapley_proposals(const Instance& I) {
    int n = I.n;
    vector<int> nextIdx(n, 0);            
    vector<int> partnerOfWoman(n, -1);    
    vector<int> partnerOfMan(n, -1);      
    queue<int> freeMen;
    for (int m = 0; m < n; ++m) freeMen.push(m);

    long long proposals = 0;

    while (!freeMen.empty()) {
        int m = freeMen.front(); freeMen.pop();

        
        int w = I.menPref[m][nextIdx[m]++];
        ++proposals;

        if (partnerOfWoman[w] == -1) {
            partnerOfWoman[w] = m;
            partnerOfMan[m] = w;
        } else {
            int m2 = partnerOfWoman[w];
            if (I.womenRank[w][m] < I.womenRank[w][m2]) {
                partnerOfWoman[w] = m;
                partnerOfMan[m] = w;
                partnerOfMan[m2] = -1;
                freeMen.push(m2);
            } else {
                if (nextIdx[m] < n) freeMen.push(m);
            }
        }
    }
    return proposals;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100;
    const int TRIALS = 1000;

    random_device rd;
    mt19937 rng(rd());

    long long minProp = LLONG_MAX, maxProp = LLONG_MIN, sumProp = 0;

    for (int t = 0; t < TRIALS; ++t) {
        Instance I = make_instance(N, rng);
        long long p = gale_shapley_proposals(I);
        minProp = min(minProp, p);
        maxProp = max(maxProp, p);
        sumProp += p;
    }

    double avg = static_cast<double>(sumProp) / TRIALS;

    cout << "Stable Matching (men-proposing Gale–Shapley)\n";
    cout << "Instances: " << TRIALS << ", Size: " << N << "x" << N << "\n";
    cout << "Proposals (min / avg / max): "
         << minProp << " / " << fixed << setprecision(2) << avg << " / " << maxProp << "\n";

    return 0;
}
