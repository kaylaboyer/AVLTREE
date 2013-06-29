//Version: 4.4
//Date: February 28, 2013
#ifndef GUARD_avltree
#define GUARD_avltree
//Author:Kayla Boyer 
//An implementation of an Avltree which is a type of balancing binary 
//tree.
#include <functional>
#include <memory>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <vector>
#include <iostream>
template<class Key, class Type, class Traits = std::less<Key>, class Alloc = std::allocator<const Key>> 
class avltree 
{
protected:
	//a type representing a node in the avltree. 
	template<class value_type >
	class avlNode
	{
	public:
		
		avlNode(std::pair<Key,Type> pair) 
		{
			_ValuePair = pair;
			_Balance = 0;
			_Depth = 0;
			_Role = "Reg";
		}

		avlNode() {}
		
		std::shared_ptr<avlNode<std::pair<Key,Type> > > _Left;
		std::shared_ptr<avlNode<std::pair<Key,Type>>> _Right;
		std::pair<Key,Type> _ValuePair;
		int		_Balance;
		int		_Depth;
		std::string _Role;
	};


protected:
	friend class const_iterator;
	friend class iterator;
	//Need to keep track of the root node, as well 
	//as the node that is in front of begin, and the node that 
	//is behind end.
	std::shared_ptr<avlNode<std::pair<Key,Type>>> _RootNode;
	std::shared_ptr<avlNode<std::pair<Key,Type>>> _NullEnd;
	std::shared_ptr<avlNode<std::pair<Key,Type>>> _NullFront;

	//remvoes node 
	void Remove(std::shared_ptr<avlNode<std::pair<Key,Type>>>& root, const Key key, bool& delOK)
	{
		if (!root)
		{
			delOK = false;
		}
		else if (root->_ValuePair.first > key)	// go to left subtree
		{
			Remove(root->_Left, key, delOK);
			if (delOK)
			{
				ComputeBalance(root);
				BalanceRight(root);
			}
		}
		else if (root->_ValuePair.first < key) // go to right subtree
		{
			Remove(root->_Right, key, delOK);
			if (delOK)
			{
				ComputeBalance(root);
				BalanceLeft(root);
			}
		}
		else	// node found!
		{
			std::shared_ptr<avlNode<std::pair<Key, Type>>> pMe = root;

			if (!root->_Right)
			{
				root = root->_Left;
				delOK = true;
				pMe = nullptr;
				--_Size;
			}
			else if (!root->_Left)
			{
				root = root->_Right;
				delOK = true;
				pMe = nullptr;
				--_Size;
			}
			else
			{

				RemoveBothChildren(root, root->_Left, delOK);
				if (delOK)
				{
					ComputeBalance(root);
					Balance(root);
				}

				delOK = true;
			}
		}
	}

	//have to stich node together  
	void RemoveBothChildren	(std::shared_ptr<avlNode<std::pair<Key, Type>>>& root, std::shared_ptr<avlNode<std::pair<Key, Type>>>& curr, bool& delOK)
	{
		if (!curr->_Right)
		{
			root->_ValuePair = curr->_ValuePair;
			std::shared_ptr<avlNode<std::pair<Key, Type>>> pMe = curr;
			curr = curr->_Left;
			pMe = nullptr;
			delOK = true;
			--_Size;
		}
		else
		{
			RemoveBothChildren(root, curr->_Right, delOK);
			if (delOK)
			{
				ComputeBalance(root);
				Balance(root);
			}
		}
	}
	//integrated
	
	//determines if the tree is in or out of balance. 
	void ComputeBalance(std::shared_ptr<avlNode<std::pair<Key, Type>>>&  root)
	{
		int leftDepth;
		int rightDepth;

		if (root)
		{
			if(root->_Left)
			{
				leftDepth = root->_Left->_Depth;
			}
			else
			{
				leftDepth = 0;
			}
			if(root->_Right)
			{
				rightDepth = root->_Right->_Depth;
			}
			else
			{
				rightDepth = 0;
			}


			root->_Depth = 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
			root->_Balance = rightDepth - leftDepth;
		}
	}

	//Determines what to do by calling balance left or right based on the balance variable. 
	void Balance(std::shared_ptr<avlNode<std::pair<Key, Type>>>& root)
	{
		// AVL trees have the property that no branch is more than 1 longer than its sibling
		// If the balance integer is greater than 1 then the right side is wrong
		if (root->_Balance > 1)
		{

			BalanceRight(root);
		}
		//if the the balance integer is less than -1 then the left side is wrong.
		//We wish to hover between -1 and +1
		if (root->_Balance < -1)
		{

			BalanceLeft(root);
		}
	}

	//Swaps a right variable if rebalacing needs to occur. 
	void BalanceRight(std::shared_ptr<avlNode<std::pair<Key, Type>>>& root)
	{
		if (root->_Right)
		{
			if (root->_Right->_Balance > 0)
			{

				RotateLeft(root);
			}
			else if (root->_Right->_Balance < 0)
			{

				RotateRight(root->_Right);
				RotateLeft(root);
			}
		}
	}

	//Swaps a left variable if rebalancing needs to occur. 
	void BalanceLeft(std::shared_ptr<avlNode<std::pair<Key, Type>>>& root)
	{
		if (root->_Left)
		{
			if (root->_Left->_Balance < 0)
			{

				RotateRight(root);
			}
			else if (root->_Left->_Balance > 0)
			{

				RotateLeft(root->_Left);
				RotateRight(root);
			}
		}
	}

	//swaps the nodes along a particular branch
	void RotateLeft(std::shared_ptr<avlNode<std::pair<Key, Type>>>& root)
	{

		std::shared_ptr<avlNode<std::pair<Key, Type>>> pTemp = root;
		root = root->_Right;
		pTemp->_Right = root->_Left;
		root->_Left = pTemp;	
		ComputeBalance(root->_Left);
		ComputeBalance(root->_Right);
		ComputeBalance(root);
	}

	//swaps the nodes along a particular branch
	void RotateRight(std::shared_ptr<avlNode<std::pair<Key, Type>>>& root)
	{

		std::shared_ptr<avlNode<std::pair<Key, Type>>> pTemp = root;
		root = root->_Left;
		pTemp->_Left = root->_Right;
		root->_Right = pTemp;	
		ComputeBalance(root->_Left);
		ComputeBalance(root->_Right);
		ComputeBalance(root);
	}

	//inserts the node into the avltree. this function is called by all types of insert. 
	void nodeInsert(std::pair<Key,Type> pair, std::shared_ptr<avlNode<std::pair<Key,Type>>>& root)
	{
		if( _comp(2,1) )
		{
			//now he sorting begins...if the new key is greater than the rootnode's key
			if(pair.first > root->_ValuePair.first)
			{
				//If the left node of the rootNode exists
				if(root->_Left)
				{
					nodeInsert(pair, root->_Left);

				}
				//then create a left node.
				else
				{
					this->_Size = this->_Size +1;
					root->_Left = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>(pair));
					_InsertFlag = true;

				}
			}
			//if the key is less than the rootnode's key
			else if( root->_ValuePair.first > pair.first)
			{

				//If the right node of the rootNode exists
				if(root->_Right)
				{

					nodeInsert(pair, root->_Right);
				}
				else
				{
					this->_Size = this->_Size +1;
					root->_Right = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>(pair));
					_InsertFlag = true;
				}
			}
			else
			{
				_InsertFlag = false;


			}
		}
		else
		{
			//now he sorting begins...if the new key is greater than the rootnode's key
			if(pair.first < root->_ValuePair.first)
			{
				//If the left node of the rootNode exists
				if(root->_Left)
				{
					nodeInsert(pair, root->_Left);

				}
				//then create a left node.
				else
				{
					this->_Size = this->_Size +1;
					root->_Left = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>(pair));
					_InsertFlag = true;

				}
			}
			//if the key is less than the rootnode's key
			else if( root->_ValuePair.first < pair.first)
			{

				//If the right node of the rootNode exists
				if(root->_Right)
				{

					nodeInsert(pair, root->_Right);
				}
				else
				{
					this->_Size = this->_Size +1;
					root->_Right = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>(pair));
					_InsertFlag = true;
				}
			}
			else
			{
				_InsertFlag = false;
			}
		}
		ComputeBalance(root);
		Balance(root);
	}//end funtion 

public:
	//public types
	typedef Key										key_type;
	typedef Type									mapped_type;
	typedef std::pair<const Key, Type>				value_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef size_t									size_type;
	typedef Traits									key_compare;
	typedef std::ptrdiff_t					   		difference_type;
	typedef std::allocator<const Key>				allocator_type;
	class iterator;
	class const_iterator;


private:
	size_type _Size;
	bool _InsertFlag;
	key_compare _comp;
	allocator_type _alloc;
	//funky iterator magic.
	template <typename childType, typename Pointer, typename Reference>
	class IteratorParent;
	template <typename childType, typename Pointer, typename Reference>
	friend class IteratorParent;

	//private iterators for the constructors. 
	iterator _first;
	iterator _last;

public:
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	//nested class that uses the internal comparison object to
	//generate the appropriate comparison functional class. 
	class value_compare  : public std::binary_function<value_type, value_type, bool> {
		public:
			bool operator()(const value_type& x, const value_type& y) const
			{
				return (comp(x.first, y.first));
			}
		protected:
			friend class avltree;
			value_compare(key_compare pr)
				: comp(pr) {}
			key_compare comp;
    };

	avltree<Key, Type, Traits, Alloc>() 
	{
		_Size = 0;
		_NullEnd = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		_NullFront = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		_first.SetPointer(this);
	}

	~avltree<Key, Type, Traits, Alloc>() {}

	template<class InputIterator>
	avltree<Key, Type, Traits, Alloc>(InputIterator _First, InputIterator _Last) :  _first(_First), _last(_Last) 
	{
		_Size = 0;
		_NullEnd = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		_NullFront = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		while(_first != _last)
		{
			insert(std::pair<const Key, Type>(_first._CurrentNode->_ValuePair));  
			_Size++;
			_first++;
		}
	}
	
	template<class InputIterator>
	avltree<Key, Type, Traits, Alloc>(InputIterator _First, InputIterator _Last, const Traits& _Comp) :  _first(_First), _last(_Last), _comp(_Comp)
	{
		_Size = 0;
		_NullEnd = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		_NullFront = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		while(_first != _last)
		{
			insert(std::pair<const Key, Type>(_first._CurrentNode->_ValuePair));  
			_Size++;
			_first++;
		}
	}

	template<class InputIterator>
	avltree<Key, Type, Traits, Alloc>(InputIterator _First, InputIterator _Last, const Traits& _Comp, const Alloc& _Al) :  
		_first(_First), _last(_Last), _comp(_Comp), _alloc(_Al)
	{
		_Size = 0;
		_NullEnd = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		_NullFront = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		while(_first != _last)
		{
			insert(std::pair<const Key, Type>(_first._CurrentNode->_ValuePair));  
			_Size++;
			_first++;
		}
	}

	avltree<Key, Type, Traits, Alloc>( Traits const& _Comp, Alloc const& _Al ) : _comp(_Comp), _alloc(_Al) 
	{
		_Size = 0;
		_NullEnd = std::shared_ptr<avlNode<Key,Type>>(new avlNode<Key,Type>());
		_NullFront = std::shared_ptr<avlNode<Key,Type>>(new avlNode<Key,Type>());
		_first.SetPointer(this);
	}
	
	avltree<Key, Type, Traits, Alloc>(avltree<Key,Type>& rhs) 
	{ 
		_first.SetPointer(&rhs);
		_Size = rhs.size(); 
		_NullEnd = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		_NullFront = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		this->insert(rhs.begin(),rhs.end());
	}

	avltree<Key, Type, Traits, Alloc>(avltree&& rhs)
	{
		_first.SetPointer(&rhs);
		_Size = rhs.size();
		_NullEnd = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		_NullFront = std::shared_ptr<avlNode<std::pair<Key,Type>>>(new avlNode<std::pair<Key,Type>>());
		this->insert(rhs.begin(),rhs.end());
		rhs.clear();
	}

	explicit avltree<Key, Type, Traits, Alloc>(const Traits& _Comp) : _comp(_Comp)
	{
		_Size = 0;
		_NullEnd = std::shared_ptr<avlNode<Key,Type>>(new avlNode<Key,Type>());
		_NullFront = std::shared_ptr<avlNode<Key,Type>>(new avlNode<Key,Type>());
		_first.SetPointer(this);
	}

	//returns the type at the given key. 
	Type& at(Key const& key)
	{
		iterator returnIT;
		returnIT.FindNode(key, _RootNode);

		if(returnIT._CurrentNode != nullptr)
		{
			if(returnIT._CurrentNode->_ValuePair.first == key)
			{

				return returnIT._CurrentNode->_ValuePair.second;
			}
			else
			{
				//Throw an out of range exception
				throw std::out_of_range (""); 
			}
		}
		//Throw an out of range exception
		throw std::out_of_range (""); 


	}//end at 


	allocator_type get_allocator() const
	{
		return _alloc;
	}
	
	//returns the const type at the given key. 
	const Type& at(Key const& key) const
	{
		iterator returnIT;
		returnIT.FindNode(key, _RootNode);

		if(returnIT._CurrentNode != nullptr)
		{
			if(returnIT._CurrentNode->_ValuePair->first == key)
			{

				return returnIT._CurrentNode->_ValuePair->second;
			}
			else
			{
				//Throw an out of range exception
				throw std::out_of_range (""); 


			}
		}
		//Throw an out of range exception
		throw std::out_of_range (""); 


	}

	//compares two keys given 
	key_compare key_comp() const 
	{
		return _comp;
	}

	friend class value_compare;
	value_compare value_comp() const 
	{
		return value_compare(_comp);

	}

	//returns an iterator to the begining node 
	//in the avltree. 
	iterator begin() 
	{ 
		iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
			returnIT.SetPointer(this);
			returnIT.GetBeginNode(_RootNode);
			//Set the variables on the null end and return the null end. 
			//Which is not the end in the tree but a fake end for the iterator to work
			//this->_NullFront->_ValuePair = returnIT._CurrentNode->_ValuePair;
			this->_NullFront = returnIT._CurrentNode;
			this->_NullFront->_Role = "Begin";
			returnIT._CurrentNode = this->_NullFront;
		}
			return returnIT;
	}//end begin

	//returns an const_iterator to the begining node 
	//in the avltree.
	const_iterator cbegin() const
	{ 
		const_iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
		returnIT.SetPointer(this);
		returnIT.GetBeginNode(_RootNode);
		//Set the variables on the null end and return the null end. 
		//Which is not the end in the tree but a fake end for the iterator to work
		this->_NullFront->_ValuePair = returnIT._CurrentNode->_ValuePair;
		this->_NullFront->_Role = "Begin";
		returnIT._CurrentNode = this->_NullFront;
		}
		return returnIT;
	}

	//returns an iterator to the  one past 
	//the ending node in the avltree. 
	iterator end()
	{
		iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
		returnIT.SetPointer(this);
		returnIT.GetLastNode(_RootNode);
		//Set the variables on the null end and return the null end. 
		//Which is not the end in the tree but a fake end for the iterator to work
		this->_NullEnd->_ValuePair = returnIT._CurrentNode->_ValuePair;
		this->_NullEnd->_Role = "End";
		returnIT._CurrentNode = this->_NullEnd;
		}

		return returnIT;
	}

	//returns an const_iterator to the  one past 
	//the ending node in the avltree. 
	const_iterator cend() const
	{
		const_iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
		returnIT.SetPointer(this);
		returnIT.GetLastNode(_RootNode);
		//Set the variables on the null end and return the null end. 
		//Which is not the end in the tree but a fake end for the iterator to work
		this->_NullEnd->_ValuePair = returnIT._CurrentNode->_ValuePair;
		this->_NullEnd->_Role = "End";
		returnIT._CurrentNode = this->_NullEnd;
		}

		return returnIT;

	}

	//returns a reverse_iterator to the ending node in the tree. 
	reverse_iterator rbegin() { return reverse_iterator( lastValueEnd());}
		
	//returns a reverse_iterator to the begining node in the tree.
	reverse_iterator rend() { return reverse_iterator(  firstValueBegin()  );}

	//returns a const_reverse_iterator to the ending node in the tree.
	const_reverse_iterator crbegin() const  {return const_reverse_iterator( clastValueEnd() );}

	//returns a const_reverse_iterator to the begining node in the tree.
	const_reverse_iterator crend() const { return const_reverse_iterator( cbegin());}

	//clears the tree of all nodes. 
	void clear()
	{
		//Clearing an empty avltree brings on bad things.
		if(size() != 0)
		{
		//Hoping to convert the vector to an array if we have time.
		std::vector<iterator> tempVector;
		for(iterator test = begin(); test != end(); ++test)
		{
			tempVector.push_back(test);

		}
		for(size_t i = 0; i < tempVector.size(); ++i)
		{
			bool delOK = false;

			Remove(_RootNode, tempVector[i]._CurrentNode->_ValuePair.first, delOK);
		}	
		}

	}

	//returns the number of times to given key is in the avltree. 
	size_t count(Key const& key) 
	{
		iterator returnIT;
		//Do this so the current is the end if their is no match.
		returnIT.GetLastNode(_RootNode);
		returnIT.FindNode(key,_RootNode);
		if(returnIT._CurrentNode->_ValuePair.first == key)
		{
			return 1;
		}
		return 0;
	}

	//this function inserts a new element into the map it its key is unique.  
	std::pair<iterator,bool> emplace(Key const& key, Type const& type)
	{
		iterator returnIT;
		returnIT.FindNode(key, _RootNode);

		if(returnIT._CurrentNode != nullptr)
		{
			if(returnIT._CurrentNode->_ValuePair.first == key)
			{
				//The key already exists so return the iterator and the bool for fail.
				return std::make_pair(returnIT, false);
			}
			else
			{
				//The key does not exist, so go ahead and insert it.
				return insert(std::pair<const Key, Type>(key, type));
			}
		}
		return insert(std::pair<const Key, Type>(key, type));
	}

	//this function inserts a new element into the map if its key is unqiue, 
	//with a hint to the insertion position. 
	iterator emplace_hint (const_iterator position, Key const& key, Type const& type)
	{
		if(position._CurrentNode != nullptr)
		{
			if(position._CurrentNode->_ValuePair.first == key)
			{
				//The key already exists so return the iterator and the bool for fail.
				iterator returnIT;
				returnIT.FindNode(key, _RootNode);
				return returnIT;
			}
			else
			{
				//The key does not exist, so go ahead and insert it.

				insert(std::pair<const Key, Type>(key, type));
				iterator returnIT;
				returnIT.FindNode(key, _RootNode);
				return returnIT;
			}
		}
		insert(std::pair<Key, Type>(key, type));
		iterator returnIT;
		returnIT.FindNode(key, _RootNode);
		return returnIT;
	}

	//returns whether or not the avltree is empty. 
	bool empty() {return _Size == 0;}

	//returns the const_iterator bounds of a range that includes the elements in the 
	//avltree which have a Key equal to key. 
	std::pair<const_iterator,const_iterator> equal_range(Key const& key) const
	{
		const_iterator returnIT;
		//Do this so the current is the end if their is no match.
		returnIT.GetLastNode(_RootNode);
		returnIT.FindNode(key,_RootNode);
		
		return std::pair<const_iterator,const_iterator>(returnIT,returnIT);
	}
	
	//returns the iterator bounds of a range that includes the elements in the 
	//avltree which have a Key equal to key. 
	std::pair<iterator,iterator> equal_range(Key const& key)
	{
		iterator returnIT;
		//Do this so the current is the end if their is no match.
		returnIT.GetLastNode(_RootNode);
		returnIT.FindNode(key,_RootNode);
		
		return std::pair<iterator,iterator>(returnIT,returnIT);
	}

	//erases the pair from the given const_iterator position 
	void erase(const_iterator position)
	{

		bool delOK = false;
		Remove(_RootNode, position._CurrentNode->_ValuePair.first, delOK);

	}

	//erases the pair from the given iterator position 
	void erase(iterator position)
	{

		bool delOK = false;
		Remove(_RootNode, position._CurrentNode->_ValuePair.first, delOK);

	}
	
	//removes from the avltree a single element
	size_t erase(Key const& key)
	{
		bool delOK = false;
		Remove(_RootNode, key, delOK);
		return _Size;
	}

	//removes from the avltree a range of elements. 
	void erase (const iterator first, const iterator last) 
	{
		//I am totally unhappy with this solution but it has to be this way. I have a deadline.
		//When you delete an element it screws up iterating in a loop since the pervious element is needed.
		//So put it all in a vector first. Then delete it since I have the pointers now.

		std::vector<iterator> tempVector;
		for(iterator test = first; test <= last && test != end(); ++test)
		{
			tempVector.push_back(test);

		}
		for(size_t i = 0; i < tempVector.size(); ++i)
		{
			bool delOK = false;
			Remove(_RootNode, tempVector[i]._CurrentNode->_ValuePair.first, delOK);
		}

		
	}

	//searches the avltree for the given Key, 
	//and returns an iterator to it if it is found 
	//otherwise it returns the end. 
	iterator find(Key const& key) 
	{
		iterator returnIT;
		if(size() != 0)
		{
		returnIT.SetPointer(this);
		//Do this so the current is the end if their is no match.
		returnIT.GetLastNode(_RootNode);
		returnIT++;
		returnIT.FindNode(key, _RootNode);
		}
		return returnIT;
	}

	//searches the avltree for the given Key, 
	//and returns a const_iterator to it if it is found 
	//otherwise it returns the end. 
	const_iterator find(Key const& key) const 
	{
		const_iterator returnIT;
		if(size() != 0)
		{
		//Do this so the current is the end if their is no match.
		returnIT.GetLastNode(_RootNode);
		returnIT++;
		returnIT.FindNode(key, _RootNode);
		}
		return returnIT;
	}
	
	//extends the avltree by creating new elements. 
	//takes in the position to insert, and the value pair to insert 
	//(similar to emplace hint) 
	template<class value_type>
	iterator insert ( iterator position, value_type& val)
	{
		if(position._CurrentNode != nullptr)
		{
			if(position._CurrentNode->_Role == "Begin")
			{
				position.SetPointer(this);
				position.GetBeginNode(_RootNode);

			}

			if(position._CurrentNode->_Role == "End")
			{
				position.SetPointer(this);
				position.GetLastNode(_RootNode);
			}

			if(position._CurrentNode->_ValuePair.first == val.first)
			{
				position._CurrentNode->_ValuePair.second = val.second;
				return position;
			}
			else
			{
				insert(val);
				return find(val.first);
			}
		}
		else
		{
			insert(val);
			return find(val.first);
		}
	}
	
	//extends the avltree by creating new elements, takes 
	//a const pair to the Key and Type to insert. 
	//if there is already an equivalent key it is not inserted 
	//and returns an iterator to this existing element. 
	template<class value_type>
	std::pair<iterator,bool> insert (const value_type& val) 
	{
		_InsertFlag = false;
		std::pair<Key, Type> foo;
		foo = std::make_pair (val.first,val.second);
		if(_RootNode == nullptr)
		{
			_RootNode = std::shared_ptr<avlNode<std::pair<Key, Type>>>(new avlNode<std::pair<Key, Type>>(foo));
			this->_Size = this->_Size +1;
			_InsertFlag = true;
		}
		else
		{
			nodeInsert(foo,_RootNode);

		}
		iterator returnIterator;
		returnIterator.FindNode(val.first, _RootNode);
		std::pair<iterator,bool> returnPair (returnIterator,_InsertFlag);
		return returnPair;
	}
	
	//extends the avltree by creating new elements, takes 
	//a const pair to the Key and Type to insert. 
	//if there is already an equivalent key it is not inserted 
	//and returns an iterator to this existing element. 
	template<class value_type>
	std::pair<iterator,bool> insert (value_type&& val) 
	{
		_InsertFlag = false;
		std::pair<Key, Type> foo;
		foo = std::make_pair (val.first,val.second);
		if(_RootNode == nullptr)
		{
			_RootNode = std::shared_ptr<avlNode<std::pair<Key, Type>>>(new avlNode<std::pair<Key, Type>>(foo));
			this->_Size = this->_Size +1;
			_InsertFlag = true;
		}
		else
		{
			nodeInsert(foo,_RootNode);
		}
		iterator returnIterator;
		returnIterator.FindNode(val.first, _RootNode);
		std::pair<iterator,bool> returnPair (returnIterator,_InsertFlag);
		return returnPair;
	}

//extends the avltree by creating new elements, takes 
//a const pair to the Key and Type to insert. 
//if there is already an equivalent key it is not inserted 
//and returns an iterator to this existing element. 
template<class value_type>
iterator insert ( const_iterator position, const Type& type)
	{
		if(position._CurrentNode->_Role == "Begin")
		{
			iterator returnIT;
			returnIT.SetPointer(this);
			returnIT.GetBeginNode(_RootNode);
			returnIT._CurrentNode->_ValuePair.second = type;
			return returnIT;
		}
		else if(position._CurrentNode->_Role == "End")
		{
			iterator returnIT;
			returnIT.SetPointer(this);
			returnIT.GetLastNode(_RootNode);
			returnIT._CurrentNode->_ValuePair.second = type;
			return returnIT;
		}
		else
		{
			position._CurrentNode->_ValuePair.second = type;
			return position;
		}



	}

//extends the avltree by creating new elements, takes 
//a const pair to the Key and Type to insert. 
//if there is already an equivalent key it is not inserted 
//and returns an iterator to this existing element. 
void insert (iterator first, iterator last)
	{
		while(first != last)
		{			
			insert(first._CurrentNode->_ValuePair);
			++first;
		}

	}


//returns a iterator pointing to the first element in the container 
//whose key is not considered to go after the given key. 
iterator upper_bound (Key const& key) 
	{
		iterator returnIT;
		returnIT.SetPointer(this);
		returnIT.FindNode(key, _RootNode);
		++returnIT;
		return returnIT;
	}
	
//returns a iterator pointing to the first element in the container 
//whose key is not considered to go before or after. 
iterator lower_bound (Key const& key) 
	{
		iterator returnIT;
		returnIT.SetPointer(this);
		returnIT.FindNode(key, _RootNode);
		return returnIT;
	}

//returns a const iterator pointing to the first element in the container 
//whose key is not considered to go after the given key. 
const_iterator upper_bound (const Key& k) const
	{
		const_iterator returnIT;
		returnIT.SetPointer(this);
		returnIT = find(key);
		++returnIT;
		return returnIT;
	}

//returns a const iterator pointing to the first element in the container 
//whose key is not considered to go before or after. 
const_iterator lower_bound (const Key& k) const
	{
		const_iterator returnIT;
		returnIT.SetPointer(this);
		returnIT = find(key);
		return returnIT;
	}

//returns the maximum number of elements that 
//the container can hold.  
size_type max_size () const
	{
		return _alloc.max_size();
	}

//Assigns new contents to the container, replacing its current content.
avltree& operator = (const avltree<Key, Type> & rhs)
	{
		clear();
		_Size = 0;
		for(const_iterator it = rhs.cbegin(); it != rhs.cend(); it++)
		{
			this->insert(std::pair<Key, Type>(it._CurrentNode->_ValuePair));
		}

		return *this;	
	}

//move the  contents to the container, deleting its current content, and 
//the contents of the passed container. 
avltree& operator = ( avltree<Key, Type>&& rhs)
	{
		clear();
		_Size = 0;
		for(iterator it = rhs.begin(); it != rhs.end(); it++)
		{
			rhs.insert(std::pair<Key, Type>(it._CurrentNode->_ValuePair));
		}
		rhs.clear();
		return *this;	
	}

//access element operator returns the type of the given key. 
Type& operator[] (const Key& key) 
	{
		Type type;
		std::pair<Key,Type>testpair(key,type) ;
		return insert(testpair).first._CurrentNode->_ValuePair.second;
	}
	
	//this function returns the size of the container. 
size_t size() const 
	{
		return this->_Size;
	}
	
//Exchanges the content of the container by the content of x, 
//which is another map of the same type
void swap(avltree<Key,Type,Traits,Alloc>& rhs)
	{
		//create a temporary map.
		avltree<Key,Type,Traits,Alloc> tempTree;
		tempTree = rhs;

		rhs.clear();
		for(avltree<Key,Type>::iterator it = begin(); it != end(); ++it)
		{
			rhs.insert(it._CurrentNode->_ValuePair);
		}

		clear();
		for(avltree<Key,Type>::iterator it = tempTree.begin(); it != tempTree.end(); ++it)
		{
			insert(it._CurrentNode->_ValuePair);
		}
	}

//this operator overload compares this to the passed in 
//rhs avltree and decides if they are equal
bool operator == (avltree<Key,Type,Traits>& rhs )
	{

		iterator ITrhs = rhs.begin();



		if(_Size != rhs._Size)
		{
			return false;
		}

		for(iterator ITlhs = begin(); ITlhs != end(); ++ITlhs, ++ITrhs) 
		{
			if(ITlhs._CurrentNode->_ValuePair.second != ITrhs._CurrentNode->_ValuePair.second) 
			{
				return false;
			}


		}

		return true;
	}

//this operator overload compares this to the passed in 
//rhs avltree and decides if they are not euqal
bool operator != (avltree<Key,Type,Traits,Alloc>& rhs )
	{
		iterator ITrhs = rhs.begin();



		if(_Size != rhs._Size)
		{
			return true;
		}

		for(iterator ITlhs = begin(); ITlhs != end(); ++ITlhs, ++ITrhs) 
		{
			if(ITlhs._CurrentNode->_ValuePair.second != ITrhs._CurrentNode->_ValuePair.second || ITlhs._CurrentNode->_Role != ITrhs._CurrentNode->_Role) 
			{
				return true;
			}

		}

		return false;


	}

//this operator overload compares this to the passed in 
//rhs avltree and decides which is less, or equal 
bool operator <=  ( avltree<Key,Type,Traits,Alloc>& rhs  )
	{
		if(_Size == 0 && rhs._Size == 0)
		{
			return true;
		}
		
		
		if(_Size < rhs._Size && _Size == 0)
		{
			return true;
		}
		if(rhs._Size < _Size && rhs._Size == 0)
		{
			return true;
		}
		

		

		if(_Size >= rhs._Size)
		{
			iterator ITrhs = rhs.begin();
			size_t counter = 0;

			for(iterator ITlhs = begin(); ITlhs != end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > rhs._Size)
				{
					break;
				}				
				if(ITlhs._CurrentNode->_ValuePair.second > ITrhs._CurrentNode->_ValuePair.second) 
				{
					return false;
				}
				++counter;
			}
		}
		else
		{
			iterator ITlhs = begin();
			size_t counter = 0;
			
			for(iterator ITrhs = rhs.begin(); ITrhs != rhs.end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > _Size)
				{
					break;
				}
				if(ITlhs._CurrentNode->_ValuePair.second > ITrhs._CurrentNode->_ValuePair.second)  
				{
					return false;
				}
				++counter;
			}

			
		}
	

	return true;

	}

//this operator overload compares this to the passed in 
//rhs avltree and decides which is greater or equal
bool operator >=  ( avltree<Key,Type,Traits,Alloc>& rhs  )
	{
		if(_Size == 0 && rhs._Size == 0)
		{
			return true;
		}
		
		if(_Size < rhs._Size && _Size == 0)
		{
			return false;
		}
		if(rhs._Size < _Size && rhs._Size == 0)
		{
			return false;
		}

		

		if(_Size >= rhs._Size)
		{
			iterator ITrhs = rhs.begin();
			size_t counter = 0;
			
			for(iterator ITlhs = begin(); ITlhs != end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > rhs._Size)
				{
				break;
				}
				if(ITlhs._CurrentNode->_ValuePair.second < ITrhs._CurrentNode->_ValuePair.second)

				{
					return false;
				}
				++counter;

			}
		}
		else
		{
			iterator ITlhs = begin();
			size_t counter = 0;

			for(iterator ITrhs = rhs.begin(); ITrhs != rhs.end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > _Size)
				{
					break;
				}
				if(ITlhs._CurrentNode->_ValuePair.second < ITrhs._CurrentNode->_ValuePair.second)
				{
					return false;
				}
				++counter;
			}

			
		}
		

	return true;

	}

//this operator overload compares this to the passed in 
//rhs avltree and decides which is less. 
bool operator <  ( avltree<Key,Type,Traits,Alloc>& rhs  )
	{
		if(_Size == 0 && rhs._Size == 0)
		{
			return false;
		}
		if(_Size < rhs._Size && _Size == 0)
		{
			return true;
		}
		if(rhs._Size < _Size && rhs._Size == 0)
		{
			return true;
		}
		

		

		

		if(_Size >= rhs._Size)
		{
			iterator ITrhs = rhs.begin();
			size_t counter = 0;

			for(iterator ITlhs = begin(); ITlhs != end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > rhs._Size)
				{
					break;
				}				
				if(ITlhs._CurrentNode->_ValuePair.second > ITrhs._CurrentNode->_ValuePair.second) 
				{
					return false;
				}
				++counter;
			}
		}
		else
		{
			iterator ITlhs = begin();
			size_t counter = 0;
			
			for(iterator ITrhs = rhs.begin(); ITrhs != rhs.end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > _Size)
				{
					break;
				}
				if(ITlhs._CurrentNode->_ValuePair.second > ITrhs._CurrentNode->_ValuePair.second)  
				{
					return false;
				}
				++counter;
			}

			
		}
		if( rhs == *this)
		{
			return false;
		}

	return true;

	}


//this operator overload compares this to the passed in 
//rhs avltree and decides which is greater. 
bool operator >  ( avltree<Key,Type,Traits,Alloc>& rhs  )
	{
		if(_Size == 0 && rhs._Size == 0)
		{
			return false;
		}
		
		if(_Size < rhs._Size && _Size == 0)
		{
			return false;
		}
		if(rhs._Size < _Size && rhs._Size == 0)
		{
			return false;
		}		

		if(_Size >= rhs._Size)
		{
			iterator ITrhs = rhs.begin();
			size_t counter = 0;
			
			for(iterator ITlhs = begin(); ITlhs != end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > rhs._Size)
				{
				break;
				}
				if(ITlhs._CurrentNode->_ValuePair.second < ITrhs._CurrentNode->_ValuePair.second)

				{
					return false;
				}
				++counter;

			}
		}
		else
		{
			iterator ITlhs = begin();
			size_t counter = 0;

			for(iterator ITrhs = rhs.begin(); ITrhs != rhs.end(); ++ITlhs, ++ITrhs) 
			{
				if(counter > _Size)
				{
					break;
				}
				if(ITlhs._CurrentNode->_ValuePair.second < ITrhs._CurrentNode->_ValuePair.second)
				{
					return false;
				}
				++counter;
			}

			
		}
		if( rhs == *this)
		{
			return false;
		}

	return true;

	}



private:

	//Need to have a function that returns an iterator 
	//to the REAL end, not the fake end. 
	iterator lastValueEnd()
	{
		iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
			returnIT.SetPointer(this);
			returnIT.GetBeginNode(_RootNode);
		}
			return returnIT;
	}
	
	//Need to have a function that returns an iterator 
	//to the REAL end, not the fake end, for the const
	const_iterator clastValueEnd()
	{
		const_iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
			returnIT.SetPointer(this);
			returnIT.GetBeginNode(_RootNode);
		}
			return returnIT;
	}
	
	//Need to have a function that returns an iterator 
	//to the REAL begin, not the fake begin.
	iterator firstValueBegin()
	{
		iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
			returnIT.SetPointer(this);
			returnIT.GetBeginNode(_RootNode);
		}
			return returnIT;
	}
	
	//Need to have a function that returns an iterator 
	//to the REAL begin, not the fake begin, for the const.
	const_iterator cfirstValueBegin()
	{
		const_iterator returnIT;
		//Bad things happen if you try this code to an empty avltree.
		if(size() != 0)
		{
			returnIT.SetPointer(this);
			returnIT.GetBeginNode(_RootNode);
		}
			return returnIT;
	}

};

//exchanges the contents of the container with 
//another container. 
template <class Key, class Type, class Traits, class Alloc>
  void swap (avltree<Key,Type, Traits, Alloc>& lhs, avltree<Key,Type,Traits, Alloc>& rhs)
  {
	  lhs.swap(rhs);
  }


//this parent iterator class is use to provide a common implementation 
  //for iterator and const_iterator. 
template <typename Key, typename Type, typename Traits, typename Alloc>
template <typename childType, typename Pointer, typename Reference>
class avltree<Key, Type, Traits, Alloc>::IteratorParent
{
public:

	//Increment (pre) operator constructs detrived child type instances of 
	//the proper type and advances them. 
	childType& operator ++()
	{
		//you cannot increment an empty iterator.
		assert(_avlTreePointer != nullptr);
		assert(_avlTreePointer->_Size != 0);

		if(_CurrentNode->_Role == "Reg")
		{
			iterator returnIT;
			returnIT.GetLastNode(this->_avlTreePointer->_RootNode);
			

			//if we are at the end of the avltree node the set the currentnode to the fake end.
			if(_CurrentNode->_ValuePair.first == returnIT._CurrentNode->_ValuePair.first)
			{
				this->_avlTreePointer->_NullEnd->_Role = "End";
				this->_avlTreePointer->_NullEnd->_ValuePair = _CurrentNode->_ValuePair;
				_CurrentNode = this->_avlTreePointer->_NullEnd;

			}
			else
			{
				bool flag = false;		
				ForwardNextNode(_CurrentNode->_ValuePair.first,flag, _avlTreePointer->_RootNode);
			}
		}
		if(_CurrentNode->_Role == "Begin")
		{
			bool flag = false;	
			GetBeginNode(_avlTreePointer->_RootNode);
			_CurrentNode->_Role = "Reg";
			ForwardNextNode(_CurrentNode->_ValuePair.first,flag, _avlTreePointer->_RootNode);


		}

		return static_cast<childType&>(*this);
	}

	//Increment (post) operator  constructs detrived child type instances of 
	//the proper type and advances them. 
	const childType operator++ (int) 
	{
		assert(_avlTreePointer != nullptr);
			assert(_avlTreePointer->_Size != 0);
		
		childType result = static_cast<childType&>(*this);
		++*this;
		return result;
	}

	//decrement (pre) operator  constructs detrived child type instances of 
	//the proper type and decrements them. 
	childType& operator --()
	{
		//you cannot increment an empty iterator.
		assert(_avlTreePointer != nullptr);
		assert(_avlTreePointer->_Size != 0);

		if(_CurrentNode->_Role == "Reg")
		{
			iterator returnIT;
			returnIT.GetBeginNode(this->_avlTreePointer->_RootNode);
			
			if(_CurrentNode->_ValuePair.first == returnIT._CurrentNode->_ValuePair.first)
			{
				this->_avlTreePointer->_NullFront->_Role = "End";
				this->_avlTreePointer->_NullFront->_ValuePair = _CurrentNode->_ValuePair;
				_CurrentNode = this->_avlTreePointer->_NullFront;
			}
			else
			{
				bool flag = false;		
				ReverseNextNode(_CurrentNode->_ValuePair.first,flag, _avlTreePointer->_RootNode);
			}
		}
		if(_CurrentNode->_Role == "End")
		{
			bool flag = false;
			GetLastNode(_avlTreePointer->_RootNode);	
			_CurrentNode->_Role = "Reg";
			ReverseNextNode(_CurrentNode->_ValuePair.first,flag, _avlTreePointer->_RootNode);

		}
		return static_cast<childType&>(*this);
	}

	//Increment (post) operator  constructs detrived child type instances of 
	//the proper type and decrements them. 
	const childType operator-- (int) 
	{
		assert(_avlTreePointer != nullptr);
		assert(_avlTreePointer->_Size != 0);
		childType result = static_cast<childType&>(*this);
		--*this;
		return result;
	}

// Equality and disequality operators are parameterized to we'll allow anyone
   //whose type is IteratorBase to compare with us.  This means that we can
   // compare both iterator and const_iterator against one another.
	template<typename childType, typename Pointer2, typename Reference2>
	bool operator == (const IteratorParent<childType, Pointer2, Reference2>& rhs) 
	{
		//if both empty return true.
		if(_CurrentNode == nullptr && rhs._CurrentNode == nullptr)
		{
			return true;
		}
		//if one or the other is empty return false.
		if(_CurrentNode == nullptr || rhs._CurrentNode == nullptr)
		{
			return true;
		}

		
		if (_CurrentNode->_Role != rhs._CurrentNode->_Role)
		{
		
			return false;
		}

		return _CurrentNode->_ValuePair.first == rhs._CurrentNode->_ValuePair.first;
	}
	
	template<typename childType, typename Pointer2, typename Reference2>
	bool operator != ( const IteratorParent<childType, Pointer2, Reference2>& rhs) 
	{		
		//empty iterators can't be compared so return false in this case.
		if(_CurrentNode == nullptr || rhs._CurrentNode == nullptr)
		{
			return false;
		}

		if (_CurrentNode->_Role != rhs._CurrentNode->_Role)
		{
			return true;
		}
		return _CurrentNode->_ValuePair.first != rhs._CurrentNode->_ValuePair.first;
	}

	 //defererences operator, and hands back a reference. 
	Reference operator* () const 
	{	
		assert(_avlTreePointer != nullptr);	
		std::pair<const Key, Type> toReturn = std::make_pair(_CurrentNode->_ValuePair.first, _CurrentNode->_ValuePair.second);
		return &toReturn;//_CurrentNode->_ValuePair;
	}

	//Arrow operator returns a pointer
	Pointer operator->() const
	{
		assert(_avlTreePointer != nullptr);
		std::unique_ptr<std::pair<const Key, Type>> test;
		test = std::unique_ptr<std::pair<const Key, Type>>( new std::pair<const Key, Type>(_CurrentNode->_ValuePair.first, _CurrentNode->_ValuePair.second));
		return test;
	}

	template<typename childType2, typename Pointer2, typename Reference2>
	bool operator < (const IteratorParent<childType2, Pointer2, Reference2>& rhs)
	{
		//You cannot compare different iterators.
		assert(this->_avlTreePointer == rhs._avlTreePointer);

		//empty iterators can't be compared so return false in this case.
		if(_avlTreePointer == nullptr)
		{
			return false;
		}
		if(_avlTreePointer->_Size == 0)
		{
			return false;
		}

		return _CurrentNode->_ValuePair->first < rhs._CurrentNode->_ValuePair->first;
	}

	template<typename childType2, typename Pointer2, typename Reference2>
	bool operator > (const IteratorParent<childType, Pointer2, Reference2>& rhs)
	{
		//You cannot compare different iterators.
		assert(this->_avlTreePointer == rhs._avlTreePointer);

		//empty iterators can't be compared so return false in this case.
		if(_avlTreePointer == nullptr)
		{
			return false;
		}
		if(_avlTreePointer->_Size == 0)
		{
			return false;
		}
		return _CurrentNode->_ValuePair->first > rhs._CurrentNode->_ValuePair->first;
	}

	template<typename childType2, typename Pointer2, typename Reference2>
	bool operator >= (const IteratorParent<childType2, Pointer2, Reference2>& rhs)
	{
		//You cannot compare different iterators.
		assert(this->_avlTreePointer == rhs._avlTreePointer);

		//empty iterators can't be compared so return false in this case.
		if(_avlTreePointer == nullptr)
		{
			return false;
		}
		if(_avlTreePointer->_Size == 0)
		{
			return false;
		}
		return _CurrentNode->_ValuePair.first >= rhs._CurrentNode->_ValuePair.first;
	}

	template<typename childType2, typename Pointer2, typename Reference2>
	bool operator <= (const IteratorParent<childType2, Pointer2, Reference2>& rhs)
	{
		//You cannot compare different iterators.
		assert(this->_avlTreePointer == rhs._avlTreePointer);

		//empty iterators can't be compared so return false in this case.
		if(_avlTreePointer == nullptr)
		{
			return false;
		}
		if(_avlTreePointer->_Size == 0)
		{
			return false;
		}


		return _CurrentNode->_ValuePair.first <= rhs._CurrentNode->_ValuePair.first;
	}

protected:
	//all iteratorParent classes must be besties:
	//in order for equaliy comparions to work correctly, 
	//all iterator parents must be friends.
	template<typename childType, typename Pointer2, typename Reference2>
	friend class IteratorParent;

	//constructor for the children....
	//basically wont work unless the children pass us the correct info. 
	IteratorParent	(avltree<Key, Type, Traits, Alloc>* owner = nullptr, std::shared_ptr<avlNode<std::pair<Key, Type>>> curr = nullptr) :
		_avlTreePointer(owner), _CurrentNode(curr)
	{
	
	}

	//this function sets the pointer for the avltree we are looking at. 
	void SetPointer(const avltree<Key,Type,Traits, Alloc>* const ptr)
	{
		_avlTreePointer = ptr;
	}

	//this function recursivly increments to get the next correct node 
	//in the tree. 
	void ForwardNextNode(Key const& key, bool& flag, std::shared_ptr<avlNode<std::pair<Key, Type>>> root)
	{
		if(root != nullptr)
		{

			ForwardNextNode(key, flag, root->_Left);

			if(key == root->_ValuePair.first)
			{
				flag = true;
			}
			if(key < root->_ValuePair.first && flag == true)
			{
				_CurrentNode = root;
				flag = false;
			}

			if(root->_Right != nullptr)
			{
				ForwardNextNode(key, flag, root->_Right);
			}

		}


	}

	//this function recursively increments to get the previous correct node 
	void ReverseNextNode(Key const& key, bool& flag, std::shared_ptr<avlNode<std::pair<Key, Type>>> root)
	{
		if(root != nullptr)
		{

			ReverseNextNode(key, flag, root->_Right);

			if(key == root->_ValuePair.first)
			{
				flag = true;
			}
			if(key > root->_ValuePair.first && flag == true)
			{
				_CurrentNode = root;
				flag = false;
			}

			if(root->_Left != nullptr)
			{
				ReverseNextNode(key, flag, root->_Left);
			}

		}


	}

	//this function gets the begining node in the tree. 
	void GetBeginNode( std::shared_ptr<avlNode<std::pair<Key, Type>>> root) 
	{
		if(root != nullptr)
		{
			GetBeginNode(root->_Left);
			if(_CurrentNode == nullptr)
			{
				_CurrentNode = root;

			}

			if(root->_Right != nullptr)
			{
				GetBeginNode(root->_Right);
			}
		}


	}

	//this function gets the last node of the tree (not the fake end) 
	void GetLastNode(std::shared_ptr<avlNode<std::pair<Key, Type>>> root)
	{
		if(root != nullptr)
		{
			{
				GetLastNode(root->_Right);
			}

			if(_CurrentNode == nullptr)
			{
				_CurrentNode = root;


			}

			if(root->_Left != nullptr)
			{
				GetLastNode(root->_Left);
			}

		}


	}

	//this function takes the root node of the current avltree, and 
	//a pointer to the avlnode to search for. 
	void FindNode(Key const& key, std::shared_ptr<avlNode<std::pair<Key, Type>>>& root)
	{
		if(root != nullptr)
		{

			FindNode(key, root->_Left);


			if(key == root->_ValuePair.first)
			{
				_CurrentNode = root;
				_CurrentNode->_Role = "Reg";

			}
			else
			{

			}
			if(root->_Right != nullptr)
			{
				FindNode(key, root->_Right);
			}

		}


	}
	
	//utility pointers to keep track of our avltree and the current node. 
	std::shared_ptr<avlNode<std::pair<Key, Type>>> _CurrentNode;

	//this is the avltree we belong to, the pointer is const 
	//even through we may modify avltree elements to avoid having 
	//tp duplicate logic for const vs non const. 
	const avltree<Key,Type,Traits,Alloc>* _avlTreePointer;
};




//iterator and const iterator implementations 
//dereive off the iteratorParent class, we pass in params that make it 
//all work happily. 
//we also inheirt from std::iterator to import the necessary typedefs to be 
//a real iterator. 
template<class Key, class Type, class Traits,class Alloc>
class avltree<Key, Type, Traits, Alloc>:: iterator :	public std::iterator< std::bidirectional_iterator_tag,std::pair<const Key, Type>>,
	public IteratorParent<iterator, std::unique_ptr<std::pair<const Key, Type>>, std::pair<const Key, Type>&>
{

public: 
	//nothing to do here. 
	iterator() {}

private:
	//the constructor for creating an iterator 
	//of a raw node which just forwards it to 
	//the parent type. 
	iterator(const avltree<Key, Type, Traits, Alloc>* owner, std::shared_ptr<avlNode<std::pair<const Key, Type>>> node ) :
		IteratorParent<iterator, std::pair<const Key, Type>*, std::pair<const Key, Type>&>     (owner, node) {}

	friend class avltree;
};




template<typename Key, typename Type, typename Traits, typename Alloc>
class avltree<Key, Type, Traits, Alloc>::const_iterator :	public std::iterator< std::bidirectional_iterator_tag, const std::pair<const Key, Type> >,
	public IteratorParent<const_iterator,// Our type
	const std::unique_ptr<std::pair<const Key, Type>>,   // Reference type
	const std::pair<const Key, Type>&>   //pointer type 
{
public:
	//dfault, nothing to do here. 
	const_iterator(){}

	//iterator conversion constructor.
	const_iterator(iterator itr) :
		IteratorParent<const_iterator,
		const std::unique_ptr<std::pair<const Key, Type>>,
		const std::pair<const Key, Type>&>(itr._avlTreePointer, itr._CurrentNode) {}
private:
	//make them friends. 
	friend class avltree;

	const_iterator(avltree<Key, Type, Traits, Alloc>* const owner, std::shared_ptr<avlNode<std::pair<const Key, Type>>> node ) :	
	IteratorParent<const_iterator, 	const std::pair<const Key, Type>*, 	const std::pair<const Key, Type>&> (owner, node){}
};


#endif