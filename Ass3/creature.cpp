//
//

#include "creature.h"
#include "iostream"

/**
  * operator<<
  * @param ostream: reference of an ostream
  * @param Creature: the creature's the user wants to print
  * @Pre: NONE
  * @Post: NONE
  * @Return: ostream
  * @functions:
  */
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  return Out << Creature.getRow() << ", " << Creature.getCol();
}

/**
  * Creature (constructor)
  * @param Row: the Row of the creature is spawning in
  * @param Col: the Col of the creature is spawning in
  * @Pre: NONE
  * @Post: Initialize all instance variables
  * @Return: n/a
  * @functions: 
  */
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

/**
  * atExit
  * @param Maze: the maze that we want to check the exit at
  * @Pre: NONE
  * @Post: NONE
  * @Return: True if the creature's row and col is 
  *  the same as the maze's exit row and col false otherwise
  * @functions: getExitRow() getExitColumn()
  */
bool Creature::atExit(const Maze &Maze) const {
  return this->Row == Maze.getExitRow() && this->Col == Maze.getExitColumn();
}

/**
  * solveHelper
  * @param Maze: the maze the creature is currently in
  * @param path: the path that tracks how the creature got to the exit
  * @param dir: the direction that the creature came from
  * @param Row: the Row of the creature is travesing to
  * @param Col: the Col of the creature is travesing to
  * @Pre: location and maze initialized
  * @Post: creature will be at the exit with a path and visited places marked
  * @Return: the path
  * @functions: atExit(), markAsPath(), substr(), length(), 
  *  getHeight(), getWidth(), isWall(), solveHelper()
  */
string Creature::solveHelper(Maze &Maze, string &path, 
string dir, int Row, int Col){
  this->Row = Row;
  this->Col = Col; 
  //base case if creature is at the exit
  if (this->atExit(Maze)) {
    if (Maze.isWall(this->Row,this->Col)) {
      cout << "Exit is blocked" << endl;
    }
    Maze.markAsPath(Row,Col);
    path += dir;
    path = path.substr(1,path.length()-1);
    return path;
  } 
  //base case if creature is out of bounds
  if (Row < 0 || Col < 0 || Row >= Maze.getHeight() || Col >= Maze.getWidth())
    return ""; 
  //base case if creature hits a wall/visited path
  if (Maze.isWall(Row,Col)) return "";
  //can assume we're temporaly on the right path
  Maze.markAsPath(Row,Col);
  //add direction of where we can from
  path += dir;
  //try going south, if valid, path is returned
  dir = "S";
  if (!solveHelper(Maze, path, dir, Row + 1, Col).empty()) return path;
  //try going north, if valid, path is returned
  dir = "N";
  if (!solveHelper(Maze, path, dir, Row - 1, Col).empty()) return path;
  // try going east, if valid, path is returned
  dir = "E";
  if (!solveHelper(Maze, path, dir, Row, Col + 1).empty()) return path;
  //try going west, if valid, path is returned
  dir = "W";
  if (!solveHelper(Maze, path, dir, Row, Col - 1).empty()) {
    return path;
  }
  //if it reaches this stage, the creature will have no way to go
  //mark it as visited and take out the added direction to the path
  path.pop_back();
  Maze.markAsVisited(Row,Col);
  return "";
}
  

/**
  * solve
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: creature will be at the exit with a path and visited places marked
  * @Return: the path returned from solveHelper
  * @functions: solveHelper()
  */
string Creature::solve(Maze &Maze) {
  string Path;
  return solveHelper(Maze, Path, seek(Maze),this->Row, this->Col);
}

/**
  * goNorth
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "N"
  * @functions: isWall(), markAsPath()
  */
string Creature::goNorth(Maze &Maze){
  if (Maze.isWall(this->Row-1,this->Col)){
    Maze.markAsPath(this->Row-1,this->Col);
    this->Row--;
    return "X";
  } 
  return "N";
}

/**
  * goWest
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "W"
  * @functions: isWall(), markAsPath()
  */
string Creature::goWest(Maze &Maze){
  if (Maze.isWall(this->Row,this->Col-1)){
    Maze.markAsPath(this->Row,this->Col-1);
    this->Col--;
    return "X";
  } 
  return "W";
}

/**
  * goEast
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "E"
  * @functions: isWall(), markAsPath()
  */
string Creature::goEast(Maze &Maze){
  if (Maze.isWall(this->Row,this->Col+1)){
    Maze.markAsPath(this->Row,this->Col+1);
    this->Col++;
    return "X";
  } 
  return "E";
}

/**
  * goSouth
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "S"
  * @functions: isWall(), markAsPath()
  */
string Creature::goSouth(Maze &Maze){
  if (Maze.isWall(this->Row+1,this->Col)){
    Maze.markAsPath(this->Row+1,this->Col);
    this->Row++;
    return "X";
  } 
  return "S";
}

/**
  * seek
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: NONE
  * @Return: a direction the creature can go
  * @functions: isWall()
  */
string Creature::seek(const Maze &Maze) const{
  if (!Maze.isWall(this->Row+1,this->Col)) return "S";
  if (!Maze.isWall(this->Row-1,this->Col)) return "N";
  if (!Maze.isWall(this->Row,this->Col+1)) return "E";
  if (!Maze.isWall(this->Row,this->Col-1)) return "W";
  return "X";
}


/**
  * getRow
  * @Pre: NONE
  * @Post: NONE
  * @Return: the creature's Row
  * @functions:
  */
int Creature::getRow() const{
  return this->Row;
}

/**
  * getCol
  * @Pre: NONE
  * @Post: NONE
  * @Return: the creature's Col
  * @functions:
  */
int Creature::getCol() const{
  return this->Col;
}