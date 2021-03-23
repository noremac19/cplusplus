#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
    for(int i = 0; i < height; i++){
        if(top+i >=0 && top+i <= 255){
            if(left >= 0 && left <=255){
                image[top+i][left] = 0;
            }
            if(width+left >= 0 && width+left <= 255){
                image[top+i][width+left] = 0;
            }
        }
    }
    
    for(int i = 0; i < width; i++){
        if(left+i >=0 && left+i <= 255){
            if(top >= 0 && top <=255){
                image[top][left+i] = 0;
            }
            if(height+left >= 0 && height+left <= 255){
                image[top+height][i+left] = 0;
            }
        }
    }


}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
    for(double angle = 0.0; angle < 2*M_PI; angle += .01){
        double x = cos(angle)*(width/2);
        double y = sin(angle)*(height/2);
        if(cy+y >= 0 && cy+y <= 255){
            image[(int)(cy+y)][(int)(cx+x)] = 0;
        }
    }
}


int main(){
   // initialize the image to all white pixels
   for (int a=0; a < SIZE; a++) {
      for (int b=0; b < SIZE; b++) {
         image[a][b] = 255;
      }
   }
   
   // Main program loop here
    int top;
    int left;
    int height;
    int width;
    int cy;
    int cx;
    
    int n = 1;
    while(n != 2){
        cout << "Enter 0 draw a rectangle. Enter 1 to draw an ellipse. Enter 2 to quit" << endl;
        cin >> n;
        if(n==0){
            cout << "Enter: row, column, height, width" << endl;
            cin >> top >> left >> height >> width;
            draw_rectangle(top, left, height, width);
        }else if(n==1){
            cout << "Enter: center row, center column, height, width" << endl;
            cin >> cy >> cx >> height >> width;
            draw_ellipse(cy, cx, height, width);
        }
    }
    
   
   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
