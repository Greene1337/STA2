#include <iostream>
#include "integer_list_stack.hpp"
#include <cassert>

struct IntegerListStack
{
	IntegerList * m_pData;
	IntegerList * m_pTop;
	int m_Size;
};


IntegerListStack * IntegerListStackCreate(int _fixedSize)
{
	IntegerListStack * pStack = new IntegerListStack;

	pStack->m_pData = new IntegerList[_fixedSize];
	for (int i = 0; i < _fixedSize; i++)
		IntegerListInit(pStack->m_pData[i]);
	pStack->m_pTop = pStack->m_pData;
	pStack->m_Size = _fixedSize;

	return pStack;
}


void IntegerListStackDestroy(IntegerListStack * _pStack)
{

	for (int i = 0; i < _pStack->m_Size; i++)
		IntegerListClear(_pStack->m_pData[i]);
	delete _pStack;
}


void IntegerListStackClear(IntegerListStack & _stack)
{
	_stack.m_pTop = _stack.m_pData;
}

void IntegerListCopy(IntegerList & _dest, IntegerList & _src)
{
	IntegerList::Node * pCurrent = _src.m_pFirst;
	while (pCurrent)
	{
		std::cout << pCurrent->m_value << std::endl;
		IntegerListPushBack(_dest, pCurrent->m_value);
		pCurrent = pCurrent->m_pNext;
	}
}

void IntegerListStackPush(IntegerListStack & _stack, IntegerList _value)
{
	IntegerListCopy(*_stack.m_pTop,_value);
	++_stack.m_pTop;
}


void IntegerListStackPop(IntegerListStack & _stack)
{
	--_stack.m_pTop;
}


IntegerList IntegerListStackTop(const IntegerListStack & _stack)
{
	return *(_stack.m_pTop - 1);
}


bool IntegerListStackIsEmpty(const IntegerListStack & _stack)
{
	return _stack.m_pData == _stack.m_pTop;
}
