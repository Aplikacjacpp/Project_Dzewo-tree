/***************************************************************************************************************
*"aplication_txt.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_aplication"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1     09.05.2017  Adding methods for menu										  Mateusz Marchelewicz
*1.2     15.05.2017  Windows size changed										      Mateusz Marchelewicz
*1.3     17.05.2017  Font size changed										          Mateusz Marchelewicz
*1.4     21.05.2017  Menu modified, new methods added								  Mateusz Marchelewicz
*1.5     22.05.2017  Menu modified								                      Mateusz Marchelewicz
*1.6	 10.06.2017	 Add valuue to dystryct private									  Lukasz Witek vel Witkowski
*1.7     27.06.2017  Methods names changed		     								  Mateusz Marchelewicz
****************************************************************************************************************/
#ifndef APLICATION_TXT_H
#define APLICATION_TXT_H
#include "aplication.h"
#include <Windows.h>

using std::cout;
using std::endl;

class C_aplication_txt :
	public C_aplication
{
public:
	C_aplication_txt();			// konstruktor domyslny
	C_aplication_txt(const C_aplication_txt & aplication_txt);		// konstruktor
	C_aplication_txt& operator=(const C_aplication_txt& aplication_txt);	// konstruktor kopiujacy
	bool operator==(const C_aplication_txt& aplication_txt);	// przeciazone operatory
	bool operator!=(const C_aplication_txt& aplication_txt);
	virtual ~C_aplication_txt();						// destruktor
	void m_set_window(int Width, int Height);			// ustawia wymiary okna, czcionke
//	friend char& operator>>(std::iostream& is, char &c);
	void m_main_menu();			// menu glowne
	void m_sub_1();				// podmenu
	void m_sub_menu_2();		// podmenu, edycja, wyswietlanie drzewa
	void m_import_tree();		// import drzewa
	void m_edit_tree();			// edycja drzewa
	void m_display_tree();		// wyswietla drzewo
	void m_search_tree();
	void m_create_logo();		// tworzy "atrape" drzewa
	char m_get_key();
	bool m_what_return();
	bool m_what_menu();
	//Poszczegolne menu:
	void m_menu_name_tree();
	C_human m_menu_add_first_name();
	C_element m_menu_wybor_humana_wskaznikowego();
	void m_menu_add_human();
	C_human m_menu_add_last_name();
	C_human m_menu_add_gender();
	C_human m_menu_add_date();
	void m_menu_relation();
	C_element m_menu_add_relations(int data, C_element Element);
	C_human m_menu_edit_human();
	void m_menu_tree();
private:
	N_vektor<N_striing> Lista; //do wykorzysatnia przy liscie ludzi i dystryktow:)
	N_vektor<C_id> V_ID;
	N_striing name_user_profile;
	void m_load_lista();
	void m_lista(bool b_pointer);
	bool m_what_files();
};
#endif // !APLICATION_TXT_H
