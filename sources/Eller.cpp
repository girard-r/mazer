#include "Eller.hh"

Eller::Eller()
{
}

Eller::~Eller()
{
}

IGen*		Eller::clone()
{
  return new Eller();
}

void		Eller::seed(long seed)
{
  _randomEngine.seed(seed);
  std::cout << "Eller seeded with value : " << (long)seed << std::endl;
}

void		Eller::generateMaze(Maze *maze)
{
  State		*state = new State(maze->getWidth());

  // Horizontals
  for (int rowCounter = 0; rowCounter < maze->getHeight(); ++rowCounter)
    {
      state->populate();
      
      std::vector<std::vector<int> > connectedSets;
      std::vector<int> connectedSet;
      connectedSet.push_back(0);

      for (int cell = 0; cell < maze->getWidth() - 1; ++cell) {
	if (state->same(cell, cell + 1) || (_randomEngine() % 2 == 0 && rowCounter < maze->getHeight() - 1)) {
	  connectedSets.push_back(connectedSet);
	  connectedSet = std::vector<int>(1, cell + 1);
	} else {
	  state->merge(cell, cell + 1);
	  connectedSet.push_back(cell + 1);
	}
      }

      connectedSets.push_back(connectedSet);

      // Verticals
      State	*nextState = state->next();
      std::vector<int> verticals;

      for (auto& set : state->getSets())
	{
	  int cnt = 0;
	  bool connected = false;
	  for (int cell : set.second) {
	    // If no vertical link exists in the set, add one
	    if (_randomEngine() % 2 == 0
		|| (cnt == set.second.size() - 1 && !connected)) {
	      connected = true;
	      nextState->add(cell, set.first);
	      verticals.push_back(cell);
	    }
	    cnt += 1;
	  }
	}

      // Modify maze in consequence
      // Horizontal links
      for (auto& set : connectedSets) {
	for (int i = 0; i < set.size(); ++i) {
	  if (i < set.size() - 1)
	    maze->connectCells(rowCounter, set[i], rowCounter, set[i + 1]);

	  // verticals links
	  if (std::find(verticals.begin(), verticals.end(), set[i]) != verticals.end()
	      && rowCounter < maze->getHeight() - 1)
	    {
	      maze->connectCells(rowCounter, set[i], rowCounter + 1, set[i]);
	    }
	}
      }
      
      // Get next state for next loop
      delete state;
      state = nextState;
    }
  delete state;
  std::cout << "Maze successfully generated using Eller's algorithm" << std::endl;
}

State::State(int width, int nextSet)
  : _width(width), _nextSet(nextSet)
{
}

State::~State()
{
}

State*		State::next()
{
  return new State(_width, _nextSet);
}

void		State::populate()
{
  for (int cell = 0; cell < _width; ++cell)
    {
      std::vector<int>	set;
      std::map<int, int>::const_iterator it = _cells.find(cell);
      if (it == _cells.end()) {
	_nextSet += 1;
	set.push_back(cell);
	_sets[_nextSet] = set;
	_cells[cell] = _nextSet;
      }
    }
}

bool		State::same(int cell1, int cell2)
{
  return _cells[cell1] == _cells[cell2];
}

void		State::merge(int cell1, int cell2)
{
  int setFrom = _cells[cell1];
  int setTo = _cells[cell2];

  for (int cell : _sets[setTo]) {
    _sets[setFrom].push_back(cell);
    _cells[cell] = setFrom;
  }

  _sets.erase(setTo);
}

void		State::add(int cell, int set)
{
  _cells[cell] = set;
  std::map<int, std::vector<int> >::const_iterator it = _sets.find(set);
  if (it != _sets.end()) {
    _sets[set].push_back(cell);
  } else {
    _sets[set] = std::vector<int>(1, cell);
  }
}

std::map<int, std::vector<int> >&	State::getSets()
{
  return _sets;
}
