/***************************************************************************************************************
*"id.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     22.04.2017  Orginal design													  £ukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef ID_H
#define ID_H
#include "data.h"
class C_id:public C_data
{
public:
	C_id();
	C_id(const C_id &C);
	C_id& operator=(const C_id &C);
	bool operator==(const C_id &C);
	bool operator!=(const C_id &C);
	~C_id();
protected:

private:
	N_striing s_data_id;
};
#endif // !ID_H
