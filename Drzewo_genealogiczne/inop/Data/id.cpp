#include "id.h"
C_id::C_id() :C_data("#0") { s_data_id = ""; }
C_id::C_id(const C_id &id):C_data(id) {
	if (this != &id) *this = id;
}
C_id& C_id::operator=(const C_id &id) {
	if (*this == id) return *this;
	s_data_id = id.s_data_id;
	return *this;
}
bool C_id::operator==(const C_id &id) {
	if (s_data_id == id.s_data_id) return true;
	return false;
}
bool C_id::operator!=(const C_id &id) {
	if (s_data_id != id.s_data_id) return true; 
	return false;
}
C_id::~C_id() {};
