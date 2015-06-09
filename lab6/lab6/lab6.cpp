// Lab6.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "TList.h"
#include "iostream"
#include "string"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string code;
	cout << "Enter code" << endl;
	getline(cin, code);

	CTList* instance = new CTList(code);
	string result = instance->Run();
	cout << endl << " > " << result << endl;
	return 0;
}