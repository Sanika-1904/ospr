#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#define S_C "myfifo1"
#define C_S "myfifo2"
int main()
{
char readbuf[80];
char string[80]="";
char temp[20];
int s2c,c2s;
int i=0,w=1,l=1;
FILE *fp;
s2c=open(S_C,O_RDWR);
printf("Reading from myfifo1\n");
read(s2c,readbuf,80);
printf("recieved from server=%s\n",readbuf);
while(readbuf[i] != '\0')
{
if(readbuf[i]==' ' || readbuf[i]=='.' || readbuf[i]==',')
{
w++;
}
if(readbuf[i]=='\n')
{
l++;
w++;
}
i++;
}
fp=fopen("server.txt","w");
fprintf(fp,"No of Characters = %d\n",i);
fprintf(fp,"No of Words= %d\n",w);
fprintf(fp,"No of Lines = %d",l);
strcat(string,"No of character=");
sprintf(temp,"%d",i);
strcat(string,temp);
strcat(string,",");
strcat(string,"No of Words=");
sprintf(temp,"%d",w);
strcat(string,temp);
strcat(string,",");
strcat(string,"No of Lines=");
sprintf(temp,"%d",l);
strcat(string,temp);
strcat(string,",");
c2s=open(C_S,O_RDWR);
printf("Writing to myfifo2\n");
write(c2s,string,sizeof(string));
fclose(fp);
close(s2c);
close(c2s);
return 0;
}

