//
//

#include <iostream>
#include "maze.h"
#include <fstream>
#include <string>

using namespace std;

//prints out the whole field (Maze)
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
      Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}

// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
Maze::Maze(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  InFile >> Width >> Height;
  InFile >> ExitRow >> ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
      //cout << Row << ", " << Col << ": " << Field[Row][Col] << endl;
    }
    getline(InFile, Str);
  }

}
//returns the exit row
int Maze::getExitRow() const {
  return ExitRow;
}
//returns the exit col
int Maze::getExitColumn() const {
  return ExitColumn;
}
//check if where the row and col is a space
bool Maze::isClear(int Row, int Col) const {
  return Field[Row][Col] == ' ';
}
//mark the row and col with *
void Maze::markAsPath(int Row, int Col) {
  Field[Row][Col] = '*';
}
//mark the row and col with +
void Maze::markAsVisited(int Row, int Col) {
  Field[Row][Col] = '+';
}

/**
  * isWall
  * @param Row: the Row of location the function is checking for
  * @param Col: the Column of location the function is checking for
  * @Pre: NONE
  * @Post: NONE
  * @Return: true if its not an empty space
  * @functions:
  */
bool Maze::isWall(int Row, int Col) const {
  return this->Field[Row][Col] == 'x' 
  || this->Field[Row][Col] == '*' 
  || this->Field[Row][Col] == '+';
}

/**
  * getHeight
  * @Pre: NONE
  * @Post: NONE
  * @Return: the maze's height
  * @functions:
  */
int Maze::getHeight() const{
  return this->Height;
}

/**
  * getWidth
  * @Pre: NONE
  * @Post: NONE
  * @Return: the maze's width
  * @functions:
  */
int Maze::getWidth() const{
  return this->Width;
}