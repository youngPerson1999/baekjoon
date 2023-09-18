#include <iostream>

using namespace std;

int main()
{
    int n, three, five, result;
    cin >> n;
    five = n / 5;
    if ((n % 5) % 3 == 0)
        result = five + (n % 5) / 3;
    else
    {
        for (; five >= 0; five--)
        {
            three = (n - five * 5) / 3;
            if ((n - five * 5) % 3 == 0)
                break;
        }
        if (five < 0)
            result = -1;
        else
            result = three + five;
    }
    cout << result << "\n";

    return 0;
}