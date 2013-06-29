/**	@file: ut_avltree_empty.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::empty() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include <map>
#include "KaylaTestObject.hpp"

/*
Returns whether the map container is empty (i.e. whether its size is 0).

This function does not modify the container in any way. To clear the content of a map container, see map::clear.

*/

/**	bool empty() const */
BOOST_AUTO_TEST_CASE( ut_empty ) {
//	//std::cout << "NOT IMPLEMENTED: avltree<T>::empty() const\n";
//
	KaylaTestObject TestObject;
	std::map<char, int> mapPrimTest;
	avltree<char, int> avlPrimTest;
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;
	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	std::map<int, std::map<int, int>> mapOuterTest;
	avltree<int, std::map<int, int>> avlOuterTest;
	std::map<int, int> mapInnerTest;
	avltree<int,int> avlInnerTest;
	
	

	BOOST_CHECK_EQUAL(mapPrimTest.empty(), true);
	BOOST_CHECK_EQUAL(avlPrimTest.empty(), true);
	BOOST_CHECK_EQUAL(mapObjectTest.empty(), true);
	BOOST_CHECK_EQUAL(avlObjectTest.empty(), true);
	BOOST_CHECK_EQUAL(mapDoubleStringTest.empty(), true);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.empty(), true);
	BOOST_CHECK_EQUAL(mapOuterTest.empty(), true);
	BOOST_CHECK_EQUAL(avlOuterTest.empty(), true);

	mapPrimTest.insert(std::pair<char, int>('a', 100));
	avlPrimTest.insert(std::pair<char, int>('a', 100));	
	mapObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));
	avlObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));
	mapDoubleStringTest.insert(std::pair<double, std::string>(1.0, "Kayla"));
	avlDoubleStringTest.insert(std::pair<double, std::string>(1.0, "Kayla"));
	mapPrimTest.insert(std::pair<char, int>('b', 100));
	avlPrimTest.insert(std::pair<char, int>('b', 100));	

	BOOST_CHECK_EQUAL(mapPrimTest.empty(), false);
	BOOST_CHECK_EQUAL(avlPrimTest.empty(), false);
	BOOST_CHECK_EQUAL(mapObjectTest.empty(), false);
	BOOST_CHECK_EQUAL(avlObjectTest.empty(), false);
	BOOST_CHECK_EQUAL(mapDoubleStringTest.empty(), false);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.empty(), false);
	
	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapPrimTest.insert(std::pair<char, int>('a' + i, i));
		avlPrimTest.insert(std::pair<char, int>('a' + i, i));
		mapObjectTest.insert(std::pair<int,KaylaTestObject>(1+i,TestObject));
		avlObjectTest.insert(std::pair<int,KaylaTestObject>(1+i,TestObject));
		mapPrimTest.insert(std::pair<char, int>('a'+i, 100));
	avlPrimTest.insert(std::pair<char, int>('a'+i, 100));	
	}
	for(double i = 0.00; i <= 99.00; ++i)
	{
		mapDoubleStringTest.insert(std::pair<double, std::string>(i, "Kayla"));
		avlDoubleStringTest.insert(std::pair<double, std::string>(i, "Kayla"));
	}

	BOOST_CHECK_EQUAL(mapPrimTest.empty(), false);
	BOOST_CHECK_EQUAL(avlPrimTest.empty(), false);
	BOOST_CHECK_EQUAL(mapObjectTest.empty(), false);
	BOOST_CHECK_EQUAL(avlObjectTest.empty(), false);
	BOOST_CHECK_EQUAL(mapDoubleStringTest.empty(), false);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.empty(), false);
	
	

	mapPrimTest.clear();
	avlPrimTest.clear();
	mapObjectTest.clear();
	avlObjectTest.clear();
	mapDoubleStringTest.clear();
	avlDoubleStringTest.clear();
	mapOuterTest.clear();
	avlOuterTest.clear();

	BOOST_CHECK_EQUAL(mapPrimTest.empty(), true);
	BOOST_CHECK_EQUAL(avlPrimTest.empty(), true);
	BOOST_CHECK_EQUAL(mapObjectTest.empty(), true);
	BOOST_CHECK_EQUAL(avlObjectTest.empty(), true);
	BOOST_CHECK_EQUAL(mapDoubleStringTest.empty(), true);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.empty(), true);
	
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