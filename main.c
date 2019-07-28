/*
 ============================================================================
 Name        : hwl.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//sudo apt-get install libx11-dev <<<<<<<<<<
//sudo apt install libqt4-dev
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include <math.h>

const double PI25DT = 3.141592653589793238462643;

#include <stdio.h>
#include <stdlib.h>


#include <string.h>
#include <errno.h>
#include <X11/Xlib.h>

#include <X11/cursorfont.h> /* определяет XC_watch и т.п. */
/* эта переменная содержит дескриптор создаваемого курсора */
#include "bmp2nc.h"

int ret, bufa;
double  px;
char bufr[32], bufi;
Cursor p1_cursor;
Cursor p2_cursor;
Cursor p3_cursor;
Cursor p4_cursor;

//#include <X11/X.h>

void  numtostr (int in, char* out);
//char [];


int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//////////////////////////////////////////////////////////////////////////


	imgdmp imgr; ///flrdstr

	int fd; ////file
	FILE *file;
	/////////////////////file = fopen("./tabsin.tab", "wb");
	//fd = open("test.txt","rw+");/////file
	//fd=open("tabsin.tab", O_APPEND );
	int nomt, noms, pnm, notab;
	long unsigned int kimg, mkimg, ximg, yimg, drvy, drvx, imgis;
	long unsigned int offsetx_max, offsetx, offsety_max, offsety;
	char numer[2], msg2[16];
	numer[1]=0;
	int   tmp,tmp2, battw, batth, bk;// xlast, ylast,
	Display *d;
	Window w, w2;
	XEvent e;
//////////for color 
	GC gc;			/* GC (graphics context) used for drawing    */
    XGCValues gcval;


	//XSetWindowAttributes winatr;
	battw = 600;
	batth = 490;
	//tmp2=0;
	//char *msg = "Hello, World!";
	//char msg2[200];
	int s;//, t;

	if( ( d = XOpenDisplay( getenv("DISPLAY" ) ) ) == NULL )
	{  // Соединиться с X сервером,
		printf( "Can't connect X server: %s\n", strerror( errno ) );
		exit( 1 );
	}
	s = DefaultScreen( d );
	w = XCreateSimpleWindow( d, RootWindow( d, s ),     // Создать окно
			0, 0, 1000, 500, 0,
			BlackPixel( d, s ), WhitePixel( d, s ) );
//XSetWMName(d, w, "CNC_PCB");
	w2 = XCreateSimpleWindow( d, w,     // Создать окно в окні
			5, 5, battw, batth, 0,
			BlackPixel( d, s ), WhitePixel( d, s ) );
	XSelectInput( d, w2, ExposureMask | ButtonPressMask | ButtonReleaseMask  );  // На какие события будем реагировать?2222222
	XSelectInput( d, w, ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | Button1MotionMask| KeymapStateMask );  // На какие события будем реагировать?| ResizeRedirectMask
	XMapWindow( d, w );                                 // Вывести окно на экран
	XMapWindow( d, w2 );
////////////////////////////////////////////////////////////

	Atom              wm_protocols;
	Atom              wm_delete_window;

	wm_protocols = XInternAtom(d, "WM_PROTOCOLS", False);
	wm_delete_window = XInternAtom(d, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(d, w , &wm_delete_window, 1);

	/////////////////////////////////////
	XStoreName (d,w,"CNC_PCB");
//////////////////////////////////////////////////////////////////
	/* создаем курсор "песочные часы" */
	p1_cursor = XCreateFontCursor(d, XC_pencil);//XC_watch
	p2_cursor = XCreateFontCursor(d, XC_hand2);
	p3_cursor = XCreateFontCursor(d, XC_hand1);
	p4_cursor = XCreateFontCursor(d, XC_watch);
//////////////////////////colors
	
	gcval.foreground=0; 
	gc=XCreateGC (d, RootWindow (d, s), GCForeground, &gcval);
	gcval.foreground=0;
	XChangeGC (d, gc, GCForeground, &gcval);
 	



	////////////////////////////////////////////////////
	//struct termios options;
	//int fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
	    //if(fd == -1)
	    //{
	    //    perror("open_port: Unable to open:");
	    //}

	    //tcgetattr(fd, &options);

	        //cfsetispeed(&options, B9600);
	        //cfsetospeed(&options, B9600);
	        //options.c_cflag |= (CLOCAL | CREAD);
	        //options.c_cflag &= ~PARENB;
	        //options.c_cflag &= ~CSTOPB;
	        //options.c_cflag &= ~CSIZE;
	        //options.c_cflag |= CS8;
	        //options.c_cflag &= ~( ICANON | ECHO | ECHOE |ISIG );
	        //options.c_iflag &= ~(IXON | IXOFF | IXANY );
	        //options.c_oflag &= ~OPOST;

	        //tcsetattr(fd, TCSANOW, &options);

	        ////////////////////////////////////////////


	bk=open_img("img.bmp", &imgr);
	//printf ("openimg %d", bk);
	if ( (imgr.x/battw) > (imgr.y/batth) )
	{
		mkimg=imgr.x/(battw-4) + 1;
	}
	else
	{
		mkimg=imgr.y/(batth-4) + 1;
	}
	kimg=mkimg;
	// Бесконечный цикл обработки событий
	while( 1 )
	{
		XNextEvent( d, &e );
		if( e.type == Expose ) // Перерисовать окно
		{
			//if (t > 5)
			//{
			//XClearArea (d, w, 0, 0, 80, 30, True );
			//tmp=e.xexpose.window;
			//numtostr (tmp, &msg2[0]);
			//XDrawString( d, w, DefaultGC( d, s ), 0, 30, &msg2[0] ,strlen ( &msg2[0] ));
			//XFillRectangle( d, w, DefaultGC( d, s ), 0, 0, 100, 100 );

			//XDrawString( d, w2, DefaultGC( d, s ), 15, 14, msg, strlen( msg ) );
			//XDrawString( d, w2, DefaultGC( d, s ), 5, 30, "X =", 3 );
			//XDrawString( d, w2, DefaultGC( d, s ), 5, 46, "Y =", 3 );

			//	  if ( t > 10)
	    	//	  {
	    	//		  t=0;
	    	//	  }
	    	//  }
	    	//  t++;

			XDrawLine (d, w2, DefaultGC( d, s ), 0, 0, battw-1, 0);
			XDrawLine (d, w2, DefaultGC( d, s ), 0, batth-1, battw-1, batth-1);
			XDrawLine (d, w2, DefaultGC( d, s ), battw-1, 0, battw-1, batth-1);
			XDrawLine (d, w2, DefaultGC( d, s ), 0, 0, 0, batth-1);

			///////XDrawLine (d, w2, DefaultGC( d, s ), 10, 0, 10, 300);
			///////XDrawLine (d, w2, DefaultGC( d, s ), 10, 250, 500, 250);
			//gcval.foreground=0xffff00;
			//XChangeGC (d, gc, GCForeground, &gcval);
			//XDrawLine (d, w2, gc, 120, 50, 150, 400);
			//XDrawLine (d, w2, DefaultGC( d, s ), 10, 200, 150, 200);
			//XDrawLine (d, w2, DefaultGC( d, s ), 150, 708, 150, 400);
			//XDrawLine (d, w2, DefaultGC( d, s ), 10, 0, 12, 5);
			//XDrawLine (d, w2, DefaultGC( d, s ), 10, 0, 8, 5);

			//XDrawLine (d, w2, DefaultGC( d, s ), 0, 0, 0, 300);
			//imgr.x=1000;
			//imgr.y=1000;
			if (imgis < 1)
			{
				imgis = 1;
				if ( (kimg * (battw-4)) > imgr.x )
				{
					drvx=imgr.x/kimg+1;
				}
				else
				{
					drvx=battw-4;
				}
				if ( (kimg * (batth-4)) > imgr.y )
				{
					drvy=imgr.y/kimg+1;
				}
				else
				{
					drvy=batth-4;
				}

				for (yimg=0; yimg < drvy; yimg++)
				{
					for (ximg=0; ximg < drvx; ximg++)
					{
						
							//gcval.foreground=0x000000;
							//XChangeGC (d, gc, GCForeground, &gcval);
						
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 2)
						{
							gcval.foreground=0x7f7f7f;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 3)
						{
							gcval.foreground=0x005fff;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 4)
						{
							gcval.foreground=0x305fff;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 5)
						{
							gcval.foreground=0x505fff;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 6)
						{
							gcval.foreground=0x705fff;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 7)
						{
							gcval.foreground=0xa05fff;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 8)
						{
							gcval.foreground=0xc05fff;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}
						if (imgr.pnt[ (ximg + offsetx) * kimg + (yimg + offsety) * imgr.x * kimg] == 9)
						{
							gcval.foreground=0xff0000;
							XChangeGC (d, gc, GCForeground, &gcval);
							XDrawPoint(d, w2, gc, ximg +2,  batth - 2 -yimg);
						}

					}
				}




			}
			


			

		}
		if( e.type == KeyPress ) // При нажатии кнопки - выход
		{
			XClearArea (d, w, 610, 0, 990, 50, True );
			//XDrawString( d, w, DefaultGC( d, s ), 100,16, &e.xkey.keycode, strlen (&e.xkey.keycode) );
			//XClearArea (d, w, 1100, 0, 80, 20, True );
			//XClearArea (d, w2, 0, 0, 80, 20, True );
			//XDrawString( d, w, DefaultGC( d, s ), 70,70, " ", 1 );
			//XDrawString( d, w2, DefaultGC( d, s ), 0,16, XKeysymToString (XKeycodeToKeysym (d, e.xkey.keycode, (e.xkey.state & 0x00000001) )),strlen (XKeysymToString (XKeycodeToKeysym (d, e.xkey.keycode, (e.xkey.state & 0x00000001) )))  );

			XDrawString( d, w, DefaultGC( d, s ), 610,30, XKeysymToString (XKeycodeToKeysym (d, e.xkey.keycode, (e.xkey.state & 0x00000001) )),strlen (XKeysymToString (XKeycodeToKeysym (d, e.xkey.keycode, (e.xkey.state & 0x00000001) )))  );
			numtostr(e.xkey.keycode, msg2);
			//printf ("---%s\n--%i",msg2, strlen(msg2));
			XDrawString( d, w, DefaultGC( d, s ), 610,20, msg2, strlen(msg2) );
			numtostr(e.xkey.state, msg2);
			XDrawString( d, w, DefaultGC( d, s ), 610,10, msg2, strlen(msg2) );	
///			//tmp=XKeycodeToKeysym (d, e.xkey.keycode, 0 );//
			//;
			//puts (tmp);
			if (e.xkey.keycode == 9 ) break;


			if (e.xkey.keycode == 20)
			{
				if ( kimg < mkimg)
				{
					kimg++;
					if ( (imgr.x/kimg) > (battw-4) )
					{
						offsetx_max=(imgr.x / kimg) - (battw-4);
					}
					else
					{
						offsetx_max=0;
					}
					if ( (imgr.y/kimg) > (batth-4) )
					{
						offsety_max=(imgr.y / kimg) - (batth-4);
					}
					else
					{
						offsety_max=0;
					}
					if ( offsetx > offsetx_max)
					{
						offsetx=offsetx_max;
					}
					if ( offsety > offsety_max)
					{
						offsety=offsety_max;
					}
				}
				XClearArea (d, w2, 1, 1, battw-2, batth-2, True );
				imgis=0;
			}
			if (e.xkey.keycode == 21)
			{
				if ( kimg > 1)
				{
					kimg--;
					if ( (imgr.x/kimg) > (battw-4) )
					{
						offsetx_max=(imgr.x / kimg) - (battw-4);
					}
					else
					{
						offsetx_max=0;
					}
					if ( (imgr.y/kimg) > (batth-4) )
					{
						offsety_max=(imgr.y / kimg) - (batth-4);
					}
					else
					{
						offsety_max=0;
					}
					if ( offsetx > offsetx_max)
					{
						offsetx=offsetx_max;
					}
					if ( offsety > offsety_max)
					{
						offsety=offsety_max;
					}
					
				}
				XClearArea (d, w2, 1, 1, battw-2, batth-2, True );
				imgis=0;
			}

			if (e.xkey.keycode == 111)
			{
				if (offsety < offsety_max)
				{
					if ( (offsety+10) <= offsety_max)
					{
						offsety+=10;
					}
					else
					{
						offsety++;
					}
				}
				XClearArea (d, w2, 1, 1, battw-2, batth-2, True );
				imgis=0;
				//printf("%d \t %d\n", offsety_max, offsety);
			}
			if (e.xkey.keycode == 116)
			{
				if (offsety > 0)
				{
					if ( offsety >= 10)
					{
						offsety-=10;
					}
					else
					{
						offsety--;
					}
				}
				XClearArea (d, w2, 1, 1, battw-2, batth-2, True );
				imgis=0;
				//printf("%d \t %d\n", offsety_max, offsety);
			}

			if (e.xkey.keycode == 114)
			{
				if (offsetx < offsetx_max)
				{
					if ( (offsetx+10) <= offsetx_max)
					{
						offsetx+=10;
					}
					else
					{
						offsetx++;
					}
				}
				XClearArea (d, w2, 1, 1, battw-2, batth-2, True );
				imgis=0;
				//printf("%d \t %d\n", offsetx_max, offsetx);
			}
			if (e.xkey.keycode == 113)
			{
				if (offsetx > 0)
				{
					if ( offsetx >= 10)
					{
						offsetx-=10;
					}
					else
					{
						offsetx--;
					}
				}
				XClearArea (d, w2, 1, 1, battw-2, batth-2, True );
				imgis=0;
				//printf("%d \t %d\n", offsetx_max, offsetx);
			}
			if (e.xkey.keycode == 32)
			{
				found_line (&imgr);
				XClearArea (d, w2, 1, 1, battw-2, batth-2, True );
				imgis=0;
				//printf("%d \t %d\n", offsetx_max, offsetx);
			}
			///////////////////////////////////////////////
			//printf ("---%i\n",e.xkey.keycode);
					
 

		}
		/*if( e.type == ButtonPress )
		{
			XClearArea (d, w, 25, 16, 50, 20, True );
			tmp=e.xbutton.button;


			if (tmp==4) tmp2++;
			if (tmp==5) tmp2--;
			if (tmp==2) tmp2=0;
			numtostr (tmp2, &msg2[0]);
			XDrawString( d, w, DefaultGC( d, s ), 25, 30, &msg2[0] ,strlen ( &msg2[0] ));

			///* прикрепить курсор к окну * /
			if (tmp==1) XDefineCursor(d, w, p1_cursor);
			if (tmp==2) XDefineCursor(d, w, p2_cursor);
			if (tmp==3) XDefineCursor(d, w, p3_cursor);
			if (tmp==4) XDefineCursor(d, w, p4_cursor);
			if (tmp==5) XDefineCursor(d, w, p4_cursor);


			tmp=e.xmotion.x;
			//printf ("p--%i\n",tmp);
			//XDrawString( d, w, DefaultGC( d, s ), 0,32, "rtyu",7);
			//XDrawString( d, w, DefaultGC( d, s ), 50,32, numtostr(tmp),7);
			XDrawPoint (d, w, DefaultGC( d, s ), e.xmotion.x,e.xmotion.y);
			//XDrawLine (d, w, DefaultGC( d, s ), xlast, ylast, e.xmotion.x, e.xmotion.y);
			xlast=e.xmotion.x;
			ylast=e.xmotion.y;


		}
		//ButtonPress KeyRelease  ButtonPress MotionNotify

		if( e.type == MotionNotify )
		{
			tmp=e.xmotion.x;
			//printf ("m--%i\n",tmp);
			//XDrawString( d, w, DefaultGC( d, s ), 0,32, "rtyu",7);
			//XDrawString( d, w, DefaultGC( d, s ), 50,32, numtostr(tmp),7);
			XDrawPoint (d, w, DefaultGC( d, s ), e.xmotion.x,e.xmotion.y);
			XDrawLine (d, w, DefaultGC( d, s ), xlast, ylast, e.xmotion.x, e.xmotion.y);

			xlast=e.xmotion.x;
			ylast=e.xmotion.y;
			XClearArea (d, w2, 20, 16, 78, 30, True );
			numtostr (xlast, &msg2[0]);
			XDrawString( d, w2, DefaultGC( d, s ), 25, 30, &msg2[0] ,strlen ( &msg2[0] ));
			numtostr (ylast, &msg2[0]);
			XDrawString( d, w2, DefaultGC( d, s ), 25, 46, &msg2[0] ,strlen ( &msg2[0] ));

		}
		//ButtonPress KeyRelease  ButtonPress MotionNotify
		if( e.type == ButtonRelease )
		{
			///* отключить курсор от окна * /
			if (e.xbutton.button < 4)XUndefineCursor(d, w);

			//tmp=e.xmotion.x;
			//printf ("n=%s\n","ras");
			//msg2="";

			//numtostr (-356, &msg2[0]);
			//printf ("no=%s\n","dva");
			//printf ("nom=%s\n",&msg2[0]);
			//
			//XDrawString( d, w, DefaultGC( d, s ), 50,32, numtostr(tmp),7);
		}
		*/
		if( e.type == ClientMessage )
		{
			if (e.xclient.message_type == wm_protocols &&
					e.xclient.data.l[0] == wm_delete_window)
			{
				//printf ("%s\n","Window done");
				//XDestroyWindow(d, w);
				//XCloseDisplay( d );
				//exit(0);
				break;
			}

		}

		//if (event.xclient.data.l[0] == wmDeleteMessage)
		//running = false;



		////////////////////////////////
		//ret = read(fd, &bufi, 1);
		//bufa=0;
		//while (ret != -1)
		//if (
		//{
		//	bufr[bufa]=bufi;
		//	bufa++;
		//	ret = read(fd, &bufi, 1);

		//}
		//if (bufa > 0)
		//{
		///	XClearArea (d, w, 30, 130, 180, 20, True );
		//	XDrawString( d, w, DefaultGC( d, s ), 30,146, bufr ,32  );
		//}

		////////////////////////////////



	}


	//close (fd);

	//XFreeCursor (d, p_cursor);
	//fclose(file);
	printf ("%s\n","Window done");
	XDestroyWindow(d, w);
	XCloseDisplay( d );                                 // Закрыть соединение с X сервером
	//////////////////////////////////////////////////////////////////////////
	return EXIT_SUCCESS;
}

void  numtostr (int in, char* out)
{

	int i,tmb, input, tmq, tmw;

	if (in < 0)
	{
		out[0]='-';
	}
	else
	{
		out[0]=' ';
	}
	input=abs(in);
	//tmb=in;
	//printf ("in==%i\n",input);

	for (i=1; i<6; i++)
	{

		tmb=0;

		tmq=1;
		tmw=(5-i);
		while ( tmw )
		{
			tmq*=10;
			tmw--;
		}

		//printf ("ion=%i\n",tmq);
		while (input >= tmq)
		{
			input -= tmq;
			tmb++;
			//printf ("innn=%i\t%i\n",input,tmq );
		}

	out[i]=tmb+0x30;//
	}
	//out[5]=0x32+input;
	out[6]=0x00;
	//out[5]=0x30;
	//out[4]=0x30;
	//out[3]=0x30;
	//out[2]=0x30;
	//out[1]=0x30;



}
