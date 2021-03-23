#include "turtle.h"
#include "draw.h"
#include <iostream>
#include <cmath>

using namespace std;

Turtle::Turtle(double xi, double yi, double diri){
	X = xi;
	Y = yi;
	direction = diri;
    color = draw::BLACK;
    trans = 0;
}

void Turtle::move(double distance){
	double x2 = X + distance*(cos(direction*(M_PI / 180)));
	double y2 = Y + distance*(sin(direction*(M_PI / 180)));
    draw::setcolor(color);
    if(trans == 0){
        draw::line(X, Y, x2, y2);
    }
	X = x2;
	Y = y2;
}

void Turtle::turn(double deg){
	direction = direction + deg;
}

void Turtle::setColor(Color c){
	color = c;
}

void Turtle::on(){
	trans = 0;
}

void Turtle::off(){
	trans = 1;
}