#include<iostream>
#include<list>
#include<string>

using namespace std;
list<char> L;
list<char>::iterator t = L.begin();
string s;
int main() {

	int n;	
	cin >> n;
	while (n != 0) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			switch (s.at(i)) {
			case '<':
				if(t!=L.begin()) t--;
				break;
			case '>':
				if (t != L.end()) t++;
				break;
			case '-':
				if (t != L.begin()) t--;
				 t = L.erase(t);
				break;
			default:
				L.insert(t, s.at(i));
				break;
			}
		}
		for (list<char>::iterator it = L.begin(); it != L.end(); it++)cout << *it;
		cout << '\n';
		L.clear();
		t = L.begin();
		n--;
	}
}