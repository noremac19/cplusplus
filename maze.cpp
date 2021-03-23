/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze;
    
    if(argc<2){
        cout << "Please provide a maze input file" << endl;
        return 1;
    }
   
   mymaze = read_maze(argv[1], &rows, &cols); 
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
  result = maze_search(mymaze, rows, cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
    for (int a=0; a<rows; a++){
		delete [] mymaze[a];
	}
	delete [] mymaze;
    return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
    Location start;
    int startcount = 0;
    int finishcount = 0;
	bool found = false;

	// Counts how many starts and finishes found
	for (int a=0; a<rows; a++){
		for (int b=0; b<cols; b++){
			if (maze[a][b] == 'S'){
				start.row = a;
				start.col = b;
				startcount++;
			}else if (maze[a][b] == 'F'){
    			finishcount++;
    		}
		}
	}
    
    if (startcount != 1 || finishcount != 1){
    	return -1;
    }
    
    Queue q(rows * cols);
	q.add_to_back(start);
    int ** visited;
	visited = new int* [rows];
    
    for (int a=0; a<rows; a++){
		visited[a] = new int[cols];
	}
	for (int a=0; a<rows; a++){
		for (int b=0; b<cols; b++){
			visited[a][b] = 0;
		}
	}
    
    visited[start.row][start.col] = 1;

	Location predstart;
	predstart.row = -1;
	predstart.col = -1;

	Location ** predecessor;
	predecessor = new Location* [rows];

	for (int a = 0; a < rows; a++){
		predecessor[a] = new Location[cols];
	}

	for (int a = 0; a < rows; a++){
		for (int b = 0; b < cols; b++){
			predecessor[a][b] = predstart;
		}
	}
    while(!q.is_empty()){
		Location current = q.remove_from_front();
		Location above1;
		above1.row = current.row - 1;
		above1.col = current.col;
		if(above1.row >= 0){
			if(maze[above1.row][above1.col] == 'F'){
				while(maze[current.row][current.col] != 'S'){
					maze[current.row][current.col] = '*';
					current = predecessor[current.row][current.col];
				}
				found = true;
				break;
			}else if (maze[above1.row][above1.col] == '.' && visited[above1.row][above1.col] == 0){
				visited[above1.row][above1.col] = 1;
				predecessor[above1.row][above1.col] = current;
				q.add_to_back(above1);
			}
		}
        
        Location left1;
		left1.row = current.row;
		left1.col = current.col - 1;
		if(left1.col >= 0){
			if(maze[left1.row][left1.col] == 'F'){
				while(maze[current.row][current.col] != 'S'){
					maze[current.row][current.col] = '*';
					current = predecessor[current.row][current.col];
				}
				found = true;
				break;
			}else if(maze[left1.row][left1.col] == '.' && visited[left1.row][left1.col] == 0){
				visited[left1.row][left1.col] = 1;
				predecessor[left1.row][left1.col] = current;
				q.add_to_back(left1);
			}
		}
        
        Location below1;
		below1.row = current.row + 1;
		below1.col = current.col;
		if(below1.row < rows){
			if(maze[below1.row][below1.col] == 'F'){
				while(maze[current.row][current.col] != 'S'){
					maze[current.row][current.col] = '*';
					current = predecessor[current.row][current.col];
				}
				found = true;
				break;
			}else if (maze[below1.row][below1.col] == '.' && visited[below1.row][below1.col] == 0){
				visited[below1.row][below1.col] = 1;
				predecessor[below1.row][below1.col] = current;
				q.add_to_back(below1);
			}
		}
        
        Location right1;
		right1.row = current.row;
		right1.col = current.col + 1;
		if(right1.col < cols){
			if(maze[right1.row][right1.col] == 'F'){
				while(maze[current.row][current.col] != 'S'){
					maze[current.row][current.col] = '*';
					current = predecessor[current.row][current.col];
				}
				found = true;
				break;
			}else if (maze[right1.row][right1.col] == '.' && visited[right1.row][right1.col] == 0){
				visited[right1.row][right1.col] = 1;
				predecessor[right1.row][right1.col] = current;
				q.add_to_back(right1);
			}
		}
        
    }
    for (int a=0; a<rows; a++){
		    delete [] predecessor[a];
		    delete [] visited[a];
	    }
	    delete [] predecessor;
	    delete [] visited;
    
	    if (found == true){
		    return 1;
	    }else{
		    return 0;
	    }  
}
