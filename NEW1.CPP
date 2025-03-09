#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include"struct.h"
#include"search.h"

void main()
{    void add_contact();
	 void list_contact();
	 void edit_contact();
	 void delete_contact();
	 void search_contact();
	 void change_password();

	int gdriver=DETECT,gmode,errorcode;
	initgraph(&gdriver, &gmode,"c://turboc3//bgi");
	errorcode = graphresult();
	if(errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}
	int x=getmaxx();int y=getmaxy();
	setbkcolor(WHITE);
	setcolor(12);
	for(int j=10;j<=200;j=j+10)
	{rectangle(1+j,1+j,x-j,y-j);
	 delay(200);
	}
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	setcolor(RED);
	outtextxy(210,225,"WELCOME");
	delay(1000);
	cleardevice();
	closegraph();

	char pass[30],original[30],ch;
	FILE *fp;
	int i;
	window(1,1,80,25);
	textbackground(3);
	clrscr();
	window(20,10,60,15);
	textbackground(2);
	clrscr();
	gotoxy(4,3);
	textcolor(RED);
	cprintf("Enter your password :");
	i=0;
while(1)
 {
  ch=getch();
  if(ch==13)
	{ pass[i]='\0';
	  break;
	}
 textcolor(BLACK);
 pass[i++]=ch;
 cprintf("*");
 }
 fp=fopen("password.dat","r");
 fgets(original,30,fp);
 fclose(fp);
 if(strcmp(original,pass)!=0)
  { gotoxy(4,5);
	textcolor(WHITE+BLINK);
	cprintf("Incorrect password, Press Any Key...");
	getch();
	exit(0);
	}
 else
  { window(1,1,80,25);
	textbackground(14);
	clrscr();
	gotoxy(32,3);
	textcolor(BLACK);
	cprintf("CONTACT MANAGER");
	gotoxy(31,5);
	textcolor(BLUE);
	cprintf("Version no. : 1.0");
	gotoxy(22,8);
	textcolor(YELLOW);
	cprintf("Developed by : PRAVEEN TRIPATHI");
	textcolor(RED);
	gotoxy(5,15);
	cprintf("Please wait ");
	for(i=1;i<=50;i++)
	{
	cprintf("%c",220);
	delay(50);
	}
	while(1){
	textbackground(YELLOW);
	clrscr();
	window(18,5,60,22);
	textbackground(BLACK);
	clrscr();
	textcolor(11);
	gotoxy(18,2);
	cprintf("MAIN MENU");
	gotoxy(16,3);
	cprintf("--------------");
	textcolor(WHITE);
	gotoxy(12,5);
	cprintf("1. Add New Contact");
	gotoxy(12,6);
	cprintf("2. Delete Contact");
	gotoxy(12,7);
	cprintf("3. Edit Contact");
	gotoxy(12,8);
	cprintf("4. Search Contact");
	gotoxy(12,9);
	cprintf("5. List of All Contact");
	gotoxy(12,10);
	cprintf("6. Change Password");
	gotoxy(12,11);
	cprintf("7. Exit");
	gotoxy(10,13);
	textcolor(11);
	cprintf("---------------------------");
	gotoxy(12,16);
	textcolor(YELLOW+BLINK);
	cprintf("Enter Your choice ?");
   char choice;
   choice=getche();
   switch(choice)
   {
   case '1':
			add_contact();
			break;
   case '2':
			delete_contact();
			break;
   case '3':
			edit_contact();
			break;
   case '4':
			search_contact();
			break;
   case '5':
			list_contact();
			break;
   case '6':
			change_password();
			break;
   case '7':
			exit(0);
   }
  }
 }
 getch();
}
int getsno()
{
	FILE *fp;
	int n,size;
	fp=fopen("info.dat","rb");
	size=sizeof(cont);
	fseek(fp,-size,SEEK_END);
	fread(&cont,sizeof(cont),1,fp);
	n=cont.sno;
	fclose(fp);
	n++;
	return(n);
}
void add_contact()
{   FILE *fp;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(2);
	clrscr();
	printf("Add New Contact\n");
	printf("--------------------------------------------------");
	fflush(stdin);
	textcolor(WHITE);
	printf("\nEnter Serial number :");
	scanf("%d",&cont.sno);
	fflush(stdin);
	printf("Enter Name : ");
	gets(cont.name);
	fflush(stdin);
	printf("Enter category (Friend/Family/Customer/Student) :");
	gets(cont.category);
	fflush(stdin);
	printf("Enter Gender M/F :");
	scanf("%c",&cont.gender);
	fflush(stdin);
	printf("Enter age :");
	scanf("%d",&cont.age);
	fflush(stdin);
	printf("Enter address :");
	gets(cont.address);
	fflush(stdin);
	printf("Enter Phone Number :");
	gets(cont.phone);
	fflush(stdin);
	fp=fopen("info.dat","ab");
	fwrite(&cont,sizeof(cont),1,fp);
	fclose(fp);
	textcolor(WHITE+BLINK);
	cprintf("\nSuccessfully saved, Press any key...");
}
void delete_contact()
{
	int n;char choice,found;
	FILE *fp1,*fp2;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(YELLOW);
	clrscr();
	printf("DELETE CONTACT");
	printf("\n------------------------------------------------");
	printf("\nEnter Serial Number to be Deleted :");
	scanf("%d",&n);
	printf("\n------------------------------------------------");
	fp1=fopen("info.dat","rb");
	while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
	{
		if(cont.sno==n)
		{   textcolor(WHITE);
			printf("\n");
			 cprintf("Category  : %s",cont.category);
			 printf("\n");
			 cprintf("Name      : %s",cont.name);
			 printf("\n");
			 cprintf("Gender    : %c",cont.gender);
			 printf("\n");
			 cprintf("Age       : %d",cont.age);
			 printf("\n");
			 cprintf("Address   : %s",cont.address);
			 printf("\n");
			 cprintf("Phone     : %s",cont.phone);
			textcolor(YELLOW);
			printf("\n");
			cprintf("------------------------------------------------");
			found=1;
			break;
		}
	}
  if(found==0)
  {
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("Data Not Found,Press Any Key.....");
		fclose(fp1);
		return;
  }
  printf("\nDelete it y/n? :");
  choice=getche();
  if(choice=='y'||choice=='Y')
  {
  rewind(fp1);
  fp2=fopen("temp.dat","wb");
  while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
  {
   if(cont.sno!=n)
	fwrite(&cont,sizeof(cont),1,fp2);
  }
  fclose(fp1);
  fclose(fp2);
  remove("info.dat");
  rename("temp.dat","info.dat");
  textcolor(GREEN+BLINK);
  printf("\n------------------------------------------------");
  printf("\n");
  cprintf("\nSuccessfully deleted ,Press Any Key.....");
  }
  getch();
}

void edit_contact()
{
	FILE *fp;
	int n,pos,found;
	window(1,1,80,25);
	textcolor(YELLOW);
	textbackground(BLACK);
	clrscr();
	printf("EDIT CONTACT\n");
	printf("-------------------------------------------------------\n");
	printf("Enter Serial Number to be Edited :");
	scanf("%d",&n);
	fp=fopen("info.dat","r+b");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
		if(cont.sno==n)
		{   found=1;
		  textcolor(WHITE);
		  printf("\n");
			cprintf("Category  : %s",cont.category);
			printf("\n");
			cprintf("Name      : %s",cont.name);
			printf("\n");
			cprintf("Gender    : %c",cont.gender);
			printf("\n");
			cprintf("Age       : %d",cont.age);
			printf("\n");
			cprintf("Address   : %s",cont.address);
			printf("\n");
			cprintf("Phone     : %s",cont.phone);
			textcolor(YELLOW);
			printf("\n");
			cprintf("--------------------------------------");

			break;
		}
	}
	if(found==0)
	{
		printf("\n");
		textcolor(RED+BLINK);
		cprintf("Data Not Found,Press Any Key....");
		fclose(fp);
		getch();
		return;
	}
	textcolor(WHITE);
	printf("\n");
	cprintf("Enter New Data");
	printf("\n\n");
	pos=ftell(fp);
	fseek(fp,pos-sizeof(cont),SEEK_SET);

	fflush(stdin);
	printf("Enter Name : ");
	gets(cont.name);
	fflush(stdin);
	printf("Enter category (Friend/Family/Customer/Student) :");
	gets(cont.category);
	fflush(stdin);
	printf("Enter Gender M/F :");
	scanf("%c",&cont.gender);
	fflush(stdin);
	printf("Enter age :");
	scanf("%d",&cont.age);
	fflush(stdin);
	printf("Enter address :");
	gets(cont.address);
	fflush(stdin);
	printf("Enter Phone Number :");
	gets(cont.phone);
	fflush(stdin);
	fwrite(&cont,sizeof(cont),1,fp);
	fclose(fp);
	printf("\n");
	textcolor(RED+BLINK);
	cprintf("Successfully Updated,Press Any Key....");
	textcolor(YELLOW);
	printf("\n");
	cprintf("-------------------------------------------------------");
	getch();
}
void search_contact()
{	char ch;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(11);
	clrscr();
	printf("PLEASE CHOOSE ANY ONE OPTION\n");
	printf("--------------------------------------------");
	printf("\n1. Search by Serial Number ");
	printf("\n2. Search by Category ");
	printf("\n3. Search by Name ");
	printf("\n4. Search by phone number");
	printf("\n5. Back to Main Menu\n");
	printf("--------------------------------------------\n");
	textcolor(YELLOW);
	cprintf("\nEnter your Choice ?");
	ch=getche();
	switch(ch)
	{
	 case '1':
			search_sno();
			break;
	 case '2':
			search_category();
			break;
	 case '3':
			search_name();
			break;
	 case '4':
			search_phone();
			break;
	 case '5':
			return;
	}

}
void list_contact()
{	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(RED);
	clrscr();
	gotoxy(34,1);
	cprintf("LIST OF CONTACTS");
	printf("\n");
	textcolor(YELLOW);
	for(int i=1;i<=80;i++)
	cprintf("-");
	textcolor(BLUE);
	gotoxy(1,3);
	cprintf("SNO");
	gotoxy(8,3);
	cprintf("CATEGORY");
	gotoxy(20,3);
	cprintf("NAME");
	gotoxy(36,3);
	cprintf("GENDER");
	gotoxy(46,3);
	cprintf("AGE");
	gotoxy(55,3);
	cprintf("ADDRESS");
	gotoxy(70,3);
	cprintf("PHONE");

	printf("\n");
	textcolor(YELLOW);
	for(i=1;i<=80;i++)
	cprintf("-");
	fp=fopen("info.dat","rb");
	i=5;
	textcolor(GREEN);
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
	gotoxy(1,i);
	cprintf("%d",cont.sno);
	gotoxy(8,i);
	cprintf("%s",cont.category);
	gotoxy(20,i);
	cprintf("%s",cont.name);
	gotoxy(36,i);
	cprintf("%c",cont.gender);
	gotoxy(46,i);
	cprintf("%d",cont.age);
	gotoxy(55,i);
	cprintf("%s",cont.address);
	gotoxy(70,i);
	cprintf("%s",cont.phone);
	i++;
	}
	fclose(fp);
	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Press Any Key...");
	getch();
	}
	void change_password()
	{
	FILE *fp;
	char current [30],original[30],newpass[30],confirm[30];
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();
	cprintf("Change Password");
	printf("\n");
	textcolor(YELLOW);
	cprintf("--------------------------------------------------");
	printf("\n");
	textcolor(BLACK);
	cprintf("Enter The Current Password :");
	gets(current);
	fp=fopen("password.dat","r");
	fgets(original,30,fp);
	fclose(fp);
	if(strcmp(current,original)!=0)
	{
	textcolor(RED);
	printf("\n");
	cprintf("Incorrect Passsword,Press Any Key.....");
	getch();
	return;
	}
	printf("\n");
	textcolor(GREEN);
	cprintf("Enter New Password :");
	gets(newpass);
	cprintf("Re-enter Password :");
	gets(confirm);
	if(strcmp(confirm,newpass)!=0)
	{
	textcolor(RED);
	printf("\n");
	cprintf("Not matched,Press Any Key.....");
	getch();
	return;
	}
	fp=fopen("password.dat","w");
	fprintf(fp,"%s",newpass);
	fclose(fp);
	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Successfully Updated,Press Any Key");
	printf("\n");
	textcolor(YELLOW);
	cprintf("--------------------------------------------------");
	getch();
	}