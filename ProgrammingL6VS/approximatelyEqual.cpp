// ���������� true, ���� ������� ����� a � b � �������� �������� ��������
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

bool isFloat(const string& str) {
	//cout << "checking number: " << str << endl;
	bool e = false;
	bool dot = false;
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			continue;
		}
		else {
			if (i == 0 && (str[i] == '-' || str[i] == '+')) {
				continue;
			}
			else if (str[i] == ',' && !dot && !e && !(i==1 && (str[i - 1] == '-' || str[i - 1] == '+'))) {
				dot = true;
				continue;
			}
			else if (str[i] == 'e' && !e) {
				e = true;
				continue;
			}
			else if (i > 0 && str[i - 1] == 'e' && (str[i] == '-' || str[i] == '+')) {
				continue;
				
			}
			else {
				return false;
			}
		}
	}

	//cout << stof(str) << endl;

	return true;
}

bool approximatelyEqual(float a, float b, float epsilon)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// ���������� true, ���� ������� ����� a � b ������ absEpsilon
// ��� � �������� relEpsilon
bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon) {

	float diff = fabs(a - b);
	if (diff <= absEpsilon)
		return true;
	// � ��������� ������, ������������ � ��������� �����
	return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

bool argsAreCorrect(int countArgs, char* args[], int countMeaningfulArgs) {
	if (countArgs < countMeaningfulArgs) return false;

	for (int i = 2; i < countMeaningfulArgs; i++) {
		if (!isFloat(args[i]))
			return false;
	}

	return true;
}

void doApproximatelyEqualAbsRel(int countArgs, char* args[]) {
	if (!argsAreCorrect(countArgs, args, 6)) {
		cout << "������������ ���������";
	}
	else {
		std::cout << std::fixed << std::setprecision(15);
		cout << "��������� ��������� ����� " << stof(args[2]) << " � " << stof(args[3]) << " � absEpsilon " << stof(args[4]) << " � relEpsilon " << stof(args[5]) << ": ";
		cout << (approximatelyEqualAbsRel(stof(args[2]), stof(args[3]), stof(args[4]), stof(args[5])) ? "�����" : "�� �����") << endl;
	}
}

void doApproximatelyEqual(int countArgs, char* args[]) {
	if (countArgs == 6) {
		doApproximatelyEqualAbsRel(countArgs, args);
	}
	else if (!argsAreCorrect(countArgs, args, 5)) {
		cout << "������������ ���������";
	}
	else {
		std::cout << std::fixed << std::setprecision(15);
		cout << "��������� ��������� ����� " << stof(args[2]) << " � " << stof(args[3]) << " � ��������� " << stof(args[4]) << ": ";
		cout << (approximatelyEqual(stof(args[2]), stof(args[3]), stof(args[4])) ? "�����" : "�� �����") << endl;
	}
}


