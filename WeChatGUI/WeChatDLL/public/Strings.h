#pragma once
#include <string>
#include <vector>

//ʮ�������ַ���ת�ֽڼ�
std::vector<unsigned char> HexStrToBin(std::string& HexCode);

std::string ReplaceString(std::string& str,std::string to_replaced,const std::string& newchars);

std::string UnicodeToAnsi(const wchar_t* szStr);

std::wstring AnsiToUnicode(const char* szStr);

//תutf8
std::string LocalCpToUtf8(const char* str);