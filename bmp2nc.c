/***********************



************************/


#include <stdio.h>

#include "bmp2nc.h"

int img_stat, nc_stat;
int img_x, img_y, img_dpi_x, img_dpi_y;

char num_format; // 0x32 >>> 002.27

int offset_x, offset_y;    /// zero point in image

char img_fl[256], nc_fl[256], tmp_img_fl[256], tmp_nc_fl[256];
char n_nc[256], tmp_n1_nc[256], tmp_n2_nc[256], tmp_n3_nc[256], tmp_n4_nc[256];




int init_system (void)
{
  
  
  
  
  
  
  
  
  
}


int open_img ( char *imgfl, imgdmp *img)
{
  long unsigned int s_x, s_y, offset_bm, sz_px, px, py, tmcol, rdcol, pnf;
  unsigned char bf, bf2[2], bf4[4];
  FILE *fld;
  fld = fopen(imgfl,"rb");
  if ( !fld )
  {
  	return -1;
  }  
  fseek ( fld, 0, SEEK_SET); // SEEK_SET _CUR _END
  fread(bf2, 2, 1, fld);
  if ( (bf2[0] != 0x42) || (bf2[1] != 0x4d) )
  {
  	return -2;
  }

  fseek (fld, 0x12, SEEK_SET);
  fread (bf4, 4, 1, fld);
  s_x=bf4[0] + bf4[1]*256 + bf4[2]*0x010000 + bf4[3]*0x01000000;
  img->x=s_x;

  fseek (fld, 0x16, SEEK_SET);
  fread (bf4, 4, 1, fld);
  s_y=bf4[0] + bf4[1]*0x0100 + bf4[2]*0x010000 + bf4[3]*0x01000000;
  img->y=s_y;

  fseek (fld, 0x1c, SEEK_SET);
  fread (bf2, 2, 1, fld);
  sz_px=bf2[0] + bf2[1]*0x0100;

  fseek (fld, 0x0a, SEEK_SET);
  fread (bf4, 4, 1, fld);
  offset_bm=bf4[0] + bf4[1]*0x0100 + bf4[2]*0x010000 + bf4[3]*0x01000000;
//printf ( "read \t %d \t %d \t %d \n", offset_bm, s_x, s_y);

  fseek(fld, offset_bm, SEEK_SET);
  fread (bf4, 4, 1, fld);
  tmcol=bf4[0] + bf4[1]*0x0100 + bf4[2]*0x010000 + bf4[3]*0x01000000;

  fseek(fld, offset_bm, SEEK_SET);
  for (py=0; py<s_y; py++)
  {
  	for (px=0; px<s_x; px++)
    {
 		fread (bf4, 4, 1, fld);
 		rdcol=bf4[0] + bf4[1]*0x0100 + bf4[2]*0x010000 + bf4[3]*0x01000000;
 		if (rdcol == tmcol)
 		{
 			img->pnt[px + py * s_x]=1;
 		}
 		else
 		{
 			img->pnt[px + py * s_x]=2;
 		}
 		//pnf=  px + py * s_x;//ftell (fld);

 		//printf ( "read \t %d \t %d \t %d \n", pnf, px, py);

    }
  }
  
  fclose (fld);

  return 0;

}


int open_nc (char *ncfl)
{
  
  
  
 
  
  
  
  
  
  
  
  
}

int open_tmp_fl ( void )
{
  
  
  
  
  
  
  
  
}

int mk_bs_nc ( void )
{
  
  
  
  
  
}


int found_line (imgdmp *img)
{
	volatile unsigned int prx, pry, tmprx, tmpry;
	volatile unsigned char setfind;
	for (setfind=2; setfind < 5; setfind++)
	{
		for (pry=1; pry < (img->y -2); pry++)
		{
			for (prx=1; prx < (img->x -2); prx++)
			{
				if (img->pnt[prx+pry*img->x] == 1)
				{
					
					if ( img->pnt[prx-1+(pry * img->x)] == setfind )
					{
						////if ( img->pnt[prx+1+(pry*img->x)] != 1  )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						////}
						///else
						//{
							img->pnt[prx+pry*img->x] = setfind+1;
						//}
					}
					if ( img->pnt[prx+1+pry*img->x] == setfind )
					{
						//if ( img->pnt[prx-1+(pry*img->x)] != 1  )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						//}
						//else

						//{
							img->pnt[prx+pry*img->x] = setfind+1;
						//}
					}
					//else if ( img->pnt[prx-1+((pry-1)*img->x)] == setfind )
					//{
						//if ( img->pnt[prx+1+((pry+1)*img->x)] == setfind )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						//}
						//else
						//{
					//		img->pnt[prx+pry*img->x] = setfind+1;
						//}
					//}
					//else if ( img->pnt[prx+((pry-1)*img->x)] == setfind )
					//{
						//if ( img->pnt[prx+((pry+1)*img->x)] == setfind )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						//}
						//else
						//{
					//		img->pnt[prx+pry*img->x] = setfind+1;
						//}
					//}
					//else if ( img->pnt[prx+1+((pry-1)*img->x)] == setfind )
					//{
						//if ( img->pnt[prx-1+((pry+1)*img->x)] == setfind )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						//}
						//else
						//{
					//		img->pnt[prx+pry*img->x] = setfind+1;
						//}
					//}
					//if ( img->pnt[prx-1+((pry+1)*img->x)] == setfind )
					//{
						//if ( img->pnt[prx+1+((pry-1)*img->x)] == setfind )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						///}
						//else
						//{
					//		img->pnt[prx+pry*img->x] = setfind+1;
						//}
					//}
					if ( img->pnt[prx+((pry+1)*img->x)] == setfind )
					{
						//if ( img->pnt[prx+((pry-1)*img->x)] == setfind )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						//}
						//else
						//{
							img->pnt[prx+pry*img->x] = setfind+1;
						//}
					}
					if ( img->pnt[prx+((pry-1)*img->x)] == setfind )
					{
						//if ( img->pnt[prx-1+((pry-1)*img->x)] == setfind )
						//{
						//	img->pnt[prx+pry*img->x] = 9;
						//}
						//else
						//{
							img->pnt[prx+pry*img->x] = setfind+1;
						//}
					}
				}
			}
		}
	}

		for (pry=1; pry < (img->y -2); pry++)
		{
			for (prx=1; prx < (img->x -2); prx++)
			{
				if (img->pnt[prx+pry*img->x] == 1)
				{
					img->pnt[prx+pry*img->x] = 9;
				}
			}
		}
	
}