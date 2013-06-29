//**	@file: ut_avltree_ctor.cpp
//	@author Garth Santor
//	@author gsantor@fanshaweonline.ca
//	@author http://www.gats.ca/
//	@date 2013-01-16
//	@version 0.0.0
//	@note Developed for C++ 11
//	@brief avltree<T>::ctor() unit tests.
//	*/
//

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include <map>
#include <vector>

//Constructs an avltree container object, initializing its contents depending on the constructor version used:

//**	avltree() */
BOOST_AUTO_TEST_CASE( ut_ctor_default ) {
	//std::cout << "IMPLEMENTED: avltree<T>::avltree()\n";
	//empty ctor
	avltree<int, int> emptyTreeOne;
	avltree<char, int> emptyTreeTwo;
	avltree<char, char> emptyTreeThree;
	avltree<double, double> emptyTreeFour;
	avltree<char, double> emptyTreeFive;
	avltree<char, std::map<int, int>> emptyTreeSix;
	avltree<int, std::string> emptyTreeSeven;
	std::map<int, int> emptyMapOne;
	std::map<char, int> emptyMapTwo;
	std::map<char, char> emptyMapThree;
	std::map<double, double> emptyMapFour;
	std::map<char, double> emptyMapFive;
	std::map<char, std::map<int, int>> emptyMapSix;
	std::map<int, std::string> emptyMapSeven;
	//check that the containers are empty
	BOOST_CHECK_EQUAL( emptyMapOne.empty() == emptyTreeOne.empty(), true);
	BOOST_CHECK_EQUAL( emptyMapTwo.empty() == emptyTreeTwo.empty(), true);
	BOOST_CHECK_EQUAL( emptyMapThree.empty() == emptyTreeThree.empty(), true);
	BOOST_CHECK_EQUAL( emptyMapFour.empty() == emptyTreeFour.empty(), true);
	BOOST_CHECK_EQUAL( emptyMapFive.empty() == emptyTreeFive.empty(), true);
	BOOST_CHECK_EQUAL( emptyMapSix.empty() == emptyTreeSix.empty(), true);
	BOOST_CHECK_EQUAL( emptyMapSeven.empty() == emptyTreeSeven.empty(), true);
}


///**	explicit avltree( Traits const& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_traits_ref ) {
	//std::cout << "IMPLEMENTED: avltree<T>::avltree( Traits& )\n";
	avltree<int, int, std::less<int>> lessTreeOne;
	avltree<char, int, std::less<char>> lessTreeTwo;
	avltree<char, char, std::less<char>> lessTreeThree;
	avltree<double, double, std::less<double>> lessTreeFour;
	avltree<char, double, std::less<char>> lessTreeFive;
	avltree<char, std::map<int, int>, std::less<char>> lessTreeSix;
	avltree<int, std::string, std::less<int>> lessTreeSeven;
	avltree<int, int, std::greater<int>> greaterTreeOne;
	avltree<char, int, std::greater<char>> greaterTreeTwo;
	avltree<char, char, std::greater<char>> greaterTreeThree;
	avltree<double, double, std::greater<double>> greaterTreeFour;
	avltree<char, double, std::greater<char>> greaterTreeFive;
	avltree<char, std::map<int, int>, std::greater<char>> greaterTreeSix;
	avltree<int, std::string, std::greater<int>> greaterTreeSeven;

	
	char ch = 'a';
	double d = 0.0;
	std::string s = "test";
	std::map<int,int> m;

	for(int i = 0; i < 10; ++i)
	{
		m.insert(std::pair<int,int>(i,i));

		lessTreeOne.insert(std::pair<int, int>(i,i));
		greaterTreeOne.insert(std::pair<int, int>(i,i));
		lessTreeTwo.insert(std::pair<char, int>(ch,i));
		greaterTreeTwo.insert(std::pair<char, int>(ch,i));
		lessTreeThree.insert(std::pair<char, char>(ch,ch));
		greaterTreeThree.insert(std::pair<char, char>(ch,ch));
		lessTreeFour.insert(std::pair<double, double>(d,d));
		greaterTreeFour.insert(std::pair<double, double>(d,d));
		lessTreeFive.insert(std::pair<char, double>(ch,d));
		greaterTreeFive.insert(std::pair<char, double>(ch,d));
		lessTreeSix.insert(std::pair<char, std::map<int,int>>(ch,m));
		greaterTreeSix.insert(std::pair<char, std::map<int,int>>(ch,m));
		lessTreeSeven.insert(std::pair<int, std::string>(i,s));
		greaterTreeSeven.insert(std::pair<int, std::string>(i,s));

		++ch;
		++d;
		
	}

	BOOST_CHECK(lessTreeOne.begin()->first == 0);
	BOOST_CHECK(greaterTreeOne.end()->first == 0);
	BOOST_CHECK(lessTreeTwo.begin()->first == 'a');
	BOOST_CHECK(greaterTreeTwo.end()->first == 'a');
	BOOST_CHECK(lessTreeThree.begin()->first == 'a');
	BOOST_CHECK(greaterTreeThree.end()->first == 'a');
	BOOST_CHECK(lessTreeFour.begin()->first == 0.0);
	BOOST_CHECK(greaterTreeFour.end()->first == 0.0);
	BOOST_CHECK(lessTreeFive.begin()->first == 'a');
	BOOST_CHECK(greaterTreeFive.end()->first == 'a');
	BOOST_CHECK(lessTreeSix.begin()->first == 'a');
	BOOST_CHECK(greaterTreeSix.end()->first == 'a');
	BOOST_CHECK(lessTreeSeven.begin()->first == 0);
	BOOST_CHECK(greaterTreeSeven.end()->first == 0);


}


//**	avltree( Traits const&, Allocator const& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_traits_ref_allocator_ref ) {
	//std::cout << "IMPLEMENTED: avltree<T>::avltree( traits&, allocator& )\n";
	
	avltree<int, int, std::less<int>, std::allocator<int>> lessTreeOne;
	avltree<char, int, std::less<char>, std::allocator<char>> lessTreeTwo;
	avltree<char, char, std::less<char>, std::allocator<char>> lessTreeThree;
	avltree<double, double, std::less<double>, std::allocator<double>> lessTreeFour;
	avltree<char, double, std::less<char>, std::allocator<char>> lessTreeFive;
	avltree<char, std::map<int, int>, std::less<char>, std::allocator<char>> lessTreeSix;
	avltree<int, std::string, std::less<int>, std::allocator<int>> lessTreeSeven;
	avltree<int, int, std::greater<int>, std::allocator<int>> greaterTreeOne;
	avltree<char, int, std::greater<char>, std::allocator<char>> greaterTreeTwo;
	avltree<char, char, std::greater<char>, std::allocator<char>> greaterTreeThree;
	avltree<double, double, std::greater<double>, std::allocator<double>> greaterTreeFour;
	avltree<char, double, std::greater<char>, std::allocator<char>> greaterTreeFive;
	avltree<char, std::map<int, int>, std::greater<char>, std::allocator<char>> greaterTreeSix;
	avltree<int, std::string, std::greater<int>, std::allocator<int>> greaterTreeSeven;

	BOOST_CHECK( typeid(lessTreeOne.get_allocator()).name() == typeid(std::allocator<const int>).name() );
	BOOST_CHECK( typeid(lessTreeTwo.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(lessTreeThree.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(lessTreeFour.get_allocator()).name() == typeid(std::allocator<const double>).name() );
	BOOST_CHECK( typeid(lessTreeFive.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(lessTreeSix.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(lessTreeSeven.get_allocator()).name() == typeid(std::allocator<const int>).name() );
	BOOST_CHECK( typeid(greaterTreeOne.get_allocator()).name() == typeid(std::allocator<const int>).name() );
	BOOST_CHECK( typeid(greaterTreeTwo.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(greaterTreeThree.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(greaterTreeFour.get_allocator()).name() == typeid(std::allocator<const double>).name() );
	BOOST_CHECK( typeid(greaterTreeFive.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(greaterTreeSix.get_allocator()).name() == typeid(std::allocator<const char>).name() );
	BOOST_CHECK( typeid(greaterTreeSeven.get_allocator()).name() == typeid(std::allocator<const int>).name() );

}

//**	avltree( avltree& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_avltree_ref ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(avltree&)\n";
	avltree<int, int> copyTreeOne;
	avltree<char, int> copyTreeTwo;
	avltree<char, char> copyTreeThree;
	avltree<double, double> copyTreeFour;
	avltree<char, double> copyTreeFive;
	
	char ch = ' ';
	double d = 1.2;
	for( int i = 0; i != 10; ++i )
	{		
		++ch;
		++d;	
		copyTreeOne.insert( std::pair<int,int>(i,i) );
		copyTreeTwo.insert( std::pair<char,int>(i,ch) );
		copyTreeThree.insert( std::pair<char,char>(ch,ch) );
		copyTreeFour.insert( std::pair<double,double>(d,d) );
		copyTreeFive.insert( std::pair<char,double>(ch,d) );
	}	
	
	avltree<int, int> avlRefTreeOne( copyTreeOne );
	avltree<char, int> avlRefTreeTwo( copyTreeTwo );
	avltree<char, char> avlRefTreeThree( copyTreeThree );
	avltree<double, double> avlRefTreeFour( copyTreeFour );
	avltree<char, double> avlRefTreeFive( copyTreeFive );

	BOOST_CHECK(avlRefTreeOne.begin()->second == copyTreeOne.begin()->second);
	BOOST_CHECK(avlRefTreeTwo.begin()->second == copyTreeTwo.begin()->second);
	BOOST_CHECK(avlRefTreeThree.begin()->second == copyTreeThree.begin()->second);
	BOOST_CHECK(avlRefTreeFour.begin()->second == copyTreeFour.begin()->second);
	BOOST_CHECK(avlRefTreeFive.begin()->second == copyTreeFive.begin()->second);
}


//**	avltree( InputIterator, InputIterator ) 
BOOST_AUTO_TEST_CASE( ut_ctor_iterator_iterator ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(iterator,iterator)\n";
	
	
	avltree<int, int> avltree1;

	for( int i = 0; i < 10; ++i)
		avltree1.insert( std::pair<int,int>(i,i) );

	avltree<int,int>::iterator it = avltree1.begin();

	++it; ++it; ++it;

	avltree<int,int> iterTree( avltree1.begin(), avltree1.end() );
	avltree<int,int> iterTree2( avltree1.begin(), it );

	++it; ++it; ++it;

	avltree<int,int> iterTree3( avltree1.begin(), it );

	BOOST_CHECK(iterTree.end()->second == avltree1.end()->second);
	BOOST_CHECK(iterTree.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree2.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree2.end()->second != avltree1.end()->second);
	BOOST_CHECK(iterTree3.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree3.end()->second != avltree1.end()->second);
	BOOST_CHECK(iterTree3.end()->second != iterTree2.end()->second);

}

///**	avltree( InputIterator, InputIterator, Traits const& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_iterator_iterator_traits ) {
	std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(iterator,iterator,traits)\n";

	
	avltree<int, int, std::less<int>> avltree1;

	for( int i = 0; i < 10; ++i)
		avltree1.insert( std::pair<int,int>(i,i) );

	avltree<int,int,std::less<int>>::iterator it = avltree1.begin();

	++it; ++it; ++it;

	avltree<int,int, std::less<int>> iterTree( avltree1.begin(), avltree1.end() );
	avltree<int,int, std::less<int>> iterTree2( avltree1.begin(), it );

	++it; ++it; ++it;

	avltree<int,int, std::less<int>> iterTree3( avltree1.begin(), it );

	BOOST_CHECK(iterTree.end()->second == avltree1.end()->second);
	BOOST_CHECK(iterTree.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree2.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree2.end()->second != avltree1.end()->second);
	BOOST_CHECK(iterTree3.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree3.end()->second != avltree1.end()->second);
	BOOST_CHECK(iterTree3.end()->second != iterTree2.end()->second);

}


//**	avltree( InputIterator, InputIterator, Traits const&, allocator& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_iterator_iterator_traits_allocator ) {
	//std::cout << "IMPLEMENTED: avltree<T>::avltree(iterator,iterator,traits,allocator)\n";
	avltree<int, int, std::less<int>> avltree1;

	for( int i = 0; i < 10; ++i)
		avltree1.insert( std::pair<int,int>(i,i) );

	avltree<int,int>::iterator it = avltree1.begin();

	++it; ++it; ++it;

	avltree<int,int> iterTree( avltree1.begin(), avltree1.end(), avltree1.key_comp(), avltree1.get_allocator() );
	avltree<int,int> iterTree2( avltree1.begin(), it, avltree1.key_comp(), avltree1.get_allocator() );

	++it; ++it; ++it;

	avltree<int,int> iterTree3( avltree1.begin(), it, avltree1.key_comp(), avltree1.get_allocator() );

	BOOST_CHECK(iterTree.end()->second == avltree1.end()->second);
	BOOST_CHECK(iterTree.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree2.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree2.end()->second != avltree1.end()->second);
	BOOST_CHECK(iterTree3.begin()->second == avltree1.begin()->second);
	BOOST_CHECK(iterTree3.end()->second != avltree1.end()->second);
	BOOST_CHECK(iterTree3.end()->second != iterTree2.end()->second);
}


///**	avltree( avltree&& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_avltree_move ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(avltree&&)\n";
	avltree<int, int> copyTreeOne;
	avltree<int, char> copyTreeTwo;
	avltree<char, char> copyTreeThree;
	avltree<double, double> copyTreeFour;
	avltree<char, double> copyTreeFive;
	avltree<int, std::string> copyTreeSix;
	avltree<int,int> treeOneToCheckAgainst;
	avltree<int,char> treeOneToCheckAgainst2;
	avltree<char,char> treeOneToCheckAgainst3;
	avltree<double,double> treeOneToCheckAgainst4;
	avltree<char,double> treeOneToCheckAgainst5;
	avltree<int,std::string> treeOneToCheckAgainst6;

	char ch = ' ';
	double d = 1.2;
	std::string s = "test";
	for( int i = 0; i != 10; ++i )
	{		
		++ch;
		++d;
		s += ch;
		copyTreeOne.insert( std::pair<int,int>(i,i) );
		copyTreeTwo.insert( std::pair<int,char>(i,ch) );
		copyTreeThree.insert( std::pair<char,char>(ch,ch) );
		copyTreeFour.insert( std::pair<double,double>(d,d) );
		copyTreeFive.insert( std::pair<char,double>(ch,d) );
		copyTreeSix.insert( std::pair<int,std::string>(i,s) );
		treeOneToCheckAgainst.insert( std::pair<int,int>(i,i) );
		treeOneToCheckAgainst2.insert( std::pair<int,char>(i,ch) );
		treeOneToCheckAgainst3.insert( std::pair<char,char>(ch,ch) );
		treeOneToCheckAgainst4.insert( std::pair<double,double>(d,d) );
		treeOneToCheckAgainst5.insert( std::pair<char,double>(ch,d) );
		treeOneToCheckAgainst6.insert( std::pair<int,std::string>(i,s) );
	}

	//first do a copy of the tree we want to move the values from, 
	//so that we can check against what was in it later on. 
	

	avltree<int,int> moveTreeOne( move(copyTreeOne) );
	avltree<int,char> moveTreeTwo( move(copyTreeTwo) );
	avltree<char,char> moveTreeThree( move(copyTreeThree) );
	avltree<double,double> moveTreeFour( move(copyTreeFour) );
	avltree<char,double> moveTreeFive( move(copyTreeFive) );
	avltree<int,std::string> moveTreeSix( move(copyTreeSix) );

	auto copyIterOne = treeOneToCheckAgainst.begin();
	for(auto treeIterOne = moveTreeOne.begin(); treeIterOne != moveTreeOne.end(); ++treeIterOne )
	{
		BOOST_CHECK_EQUAL(treeIterOne->second == copyIterOne->second,true);
		++copyIterOne;
	}

	auto copyIterTwo = treeOneToCheckAgainst2.begin();
	for(auto treeIterTwo = moveTreeTwo.begin(); treeIterTwo != moveTreeTwo.end(); ++treeIterTwo )
	{
		BOOST_CHECK_EQUAL(treeIterTwo == copyIterTwo,true);
		++copyIterTwo;
	}
	auto copyIterThree = treeOneToCheckAgainst3.begin();
	for(auto treeIterThree = moveTreeThree.begin(); treeIterThree != moveTreeThree.end(); ++treeIterThree )
	{
		BOOST_CHECK_EQUAL(treeIterThree == copyIterThree,true);
		++copyIterThree;
	}
	auto copyIterFour = treeOneToCheckAgainst4.begin();
	for(auto treeIterFour = moveTreeFour.begin(); treeIterFour != moveTreeFour.end(); ++treeIterFour )
	{
		BOOST_CHECK_EQUAL(treeIterFour == copyIterFour,true);
		++copyIterFour;
	}
	auto copyIterFive = treeOneToCheckAgainst5.begin();
	for(auto treeIterFive = moveTreeFive.begin(); treeIterFive != moveTreeFive.end(); ++treeIterFive )
	{
		BOOST_CHECK_EQUAL(treeIterFive == copyIterFive,true);
		++copyIterFive;
	}
	auto copyIterSix = treeOneToCheckAgainst6.begin();
	for(auto treeIterSix = moveTreeSix.begin(); treeIterSix != moveTreeSix.end(); ++treeIterSix )
	{
		BOOST_CHECK_EQUAL(treeIterSix == copyIterSix,true);
		++copyIterSix;
	}
}


//
//*=============================================================
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