/**	@file: ut_avltree_size.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::size() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include <map>
#include "KaylaTestObject.hpp"

/**	size_type max_size() const */
BOOST_AUTO_TEST_CASE( ut_max_size ) 
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::max_size() const\n";
	std::map<char, int> mapPrimTest;
	avltree<char, int> avlPrimTest;
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;
	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	std::map<int, std::map<int, int>> mapOuterTest;
	avltree<int, std::map<int, int>> avlOuterTest;

	size_t charalloc = avlPrimTest.max_size();
	size_t intalloc = avlObjectTest.max_size();
	size_t doublealloc = avlDoubleStringTest.max_size();
	size_t intallocmap = avlOuterTest.max_size();

	BOOST_CHECK_EQUAL(avlPrimTest.max_size() == charalloc, true);
	BOOST_CHECK_EQUAL(avlObjectTest.max_size() == intalloc, true);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.max_size() == doublealloc, true);
	BOOST_CHECK_EQUAL(avlOuterTest.max_size() == intallocmap, true);	
}



///**	size_type size() const */
BOOST_AUTO_TEST_CASE( ut_size ) 
{
	//-------Primative Check----------------------------
	std::map<int, int> mapPrimTest;
	avltree<int, int> avlPrimTest;

	//Single insert 
	mapPrimTest.insert(std::pair<int, int>(0, 100));
	std::pair<int, int>testpair(0, 100);
	avlPrimTest.insert(testpair);	
	BOOST_CHECK(mapPrimTest.size()== avlPrimTest.size());
	BOOST_CHECK(mapPrimTest.size()== 1);
	BOOST_CHECK(avlPrimTest.size()== 1);
	
	
	//Second insert 
	mapPrimTest.insert(std::pair<char, int>(1, 100));
	std::pair<char, int>testpair6(1, 100);
	avlPrimTest.insert(testpair6);	
	BOOST_CHECK(mapPrimTest.size()== avlPrimTest.size());
	BOOST_CHECK(mapPrimTest.size()== 2);
	BOOST_CHECK(avlPrimTest.size()== 2);
	
	//Multi Insert 
	for(unsigned int i = 0; i < 10; i++)
	{
		mapPrimTest.insert(std::pair<int, int>(i, i));
		std::pair<int, int>testpair(i, i);
		avlPrimTest.insert(testpair);
		
	}
	size_t testsize = 10;
	BOOST_CHECK_EQUAL(mapPrimTest.size(), avlPrimTest.size());
	BOOST_CHECK_EQUAL(mapPrimTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlPrimTest.size(), testsize);


	////Duplicate Insert 
	mapPrimTest.insert(std::pair<char, int>(1, 3));
	std::pair<char, int>testpair1(1,  3);
	avlPrimTest.insert(testpair1);

	BOOST_CHECK_EQUAL(mapPrimTest.size(), avlPrimTest.size());
	BOOST_CHECK_EQUAL(mapPrimTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlPrimTest.size(), testsize);

	//Erase
	mapPrimTest.erase(1);
	avlPrimTest.erase(1);
	testsize = 9;
	BOOST_CHECK_EQUAL(mapPrimTest.size(), avlPrimTest.size());
	BOOST_CHECK_EQUAL(mapPrimTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlPrimTest.size(), testsize);


	////Clear
	mapPrimTest.clear();
	avlPrimTest.clear();
	testsize = 0;
	BOOST_CHECK_EQUAL(mapPrimTest.size(), avlPrimTest.size());
	BOOST_CHECK_EQUAL(mapPrimTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlPrimTest.size(),testsize );


	//-------------------------------------------------------
	

	//------Object Check -------------------------------------	
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;

	KaylaTestObject TestObject;
	testsize = 1;
	mapObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));
	std::pair<int, KaylaTestObject>testpair8(1, TestObject);
	avlObjectTest.insert(testpair8);	
	BOOST_CHECK_EQUAL(mapObjectTest.size(), avlObjectTest.size());
	BOOST_CHECK_EQUAL(mapObjectTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlObjectTest.size(), testsize);
	
	//Second insert 
	testsize = 2;
	mapObjectTest.insert(std::pair<int, KaylaTestObject>(2, TestObject));
	std::pair<char, KaylaTestObject>testpair3(2, TestObject);
	avlObjectTest.insert(testpair3);	
	BOOST_CHECK_EQUAL(mapObjectTest.size(), avlObjectTest.size());
	BOOST_CHECK_EQUAL(mapObjectTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlObjectTest.size(), testsize);
	
	//Multi Insert 
	for(unsigned int i = 0; i <= 99; ++i)
	{
		mapObjectTest.insert(std::pair<int, KaylaTestObject>(i, TestObject ));
		std::pair<int, KaylaTestObject>testpair(i, TestObject);
		avlObjectTest.insert(testpair);
	}
	testsize = 100;
	BOOST_CHECK_EQUAL(mapObjectTest.size(), avlObjectTest.size());
	BOOST_CHECK_EQUAL(mapObjectTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlObjectTest.size(), testsize);


	//Duplicate Insert 
	mapObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));
	std::pair<int, KaylaTestObject>testpair9(1,  TestObject);
	avlObjectTest.insert(testpair9);

	BOOST_CHECK_EQUAL(mapObjectTest.size(), avlObjectTest.size());
	BOOST_CHECK_EQUAL(mapObjectTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlObjectTest.size(), testsize);

	//Erase
	mapObjectTest.erase(1);
	avlObjectTest.erase(1);
	testsize = 99;
	BOOST_CHECK_EQUAL(mapObjectTest.size(), avlObjectTest.size());
	BOOST_CHECK_EQUAL(mapObjectTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlObjectTest.size(), testsize);


	//Clear
	mapObjectTest.clear();
	avlObjectTest.clear();
	testsize = 0;
	BOOST_CHECK_EQUAL(mapObjectTest.size(), avlObjectTest.size());
	BOOST_CHECK_EQUAL(mapObjectTest.size(),testsize);
	BOOST_CHECK_EQUAL(avlObjectTest.size(), testsize);


//	//-------------------------------------------------------
//
//	//-----String Double Check------------------------------------
//		//-------Primative Check----------------------------
	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;

	//Single insert 
	mapDoubleStringTest.insert(std::pair<double, std::string>(1.2, "hello"));
	std::pair<double, std::string>testpair10(1.2, "hello");
	avlDoubleStringTest.insert(testpair10);	
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), avlDoubleStringTest.size());
	testsize = 1;
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(),testsize);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.size(), testsize);
	
	//Second insert 
	mapDoubleStringTest.insert(std::pair<double, std::string>(1.3, "hello" ));
	std::pair<double, std::string>testpair4(1.3, "hello");
	avlDoubleStringTest.insert(testpair4);	
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), avlDoubleStringTest.size());
	testsize = 2;
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.size(), testsize);
	
	//Multi Insert 
	
	for(double i = 0.0; i <=99; ++i)
	{
		mapDoubleStringTest.insert(std::pair<double, std::string>(i, "hello"));
	std::pair<double, std::string>testpair(i, "hello");
		avlDoubleStringTest.insert(testpair);
	}
	
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), avlDoubleStringTest.size());
	testsize = 102;
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.size(), testsize);


	//Duplicate Insert 
	mapDoubleStringTest.insert(std::pair<double,std::string>(1.2, "hello"));
	std::pair<double,std::string>testpair5(1.2,  "hello");
	avlDoubleStringTest.insert(testpair5);

	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), avlDoubleStringTest.size());
	testsize = 102;
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.size(), testsize);


	//Erase
	mapDoubleStringTest.erase(1);
	avlDoubleStringTest.erase(1);
	testsize = 101;
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), avlDoubleStringTest.size());
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.size(), testsize);

//
//	//Clear
	mapDoubleStringTest.clear();
	avlDoubleStringTest.clear();
	testsize = 0;
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), avlDoubleStringTest.size());
	BOOST_CHECK_EQUAL(mapDoubleStringTest.size(), testsize);
	BOOST_CHECK_EQUAL(avlDoubleStringTest.size(), testsize);

//	//std::cout << "NOT IMPLEMENTED: avltree<T>::size() const\n";
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