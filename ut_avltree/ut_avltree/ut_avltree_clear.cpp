/**	@file: ut_avltree_clear.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::clear() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "KaylaTestObject.hpp"
#include "avltree.hpp"
#include <map>

//removes all elements from the map container (which are 
//destroyed leaving the container with a size of 0 

/**	void clear() */
BOOST_AUTO_TEST_CASE( ut_clear ) 
{
	//insert some values into a map. 
	//-------Primative Check----------------------------
	std::map<char, int> mapPrimTest;
	avltree<char, int> avlPrimTest;

	//clear an empty map 
	mapPrimTest.clear();
	avlPrimTest.clear();

	BOOST_CHECK(mapPrimTest.size() == avlPrimTest.size());
	BOOST_CHECK(mapPrimTest.size() == 0);
	BOOST_CHECK(avlPrimTest.size() == 0);
	BOOST_CHECK(mapPrimTest.empty() == true);
	BOOST_CHECK(avlPrimTest.empty() == true);

	//Insert into map, avl and clear. 
	mapPrimTest.insert(std::pair<char, int>('a', 100));
	avlPrimTest.insert(std::pair<char, int>('a', 100));		
	mapPrimTest['b'] = 30;
	avlPrimTest['b'] = 30;	
	mapPrimTest.emplace('c', 20);
	avlPrimTest.emplace('c', 20);
	
	BOOST_CHECK(mapPrimTest.size() == avlPrimTest.size());
	BOOST_CHECK(mapPrimTest.size() == 3);
	BOOST_CHECK(avlPrimTest.size() == 3);
	BOOST_CHECK(mapPrimTest.empty() == false);
	BOOST_CHECK(avlPrimTest.empty() == false);

	mapPrimTest.clear();
	avlPrimTest.clear();

	BOOST_CHECK(mapPrimTest.size() == avlPrimTest.size());
	BOOST_CHECK(mapPrimTest.size() == 0);
	BOOST_CHECK(avlPrimTest.size() == 0);
	BOOST_CHECK(mapPrimTest.empty() == true);
	BOOST_CHECK(avlPrimTest.empty() == true);

	mapPrimTest.insert(std::pair<char, int>('a', 100));
	avlPrimTest.insert(std::pair<char, int>('a', 100));		
	mapPrimTest['b'] = 30;
	avlPrimTest['b'] = 30;	

	//Erase some, then clear. 
	mapPrimTest.erase('a');
	avlPrimTest.erase('a');
	BOOST_CHECK(mapPrimTest.size() == avlPrimTest.size());
	BOOST_CHECK(mapPrimTest.size() == 1);
	BOOST_CHECK(avlPrimTest.size() == 1);
	BOOST_CHECK(mapPrimTest.empty() == false);
	BOOST_CHECK(avlPrimTest.empty() == false);

	//clear an empty map 
	mapPrimTest.clear();
	avlPrimTest.clear();
	BOOST_CHECK(mapPrimTest.size() == avlPrimTest.size());
	BOOST_CHECK(mapPrimTest.size() == 0);
	BOOST_CHECK(avlPrimTest.size() == 0);
	BOOST_CHECK(mapPrimTest.empty() == true);
	BOOST_CHECK(avlPrimTest.empty() == true);

//-------------------------------------------------------

	//------Object Check -------------------------------------	
	std::map<int,KaylaTestObject> mapObjectTest;
	avltree<int, KaylaTestObject> avlObjectTest;

	//clear empty maps 
	mapObjectTest.clear();
	mapObjectTest.clear();

	BOOST_CHECK(mapObjectTest.size() == avlObjectTest.size());
	BOOST_CHECK(mapObjectTest.size() == 0);
	BOOST_CHECK(avlObjectTest.size() == 0);
	BOOST_CHECK(mapObjectTest.empty() == true);
	BOOST_CHECK(avlObjectTest.empty() == true);

	KaylaTestObject TestObject;
	//Insert different ways, then clear. 
	mapObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));
	avlObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));	

	KaylaTestObject TestObject2;
	mapObjectTest[2] = TestObject2;
	avlObjectTest[2] = TestObject2;

	mapObjectTest.emplace(3, TestObject2);
	avlObjectTest.emplace(3, TestObject2);

	BOOST_CHECK(mapObjectTest.size() == avlObjectTest.size());
	BOOST_CHECK(mapObjectTest.size() == 3);
	BOOST_CHECK(avlObjectTest.size() == 3);
	BOOST_CHECK(mapObjectTest.empty() == false);
	BOOST_CHECK(avlObjectTest.empty() == false);
	
	mapObjectTest.clear();
	avlObjectTest.clear();

	BOOST_CHECK(mapObjectTest.size() == avlObjectTest.size());
	BOOST_CHECK(mapObjectTest.size() == 0);
	BOOST_CHECK(avlObjectTest.size() == 0);
	BOOST_CHECK(mapObjectTest.empty() == true);
	BOOST_CHECK(avlObjectTest.empty() == true);

	//Insert again, then erase some then clear. 
	mapObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));
	avlObjectTest.insert(std::pair<int, KaylaTestObject>(1, TestObject));	

	mapObjectTest[2] = TestObject2;
	avlObjectTest[2] = TestObject2;

	//Erase
	mapObjectTest.erase(1);
	avlObjectTest.erase(1);

	BOOST_CHECK(mapObjectTest.size() == avlObjectTest.size());
	BOOST_CHECK(mapObjectTest.size() == 1);
	BOOST_CHECK(avlObjectTest.size() == 1);
	BOOST_CHECK(mapObjectTest.empty() == false);
	BOOST_CHECK(avlObjectTest.empty() == false);



	//-----String Double Check------------------------------------

	std::map<double, std::string> mapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;

	//clear empty map. 
	mapDoubleStringTest.clear();
	avlDoubleStringTest.clear();
	
	BOOST_CHECK(mapDoubleStringTest.size() == avlDoubleStringTest.size());
	BOOST_CHECK(mapDoubleStringTest.size() == 0);
	BOOST_CHECK(avlDoubleStringTest.size() == 0);
	BOOST_CHECK(mapDoubleStringTest.empty() == true);
	BOOST_CHECK(avlDoubleStringTest.empty() == true);

	//Insert differnt ways, then clear. 
	mapDoubleStringTest.insert(std::pair<double, std::string>(1.1, "hello"));
	avlDoubleStringTest.insert(std::pair<double, std::string>(1.1, "hello"));	
	
	mapDoubleStringTest[1.2] = "hello world";
	avlDoubleStringTest[1.2] = "hello world";
	mapDoubleStringTest.emplace(1.3, "hello world again");
	avlDoubleStringTest.emplace(1.3, "hello world again");

	
	BOOST_CHECK(mapDoubleStringTest.size() == avlDoubleStringTest.size());
	BOOST_CHECK(mapDoubleStringTest.size() == 3);
	BOOST_CHECK(avlDoubleStringTest.size() == 3);
	BOOST_CHECK(mapDoubleStringTest.empty() == false);
	BOOST_CHECK(avlDoubleStringTest.empty() == false);
	
	mapDoubleStringTest.clear();
	avlDoubleStringTest.clear();
		
	BOOST_CHECK(mapDoubleStringTest.size() == avlDoubleStringTest.size());
	BOOST_CHECK(mapDoubleStringTest.size() == 0);
	BOOST_CHECK(avlDoubleStringTest.size() == 0);
	BOOST_CHECK(mapDoubleStringTest.empty() == true);
	BOOST_CHECK(avlDoubleStringTest.empty() == true);

	//Insert some more, erase some, then clear	
	mapDoubleStringTest.insert(std::pair<double, std::string>(1.1, "hello"));
	avlDoubleStringTest.insert(std::pair<double, std::string>(1.1, "hello"));	
	mapDoubleStringTest[1.2] = "hello world";
	avlDoubleStringTest[1.2] = "hello world";

	mapDoubleStringTest.erase(1.1);
	avlDoubleStringTest.erase(1.1);
	
	BOOST_CHECK(mapDoubleStringTest.size() == avlDoubleStringTest.size());
	BOOST_CHECK(mapDoubleStringTest.size() == 1);
	BOOST_CHECK(avlDoubleStringTest.size() == 1);
	BOOST_CHECK(mapDoubleStringTest.empty() == false);
	BOOST_CHECK(avlDoubleStringTest.empty() == false);

	mapDoubleStringTest.clear();
	avlDoubleStringTest.clear();
	
	BOOST_CHECK(mapDoubleStringTest.size() == avlDoubleStringTest.size());
	BOOST_CHECK(mapDoubleStringTest.size() == 0);
	BOOST_CHECK(avlDoubleStringTest.size() == 0);
	BOOST_CHECK(mapDoubleStringTest.empty() == true);
	BOOST_CHECK(avlDoubleStringTest.empty() == true);


	//std::cout << "IMPLEMENTED: avltree<T>::clear()\n";
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