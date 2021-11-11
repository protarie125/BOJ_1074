#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<ll> twos{};

ll solve(ll N, ll r, ll c) {
    if (1 == N)
        return 2 * r + c;

    const auto& t = twos[N - 1];
    auto r2 = r / t;
    auto c2 = c / t;

    auto v = 2 * r2 + c2;
    auto t2 = t * t;

    return v * t2 + solve(N - 1, r - r2 * t, c - c2 * t);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N, r, c;
    cin >> N >> r >> c;

    twos.reserve(N + 1);
    ll t{ 1 };
    for (int i = 0; i <= N; ++i)
    {
        twos.push_back(t);
        t *= 2;
    }

    cout << solve(N, r, c);

    return 0;
}