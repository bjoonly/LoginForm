#pragma once
#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include"Windows.h"
using namespace std;
#define CLEAR system("cls");
#define SLEEP Sleep(1500);
struct User {
	string name;
	string email;
	string password;
};
void init();
void Registration();
void LogIn();

