/**	@file: ut_avltree_find.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::find() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avltree.hpp"
#include "KaylaTestObject.hpp"
#include <iostream>
#include <map>

/**	iterator find( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_find )
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::find()\n";

	// Test Case #1 - Basic find()
	std::map<char,int> findMap;
	std::map<char,int>::iterator itMap;
	findMap['a'] = 10;
	avltree<char,int> findAvltree;
	avltree<char,int>::iterator itAvltree;
	findAvltree['a'] = 10;
	BOOST_CHECK( findMap.find('a')->second == 10 );
	BOOST_CHECK( findAvltree.find('a')->second == 10 );
	BOOST_CHECK( findMap.find('a')->second == findAvltree.find('a')->second );
	itMap = findMap.find('a');
	itAvltree = findAvltree.find('a');
	BOOST_CHECK( itMap->second == 10 );
	BOOST_CHECK( itAvltree->second == 10 );
	BOOST_CHECK( itMap->second == itAvltree->second );

	std::map<char,double> findMap2;
	std::map<char,double>::iterator itMap2;
	findMap2['f'] = 10.0003;
	avltree<char,double> findAvltree2;
	avltree<char,double>::iterator itAvltree2;
	findAvltree2['f'] = 10.0003;
	BOOST_CHECK( findMap2.find('f')->second == 10.0003 );
	BOOST_CHECK( findAvltree2.find('f')->second == 10.0003 );
	BOOST_CHECK( findMap2.find('f')->second == findAvltree2.find('f')->second );
	itMap2 = findMap2.find('f');
	itAvltree2 = findAvltree2.find('f');
	BOOST_CHECK( itMap2->second == 10.0003 );
	BOOST_CHECK( itAvltree2->second == 10.0003 );
	BOOST_CHECK( itMap2->second == itAvltree2->second );

	std::map<int,std::string> findMap3;
	std::map<int,std::string>::iterator itMap3;
	findMap3[1] = "test";
	avltree<int,std::string> findAvltree3;
	avltree<int,std::string>::iterator itAvltree3;
	findAvltree3[1] = "test";
	BOOST_CHECK( findMap3.find(1)->second == "test" );
	BOOST_CHECK( findAvltree3.find(1)->second == "test" );
	BOOST_CHECK( findMap3.find(1)->second == findAvltree3.find(1)->second );
	itMap3 = findMap3.find(1);
	itAvltree3 = findAvltree3.find(1);
	BOOST_CHECK( itMap3->second == "test" );
	BOOST_CHECK( itAvltree3->second == "test" );
	BOOST_CHECK( itMap3->second == itAvltree3->second );

	KaylaTestObject objKayla;

	std::map<int,KaylaTestObject> findMap4;
	std::map<int,KaylaTestObject>::iterator itMap4;
	findMap4[1] = objKayla;
	avltree<int,KaylaTestObject> findAvltree4;
	avltree<int,KaylaTestObject>::iterator itAvltree4;
	findAvltree4[1] = objKayla;
	//BOOST_CHECK( findMap4.find(1)->second.theMeaningOfLife() == "Your guess is as good as mine" );
	//BOOST_CHECK( findAvltree4.find(1)->second.theMeaningOfLife() == "Your guess is as good as mine" );
	//BOOST_CHECK( findMap4.find(1)->second.theMeaningOfLife() == findAvltree4.find(1)->second.theMeaningOfLife() );
	//itMap4 = findMap4.find(1);
	//itAvltree4 = findAvltree4.find(1);
	//BOOST_CHECK( itMap4->second.theMeaningOfLife() == "Your guess is as good as mine" );
	//BOOST_CHECK( itAvltree4->second.theMeaningOfLife() == "Your guess is as good as mine" );
	//BOOST_CHECK( itMap4->second.theMeaningOfLife() == itAvltree4->second.theMeaningOfLife() );


	// Test Case #2 - find() defaulting to end() when index is not found
	std::map<char,int> findNFMap;
	std::map<char,int>::iterator itFindNFMap, itFindNFMap2;
	findNFMap.insert(std::pair<char,int>('b',2));
	findNFMap.insert(std::pair<char,int>('z',26));
	avltree<char,int> findNFAvltree;
	avltree<char,int>::iterator itFindNFAvltree, itFindNFAvltree2;
	findNFAvltree.insert(std::pair<char,int>('b',2));
	findNFAvltree.insert(std::pair<char,int>('z',26));
	itFindNFMap = findNFMap.find('a');
	itFindNFMap2 = findNFMap.end();
	itFindNFAvltree = findNFAvltree.find('a');
	itFindNFAvltree2 = findNFAvltree.end();
	BOOST_CHECK(itFindNFMap == itFindNFMap2);
	BOOST_CHECK(itFindNFAvltree ==  itFindNFAvltree2);
	BOOST_CHECK(itFindNFAvltree->first == 'z');	

////	// Test Case #3 - erasing the key at find()'s location
	std::map<char, int> findEraseMap;
	std::map<char,int>::iterator itFindEraseMap;
	avltree<char,int> findEraseAvltree;
	avltree<char,int>::iterator itFindEraseAvltree;
	std::map<int,int> emptyMap;
	avltree<int,int> emptyAvltree;
	findEraseMap.insert(std::pair<char,int>('a',1) );
	findEraseMap.insert(std::pair<char,int>('b',2) );
	findEraseAvltree.insert(std::pair<char,int>('a',1) );
	findEraseAvltree.insert(std::pair<char,int>('b',2) );
	itFindEraseMap = findEraseMap.find('b');
	itFindEraseAvltree = findEraseAvltree.find('b');
	findEraseMap.erase(findEraseMap.find('a'));
	findEraseMap.erase(itFindEraseMap);
	findEraseAvltree.erase(findEraseAvltree.find('a'));
	findEraseAvltree.erase(itFindEraseAvltree);

	BOOST_CHECK( findEraseMap.find('a') == findEraseMap.end() );
	BOOST_CHECK( findEraseAvltree.find('a') == findEraseAvltree.end() );
	BOOST_CHECK( findEraseMap.find('b') ==  findEraseMap.end() );
	BOOST_CHECK( findEraseAvltree.find('b') == findEraseAvltree.end());
	BOOST_CHECK( findEraseMap.size() == emptyMap.size() );
	BOOST_CHECK( findEraseAvltree.size() == emptyAvltree.size() );
}
//
///**	const_iterator find( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_find_const )
{
	std::cout << "NOT IMPLEMENTED: avltree<T>::find() const\n";

	 //Test Case #1 - Basic find() const
	std::map< char,int> findMapC;
	std::map< char,int>::iterator itMapC;
	avltree< char,int> findAvltreeC;
	avltree< char,int>::iterator itAvltreeC;
	const char& ch = 'a';
	findMapC[ch] = 20;
	findAvltreeC[ch] = 20;
	BOOST_CHECK( findMapC.find(ch)->second == 20 );
	BOOST_CHECK( findAvltreeC.find(ch)->second == 20 );
	BOOST_CHECK( findMapC.find(ch)->second == findAvltreeC.find(ch)->second );
	itMapC = findMapC.find(ch);
	itAvltreeC = findAvltreeC.find(ch);
	BOOST_CHECK( itMapC->second == 20 );
	BOOST_CHECK( itAvltreeC->second == 20 );
	BOOST_CHECK( itMapC->second == itAvltreeC->second );

	std::map< char,double> findMap2C;
	std::map< char,double>::iterator itMap2C;
	avltree< char,double> findAvltree2C;
	avltree< char,double>::iterator itAvltree2C;
	const char& ch2 = 'f';
	findMap2C[ch2] = 10.0003;
	findAvltree2C[ch2] = 10.0003;
	BOOST_CHECK_EQUAL( findMap2C.find('f')->second, 10.0003 );
	BOOST_CHECK_EQUAL( findAvltree2C.find('f')->second, 10.0003 );
	BOOST_CHECK_EQUAL( findMap2C.find('f')->second, findAvltree2C.find('f')->second );
	itMap2C = findMap2C.find('f');
	itAvltree2C = findAvltree2C.find('f');
	BOOST_CHECK_EQUAL( itMap2C->second, 10.0003 );
	BOOST_CHECK_EQUAL( itAvltree2C->second, 10.0003 );
	BOOST_CHECK_EQUAL( itMap2C->second, itAvltree2C->second );

	std::map< int,std::string> findMap3C;
	std::map< int,std::string>::iterator itMap3C;
	avltree< int,std::string> findAvltree3C;
	avltree< int,std::string>::iterator itAvltree3C;
	const int& i = 5;
	findMap3C[i] = "This is a test!";
	findAvltree3C[i] = "This is a test!";
	BOOST_CHECK_EQUAL( findMap3C.find(i)->second, "This is a test!" );
	BOOST_CHECK_EQUAL( findAvltree3C.find(i)->second, "This is a test!" );
	BOOST_CHECK_EQUAL( findMap3C.find(i)->second, findAvltree3C.find(i)->second );
	itMap3C = findMap3C.find(i);
	itAvltree3C = findAvltree3C.find(i);
	BOOST_CHECK_EQUAL( itMap3C->second, "This is a test!" );
	BOOST_CHECK_EQUAL( itAvltree3C->second, "This is a test!" );
	BOOST_CHECK_EQUAL( itMap3C->second, itAvltree3C->second );
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