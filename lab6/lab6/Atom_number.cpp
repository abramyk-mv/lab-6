#pragma once
#include "stdafx.h"
#include "Atom_number.h"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

CAtom_Number::CAtom_Number(void)
{
	value = 0;
};

CAtom_Number::~CAtom_Number(void)
{};

string CAtom_Number::GetAtom()
{
	ostringstream buff;
	buff << value;
	return buff.str();
}
void CAtom_Number::SetAtom(string arg)
{
	value = atof(arg.c_str());
}
void CAtom_Number::ShowAtom()
{
	cout << "Number - " << value << std::endl;
}