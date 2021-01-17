#pragma once

// call_once
#include <cstdio>
#include <mutex>
#include <memory>

template<typename T>
class singleton_call_once {
public:
	static T& instance() {
		std::call_once(singleton_call_once::once_flag_, []() {
			instance_.reset(new T);
			});

		return *(instance_.get());
	}
protected:
	static std::unique_ptr<T> instance_;
	static std::once_flag once_flag_;

	singleton_call_once() = default;
	singleton_call_once(const singleton_call_once&) = delete;
	T& operator=(const singleton_call_once&) = delete;
};

template<typename T>
std::unique_ptr<T> singleton_call_once<T>::instance_;

template<typename T>
std::once_flag singleton_call_once<T>::once_flag_;