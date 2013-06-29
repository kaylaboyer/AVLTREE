/**	@file: ut_avltree_equal_range.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::equal_range() unit tests.
	*/
#define _SCL_SECURE_NO_WARNINGS
#include <boost/test/auto_unit_test.hpp>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"
#include <iostream>
#include <map>

/**	pair <iterator, iterator> equal_range ( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_equal_range )
{
	 std::cout << "NOT IMPLEMENTED: avltree<T>::equal_range()\n";
	//******************************Int, Int*******************************************
	//{
	//	std::map<int,int> mapI;
	//	avltree<int,int> avlI;
	//	for( int i = 1; i != 100; i++ ) {
	//		mapI.insert(std::pair<int,int>(i,i));
	//		avlI.insert(std::pair<int,int>(i,i));
	//	}
	//	for( int i = 1; i != 100; ++i ){
	//		BOOST_CHECK(mapI.equal_range(i).first->first == avlI.equal_range(i).first->first);
	//		BOOST_CHECK(mapI.equal_range(i).first->second == avlI.equal_range(i).first->second);
	//		BOOST_CHECK(mapI.equal_range(i).first->first == i);
	//		BOOST_CHECK(avlI.equal_range(i).first->second == i);
	//		BOOST_CHECK(avlI.equal_range(i).first->first == i);
	//		BOOST_CHECK(mapI.equal_range(i).first->second == i);
	//	}
	//}
	////******************************char, Int*******************************************
	//{
	//	std::map<char,int> mapI;
	//	avltree<char,int> avlI;
	//	for(unsigned char i = 'a'; i != 'a'+100; i++ ) {
	//		mapI.insert(std::pair<char,int>(i,100));
	//		avlI.insert(std::pair<char,int>(i,100));
	//	}
	//	for(unsigned char i = 'a'; i != 'a'+100; i++ ){
	//		BOOST_CHECK(mapI.equal_range(i).first->first == avlI.equal_range(i).first->first);
	//		BOOST_CHECK(mapI.equal_range(i).first->second == avlI.equal_range(i).first->second);
	//		BOOST_CHECK(mapI.equal_range(i).first->second == 100);
	//		BOOST_CHECK(avlI.equal_range(i).first->second == 100);
	//	}
	//}
	////******************************double, string*******************************************
	//{
	//	std::map<double, std::string> mapI;
	//	avltree<double, std::string> avlI;
	//	for( double i = 0.1; i != 100.1; i++ ) {
	//		mapI.insert(std::pair<double, std::string>(i,"test"));
	//		avlI.insert(std::pair<double, std::string>(i,"test"));
	//	}
	//	for( double i = 0.1; i != 100.1; ++i ){
	//		BOOST_CHECK(mapI.equal_range(i).first->first == avlI.equal_range(i).first->first);
	//		BOOST_CHECK(mapI.equal_range(i).first->second == avlI.equal_range(i).first->second);
	//		BOOST_CHECK(mapI.equal_range(i).first->first == i);
	//		BOOST_CHECK(avlI.equal_range(i).first->second == "test");
	//		BOOST_CHECK(avlI.equal_range(i).first->first == i);
	//		BOOST_CHECK(mapI.equal_range(i).first->second == "test");
	//	}
	//}
	//******************************int, object*******************************************
	//{
	//	std::map<int, KaylaTestObject> mapI;
	//	avltree<int, KaylaTestObject> avlI;
	//	KaylaTestObject testObject;
	//	for( int i = 1; i != 100; i++ ) {
	//		mapI.insert(std::pair<int, KaylaTestObject>(i,testObject));
	//		avlI.insert(std::pair<int, KaylaTestObject>(i,testObject));
	//	}
	//	for( int i = 1; i != 100; ++i ){
	//		BOOST_CHECK(mapI.equal_range(i).first->first == avlI.equal_range(i).first->first);
	//		BOOST_CHECK(mapI.equal_range(i).first->second.testString() == avlI.equal_range(i).first->second.testString());
	//		BOOST_CHECK(mapI.equal_range(i).first->first == i);
	//		BOOST_CHECK(avlI.equal_range(i).first->second.testString() == testObject.testString());
	//		BOOST_CHECK(avlI.equal_range(i).first->first == i);
	//		BOOST_CHECK(mapI.equal_range(i).first->second.testString() == testObject.testString());
	//	}
	//}
}


/**	pair <const_iterator, const_iterator> equal_range ( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_equal_range_const )
{
	std::cout << "NOT IMPLEMENTED: avltree<T>::equal_range() const\n";
	//******************************Int, Int*******************************************
	//{
	//	std::map<int,int> mapI;
	//	avltree<int,int> avlI;
	//	for( int i = 1; i != 100; i++ ) {
	//		mapI.insert(std::pair<int,int>(i,i));
	//		avlI.insert(std::pair<int,int>(i,i));
	//	}
	//	
	//	for( int i = 1; i != 100; ++i ){
	//		std::pair<std::map<int,int>::const_iterator, std::map<int,int>::const_iterator> const m = mapI.equal_range(i);
	//		std::pair<avltree<int,int>::const_iterator, avltree<int,int>::const_iterator> const a = avlI.equal_range(i);

	//		BOOST_CHECK(m.first->first == a.first->first);
	//		BOOST_CHECK(m.first->second == a.first->second);
	//		BOOST_CHECK(m.first->first == i);
	//		BOOST_CHECK(a.first->second ==  i);
	//		BOOST_CHECK(a.first->first == i);
	//		BOOST_CHECK(m.first->second == i);
	//	}
	//}
	////******************************char, Int*******************************************
	//{
	//	std::map<char,int> mapI;
	//	avltree<char,int> avlI;
	//	for(unsigned char i = 'a'; i != 'a'+100; i++ ) {
	//		mapI.insert(std::pair<char,int>(i,100));
	//		avlI.insert(std::pair<char,int>(i,100));
	//	}
	//	for(unsigned char i = 'a'; i != 'a'+100; i++ ){
	//		std::pair<std::map<char,int>::const_iterator, std::map<char,int>::const_iterator> const m = mapI.equal_range(i);
	//		std::pair<avltree<char,int>::const_iterator, avltree<char,int>::const_iterator> const a = avlI.equal_range(i);

	//		BOOST_CHECK(m.first->first == a.first->first);
	//		BOOST_CHECK(m.first->second == a.first->second);
	//		BOOST_CHECK(m.first->second == 100);
	//		BOOST_CHECK(a.first->second == 100);
	//	}
	//}
	////******************************double, string*******************************************
	//{
	//	std::map<double, std::string> mapI;
	//	avltree<double, std::string> avlI;
	//	for( double i = 0.1; i != 100.1; i++ ) {
	//		mapI.insert(std::pair<double, std::string>(i,"test"));
	//		avlI.insert(std::pair<double, std::string>(i,"test"));
	//	}
	//	for( double i = 0.1; i != 100.1; ++i ){
	//		std::pair<std::map<double,std::string>::const_iterator, std::map<double,std::string>::const_iterator> const m = mapI.equal_range(i);
	//		std::pair<avltree<double,std::string>::const_iterator, avltree<double,std::string>::const_iterator> const a = avlI.equal_range(i);

	//		BOOST_CHECK(m.first->first == a.first->first);
	//		BOOST_CHECK(m.first->second == a.first->second);
	//		BOOST_CHECK(m.first->first == i);
	//		BOOST_CHECK(a.first->second == "test");
	//		BOOST_CHECK(a.first->first == i);
	//		BOOST_CHECK(m.first->second == "test");
	//	}
	//}
	//******************************int, object*******************************************
	//{
	//	std::map<int, KaylaTestObject> mapI;
	//	avltree<int, KaylaTestObject> avlI;
	//	KaylaTestObject testObject;
	//	for( int i = 1; i != 100; i++ ) {
	//		mapI.insert(std::pair<int, KaylaTestObject>(i,testObject));
	//		avlI.insert(std::pair<int, KaylaTestObject>(i,testObject));
	//	}
	//	for( int i = 1; i != 100; ++i ){
	//		std::pair<std::map<int, KaylaTestObject>::const_iterator, std::map<int, KaylaTestObject>::const_iterator> const m = mapI.equal_range(i);
	//		std::pair<avltree<int, KaylaTestObject>::const_iterator, avltree<int, KaylaTestObject>::const_iterator> const a = avlI.equal_range(i);

	//		BOOST_CHECK(m.first->first == a.first->first);
	//		BOOST_CHECK(m.first->second.testString() == a.first->second.testString());
	//		BOOST_CHECK(m.first->first == i);
	//		BOOST_CHECK(a.first->second.testString() == testObject.testString());
	//		BOOST_CHECK(a.first->first, i);
	//		BOOST_CHECK(m.first->second.testString() == testObject.testString());
	//	}
	//}
	//******************************int, map*******************************************
	//{
	//	std::map<int, std::map<int,int>> mapI;
	//	avltree<int, avltree<int,int>> avlI;
	//	std::map<int,int> innerM;
	//	avltree<int,int> innerA;
	//	innerM.insert(std::pair<int,int>(100,100));
	//	innerA.insert(std::pair<int,int>(100,100));
	//	for( int i = 1; i != 100; i++ ) {
	//		mapI.insert(std::pair<int, std::map<int,int>>(i,innerM));
	//		avlI.insert(std::pair<int, avltree<int,int>>(i,innerA));
	//	}
	//	for( int i = 1; i != 100; ++i ){
	//		std::pair<std::map<int, std::map<int,int>>::const_iterator, std::map<int, std::map<int,int>>::const_iterator> const m = mapI.equal_range(i);
	//		std::pair<avltree<int, avltree<int,int>>::const_iterator, avltree<int, avltree<int,int>>::const_iterator> const a = avlI.equal_range(i);

	//		BOOST_CHECK(m.first->first == a.first->first);
	//		BOOST_CHECK(m.first->first == i);
	//		BOOST_CHECK(a.first->first ==  i);
	//	}
	//}
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