#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, a, b;
	cin >> s >> a >> b;
	int sm = 0;
	int big = 0;
	int ot = 0;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		string sim = s.substr(i, 1);
		if (sim == a) {
			big++;
		}
		else if (sim == b) {
			sm++;
		}
		else {
			ot++;
		}
	}
	cout << big << endl << sm << endl << ot<< endl << s.length();
	
}