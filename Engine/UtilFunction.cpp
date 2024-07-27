#include "pch.h"
#include "UtilFunction.h"

std::wstring StringToWstring(std::string& str)
{
    std::wstring tmp;
    tmp.assign(str.begin(), str.end());
    wprintf(tmp.c_str());
    return tmp;
}

std::string WstringToString(std::wstring& wstr)
{
    std::string tmp;
    tmp.assign(wstr.begin(), wstr.end());
    printf(tmp.c_str());
    return tmp;
}

int GetRandomNum(int start, int end)
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dis(start, end);

    return dis(gen);
}