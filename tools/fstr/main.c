#include <stdio.h>
#include <string.h>

#define BSIZE 1024


static char ofile[BSIZE+1];

static const char ext[]=".h";
static const char var[]="static const char %s[]=";

int main(int argc,char **argv)
{
  FILE *inf,*outf;
  int ch;

  if(argc!=3)
    {
      fprintf(stderr,"Number of argument must be 3\n");
      return 1;
    }

  if((inf=fopen(argv[1],"rb"))==NULL)
    {
      fprintf(stderr,"Reading file error\n");
      return 1;
    }

    strcpy(ofile,argv[2]);
    strcat(ofile,ext);

  if((outf=fopen(ofile,"wb"))==NULL)
    {
      fprintf(stderr,"Writing file error\n");
      fclose(inf);
      return 1;
    }

  fprintf(outf,var,argv[2]);fputc('"',outf);
  while((ch=fgetc(inf))!=EOF)
    {
      if(ch==10){fputc('\\',outf);fputc('n',outf);}
      else{fputc(ch,outf);}
    }
  fputc('"',outf);fputc(';',outf);

  fclose(inf);fclose(outf);
  return 0;
}
