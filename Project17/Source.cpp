#include"Login_Form.h"

int main() {
	init();
	int action = 0;
	do {
		CLEAR
		cout << "Select action:\n1.New user registration\n2.Log in\n3.Exit\n";
		cin >> action;
		CLEAR
		switch (action) {
		case 1:
			Registration();
			break;
		case 2:
			LogIn();
			break;
		case 3:
			cout << "Bye.";
				SLEEP
				break;
		default:
			cout << "Invalid value.";
		}
	} while (action != 3);


	return 0;
}