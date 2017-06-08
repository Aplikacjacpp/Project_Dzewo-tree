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
*1.0     22.04.2017  Orginal design													  Lukasz Witek vel Witkowski 
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.3	 02.05.2015	 Adding a method "m_what_type()"							      Lukasz Witek vel Witkowski
*1.4	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef DATA_H
#define DATA_H
#include "../narzedzia/striing.h"
#include "../Helpful/definition.h"
class C_data
{
public:
	C_data(N_striing string);
	C_data(const C_data& data);
	C_data& operator=(const C_data& data);
	bool operator==(const C_data& data);
	bool operator!=(const C_data& data);
//	~C_data();
	virtual ~C_data();
//Methods Virtuals
	virtual bool m_wchat_is()=0;
	virtual void m_get_contens(N_striing &contens) = 0;
	virtual N_striing m_set_contens() = 0;
	virtual int m_set_variable() = 0;
//Methods Implementate
	N_striing m_what_type();
private:
	virtual N_striing m_is_there_contens(N_striing &Word) = 0;
	N_striing s_data_text;
};
#endif // !DATA_H
//dodac metode virtualna zwracajaca wartosc z define.h zaczynajaca sie od 't' np. t_first_name 
//zwracac pod postacia inta