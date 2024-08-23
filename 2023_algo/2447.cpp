#include <iostream>

using namespace std;

int n;

bool involve_check(int x, int y, int involve)
{
    
    if(involve > 1)
        return involve_check(x, y, involve / 3);
}

void recur_star(int x, int y){
    if (x == n)
    {
        cout << "\n";
        recur_star(0, y + 1);
        return;
    }
    if (y == n)
        return;
    if (involve_check(x, y, n))
        cout << " ";
    else
        cout << "*";
    recur_star(x + 1, y);
}

int main()
{
    cin >> n;
    recur_star(0, 0);

    return 0;
}