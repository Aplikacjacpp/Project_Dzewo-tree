#include "first_name.h"
C_first_name::C_first_name():C_data("$0"){
	s_data_first_name = "";
}
C_first_name::C_first_name(N_striing &first):C_data("$0") {
	s_data_first_name = first;
}
C_first_name::C_first_name(const C_first_name &first_name):C_data(first_name) {
	if (this != &first_name) *this = first_name;
}
C_first_name& C_first_name::operator=(const C_first_name &first_name) {
	if (*this == first_name) return *this;
	s_data_first_name = first_name.s_data_first_name;
	return *this;
}
bool C_first_name::operator==(const C_first_name &first_name) {
	if (s_data_first_name == first_name.s_data_first_name) return true;
	return false;
}
bool C_first_name::operator!=(const C_first_name &first_name) {
	if (s_data_first_name != first_name.s_data_first_name) return true; 
	return false;
}
C_first_name::~C_first_name() {};
