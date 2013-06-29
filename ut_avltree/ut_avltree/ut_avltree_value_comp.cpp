///**	@file: ut_avltree_value_comp.cpp
//	@author Garth Santor
//	@author gsantor@fanshaweonline.ca
//	@author http://www.gats.ca/
//	@date 2013-01-16
//	@version 0.0.0
//	@note Developed for C++ 11
//	@brief avltree<T>::value_comp() unit tests.
//	*/
//
#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "KaylaTestObject.hpp"
#include "avltree.hpp"
#include <map>
//
///*
//Returns a comparison object that can be used to compare two elements to 
//get whether the key of the first one goes before the second.
//
//The arguments taken by this function object are of member 
//type value_type (defined in map as an alias of pair<const key_type,mapped_type>), 
//but the mapped_type part of the value is not taken into consideration in this comparison.
//
//The comparison object returned is an object of the member type 
//map::value_compare, which is a nested class that uses the internal 
//comparison object to generate the appropriate comparison functional class.
//
//*/
//
///**	value_compare value_comp() const */
BOOST_AUTO_TEST_CASE( ut_value_comp ) 
{
	std::cout << "NOT IMPLEMENTED: avltree<T>::value_comp() const\n";
//	
//	std::map<char, int> mapPrimTest;
//	avltree<char, int> avlPrimTest;
//
//    std::vector<char> asciiChars;
//	for(unsigned int i = 0; i < 154; i++)
//	{
//		asciiChars.push_back('z' - (char)i);
//	}
//
//	std::vector<char>::iterator asciiIter;
//
//	for(asciiIter = asciiChars.begin(); asciiIter != asciiChars.end(); asciiIter++)
//	{
//		mapPrimTest.insert(std::pair<char, int>(*asciiIter, 1 ));
//		avlPrimTest.insert(std::pair<char, int>(*asciiIter, 1));	
//	}
//
//	//check to see that they compare correctly.
//	//key value of the last element. 
//	std::pair<char, int> mapHighest;
//	std::pair<char, int> avlHighest;
//	mapHighest = *mapPrimTest.rbegin();
//
//	avlHighest = *avlPrimTest.rbegin();
//
//	std::map<char,int>::iterator mapIt = mapPrimTest.begin();
//	avltree<char,int>::iterator avlIt = avlPrimTest.begin();
//
//	//should return true, until they are equal 
//	for(mapIt = mapPrimTest.begin(); mapIt != mapPrimTest.end(); mapIt++  )
//	 {
//		 if((*mapIt).first != (mapHighest).first)
//		 {
//			 BOOST_CHECK( mapPrimTest.value_comp()(*mapIt, mapHighest) == true);
//		 }
//		 else
//		 {
//			 BOOST_CHECK( mapPrimTest.value_comp()(*mapIt, mapHighest) == false);
//		 }
//    } 
//
//	//for(avlIt = avlPrimTest.begin(); avlIt != avlPrimTest.end(); avlIt++  )
//	// {
//	//	 if((*avlIt).first != (avlHighest).first)
//	//	 {
//	//		 BOOST_CHECK( avlPrimTest.value_comp()(*avlIt, avlHighest) == true);
//	//	 }
//	//	/* else
//	//	 {
//	//		 BOOST_CHECK( avlPrimTest.value_comp()(*avlIt, avlHighest) == false);
//	//	 }*/
// //   } 
//
//	
//	////should return true, until they are equal 
//	//for(mapIt = mapPrimTest.begin(); mapIt != mapPrimTest.end(); mapIt++  )
//	// {
//	//	 std::map<char,int>::iterator mapIt2 = mapIt;
//	//	 mapIt2++;
//
//	//	 if((*mapIt).first != (mapHighest).first)
//	//	 {
//	//		 BOOST_CHECK( mapPrimTest.value_comp()(*mapIt, *mapIt2)  == true);
//	//	 }
// //   } 
//
//
//	//for(avlIt = avlPrimTest.begin(); avlIt != avlPrimTest.end(); avlIt++  )
//	// {
//	//	 avltree<char,int>::iterator avlIt2 = avlIt;
//	//	 avlIt2++;
//	//	 if(( *avlIt).first != (avlHighest).first)
//	//	 {
//	//		 BOOST_CHECK_EQUAL( avlPrimTest.value_comp()(*avlIt, *avlIt2), true);
//	//	 }
// //   } 
//
////    
////	//try using double 
//	std::map<double, int> mapDoubleTest;
//	avltree<double, int> avlDoubleTest;
//
//    std::vector<double> testNums;
//	
//	for(double i = 0.5; i < 10; i++)
//	{
//		testNums.push_back(i);
//	}
//
//	std::vector<double>::iterator doubleIter;
//
//
//	for(doubleIter = testNums.begin(); doubleIter != testNums.end(); doubleIter++)
//	{
//		mapDoubleTest.insert(std::pair<double, int>(*doubleIter, 1 ));
//		avlDoubleTest.insert(std::pair<double, int>(*doubleIter, 1));	
//	}
//
//	//check to see that they compare correctly.
//	//key value of the last element. 
//	std::pair<double, int> mapHighestDouble;
//	std::pair<double, int> avlHighestDouble;
//	
//	mapHighestDouble = *mapDoubleTest.rbegin();
//	avlHighestDouble = *avlDoubleTest.rbegin();
//
//	double check = avlDoubleTest.rbegin()->first;
//
//	std::map<double,int>::iterator mapItDouble = mapDoubleTest.begin();
//	avltree<double,int>::iterator avlItDouble = avlDoubleTest.begin();
//
//
//
//	//should return true, until they are equal 
//	for(mapItDouble = mapDoubleTest.begin(); mapItDouble != mapDoubleTest.end(); mapItDouble++  )
//	 {
//		 if((*mapItDouble).first != (mapHighestDouble).first)
//		 {
//			 BOOST_CHECK_EQUAL( mapDoubleTest.value_comp()(*mapItDouble, mapHighestDouble), true);
//		 }
//		 else
//		 {
//			 BOOST_CHECK_EQUAL( mapDoubleTest.value_comp()(*mapItDouble, mapHighestDouble), false);
//		 }
//    } 
//
//	//for(avlItDouble = avlDoubleTest.begin(); avlItDouble != avlDoubleTest.end(); avlItDouble++  )
//	// {
//	//	 if((*avlItDouble).first != (avlHighestDouble).first)
//	//	 {
//	//		 BOOST_CHECK_EQUAL( avlDoubleTest.value_comp()(*avlItDouble, avlHighestDouble), true);
//	//	 }
//	//	 else
//	//	 {
//	//		 BOOST_CHECK_EQUAL( avlDoubleTest.value_comp()(*avlItDouble, avlHighestDouble), false);
//	//	 }
// //   } 
//
////	//should return true, until they are equal 
////	for(mapItDouble = mapDoubleTest.begin(); mapItDouble != mapDoubleTest.end(); mapItDouble++  )
////	 {
////		  std::map<double,int>::iterator mapItDouble2 = mapItDouble;
////		  mapItDouble2++;
////		  
////		  if((*mapItDouble).first != (mapHighestDouble).first)
////		 {
////			 BOOST_CHECK_EQUAL( mapDoubleTest.value_comp()(*mapItDouble, *mapItDouble2), true);
////		 }
////    } 
////
////
////	//for(avlItDouble = avlDoubleTest.begin(); avlItDouble != avlDoubleTest.end(); avlItDouble++  )
////	//{
////	//	  avltree<double,int>::iterator avlItDouble2 = avlItDouble;
////	//	  avlItDouble2++;
////
////	//	 if((*avlItDouble).first != (avlHighestDouble).first)
////	//	 {
////	//		 BOOST_CHECK_EQUAL( avlDoubleTest.value_comp()(*mapItDouble, *avlItDouble2), true);
////	//	 }
//// //   } 
////
////
////
////
////	//string test 
////	std::map<std::string, int> mapStringTest;
////	avltree<std::string, int> avlStringTest;
////
////	std::vector<std::string> testStringValues;
////	
////	//iterate over uppercase ascii characters backwards 
////	for(unsigned int i = 90; i > 65; i--)
////	{
////		char upperCase = (char)i;
////		testStringValues.push_back(upperCase +  ":upper");
////		unsigned int j = 97;
////		char lowerCase = (char)j++;
////		testStringValues.push_back(lowerCase + ":lower");
////	}
////
////	std::vector<std::string>::iterator stringIter;
////
////	for(stringIter = testStringValues.begin(); stringIter != testStringValues.end(); stringIter++)
////	{
////		mapStringTest.insert(std::pair<std::string, int>(*stringIter, 1 ));
////		avlStringTest.insert(std::pair<std::string, int>(*stringIter, 1));	
////	}
////
////	//check to see that they compare correctly.
////	//key value of the last element. 
////	std::pair<std::string, int> mapHighestString;
////	std::pair<std::string, int> avlHighestString;
////
////	mapHighestString = *mapStringTest.rbegin();
////	avlHighestString = *avlStringTest.rbegin();
////
////	std::map<std::string,int>::iterator mapit3 = mapStringTest.begin();
////	avltree<std::string,int>::iterator avlIt3 = avlStringTest.begin();
////
////	//should return true, until they are equal 
////	for(mapit3 = mapStringTest.begin(); mapit3 != mapStringTest.end(); mapit3++  )
////	 {
////		 if((*mapit3).first != (mapHighestString).first)
////		 {
////			 BOOST_CHECK_EQUAL( mapStringTest.value_comp()(*mapit3, mapHighestString), true);
////		 }
////		 else
////		 {
////			 BOOST_CHECK_EQUAL( mapStringTest.value_comp()(*mapit3, mapHighestString), false);
////		 }
////    } 
////
////	for(avlIt3 = avlStringTest.begin(); avlIt3 != avlStringTest.end(); avlIt3++  )
////	 {
////		 if((*avlIt3).first != (avlHighestString).first)
////		 {
////			 BOOST_CHECK_EQUAL( avlStringTest.value_comp()(*avlIt3, avlHighestString), true);
////		 }
////		 else
////		 {
////			 BOOST_CHECK_EQUAL( avlStringTest.value_comp()(*avlIt3, avlHighestString), false);
////		 }
////    } 
////	
////
////
////	//Iterating through a map of objects 
////	std::map<KaylaTestObject, int> mapObjectTest;
////	avltree<KaylaTestObject, int> avlObjectTest;
////
////	std::vector<KaylaTestObject> testObjectValues;
////
////	//create some objects with different variables set 
////	KaylaTestObject myTestObj;
////	for(unsigned int i = 0; i < 10; i++)
////	{
////		myTestObj.doubleTest = 0.5 + i;
////		mapObjectTest[myTestObj] = 30;
////		avlObjectTest[myTestObj] = 30;	
////	}
////
////	//check to see that they compare correctly.
////	//key value of the last element. 
////	std::pair<KaylaTestObject, int> mapHighestObject;
////	std::pair<KaylaTestObject, int> avlHighestObject;
////	mapHighestObject = *mapObjectTest.rbegin();
////	avlHighestObject = *avlObjectTest.rbegin();
////
////	std::map<KaylaTestObject,int>::iterator mapItObject = mapObjectTest.begin();
////	avltree<KaylaTestObject,int>::iterator avlItObject = avlObjectTest.begin();
////
////	//should return true, until they are equal 
////	for(mapItObject = mapObjectTest.begin(); mapItObject != mapObjectTest.end(); mapItObject++  )
////	 {
////		 if((*mapItObject).first != (mapHighestObject).first)
////		 {
////			 BOOST_CHECK_EQUAL( mapObjectTest.value_comp()(*mapItObject, mapHighestObject), true);
////		 }
////		 else
////		 {
////			 BOOST_CHECK_EQUAL( mapObjectTest.value_comp()(*mapItObject, mapHighestObject), false);
////		 }
////    } 
////
////	for(avlItObject = avlObjectTest.begin(); avlItObject != avlObjectTest.end(); avlItObject++  )
////	 {
////		 if((*avlItObject).first != (avlHighestObject).first)
////		 {
////			 BOOST_CHECK_EQUAL( avlObjectTest.value_comp()(*avlItObject, avlHighestObject), true);
////		 }
////		 else
////		 {
////			 BOOST_CHECK_EQUAL( avlObjectTest.value_comp()(*avlItObject, avlHighestObject), false);
////		 }
////    } 
////
//
//
//
//
//	
}
//
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