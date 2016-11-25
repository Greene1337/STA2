#include <iostream>
#include "integer_list_stack.hpp"
#include "integer_list.hpp"
#include <cassert>

int main()
{
	
	IntegerListStack * pStack = IntegerListStackCreate();

	

	IntegerList l1, l2;
	IntegerListInit(l1);
	IntegerListInit(l2);

	IntegerListPushBack(l1, 1);
	IntegerListPushBack(l1, 2);
	IntegerListPushBack(l1, 3);

	IntegerListPushBack(l2, 0);
	IntegerListPushBack(l2, 2);
	IntegerListPushBack(l2, 4);
	IntegerListPushBack(l2, 6);

		IntegerListStackPush(*pStack, l1);
	IntegerListStackPush(*pStack, l2);

		IntegerListClear(l1);
	IntegerListClear(l2);

		const IntegerList & lTop = IntegerListStackTop(*pStack);
	assert(lTop.m_pLast->m_value == 6);

	
	IntegerListStackPop(*pStack);

	
	const IntegerList & lTop2 = IntegerListStackTop(*pStack);
	assert(lTop2.m_pLast->m_value == 3);

	
	IntegerListStackDestroy(pStack);

	return 0;
}
