#include "constants.h"
#include <string>

using ullong = unsigned long long;
using namespace constants;
using namespace std;

bool isullong(const string& str) {

	for (char c : str) {
		if (!isdigit(c)) return false;
	}

	return true;
}