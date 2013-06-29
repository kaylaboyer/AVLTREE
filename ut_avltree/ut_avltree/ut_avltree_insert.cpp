/**	@file: ut_avltree_insert.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::insert() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <map>
#include "KaylaTestObject.hpp"
#include "avltree.hpp"



/**	pair<iterator,bool> insert( value_type const& ) */
BOOST_AUTO_TEST_CASE( ut_insert_value ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::insert(value)\n";
	
	KaylaTestObject TestObject;
	
	std::map<int, int> mapintint;
	avltree<int, int> avlintint;

	std::map<char, int> mapPrimTest;
	avltree<char, int> avlPrimTest;
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;
	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	std::map<int, std::map<int, int>> mapOuterTest;
	avltree<int,avltree<int, int>> avlOuterTest;

	mapPrimTest.insert(std::pair<char, int>('a',100));
	mapPrimTest.insert(std::pair<char,int>('b', 200));
	mapPrimTest['c'] = 200;

	avlPrimTest.insert(std::pair<char, int>('a', 100));
	avlPrimTest.insert(std::pair<char, int>('b', 200));
	avlPrimTest['c'] = 200;

	BOOST_CHECK(avlPrimTest['a'] == mapPrimTest['a']);
	BOOST_CHECK(avlPrimTest['b'] == mapPrimTest['b']);
	BOOST_CHECK(avlPrimTest['c'] == mapPrimTest['c']);
	
	
	
	mapObjectTest.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	avlObjectTest.insert (std::pair<int,KaylaTestObject>(1,TestObject));
	mapObjectTest.insert (std::pair<int,KaylaTestObject>(2,TestObject));
	avlObjectTest.insert (std::pair<int,KaylaTestObject>(2,TestObject));
	mapObjectTest[3] = TestObject;
	avlObjectTest[3] = TestObject;

	BOOST_CHECK(mapObjectTest[1] == avlObjectTest[1]);
	BOOST_CHECK(avlObjectTest[2] == mapObjectTest[2]);
	BOOST_CHECK(avlObjectTest[3] == mapObjectTest[3]);

	mapDoubleStringTest.insert(std::pair<double, std::string>(1.0, "test"));
	avlDoubleStringTest.insert(std::pair<double, std::string>(1.0, "test"));

	mapDoubleStringTest.insert(std::pair<double, std::string>(2.0, "testing"));
	avlDoubleStringTest.insert(std::pair<double, std::string>(2.0, "testing"));

	mapDoubleStringTest[3.0] = "testing again";
	avlDoubleStringTest[3.0] = "testing again";

	BOOST_CHECK(mapDoubleStringTest[1.0] == avlDoubleStringTest[1.0]);
	BOOST_CHECK(mapDoubleStringTest[2.0] == avlDoubleStringTest[2.0]);
	BOOST_CHECK(mapDoubleStringTest[3.0] == avlDoubleStringTest[3.0]);

	


}


/**	iterator insert( iterator, value_type const& ) */

BOOST_AUTO_TEST_CASE( ut_insert_iterator_value ) {
//	//std::cout << "NOT IMPLEMENTED: avltree<T>::insert(iterator,value)\n";
	
	KaylaTestObject TestObject;
	
	std::map<char, int> mapPrimTest;
	avltree<char, int> avlPrimTest;
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;
	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	std::map<int, std::map<int, int>> mapOuterTest;
	avltree<int, std::map<int, int>> avlOuterTest;
		
	std::map<char,int>::iterator it = mapPrimTest.begin();
	  
	mapPrimTest.insert (it, std::pair<char,int>('c',400)); 
	mapPrimTest.insert (it, std::pair<char,int>('b',300));
	
	avltree<char,int>::iterator avlit = avlPrimTest.begin();
	
	std::pair<char, int> toInsert = std::make_pair('b', 300);
	std::pair<char, int> toInsert2 = std::make_pair('c', 400);
	avlPrimTest.insert (avlit, toInsert);
	avlPrimTest.insert (avlit, toInsert2);

	BOOST_CHECK(mapPrimTest['b'] == avlPrimTest['b']);
	BOOST_CHECK(mapPrimTest['c'] == avlPrimTest['c']);

	std::map<int,KaylaTestObject>::iterator ittest = mapObjectTest.begin();
	avltree<int,KaylaTestObject>::iterator avlittest = avlObjectTest.begin();

	mapObjectTest.insert (ittest, std::pair<int,KaylaTestObject>(1, TestObject));
	mapObjectTest.insert (ittest, std::pair<int,KaylaTestObject>(2, TestObject));

	std::pair<int, KaylaTestObject> toInsert3 = std::make_pair('b', 300);
	std::pair<int, KaylaTestObject> toInsert4 = std::make_pair('c', 400);
	avlObjectTest.insert (avlittest, toInsert3);
	avlObjectTest.insert (avlittest, toInsert4);

	BOOST_CHECK(mapObjectTest[1] == avlObjectTest[1]);
	BOOST_CHECK(mapObjectTest[2] == avlObjectTest[2]);

	std::map<double, std::string>::iterator itmapdoublestring = mapDoubleStringTest.begin();
	avltree<double, std::string>::iterator itavltreedoublestring = avlDoubleStringTest.begin();

	mapDoubleStringTest.insert( itmapdoublestring, std::pair<double, std::string>(1.0, "AB"));
	mapDoubleStringTest.insert( itmapdoublestring, std::pair<double, std::string>(2.0, "ABBA"));

	std::pair<double, std::string> toInsert5 = std::make_pair(1.0, "AB");
	std::pair<double, std::string> toInsert6 = std::make_pair(2.0, "ABBA");
	avlDoubleStringTest.insert(itavltreedoublestring, toInsert5);
	avlDoubleStringTest.insert(itavltreedoublestring, toInsert6);

	BOOST_CHECK_EQUAL(mapDoubleStringTest[1.0], avlDoubleStringTest[1.0]);
	BOOST_CHECK_EQUAL(mapDoubleStringTest[2.0], avlDoubleStringTest[2.0]);
	
}


///**	template <class InputIterator> void insert( InputIterator, InputIterator ) */
//
BOOST_AUTO_TEST_CASE( ut_insert_iterator_iterator ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::insert(iterator,iterator)\n";
	
	std::map<char, int> mapCharIntSource;
	avltree<char, int> avlCharIntSource;
	std::map<char, int> mapCharIntDestination;
	avltree<char, int> avlCharIntDestination;
	
	for(unsigned char i = 0; i < 99; ++i)
	{
	mapCharIntSource['a'+i] = 100;
	avlCharIntSource['a'+i] = 100;
	}

	mapCharIntDestination.insert(mapCharIntSource.begin(), mapCharIntSource.find('b'));
	avlCharIntDestination.insert(avlCharIntSource.begin(), avlCharIntSource.find('b'));
	mapCharIntDestination.insert(mapCharIntSource.begin(), mapCharIntSource.find('c'));
	avlCharIntDestination.insert(avlCharIntSource.begin(), avlCharIntSource.find('c'));

	BOOST_CHECK(100 == avlCharIntDestination['a']);
	BOOST_CHECK(100 == avlCharIntDestination['b']);

	
}



//**	template <class ValTy> pair<iterator,bool> insert( ValTy && ) */

BOOST_AUTO_TEST_CASE( ut_insert_T_move ) {
	std::cout << "NOT IMPLEMENTED: avltree<T>::insert(&&)\n";
	
	//KaylaTestObject TestObject;
	//
	//std::map<int, int&> mapintint;
	//avltree<int, int&> avlintint;
	//std::map<double, std::string&> mapDoubleStringTest;
	//avltree<double, std::string&> avlDoubleStringTest;
	//	
	//int testint = 100;
	//std::string teststring = "String";

	//mapintint.insert(std::pair<int, int&>(1,testint));
	//avlintint.insert(std::pair<int, int&>(1,testint));

	//std::map<int, int&>::iterator mapintint_it;
	//avltree<int, int&>::iterator avlintint_it;
	//
	//std::map<double, std::string&>::iterator mapDoubleStringTest_it;
	//avltree<double,std::string&>::iterator avlDoubleStringTest_it;

	//mapintint_it = mapintint.begin();
	//avlintint_it = avlintint.begin();
	//
	//mapDoubleStringTest.insert(std::pair<double, std::string&>(1.0, teststring));
	//avlDoubleStringTest.insert(std::pair<double, std::string&>(1.0, teststring));

	//mapDoubleStringTest_it = mapDoubleStringTest.begin();
	//avlDoubleStringTest_it = avlDoubleStringTest.begin();
	//	
	//BOOST_CHECK_EQUAL(avlintint_it->first, mapintint_it->first);
	//BOOST_CHECK_EQUAL(mapDoubleStringTest_it->first, avlDoubleStringTest_it->first);
	
}



///**	template <class ValTy> pair<iterator,bool> insert( const_iterator, ValTy && ) */

BOOST_AUTO_TEST_CASE( ut_insert_iterator_T_move ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::insert(iterator,&&)\n";
	
	std::map<char, int> mapCharIntSource;
	avltree<char, int> avlCharIntSource;
	std::map<char, int> mapCharIntDestination;
	avltree<char, int> avlCharIntDestination;

	for(unsigned char i = 0; i < 10; ++i)
	{
	mapCharIntSource['a'+i] = 100;
	avlCharIntSource['a'+i] = 100;
	}

	std::pair<char,int> dapair('z',500);

	std::map<char, int>::iterator mapCharInt_it;
	avltree<char, int>::iterator avlCharInt_it;

	mapCharInt_it = mapCharIntSource.begin();
	avlCharInt_it = avlCharIntSource.begin();

	mapCharIntSource.insert(mapCharIntSource.begin(), dapair);
	avlCharIntSource.insert(avlCharInt_it,dapair);
	
	
	BOOST_CHECK(500 ==  avlCharIntSource['z']);
	
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