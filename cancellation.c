#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void cancellation()
{
FILE *f,*day,*bank;
 long int file_pos;
int
t_sum=0,t_bal=0,t_count=0,date=0,i=0,total=0,flag=0,j=0,m=0,a=0,count=0,k=0,temp_seat=0;
char
temp_ex[15]={},filename[70]={},line[20][200]={},id[15]={},train[15]={},temp_str[200]={},te
mp_train[15]={},temp_id[15]={},str[20]={};
char
seats[5]={},p_id[100]={},depart_time[7]={},arrival_time[7]={},express[15]={},temp_sum[6]={
},temp_count[3]={},temp_accountno[10]={},temp_from[15]={},temp_to[15]={},from[15]={},t
o[15]={};
char
temp_account[10]={},temp_pswd[6]={},temp_bal[6]={},t_year[10]={},t_month[10]={},t_date[
10]={};
printf("\033[1;36mEnter the date of travel(dd/mm/yyyy)\n\033[0m");
 printf("\033[1;32m");
scanf("%s",str);
 printf("\033[0m");
 i=0;count=0;m=0;
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
 sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/train details each
day/day%s.txt",t_year,t_month,t_date);
 day=fopen(filename,"r+");
printf("\033[1;36mEnter the passenger id\n\033[0m");
 printf("\033[1;32m");
scanf("%s",id);
 printf("\033[0m");
 printf("\033[1;36mEnter the train\n\033[0m");
 printf("\033[1;32m");
 scanf("%s",train);
 printf("\033[0m");
sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/customer details each
day/detail%s.txt",t_year,t_month,t_date);
f=fopen(filename,"r+");
 fseek(f,0,SEEK_SET);
 i=0;file_pos=ftell(f);
while(fgets(line[i], sizeof(line[i]), f))
{
 if(line[i][strlen(line[i])-1]=='$')
 {
 temp_id[0]='\0';
 temp_ex[0]='\0';
 j=0;
 line[i][strlen(line[i]) - 1] = '\0';
 strcpy(temp_str,line[i]);
 j=(int)(strlen(temp_str))-1;
 count=0;
 while(count<7)
 {
 if(temp_str[j]==',')
 count++;
 j-=1;
 }
 j+=2;
 k=0;m=0;
 while(temp_str[j]!='$')
 {
 if(temp_str[j]==',')
 {
 if(k==0)
 temp_sum[m]='\0';
 else if(k==1)
 temp_count[m]='\0';
 else if(k==2)
 temp_accountno[m]='\0';
 else if(k==3)
 temp_from[m]='\0';
 else if(k==4)
 temp_to[m]='\0';
 else if(k==5)
 temp_id[m]='\0';
 else if(k==6)
 temp_ex[m]='\0';
 k+=1;
 m=0;
 }
 else
 {
 if(k==0)
 temp_sum[m]=temp_str[j];
 else if(k==1)
 temp_count[m]=temp_str[j];
 else if(k==2)
 temp_accountno[m]=temp_str[j];
 else if(k==3)
 temp_from[m]=temp_str[j];
 else if(k==4)
 temp_to[m]=temp_str[j];
 else if(k==5)
 temp_id[m]=temp_str[j];
 else if(k==6)
 temp_ex[m]=temp_str[j];
 m+=1;
 }
 j+=1;
 }
 temp_ex[m]='\0';
 printf("%s %s %s %s\n",temp_id,id,temp_ex,train);
 if(!strcmp(temp_id,id) && !strcmp(temp_ex,train))
 {
 temp_str[strlen(temp_str)-1]='#';
 fseek(f,file_pos,SEEK_SET);
 fputs(temp_str,f);
 printf("\033[1;36mYour tickets are cancelled successfully\n\033[0m");
 flag=1;
 break;
 }
 i++;
 file_pos=ftell(f);
 }
 }
 if(flag==1)
 {
 file_pos=ftell(day);i=0;
 while(fgets(line[i], sizeof(line[i]), day))
 {
 line[i][strlen(line[i]) - 1] = '\0';
 strcpy(temp_str,line[i]);
 j=0,m=0,k=0;
 while(temp_str[k]!='$')
 {
 if(temp_str[k]==',')
 {
 if(j==0)
 express[m]='\0';
 else if(j==1)
 from[m]='\0';
 else if(j==2)
 to[m]='\0';
 else if(j==3)
 depart_time[m]='\0';
 else if(j==4)
 arrival_time[m]='\0';
 m=0;
 j+=1;
 }
 else
 {
 if(j==0)
 express[m]=temp_str[k];
 else if(j==1)
 from[m]=temp_str[k];
 else if(j==2)
 to[m]=temp_str[k];
 else if(j==5)
 seats[m]=temp_str[k];
 else if(j==3)
 depart_time[m]=temp_str[k];
 else if(j==4) 
 arrival_time[m]=temp_str[k];
 m+=1;
 }
 k+=1;
 }
 seats[m]='\0';
 if(!strcmp(temp_ex,express) && !strcmp(from,temp_from) && !strcmp(to,temp_to))
 {
 sscanf(seats,"%d",&temp_seat);
 sscanf(temp_count,"%d",&t_count);

sprintf(p_id,"%s,%s,%s,%s,%s,%d$",express,temp_from,temp_to,depart_time,arrival_time,temp
_seat+t_count);
 fseek(day,file_pos,SEEK_SET);
 fputs(p_id,day);
 break;
 }
 i++;file_pos=ftell(day);
 }
 i=0;
 bank=fopen("/home/rajee/Desktop/bootathon/bank accounts/accountdetails.txt","r+");
 file_pos=ftell(bank);
 while(fgets(line[i], sizeof(line[i]), bank))
 {
 line[i][strlen(line[i]) - 1] = '\0';
 strcpy(temp_str,line[i]);
 j=0,m=0,k=0;
 while(temp_str[k]!='$')
 {
 if(temp_str[k]==',')
 {
 if(j==0)
 temp_account[m]='\0';
 else if(j==1)
 temp_pswd[m]='\0';
 m=0;
 j+=1;
 }
 else
 {
 if(j==0)
 temp_account[m]=temp_str[k];
 else if(j==1)
 temp_pswd[m]=temp_str[k];
 else if(j==2)
 temp_bal[m]=temp_str[k];
 m+=1;
 }
 k+=1;
 }
 if(!strcmp(temp_accountno,temp_account))
 {
 sscanf(temp_sum,"%d",&t_sum);
 sscanf(temp_bal,"%d",&t_bal);
 sprintf(p_id,"%s,%s,%d$",temp_accountno,temp_pswd,t_bal+t_sum);
 fseek(bank,file_pos,SEEK_SET);
 fputs(p_id,bank);
 break;
 }
 i++;file_pos=ftell(bank);
 }
 }
 fclose(bank);
 fclose(day);
 fclose(f);
return;
}
