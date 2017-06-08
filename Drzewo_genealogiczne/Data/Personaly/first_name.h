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
*1.0     22.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.3     09.05.2017  Adding a overloaded operators									  Mateusz Marchelewicz
*1.4	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
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
	bool operator>(C_first_name &first);
	bool operator<(C_first_name &first);
	friend std::ostream& operator<<(std::ostream& is,const C_first_name &first);
	//~C_first_name();
	virtual ~C_first_name();
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual N_striing m_set_contens();
	virtual int m_set_variable();
protected:
	
private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	N_striing s_data_first_name;
};
#endif // !C_FIRST_NAME_H
