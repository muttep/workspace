#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <sys/stat.h>

int main(int agc,char *argv[])  //usage $sudo ./a.out <imagefilename>
{
	int FramebuffFD,fd,ret_ioctl,fb_size,length,ret_stat;
	struct fb_fix_screeninfo f_info;
	struct fb_var_screeninfo v_info;
	unsigned char *bmp_ptr;
	unsigned int *fbptr;
    struct stat s;
	long long int image_size;
	char bmp_head[54];
	FramebuffFD=open("/dev/fb0",O_RDWR);
	if(FramebuffFD<0)
	{
		perror("open fb fail:");
		exit(1);
	}
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("open file fail");
		exit(1);
	}
	ret_ioctl=ioctl(FramebuffFD,FBIOGET_FSCREENINFO,&f_info);
	if(ret_ioctl<0)
	{
		printf("get fix_screeninfo fail\n");
		exit(1);
		close(FramebuffFD);
	}
	ret_ioctl=ioctl(FramebuffFD,FBIOGET_VSCREENINFO,&v_info);
	if(ret_ioctl<0)
	{
		printf("get fix_screeninfo fail\n");
		exit(1);
		close(FramebuffFD);
	}
	/* Print some screen info currently available */
	printf("Screen resolution: (%dx%d)\n", v_info.xres,v_info.yres);
	printf("Line width in bytes %d\n", f_info.line_length);
	printf("bits per pixel : %d\n", v_info.bits_per_pixel);
	printf("Red: length %d bits, offset %d\n",
	v_info.red.length,v_info.red.offset);
	printf("Green: length %d bits, offset %d\n",
	v_info.red.length, v_info.green.offset);
	printf("Blue: length %d bits, offset %d\n",
	v_info.red.length,v_info.blue.offset);
	fb_size=v_info.xres * v_info.yres *( v_info.bits_per_pixel/8); //actual size in bits
	//fb_size/=8;//size in bytes
	printf("fb size %lld\n",(long long)fb_size);
	length=f_info.line_length*v_info.yres;
	printf("map length for FB %lld",(long long)length);
	//mapping the frame buffer
	fbptr=(unsigned int *)mmap(0,length,PROT_READ | PROT_WRITE,MAP_SHARED,FramebuffFD,0);
	if(fbptr==MAP_FAILED)
	{
		printf("Map failed\n");
		close(FramebuffFD);
		return -1;
	}
	printf("fb ptr address %p\n",fbptr);
	ret_stat=stat(argv[1],&s);
	if(ret_stat<0)
	{
		perror("stat failure:\n");
		return -1;
	}
	image_size=s.st_size;
	printf("image size(from stat)is %lld\n",image_size);//printing image size
	//Reading image header
	int ret=read(fd,bmp_head,54);
	if(ret<0)
	{
		perror("read fail\n");
		exit(1);
	}
	int i;
	printf("=================>BMP image information<============\n");
	printf("file type:");
	for(i=0;i<2;i++)
	printf("%c",bmp_head[i]);
	printf("\n");
	char *temp=bmp_head+2;
	long long int bmp_size=*((long long int *)temp);
	printf("size of the file %lld\n",bmp_size);
	temp=bmp_head+18;
	unsigned int im_xres=*((unsigned int *)temp);
	printf("x resof image %i\n",im_xres);
	temp=bmp_head+22;
	int im_yres=*((signed int *)temp);
	printf("y resof image %i\n",im_yres);
	temp=bmp_head+28;
	unsigned short int im_bpp=*((unsigned short int *)temp);
	printf("BPP of image %hi\n",im_bpp);
	temp=bmp_head+10;
	unsigned int bmp_pixeloffset=*((unsigned int *)temp);
	printf("Pixel Data offset %i\n",bmp_pixeloffset);
	//map image
	bmp_ptr =(unsigned char *)mmap(0,bmp_size, PROT_READ, MAP_SHARED, fd, 0);
	if(bmp_ptr==MAP_FAILED)
	{
		perror("bmp file map failed:");
		return -1;
	}
	printf("map address of %p\n",bmp_ptr);
	//setting image position
	unsigned char * bmp=bmp_ptr+54;
	//comparing frame buffer resolution
	//if(bmp_size>(fb_size))
	if(im_bpp>v_info.bits_per_pixel)
	{
		printf("image file is more than frame buffer size\n");
		exit(1);
	}
	int linelength=f_info.line_length/4,j;
	unsigned char r,g,b,a; 
	for (i =im_yres-1;i>=0;i--)
	{
		for (j=0;j<im_xres;j++)
		{
			r = bmp[0];
			g = bmp[1];
			b = bmp[2];
			a = bmp[3];
			bmp+= 4;
			fbptr[i*linelength+j] = (r | (g << 8) | (b << 16) | (a << 24));
		}
	}
	munmap(fbptr,fb_size);
	munmap(bmp_ptr,bmp_size);
	close(FramebuffFD);
	close(fd);
}