# include "Factory.hh"

Factory::genMap	Factory::_genOccur = {
  {"--ga", new AldousBroder()},
  {"--ge", new Eller()}
};

Factory::solveMap	Factory::_solveOccur = {
  {"--pm", new Dijkstra(new ManhattanH())},
  {"--pe", new Dijkstra(new EuclideanH())},
  {"--pd", new DepthFirst()},
  {"--pb", new BreadthFirst()}
};

IGen*	Factory::getGenAlgorithm(std::string const& choice)
{
  return _genOccur[choice]->clone();
}

ISolve*	Factory::getSolveAlgorithm(std::string const& choice)
{
  return _solveOccur[choice]->clone();
}
