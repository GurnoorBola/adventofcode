#include <iostream>
#include <cmath>

constexpr long long pow(long long a, long long x)
{
    long long res{1};
    for (long long i{0}; i < x; ++i)
        res *= a;
    return res;
}

constexpr long long numDigits(long long a)
{
    long long max{a};
    long long digits{0};
    while (max > 0)
    {
        max /= 10;
        digits += 1;
    }
    return digits;
}

constexpr long long sumInvalid(long long lower, long long upper)
{
    long long res{0};

    //ex: 11 since 1 and 1 is repeated
    //ex: 123123 since 1 and 1 is repeated
    //
    //idea: to check if number is invalid just find the number of digitis it has
    //then find if num / 10^(digits/2) == num % 10^(digits/2)
    //
    //if number of digits is odd we treat as if there is invisible 0 in front 
    //so we check with (digits+1)/2 instead
    
    long long digits{numDigits(lower)};
    long long max{pow(10, digits)};

    long long start{lower};
    if (digits % 2 == 1)
    {
        start = max;
        max *= 10;
        digits += 1;
    }

    long long divisor{pow(10, digits/2)};
    
    for (long long num{start}; num <= upper; ++num)
    {
        if (num >= max)
        {
            digits += 1;
            max *= 10;
            if (digits % 2 == 1)
            {
                max *= 10;
                num *= 10;
                digits += 1;
            }
                
        }
        long long left{num / divisor};
        long long right{num % divisor};
        
        // std::cout << "Parts: " << left << " " << right << "\n";

        res += ((left == right) ? num: 0);
    }

    return res;
}


int main () {

    long long res{0};
    long long lower{};
    long long upper{};
    char garb{};

    while(std::cin >> lower >> garb >> upper >> garb)
    {

        res += sumInvalid(lower, upper);
    }

    std::cout << "Result: " << res << "\n";

    return 0;
}
