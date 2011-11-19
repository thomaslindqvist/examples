//$Id: Data.h 10 2011-06-11 16:48:12Z home.thomas.lindqvist@gmail.com $
/*! \brief A dummy class to handle threads, for test purpose only.
 */

#ifndef FOO_H_
#define FOO_H_

#include <iostream>

using namespace std;

class Foo{
    public:
        void operator()()
	{
		cout<<"Foo::operator\n";
	}
};

#endif /* FOO_H_ */
