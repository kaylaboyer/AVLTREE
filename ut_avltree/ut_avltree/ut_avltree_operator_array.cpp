/**	@file: ut_avltree_operator_array.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::operator[] unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include <map>
#include "KaylaTestObject.hpp"

/**	Type& operator[]( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_operator_array_key_ref ) {
	//std::cout << "NOT IMPLEMENTED: operator [&]\n";

	char aChar = 'a';
	int aInt = 1;
	double aDouble = 1.0;
	KaylaTestObject test;

	std::map<char, int> mapPrimTest;
	avltree< char, int> avlPrimTest;
	std::map< int,KaylaTestObject> mapObjectTest;
	avltree< int, KaylaTestObject> avlObjectTest;
	std::map< double, std::string> mapDoubleStringTest;
	avltree< double, std::string> avlDoubleStringTest;
	
	mapPrimTest[aChar] = 1;
	avlPrimTest[aChar] = 1;
	mapObjectTest[aInt] = test;
	avlObjectTest[aInt] = test;
	mapDoubleStringTest[aDouble] = "bah";
	avlDoubleStringTest[aDouble] = "bah";

	BOOST_CHECK(mapPrimTest[aChar] == avlPrimTest[aChar]);
	BOOST_CHECK(mapObjectTest[aInt].testString() == "This is a test string.");
	BOOST_CHECK(mapDoubleStringTest[aDouble] == avlDoubleStringTest[aDouble]);
}

/**	Type& operator[]( Key && ) */
BOOST_AUTO_TEST_CASE( ut_operator_array_key_move ) {
	// c2[move(str)] 
	//std::cout << "NOT IMPLEMENTED: operator [&&]\n";
	
	std::string tempstring = "testing string";
	int tempint = 1;
	KaylaTestObject test;
	
	std::map<std::string, int> mapStringInt;
	std::map<std::string, double>mapStringDouble;
	std::map<std::string, KaylaTestObject> mapObjectTest;
	std::map<int,int> mapintint;
	//std::map<std::string, std::map<int,int>> mapofmap;
	
	mapStringInt[std::move(tempstring)] = 1;
	BOOST_CHECK(mapStringInt["testing string"] == 1);
	tempstring = "testing string";
	mapStringDouble[std::move(tempstring)] = 1.0;
	BOOST_CHECK(mapStringDouble["testing string"] == 1);
	tempstring = "testing string";
	mapObjectTest[std::move(tempstring)] = test;
	BOOST_CHECK(mapObjectTest["testing string"].testString() == "This is a test string.");
	
	mapintint[std::move(tempint)] = 100;
	
	BOOST_CHECK(mapintint[1] == 100);
	
	avltree<int, std::string> avlStringInt;
	avltree<double, std::string>avlStringDouble;
	avltree<int,int> avlintint;
	avltree<std::string, std::map<int,int>> avlofmap;
	tempstring = "testing string";
	avlStringInt[std::move(1)] = tempstring;
	BOOST_CHECK(avlStringInt[1] == "testing string");
	tempstring = "testing string";
	avlStringDouble[std::move(1.0)] = tempstring;
	BOOST_CHECK(avlStringDouble[1] == "testing string");
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