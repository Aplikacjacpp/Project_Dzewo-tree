/***************************************************************************************************************
*"enginer.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_tree reprezentuje silnik aplikacji"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     01.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef ENGINER_H
#define ENGINER_H
#include "../Databases/tree.h"
#include "sl_date.h"
#include "sl_personalys.h"
#include "sl_relations.h"
class C_enginer :virtual public C_sl_date, virtual public C_sl_personalys, virtual public C_sl_relations
{
public:
	C_enginer();
	C_enginer(const C_enginer &enginer);
	C_enginer& operator=(const C_enginer &enginer);
	bool operator==(const C_enginer &enginer);
	bool operator!=(const C_enginer &enginer);
	virtual ~C_enginer();
	int m_set_index();
	void m_load_files();
	void m_save_files();
	void m_new_human(C_human &human);
	void m_new_element(C_element &element, bool b_what);
	C_element m_create_element(C_id id_finter);
	C_human m_create_human(C_id id_finter);
	C_tree m_create_tree(C_id id_pointer);
	void m_create_new_location(N_striing Data);
	void m_get_index_value_tree(N_striing data);
private:
	void m_printer(int i);
	void m_get_index(int value);
	void m_file_init(bool b_what);
	bool m_add_to_operation(N_striing Data);
	void m_create_file_operation(N_striing Data);
	N_vektor<C_tree> V_tree;
	N_striing index_value_tree;
protected:
	static int i_index;
};
#endif // !ENGINER_H

