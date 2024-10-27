// lab_8_1_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int Count(char* str, int i = 0) {
	if (str[i + 4] != 0) {
		if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e') {
			return 1 + Count(str, i + 5);
		}
		else {
			return Count(str, i + 1);
		}
	}
	else {
		return 0;
	}
}


char* Change(char* dest, const char* str, char* t, int i) {
	if (str[i + 4] != 0) {
		if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e') {
			strcat(t, "***");
			return Change(dest, str, t + 3, i + 5);
		}
		else {
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else {
		*t++ = str[i++];
		*t++ = str[i++];
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main() {
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << Count(str) << " occurrences of 'while'" << endl;

	char* dest1 = new char[101];
	dest1[0] = '\0';
	char* dest2 = Change(dest1, str, dest1, 0);

	cout << "Modified string (param): " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;

	cin.get();
	return 0;
}
