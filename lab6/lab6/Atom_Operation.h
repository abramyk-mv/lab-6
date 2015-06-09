#pragma once
#include "stdafx.h"
#include "Atom.h"
#include "string"
using namespace std;
class CAtom_Operation : public CAtom
{
public:
	CAtom_Operation(void);
	CAtom_Operation (string);
	~CAtom_Operation(void);

	string GetAtom();
	void SetAtom(string);
	void ShowAtom();
private:
	string nameOfOperation;
};

