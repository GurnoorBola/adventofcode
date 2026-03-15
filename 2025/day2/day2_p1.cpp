#include <iostream>

using ll = long long;

constexpr ll pow(ll a, int x) {
    ll res{1};
    for (int i{0}; i < x; ++i) res *= a;
    return res;
}

constexpr int numDigits(ll a) {
    ll max{a};
    int digits{0};
    while (max > 0) {
        max /= 10;
        digits += 1;
    }
    return digits;
}

constexpr ll sumInvalid(ll lower, ll upper) {
    ll res{0};

    // ex: 11 since 1 and 1 is repeated
    // ex: 123123 since 1 and 1 is repeated
    //
    // idea: to check if number is invalid just find the number of digits it has
    // then find if num / 10^(digits/2) == num % 10^(digits/2)

    int digits{numDigits(lower)};
    ll max{pow(10, digits)};

    ll start{lower};
    if (digits % 2 == 1) {
        start = max;
        max *= 10;
        digits += 1;
    }

    ll divisor{pow(10, digits / 2)};

    for (ll num{start}; num <= upper; ++num) {
        if (num >= max) {
            digits += 1;
            max *= 10;
            if (digits % 2 == 1) {
                max *= 10;
                num *= 10;
                digits += 1;
            }
        }
        ll left{num / divisor};
        ll right{num % divisor};

        res += ((left == right) ? num : 0);
    }

    return res;
}

int main() {
    ll res{0};
    ll lower{};
    ll upper{};
    char garb{};

    while (std::cin >> lower >> garb >> upper >> garb) { res += sumInvalid(lower, upper); }

    std::cout << "Result: " << res << "\n";

    return 0;
}
