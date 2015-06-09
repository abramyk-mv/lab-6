#pragma once
#include "stdafx.h"

class CAtom
{
public:
	CAtom(void);
	~CAtom(void);
	virtual void GetAtom();
	virtual void SetAtom();
	virtual void ShowAtom();
};