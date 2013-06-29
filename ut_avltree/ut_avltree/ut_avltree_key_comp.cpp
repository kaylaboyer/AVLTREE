///**	@file: ut_avltree_key_comp.cpp
//	@author Garth Santor
//	@author gsantor@fanshaweonline.ca
//	@author http://www.gats.ca/
//	@date 2013-01-16
//	@version 0.0.0
//	@note Developed for C++ 11
//	@brief avltree<T>::key_comp() unit tests.
//	*/


#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <map>
#include "avltree.hpp"


///**	key_compare key_comp() const */
BOOST_AUTO_TEST_CASE( ut_key_comp ) 
{
	avltree<int, int, std::less<int>> lessTree;
	avltree<int, int, std::greater<int>> greaterTree;

	lessTree.insert(std::pair<int,int>( 1, 1 ));
	lessTree.insert(std::pair<int,int>( 2, 2 ));
	lessTree.insert(std::pair<int,int>( 0, 3 ));

	greaterTree.insert(std::pair<int,int>( 1, 1 ));
	greaterTree.insert(std::pair<int,int>( 2, 2 ));
	greaterTree.insert(std::pair<int,int>( 0, 3 ));

	BOOST_CHECK( lessTree[1] == 1 );
	BOOST_CHECK( lessTree.end()->second == 2 );
	BOOST_CHECK( lessTree.begin()->second == 3 );
	BOOST_CHECK( greaterTree[1] == 1 );
	BOOST_CHECK( greaterTree.end()->second == 3 );
	BOOST_CHECK( greaterTree.begin()->second == 2 );


}
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