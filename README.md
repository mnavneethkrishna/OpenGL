# OpenGL
Just some college related stuff with OpenGL and Computer Graphics. All written in C

This one is a 2D printer with simple functionality

It has two (actually many) papers displayed on the printer.
When the down arrow key is pressed, the paper appears to go through the printer and print a sample text. 

The upward arrow will send the paper back to the top (back in time!!). The code is very simple and written as a part of 
academic requirement (monthly assignment) of VTU 6th semester Computer Graphics course.

Note that this C program was written on a Macintosh operating system.
To run it on linux systems, please change the OpenGL headers to <GL/glut.h>

To execute on a Mac :
 Install XCode and then in the terminal with file in directory, "gcc printer.c -framework OpenGl -framework GLUT"
 
On Linux:
 Install OpenGL first, later with file in directory, "gcc printer.c -lglut -lGL -lGLU"
 
That should pop the window to display the printer :)

Enjoy!
