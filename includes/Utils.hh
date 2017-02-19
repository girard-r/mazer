/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <string>
# include <cctype>
# include <fstream>
# include <iostream>
# include <sstream>
# include "Exceptions.hpp"

class		Utils
{
public :
  Utils();
  ~Utils();
  static bool		isInteger(std::string const&);
  static bool		fileExists(std::string const&);
  static std::string	doubleToString(double n);
  static int		stringToInt(std::string const&);
  static long		stringToLong(std::string const&);
};
