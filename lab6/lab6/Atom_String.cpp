#include "StdAfx.h"
#include "Atom_String.h"
#include "iostream"
using namespace std;

CAtom_String::CAtom_String(void)
{
}


CAtom_String::~CAtom_String(void)
{
}

string CAtom_String::GetAtom()
{
	return value;
}
void CAtom_String::SetAtom(string arg)
{
	value = arg;
}
void CAtom_String::ShowAtom()
{
	cout << "String - " << value << endl;
}
