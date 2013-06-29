/**	@file: ut_avltree_iterator.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::iterator unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avltree.hpp"
#include <map>
#include "KaylaTestObject.hpp"


/**	const_iterator begin() const */
BOOST_AUTO_TEST_CASE( ut_begin_const ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::begin() const\n";
	//**************************Int,Int*********************************
	{
		std::map<int,int> map_int_int;
		avltree<int,int> avltree_int_int;

		for(int i = 0; i != 10; ++i){
			map_int_int.insert(std::pair<int,int>(i, 100));
			avltree_int_int.insert(std::pair<int,int>(i, 100));
		}
		std::map<int,int>::const_iterator map_it = map_int_int.begin();
		avltree<int,int>::const_iterator avl_it = avltree_int_int.cbegin();

		BOOST_CHECK(map_it == map_int_int.begin());
		BOOST_CHECK(map_it == map_int_int.cbegin());
		BOOST_CHECK(avl_it == avltree_int_int.begin());
		BOOST_CHECK(avl_it == avltree_int_int.cbegin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************Char,Int*********************************
	{
		std::map<char,int> mapC;
		avltree<char,int> avlC;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<char,int>('a'+i, 100));
			avlC.insert(std::pair<char,int>('a'+i, 100));
		}
		std::map<char,int>::const_iterator map_it = mapC.begin();
		avltree<char,int>::const_iterator avl_it = avlC.cbegin();

		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************Double,String*********************************
	{
		std::map<double,std::string> mapC;
		avltree<double,std::string> avlC;
		for(double i = 0.1; i != 10.1; ++i){
			mapC.insert(std::pair<double,std::string>(i, "test"));
			avlC.insert(std::pair<double,std::string>(i, "test"));
		}
		std::map<double,std::string>::const_iterator map_it = mapC.begin();
		avltree<double,std::string>::const_iterator avl_it = avlC.cbegin();

		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************int,Object*********************************
	{
		std::map<int,KaylaTestObject> mapC;
		avltree<int,KaylaTestObject> avlC;
		KaylaTestObject test;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
		}
		std::map<int,KaylaTestObject>::const_iterator map_it = mapC.begin();
		avltree<int,KaylaTestObject>::const_iterator avl_it = avlC.cbegin();

		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(map_it->first == avl_it->first);
	}
}

/**	iterator begin() */
BOOST_AUTO_TEST_CASE( ut_begin ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::begin()\n";
	//**************************Int,Int*********************************
	{
		std::map<int,int> map_int_int;
		avltree<int,int> avltree_int_int;

		for(int i = 0; i != 10; ++i){
			map_int_int.insert(std::pair<int,int>(i, 100));
			avltree_int_int.insert(std::pair<int,int>(i, 100));
		}
		std::map<int,int>::iterator map_it = map_int_int.begin();
		avltree<int,int>::iterator avl_it = avltree_int_int.begin();

		BOOST_CHECK(map_it == map_int_int.begin());
		BOOST_CHECK(map_it == map_int_int.cbegin());
		BOOST_CHECK(avl_it == avltree_int_int.begin());
		BOOST_CHECK(avl_it == avltree_int_int.cbegin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************Char,Int*********************************
	{
		std::map<char,int> mapC;
		avltree<char,int> avlC;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<char,int>('a'+i, 100));
			avlC.insert(std::pair<char,int>('a'+i, 100));
		}
		std::map<char,int>::iterator map_it = mapC.begin();
		avltree<char,int>::iterator avl_it = avlC.begin();

		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************Double,String*********************************
	{
		std::map<double,std::string> mapC;
		avltree<double,std::string> avlC;
		for(double i = 0.1; i != 10.1; ++i){
			mapC.insert(std::pair<double,std::string>(i, "test"));
			avlC.insert(std::pair<double,std::string>(i, "test"));
		}
		std::map<double,std::string>::iterator map_it = mapC.begin();
		avltree<double,std::string>::iterator avl_it = avlC.begin();

		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************int,Object*********************************
	{
		std::map<int,KaylaTestObject> mapC;
		avltree<int,KaylaTestObject> avlC;
		KaylaTestObject test;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
		}
		std::map<int,KaylaTestObject>::iterator map_it = mapC.begin();
		avltree<int,KaylaTestObject>::iterator avl_it = avlC.begin();

		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(map_it->first == avl_it->first);
	}
}

/**	const_iterator cbegin() const */
BOOST_AUTO_TEST_CASE( ut_cbegin_const ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::cbegin() const\n";
	//**************************Int,Int*********************************
	{
		std::map<int,int> map_int_int;
		avltree<int,int> avltree_int_int;

		for(int i = 0; i != 10; ++i){
			map_int_int.insert(std::pair<int,int>(i, 100));
			avltree_int_int.insert(std::pair<int,int>(i, 100));
		}
		std::map<int,int>::const_iterator map_it = map_int_int.cbegin();
		avltree<int,int>::const_iterator avl_it = avltree_int_int.cbegin();

		BOOST_CHECK(map_it == map_int_int.cbegin());
		BOOST_CHECK(map_it == map_int_int.begin());
		BOOST_CHECK(avl_it == avltree_int_int.cbegin());
		BOOST_CHECK(avl_it == avltree_int_int.begin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************Char,Int*********************************
	{
		std::map<char,int> mapC;
		avltree<char,int> avlC;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<char,int>('a'+i, 100));
			avlC.insert(std::pair<char,int>('a'+i, 100));
		}
		std::map<char,int>::const_iterator map_it = mapC.cbegin();
		avltree<char,int>::const_iterator avl_it = avlC.cbegin();

		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************Double,String*********************************
	{
		std::map<double,std::string> mapC;
		avltree<double,std::string> avlC;
		for(double i = 0.1; i != 10.1; ++i){
			mapC.insert(std::pair<double,std::string>(i, "test"));
			avlC.insert(std::pair<double,std::string>(i, "test"));
		}
		std::map<double,std::string>::const_iterator map_it = mapC.cbegin();
		avltree<double,std::string>::const_iterator avl_it = avlC.cbegin();

		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(map_it->first == avl_it->first);
		BOOST_CHECK(map_it->second == avl_it->second);
	}
	//**************************int,Object*********************************
	{
		std::map<int,KaylaTestObject> mapC;
		avltree<int,KaylaTestObject> avlC;
		KaylaTestObject test;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
		}
		std::map<int,KaylaTestObject>::const_iterator map_it = mapC.cbegin();
		avltree<int,KaylaTestObject>::const_iterator avl_it = avlC.cbegin();

		BOOST_CHECK(map_it == mapC.cbegin());
		BOOST_CHECK(map_it == mapC.begin());
		BOOST_CHECK(avl_it == avlC.cbegin());
		BOOST_CHECK(avl_it == avlC.begin());
		BOOST_CHECK(map_it->first == avl_it->first);
	}
}

//**	const_iterator cend() const */
BOOST_AUTO_TEST_CASE( ut_cend_const ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::cend() const\n";
	//**************************Int,Int*********************************
	{
		std::map<int,int> map_int_int;
		avltree<int,int> avltree_int_int;

		for(int i = 0; i != 10; ++i){
			map_int_int.insert(std::pair<int,int>(i, 100));
			avltree_int_int.insert(std::pair<int,int>(i, 100));
		}
		std::map<int,int>::const_iterator map_it = map_int_int.end();
		avltree<int,int>::const_iterator avl_it = avltree_int_int.cend();

		BOOST_CHECK(map_it == map_int_int.end());
		BOOST_CHECK(map_it == map_int_int.cend());
		BOOST_CHECK(avl_it == avltree_int_int.end());
		BOOST_CHECK(avl_it == avltree_int_int.cend());
	}
	//**************************Char,Int*********************************
	{
		std::map<char,int> mapC;
		avltree<char,int> avlC;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<char,int>('a'+i, 100));
			avlC.insert(std::pair<char,int>('a'+i, 100));
		}
		std::map<char,int>::const_iterator map_it = mapC.end();
		avltree<char,int>::const_iterator avl_it = avlC.cend();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
	//**************************Double,String*********************************
	{
		std::map<double,std::string> mapC;
		avltree<double,std::string> avlC;
		for(double i = 0.1; i != 10.1; ++i){
			mapC.insert(std::pair<double,std::string>(i, "test"));
			avlC.insert(std::pair<double,std::string>(i, "test"));
		}
		std::map<double,std::string>::const_iterator map_it = mapC.end();
		avltree<double,std::string>::const_iterator avl_it = avlC.cend();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
	//**************************int,Object*********************************
	{
		std::map<int,KaylaTestObject> mapC;
		avltree<int,KaylaTestObject> avlC;
		KaylaTestObject test;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
		}
		std::map<int,KaylaTestObject>::const_iterator map_it = mapC.end();
		avltree<int,KaylaTestObject>::const_iterator avl_it = avlC.cend();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
}

//**	const_iterator end() const */
BOOST_AUTO_TEST_CASE( ut_end_const ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::end() const\n";
	//**************************Int,Int********************************
	{
		std::map<int,int> map_int_int;
		avltree<int,int> avltree_int_int;

		for(int i = 0; i != 10; ++i){
			map_int_int.insert(std::pair<int,int>(i, 100));
			avltree_int_int.insert(std::pair<int,int>(i, 100));
		}
		std::map<int,int>::const_iterator map_it = map_int_int.end();
		avltree<int,int>::const_iterator avl_it = avltree_int_int.cend();

		BOOST_CHECK(map_it == map_int_int.end());
		BOOST_CHECK(map_it == map_int_int.cend());
		BOOST_CHECK(avl_it == avltree_int_int.end());
		BOOST_CHECK(avl_it == avltree_int_int.cend());
	}
	//**************************Char,Int*********************************
	{
		std::map<char,int> mapC;
		avltree<char,int> avlC;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<char,int>('a'+i, 100));
			avlC.insert(std::pair<char,int>('a'+i, 100));
		}
		std::map<char,int>::const_iterator map_it = mapC.end();
		avltree<char,int>::const_iterator avl_it = avlC.cend();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
	//**************************Double,String********************************
	{
		std::map<double,std::string> mapC;
		avltree<double,std::string> avlC;
		for(double i = 0.1; i != 10.1; ++i){
			mapC.insert(std::pair<double,std::string>(i, "test"));
			avlC.insert(std::pair<double,std::string>(i, "test"));
		}
		std::map<double,std::string>::const_iterator map_it = mapC.end();
		avltree<double,std::string>::const_iterator avl_it = avlC.cend();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
	//**************************int,Object*********************************
	{
		std::map<int,KaylaTestObject> mapC;
		avltree<int,KaylaTestObject> avlC;
		KaylaTestObject test;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
		}
		std::map<int,KaylaTestObject>::const_iterator map_it = mapC.end();
		avltree<int,KaylaTestObject>::const_iterator avl_it = avlC.cend();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
}

//**	iterator end() */
BOOST_AUTO_TEST_CASE( ut_end ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::end()\n";
	//**************************Int,Int********************************
	{
		std::map<int,int> map_int_int;
		avltree<int,int> avltree_int_int;

		for(int i = 0; i != 10; ++i){
			map_int_int.insert(std::pair<int,int>(i, 100));
			avltree_int_int.insert(std::pair<int,int>(i, 100));
		}
		std::map<int,int>::iterator map_it = map_int_int.end();
		avltree<int,int>::iterator avl_it = avltree_int_int.end();

		BOOST_CHECK(map_it == map_int_int.end());
		BOOST_CHECK(map_it == map_int_int.cend());
		BOOST_CHECK(avl_it == avltree_int_int.end());
		BOOST_CHECK(avl_it == avltree_int_int.cend());
	}
	//**************************Char,Int*********************************
	{
		std::map<char,int> mapC;
		avltree<char,int> avlC;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<char,int>('a'+i, 100));
			avlC.insert(std::pair<char,int>('a'+i, 100));
		}
		std::map<char,int>::iterator map_it = mapC.end();
		avltree<char,int>::iterator avl_it = avlC.end();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
	//**************************Double,String*********************************
	{
		std::map<double,std::string> mapC;
		avltree<double,std::string> avlC;
		for(double i = 0.1; i != 10.1; ++i){
			mapC.insert(std::pair<double,std::string>(i, "test"));
			avlC.insert(std::pair<double,std::string>(i, "test"));
		}
		std::map<double,std::string>::iterator map_it = mapC.end();
		avltree<double,std::string>::iterator avl_it = avlC.end();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
	//**************************int,Object*********************************
	{
		std::map<int,KaylaTestObject> mapC;
		avltree<int,KaylaTestObject> avlC;
		KaylaTestObject test;
		for(int i = 0; i != 10; ++i){
			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
		}
		std::map<int,KaylaTestObject>::iterator map_it = mapC.end();
		avltree<int,KaylaTestObject>::iterator avl_it = avlC.end();

		BOOST_CHECK(map_it == mapC.end());
		BOOST_CHECK(map_it == mapC.cend());
		BOOST_CHECK(avl_it == avlC.end());
		BOOST_CHECK(avl_it == avlC.cend());
	}
}

//**	const_iterator crbegin() const */
BOOST_AUTO_TEST_CASE( ut_crbegin_const ) {
	std::cout << "NOT IMPLEMENTED: avltree<T>::crbegin() const\n";
	////**************************Int,Int*********************************
	//{
	//	std::map<int,int> map_int_int;
	//	avltree<int,int> avltree_int_int;

	//	for(int i = 0; i != 10; ++i){
	//		map_int_int.insert(std::pair<int,int>(i, 100));
	//		avltree_int_int.insert(std::pair<int,int>(i, 100));
	//	}
	//	std::map<int,int>::const_reverse_iterator map_it = map_int_int.crbegin();
	//	avltree<int,int>::const_reverse_iterator avl_it = avltree_int_int.crbegin();

	//	BOOST_CHECK(map_it == map_int_int.crbegin());
	//	BOOST_CHECK(map_it == map_int_int.rbegin());
	//	BOOST_CHECK(avl_it == avltree_int_int.crbegin());
	//	BOOST_CHECK(avl_it == avltree_int_int.rbegin());
	//	BOOST_CHECK(map_it->first == avl_it->first);
	//	BOOST_CHECK(map_it->second == avl_it->second);
	//}
	////**************************Char,Int*********************************
	//{
	//	std::map<char,int> mapC;
	//	avltree<char,int> avlC;
	//	for(int i = 0; i != 10; ++i){
	//		mapC.insert(std::pair<char,int>('a'+i, 100));
	//		avlC.insert(std::pair<char,int>('a'+i, 100));
	//	}
	//	std::map<char,int>::const_reverse_iterator map_it = mapC.crbegin();
	//	avltree<char,int>::const_reverse_iterator avl_it = avlC.crbegin();

	//	BOOST_CHECK(map_it == mapC.crbegin());
	//	BOOST_CHECK(map_it == mapC.rbegin());
	//	BOOST_CHECK(avl_it == avlC.crbegin());
	//	BOOST_CHECK(avl_it == avlC.rbegin());
	//	BOOST_CHECK(map_it->first == avl_it->first);
	//	BOOST_CHECK(map_it->second == avl_it->second);
	//}
	////**************************Double,String*********************************
	//{
	//	std::map<double,std::string> mapC;
	//	avltree<double,std::string> avlC;
	//	for(double i = 0.1; i != 10.1; ++i){
	//		mapC.insert(std::pair<double,std::string>(i, "test"));
	//		avlC.insert(std::pair<double,std::string>(i, "test"));
	//	}
	//	std::map<double,std::string>::const_reverse_iterator map_it = mapC.crbegin();
	//	avltree<double,std::string>::const_reverse_iterator avl_it = avlC.crbegin();

	//	BOOST_CHECK(map_it == mapC.crbegin());
	//	BOOST_CHECK(map_it == mapC.rbegin());
	//	BOOST_CHECK(avl_it == avlC.crbegin());
	//	BOOST_CHECK(avl_it == avlC.rbegin());
	//	BOOST_CHECK(map_it->first == avl_it->first);
	//	BOOST_CHECK(map_it->second == avl_it->second);
	//}
	////**************************int,Object*********************************
	//{
	//	std::map<int,KaylaTestObject> mapC;
	//	avltree<int,KaylaTestObject> avlC;
	//	KaylaTestObject test;
	//	for(int i = 0; i != 10; ++i){
	//		mapC.insert(std::pair<int,KaylaTestObject>(i,test));
	//		avlC.insert(std::pair<int,KaylaTestObject>(i, test));
	//	}
	//	std::map<int,KaylaTestObject>::const_reverse_iterator map_it = mapC.crbegin();
	//	avltree<int,KaylaTestObject>::const_reverse_iterator avl_it = avlC.crbegin();

	//	BOOST_CHECK(map_it == mapC.crbegin());
	//	BOOST_CHECK(map_it == mapC.rbegin());
	//	BOOST_CHECK(avl_it == avlC.crbegin());
	//	BOOST_CHECK(avl_it == avlC.rbegin());
	//	BOOST_CHECK(map_it->first == avl_it->first);
	//}
}

//**	const_iterator crend() const */
BOOST_AUTO_TEST_CASE( ut_crend_const ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::crend() const\n";
//	//**************************Int,Int*********************************
//	{
//		std::map<int,int> map_int_int;
//		avltree<int,int> avltree_int_int;
//
//		for(int i = 0; i != 10; ++i){
//			map_int_int.insert(std::pair<int,int>(i, 100));
//			avltree_int_int.insert(std::pair<int,int>(i, 100));
//		}
//		std::map<int,int>::const_reverse_iterator map_it = map_int_int.rend();
//		avltree<int,int>::const_reverse_iterator avl_it = avltree_int_int.rend();
//
//		BOOST_CHECK(map_it == map_int_int.rend());
//		BOOST_CHECK(map_it == map_int_int.crend());
//		BOOST_CHECK(avl_it == avltree_int_int.rend());
//		BOOST_CHECK(avl_it == avltree_int_int.crend());
//	}
//	//**************************Char,Int*********************************
//	{
//		std::map<char,int> mapC;
//		avltree<char,int> avlC;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<char,int>('a'+i, 100));
//			avlC.insert(std::pair<char,int>('a'+i, 100));
//		}
//		std::map<char,int>::const_reverse_iterator map_it = mapC.rend();
//		avltree<char,int>::const_reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
//	//**************************Double,String*********************************
//	{
//		std::map<double,std::string> mapC;
//		avltree<double,std::string> avlC;
//		for(double i = 0.1; i != 10.1; ++i){
//			mapC.insert(std::pair<double,std::string>(i, "test"));
//			avlC.insert(std::pair<double,std::string>(i, "test"));
//		}
//		std::map<double,std::string>::const_reverse_iterator map_it = mapC.rend();
//		avltree<double,std::string>::const_reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
//	//**************************int,Object*********************************
//	{
//		std::map<int,KaylaTestObject> mapC;
//		avltree<int,KaylaTestObject> avlC;
//		KaylaTestObject test;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
//			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
//		}
//		std::map<int,KaylaTestObject>::const_reverse_iterator map_it = mapC.rend();
//		avltree<int,KaylaTestObject>::const_reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
}

///**	const_reverse_iterator rbegin() const */
BOOST_AUTO_TEST_CASE( ut_rbegin_const ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::rbegin() const\n";
//	//**************************Int,Int*********************************
//	{
//		std::map<int,int> map_int_int;
//		avltree<int,int> avltree_int_int;
//
//		for(int i = 0; i != 10; ++i){
//			map_int_int.insert(std::pair<int,int>(i, 100));
//			avltree_int_int.insert(std::pair<int,int>(i, 100));
//		}
//		std::map<int,int>::const_reverse_iterator map_it = map_int_int.rbegin();
//		avltree<int,int>::const_reverse_iterator avl_it = avltree_int_int.rbegin();
//
//		BOOST_CHECK(map_it == map_int_int.crbegin());
//		BOOST_CHECK(map_it == map_int_int.rbegin());
//		BOOST_CHECK(avl_it == avltree_int_int.crbegin());
//		BOOST_CHECK(avl_it == avltree_int_int.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//		BOOST_CHECK(map_it->second == avl_it->second);
//	}
//	//**************************Char,Int*********************************
//	{
//		std::map<char,int> mapC;
//		avltree<char,int> avlC;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<char,int>('a'+i, 100));
//			avlC.insert(std::pair<char,int>('a'+i, 100));
//		}
//		std::map<char,int>::const_reverse_iterator map_it = mapC.rbegin();
//		avltree<char,int>::const_reverse_iterator avl_it = avlC.rbegin();
//
//		BOOST_CHECK(map_it == mapC.crbegin());
//		BOOST_CHECK(map_it == mapC.rbegin());
//		BOOST_CHECK(avl_it == avlC.crbegin());
//		BOOST_CHECK(avl_it == avlC.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//		BOOST_CHECK(map_it->second == avl_it->second);
//	}
//	//**************************Double,String*********************************
//	{
//		std::map<double,std::string> mapC;
//		avltree<double,std::string> avlC;
//		for(double i = 0.1; i != 10.1; ++i){
//			mapC.insert(std::pair<double,std::string>(i, "test"));
//			avlC.insert(std::pair<double,std::string>(i, "test"));
//		}
//		std::map<double,std::string>::const_reverse_iterator map_it = mapC.rbegin();
//		avltree<double,std::string>::const_reverse_iterator avl_it = avlC.rbegin();
//
//		BOOST_CHECK(map_it == mapC.crbegin());
//		BOOST_CHECK(map_it == mapC.rbegin());
//		BOOST_CHECK(avl_it == avlC.crbegin());
//		BOOST_CHECK(avl_it == avlC.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//		BOOST_CHECK(map_it->second == avl_it->second);
//	}
//	//**************************int,Object*********************************
//	{
//		std::map<int,KaylaTestObject> mapC;
//		avltree<int,KaylaTestObject> avlC;
//		KaylaTestObject test;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
//			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
//		}
//		std::map<int,KaylaTestObject>::const_reverse_iterator map_it = mapC.rbegin();
//		avltree<int,KaylaTestObject>::const_reverse_iterator avl_it = avlC.rbegin();
//
//		BOOST_CHECK(map_it == mapC.crbegin());
//		BOOST_CHECK(map_it == mapC.rbegin());
//		BOOST_CHECK(avl_it == avlC.crbegin());
//		BOOST_CHECK(avl_it == avlC.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//	}
}

///**	reverse_iterator rbegin() */
BOOST_AUTO_TEST_CASE( ut_rbegin ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::rbegin()\n";
//	//**************************Int,Int*********************************
//	{
//		std::map<int,int> map_int_int;
//		avltree<int,int> avltree_int_int;
//
//		for(int i = 0; i != 10; ++i){
//			map_int_int.insert(std::pair<int,int>(i, 100));
//			avltree_int_int.insert(std::pair<int,int>(i, 100));
//		}
//		std::map<int,int>::reverse_iterator map_it = map_int_int.rbegin();
//		avltree<int,int>::reverse_iterator avl_it = avltree_int_int.rbegin();
//
//		BOOST_CHECK(map_it == map_int_int.crbegin());
//		BOOST_CHECK(map_it == map_int_int.rbegin());
//		BOOST_CHECK(avl_it == avltree_int_int.crbegin());
//		BOOST_CHECK(avl_it == avltree_int_int.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//		BOOST_CHECK(map_it->second == avl_it->second);
//	}
//	//**************************Char,Int*********************************
//	{
//		std::map<char,int> mapC;
//		avltree<char,int> avlC;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<char,int>('a'+i, 100));
//			avlC.insert(std::pair<char,int>('a'+i, 100));
//		}
//		std::map<char,int>::reverse_iterator map_it = mapC.rbegin();
//		avltree<char,int>::reverse_iterator avl_it = avlC.rbegin();
//
//		BOOST_CHECK(map_it == mapC.crbegin());
//		BOOST_CHECK(map_it == mapC.rbegin());
//		BOOST_CHECK(avl_it == avlC.crbegin());
//		BOOST_CHECK(avl_it == avlC.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//		BOOST_CHECK(map_it->second == avl_it->second);
//	}
//	//**************************Double,String*********************************
//	{
//		std::map<double,std::string> mapC;
//		avltree<double,std::string> avlC;
//		for(double i = 0.1; i != 10.1; ++i){
//			mapC.insert(std::pair<double,std::string>(i, "test"));
//			avlC.insert(std::pair<double,std::string>(i, "test"));
//		}
//		std::map<double,std::string>::reverse_iterator map_it = mapC.rbegin();
//		avltree<double,std::string>::reverse_iterator avl_it = avlC.rbegin();
//
//		BOOST_CHECK(map_it == mapC.crbegin());
//		BOOST_CHECK(map_it == mapC.rbegin());
//		BOOST_CHECK(avl_it == avlC.crbegin());
//		BOOST_CHECK(avl_it == avlC.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//		BOOST_CHECK(map_it->second == avl_it->second);
//	}
//	//**************************int,Object*********************************
//	{
//		std::map<int,KaylaTestObject> mapC;
//		avltree<int,KaylaTestObject> avlC;
//		KaylaTestObject test;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
//			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
//		}
//		std::map<int,KaylaTestObject>::reverse_iterator map_it = mapC.rbegin();
//		avltree<int,KaylaTestObject>::reverse_iterator avl_it = avlC.rbegin();
//
//		BOOST_CHECK(map_it == mapC.crbegin());
//		BOOST_CHECK(map_it == mapC.rbegin());
//		BOOST_CHECK(avl_it == avlC.crbegin());
//		BOOST_CHECK(avl_it == avlC.rbegin());
//		BOOST_CHECK(map_it->first == avl_it->first);
//	}
}

///**	const_reverse_iterator rend() const */
BOOST_AUTO_TEST_CASE( ut_rend_const ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::rend() const\n";
//	//**************************Int,Int*********************************
//	{
//		std::map<int,int> map_int_int;
//		avltree<int,int> avltree_int_int;
//
//		for(int i = 0; i != 10; ++i){
//			map_int_int.insert(std::pair<int,int>(i, 100));
//			avltree_int_int.insert(std::pair<int,int>(i, 100));
//		}
//		std::map<int,int>::const_reverse_iterator map_it = map_int_int.rend();
//		avltree<int,int>::const_reverse_iterator avl_it = avltree_int_int.rend();
//
//		BOOST_CHECK(map_it == map_int_int.rend());
//		BOOST_CHECK(map_it == map_int_int.crend());
//		BOOST_CHECK(avl_it == avltree_int_int.rend());
//		BOOST_CHECK(avl_it == avltree_int_int.crend());
//	}
//	//**************************Char,Int*********************************
//	{
//		std::map<char,int> mapC;
//		avltree<char,int> avlC;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<char,int>('a'+i, 100));
//			avlC.insert(std::pair<char,int>('a'+i, 100));
//		}
//		std::map<char,int>::const_reverse_iterator map_it = mapC.rend();
//		avltree<char,int>::const_reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
//	//**************************Double,String*********************************
//	{
//		std::map<double,std::string> mapC;
//		avltree<double,std::string> avlC;
//		for(double i = 0.1; i != 10.1; ++i){
//			mapC.insert(std::pair<double,std::string>(i, "test"));
//			avlC.insert(std::pair<double,std::string>(i, "test"));
//		}
//		std::map<double,std::string>::const_reverse_iterator map_it = mapC.rend();
//		avltree<double,std::string>::const_reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
//	//**************************int,Object*********************************
//	{
//		std::map<int,KaylaTestObject> mapC;
//		avltree<int,KaylaTestObject> avlC;
//		KaylaTestObject test;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
//			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
//		}
//		std::map<int,KaylaTestObject>::const_reverse_iterator map_it = mapC.rend();
//		avltree<int,KaylaTestObject>::const_reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
}
//
///**	reverse_iterator rend() */
BOOST_AUTO_TEST_CASE( ut_rend ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::rend()\n";
//		//**************************Int,Int*********************************
//	{
//		std::map<int,int> map_int_int;
//		avltree<int,int> avltree_int_int;
//
//		for(int i = 0; i != 10; ++i){
//			map_int_int.insert(std::pair<int,int>(i, 100));
//			avltree_int_int.insert(std::pair<int,int>(i, 100));
//		}
//		std::map<int,int>::reverse_iterator map_it = map_int_int.rend();
//		avltree<int,int>::reverse_iterator avl_it = avltree_int_int.rend();
//
//		BOOST_CHECK(map_it == map_int_int.rend());
//		BOOST_CHECK(map_it == map_int_int.crend());
//		BOOST_CHECK(avl_it == avltree_int_int.rend());
//		BOOST_CHECK(avl_it == avltree_int_int.crend());
//	}
//	//**************************Char,Int*********************************
//	{
//		std::map<char,int> mapC;
//		avltree<char,int> avlC;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<char,int>('a'+i, 100));
//			avlC.insert(std::pair<char,int>('a'+i, 100));
//		}
//		std::map<char,int>::reverse_iterator map_it = mapC.rend();
//		avltree<char,int>::reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
//	//**************************Double,String*********************************
//	{
//		std::map<double,std::string> mapC;
//		avltree<double,std::string> avlC;
//		for(double i = 0.1; i != 10.1; ++i){
//			mapC.insert(std::pair<double,std::string>(i, "test"));
//			avlC.insert(std::pair<double,std::string>(i, "test"));
//		}
//		std::map<double,std::string>::reverse_iterator map_it = mapC.rend();
//		avltree<double,std::string>::reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
//	//**************************int,Object*********************************
//	{
//		std::map<int,KaylaTestObject> mapC;
//		avltree<int,KaylaTestObject> avlC;
//		KaylaTestObject test;
//		for(int i = 0; i != 10; ++i){
//			mapC.insert(std::pair<int,KaylaTestObject>(i,test));
//			avlC.insert(std::pair<int,KaylaTestObject>(i, test));
//		}
//		std::map<int,KaylaTestObject>::reverse_iterator map_it = mapC.rend();
//		avltree<int,KaylaTestObject>::reverse_iterator avl_it = avlC.rend();
//
//		BOOST_CHECK(map_it == mapC.rend());
//		BOOST_CHECK(map_it == mapC.crend());
//		BOOST_CHECK(avl_it == avlC.rend());
//		BOOST_CHECK(avl_it == avlC.crend());
//	}
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