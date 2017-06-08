/***************************************************************************************************************
*"year.h"
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
*1.1	 02.05.2015	 shift name variable										      Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.3	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.4	 02.05.2015	 Adding parameter constructors								      Lukasz Witek vel Witkowski
*1.5	 12.05.2015	 Redbuind m_is_there_contens									  Lukasz Witek vel Witkowski
*1.6	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
****************************************************************************************************************/
//

#ifndef YEAR_H
#define YEAR_H
#include "../Personaly/data.h"
class C_year: public C_data
{
public:
	C_year();
	C_year(N_striing &year);
	C_year(int year);
	C_year(const C_year &C);
	C_year& operator=(const C_year &C);
	bool operator==(const C_year &C);
	bool operator!=(const C_year &C);
	virtual ~C_year();
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual int m_set_variable();
	void m_get_year(N_striing &contens);
	N_striing m_year_set();
private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	virtual N_striing m_set_contens();
protected:
	int m_set_value_year();
	void m_get_value_year(int value);
	int i_data_year;
};
#endif // !year_H




