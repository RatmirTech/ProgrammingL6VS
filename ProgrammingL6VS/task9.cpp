#include <string>
#include <iostream>

#include "constants.h"
#include "myfunctions.h"

using namespace std;
using namespace constants;

using ullong = unsigned long long;

bool argsAreCorrect9(int countArgs, char* args[]) {
	if (countArgs < 4) {
		cout << "������� ���� ����������";
		return false;
	}
	else if (!isullong(args[2]) || !isullong(args[3])) {
		cout << "��������� ������ ���� ���� ullong" << endl;
		return false;
	}
	else
		return true;
}

void printInputArgs9(ullong number, ullong count) {
	cout << "�������� �����: " << number << endl;
	cout << "���������� ���: " << count << endl;
}

ullong getModifiedNumber9(ullong number, ullong count) {

	ullong leftBit{};

	for (int i = 0; i < count; i++) {
		leftBit = number & lastBitMask;
		number <<= 1;

		if (leftBit != 0) {
			number |= firstBitMask;
		}
	}

	return number;
}

void doTask9(int countArgs, char* args[]) {

	if (!argsAreCorrect9(countArgs, args)) return;

	ullong number = stoull(args[2]);
	ullong count = stoull(args[3]);

	printInputArgs9(number, count);

	ullong result = getModifiedNumber9(number, count);
	
	cout << "��������������� �����: " << result << endl << endl;
}