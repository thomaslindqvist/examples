//$Id: Data.h 10 2011-06-11 16:48:12Z home.thomas.lindqvist@gmail.com $
/*! \brief A dummy class to handle data, for test purpose only.
 */

#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include <string>

class Data {
public:
        /**
	 * Constructor
	 * @param n Number of elements in Data::m_data.
	 */
	Data(unsigned int n);

	/**
	 * Destructor.
	 */
	virtual ~Data();

	/**
	 * Print data contents.
	 */
	void print();

private:
        /**
	 * Disabled default constructor.
	 */
	Data();

 	/**
	 * Vector with data content.
	 */      
	std::vector<std::string> m_data;
};

#endif /* DATA_H_ */
