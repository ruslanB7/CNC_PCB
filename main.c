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
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include<math.h>

const double PI25DT = 3.141592653589793238462643;

#include <stdio.h>
#include <stdlib.h>


#include <string.h>
#include <errno.h>
#include <X11/Xlib.h>

#include <X11/cursorfont.h> /* определяет XC_watch и т.п. */
/* эта переменная содержит дескриптор создаваемого курсора */


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


	int fd; ////file
	FILE *file;
	/////////////////////file = fopen("./tabsin.tab", "wb");
	//fd = open("test.txt","rw+");/////file
	//fd=open("tabsin.tab", O_APPEND );
	int nomt, noms, pnm, notab;
	char numer[2];
	numer[1]=0;
	int    battw, batth;// xlast, ylast,tmp,tmp2,
	Display *d;
	Window w, w2;
	XEvent e;

	//XSetWindowAttributes winatr;
	battw = 915;
	batth = 715;
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
			0, 0, 800, 400, 0,
			BlackPixel( d, s ), WhitePixel( d, s ) );

	w2 = XCreateSimpleWindow( d, w,     // Создать окно в окні
			30, 30, battw, batth, 0,
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
	XStoreName (d,w,"My new window");
//////////////////////////////////////////////////////////////////
	/* создаем курсор "песочные часы" */
	p1_cursor = XCreateFontCursor(d, XC_pencil);//XC_watch
	p2_cursor = XCreateFontCursor(d, XC_hand2);
	p3_cursor = XCreateFontCursor(d, XC_hand1);
	p4_cursor = XCreateFontCursor(d, XC_watch);



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

			//XDrawLine (d, w2, DefaultGC( d, s ), 0, 0, battw-1, 0);
			//XDrawLine (d, w2, DefaultGC( d, s ), 0, batth-1, battw-1, batth-1);
			//XDrawLine (d, w2, DefaultGC( d, s ), battw-1, 0, battw-1, batth-1);
			//XDrawLine (d, w2, DefaultGC( d, s ), 0, 0, 0, batth-1);

			XDrawLine (d, w2, DefaultGC( d, s ), 10, 0, 10, 300);
			XDrawLine (d, w2, DefaultGC( d, s ), 10, 250, 500, 250);
			//XDrawLine (d, w2, DefaultGC( d, s ), 150, 712, 150, 400);
			//XDrawLine (d, w2, DefaultGC( d, s ), 10, 200, 150, 200);
			//XDrawLine (d, w2, DefaultGC( d, s ), 150, 708, 150, 400);
			//XDrawLine (d, w2, DefaultGC( d, s ), 10, 0, 12, 5);
			//XDrawLine (d, w2, DefaultGC( d, s ), 10, 0, 8, 5);



			file = fopen("./tabsin.tab", "wb");
			for (px=0; px<121; px++)
			{
				XDrawPoint (d, w2, DefaultGC( d, s ), px +11, 250 - (sin( ((px) * 2 * PI25DT)/500) * 250) );
				if ( ( px - (int)( (int)(px/5)*5)) == 0)
								{
									numer[0]='\n';
									fwrite(&numer, 1 , 1, file);
								}
				nomt=sin( ((px) * 2 * PI25DT)/480) * 0xffff;
				noms=0;
				notab = 0;
				for (pnm=100000; pnm > 0; pnm=pnm/10)
				{
					while ( nomt >= pnm )
					{
						nomt = nomt - pnm;
						noms++;
					}
					if (notab != 0)
					{
						numer[0]=noms + '0';
					}
					else
					{
						if (noms != 0)
						{
							notab = 1;
							numer[0]=noms + '0';
						}
						else
						{
							numer[0]=' ';
						}
					}
					//write (fd, &numer,1 );
					//printf ("%i\t",noms);
					fwrite(&numer[0], 1, 1, file);
					printf ("%s",&numer[0]);
					noms=0;
				}
				numer[0]=',';
				printf ("%s\n",&numer);
				fwrite(&numer, 1 , 1, file);

				//write (fd, ',',1 );


			}
			fclose(file);

			for (px=120; px<240; px++)
						{
							XDrawPoint (d, w2, DefaultGC( d, s ), px +15, 250 - (sin( ((px) * 2 * PI25DT)/500) * 250) );
							if ( ( px - (int)( (int)(px/5)*5)) == 0)
											{
												numer[0]='\n';
												//fwrite(&numer, 1 , 1, file);
											}
							nomt=sin( ((px) * 2 * PI25DT)/480) * 0xffff;
							noms=0;
							notab = 0;
							for (pnm=100000; pnm > 0; pnm=pnm/10)
							{
								while ( nomt >= pnm )
								{
									nomt = nomt - pnm;
									noms++;
								}
								if (notab != 0)
								{
									numer[0]=noms + '0';
								}
								else
								{
									if (noms != 0)
									{
										notab = 1;
										numer[0]=noms + '0';
									}
									else
									{
										numer[0]=' ';
									}
								}
								//write (fd, &numer,1 );
								//printf ("%i\t",noms);
								//fwrite(&numer[0], 1, 1, file);
								printf ("%s",&numer[0]);
								noms=0;
							}
							numer[0]=',';
							printf ("%s\n",&numer);
							//fwrite(&numer, 1 , 1, file);

							//write (fd, ',',1 );


						}

		}
		if( e.type == KeyPress ) // При нажатии кнопки - выход
		{

			//XDrawString( d, w, DefaultGC( d, s ), 70,70, &e.xkey.keycode, strlen (&e.xkey.keycode) );
			XClearArea (d, w, 0, 0, 80, 20, True );
			//XDrawString( d, w, DefaultGC( d, s ), 70,70, " ", 1 );
			XDrawString( d, w, DefaultGC( d, s ), 0,16, XKeysymToString (XKeycodeToKeysym (d, e.xkey.keycode, (e.xkey.state & 0x00000001) )),strlen (XKeysymToString (XKeycodeToKeysym (d, e.xkey.keycode, (e.xkey.state & 0x00000001) )))  );
///			//tmp=XKeycodeToKeysym (d, e.xkey.keycode, 0 );//
			//;
			//puts (tmp);
			if (e.xkey.keycode == 9 ) break;

			//printf ("---%i\n",e.xkey.keycode);
			//tmp2=numtostr(tmp, &msg2);
			//printf ("---%s\n--%i",msg2, strlen(msg2));
			//XDrawString( d, w, DefaultGC( d, s ), 150,52, msg2, strlen(msg2) );


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
