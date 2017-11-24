#include <GL/glut.h>

GLsizei winWidth = 1000 , winHeight = 800;
GLint xRaster = 25 , yRaster = 40;

GLubyte f_label [2] = { '0','5' };

GLubyte label [10] = {'1','0','1', '5','2','0', '2','5','3', '0'};

GLint dataValue_orange [8] = { 290 , 370 , 430 , 450 , 480 , 573 , 680 , 770   };

GLint dataValue_blue [8] = { 240 , 280 , 311 , 348 , 380 , 465 , 540 , 680   };

GLubyte dataValue_text [500] = {
'b' , 'a' , 'z' , 'n' , 'e' , 'g' , 'a' , 'r' , 'i' , ' ' , 'v' , 'a' , ' ' , 'b' , 'e' , 'h' , 'b' , 'o' , 'd' , 'e' , 't' , 'a' , 'r' , 'h' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '  ,
'a' , 'r' , 'z' , 'y' , 'a' , 'b' , 'i' , ' ' , 'a' , 'v' , 'a' , 'l' , 'i' , 'e' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '  ,
'e' , 'j' , 'r' , 'a' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '  ,
'e' , 'n' , 't' , 'e' , 'k' , 'h' , 'a' , 'b' , 'e' , ' ' , 'f' , 'o' , 'r' , 'o' , 's' , 'h' , 'g' , 'h' , 'a' , 'h' , 'a' , 'y' , 'e' , ' ' , 'p' , 'a' , 'i' , 'l' , 'o' , 't'  ,
'a' , 'm' , 'o' , 'o' , 'z' , 'e' , 's' , 'h' , 'e' , ' ' , 's' , 'a' , 'r' , 'c' , 'h' , 'a' , 'n' , 'd' , 'd' , 'a' , 'y' , 'z' , 'e' , 'r' , 'h' , 'a' , ' ' , ' ' , ' ' , ' '  ,
'k' , 'h' , 'a' , 'r' , 'i' , 'd' , 'e' , ' ' , 'm' , 'a' , 'l' , 'z' , 'o' , 'm' , 'a' , 't' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '  ,
't' , 'a' , 'r' , 'a' , 'h' , 'i' , 'e' , ' ' , 'p' , 'e' , 'l' , 'n' , 'o' , 'g' , 'r' , 'a' , 'm' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '  ,
'b' , 'a' , 'r' , 'n' , 'a' , 'm' , 'e' , ' ' , 'r' , 'i' , 'z' , 'i' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '  ,

};



void init (void)
{
     glClearColor (1.0, 1.0, 1.0, 1.0);
     glMatrixMode (GL_PROJECTION);
     gluOrtho2D (0.0 , 1000 , 0.0 , 1000);

}


void barChart (void)
{
     GLint month , o , n , b , k;

     glClear(GL_COLOR_BUFFER_BIT);


     glColor3f (0.0, 0.0, 1.0);

     glBegin (GL_LINES);          //print 7 lines

             for( int x=0 ; x<7 ; x++)
             {
                  glVertex2i ( x * 100 + 210  , 60);
                  glVertex2i ( x * 100 + 210  , 510);
             }
     glEnd();


     glColor3f (1.0, 0.7, 0.0);     //print orange rectangle
        for(o=0 ; o<8 ; o++)
         glRecti (210, 80 + o*50, dataValue_orange [o] ,  100 + o*50  );

     glColor3f (0.0, 0.0, 1.0);    //print orange rectangle
        for(b=0 ; b<8 ; b++)
         glRecti (210, 80 + b*50, dataValue_blue [b] ,  100 + b*50  );




     glColor3f (0.0, 0.0, 0.0);       //print value of bar
     xRaster = 208;
     for (n=0 ; n<2 ; n++)
          {
              glRasterPos2i (xRaster , yRaster);
              glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12 , f_label [n]);
              xRaster += 100;
           }

     for (month=0 ; month<10 ; month++)
          {
              glRasterPos2i (xRaster , yRaster);
              for (k = 2*month ; k < 2*month + 2 ; k++)
                  glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12 , label [k]);
              xRaster += 100;
           }



     glColor3f (0.0, 0.0, 0.0);       //print character of bar
     xRaster = 20;
     yRaster = 87 ;
     for (month=0 ; month<9 ; month++)
          {
              glRasterPos2i (xRaster , yRaster);
              for (k = 30*month ; k < 30*month + 30 ; k++)
                  glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12 , dataValue_text [k]);
              yRaster += 50;
           }




     glFlush();
}


void winReshapeFcn (int newWidth , int newHeight)
{
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity ();
     gluOrtho2D (0.0 , GLdouble (newWidth) , 0.0 , GLdouble (newHeight));
     glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc , char** argv)
{
     glutInit (&argc , argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowPosition (100,100);
     glutInitWindowSize (winWidth , winHeight);
     glutCreateWindow ("Bar Chart Data Plot");

     init();

     glutDisplayFunc (barChart);
     glutReshapeFunc (winReshapeFcn);

     glutMainLoop ();

     return 0;
}
