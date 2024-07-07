#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> b;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (b.find(a[i]) == b.end()) {
            b[a[i]] = i + 1; 
        }
    }

    for (const auto& c : b) {
        cout << c.first << " x " << c.second << endl;
    }

    return 0;
}