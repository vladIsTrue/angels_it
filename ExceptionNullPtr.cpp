#include "ExceptionNullPtr.h"

ExceptionNullPtr::ExceptionNullPtr(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) {}

ExceptionNullPtr::ExceptionNullPtr(const std::string& whatStr) noexcept : whatStr(whatStr) {}

const char* ExceptionNullPtr::what() const noexcept
{
	return whatStr.c_str();
}
