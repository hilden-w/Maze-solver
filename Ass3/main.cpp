#include <iostream>
#include "creature.h"
#include <cassert>
#include "maze.h"


void test() {
    Maze M("maze.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    assert(C.getRow() == M.getExitRow());
    assert(C.getCol() == M.getExitColumn());
}

void test1() {
    Maze M("maze1.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    assert(C.getRow() == M.getExitRow());
    assert(C.getCol() == M.getExitColumn());
}

void test2() {
    Maze M("maze2.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    assert(C.getRow() == M.getExitRow());
    assert(C.getCol() == M.getExitColumn());
}

void test3() {
    Maze M("maze3.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    assert(C.getRow() == M.getExitRow());
    assert(C.getCol() == M.getExitColumn());
}

void test4() {
    Maze M("maze4.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    assert(C.getRow() == M.getExitRow());
    assert(C.getCol() == M.getExitColumn());
}
int main() {
    test();
    test1();
    test2();
    test3();
    test4();
   
    
    cout << "Done!" << std::endl;
    return 0;
}