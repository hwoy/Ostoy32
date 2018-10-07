#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void showhelp(const char *pname);
static char *croppath(char *path);

int main(int argc,char *argv[])
{
	FILE *fin,*fout;
	char *sin,*sout;
	int ch,base;
	long pos;

	if((argc<3)||(argc>4))
	{
		showhelp(croppath(argv[0]));
		return 1;
	}
	
		sin=argv[2];
		sout=argv[1];
		
		if(argc==4)
		{
			base=(!strncmp(argv[3],"0x",2)) ?  16 : 10;
			pos=strtol(argv[3],NULL,base);
		}
		
		else
		{
			pos=0;
		}
		
	
	if(!(fout=fopen(sout,"r+b")))
	{
		perror(sout);
		return 1;
	}
	
	if(!(fin=fopen(sin,"rb")))
	{
		fclose(fout);
		perror(sin);
		return 1;
	}
	
	if(fseek(fout,pos,SEEK_SET)<0)
	{
		perror(sout);
		fclose(fin);
		fclose(fout);
		return 1;
	}
	
	while((ch=fgetc(fin))!=EOF)
	{
		fputc(ch,fout);
	}
	
	fclose(fin);
	fclose(fout);
	
	if(base==10)
	printf("Success copy %s to %s at %d\n",croppath(argv[2]),croppath(argv[1]),pos);
	
	else
	printf("Success copy %s to %s at 0x%x\n",croppath(argv[2]),croppath(argv[1]),pos);
	
	return 0;
	
}


static void showhelp(const char *pname)
{
	fprintf(stderr,"\n%s is a program that can copy infile to outfile as a part of outfile\n",pname);
	fprintf(stderr,"USAGE: %s outfile infile\n",pname);
	fprintf(stderr,"USAGE: %s outfile infile offset\n\n",pname);
}

static char *croppath(char *path)
{
	int i,j;
	for(i=0,j=0;path[i];i++)
	{
		if(path[i]=='\\' || path[i]=='/')
		{
			j=i;
		}
	}
	
	return (j==0)?  path : path+j+1;
}

