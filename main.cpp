
#include <iostream>
#include <string>

#include "Types.h"
#include "MazeSolver.h"

// Helper test functions
void testBreadcrumb();
void testTrail();

// Read a maze from standard input.
void readMazeStdin(Maze maze);

// Print out a Maze to standard output.
void printMazeStdout(Maze maze, Trail* solution);

int main(int argc, char** argv) {
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    // std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    // testBreadcrumb();
    // testTrail();
    // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Maze from stdin
    Maze maze;
    readMazeStdin(maze);

    // Solve using MazeSolver
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    MazeSolver* solver = new MazeSolver();
    Trail* solution = nullptr;
    solver->solve(maze);
    solution = solver->getSolution();

    // Print Maze to stdout
    printMazeStdout(maze, solution);

    delete solver;
    delete solution;

    return EXIT_SUCCESS;
}

void readMazeStdin(Maze maze) {
    // ASSUME THE MAZE IS A FIXED SIZE (20X20).
    if(std::cin.good()) {
        for(int i=0; i< MAZE_DIM; ++i) {
            for(int j=0; j< MAZE_DIM; ++j) {
                std::cin >> maze[i][j];
            }
        }
    }
}


void printMazeStdout(Maze maze, Trail* solution) {
    int x = 0;
    int y = 0;

    for(int i = 0; i<TRAIL_ARRAY_MAX_SIZE; ++i) {
        if (solution->getPtr(i) != nullptr) {
            if(!solution->getPtr(i)->isStale()) {
                x = solution->getPtr(i)->getX();
                y = solution->getPtr(i)->getY();
                
                maze[y][x] = ROUTE;
            }
        }
    }

    for(int i=0; i< MAZE_DIM; ++i) {
        for(int j=0; j< MAZE_DIM; ++j) {
            std::cout << maze[i][j];
            }
        std::cout << std::endl;
    }
    
}

void testBreadcrumb() {
    std::cout << "TESTING BREADCRUMB" << std::endl;

    // Make a breadcrumb and print out the contents
    Breadcrumb* breadcrumb = new Breadcrumb(1, 1, false);
    std::cout << breadcrumb->getX() << ",";
    std::cout << breadcrumb->getY() << ",";
    std::cout << breadcrumb->isStale() << std::endl;

    // Change breadcrumb stale-ness and print again
    breadcrumb->setStale(true);
    std::cout << breadcrumb->getX() << ",";
    std::cout << breadcrumb->getY() << ",";
    std::cout << breadcrumb->isStale() << std::endl;
}

void testTrail() {
    std::cout << "TESTING TRAIL" << std::endl;

    // Make a simple trail, should be empty size
    Trail* trail = new Trail();
    std::cout << "Trail size: " << trail->size() << std::endl;

    // Add a breadcrumb to the trail, print size, check contains
    Breadcrumb* b1 = new Breadcrumb(1, 1, false);
    trail->addCopy(b1);
    std::cout << "Trail size: " << trail->size() << std::endl;
    std::cout << "Contains (0,0): " << trail->contains(0,0) << std::endl;
    std::cout << "Contains (1,1): " << trail->contains(1,1) << std::endl;

    // Add second breadcrumb
    Breadcrumb* b2 = new Breadcrumb(0, 0, true);
    trail->addCopy(b2);
    std::cout << "Trail size: " << trail->size() << std::endl;
    std::cout << "Contains (0,0): " << trail->contains(0,0) << std::endl;
    std::cout << "Contains (1,1): " << trail->contains(1,1) << std::endl;

    // Test Get-ith - should be 0,0,true
    Breadcrumb* getB = trail->getPtr(1);
    std::cout << getB->getX() << ",";
    std::cout << getB->getY() << ",";
    std::cout << getB->isStale() << std::endl;

    // Print out the trail
    std::cout << "PRINTING OUT A TRAIL IS AN EXERCISE FOR YOU TO DO" << std::endl;
}
