/***************************************************************************************************************
*"aplication.h"
*
*
*
*
*
*CONTENTS:
* "Klasa czysto abstrakcyjna dla klas poswieconych interfejsowi, klasa dziecko po klasie enginer"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef APLICATION_H
#define APLICATION_H
#include "../Enginer/enginer.h"
class C_aplication :
	public C_enginer
{
public:
	C_aplication();
	C_aplication(const C_aplication & aplication);
	C_aplication& operator=(const C_aplication& aplication);
	bool operator==(const C_aplication& aplication);
	bool operator!=(const C_aplication& aplication);
	//void m_add_human(C_human human);
	virtual ~C_aplication();
};
#endif // !APLICATION_H



