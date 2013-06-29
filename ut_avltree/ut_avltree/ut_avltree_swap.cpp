/**	@file: ut_avltree_swap.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::swap() unit tests.
	*/
#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"
#include <algorithm>
#include <string>
#include <iterator>



/**	void swap( avltree<Key, Type, Traits, Allocator>& ) */
BOOST_AUTO_TEST_CASE( ut_swap_method ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::swap( avltree<T>& )\n";
//************Int, int**********************
	avltree<int,int> avltree_int_int;
	avltree<int,int> avltree2_int_int;

	for(int i = 0; i <3; ++i)
		avltree_int_int.insert(std::pair<int,int>(i,1));
	for(int i = 0; i <5; ++ i)
		avltree2_int_int.insert(std::pair<int,int>(i,2));

	BOOST_CHECK(avltree_int_int.size() == 3);
	BOOST_CHECK(avltree2_int_int.size() == 5);
	BOOST_CHECK( avltree_int_int.size() <= avltree2_int_int.size());
	avltree_int_int.swap(avltree2_int_int);
	BOOST_CHECK(avltree_int_int.size() == 5);
	BOOST_CHECK(avltree2_int_int.size() == 3);
	BOOST_CHECK( avltree_int_int.size() >= avltree2_int_int.size());

//************char, int**********************
	avltree<char,int> avltree_char_int;
	avltree<char,int> avltree2_char_int;

	for(int i = 0; i <3; ++i)
		avltree_char_int.insert(std::pair<char,int>('a'+i,i));
	for(int i = 0; i <5; ++ i)
		avltree2_char_int.insert(std::pair<char,int>('b'+i,i));

	BOOST_CHECK(avltree_char_int.size() == 3);
	BOOST_CHECK(avltree2_char_int.size() == 5);
	BOOST_CHECK( avltree_char_int.size() <= avltree2_char_int.size());
	avltree_char_int.swap(avltree2_char_int);
	BOOST_CHECK(avltree_char_int.size() == 5);
	BOOST_CHECK(avltree2_char_int.size() == 3);
	BOOST_CHECK( avltree_char_int.size() >= avltree2_char_int.size());
//
////************double, Object**********************
	avltree<double,KaylaTestObject> avltree_double_object;
	avltree<double, KaylaTestObject> avltree2_double_object;
	KaylaTestObject TestObject(2);

	for(double i = 0.1; i < 3; ++i)
		avltree_double_object.insert(std::pair<double,KaylaTestObject>(i, TestObject));
	for(double i = 0.1; i <5; ++ i)
		avltree2_double_object.insert(std::pair<double, KaylaTestObject>(i, TestObject));

	BOOST_CHECK(avltree_double_object.size() == 3);
	BOOST_CHECK(avltree2_double_object.size() == 5);
	BOOST_CHECK( avltree_double_object.size() <= avltree2_double_object.size());
	avltree_double_object.swap(avltree2_double_object);
	BOOST_CHECK(avltree_double_object.size() == 5);
	BOOST_CHECK(avltree2_double_object.size() == 3);
	BOOST_CHECK( avltree_double_object.size() >= avltree2_double_object.size());
//
////************Int, string**********************
	avltree<int,std::string> avltree_int_string;
	avltree<int,std::string> avltree2_int_string;

	for(int i = 0; i <3; ++i)
		avltree_int_string.insert(std::pair<int,std::string>(i,"Test"));
	for(int i = 0; i <5; ++ i)
		avltree2_int_string.insert(std::pair<int,std::string>(i,"Test"));

	BOOST_CHECK(avltree_int_string.size() == 3);
	BOOST_CHECK(avltree2_int_string.size() ==5);
	BOOST_CHECK( avltree_int_string.size() <= avltree2_int_string.size());
	avltree_int_string.swap(avltree2_int_string);
	BOOST_CHECK(avltree_int_string.size() == 5);
	BOOST_CHECK(avltree2_int_string.size() == 3);
	BOOST_CHECK( avltree_int_string.size() >= avltree2_int_string.size());

//****************double,const int******************
	avltree<double, int> avltree_double_int;
	avltree<double, int> avltree2_double_int;

	for(int i = 0; i <3; ++i)
		avltree_double_int.insert(std::pair<double,  int>('a'+i,i));
	for(int i = 0; i <5; ++ i)
		avltree2_double_int.insert(std::pair<double,  int>('b'+i,i));
	BOOST_CHECK(avltree_double_int.size() == 3);
	BOOST_CHECK(avltree2_double_int.size() == 5);
	BOOST_CHECK( avltree_double_int.size() <= avltree2_double_int.size());
	avltree_double_int.swap(avltree2_double_int);
	BOOST_CHECK(avltree_double_int.size() == 5);
	BOOST_CHECK(avltree2_double_int.size() == 3);
	BOOST_CHECK( avltree_double_int.size() >= avltree2_double_int.size());
}


/**	void swap( avltree<Key, Type, Traits, Allocator>& ) */

BOOST_AUTO_TEST_CASE( ut_swap_function ) {
	//std::cout << "NOT IMPLEMENTED: swap( avltree<T>&, avltree<T>& )\n";
//************Int, int**********************
	avltree<int,int> avltree_int_int;
	avltree<int,int> avltree2_int_int;

	for(int i = 0; i <3; ++i)
		avltree_int_int.insert(std::pair<int,int>(i,1));
	for(int i = 0; i <5; ++ i)
		avltree2_int_int.insert(std::pair<int,int>(i,2));

	BOOST_CHECK(avltree_int_int.size() == 3);
	BOOST_CHECK(avltree2_int_int.size() == 5);
	BOOST_CHECK( avltree_int_int.size() <= avltree2_int_int.size());
	swap(avltree_int_int,avltree2_int_int);
	BOOST_CHECK(avltree_int_int.size() == 5);
	BOOST_CHECK(avltree2_int_int.size() == 3);
	BOOST_CHECK( avltree_int_int.size() >= avltree2_int_int.size());

//************char, int**********************
	avltree<char,int> avltree_char_int;
	avltree<char,int> avltree2_char_int;

	for(int i = 0; i <3; ++i)
		avltree_char_int.insert(std::pair<char,int>('a'+i,i));
	for(int i = 0; i <5; ++ i)
		avltree2_char_int.insert(std::pair<char,int>('b'+i,i));

	BOOST_CHECK(avltree_char_int.size() == 3);
	BOOST_CHECK(avltree2_char_int.size() == 5);
	BOOST_CHECK( avltree_char_int.size() <= avltree2_char_int.size());
	swap(avltree_char_int,avltree2_char_int);
	BOOST_CHECK(avltree_char_int.size() == 5);
	BOOST_CHECK(avltree2_char_int.size() == 3);
	BOOST_CHECK( avltree_char_int.size() >= avltree2_char_int.size());
//
////************double, Object**********************
	avltree<double,KaylaTestObject> avltree_double_object;
	avltree<double, KaylaTestObject> avltree2_double_object;
	KaylaTestObject TestObject(2);

	for(double i = 0.1; i < 3; ++i)
		avltree_double_object.insert(std::pair<double,KaylaTestObject>(i, TestObject));
	for(double i = 0.1; i <5; ++ i)
		avltree2_double_object.insert(std::pair<double, KaylaTestObject>(i, TestObject));

	BOOST_CHECK(avltree_double_object.size() == 3);
	BOOST_CHECK(avltree2_double_object.size() == 5);
	BOOST_CHECK( avltree_double_object.size() <= avltree2_double_object.size());
	swap(avltree_double_object,avltree2_double_object);
	BOOST_CHECK(avltree_double_object.size() == 5);
	BOOST_CHECK(avltree2_double_object.size() == 3);
	BOOST_CHECK( avltree_double_object.size() >= avltree2_double_object.size());
//
////************Int, string**********************
	avltree<int,std::string> avltree_int_string;
	avltree<int,std::string> avltree2_int_string;

	for(int i = 0; i <3; ++i)
		avltree_int_string.insert(std::pair<int,std::string>(i,"Test"));
	for(int i = 0; i <5; ++ i)
		avltree2_int_string.insert(std::pair<int,std::string>(i,"Test"));

	BOOST_CHECK(avltree_int_string.size() == 3);
	BOOST_CHECK(avltree2_int_string.size() ==5);
	BOOST_CHECK( avltree_int_string.size() <= avltree2_int_string.size());
	swap(avltree_int_string,avltree2_int_string);
	BOOST_CHECK(avltree_int_string.size() == 5);
	BOOST_CHECK(avltree2_int_string.size() == 3);
	BOOST_CHECK( avltree_int_string.size() >= avltree2_int_string.size());


	avltree<double, int> avltree_double_int;
	avltree<double, int> avltree2_double_int;

	for(int i = 0; i <3; ++i)
		avltree_double_int.insert(std::pair<double,  int>('a'+i,i));
	for(int i = 0; i <5; ++ i)
		avltree2_double_int.insert(std::pair<double,  int>('b'+i,i));
	BOOST_CHECK(avltree_double_int.size() == 3);
	BOOST_CHECK(avltree2_double_int.size() == 5);
	BOOST_CHECK( avltree_double_int.size() <= avltree2_double_int.size());
	swap(avltree_double_int,avltree2_double_int);
	BOOST_CHECK(avltree_double_int.size() == 5);
	BOOST_CHECK(avltree2_double_int.size() == 3);
	BOOST_CHECK( avltree_double_int.size() >= avltree2_double_int.size());
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