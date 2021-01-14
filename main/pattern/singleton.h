#pragma once

template<typename T>
class singleton {
public:
	static T& instance();
	/*{
		static T* _instance = new T();
		return *_instance;
	}*/

protected:
	singleton() {}
};

#include "singleton.hpp";