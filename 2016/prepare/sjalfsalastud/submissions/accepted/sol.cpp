#include<iostream>

using namespace std;

int main()
{
    int cokes, hundred, fifty, ten, count;

    cin >> cokes >> ten >> fifty >> hundred;
    count = 0;
    while(cokes > 0)
    {
        if(hundred > 0)
        {
            if(hundred + fifty >= cokes || ten < 3)
            {
                hundred--;
                ten += 2;
                count++;
            }
            else
            {
                hundred--;
                ten -= 3;
                fifty++;
                count += 4;
            }
        }
        else if(fifty > 0)
        {
            if(fifty <= cokes)
            {
                fifty--;
                ten -= 3;
                count += 4;
            }
            else
            {
                fifty -= 2;
                ten += 2;
                count += 2;
            }
        }
        else
        {
            ten -= 8;
            count += 8;
        }
        cokes--;
    }
    cout << count << '\n';
    return 0;
}
