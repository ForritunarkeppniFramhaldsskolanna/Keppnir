#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<dd> vdd;

double dist(dd a, dd b)
{
    double xd = a.first - b.first;
    double yd = a.second - b.second;
    return sqrt(xd*xd + yd*yd);
}

int main()
{
    cout << setprecision(9) << fixed;
    int n;
    cin >> n;
    vdd points(n);
    for(int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    vi tour(n);
    for(int i = 0; i < n; i++)
    {
        cin >> tour[i];
    }

    double tourlength = 0;
    for(int i = 0; i < n; i++)
    {
        cout << tour[i] << " ";
        tourlength += dist(points[tour[i]], points[tour[(i+1)%n]]);
    }
    cout << endl;
    cout << "Length: " << tourlength << endl;
}
