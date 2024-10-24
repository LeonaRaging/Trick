#include<bits/stdc++.h>
using namespace std;

#define ll long long

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

ll get(int l, int r) {
    return l + mt() * mt() % (r - l + 1);
}

signed main()
{
    const string NAME = "main";
    for (int test = 1; test <= 100; test++) {
        ofstream inp("inputf.in");
        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "__Good.exe").c_str());
        if (system("fc outputf.out test.out")) {
            cout << "Test " << test << ": Wrong!\n";
            return 0;
        }
        cout << "Test " << test << ": Correct!\n";
    }
}

