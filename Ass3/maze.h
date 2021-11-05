//
// 
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
  //prints out the whole field (Maze)
  friend ostream &operator<<(ostream &Out, const Maze &Maze);
private:
  const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;
public:
  //constructor
  explicit Maze(const string &FileName);
  //check if where the row and col is a space
  bool isClear(int Row, int Col) const;
  //mark the row and col with *
  void markAsPath(int Row, int Col);
  //mark the row and col with +
  void markAsVisited(int Row, int Col);
  //returns the exit row
  int getExitRow() const;
  //returns the exit col
  int getExitColumn() const;

  /**
  * isWall
  * @param Row: the Row of location the function is checking for
  * @param Col: the Column of location the function is checking for
  * @Pre: NONE
  * @Post: NONE
  * @Return: true if its not an empty space
  * @functions:
  */
  bool isWall(int Row, int Col) const;
  int getHeight() const;
  int getWidth() const;
  

};

#endif //ASS3_MAZE_H