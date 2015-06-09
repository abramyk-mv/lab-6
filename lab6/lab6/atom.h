#pragma once
#include "stdafx.h"

class CAtom
{
public:
	CAtom(void);
	~CAtom(void);
	virtual string GetAtom();
	virtual void SetAtom(string);
	virtual void ShowAtom();
};

