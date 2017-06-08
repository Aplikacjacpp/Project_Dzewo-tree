/***************************************************************************************************************
*"first_name.h"
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
#ifndef C_FIRST_NAME_H
#define C_FIRST_NAME_H
#include "data.h"
class C_first_name :public C_data
{
public:
	C_first_name();
	C_first_name(N_striing &first);
	C_first_name(const C_first_name &first);
	C_first_name& operator=(const C_first_name &first);
	bool operator==(const C_first_name &first);
	bool operator!=(const C_first_name &first);
	~C_first_name();
protected:

private:
	N_striing s_data_first_name;
};
#endif // !C_FIRST_NAME_H
