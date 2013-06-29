/**	@file: ut_avltree_count.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::count() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <map>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"

/*
Searches the container for elements with a key equivalent to k and returns the number of matches.

Because all elements in a map container are unique, the function can only return 1 (if the element is found) or zero (otherwise).

*/
/**	size_type count( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_count ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::count()\n";

	KaylaTestObject TestObject;
	
	std::map<char, int> mapcharint;
	avltree<char, int> avlcharint;
	std::map<int, KaylaTestObject> mapinttestobject;
	avltree<int,KaylaTestObject>avlinttestobject;
	std::map<double, std::string> mapdoublestring;
	avltree<double, std::string> avldoublestring;
	
	std::map<int,int> mapintint;
	avltree<int,int>avlintint;

	
	mapdoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	mapinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	avlinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));

	
	BOOST_CHECK_EQUAL(mapdoublestring.count(1.00), avldoublestring.count(1.00) );
	BOOST_CHECK_EQUAL(mapinttestobject.count(1), avlinttestobject.count(1) );
	BOOST_CHECK_EQUAL(mapcharint.count('a'),avlcharint.count('a') );

	size_t testvalue = 1;
	BOOST_CHECK_EQUAL(mapdoublestring.count(1.00), testvalue );
	BOOST_CHECK_EQUAL(mapinttestobject.count(1), testvalue );
	BOOST_CHECK_EQUAL(mapcharint.count('a'),testvalue );
	BOOST_CHECK_EQUAL(avldoublestring.count(1.00),testvalue);
	BOOST_CHECK_EQUAL(avlinttestobject.count(1),testvalue );
	BOOST_CHECK_EQUAL(avlcharint.count('a'),testvalue);

	///////////////////Duplicate entry test ////////////////////////////////////

	mapdoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	avldoublestring.insert (std::pair<double,std::string>(1.0,"Kayla"));
	mapinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	avlinttestobject.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	mapcharint.insert (std::pair<char,int>('a',100));
	avlcharint.insert (std::pair<char,int>('a',100));

	
	BOOST_CHECK_EQUAL(mapdoublestring.count(1.00), avldoublestring.count(1.00) );
	BOOST_CHECK_EQUAL(mapinttestobject.count(1), avlinttestobject.count(1) );
	BOOST_CHECK_EQUAL(mapcharint.count('a'),avlcharint.count('a') );

	
	BOOST_CHECK_EQUAL(mapdoublestring.count(1.00), testvalue );
	BOOST_CHECK_EQUAL(mapinttestobject.count(1), testvalue );
	BOOST_CHECK_EQUAL(mapcharint.count('a'),testvalue );
	
	BOOST_CHECK_EQUAL(avldoublestring.count(1.00),testvalue);
	BOOST_CHECK_EQUAL(avlinttestobject.count(1),testvalue );
	BOOST_CHECK_EQUAL(avlcharint.count('a'),testvalue);

	////////////////////Return of 0 test ////////////////////////////////////////////

	
	BOOST_CHECK_EQUAL(mapdoublestring.count(2.00), avldoublestring.count(2.00) );
	BOOST_CHECK_EQUAL(mapinttestobject.count(2), avlinttestobject.count(2) );
	BOOST_CHECK_EQUAL(mapcharint.count('b'),avlcharint.count('b') );

	testvalue = 0;
	BOOST_CHECK_EQUAL(mapdoublestring.count(2.00), testvalue );
	BOOST_CHECK_EQUAL(mapinttestobject.count(2), testvalue );
	BOOST_CHECK_EQUAL(mapcharint.count('b'),testvalue );
	
	BOOST_CHECK_EQUAL(avldoublestring.count(2.00),testvalue);
	BOOST_CHECK_EQUAL(avlinttestobject.count(2),testvalue );
	BOOST_CHECK_EQUAL(avlcharint.count('b'),testvalue);
}



/*=============================================================

Revision History

Version 0.0.0: 2013-01-16
Alpha release.

=============================================================

Copyright Garth Santor

The copyright to the computer program(s) herein
is the property of Garth Santor of Canada.
The program(s) may be used and/or copied only with
the written permission of Garth Santor
or in accordance with the terms and conditions
stipulated in the agreement/contract under which
the program(s) have been supplied.
=============================================================*/