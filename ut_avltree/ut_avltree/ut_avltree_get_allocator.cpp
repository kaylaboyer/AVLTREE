///**	@file: ut_avltree_get_allocator.cpp
//	@author Garth Santor
//	@author gsantor@fanshaweonline.ca
//	@author http://www.gats.ca/
//	@date 2013-01-16
//	@version 0.0.0
//	@note Developed for C++ 11
//	@brief avltree<T>::get_allocator() unit tests.
//	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"


//Returns a copy of the allocator object associated with the map.
/**	allocator_type get_allocator() const */
BOOST_AUTO_TEST_CASE( ut_get_allocator ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::get_allocator()\n";
	avltree<int, int> avlAllocTestInt;
	avltree<char, int> avlAllocTestChar;

	BOOST_CHECK( typeid(avlAllocTestInt.get_allocator()).name() == typeid(std::allocator<const int>).name() );
	BOOST_CHECK( typeid(avlAllocTestChar.get_allocator()).name() == typeid(std::allocator<const char>).name() );


}


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