#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n, num;
    cin >> n;
    int cnt[101] = {};

    for (int i = 0; i < n; i++) {
        cin >> num;
        cnt[num]++;
    }
    for (int i = 1; i < 101; i++) {
        if (cnt[i] != 0) {
            cout << i << "\n";

        }
    }
}