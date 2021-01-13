#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void reservation()
{
FILE *f,*exp,*details,*bank;
long int file_pos;
int
c=0,s=0,temp_seat=0,date=0,i=0,total=0,j=0,k=0,m=0,count=0,sum=0,age=0,option=0,flag=0,t_
option=0,t_price=0,t_bal=0,passenger_id=0;
char
p_train[13][15]={},t_r[5]={},temp_count[4]={},password[5]={},filename[50]={},from[15]={},t
o[15]={},line[50][200]={},temp_str[200]={},express[15]={},temp_from[15]={},temp_to[15]={
},seats[5]={},depart_time[6]={},arrival_time[6]={};
char
train[15]={},name[15]={},gender[3]={},temp_option[2]={},temp_price[5]={},choice[3]={},acc
ount_number[8]={};
Char
temp_account[9]={},temp_pswd[5]={},temp_bal[7]={},p_id[50]={},temp_totalseat[5]={},str[1
5]={},t_date[5]={},t_month[5]={},t_year[6]={};
float r=0;
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
count=0;
sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/train details each
day/day%s.txt",t_year,t_month,t_date);
f=fopen(filename,"r");
printf("\033[1;36mEnter the starting location\n\033[0m");
printf("\033[1;32m");
scanf("%s",from);
printf("\033[0m");
printf("\033[1;36mEnter the destination\n\033[0m");
printf("\033[1;32m");
scanf("%s",to);
printf("\033[0m");
i=0;rewind(f);
while(fgets(line[i], sizeof(line[i]), f))
{
line[i][strlen(line[i]) - 1] = '\0';
i++;
}
total=i;j=0;k=0;m=0;count=0;
for(i=0;i<total;i++)
{
m=0;k=0;j=0;
 strcpy(temp_str,line[i]);
 while(temp_str[k]!='$')
 {
 if(temp_str[k]==',')
 {
 if(j==0)
 express[m]='\0';
 else if(j==1)
 temp_from[m]='\0';
 else if(j==2)
 temp_to[m]='\0';
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
 temp_from[m]=temp_str[k];
 else if(j==2)
 temp_to[m]=temp_str[k];
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
 seats[m]='\0';r=0;
 if(!strcmp(temp_from,from) && !strcmp(temp_to,to))
 {
 sprintf(filename,"/home/rajee/Desktop/bootathon/expressdetails/%s.txt",express);
exp=fopen(filename,"r");flag=0;
fgets(line[0],sizeof(line[0]),exp);
while(line[0][flag]!='$')
{
t_r[flag]=line[0][flag];
flag++;
}
t_r[flag]='\0';
sscanf(t_r,"%f",&r);
strcpy(p_train[count],express);
flag=0;
if(r!=0)
 printf("\n\033[1;36mTrain
Name:\033[0m\033[1;32m%s\033[0m\n\033[1;36mDepart
time:\033[0m\033[1;32m%s\033[0m\t\033[1;36mArrival
time:\033[0m\033[1;32m%s\033[0m\n\033[1;36mUser
Rating:\033[0m\033[1;32m%s\033[0m\t\033[1;36mAvailable
seats:\033[0m\033[1;32m%s\033[0m\n",express,depart_time,arrival_time,t_r,seats);
 else
printf("\n\033[1;36mTrain
Name:\033[0m\033[1;32m%s\033[0m\n\033[1;36mDepart
time:\033[0m\033[1;32m%s\033[0m\t\033[1;36mArrival
time:\033[0m\033[1;32m%s\033[0m\n\033[1;36mUser
Rating:\033[0m\033[1;32m%c\033[0m\t\033[1;36mAvailable
seats:\033[0m\033[1;32m%s\033[0m\n",express,depart_time,arrival_time,'-',seats);
 count+=1;
 }
 }
 if(count==0)
 {
 printf("\033[1;36mNo Trains Available\nThank you for your ccoperation!!\n\033[0m");
 return;
 }
 else
 {
 printf("\n\033[1;36mThe Number of trains available are\033[0m
\033[1;32m%d\033[0m\n",count);
printf("\n\033[1;36mEnter the name of your preferred train\n\033[0m");
printf("\033[1;32m");
scanf("%s",train);
printf("\033[0m");
for(i=0;i<count;i++)
{
if(!strcmp(train,p_train[i]))
{
flag=1;
break;
}
}
if(flag==0)
{
printf("\033[1;36mEnter a valid train\n\033[0m");
return;
}
sprintf(filename,"/home/rajee/Desktop/bootathon/expressdetails/%s.txt",train);
exp=fopen(filename,"r");
sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/customer details
each day/detail%s.txt",t_year,t_month,t_date);
details=fopen(filename,"a");
i=0;fseek(f,0,SEEK_SET);
while(fgets(line[i], sizeof(line[i]), f))
{
 line[i][strlen(line[i]) - 1] = '\0';
 i++;
 }
 total=i;j=0;k=0;m=0;count=0;
 for(i=0;i<total;i++)
 {
 m=0;k=0;j=0;
 strcpy(temp_str,line[i]);
 while(temp_str[k]!='$')
 {
 if(temp_str[k]==',')
 {
 if(j==0)
 express[m]='\0';
 else if(j==1)
 temp_from[m]='\0';
 else if(j==2)
 temp_to[m]='\0';
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
 temp_from[m]=temp_str[k];
 else if(j==2)
 temp_to[m]=temp_str[k];
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
 if(!strcmp(express,train))
 {
 sscanf(seats,"%d",&temp_seat);i=0;
 while(fgets(line[i], sizeof(line[i]), exp))
{
 line[i][strlen(line[i]) - 1] = '\0';
 if(i==6)
 {
 strcpy(temp_str,line[i]);m=0;
 while(temp_str[m]!='$')
 {
 temp_totalseat[m]=temp_str[m];
 m+=1;
 }
 temp_totalseat[m]='\0';
 sscanf(temp_totalseat,"%d",&s);
 s=(s-temp_seat)+1;
 break;
 }
 i++;
}
 break;
 }
}
i=0;sum=0;count=0;
do
{
if(temp_seat>0)
{
rewind(exp);
printf("\033[1;36mEnter the name of passenger
%d\n\033[0m",count+1);
printf("\033[1;32m");
scanf("%s",name);
printf("\033[0m");
printf("\033[1;36mEnter the age of passenger
%d\n\033[0m",count+1);
printf("\033[1;32m");
scanf("%d",&age);
printf("\033[0m");
printf("\033[1;36mEnter your gender(M/F) of passenger
%d\n\033[0m",count+1);
printf("\033[1;32m");
scanf("%s",gender);
printf("\033[0m");
printf("\033[1;36m");
fseek(exp,0,SEEK_SET);i=0;
while(fgets(line[i], sizeof(line[i]), exp))
{
 line[i][strlen(line[i]) - 1] = '\0';
 if(i>=1 && i<=4)
 {
 j=0;c=0;
 while(line[i][j]!='$')
 {
 if(line[i][j]==',')
 {
 c++;
 if(c<3)
 printf("%c",line[i][j]);
 else
 printf("%s","-Rs.");
 }
 else
 printf("%c",line[i][j]);
 j++;
 }
 printf("\n");
 }
 i++;
 }
 printf("\033[0m");
 printf("\033[1;36mEnter any of the above options to book the respective
seat for passenger %d\n\033[0m",count+1);
 printf("\033[1;32m");
 scanf("%d",&option);
 printf("\033[0m");
 if(option<1 || option>4)
 {
 printf("\033[1;36mEnter a valid option\n\033[0m");
 printf("\033[1;32m");
 scanf("%d",&option);
 printf("\033[0m");
 }
 total=i;j=0;k=0;
 for(i=0;i<total;i++)
 {
 if(i!=0 && i!=(total-1))
 {
 j=0;m=0;k=0;
 strcpy(temp_str,line[i]);
while(temp_str[k]!='$')
 {
 if(temp_str[k]==',')
 {
 if(j==0)
 temp_option[m]='\0';
 else if(j==3)
 temp_price[m]='\0';

 m=0;
 j+=1;
 }
 else
 {
 if(j==0)
 temp_option[m]=temp_str[k];
 else if(j==3)
 temp_price[m]=temp_str[k];
 m+=1;
 }
 k+=1;
 }
 temp_price[m]='\0';
 sscanf(temp_option,"%d",&t_option);
 if(t_option==option)
 {
 sscanf(temp_price,"%d",&t_price);
 sum+=t_price;
 break;
 }
}
}
printf("\033[1;36m\nyour seat number is\033[0m
\033[1;32m%d\033[0m\n",s);
if(count==0)
sprintf(p_id,"$%s,%d,%s,%d,%d,",name,age,gender,s,t_price);
else
sprintf(p_id,"%s,%d,%s,%d,%d,",name,age,gender,s,t_price);
fputs(p_id,details);
s++;
printf("\033[1;36m\nTo book another ticket Enter yes\n\033[0m");
printf("\033[1;32m");
scanf("%s",choice);
printf("\033[0m");
count+=1;
temp_seat-=1;
}
else
{
printf("\033[1;36mThe train is occupied...No more
seats\033[0m\n");
if(count>0)
{
printf("\033[1;36mDo you want to pay the amount for the
booked tickets\n\033[0m");
printf("\033[1;32m");
scanf("%s",choice);
printf("\033[0m");
if(strcmp(choice,"yes"))
{
printf("\033[1;36mThank you for your
cooperation\n\033[0m");
return;
}
break;
}
else
{
return;
}
}
}while(!strcmp(choice,"yes"));
printf("\033[1;36m\nThe total amount to be paid is\033[0m
\033[1;32m%d\033[0m\n",sum);
printf("\033[1;36m\nDo you like to pay through online\n\033[0m");
printf("\033[1;32m");
scanf("%s",choice);
printf("\033[0m");
i=0;
if(!strcmp(choice,"yes"))
{
bank=fopen("/home/rajee/Desktop/bootathon/bank
accounts/accountdetails.txt","rw");
while(fgets(line[i], sizeof(line[i]), bank))
{
 line[i][strlen(line[i]) - 1] = '\0';
 i++;
 }
 total=i;flag=0;
printf("\033[1;36mEnter your account number\n\033[0m");
printf("\033[1;32m");
scanf("%s",account_number);
printf("\033[0m");
printf("\033[1;36mEnter the password\n\033[0m");
printf("\033[1;32m");
scanf("%s",password);
printf("\033[0m");
for(i=0;i<total;i++)
{
j=0;m=0;k=0;
 strcpy(temp_str,line[i]);
while(temp_str[k]!='$')
 {
 if(temp_str[k]==',')
 {
 if(j==0)
 temp_account[m]='\0';
 else if(j==1)
 temp_pswd[m]='\0';
 j+=1;
 m=0;
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
 temp_bal[m]='\0';
 sscanf(temp_bal,"%d",&t_bal);
 if(!strcmp(temp_account,account_number) &&
!strcmp(temp_pswd,password))
 {
 if(t_bal>sum)
 {
 t_bal-=sum;
 printf("\033[1;36mYour Account Balance after deducting
the amount:\033[0m\033[1;32m%d\033[0m\n",t_bal);
 flag=1;
 }
 else
 {
 printf("\033[1;36mYour account balance is not sufficient to
pay the amount\n");
 printf("Your tickets are under waiting list\n\033[0m");
 sprintf(p_id,"%s,%s#\n","-999",train);
 fputs(p_id,details);
 return;
 }
 break;
 }
}
if(flag==1)
{
srand(time(NULL));
passenger_id=rand();
sprintf(p_id,"%d,%d,%s,%s,%s,%d,%s$\n",sum,count,account_number,from,to,passenge
r_id,train);
fputs(p_id,details);
i=0;
bank=freopen("/home/rajee/Desktop/bootathon/bank
accounts/accountdetails.txt","r+",bank);
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
 m+=1;
 }
 k+=1;
 }
if(!strcmp(account_number,temp_account) &&
!strcmp(password,temp_pswd))
{
sprintf(p_id,"%s,%s,%d$",account_number,password,t_bal);
fseek(bank,file_pos,SEEK_SET);
fputs(p_id,bank);
break;
}
 k++;
 i++;
 file_pos=ftell(bank);
 }
printf("\033[1;36mSuccessfully \033[1;32mRs.%.2f\033[0m had
been deducted from your account\033[0m\n\033[1;36mThe passenger id of yours
:\033[0m\033[1;32m%d\033[0m\n",(float)sum,passenger_id);
sprintf(filename,"/home/rajee/Desktop/bootathon/%s/month%s/train details each
day/day%s.txt",t_year,t_month,t_date);
f=freopen(filename,"r+",f);
file_pos=ftell(f);i=0;
while(fgets(line[i], sizeof(line[i]), f)) 
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
 temp_from[m]='\0';
 else if(j==2)
 temp_to[m]='\0';
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
 temp_from[m]=temp_str[k];
 else if(j==2)
 temp_to[m]=temp_str[k];
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
 sscanf(seats,"%d",&temp_seat);
 temp_seat-=count;
if(!strcmp(train,express) && !strcmp(from,temp_from) &&
!strcmp(to,temp_to))
{
sprintf(p_id,"%s,%s,%s,%s,%s,%d$",express,temp_from,temp_to,depart_time,arrival_ti
me,temp_seat);
fseek(f,file_pos,SEEK_SET);
fputs(p_id,f);
break;
}
i++;file_pos=ftell(f);
}
}
else if(flag==0)
{
fputs("#\n",details);
printf("\033[1;36mInvalid account number/password\033[0m\n");
}
fclose(bank);
}
else
{
sprintf(p_id,"%s,%s#\n","-999",train);
fputs(p_id,details);
printf("\033[1;36mYour tickets are under waiting list\n\033[0m");
}
}
fclose(f);
fclose(exp);
fclose(details);
return;
}
