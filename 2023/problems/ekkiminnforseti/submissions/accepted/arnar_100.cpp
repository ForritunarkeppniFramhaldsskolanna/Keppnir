#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
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

int n, m, required_to_win;

vector<int> get_results(const vector<vector<vector<int>>>& vote_map)
{
    vector<pair<int, int>> result(m);
    for(int i = 0; i < m; i++)
    {
        result[i] = make_pair(-static_cast<int>(vote_map[i].size()), i);
    }
    sort(result.begin(), result.end());
    vector<int> order(m);
    for(int i = 0; i < m; i++)
    {
        order[i] = result[i].second;
    }
    return order;
}

bool has_winner(const vector<int>& order, vector<vector<vector<int>>>& vote_map)
{
    if (order.empty())
    {
        return false;
    }

    int winner_id = order[0];
    return static_cast<int>(vote_map[winner_id].size()) >= required_to_win;
}

int get_next_loser(const vector<int>& order, const vector<vector<vector<int>>>& vote_map)
{
    for (int i = m-1; i >= 0; i--)
    {
        if (!vote_map[order[i]].empty())
        {
            return order[i];
        }
    }
    assert(false);
}

void transfer_votes_from_loser(const vector<int>& order, vector<vector<vector<int>>>& vote_map)
{
    int loser_id = get_next_loser(order, vote_map);
    for(auto& vote : vote_map[loser_id])
    {
        vote.pop_back();
        int successor = vote.back();
        while (vote_map[successor].empty())
        {
            vote.pop_back();
            successor = vote.back();
        }
        vote_map[successor].push_back(vote);
    }
    vote_map[loser_id].clear();
}

void print_results(const vector<string>& candidates, const vector<int>& order, const vector<vector<vector<int>>>& vote_map)
{
    for(auto i : order)
    {
        if (vote_map[i].size() == 0) break;
        cout << candidates[i] << " " << vote_map[i].size() << " " << fixed << setprecision(2) << 100.0*vote_map[i].size()/n << "%" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    vector<string> candidates(m);
    rep(i,0,m) cin >> candidates[i];

    required_to_win = n/2 + 1;

    vector<vector<int>> votes(n, vector<int>(m));
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin >> votes[i][j];
            votes[i][j]--;
        }
        reverse(votes[i].begin(), votes[i].end());
    }

    vector<vector<vector<int>>> vote_map;
    rep(i,0,m) vote_map.emplace_back();

    vector<int> order;
    int round_id = 1;

    while(!has_winner(order, vote_map))
    {
        if (order.empty())
        {
            for(auto& vote : votes)
            {
                vote_map[vote.back()].push_back(vote);
            }
        }
        else
        {
            transfer_votes_from_loser(order, vote_map);
        }
        order = get_results(vote_map);
        //print_results(candidates, order, vote_map);       
        round_id++;
    }

    cout << candidates[order[0]] << endl;

    return 0;
}
