///**	@file: ut_avltree_emplace.cpp
//	@author Garth Santor
//	@author gsantor@fanshaweonline.ca
//	@author http://www.gats.ca/
//	@date 2013-01-16
//	@version 0.0.0
//	@note Developed for C++ 11
//	@brief avltree<T>::emplace() unit tests.
//	*/
//
#include <boost/test/auto_unit_test.hpp>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"
#include <iostream>
#include <map>

//
///*
//
//Inserts a new element to the container. The element is constructed in-place,
//i.e. no copy or move operations are performed. The constructor of the element 
//type (value_type, that is, std::pair<const Key, T>) is called with exactly the 
//same arguments as supplied to the function, forwarded with std::forward<Args>(args)....
//No iterators or references are invalidated.
//*/
//
//
//**	template <class ValTy> pair<iterator,bool> emplace( ValTy&& ) */
BOOST_AUTO_TEST_CASE( ut_emplace ){
 //std::cout << "NOT IMPLEMENTED: avltree<T>::emplace(&&)\n";

	std::map<char,int> emplaceMap;
	avltree<char,int> emplaceAvltree;

	std::map<char,int>::iterator itEmplaceMap;
	avltree<char,int>::iterator itEmplaceAvltree;

	emplaceMap.insert(std::pair<char,int>('b',2));
	emplaceAvltree.insert(std::pair<char,int>('b',2));
	emplaceMap.emplace('a',1);
	emplaceAvltree.emplace('a',1);
	itEmplaceMap = emplaceMap.find('a');
	itEmplaceAvltree = emplaceAvltree.find('a');
	BOOST_CHECK_EQUAL( itEmplaceMap->first == 'a', true );
	BOOST_CHECK_EQUAL( itEmplaceAvltree->first == 'a', true );

	itEmplaceMap = emplaceMap.find('a');
	itEmplaceAvltree = emplaceAvltree.find('a');
	BOOST_CHECK_EQUAL( std::distance(itEmplaceMap, emplaceMap.begin()), 0);
	BOOST_CHECK_EQUAL( std::distance(itEmplaceAvltree, emplaceAvltree.begin()), 0 );

	emplaceMap.emplace('a',200);
	emplaceAvltree.emplace('a',200);
	BOOST_CHECK_EQUAL( itEmplaceMap->second == 1, true );
	BOOST_CHECK_EQUAL( itEmplaceAvltree->second == 1, true );

	//--------Double test ----------------------------------------
	std::map<double,int> emplaceMapDouble;
	avltree<double,int> emplaceAvltreeDouble;

	std::map<double,int>::iterator itEmplaceMapDouble;
	avltree<double,int>::iterator itEmplaceAvltreeDouble;

	emplaceMapDouble.insert(std::pair<double,int>(1.1,1));
	emplaceAvltreeDouble.insert(std::pair<double,int>(1.1,1));
	emplaceMapDouble.emplace(1.2,1);
	emplaceAvltreeDouble.emplace(1.2,1);

	itEmplaceMapDouble = emplaceMapDouble.find(1.2);
	itEmplaceAvltreeDouble = emplaceAvltreeDouble.find(1.2);

	BOOST_CHECK_EQUAL( itEmplaceMapDouble->second, 1 );
	BOOST_CHECK_EQUAL( itEmplaceAvltreeDouble->second, 1 );

	emplaceMapDouble.emplace(1.2,200);
	emplaceAvltreeDouble.emplace(1.2,200);
	BOOST_CHECK_EQUAL( itEmplaceMapDouble->second, 1 );
	BOOST_CHECK_EQUAL( itEmplaceAvltreeDouble->second, 1 );
}//end test case. 

/////**	template <class ValTy> pair<iterator,bool> emplace_hint( const_iterator, ValTy&& ) */
BOOST_AUTO_TEST_CASE( ut_emplace_hint )
{
//std::cout << "NOT IMPLEMENTED: avltree<T>::emplace(iterator,&&)\n";

	// Text Case #1 - basic emplace_hint()
	std::map<char,int> emplaceHintMap;
	std::map<char,int>::const_iterator itEmplaceHintMap;
	avltree<char,int> emplaceHintAvltree;
	avltree<char,int>::const_iterator itEmplaceHintAvltree;
	emplaceHintMap.insert(std::pair<char,int>('b',2));
	emplaceHintAvltree.insert(std::pair<char,int>('b',2));
	itEmplaceHintMap = emplaceHintMap.end();
	itEmplaceHintAvltree = emplaceHintAvltree.cend();
	emplaceHintMap.emplace_hint(itEmplaceHintMap,'a',1);
	emplaceHintAvltree.emplace_hint(itEmplaceHintAvltree,'a',1);
	BOOST_CHECK_EQUAL( emplaceHintMap.find('a')->second, 1 );
	BOOST_CHECK_EQUAL( emplaceHintAvltree.find('a')->second, 1 );
}


/////*=============================================================
////
////Revision History
////
////Version 0.0.0: 2013-01-16
////Alpha release.
////
////=============================================================
////
////Copyright Garth Santor
////
////The copyright to the computer program(s) herein
////is the property of Garth Santor of Canada.
////The program(s) may be used and/or copied only with
////the written permission of Garth Santor
////or in accordance with the terms and conditions
////stipulated in the agreement/contract under which
////the program(s) have been supplied.
////=============================================================*/