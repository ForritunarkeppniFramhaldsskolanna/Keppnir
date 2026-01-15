#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

ll egcd(ll a, ll b, ll& x, ll& y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }

string chem[118] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds ", "Rg ", "Cn ", "Nh", "Fl", "Mc", "Lv", "Ts", "Og" };

ll read_mayan(string &s) {
    ll res = 0;
    for(int i = 3; i < s.size(); i += 4) {
        res *= 20;
        res += s[i] - '\xa0';
    }
    return res;
}

void print_dig(int d) {
    cout << '\xf0' << '\x9d' << '\x8b';
    char pt = '\xa0' + d;
    cout << ((char) pt);
}

void print_mayan(ll x) {
    if(x == 0) {
        print_dig(0);
        return;
    }
    vector<int> digs;
    while(x > 0) {
        digs.push_back(x % 20);
        x /= 20;
    }
    reverse(digs.begin(), digs.end());
    for(int d : digs)
        print_dig(d);
    cout << '\n';
}


int main() {
    string inp;
    getline(cin, inp);
    stringstream ss;
    ss << inp;
    if(inp[0] == '"') {
        bool instr = false;
        for(char c : inp) {
            if(c == '"') instr = !instr;
            else if(instr) cout << c;
        }
        cout << '\n';
    } else if(inp[0] == '0' && inp[1] == 'x') {
        int a, b; char jnk; 
        ss >> hex >> a >> ws >> jnk >> b;
        cout << "0x" << hex << a + b << '\n';
    } else if(inp[0] & (1 << 7)) {
        string s1, s2, s3;
        ss >> s1 >> s2 >> s3;
        print_mayan(read_mayan(s1) + read_mayan(s3));
    } else if(inp[0] == 'l') {
        ll a, b; char jnk;
        ss >> ws >> jnk >> jnk >> jnk >> jnk;
        ss >> a >> jnk >> ws >> jnk;
        ss >> ws >> jnk >> jnk >> jnk >> jnk;
        ss >> b >> jnk;
        cout << "log(" << a * b << ")\n";
    } else if(inp[0] == '{') {
        vector<int> vals[2] = { vector<int>(), vector<int>() };
        for(int i = 0; i < 2; ++i) {
            char jnk;
            ss >> jnk;
            while(true) {
                int x; 
                ss >> x;
                vals[i].push_back(x);
                if(ss.peek() == '}') {
                    ss >> jnk;
                    break;
                }
                ss >> jnk >> ws;
            }
            if(i == 0)
                ss >> ws >> jnk >> ws;
        }
        vector<int> res;
        set_union(vals[0].begin(), vals[0].end(), vals[1].begin(), vals[1].end(), back_inserter(res));
        cout << '{';
        for(int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if(i + 1 != res.size()) cout << ", ";
        }
        cout << "}\n";
    } else if('a' <= inp[0] && inp[0] <= 'z') { 
        if(inp[0] == 't') {
            if(inp[1] == 'r') cout << "comedy\n";
            else cout << "danish\n";
        } else if(inp[0] == 'r') {
            if(inp[2] == 'd') cout << "purple\n";
            else cout << "learning\n";
        } else if(inp[0] == 'f') cout << "steam\n";
        else if(inp[0] == 'i') cout << "procrastination\n";
        else if(inp[0] == 'k') cout << "verdict\n";
        else if(inp[0] == 'p') cout << "AC\n";
        else if(inp[0] == 'c') cout << "WA\n";
        else cout << "this problem\n";
    } else if('A' <= inp[0] && inp[0] <= 'Z') {
        string s1, s2, s3;
        ss >> s1 >> s2 >> ws >> s3;
        int ind = 1;
        for(int i = 0; i < 118; ++i) {
            if(s1 == chem[i]) ind += i;
            if(s3 == chem[i]) ind += i;
        }
        cout << chem[ind] << '\n';
    } else if(inp.find("mod") != string::npos) {
        ll a1, n1, a2, n2, m1, m2; string jnk;
        ss >> a1 >> jnk >> n1 >> jnk;
        ss >> a2 >> jnk >> n2;
        egcd(n1, n2, m1, m2);
        ll mod = n1 * n2;
        __int128 s1 = m2 * n2, s2 = m1 * n1;
        s1 = (s1 % mod + mod) % mod;
        s2 = (s2 % mod + mod) % mod;
        s1 *= a1; s2 *= a2;
        cout << ((ll) ((s1 + s2) % mod)) << " mod " << mod << '\n';
    } else if(inp.find("i") != string::npos) {
        int x, y, z, w; char jnk;
        ss >> x >> ws >> jnk >> y >> jnk;
        ss >> ws >> jnk;
        ss >> z >> ws >> jnk >> w >> jnk;
        cout << x + z << " + " << y + w << "j\n";
    } else {
        int x, y; char jnk;
        ss >> x >> ws >> jnk >> y;
        cout << x + y << '\n';
    }
}
