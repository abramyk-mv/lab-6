#pragma once
#include "Atom.h"
#include "string"
using namespace std;
class CAtom_String : public CAtom
{
public:
	CAtom_String(void);
	~CAtom_String(void);

	string GetAtom();
	void SetAtom(string);
	void ShowAtom();
private:
	string value;
};

