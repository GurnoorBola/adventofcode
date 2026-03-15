#include <iostream>

int main()
{
    char m{};
    int v{};
    int s{50};
    int res{0};

    while (std::cin >> m >> v)
    {
        if (m == 'R')
        {
            res += (s + v) / 100;
            s = (s + v) % 100;
        }
        else
        {
            int diff{s - v};
            int r{diff % 100};
            if (diff == 0)
            {
                res += 1;
            }
            else if (diff < 0)
            {
                res += ((s == 0) ? 0 : 1);
                res += (diff - r) / -100;
            }
            s = r < 0 ? 100 + r : r;
        }
    }

    std::cout << "Result: " << res << "\n";
    return 0;    
}
