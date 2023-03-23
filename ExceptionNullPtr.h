#pragma once
#include <exception>
#include <string>

class ExceptionNullPtr :public std::exception
{
private:
    std::string whatStr;
public:
    ExceptionNullPtr(std::string&& whatStr) noexcept;
    ExceptionNullPtr(const std::string& whatStr) noexcept;
    ~ExceptionNullPtr() noexcept = default;

    const char* what() const noexcept override;
};

