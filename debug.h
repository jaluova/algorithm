#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

#define DEBUG(x) debug(x, #x)

namespace detail {}  // namespace detail

// 主调试函数
template <typename T>
void debug(const T& value, const std::string& varName) {
    std::cout << "[" << varName << "] ";
    detail::debug_impl(value, std::cout);
    std::cout << std::endl;
}

#endif  // _DEBUG_H_