/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <exception>
# include <string>

namespace	Exceptions
{
  class		ArgumentException : public std::exception
  {
  public:
    ArgumentException(char *arg, std::string const& msg) throw()
      : _msg(std::string(arg) + ": " + msg) {}
    ArgumentException(std::string const& arg, std::string const& msg) throw()
      : _msg(arg + ": " + msg) {}
    ArgumentException(const ArgumentException& other) throw()
      : _msg(other._msg) {}
    virtual ~ArgumentException() throw() {}
    virtual const char*	what() const throw()
    {
      return _msg.c_str();
    }
    
  private:
    ArgumentException	&operator=(const ArgumentException&) throw();
    std::string		_msg;
  };

  class		SizeException : public std::exception
  {
  public:
    SizeException(std::string const& msg) throw()
      : _msg(msg) {}
    SizeException(const SizeException& other) throw()
      : _msg(other._msg) {}
    virtual ~SizeException() throw() {}
    virtual const char*	what() const throw()
    {
      return (_msg).c_str();
    }
    
  private:
    SizeException	&operator=(const SizeException&) throw();
    std::string		_msg;
  };
}
