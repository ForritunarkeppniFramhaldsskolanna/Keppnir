#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double x, y, z, a, b;

    cin >> x >> y >> z >> a >> b;

    double worker_hour_per_hole = (y * x) / z;

    cout << fixed << setprecision(2) << worker_hour_per_hole * b / a << endl;
}