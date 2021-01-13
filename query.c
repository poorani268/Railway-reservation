#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void query()
{
FILE *f,*exp,*det;
long int file_pos;
int id=0,count=0,date=0,rating=0,m=0,i=0,flag=0,k=0,j=0,x=0,a=0;
char
filename[100]={},train[20]={},line[15][200]={},temp_str[200]={},temp_rating[20]={},temp_co
unt[20]={},t_id[20]={},tt_id[20]={},q[30]={},str[30]={};
char t_date[20]={},t_month[20]={},t_year[20]={},temp_id[20]={};
float temp_r,temp;
printf("\033[1;36mEnter the date of travel(dd/mm/yyyy)\n\033[0m");
printf("\033[1;32m");
scanf("%s",str);
printf("\033[0m");
i=0;count=0;
while(str[i]!='\n' && i<11)
 {
 if(str[i]=='/')
 {
 if(count==0)
 t_date[m]='\0';
 else if(count==1)
 t_month[m]='\0';
 else if(count==2)
 t_year[m]='\0';
 m=0;
 count+=1;
 }
 else
 {
 if(count==0)
 t_date[m]=str[i];
 else if(count==1)
 t_month[m]=str[i];
 else if(count==2)
 t_year[m]=str[i];
 m+=1;
 }
 i+=1;
 }
 t_year[m]='\0';
 i=0;count=0;
sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/customer queries each day
/query%s.txt",t_year,t_month,t_date);
f=fopen(filename,"a");
sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/customer details each
day/detail%s.txt",t_year,t_month,t_date);
det=fopen(filename,"r");
printf("\033[1;36mEnter the passenger id\n\033[0m");
printf("\033[1;32m");
scanf("%s",temp_id);
printf("\033[0m");
printf("\033[1;36mEnter the train name\n\033[0m");
printf("\033[1;32m");
scanf("%s",train);
printf("\033[0m");
sprintf(filename,"/home/rajee/Desktop/bootathon/expressdetails/%s.txt",train);
exp=fopen(filename,"r+");
printf("\033[1;36mEnter the rating out of 5\n\033[0m");
printf("\033[1;32m");
scanf("%d",&rating);
printf("\033[0m");
printf("\033[1;36mEnter your query on your travel\n\033[0m");
printf("\033[1;32m");
scanf("\n%[^\n]s",q);
printf("\033[0m");
flag=0;i=0;fseek(det,0,SEEK_SET);
while(fgets(line[i],sizeof(line[i]),det))
{
line[i][strlen(line[i])-1] = '\0';
if(line[i][strlen(line[i])-1]=='$')
{
strcpy(temp_str,line[i]);
 j=(int)((strlen(temp_str))-2);
 k=0;m=0;
 while(temp_str[j]!='$')
 {
 if(temp_str[j]==',')
 {
 if(k==1)
 t_id[m]='\0';
 k+=1;
 m=0;
 }
 else
 {
 if(k==1)
 t_id[m]=temp_str[j];
 m+=1;
 }
 j-=1;
 }
 a=strlen(t_id)-1;
 for(x=0;x<strlen(t_id) && a>=0;x++)
 {
 tt_id[x]=t_id[a];
 a-=1;
 }
 if(!strcmp(tt_id,temp_id))
 {
 flag=1;
 break;
 }
 }
 i++;
}
if(flag==0)
{
printf("\033[1;36mPlease enter a valid passenger id\n\033[0m");
printf("\033[1;36mYour query is not updated\n\033[0m");
return;
}
else
{
sprintf(temp_str,"%s,%s,%d,%s,%s$\n",t_date,temp_id,rating,train,q);
fputs(temp_str,f);
i=0;file_pos=ftell(exp);
while(fgets(line[i], sizeof(line[i]), exp))
{
 if(i==5)
 {
 line[i][strlen(line[i]) - 1] = '\0';
 strcpy(temp_str,line[i]);m=0;
 while(temp_str[m]!='$')
 {
 temp_count[m]=temp_str[m];
 m+=1;
 }
 sscanf(temp_count,"%d",&count);
 count+=1;
 fseek(exp,file_pos,SEEK_SET);
 sprintf(temp_count,"%d$",count);
 fputs(temp_count,exp);
 break;
 }
 i++;
 file_pos=ftell(exp);
 }
i=0;fseek(exp,0,SEEK_SET);
while(fgets(line[i], sizeof(line[i]), exp))
{
 if(i==0)
 {
 line[i][strlen(line[i]) - 1] = '\0';
 strcpy(temp_str,line[i]);m=0;
 while(temp_str[m]!='$')
 {
 temp_rating[m]=temp_str[m];
 m+=1;
 }
 }
 i++;
}
sscanf(temp_rating,"%f",&temp_r);
temp=(temp_r+rating)/count;
fseek(exp,0,SEEK_SET);
sprintf(temp_rating,"%.1f$",temp);
fputs(temp_rating,exp);
printf("\033[1;36mSuccessfully updated the query\n\033[0m");
}
fclose(det);
fclose(exp);
fclose(f);
return;
}
