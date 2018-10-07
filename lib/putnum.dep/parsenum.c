char * parsenum(char *buff,unsigned int num,unsigned int base,const char *numlist)
{
  unsigned int i,j,k,l;
  char buff2[40];
  buff2[39]=0;
  i=38;
  k=num;
  
  do
  {
    l=k%base;
    k=k/base;
    buff2[i--]=numlist[l];
  }while(k);
  
  i++;
  j=0;
  
 do
 {
   buff[j++]=buff2[i++];
 }while(buff[j-1]);
 
 
  return(buff);
}
