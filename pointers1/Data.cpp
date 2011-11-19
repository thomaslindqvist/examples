//$Id: Data.cpp 10 2011-06-11 16:48:12Z home.thomas.lindqvist@gmail.com $
#include "Data.h"
#include <iostream>

Data::Data(unsigned int n) {
	for(unsigned int i = 0; i < n; i++)
	   m_data.push_back("Testing pointers");

}

Data::~Data() {
	// TODO Auto-generated destructor stub
}

void Data::print(){
	std::cout<<"Print:\n";

	for(std::vector<std::string>::iterator it = m_data.begin(); it != m_data.end(); ++it)
		std::cout << *it << std::endl;
}
