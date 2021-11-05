//
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>
#include <string>
#include <unordered_set>
using namespace std;

class Creature {
public:
/**
  * operator<<
  * @param ostream: reference of an ostream
  * @param Creature: the creature's the user wants to print
  * @Pre: NONE
  * @Post: NONE
  * @Return: ostream
  * @functions: getRow, getCol
  */
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;

public:
/**
  * Creature (constructor)
  * @param Row: the Row of the creature is spawning in
  * @param Col: the Col of the creature is spawning in
  * @Pre: NONE
  * @Post: Initialize all instance variables
  * @Return: n/a
  * @functions: 
  */
  Creature(int Row, int Col);
/**
  * solve
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: creature will be at the exit with a path and visited places marked
  * @Return: the path returned from solveHelper
  * @functions: solveHelper()
  */
  string solve(Maze &Maze);


/**
  * atExit
  * @param Maze: the maze that we want to check the exit at
  * @Pre: NONE
  * @Post: NONE
  * @Return: True if the creature's row and col is 
  *  the same as the maze's exit row and col false otherwise
  * @functions: getExitRow() getExitColumn()
  */
  bool atExit(const Maze &Maze) const;
  /**
  * goNorth
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "N"
  * @functions: isWall(), markAsPath()
  */
  string goNorth(Maze &Maze);
  /**
  * goSouth
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "S"
  * @functions: isWall(), markAsPath()
  */
  string goSouth(Maze &Maze);
  /**
  * goEast
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "E"
  * @functions: isWall(), markAsPath()
  */
  string goEast(Maze &Maze);
  /**
  * goWest
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: maze will be marked and row will be changed
  * @Return: a direction the creature went "W"
  * @functions: isWall(), markAsPath()
  */
  string goWest(Maze &Maze);
  /**
  * getRow
  * @Pre: NONE
  * @Post: NONE
  * @Return: the creature's Row
  * @functions:
  */
  int getRow() const;
  /**
  * getCol
  * @Pre: NONE
  * @Post: NONE
  * @Return: the creature's Col
  * @functions:
  */
  int getCol() const;
private:
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
  string solveHelper(Maze &Maze, string &path, string dir, int Row, int Col);
  /**
  * seek
  * @param Maze: the maze the creature is currently in
  * @Pre: NONE
  * @Post: NONE
  * @Return: a direction the creature can go
  * @functions: isWall()
  */
  string seek(const Maze &Maze) const;
  
};

#endif //ASS3_CREATURE_H