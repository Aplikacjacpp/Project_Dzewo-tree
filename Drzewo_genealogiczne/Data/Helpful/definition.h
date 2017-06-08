/***************************************************************************************************************
*"definition.h"
*
*
*
*
*
*CONTENTS:
* "Definicje header'ów klas"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     09.05.2017  Orginal design													  			Lukasz Janus
****************************************************************************************************************/

#ifndef DEFINITON_H
#define DEFINITON_H

//definition from type - dane
#define n_first_name "$0"
#define n_last_name  "&0"
#define n_gender   "!0"
#define n_parent   "r0"
#define n_day   "D0"
#define n_month   "D1"
#define n_year   "D2"
#define n_id_personaly "d0"
#define n_id_data   "d0"
#define n_id_relation   "d0"
#define n_children   "r1"
#define n_sibling   "r2"
#define n_grandparent   "r3"
#define n_grandchildren   "r4"
#define n_partner "r5"
#define n_order   "r6"
#define n_gender_personaly   "~0"
#define n_gender_date   "~1"
#define n_gender_relation "~2"
//definition from type - typ
#define t_first_name   36
#define t_last_name   38 //
#define t_gender   33
#define t_parent   114
#define t_day   68
#define t_month   69
#define t_year   70
#define t_id_personaly   148
#define t_id_data   149
#define t_id_relation   157	//
#define t_children   115
#define t_sibling   116
#define t_grandparent   117
#define t_grandchildren   118
#define t_partner 119
#define t_order   120
#define t_gender_personaly   174
#define t_gender_date   175
#define t_gender_relation   183 // 
//definition from file
#define f_save_data "data.save"
#define f_save_relation "relation.save"
#define f_save_date "date.save"
#define f_init_file "file"
#define f_end_file "#@#@#@#@#@#@#@#@#@"
#define k_atribut_order '/'
//definicje from type relation
#define w_children_boy "Syn"
#define w_children_girl "Corka" //wstawic o z kreska
#define w_grandchildren_boy "Wnok" //wstawic o z kreska
#define w_grandchildren_girl "Wnoczka" //wstawic o z kreska
#define w_grandparents_boy "Dziadek" 
#define w_grandparents_girl "Babcia" 
#define w_parent_boy "Ojciec"
#define w_parent_girl "Matka"
#define w_partner_boy "Maz" //polskie litery
#define w_partner_girl "Zona"  //polskie litery
#define w_sibling_boy "Brat"
#define w_sibling_girl "Siostra"
// parametry do interfejsu drzewa
#define p_grandparent_1 1
#define p_grandparent_2 2
#define p_grandparent_3 4
#define p_grandparent_4 8
#define p_parent_1 1
#define p_parent_2 2
#define p_sibling_1 1
#define p_sibling_2 2
#define p_partner_1 1
#define p_partner_2 2
#define p_children_1 1
#define p_children_2 2
#define p_children_3 4
#define p_children_4 8
#define p_grandchildren_1 1
#define p_grandchildren_2 2
#define p_grandchildren_3 4
#define p_grandchildren_4 8

#endif // !DEFINITON_H
