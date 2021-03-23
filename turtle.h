#include "draw.h"

class Turtle
{	
	public:
		Turtle(double xi, double yi, double diri);
		void move(double distance);
		void turn(double deg);
        void setColor(Color c);
		void on();
		void off();

	private:
		double X;
		double Y;
		double direction;
        Color color;
		int trans;
};
