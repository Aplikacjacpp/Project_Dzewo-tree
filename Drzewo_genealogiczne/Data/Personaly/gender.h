/***************************************************************************************************************
*"gender.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     26.04.2017  Orginal design													  Mateusz Marchelewicz
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.3	 02.05.2015	 Adding parameter constructors								      Lukasz Witek vel Witkowski
*1.4	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
****************************************************************************************************************/

#ifndef GENDER_H
#define GENDER_H
#include "data.h"
class C_gender: public C_data
{
public:
	C_gender();
	C_gender(bool gender);
	C_gender(N_striing &gender);
	C_gender(const C_gender &C);
	C_gender& operator=(const C_gender &C);
	bool operator==(const C_gender &C);
	bool operator!=(const C_gender &C);
	friend std::ostream& operator<<(std::ostream& is,const  C_gender &gender);
	virtual ~C_gender();
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual N_striing m_set_contens();
	virtual int m_set_variable();
protected:

private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	N_striing s_data_gender;
};
#endif // !GENDER_H

