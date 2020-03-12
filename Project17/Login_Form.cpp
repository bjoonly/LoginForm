#include"Login_Form.h"

list <User> AllUsers;
const string fileName = "Users.txt";

void init(){
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == false)
		cout << "The file couldn't be opened.\n";
	else {
		int currentString = 0;
		string data;
		User oldUser;
		while (!fin.eof()) {
			currentString++;
			getline(fin, data);
			if (currentString == 1)
				oldUser.name = data;
			else if (currentString == 2)
				oldUser.email = data;
			else {
				oldUser.password = data;
				currentString = 0;
				AllUsers.push_back(oldUser);
				oldUser = User();
			}
		}
	}
	fin.close();
}

void Registration(){
	User newUser;
	cout << "Enter name->_";
	cin >> newUser.name;
	cout << "Enter email->_";
	cin >> newUser.email;
	cout << "Enter password->_";
	cin >> newUser.password;
	AllUsers.push_back(newUser);
	CLEAR
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "The file couldn't be opened.\n";
		SLEEP
	}
	else {
		fout << newUser.name << endl;
		fout << newUser.email << endl;
		fout << newUser.password << endl;
		cout << "Registration completed successfully.";
		SLEEP
	}
	fout.close();
	
}

void LogIn(){
	bool res = 0;
	int action = 0;
	string email, password;
	cout << "Email->_";
	cin >> email;
	cout << "Password->_";
	cin >> password;
	CLEAR
	for (User item : AllUsers) {
		if (item.password == password && item.email == email) {
			cout << "Login successful.\n";
			cout << "Hi, " << item.name << endl;
			SLEEP
			res = 1;
			break;
		}
	}
	if (res == 0) {
		cout << "There is no user with the entered mail and password.\n";
		SLEEP
		cout << "Want to try again(1-yes/2-no)?";
		cin >> action;
		if (action == 1) {
			CLEAR
			LogIn();

		}
	}

}
