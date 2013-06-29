///**	@file: ut_avltree_at.cpp
//	@author Garth Santor
//	@author gsantor@fanshaweonline.ca
//	@author http://www.gats.ca/
//	@date 2013-01-16
//	@version 0.0.0
//	@note Developed for C++ 11
//	@brief avltree<T>::at() unit tests.
//	*/
//
#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <map>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"
#include <exception>


//AT: returns a reference to the mapped value of the element identified with the 
//key "k"
//if "key does not match they key of any element in the container, 
//the function throws an out of range exception 

//**	at( Key const& ) 
BOOST_AUTO_TEST_CASE( ut_at_key ) 
{
	//-------Primative Check----------------------------
	std::map<char, int> mapPrimTest;
	avltree<char, int> avlPrimTest;

	//Single insert 
	mapPrimTest.insert(std::pair<char, int>('a', 100));
	avlPrimTest.insert(std::pair<char, int>('a', 100));	
	
	mapPrimTest.at('a') = 30;
	avlPrimTest.at('a') = 30;
		

	BOOST_CHECK_EQUAL(mapPrimTest.at('a'),30);
	BOOST_CHECK_EQUAL(avlPrimTest.at('a'), 30);


	//Erase
	mapPrimTest.erase('a');
	avlPrimTest.erase('a');
	
	BOOST_CHECK_THROW(mapPrimTest.at('a'), std::out_of_range);
	BOOST_CHECK_THROW(avlPrimTest.at('a'), std::out_of_range);

	BOOST_CHECK_THROW(mapPrimTest.at('b'), std::out_of_range);
	BOOST_CHECK_THROW(avlPrimTest.at('b'), std::out_of_range);

//	//-------------------------------------------------------
	

//	//------Object Check -------------------------------------	
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;

	KaylaTestObject TestObject;

	mapObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));
	avlObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));	

	KaylaTestObject TestObject2;

	mapObjectTest.at(1) = TestObject2;
	avlObjectTest.at(1) = TestObject2;
	
	//Erase
	mapObjectTest.erase(1);
	avlObjectTest.erase(1);
	BOOST_CHECK_THROW(mapObjectTest.at(1), std::out_of_range);
	BOOST_CHECK_THROW(avlObjectTest.at(1), std::out_of_range);

	BOOST_CHECK_THROW(mapPrimTest.at(2), std::out_of_range);
	BOOST_CHECK_THROW(avlPrimTest.at(2), std::out_of_range);
//	//-------------------------------------------------------
//
//	//-----String Double Check------------------------------------

	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;

	mapDoubleStringTest.insert(std::pair<double, std::string>(1.1, "hello"));
	avlDoubleStringTest.insert(std::pair<double, std::string>(1.1, "hello"));	
	
	mapDoubleStringTest.at(1.1) = "hello world";
	avlDoubleStringTest.at(1.1) = "hello world";
		
	BOOST_CHECK_EQUAL(mapDoubleStringTest.at(1.1),"hello world");
	BOOST_CHECK_EQUAL(avlDoubleStringTest.at(1.1), "hello world");


	//Erase
	mapDoubleStringTest.erase(1.1);
	avlDoubleStringTest.erase(1.1);
	
	BOOST_CHECK_THROW(mapDoubleStringTest.at(1.1), std::out_of_range);
	BOOST_CHECK_THROW(avlDoubleStringTest.at(1.1), std::out_of_range);

	BOOST_CHECK_THROW(mapDoubleStringTest.at(1.11), std::out_of_range);
	BOOST_CHECK_THROW(avlDoubleStringTest.at(1.11), std::out_of_range);
//	//-------------------------------------------------------

	//std::cout << "NOT IMPLEMENTED: avltree<T>::at( Key const& )\n";
}

///**	at( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_at_key_const ) 
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::at( Key const& ) const\n";
	//-------Primative Check----------------------------
	std::map<char, int> mapPrimTest;
	avltree<char, int> avlPrimTest;
	const char& ch = 'a';
	//Single insert 
	mapPrimTest.insert(std::pair<char, int>(ch, 100));
	avlPrimTest.insert(std::pair<char, int>(ch, 100));	
	
	mapPrimTest.at(ch) = 30;
	avlPrimTest.at(ch) = 30;
		

	BOOST_CHECK_EQUAL(mapPrimTest.at(ch),30);
	BOOST_CHECK_EQUAL(avlPrimTest.at(ch), 30);


	//Erase
	mapPrimTest.erase(ch);
	avlPrimTest.erase(ch);
	
	BOOST_CHECK_THROW(mapPrimTest.at(ch), std::out_of_range);
	BOOST_CHECK_THROW(avlPrimTest.at(ch), std::out_of_range);

	char const& b_ch = 'b';
	BOOST_CHECK_THROW(mapPrimTest.at(b_ch), std::out_of_range);
	BOOST_CHECK_THROW(avlPrimTest.at(b_ch), std::out_of_range);

	//-------------------------------------------------------
	

	//------Object Check -------------------------------------	
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;

	KaylaTestObject TestObject;
	const int& myInt = 1;
	mapObjectTest.insert(std::pair<int, KaylaTestObject>(myInt, TestObject));
	avlObjectTest.insert(std::pair<int, KaylaTestObject>(myInt, TestObject));	

	KaylaTestObject TestObject2;

	mapObjectTest.at(myInt) = TestObject2;
	avlObjectTest.at(myInt) = TestObject2;
	
	//Erase
	mapObjectTest.erase(myInt);
	avlObjectTest.erase(myInt);
	BOOST_CHECK_THROW(mapObjectTest.at(myInt), std::out_of_range);
	BOOST_CHECK_THROW(avlObjectTest.at(myInt), std::out_of_range);
	const int& myInt2 = 2;


	BOOST_CHECK_THROW(mapObjectTest.at(myInt2), std::out_of_range);
	BOOST_CHECK_THROW(avlObjectTest.at(myInt2), std::out_of_range);
	//-------------------------------------------------------

	//-----String Double Check------------------------------------

	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	const double&   myDouble = 1.1;
	const double&  myDouble2 = 1.11;
	mapDoubleStringTest.insert(std::pair<double, std::string>(myDouble, "hello"));
	avlDoubleStringTest.insert(std::pair<double, std::string>(1.1, "hello"));	
	
	mapDoubleStringTest.at(myDouble) = "hello world";
	avlDoubleStringTest.at(myDouble) = "hello world";
		
	BOOST_CHECK_EQUAL(mapDoubleStringTest.at(myDouble),"hello world");
	BOOST_CHECK_EQUAL(avlDoubleStringTest.at(myDouble), "hello world");

	//Erase
	mapDoubleStringTest.erase(myDouble);
	avlDoubleStringTest.erase(myDouble);
	
	BOOST_CHECK_THROW(mapDoubleStringTest.at(myDouble), std::out_of_range);
	BOOST_CHECK_THROW(avlDoubleStringTest.at(myDouble), std::out_of_range);

	BOOST_CHECK_THROW(mapDoubleStringTest.at(myDouble2), std::out_of_range);
	BOOST_CHECK_THROW(avlDoubleStringTest.at(myDouble2), std::out_of_range);
	
//
}
//
//
//
///*=============================================================
//
//Revision History
//
//Version 0.0.0: 2013-01-16
//Alpha release.
//
//=============================================================
//
//Copyright Garth Santor
//
//The copyright to the computer program(s) herein
//is the property of Garth Santor of Canada.
//The program(s) may be used and/or copied only with
//the written permission of Garth Santor
//or in accordance with the terms and conditions
//stipulated in the agreement/contract under which
//the program(s) have been supplied.
//=============================================================*/