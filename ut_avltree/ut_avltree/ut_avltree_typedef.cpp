/**	@file: ut_avltree_typedef.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::types() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <map>
#include "avltree.hpp"

/**	Display typedefs. */
BOOST_AUTO_TEST_CASE( ut_typedef ) {
	//std::cout << "NOT IMPLEMENTED: typedefs\n";
	/*avltree<int, int> avlIntInt;
	avltree<int, int> avlCharInt;
	avltree<int, int> avlCharChar;
	avltree<int, int> avlCharDouble;
	avltree<int, int> avlDoubleDouble;
	avltree<int, int> avlDoubleInt;
	avltree<int, int> avlIntDouble;
	avltree<int, int> avlIntChar;
	avltree<int, int> avlIntString;
	size_type;
	key_compare;
	difference_type;*/

	BOOST_CHECK( typeid(avltree<int,int>::key_type).name() == typeid(const int).name());
	BOOST_CHECK( typeid(avltree<int,int>::value_type).name() == typeid(std::pair<const int,int>).name());
	BOOST_CHECK( typeid(avltree<int,int>::value_type).name() != typeid(std::pair<int,int>).name());
	BOOST_CHECK( typeid(avltree<int,int>::mapped_type).name() == typeid(int).name());
	BOOST_CHECK( typeid(avltree<int,int>::mapped_type).name() != typeid(char).name());
	BOOST_CHECK( typeid(avltree<int,int>::reference).name() == typeid(std::pair<const int,int>).name());
	BOOST_CHECK( typeid(avltree<int,int>::const_reference).name() == typeid(const std::pair<const int,int>).name());
	BOOST_CHECK( typeid(avltree<int,int>::size_type).name() == typeid(size_t).name());
	BOOST_CHECK( typeid( avltree<std::vector<float>, std::string, std::greater<std::vector<float>>>::key_compare ).name() == typeid( std::greater<std::vector<float>> ).name() );
	BOOST_CHECK( typeid( avltree<int, int>::difference_type ).name() == typeid(int).name());
	BOOST_CHECK( typeid( avltree<int, int>::allocator_type ).name() == typeid(std::allocator<const int>).name());

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