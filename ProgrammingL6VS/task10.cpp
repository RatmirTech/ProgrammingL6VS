#include <string>
#include <iostream>

#include "constants.h"
#include "myfunctions.h"

using ullong = unsigned long long;

using namespace std;
using namespace constants;

bool argsAreCorrect10(int countArgs, char* args[]) {
	if (countArgs < 4) {
		cout << "Введено мало аргументов";
		return false;
	}
	else if (!isullong(args[2]) || !isullong(args[3])) {
		cout << "Аргументы должны быть типа ullong" << endl;
		return false;
	}
	else return true;
}

void printInputArgs10(ullong number, ullong count) {
	cout << "Исходное число: " << number << endl;
	cout << "На сколько бит сдвинуть четные: " << count << endl;
}

ullong getModifiedNumber10(ullong number, ullong count) {

	ullong oddBits = number & oddBitsMask;
	ullong evenBits = number & evenBitsMask;

	evenBits <<= 2 * count;


	return oddBits | evenBits;
}

void doTask10(int countArgs, char* args[]) {

	if (!argsAreCorrect10(countArgs, args)) return;

	ullong number = stoull(args[2]);
	ullong count = stoull(args[3]);

	printInputArgs10(number, count);

	ullong result = getModifiedNumber10(number, count);

	cout << "Преобразованное число: " << result << endl << endl;
}