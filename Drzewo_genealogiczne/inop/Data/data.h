/***************************************************************************************************************
*"data.h"
*
*
*
*
*
*CONTENTS:
* "Klasa bazowa"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     22.04.2017  Orginal design													  £ukasz Witek vel Witkowski 
****************************************************************************************************************/
#ifndef DATA_H
#define DATA_H
#include "../narzedzia/striing.h"
class C_data
{
public:
	C_data(N_striing string);
	C_data(const C_data& data);
	C_data& operator=(const C_data& data);
	bool operator==(const C_data& data);
	bool operator!=(const C_data& data);
	~C_data();
//Methods Virtuals

//Methods Implementate
protected:

private:
	N_striing s_data_text;
};
#endif // !DATA_H
