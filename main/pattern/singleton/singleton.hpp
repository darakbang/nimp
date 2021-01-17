#pragma once

template <typename T>
T& singleton<T>::instance() {
	static T* _instance = new T();
	return *_instance;
}