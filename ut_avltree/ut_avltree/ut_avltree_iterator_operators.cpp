///**	@file: ut_avltree_iterator_operators.cpp
//	@author Garth Santor
//	@author gsantor@fanshaweonline.ca
//	@author http://www.gats.ca/
//	@date 2013-01-16
//	@version 0.0.0
//	@note Developed for C++ 11
//	@brief avltree<T>::iterator::operator unit tests.
//	*/
//
#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <map>
#include "KaylaTestObject.hpp"
#include "avltree.hpp"
//
//
//
///**	iterator operator pre++ */
BOOST_AUTO_TEST_CASE( ut_iterator_pre_inc ) 
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator++(int)\n";
	KaylaTestObject Test;

	std::map<char, int> mapcharint;
	std::map<char,int>::iterator itmapcharint;
	avltree<char, int> avlcharint;

	avltree<char, int>::iterator itavlcharint;

	std::map<int,KaylaTestObject> mapObjectTest;
	std::map<int,KaylaTestObject>::iterator itMapObject;
	avltree<int, KaylaTestObject> avlObjectTest;
	avltree<int,KaylaTestObject>::iterator itavlIntObject;
	std::map<double, std::string> mapDoubleStringTest;
	std::map<double,std::string>::iterator itMapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	avltree<double, std::string>::iterator itavlDoubleString;


	for(unsigned int i = 0; i <= 20; ++i)
	{
		double test = i * 1.0;
		mapcharint.insert(std::pair<char,int>('a'+i, i));
		avlcharint.insert(std::pair<char,int>('a'+i, i));
		mapObjectTest.insert(std::pair<int, KaylaTestObject>(i, Test));
		avlObjectTest.insert(std::pair<int,KaylaTestObject>(i, Test));
		mapDoubleStringTest.insert(std::pair<double, std::string>(test,"Test"));
		avlDoubleStringTest.insert(std::pair<double, std::string>(test,"Test"));

	}
	int i;

	for(itmapcharint = mapcharint.begin(), i = 0; itmapcharint != mapcharint.end(); ++itmapcharint, ++i)
	{
		BOOST_CHECK_EQUAL(itmapcharint->second, i);
	}

	for(itavlcharint = avlcharint.begin(), i = 0; itavlcharint != avlcharint.end(); ++itavlcharint, ++i)
	{
		BOOST_CHECK_EQUAL(itavlcharint->second, i);
	}

	for(itMapObject = mapObjectTest.begin(), i = 0; itMapObject != mapObjectTest.end(); ++itMapObject, ++i)
	{
		BOOST_CHECK_EQUAL(itMapObject->first, i);
	}

	for(itavlIntObject = avlObjectTest.begin(), i = 0; itavlIntObject != avlObjectTest.end(); ++itavlIntObject, ++i)
	{
		BOOST_CHECK_EQUAL(itavlIntObject->first, i);
	}
}


///**	iterator operator post++ */
BOOST_AUTO_TEST_CASE( ut_iterator_post_inc ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator++()\n";
	std::map<char, int> mapcharint;
	std::map<char,int>::iterator itmapcharint;
	avltree<char, int> avlcharint;
	avltree<char, int>::iterator itavlcharint;
	std::map<int,KaylaTestObject> mapObjectTest;
	std::map<int,KaylaTestObject>::iterator itMapObject;
	avltree<int, KaylaTestObject> avlObjectTest;
	avltree<int,KaylaTestObject>::iterator itavlIntObject;
	std::map<double, std::string> mapDoubleStringTest;
	std::map<double,std::string>::iterator itMapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	avltree<double, std::string>::iterator itavlDoubleString;
	

	for(unsigned int i = 0; i <= 20; i++)
	{
		mapcharint.insert(std::pair<char,int>('a'+i, i));
		avlcharint.insert(std::pair<char,int>('a'+i, i));
	}

	int i;

	for(itmapcharint = mapcharint.begin(), i = 0; itmapcharint != mapcharint.end(); itmapcharint++, i++)
	{
		BOOST_CHECK_EQUAL(itmapcharint->second, i);
	}

	for(itavlcharint = avlcharint.begin(), i = 0; itavlcharint != avlcharint.end(); itavlcharint++, i++)
	{
		BOOST_CHECK_EQUAL(itavlcharint->second, i);
	}
	for(itMapObject = mapObjectTest.begin(), i = 0; itMapObject != mapObjectTest.end(); itMapObject++, i++)
	{
		BOOST_CHECK_EQUAL(itMapObject->first, i);
	}

	for(itavlIntObject = avlObjectTest.begin(), i = 0; itavlIntObject != avlObjectTest.end(); itavlIntObject++, i++)
	{
		BOOST_CHECK_EQUAL(itavlIntObject->first, i);
	}

}
//

///**	iterator operator pre-- */
BOOST_AUTO_TEST_CASE( ut_iterator_pre_dec ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator--(int)\n";
	
	std::map<char, int> mapcharint;
	std::map<char,int>::iterator itmapcharint;
	avltree<char, int> avlcharint;
	avltree<char, int>::iterator itavlcharint;
	std::map<int,KaylaTestObject> mapObjectTest;
	std::map<int,KaylaTestObject>::iterator itMapObject;
	avltree<int, KaylaTestObject> avlObjectTest;
	avltree<int,KaylaTestObject>::iterator itavlIntObject;
	std::map<double, std::string> mapDoubleStringTest;
	std::map<double,std::string>::iterator itMapDoubleStringTest;
	avltree<double, std::string> avlDoubleStringTest;
	avltree<double, std::string>::iterator itavlDoubleString;
	
	for(unsigned int i = 0; i <= 20; ++i)
	{
		mapcharint.insert(std::pair<char,int>('a'+i, i));
		avlcharint.insert(std::pair<char,int>('a'+i, i));
	}

	int i;

	for(itmapcharint = mapcharint.end(), i = 20; itmapcharint != mapcharint.begin(); --i)
	{
		--itmapcharint;
		BOOST_CHECK_EQUAL(itmapcharint->second, i);
	}

	//for(itavlcharint = avlcharint.end(), i = 20; itavlcharint != avlcharint.begin(); --i)
	//{
	//	--itavlcharint;
	//	BOOST_CHECK_EQUAL(itavlcharint->second, i);
	//}

	//for(itMapObject = mapObjectTest.end(), i = 20; itMapObject != mapObjectTest.begin();  --i)
	//{
	//	--itMapObject;
	//	BOOST_CHECK_EQUAL(itMapObject->first, i);
	//}

	//for(itavlIntObject = avlObjectTest.end(), i = 20; itavlIntObject != avlObjectTest.begin();  --i)
	//{
	//	--itavlIntObject;
	//	BOOST_CHECK_EQUAL(itavlIntObject->first, i);
	//}
}
//
//
//
//probably failing as well.
///**	iterator operator post-- */
BOOST_AUTO_TEST_CASE( ut_iterator_post_dec ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator--()\n";
//
//	std::map<char, int> mapcharint;
//	std::map<char,int>::iterator itmapcharint;
//	avltree<char, int> avlcharint;
//	avltree<char, int>::iterator itavlcharint;
//	std::map<int,KaylaTestObject> mapObjectTest;
//	std::map<int,KaylaTestObject>::iterator itMapObject;
//	avltree<int, KaylaTestObject> avlObjectTest;
//	avltree<int,KaylaTestObject>::iterator itavlIntObject;
//	std::map<double, std::string> mapDoubleStringTest;
//	std::map<double,std::string>::iterator itMapDoubleStringTest;
//	avltree<double, std::string> avlDoubleStringTest;
//	avltree<double, std::string>::iterator itavlDoubleString;
//	std::map<int, std::map<int, int>> mapOuterTest;
//	std::map<int,std::map<int,int>>::iterator itIntMapIntInt;
//	avltree<int, std::map<int, int>> avlOuterTest;
//	avltree<int,std::map<int,int>>::iterator itAvlIntMapIntInt;
//	
//
//	for(unsigned int i = 0; i <= 20; ++i)
//	{
//		mapcharint.insert(std::pair<char,int>('a'+i, i));
//		avlcharint.insert(std::pair<char,int>('a'+i, i));
//	}
//
//	int i;
//
//	for(itmapcharint = mapcharint.end(), i = 20; itmapcharint != mapcharint.begin(); i--)
//	{
//		itmapcharint--;
//		BOOST_CHECK_EQUAL(itmapcharint->second, i);
//	}
//
//	for(itavlcharint = avlcharint.end(), i = 20; itavlcharint != avlcharint.begin(); i--)
//	{
//		itavlcharint--;
//		BOOST_CHECK_EQUAL(itavlcharint->second, i);
//	}
//	for(itMapObject = mapObjectTest.end(), i = 20; itMapObject != mapObjectTest.begin();  i--)
//	{
//		itMapObject--;
//		BOOST_CHECK_EQUAL(itMapObject->first, i);
//	}
//
//	for(itavlIntObject = avlObjectTest.end(), i = 20; itavlIntObject != avlObjectTest.begin();  i--)
//	{
//		itavlIntObject--;
//		BOOST_CHECK_EQUAL(itavlIntObject->first, i);
//	}
//
//	for(itIntMapIntInt = mapOuterTest.end(), i = 20; itIntMapIntInt != mapOuterTest.begin();  i--)
//	{
//		itIntMapIntInt--;
//		BOOST_CHECK_EQUAL(itIntMapIntInt->first, i);
//	}
//	for(itAvlIntMapIntInt = avlOuterTest.end(), i = 20; itAvlIntMapIntInt != avlOuterTest.begin(); i--)
//	{
//		itAvlIntMapIntInt--;
//		BOOST_CHECK_EQUAL(itAvlIntMapIntInt->first, i);
//	}
}
//
//
//



///**	iterator operator rev pre++ */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_pre_inc ) 
{
	std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator++(int)\n";
	
	//std::map<char, int> mapcharint;
	//std::map<char,int>::reverse_iterator itmapcharint;
	//avltree<char, int> avlcharint;
	//avltree<char, int>::reverse_iterator itavlcharint;
	//std::map<int,KaylaTestObject> mapObjectTest;
	//std::map<int,KaylaTestObject>::reverse_iterator itMapObject;
	//avltree<int, KaylaTestObject> avlObjectTest;
	//avltree<int,KaylaTestObject>::reverse_iterator itavlIntObject;
	//std::map<double, std::string> mapDoubleStringTest;
	//std::map<double,std::string>::reverse_iterator itMapDoubleStringTest;
	//avltree<double, std::string> avlDoubleStringTest;
	//avltree<double, std::string>::reverse_iterator itavlDoubleString;
	//

	//for(unsigned int i = 0; i <= 20; ++i)
	//{
	//	mapcharint.insert(std::pair<char,int>('a'+i, i));
	//	avlcharint.insert(std::pair<char,int>('a'+i, i));
	//}

	//int i;

	//for(itmapcharint = mapcharint.rbegin(), i = 20; itmapcharint != mapcharint.rend(); ++itmapcharint, --i)
	//{
	//	BOOST_CHECK_EQUAL(itmapcharint->second, i);
	//}

	//for(itavlcharint = avlcharint.rbegin(), i = 20; itavlcharint != avlcharint.rend(); ++itavlcharint, --i)
	//{
	//	BOOST_CHECK_EQUAL(itavlcharint->second, i);
	//}

	//for(itMapObject = mapObjectTest.rbegin(), i = 20; itMapObject != mapObjectTest.rend(); --itMapObject, --i)
	//{
	//	BOOST_CHECK_EQUAL(itMapObject->first, i);
	//}

	//for(itavlIntObject = avlObjectTest.rbegin(), i = 20; itavlIntObject != avlObjectTest.rend(); --itavlIntObject, --i)
	//{
	//	BOOST_CHECK_EQUAL(itavlIntObject->first, i);
	//}

}
//
//
//
//
//
//
///**	iterator operator rev post++ */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_post_inc ) {
//	
std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator++()\n";
//
//	std::map<char, int> mapcharint;
//	std::map<char,int>::reverse_iterator itmapcharint;
//	avltree<char, int> avlcharint;
//	avltree<char, int>::reverse_iterator itavlcharint;
//	std::map<int,KaylaTestObject> mapObjectTest;
//	std::map<int,KaylaTestObject>::reverse_iterator itMapObject;
//	avltree<int, KaylaTestObject> avlObjectTest;
//	avltree<int,KaylaTestObject>::reverse_iterator itavlIntObject;
//	std::map<double, std::string> mapDoubleStringTest;
//	std::map<double,std::string>::reverse_iterator itMapDoubleStringTest;
//	avltree<double, std::string> avlDoubleStringTest;
//	avltree<double, std::string>::reverse_iterator itavlDoubleString;
//	std::map<int, std::map<int, int>> mapOuterTest;
//	std::map<int,std::map<int,int>>::reverse_iterator itIntMapIntInt;
//	avltree<int, std::map<int, int>> avlOuterTest;
//	avltree<int,std::map<int,int>>::reverse_iterator itAvlIntMapIntInt;
//	
//
//	for(unsigned int i = 0; i <= 20; ++i)
//	{
//		mapcharint.insert(std::pair<char,int>('a'+i, i));
//		avlcharint.insert(std::pair<char,int>('a'+i, i));
//	}
//
//	int i;
//
//	for(itmapcharint = mapcharint.rbegin(), i = 20; itmapcharint != mapcharint.rend(); itmapcharint++, i--)
//	{
//		BOOST_CHECK_EQUAL(itmapcharint->second, i);
//	}
//
//	for(itavlcharint = avlcharint.rbegin(), i = 20; itavlcharint != avlcharint.rend(); itavlcharint++, i--)
//	{
//		BOOST_CHECK_EQUAL(itavlcharint->second, i);
//	}
//
//	for(itMapObject = mapObjectTest.rbegin(), i = 20; itMapObject != mapObjectTest.rend(); itMapObject++, i--)
//	{
//		BOOST_CHECK_EQUAL(itMapObject->first, i);
//	}
//
//	for(itavlIntObject = avlObjectTest.rbegin(), i = 20; itavlIntObject != avlObjectTest.rend(); itavlIntObject++, i--)
//	{
//		BOOST_CHECK_EQUAL(itavlIntObject->first, i);
//	}
//
//	for(itIntMapIntInt = mapOuterTest.rbegin(), i = 20; itIntMapIntInt != mapOuterTest.rend(); itIntMapIntInt++, i--)
//	{
//		BOOST_CHECK_EQUAL(itIntMapIntInt->first, i);
//	}
//	for(itAvlIntMapIntInt = avlOuterTest.rbegin(), i = 20; itAvlIntMapIntInt != avlOuterTest.rend(); itAvlIntMapIntInt++, i--)
//	{
//		BOOST_CHECK_EQUAL(itAvlIntMapIntInt->first, i);
//	}
}



//
///**	iterator operator rev pre-- */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_pre_dec ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator--(int)\n";
//
//	std::map<char, int> mapcharint;
//	std::map<char,int>::reverse_iterator itmapcharint;
//	avltree<char, int> avlcharint;
//	avltree<char, int>::reverse_iterator itavlcharint;
//	std::map<int,KaylaTestObject> mapObjectTest;
//	std::map<int,KaylaTestObject>::reverse_iterator itMapObject;
//	avltree<int, KaylaTestObject> avlObjectTest;
//	avltree<int,KaylaTestObject>::reverse_iterator itavlIntObject;
//	std::map<double, std::string> mapDoubleStringTest;
//	std::map<double,std::string>::reverse_iterator itMapDoubleStringTest;
//	avltree<double, std::string> avlDoubleStringTest;
//	avltree<double, std::string>::reverse_iterator itavlDoubleString;
//	std::map<int, std::map<int, int>> mapOuterTest;
//	std::map<int,std::map<int,int>>::reverse_iterator itIntMapIntInt;
//	avltree<int, std::map<int, int>> avlOuterTest;
//	avltree<int,std::map<int,int>>::reverse_iterator itAvlIntMapIntInt;
//	
//
//	for(unsigned int i = 0; i <= 20; ++i)
//	{
//		mapcharint.insert(std::pair<char,int>('a'+i, i));
//		avlcharint.insert(std::pair<char,int>('a'+i, i));
//	}
//
//	int i;
//
//	for(itmapcharint = mapcharint.rend(), i = 0; itmapcharint != mapcharint.rbegin(); ++i)
//	{
//		--itmapcharint;
//		BOOST_CHECK_EQUAL(itmapcharint->second, i);
//	}
//
//	for(itavlcharint = avlcharint.rend(), i = 0; itavlcharint != avlcharint.rbegin(); ++i)
//	{
//		--itavlcharint;
//		BOOST_CHECK_EQUAL(itavlcharint->second, i);
//	}
//
//	for(itMapObject = mapObjectTest.rbegin(), i = 0; itMapObject != mapObjectTest.rend();  ++i)
//	{
//		--itMapObject;
//		BOOST_CHECK_EQUAL(itMapObject->first, i);
//	}
//
//	for(itavlIntObject = avlObjectTest.rbegin(), i = 0; itavlIntObject != avlObjectTest.rend();  ++i)
//	{
//		--itavlIntObject;
//		BOOST_CHECK_EQUAL(itavlIntObject->first, i);
//	}
//
//	for(itIntMapIntInt = mapOuterTest.rbegin(), i = 0; itIntMapIntInt != mapOuterTest.rend();  ++i)
//	{
//		--itIntMapIntInt;
//		BOOST_CHECK_EQUAL(itIntMapIntInt->first, i);
//	}
//	for(itAvlIntMapIntInt = avlOuterTest.rbegin(), i = 0; itAvlIntMapIntInt != avlOuterTest.rend(); ++i)
//	{
//		 --itAvlIntMapIntInt;
//		BOOST_CHECK_EQUAL(itAvlIntMapIntInt->first, i);
//	}
}
//
//
//



///**	iterator operator rev post-- */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_post_dec ) {
std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator--()\n";
//
//	std::map<char, int> mapcharint;
//	std::map<char,int>::reverse_iterator itmapcharint;
//	avltree<char, int> avlcharint;
//	avltree<char, int>::reverse_iterator itavlcharint;
//	std::map<int,KaylaTestObject> mapObjectTest;
//	std::map<int,KaylaTestObject>::reverse_iterator itMapObject;
//	avltree<int, KaylaTestObject> avlObjectTest;
//	avltree<int,KaylaTestObject>::reverse_iterator itavlIntObject;
//	std::map<double, std::string> mapDoubleStringTest;
//	std::map<double,std::string>::reverse_iterator itMapDoubleStringTest;
//	avltree<double, std::string> avlDoubleStringTest;
//	avltree<double, std::string>::reverse_iterator itavlDoubleString;
//	std::map<int, std::map<int, int>> mapOuterTest;
//	std::map<int,std::map<int,int>>::reverse_iterator itIntMapIntInt;
//	avltree<int, std::map<int, int>> avlOuterTest;
//	avltree<int,std::map<int,int>>::reverse_iterator itAvlIntMapIntInt;
//	
//
//	for(unsigned int i = 0; i <= 20; ++i)
//	{
//		mapcharint.insert(std::pair<char,int>('a'+i, i));
//		avlcharint.insert(std::pair<char,int>('a'+i, i));
//	}
//
//	int i;
//
//	for(itmapcharint = mapcharint.rend(), i = 0; itmapcharint != mapcharint.rbegin(); ++i)
//	{
//		itmapcharint--;
//		BOOST_CHECK_EQUAL(itmapcharint->second, i);
//	}
//
//	for(itavlcharint = avlcharint.rend(), i = 0; itavlcharint != avlcharint.rbegin(); ++i)
//	{
//		itavlcharint--;
//		BOOST_CHECK_EQUAL(itavlcharint->second, i);
//	}
//
//	for(itMapObject = mapObjectTest.rbegin(), i = 0; itMapObject != mapObjectTest.rend();  ++i)
//	{
//		itMapObject--;
//		BOOST_CHECK_EQUAL(itMapObject->first, i);
//	}
//
//	for(itavlIntObject = avlObjectTest.rbegin(), i = 0; itavlIntObject != avlObjectTest.rend();  ++i)
//	{
//		itavlIntObject--;
//		BOOST_CHECK_EQUAL(itavlIntObject->first, i);
//	}
//
//	for(itIntMapIntInt = mapOuterTest.rbegin(), i = 0; itIntMapIntInt != mapOuterTest.rend();  ++i)
//	{
//		itIntMapIntInt--;
//		BOOST_CHECK_EQUAL(itIntMapIntInt->first, i);
//	}
//	for(itAvlIntMapIntInt = avlOuterTest.rbegin(), i = 0; itAvlIntMapIntInt != avlOuterTest.rend(); ++i)
//	{
//		 itAvlIntMapIntInt--;
//		BOOST_CHECK_EQUAL(itAvlIntMapIntInt->first, i);
//	}
//
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