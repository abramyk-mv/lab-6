#pragma once
#include "stdafx.h"

class CAtom
{
public:
	CAtom(void);
	~CAtom(void);
	virtual std::string GetAtom();
	virtual void SetAtom(std::string);
	virtual void ShowAtom();
};

