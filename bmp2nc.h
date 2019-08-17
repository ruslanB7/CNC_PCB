/************************



**************************/


typedef struct
{
	long unsigned int x;
	long unsigned int y;
	unsigned char pnt[7000000];
} imgdmp;

//int open_img ( char *imgfl, imgdmp *img);

int open_img ( char *imgfl, imgdmp *img);
int invert ( imgdmp *img );
int found_line (imgdmp *img);
int mk_bs_nc ( imgdmp *img );
