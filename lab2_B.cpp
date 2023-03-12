//Списки по классам

#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {

	setlocale(LC_ALL, "Rus");

	typedef std::multimap<int, std::string> strMap;
	strMap m;

	for (int i = 0; i < 100000; ++i) {
		std::string s;
		std::getline(std::cin, s);
		if (s[0] == '9') {
			int num = stoi(s.substr(0, 1));
			m.insert(std::make_pair(num, s.substr(2)));
		}
		else if (s[0] == '1' && (s[1] == '0' || s[1] == '1')) {
			int num = stoi(s.substr(0, 2));
			m.insert(std::make_pair(num, s.substr(3)));
		}

	}

	for (auto& i : m) {
		std::cout << i.first << " " << i.second << std::endl;
	}

	return 0;
}

