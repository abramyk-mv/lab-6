#include "stdafx.h"
#include "Atom_Operation.h"
#include "iostream"
using namespace std;

CAtom_Operation::CAtom_Operation(void)
{
}


CAtom_Operation::~CAtom_Operation(void)
{
}

CAtom_Operation::CAtom_Operation(string arg)
{
	nameOfOperation = arg;
}

void CAtom_Operation::SetAtom(string str)
{
	nameOfOperation = str;
}

string CAtom_Operation::GetAtom()
{
	return nameOfOperation;
}

void CAtom_Operation::ShowAtom()
{
	cout << "Operation - " << nameOfOperation << endl;
}