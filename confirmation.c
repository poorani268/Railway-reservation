#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void confirmation()
{
FILE *f;
int date=0,i=0,j=0,m=0,count=0,total=0,a=0,flag=0,x=0,k=0,temp=0;
 char
filename[100]={},id[20]={},train[20]={},line[15][200]={},temp_str[200]={},temp_train[20]={}
,temp_id[20]={},str[20]={};
 char t_date[10]={},t_month[10]={},t_year[10]={},t_id[20]={},t_train[20]={};
printf("\033[1;36mEnter the date of travel(dd/mm/yyyy)\n\033[0m");
 printf("\033[1;32m");
scanf("%s",str);
 printf("\033[0m");
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
 count++;
 }
 else
 {
 if(count==0)
 t_date[m]=str[i];
 else if(count==1)
 t_month[m]=str[i];
 else if(count==2)
 t_year[m]=str[i];
 m++;
 }
 i++;
 }
 t_year[m]='\0';
 i=0;count=0;
printf("\033[1;36mEnter the passenger id\n\033[0m");
 printf("\033[1;32m");
scanf("%s",id);
 printf("\033[0m");
printf("\033[1;36mEnter the train name\n\033[0m");
 printf("\033[1;32m");
scanf("%s",train);
 printf("\033[0m");
 sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/customer details each
day/detail%s.txt",t_year,t_month,t_date);
f=fopen(filename,"r");
 i=0;
while(fgets(line[i],sizeof(line[i]), f))
{
 line[i][strlen(line[i]) - 1] = '\0';
 i++;
 }
 count=0;total=i;flag=0;
 for(i=0;i<total;i++)
 {
 temp_id[0]='\0';
 strcpy(temp_str,line[i]);
 if(line[i][strlen(line[i])-1]=='$')
 {
 j=strlen(line[i])-2;count=0;m=0;
 while(count<2)
 {
 if(temp_str[j]==',')
 {
 if(count==0)
 temp_train[m]='\0';
 else if(count==1)
 temp_id[m]='\0';
 count+=1;
 m=0;
 }
 else
 {
 if(count==0)
 temp_train[m]=temp_str[j];
 if(count==1)
 temp_id[m]=temp_str[j];
 m+=1;
 }
 j-=1;
 }
 a=strlen(temp_train)-1;
 for(j=0;j<strlen(temp_train) && a>=0;j++)
 {
 t_train[j]=temp_train[a];
 a-=1;
 }
 a=strlen(temp_id)-1;
 for(j=0;j<strlen(temp_id) && a>=0;j++)
 {
 t_id[j]=temp_id[a];
 a-=1;
 }
 t_id[strlen(temp_id)]='\0';
 if(!strcmp(t_id,id) && !strcmp(t_train,train))
 {
 temp=1;
 for(x=0;x<48;x++)
 {
 printf(" ");
 }
 printf("\033[1;36mYours tickets are confirmed!!\033[0m\n");
 for(x=0;x<53;x++)
 {
 printf(" ");
 }
 printf("\033[1;36mPASSENGER DETAILS\033[0m\n");
 for(x=0;x<30;x++)
 {
 printf(" ");
 }
 printf("\033[1;36m%-6s%-15s%-6s%-10s%-
15s%s\033[0m","S.No","Name","Age","Gender","Seat No","Ticket Price");
 j=1;
 while(temp_str[j]!='$')
 {
 if(temp_str[j]==',')
 k+=1;
 j++;
 }
 k=k-6;j=1;count=0;
 while(temp_str[j]!='$' && count<k)
 {
 if(temp_str[j]==',')
 {
 count+=1;
 j+=1;
 }
 else
 {
 if(count%5==0)
 {
 printf("\n");
 for(x=0;x<30;x++)
 printf(" ");
 printf("\033[1;32m%d\033[0m",(count/4)+1);
 for(x=0;x<5;x++)
 printf(" ");
 printf("\033[1;32m");
 m=0;
 while(temp_str[j]!=',')
 {
 printf("%c",temp_str[j]);
 j+=1;m+=1;
 }
 printf("\033[0m");
 for(x=0;x<15-m;x++)
 printf(" ");
 }
 else if(count%5==1)
 {
 printf("\033[1;32m");
 m=0;
 while(temp_str[j]!=',')
 {
 printf("%c",temp_str[j]);
 j+=1;m+=1;
 }
 printf("\033[0m");
 for(x=0;x<6-m;x++)
 printf(" ");
 }
 else if(count%5==2)
 {
 printf("\033[1;32m");
 m=0;
 while(temp_str[j]!=',')
 {
 printf("%c",temp_str[j]);
 j+=1;m+=1;
 }
 printf("\033[0m");
 for(x=0;x<10-m;x++)
 printf(" ");
 }
 else if(count%5==3)
 {
 printf("\033[1;32m");
 m=0;
 while(temp_str[j]!=',')
 {
 printf("%c",temp_str[j]);
 j+=1;m+=1;
 }
 printf("\033[0m");
 for(x=0;x<15-m;x++)
 printf(" ");
 }
 else if(count%5==4)
 {
 printf("\033[1;32m");
 m=0;
 while(temp_str[j]!=',')
 {
 printf("%c",temp_str[j]);
 j+=1;m+=1;
 }
 printf("\033[0m");
 }
 }
 }
 printf("\n");
 for(x=0;x<81;x++)
 printf(" ");
 printf("-----\n");
 for(x=0;x<67;x++)
 printf(" ");
 printf("\033[1;36mTotal amount \033[0m");
 printf("\033[1;32m");
 while(temp_str[j]!=',' && temp_str[j]!='$')
 {
 printf("%c",temp_str[j]);
 j++;
 }
 printf("\033[0m");
 printf("\n");
 for(x=0;x<81;x++)
 printf(" ");
 printf("-----\n");
 }
 }
 }
 if(temp!=1)
 printf("\033[1;36mYour tickets are not yet confirmed\n\033[0m");
 fclose(f);
return;
}
