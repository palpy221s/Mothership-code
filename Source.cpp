/*Write class AlienShip.AlienShip has 5 integer variables : xpos, ypos, xdir, ydir, and health.
It also has an ALLEGRO_BITMAP variable named "image".
It has 3 functions that take no parameters and return nothing : 
move, draw, and decreaseHealth.It has 3 functions that also take no parameters,
but return an integer : getX, getY, and getHealth.It also has a constructor that 
takes 3 parameters : int x, int y, and ALLEGRO_BITMAP* pic.

The constructor sets the xand y positions, the xdirand ydir to 0 and 2, and the image to pic.
The draw function just calls al_draw_bitmap.

After writing the class, stampand draw one alien ship - you can use the bitmap 
included or your own.
We'll add the movement and other functions tomorrow. NOTE: I'd recommend using 
the Allegro keyboard input base code from the
website so you have a timerand render section set up already.
Optional extension : combine this with the stars class from last week : D



The getX, getY, and getHealth functions simply return the xpos, ypos, and health respectively.
The decreaseHealth function subtracts one from the health variable.
Here's the part of the move function that handles rightward movement:
if (xdir == 1) //1 means right
xpos++;
if (xdir == 1 && xpos > SCREEN_W - 100) //you can replace screen_w with the width of your screen
xdir = 0; //0 means left
You need to add two more if statements so it can also move left.
Add a call to the move function in the timer section of your game to get the mothership to move.
Extension: Add horizontal movement.
Double extension: add some randomness to the movement algorithm.*/

#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h> //draws shapes
#include<allegro5/allegro_image.h>

class AlienShip {
private:
	double xpos;
	double ypos;
	double xdir;
	double ydir;
	int health;
	ALLEGRO_BITMAP* image;
public:
	void move();
	void draw();
	void decreaseHealth();
	int getY();
	int getX();
	int getHealth();
	AlienShip(int x, int y, ALLEGRO_BITMAP* pic); //constructor
};
class Missile {
private:
	double xpos;
	double ypos;
	double xdir;
	double ydir;



};

int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY* display = al_create_display(800, 800);
	ALLEGRO_BITMAP* cat = al_load_bitmap("mothership.png");
	
	//stamp the class
	AlienShip Mothership(100, 100, cat);
	AlienShip Mothership2(300, 300, cat);

	while (1) {//game loop
		Mothership.move();
		Mothership2.move();
		Mothership.draw();
		Mothership2.draw();
		al_flip_display();
	}
	al_destroy_display(display);
}

void AlienShip:: move() {
	//right movement
	if (xdir == 1) //1 means right
		xpos+=.2;
	if (xdir == 1 && xpos > 800 - 100) //you can replace screen_w with the width of your screen
		xdir = 0; //0 means left

	//left movement
	if (xdir == 0) //move left
		xpos-=.2;
	if (xdir == 0 && xpos <0) //you can replace screen_w with the width of your screen
		xdir = 1; //move right again

	if (ydir == 2) //1 means right
		ypos += .2;
	if (ydir == 2 && ypos > 800 - 100) //you can replace screen_w with the width of your screen
		ydir = 0; //0 means left

	if (ydir == 0) 
		ypos -= .2;
	if (ydir == 0 && ypos <400) 
		ydir = 2; 



	/*if (ydir == 1) //1 means right
		ypos++;
	if (ydir == 1 && ypos > 800 - 100) //you can replace screen_w with the width of your screen
		ydir = 0; //0 means left*/
}
void AlienShip::draw() {
	al_draw_bitmap(image, xpos, ypos, NULL);
}
void AlienShip::decreaseHealth() {
	health--;
}
int AlienShip::getY() { return ypos; }
int AlienShip::getX() { return xpos; }
int AlienShip::getHealth() { return health; }
AlienShip::AlienShip(int x, int y, ALLEGRO_BITMAP* pic) {
/*The constructor sets the xand y positions, the xdirand ydir to 0 and 2, and the image to pic.
The draw function just calls al_draw_bitmap.*/
	xpos = x;
	ypos = y;
	image = pic;
	xdir = 0;
	ydir = 2;
	health = 100;

} //constructor
