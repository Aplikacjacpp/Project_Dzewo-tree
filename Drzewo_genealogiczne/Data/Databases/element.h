/***************************************************************************************************************
*"element.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_human zawiera tablice dynamiczna relacji"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     01.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 03.05.2015	 adding methods												      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef ELEMENT_H
#define ELEMENT_H
#include "human.h"
#include "../Relation/children.h"
#include "../Relation/sibling.h"
#include "../Relation/parent.h"
#include "../Relation//grandchildren.h"
#include "../Relation//grandparents.h"
#include "../Relation/partner.h"
#include "../Relation/order.h"
class C_element
{
public:
	C_element();
	C_element(const C_human& human);
	C_element(const C_element &human);
	C_element& operator=(const C_element &human);
	bool operator==(const C_element &human);
	bool operator!=(const C_element &human);
	void m_get_children(C_children &children);
	void m_get_parent(C_parent &parent);
	void m_get_sibling(C_sibling &sibling);
	void m_get_grandchildren(C_grandchildren &grandchildren);
	void m_get_grandparents(C_grandparents &grandparents);
	void m_get_partner(C_partner &partner);
	void m_get_order(C_order &order);
	void m_update_children(int value,C_children &children);
	void m_update_parent(int value,C_parent &parent);
	void m_update_sibling(int value,C_sibling &sibling);
	void m_update_human(const C_human &human);
	void m_update_grandchildren(int value, C_grandchildren &human);
	void m_update_grandparents(int value, C_grandparents &human);
	void m_update_partner(int value, C_partner &partner);
	void m_update_order(int value, C_order &order);
	C_human m_set_Human();
	C_children m_set_children();
	C_parent m_set_parent();
	C_sibling m_set_sibling();
	C_partner m_set_partner();
	C_grandchildren m_set_grandchildren();
	C_grandparents m_set_grandparents();
	C_order m_set_order();
	C_children m_set_children(int value);
	C_parent m_set_parent(int value);
	C_sibling m_set_sibling(int value);
	C_grandchildren m_set_grandchildren(int value);
	C_grandparents m_set_grandparents(int value);
	C_partner m_set_partner(int value);
	C_order m_set_order(int value);
	C_element& m_clean();
	void m_clean_children();
	void m_clean_parent();
	void m_clean_sibling();
	void m_clean_grandparents();
	void m_clean_grandchildren();
	void m_clean_partner();
	void m_clean_order();
	void m_delete_children();
	void m_delete_parent();
	void m_delete_sibling();
	void m_delete_partner();
	void m_delete_order();
	void m_delete_children(int value);
	void m_delete_parent(int value);
	void m_delete_sibling(int value);
	void m_delete_grandchildren(int value);
	void m_delete_grandparents(int value);
	void m_delete_partner(int value);
	void m_delete_order(int value);
	N_vektor<C_grandparents> m_set_v_grandparents();
	N_vektor<C_grandchildren> m_set_v_grandchildren();
	N_vektor<C_parent> m_set_v_parent();
	N_vektor<C_children> m_set_v_children();
	N_vektor <C_partner> m_set_v_partner();
	N_vektor<C_sibling> m_set_v_sibling();
	N_vektor <C_order> m_set_v_order();
	//~C_element();
	virtual ~C_element();
protected:
	C_human Human;
private:
	N_vektor<C_children> V_children;
	N_vektor<C_parent> V_parent;
	N_vektor<C_sibling> V_sibling;//trzeba przetestowac czy dziala, jak nie to cos wymysle!!
	N_vektor<C_grandchildren> V_grandchildren;
	N_vektor <C_grandparents> V_grandparents;
	N_vektor <C_partner> V_partner;
	N_vektor <C_order> V_order;
};
#endif // !ELEMENT_H




