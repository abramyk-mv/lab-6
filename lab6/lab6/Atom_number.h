#pragma once
#include "atom.h"

class CAtom_Number : public CAtom
{
public:
	CAtom_Number(void);
	~CAtom_Number(void);

	string GetAtom();
	void SetAtom(string);
	void ShowAtom();
private:
	float value;
};