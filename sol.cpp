#include <bits/stdc++.h>
using namespace std;

/*

if i > x and w[i-x] = 1, then s[i] = 1
if i + x <= n and w[i+x] = 1, then s[i] = 1
otherwise, s[i] = 0

we should process 0 since the conditions are stricter than 1

if s[i] = 0, then w[i-x] = w[i+x] = 0

*/

void test_case(int& tc) {
	string s;
	int x;
	cin >> s >> x;
	int n = s.size();
	char w[n];
	for (int i = 0; i < n; i++)
		w[i] = '1';
	// process 0 first
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (i - x >= 0)
				w[i-x] = '0';
			if (i + x < n)
				w[i+x] = '0';
		}
	}
	// then process 1
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			bool ok = false;
			if (i - x >= 0 && w[i-x] == '1')
				ok = true;
			if (i + x < n && w[i+x] == '1')
				ok = true;
			if (!ok) {
				cout << "-1\n";
				return;
			}
		}
	}
	for (char ch : w)
		cout << ch;
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
