#pragma once

# include <map>
# include "IGen.hh"
# include "AldousBroder.hh"
# include "Eller.hh"
# include "ISolve.hh"
# include "Dijkstra.hh"
# include "IHeuristic.hh"
# include "ManhattanH.hh"
# include "EuclideanH.hh"
# include "DepthFirst.hh"
# include "BreadthFirst.hh"

class		Factory
{
public :
  typedef std::map<std::string, IGen*>		genMap;
  typedef std::map<std::string, ISolve*>	solveMap;
  static genMap		_genOccur;
  static solveMap	_solveOccur;
  static IGen*		getGenAlgorithm(std::string const&);
  static ISolve*	getSolveAlgorithm(std::string const&);
};
