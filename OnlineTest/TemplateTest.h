#pragma once
#ifndef __TEMPLATETEST_H__
#define __TEMPLATETEST_H__

template<typename T>
class Test
{
public:
	Test() = default;

	T Add(T i);
};

#endif // !__TEMPLATETEST_H__
