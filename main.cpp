/*
**
**  Author : Aurelien Girardeau
**
*/

#include "MazeCore.hh"

int		main(int ac, char **av)
{
  MazeCore	prog;

  try
    {
      prog.init(ac, av);
      prog.run();
    }
  catch (Exceptions::ArgumentException e)
    {
      std::cerr << e.what() << std::endl;
    }
  catch (Exceptions::SizeException e)
    {
      std::cerr << e.what() << std::endl;
    }
  return EXIT_SUCCESS;
}
