/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <locale>
#include <string>
#include <vector>

// convert string to wstring
/* --------------------------------------------------------------------------*/
/**
 * @synopsis  to_wstring 
 *
 * @param str
 * @param loc
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
std::wstring to_wstring (const std::string& str,
                         const std::locale& loc = std::locale())
{
   std::vector<wchar_t> buf(str.size());

    // std::use_facet
   // C++  Localizations library 
   // Defined in header <locale>
   // template< class Facet >
   // const Facet& use_facet( const std::locale& loc );
   //
   // std::ctype  
   // Defined in header <locale>
   // template< class CharT >
   // class ctype;
   // 
   // public:
   // CharT widen( char c ) const;	
   // public:
   // const char* widen( const char* beg, const char* end, CharT* dst ) const;
   // 
   // 国际化议题通常被划分为数个不同的模块，例如：数值、日期时间、货币等
   // 国际话的每个模块由locale内不同的对象处理，
   // 我们将这样一个处理某一模块的对象称为facet
   // locale则扮演了facet的容器。
   // 要存取locale的某个模块，可以相应的facet型别作为索引。
   // 将facet作为template参数，传递给use_facet()函数，便可以取得特定的facet
   //
   std::use_facet<std::numpunct<char> >(loc);
   std::use_facet<std::ctype<wchar_t>>(loc).widen(str.data(),
                                                  str.data()+str.size(),
                                                  buf.data());
   return std::wstring(buf.data(),buf.size());
}

// convert wstring to string with '?' as default character
/* --------------------------------------------------------------------------*/
/**
 * @synopsis  to_string 
 *
 * @param str
 * @param loc
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
std::string to_string (const std::wstring& str,
                       const std::locale& loc = std::locale())
{
   std::vector<char> buf(str.size());

  

   std::use_facet<std::ctype<wchar_t>>(loc).narrow(str.data(),
                                                   str.data()+str.size(),
                                                   '?', buf.data());
   return std::string(buf.data(),buf.size());
}
