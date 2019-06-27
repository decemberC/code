/*  Filename:       main.cpp
    Description:    MET4335 - Lab07
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include "GL/freeglut.h"

using namespace std;


/*************************************
**  TGA class for .tga image files  **
**************************************/
class TGA {
    public:
        int Load(const char *filename);
        void Release() { free(imageData); }     // free image memory

// *** Task-A-3 ***
// *** Task-A-3 ***

    private:
        GLubyte *imageData;
        GLuint bytePerPixel;
        struct tgaHeader {
            unsigned char idLength;
            unsigned char colorMapType;
            unsigned char imageTypeCode;
            unsigned char colorMapSpec[5];
            unsigned short xOrigin;
            unsigned short yOrigin;
            unsigned short width;
            unsigned short height;
            unsigned char bpp;                  // bits/pixel
            unsigned char imageDesc;
        } header;
};


int TGA::Load(const char* filename) {
    fstream tgaFile;
 
    tgaFile.open(filename, ios::in | ios::binary);

    if (!tgaFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return(-1);
    }

    // read .tga file header
    tgaFile.read((char*) &this->header, sizeof(struct tgaHeader));
    this->bytePerPixel = this->header.bpp/8;    // cal. bytes (3 or 4) per pixel

    cout << "Image file: " << filename << endl;
    cout << "   type: " << (int) this->header.imageTypeCode << endl;
    cout << "   width: " << (int) this->header.width << endl;
    cout << "   height: " << (int) this->header.height << endl;
    cout << "   bit/pixel: " << (int) this->header.bpp << endl;
    cout << "   byte/pixel: " << this->bytePerPixel << endl;
 
    int imageSize = this->header.width * this->header.height * this->header.bpp;
    this->imageData = (GLubyte*) malloc(imageSize);         
    tgaFile.read((char*) this->imageData, imageSize);     
 
    for (int i=0; i<imageSize; i+=this->bytePerPixel) {
        GLubyte blue         = this->imageData[i];
        this->imageData[i]   = this->imageData[i+2];
        this->imageData[i+2] = blue;
    }

    tgaFile.close();
    return(0);
}


// *** Task-A-4 ***
// *** Task-A-4 ***


struct glutWindow {
    GLuint width, height;
    char* title;
    GLdouble viewAngle, aspect, zNear, zFar;
} win;

// *** Task-A-5 ***
// *** Task-A-5 ***

// *** Task-A-6 ***
// *** Task-A-6 ***


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Clear Screen and Depth Buffer
    glLoadIdentity();

// *** Task-A-6 ***
// *** Task-A-6 ***

// *** Task-A-8 ***
// *** Task-A-8 ***

    glutSwapBuffers();
}


void changeSize(int width, int height) {
    if (height==0) height = 1;                                  // prevent divide by zero
    win.width = width;
    win.height = height;
    win.aspect = (GLdouble)width / (GLdouble)height;
    glMatrixMode(GL_PROJECTION);                                // use projection matrix
    glViewport(0, 0, win.width, win.height);                    // set the viewport
    glMatrixMode(GL_PROJECTION);                                // set matrix mode
    glLoadIdentity();                                           // reset projection matrix
    gluPerspective(win.viewAngle, win.aspect, win.zNear, win.zFar);
    glMatrixMode(GL_MODELVIEW);                                 // specify which matrix is the current matrix
}


void initialize() {
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);                                         // specify the clear value for the depth buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // specify implementation-specific hints

    glClearColor(0.5, 0.5, 0.5, 1.0);

// *** Task-A-7 ***
// *** Task-A-7 ***
}


void keyboard (unsigned char key, int mousePositionX, int mousePositionY) { 
    switch (key) {
        case 27 :   // [ESCAPE] key
            exit(0);   
            break;      

        default : break;
    }
}


int main(int argc, char **argv) {
    // set window values
    win.width = 1440;
    win.height = 900;
    win.title = "Texture Mapping";
    win.viewAngle = 90.0;
    win.aspect = (GLdouble)win.width / (GLdouble)win.height;
    win.zNear = 1.0;
    win.zFar = 100.0;

    cout << "Programmer: <your name>\n";
    cout << "Compiled on " __DATE__ ", " __TIME__ << endl << endl;

    // initialize and run program
    glutInit(&argc, argv);                                      // GLUT initialization
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  // Display Mode
    glutInitWindowSize(win.width, win.height);                  // set window size
    glutCreateWindow(win.title);                                // create Window

    glutReshapeFunc(changeSize);
    glutDisplayFunc(display);                                   // register Display Function
    glutIdleFunc(display);                                      // register Idle Function

    glutKeyboardFunc(keyboard);                                 // register Keyboard Handler
    initialize();

    // *** Task-A-9 ***
    // *** Task-A-9 ***

    glutMainLoop();                                             // run GLUT mainloop
    return(0);
}
