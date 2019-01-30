#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }    

#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define C(p0, r) P(p0), double r
#define PP(pp) pair<point,point> &pp
typedef complex<double> point;
double dot(P(a), P(b)) { return real(conj(a) * b); }
double cross(P(a), P(b)) { return imag(conj(a) * b); }
point rotate(P(p), double radians = pi / 2,
             P(about) = point(0,0)) {
  return (p - about) * exp(point(0, radians)) + about; }
point reflect(P(p), L(about1, about2)) {
  point z = p - about1, w = about2 - about1;
  return conj(z / w) * w + about1; }
point proj(P(u), P(v)) { return dot(u, v) / dot(u, u) * u; }
point normalize(P(p), double k = 1.0) {
  return abs(p) == 0 ? point(0,0) : p / abs(p) * k; }
double ccw(P(a), P(b), P(c)) { return cross(b - a, c - b); }
bool collinear(P(a), P(b), P(c)) {
  return abs(ccw(a, b, c)) < EPS; }
double angle(P(a), P(b), P(c)) {
  return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b)); }
double signed_angle(P(a), P(b), P(c)) {
  return asin(cross(b - a, c - b) / abs(b - a) / abs(c - b)); }
double angle(P(p)) { return atan2(imag(p), real(p)); }
point perp(P(p)) { return point(-imag(p), real(p)); }
double progress(P(p), L(a, b)) {
  if (abs(real(a) - real(b)) < EPS)
    return (imag(p) - imag(a)) / (imag(b) - imag(a));
  else return (real(p) - real(a)) / (real(b) - real(a)); }

bool collinear(L(a, b), L(p, q)) {
  return abs(ccw(a, b, p)) < EPS && abs(ccw(a, b, q)) < EPS; }
bool parallel(L(a, b), L(p, q)) {
  return abs(cross(b - a, q - p)) < EPS; }
point closest_point(L(a, b), P(c), bool segment = false) {
  if (segment) {
    if (dot(b - a, c - b) > 0) return b;
    if (dot(a - b, c - a) > 0) return a;
  }
  double t = dot(c - a, b - a) / norm(b - a);
  return a + t * (b - a); }
double line_segment_distance(L(a,b), L(c,d)) {
  double x = INFINITY;
  if (abs(a - b) < EPS && abs(c - d) < EPS) x = abs(a - c);
  else if (abs(a - b) < EPS)
    x = abs(a - closest_point(c, d, a, true));
  else if (abs(c - d) < EPS)
    x = abs(c - closest_point(a, b, c, true));
  else if ((ccw(a, b, c) < 0) != (ccw(a, b, d) < 0) &&
       (ccw(c, d, a) < 0) != (ccw(c, d, b) < 0)) x = 0;
  else {
    x = min(x, abs(a - closest_point(c,d, a, true)));
    x = min(x, abs(b - closest_point(c,d, b, true)));
    x = min(x, abs(c - closest_point(a,b, c, true)));
    x = min(x, abs(d - closest_point(a,b, d, true)));
  }
  return x; }
bool intersect(L(a,b), L(p,q), point &res, bool seg=false) {
  // NOTE: check parallel/collinear before
  point r = b - a, s = q - p;
  double c = cross(r, s),
         t = cross(p - a, s) / c, u = cross(p - a, r) / c;
  if (seg &&
      (t < 0-EPS || t > 1+EPS || u < 0-EPS || u > 1+EPS))
    return false;
  res = a + t * r;
  return true; }

bool line_segment_intersect(L(a, b), L(c, d), point &A,
                                              point &B) {
  if (abs(a - b) < EPS && abs(c - d) < EPS) {
    A = B = a; return abs(a - d) < EPS; }
  else if (abs(a - b) < EPS) {
    A = B = a; double p = progress(a, c,d);
    return 0.0 <= p && p <= 1.0
      && (abs(a - c) + abs(d - a) - abs(d - c)) < EPS; }
  else if (abs(c - d) < EPS) {
    A = B = c; double p = progress(c, a,b);
    return 0.0 <= p && p <= 1.0
      && (abs(c - a) + abs(b - c) - abs(b - a)) < EPS; }
  else if (collinear(a,b, c,d)) {
    double ap = progress(a, c,d), bp = progress(b, c,d);
    if (ap > bp) swap(ap, bp);
    if (bp < 0.0 || ap > 1.0) return false;
    A = c + max(ap, 0.0) * (d - c);
    B = c + min(bp, 1.0) * (d - c);
    return true; }
  else if (parallel(a,b, c,d)) return false;
  else if (intersect(a,b, c,d, A, true)) {
    B = A; return true; }
  return false; }

double swapCost(point a, point b, point c, point d)
{
    //cout << dist(a, c) << " " << dist(b, d) << " " << dist(a, b) << " " << dist(c, d) << endl;
    return abs(a-c) + abs(b-d) - abs(a-b) - abs(c-d);
}

double swapCost(point a, point b, point c, point d, point e)
{
    return abs(a-c) + abs(d-b) + abs(b-e) - abs(a-b) - abs(b-c) - abs(d-e);
}

const double MAXTIME = 4.5;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(9) << fixed;
	srand(time(NULL));
	clock_t begin = clock();
    int n;
    cin >> n;
    vector<point> points(n);
    vi best(n);
    rep(i,0,n) best[i] = i;
    double bestlength = INFINITY;
    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        points[i] = point(x,y);
    }
    rep(start,0,1)
    {
        if(double(clock()-begin) / CLOCKS_PER_SEC > MAXTIME) break;
        vi tour(1, start);
        vector<bool> vis(n, false);
        vis[start] = true;
        while(tour.size() < n)
        {
            int cur = tour.back();
            int mn = -1;
            for(int i = 0; i < n; i++)
            {
                if(!vis[i])
                {
                    if(mn == -1 || abs(points[i] - points[cur]) < abs(points[mn] - points[cur]))
                    {
                        mn = i;
                    }
                }
            }

            vis[mn] = true;
            tour.push_back(mn);
        }
        
        bool change=true;
        while(change)
        {
            change = false;
            for(int i = 0; i < n; i++)
            {
                if(double(clock()-begin) / CLOCKS_PER_SEC > MAXTIME) break;
                point a = points[tour[i]];
                point b = points[tour[(i+1)%n]];
                point c = points[tour[(i+2)%n]];
                for(int j = 2; j < n-1; j++)
                {
                    if(double(clock()-begin) / CLOCKS_PER_SEC > MAXTIME) break;
                    point d = points[tour[(i+j)%n]];
                    point e = points[tour[(i+j+1)%n]];
                    if(swapCost(a,b,d,e) < -EPS)
                    {
                        vi newtour;
                        for(int k = 0; k < j; k++)
                        {
                            newtour.push_back(tour[(i+j-k+n)%n]);
                        }
                        for(int k = 0; k < n - j; k++)
                        {
                            newtour.push_back(tour[(i+j+k+1)%n]);
                        }
                        tour = newtour;
                        change = true;
                    }
                    else if(swapCost(a,b,c,d,e) < -EPS)
                    {
                        vi newtour;
                        newtour.push_back(tour[(i+1)%n]);
                        for(int k = 0; k < n; k++)
                        {
                            if((i+j+k+1)%n != (i+1)%n)
                            {
                                newtour.push_back(tour[(i+j+k+1)%n]);
                            }
                        }
                        tour = newtour;
                        change = true;
                    }
                    if(change) break;
                }
                if(change) break;
            }
        }

        double tourlength = 0;
        for(int i = 0; i < n; i++)
        {
            //cout << tour[i] << " ";
            tourlength += abs(points[tour[i]] - points[tour[(i+1)%n]]);
        }
        if(tourlength < bestlength)
        {
            best = tour;
            bestlength = tourlength;
        }
        //cout << endl;
    }
    rotate(best.begin(), find(best.begin(), best.end(), 0), best.end());
    for(int i = 0; i < n; i++)
    {
        cout << best[i] << " ";
    }
    cout << endl;
    //cout << "Length: " << tourlength << endl;
}
