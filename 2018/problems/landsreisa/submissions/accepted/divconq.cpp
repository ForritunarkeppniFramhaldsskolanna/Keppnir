#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<double, double> dd;

const ll INF = (1LL<<60);
const double pi = acos(-1);
const double EPS = 1e-9;

#define MAXN 10000

dd points[MAXN];

bool cmpx(int i, int j)
{
    return points[i].first == points[j].first ? points[i].second < points[j].second : points[i].first < points[j].first;
}

bool cmpy(int i, int j)
{
    return points[i].second == points[j].second ? points[i].first < points[j].first : points[i].second < points[j].second;
}

double dist(dd a, dd b)
{
    double difx = a.first - b.first, dify = a.second - b.second;
    //return round(sqrt(difx*difx + dify*dify));
    return sqrt(difx*difx + dify*dify);
}

double swapCost(dd a, dd b, dd c, dd d)
{
    //cout << dist(a, c) << " " << dist(b, d) << " " << dist(a, b) << " " << dist(c, d) << endl;
    return dist(a, c) + dist(b, d) - dist(a, b) - dist(c, d);
}

double xmedian(vi &arr)
{
    assert(size(arr) > 0);
    if(size(arr)%2 == 1) return points[arr[size(arr)/2]].first;
    return (points[arr[size(arr)/2-1]].first +  points[arr[size(arr)/2]].first)/2.0;
}

double ymedian(vi &arr)
{
    assert(size(arr) > 0);
    if(size(arr)%2 == 1) return points[arr[size(arr)/2]].second;
    return (points[arr[size(arr)/2-1]].second +  points[arr[size(arr)/2]].second)/2.0;
}

void split(vi &arr, vi &left, vi &right)
{
    /*rep(i,0,size(arr))
    {
        cout << "(" << points[arr[i]].first << ", " << points[arr[i]].second << ") ";
    }
    cout << endl;*/
    left.clear();
    right.clear();
    vi xarr(arr);
    vi yarr(arr);
    sort(xarr.begin(), xarr.end(), cmpx);
    sort(yarr.begin(), yarr.end(), cmpy);
    if(*xarr.rbegin() - *xarr.begin() > *yarr.rbegin() - *yarr.begin())
    {
        /*double med = ymedian(yarr);
        cout << "y median is: " << med << endl;
        rep(i,0,size(arr))
        {
            if(points[arr[i]].second <= med) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }*/
        left = vi(yarr.begin(), yarr.begin()+(yarr.size()/2));
        right = vi(yarr.begin()+(yarr.size()/2), yarr.end());
    }
    else
    {
        /*double med = xmedian(xarr);
        cout << "x median is " << med << endl;
        rep(i,0,size(arr))
        {
            if(points[arr[i]].first <= med) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }*/
        left = vi(xarr.begin(), xarr.begin()+(xarr.size()/2));
        right = vi(xarr.begin()+(xarr.size()/2), xarr.end());
    }
}

vi eTSP(vi &ind)
{
    if(size(ind) < 4) return ind;
    vi left, right;
    split(ind, left, right);
    left = eTSP(left), right = eTSP(right);
    double mn = INFINITY;
    int dir = 0;
    int rstart = -1, lstart = -1;
    rep(i,0,size(left))
    {
        rep(j,0,size(right))
        {
            dd a = points[left[i]], b = points[left[(i+1)%size(left)]];
            dd c = points[right[j]], d = points[right[(j+1)%size(right)]];
            double swap1 = swapCost(a,b,c,d);
            //cout << "Connect " << left[i] << " to " << right[j] << " and " << left[(i+1)%size(left)] << " to " << right[(j+1)%size(right)] << ": " << swap1 << endl;
            if(swap1 < mn)
            {
                //cout << "HERE FOUND MINIMUM 1" << endl;
                mn = swap1;
                dir = -1;
                lstart = (i+1)%size(left);
                rstart = j;
            }
            double swap2 = swapCost(a,b,d,c);
            //cout << "Connect " << left[i] << " to " << right[(j+1)%size(right)] << " and " << left[(i+1)%size(left)] << " to " << right[j] << ": " << swap2 << endl;
            if(swap2 < mn)
            {
                //cout << "HERE FOUND MINIMUM 2" << endl;
                mn = swap2;
                dir = 1;
                lstart = (i+1)%size(left);
                rstart = (j+1)%size(right);
            }
        }
    }
    if(dir == 0) assert(false);
    vi res(size(ind));
    int k = 0;
    rep(i,0,size(left))
    {
        res[k++] = left[(lstart+i)%size(left)];
    }
    rep(j,0,size(right))
    {
        res[k++] = right[(rstart+j*dir+size(right))%size(right)];
    }
    /*cerr << "INNER:" << endl;
    rep(i,0,size(left))
    {
        cerr << left[i] << " ";
    }
    cerr << endl;
    rep(i,0,size(right))
    {
        cerr << right[i] << " ";
    }
    cerr << endl;
    rep(i,0,size(ind))
    {
        cerr << res[i] << " ";
    }
    cerr << endl;*/

    return res;
}

pair<vi,double> naive(int n)
{
    vi cur(n), best;
    rep(i,0,n) cur[i] = i;
    double mn = INFINITY;
    do
    {
        double curdist = 0;
        rep(i,0,n)
        {
            curdist += dist(points[cur[i]], points[cur[(i+1)%n]]);
        }
        if(curdist < mn)
        {
            mn = curdist;
            best = cur;
        }
    } while(next_permutation(cur.begin()+1, cur.end()));
    return make_pair(best, mn);
}

int main() {
    cin.sync_with_stdio(false);
	int n, m;
	cin >> n;
    m = n;
    if(n < 2)
    {
        rep(i,0,n)
        {
            cout << i << endl;
        }
        return 0;
    }
    vi ind(n);
    rep(i,0,n) cin >> points[i].first >> points[i].second, ind[i] = i;
    vi res = eTSP(ind);
    rotate(res.begin(), find(res.begin(), res.end(), 0), res.end());
    double distsm = 0;
    rep(i,0,n)
    {
        cout << res[i]  << " ";
        distsm  += dist(points[res[i]], points[res[(i+1)%n]]);
    }
    //cout << endl << "Length: " << distsm << endl;
    //pair<vi,double> naiveres = naive(m);
    //vi path = naiveres.first;
    //double opt = naiveres.second;
    //rep(i,0,n)
    //{
    //    cout << path[i] << " ";
    //}
    //cout << endl << "optimal: " << opt << endl;
    //cout << "abs diff: " << distsm-opt << endl;
    //cout << "rel diff: " << distsm/opt - 1 << endl;
    //if(distsm-opt > 0.001) return 1;
    return 0;
}


