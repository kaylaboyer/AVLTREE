/**	@file: ut_avltree_operator_assignment.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T> assignment operator unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include <map>
#include "KaylaTestObject.hpp"



/**	avltree& operator=( avltree const& ) */
BOOST_AUTO_TEST_CASE( ut_operator_assign_copy ) {
	//std::cout << "NOT IMPLEMENTED: operator =(&)\n";

	KaylaTestObject TestObject;
	
	std::map<int, int> mapintint1;
	avltree<int, int> avlintint1;
	std::map<int, int> mapintint2;
	avltree<int, int> avlintint2;
	
	std::map<char, int> mapPrimTest1;
	avltree<char, int> avlPrimTest1;
	std::map<char, int> mapPrimTest2;
	avltree<char, int> avlPrimTest2;

	std::map<int,KaylaTestObject> mapObjectTest1;
	avltree<int, KaylaTestObject> avlObjectTest1;
	std::map<int,KaylaTestObject> mapObjectTest2;
	avltree<int, KaylaTestObject> avlObjectTest2;
	
	std::map<double, std::string> mapDoubleStringTest1;
	avltree<double, std::string> avlDoubleStringTest1;
	std::map<double, std::string> mapDoubleStringTest2;
	avltree<double, std::string> avlDoubleStringTest2;
		
	mapintint1[1] = 8;
	mapintint1[2] = 16;
	mapintint1[3] = 32;
	avlintint1[1] = 8;
	avlintint1[2] = 16;
	avlintint1[3] = 32;

 mapintint2 = mapintint1;  
 avlintint2 = avlintint1;  
  

  BOOST_CHECK(avlintint1.size() == avlintint2.size());
  BOOST_CHECK(mapintint1.size() == mapintint2.size());
    
  mapPrimTest1['a'] = 8;
  mapPrimTest1['b'] = 16;
  mapPrimTest1['c'] = 32;
  avlPrimTest1['a'] = 8;
  avlPrimTest1['b'] = 16;
  avlPrimTest1['c'] = 32;
  	
	avlPrimTest2 = avlPrimTest1;
	mapPrimTest2 = mapPrimTest1;
	
	BOOST_CHECK(mapPrimTest1.size() == mapPrimTest2.size());
	BOOST_CHECK(avlPrimTest1.size() == avlPrimTest2.size());

	mapObjectTest1[1] = TestObject;
	avlObjectTest1[1] = TestObject;

	mapObjectTest2 = mapObjectTest1;
	avlObjectTest2 = avlObjectTest1;

	BOOST_CHECK(mapObjectTest1.size() == mapObjectTest2.size());
	BOOST_CHECK(avlObjectTest1.size() == avlObjectTest2.size());

	mapDoubleStringTest1[1.0] = "test";
	mapDoubleStringTest1[2.0] = "test";
	mapDoubleStringTest1[3.0] = "test";
	mapDoubleStringTest1[4.0] = "test";

	avlDoubleStringTest1[1.0] = "test";
	avlDoubleStringTest1[2.0] = "test";
	avlDoubleStringTest1[3.0] = "test";
	avlDoubleStringTest1[4.0] = "test";

	mapDoubleStringTest2 = mapDoubleStringTest1;
	avlDoubleStringTest2 = avlDoubleStringTest1;

	BOOST_CHECK(mapDoubleStringTest2.size() == mapDoubleStringTest1.size());
	BOOST_CHECK(avlDoubleStringTest2.size() == avlDoubleStringTest1.size());

	
}


/**	avltree& operator=( avltree && ) */
BOOST_AUTO_TEST_CASE( ut_operator_assign_move ) {
	//std::cout << "NOT IMPLEMENTED: operator =(&&)\n";

	KaylaTestObject TestObject;
	
	std::map<int, int> mapintint1;
	avltree<int, int> avlintint1;
	std::map<int, int> mapintint2;
	avltree<int, int> avlintint2;

	std::map<char, int> mapPrimTest1;
	avltree<char, int> avlPrimTest1;
	std::map<char, int> mapPrimTest2;
	avltree<char, int> avlPrimTest2;

	std::map<int,KaylaTestObject> mapObjectTest1;
	avltree<int, KaylaTestObject> avlObjectTest1;
	std::map<int,KaylaTestObject> mapObjectTest2;
	avltree<int, KaylaTestObject> avlObjectTest2;
	
	std::map<double, std::string> mapDoubleStringTest1;
	avltree<double, std::string> avlDoubleStringTest1;
	std::map<double, std::string> mapDoubleStringTest2;
	avltree<double, std::string> avlDoubleStringTest2;
		
	std::map<int, std::map<int, int>> mapOuterTest1;
	avltree<int, std::map<int, int>> avlOuterTest1;
	std::map<int, std::map<int, int>> mapOuterTest2;
	avltree<int, std::map<int, int>> avlOuterTest2;
	
	mapintint1[1] = 8;
	mapintint1[2] = 16;
	mapintint1[3] = 32;
	
	avlintint1[1] = 8;
	avlintint1[2] = 16;
	avlintint1[3] = 32;

	mapintint2 = std::move(mapintint1);  
	avlintint2 = std::move(avlintint1);  
  
  
	BOOST_CHECK(mapintint1.size() == 0);
	BOOST_CHECK(avlintint1.size() == 0); 
  
	mapPrimTest1['a'] = 8;
	mapPrimTest1['b'] = 16;
	mapPrimTest1['c'] = 32;
	avlPrimTest1['a'] = 8;
	avlPrimTest1['b'] = 16;
	avlPrimTest1['c'] = 32;
  	
	avlPrimTest2 = std::move(avlPrimTest1);
	mapPrimTest2 = std::move(mapPrimTest1);
	
	BOOST_CHECK(mapPrimTest1.size() == 0);
	BOOST_CHECK(avlPrimTest1.size() == 0);

	mapObjectTest1[1] = TestObject;
	avlObjectTest1[1] = TestObject;

	mapObjectTest2 = std::move(mapObjectTest1);
	avlObjectTest2 = std::move(avlObjectTest1);

	BOOST_CHECK(mapObjectTest1.size() == 0);
	BOOST_CHECK(avlObjectTest1.size() == 0);

	mapDoubleStringTest1[1.0] = "test";
	mapDoubleStringTest1[2.0] = "test";
	mapDoubleStringTest1[3.0] = "test";
	mapDoubleStringTest1[4.0] = "test";

	avlDoubleStringTest1[1.0] = "test";
	avlDoubleStringTest1[2.0] = "test";
	avlDoubleStringTest1[3.0] = "test";
	avlDoubleStringTest1[4.0] = "test";

	mapDoubleStringTest2 = std::move(mapDoubleStringTest1);
	avlDoubleStringTest2 = std::move(avlDoubleStringTest1);

	BOOST_CHECK(mapDoubleStringTest1.size() == 0);
	BOOST_CHECK(avlDoubleStringTest1.size() == 0);

	
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