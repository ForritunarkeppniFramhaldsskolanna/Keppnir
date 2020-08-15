#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

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

bool intersect(L(a,b), L(p,q), point &res,
    bool lseg=false, bool rseg=false) {
  // NOTE: check parallel/collinear before
  point r = b - a, s = q - p;
  double c = cross(r, s),
         t = cross(p - a, s) / c, u = cross(p - a, r) / c;
  if (lseg && (t < 0-EPS || t > 1+EPS)) return false;
  if (rseg && (u < 0-EPS || u > 1+EPS)) return false;
  res = a + t * r; return true; }
// vim: cc=60 ts=2 sts=2 sw=2:

int main() {
    cin.sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<double> A(n), Pr(n);
    rep(i,0,n-1) cin >> Pr[i] >> A[i];
    cin >> Pr[n-1];
    vector<double> B(m), Q(m);
    rep(i,0,m-1) cin >> Q[i] >> B[i];
    cin >> Q[m-1];

    rep(i,0,n) {
        Pr[i] = 1-(Pr[i]/100.0);
    }
    rep(i,0,m) {
        Q[i] = 1-(Q[i]/100.0);
    }
    A[n-1] = 10000000000000;
    B[m-1] = 10000000000000;

    double min_val = 0;
    double max_val = B[0]*Q[0];
    double start1 = 0;
    double end1 = B[0];

    double min_val2 = 0;
    double max_val2 = A[0]*Pr[0];
    double start2 = 0;
    double end2 = A[0];

    int at1 = 0;
    int at2 = 0;
    vector<double> POS;
    point f_1(start1, min_val);
    point f_2(end1, max_val);

    point s_1(start2, min_val2);
    point s_2(end2, max_val2);
    
    point res;
    if(intersect(f_1, f_2, s_1, s_2, res, true,true)) {
        POS.pb(real(res));
    }

    while(true) {
        if(end2 < start1 && at1+1 != n) {
            min_val2 += (A[at1] - (at1 == 0 ? 0 : A[at1-1]) ) * Pr[at1];
            max_val2 += (A[at1+1]-A[at1]) * Pr[at1+1];

            start2 = A[at1];
            end2 = A[at1+1];
            at1 += 1;
        } else if(end1 < start2 && at2+1 != m) {
            min_val += (B[at2] - (at2 == 0 ? 0 : B[at2-1])) * Q[at2];
            max_val += (B[at2+1] - B[at2]) * Q[at2+1];

            start1 = B[at2];
            end1 = B[at2+1];
            at2 += 1;
        } else if(end2 < end1 && at1+1 != n) {
            min_val2 += (A[at1] - (at1 == 0 ? 0 : A[at1-1]) ) * Pr[at1];
            max_val2 += (A[at1+1]-A[at1]) * Pr[at1+1];

            start2 = A[at1];
            end2 = A[at1+1];
            at1 += 1;
        } else if(end1 < end2 && at2+1 != m) {
            min_val += (B[at2] - (at2 == 0 ? 0 : B[at2-1])) * Q[at2];
            max_val += (B[at2+1] - B[at2]) * Q[at2+1];

            start1 = B[at2];
            end1 = B[at2+1];
            at2 += 1;
        } else if(at1 + 1 != n) {
            min_val2 += (A[at1] - (at1 == 0 ? 0 : A[at1-1]) ) * Pr[at1];
            max_val2 += (A[at1+1]-A[at1]) * Pr[at1+1];

            start2 = A[at1];
            end2 = A[at1+1];
            at1 += 1;
        } else if(at2+ 1 != m) {
            min_val += (B[at2] - (at2 == 0 ? 0 : B[at2-1])) * Q[at2];
            max_val += (B[at2+1] - B[at2]) * Q[at2+1];

            start1 = B[at2];
            end1 = B[at2+1];
            at2 += 1;
        
        } else break;


        point f_1(start1, min_val);
        point f_2(end1, max_val);

        point s_1(start2, min_val2);
        point s_2(end2, max_val2);
        
        point res;
        if(intersect(f_1, f_2, s_1, s_2, res, true,true) && real(res)) {
            POS.pb(real(res));
        }
    }
    iter(it,POS) cout << setprecision(15) << fixed << *it << endl;


    return 0;
}

