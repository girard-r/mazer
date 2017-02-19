/*
**
**  Author : Aurelien Girardeau
**
*/

#include "Utils.hh"

Utils::Utils()
{
}

Utils::~Utils()
{
}

bool	Utils::isInteger(std::string const& param)
{
  std::string tmp = (param.find("-") == 0 && param.size() > 1 ? param.substr(1) : param);
  for (std::string::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
      if (!isdigit(*it))
	return false;
    }
  return true;
}

bool	Utils::fileExists(std::string const& fileName)
{
  std::ifstream	file;
  bool		ret = false;

  file.open(fileName);
  ret = file.good();
  if (ret)
    file.close();
  return ret;
}

std::string		Utils::doubleToString(double n)
{
  std::ostringstream	buff;

  buff << n;
  return buff.str();
}

int			Utils::stringToInt(std::string const& toConvert)
{
  std::istringstream	buff(toConvert);
  int			ret = 0;

  if (!isInteger(toConvert))
    throw Exceptions::ArgumentException(toConvert, "is not an integer");
  buff >> ret;
  return ret;
}

long			Utils::stringToLong(std::string const& toConvert)
{
  std::istringstream	buff(toConvert);
  long			ret = 0;

  if (!isInteger(toConvert))
    throw Exceptions::ArgumentException(toConvert, "is not an integer");
  buff >> ret;
  return ret;
}
