#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

struct customer
{
  char fname[20];
  char lname[10];
  int age;
  char gender[10];
  char phno[15];
  char occupation[30];
  char salary[20];
  char cardno[20];
  long int pin;
  long unsigned int balance;
}cust[20];

int i=0,j,n1,n2,n3,n0,q;
long int check=0;

char ch[50],exist[50];

void create()
{
   int k;
   printf("\n\n===========Create new account===============");
   printf("\n\nEnter your first name: ");
   scanf("%s",cust[i].fname);
   printf("Enter your last name: ");
   scanf("%s",cust[i].lname);
   printf("Enter your age: ");
   scanf("%d",&cust[i].age);
   printf("Enter you gender\n1.Male\n2.Female\n");
   scanf("%d",&k);
   if(k==1)
        strcpy(cust[i].gender,"Male");
   else
        strcpy(cust[i].gender,"Female");
   printf("Enter your phone number: ");
   scanf("%s",cust[i].phno);
   printf("Enter your occupation: ");
   scanf("%s",cust[i].occupation);
   printf("Enter your salary: ");
   scanf("%s",cust[i].salary);


   cust[i].balance=200;
   clrscr();

   srand(time(NULL));
   n0=rand()%(9999-1000+1)+1000;
   n1=rand()%(9999-1000+1)+1000;
   n2=rand()%(9999-1000+1)+1000;
   n3=rand()%(9999-1000+1)+1000;

   sprintf(cust[i].cardno,"%d",n0);
   sprintf(ch,"%d",n1);
   cust[i].cardno[4]='-';
   strcat(cust[i].cardno,ch);
   sprintf(ch,"%d",n2);
   cust[i].cardno[9]='-';
   strcat(cust[i].cardno,ch);
   sprintf(ch,"%d",n3);
   cust[i].cardno[14]='-';
   strcat(cust[i].cardno,ch);
   cust[i].cardno[19]=NULL;

   printf("\n\nProcessing please wait.");
   delay(1000);


   printf(".");
   delay(1000);
   printf(".");
   delay(1000);

   printf("\n\n============You have successfully created an account in our bank!!  ============");
   printf("\n\n\nYour 16 digit unique card number is:%s",cust[i].cardno);
   printf("\nCreate a 4 digit pin for your account: ");
   do
   {
     if(check!=0)
       printf("\nEnter valid 4 digit pin: ");
     scanf("%d",&cust[i].pin);
     check++;
   }while(!(cust[i].pin>=1000 && cust[i].pin<=9999));
   do
   {
     printf("Re-enter your pin to confirm: ");
     scanf("%d",&check);
   }while(check!=cust[i].pin);
   printf("\nCongratulations on creating ur account!!");
   getch();


   i++;
}

int existing()
{
  int a;
  for(j=0;j<i;j++)
  {
    if(strcmp(exist,cust[j].cardno)==0 && cust[j].pin==q)
      return 1;
  }
  return 0;
}

void withdraw()
{
   long int num;
   printf("Enter the amount you would like to withdraw: ");
   scanf("%d",&num);
   if(num>(cust[j].balance-200))
     printf("Insufficient balance!!");
   else
   {


     cust[i].balance-=num;
     printf("You have successfully withrawn Rs%d from your account!!",num);
   }
   getch();
}

void deposit()
{
  long int dep;
  printf("Enter the amount you want to deposit: ");
  scanf("%d",&dep);
  cust[j].balance+=dep;
  printf("You have successfully deposited Rs%d to your account!!",dep);
  getch();
}

void change()
{
   int a,chk=0,b;
   printf("\nEnter your current pin to continue: ");
   scanf("%d",&a);
   if(a==cust[j].pin)
   {


     printf("\nEnter your new 4 digit pin: ");
     do
     {
       if(chk!=0)
	 printf("\nPlease enter a 4 digit pin only: ");
       scanf("%d",&a);
       chk++;
     }while(!(a>=1000 && a<=9999));
     chk=0;
     printf("Re enter 4 digit pin: ");
     do
     {
       if(chk!=0)
	 printf("\nRe-Enter a 4 digit pin only: ");
       scanf("%d",&b);
       chk++;
       cust[j].pin=b;
     }while(!(b>=1000 && b<=9999));
      printf("You have successfully changed ur pin!!");
   }
   else
     printf("\nInvalid pin");
}


void display()
{
  clrscr();
  printf("\n\n=======================WELCOME %s=======================",cust[j].fname);
  printf("\nName: %s %s",cust[j].fname,cust[j].lname);
  printf("\nAge: %d",cust[j].age);
  printf("\nPhone number: %s",cust[j].phno);
  printf("\nOccupation: %s",cust[j].occupation);
  printf("\nCard number: %s",cust[j].cardno);
  printf("\nCurrent balance: %d",cust[j].balance);
  getch();
}

void main()
{
  int choice1,choice2,choice3,l,flag=2,p;
  char nam[20];
  FILE *fp;
  fp=fopen("customer.txt","r+");
  clrscr();
  while(1)
  {
    fscanf(fp,"%s",nam);
    if(feof(fp))
      break;
    strcpy(cust[i].fname,nam);
    cust[i].cardno[0]=NULL;
    fscanf(fp,"%s ",cust[i].lname);
    fscanf(fp,"%d ",&cust[i].age);
    fscanf(fp,"%s ",cust[i].gender);
    fscanf(fp,"%s ",&cust[i].phno);
    fscanf(fp,"%s ",cust[i].occupation);
    fscanf(fp,"%s ",cust[i].salary);
    fscanf(fp,"%s ",cust[i].cardno);
    fscanf(fp,"%d ",&cust[i].pin);
    fscanf(fp,"%d ",&cust[i].balance);
    i++;
  }
  fclose(fp);
  do
  {
    flag=0;
    clrscr();
    printf("======================Welcome to Ashwin's ATM machine===========================\n\n\n");


    printf("1.New user\n2.Existing user\n3.Exit\n\nEnter your choice: ");
    scanf("%d",&choice1);
    switch(choice1)
    {
      case 1:clrscr();
	     create();
	     j=i-1;
	     flag=1;


      case 2:
	     while(flag!=1)
	     {
		clrscr();
		printf("\n\n=================Welcome, Please enter your credentials=================");
		printf("\n\n\nEnter the card number in xxxx-xxxx-xxxx-xxxx: ");
		scanf("%s",exist);
		printf("Enter your pin number: ");
		scanf("%d",&q);
		p=existing();
		clrscr();
		printf("\nAuthenticating credentials please wait.");


		delay(1000);
		printf(".");
		delay(1000);
		printf(".");
		delay(1000);
		if(p==1)
		{

		  flag=1;
		  break;
		}
		printf("\n\n\n\nPlease enter a valid card number and pin");
		printf("\n1.Try again\n2.Return to main menu\n");
		scanf("%d",&choice2);
		if(choice2==2)
		{
		  flag=2;
		  break;
		}

	     }
	     clrscr();
	     while(flag==1)


	     {
	       printf("\n\n================Welcome================");
	       printf("\nEnter the operation u would like to perform:\n");
	       printf("1.Withdraw money\n2.Deposit money\n3.Check current balance\n4.Change pin\n5.Log out\n");
	       scanf("%d",&choice3);
	       printf("\n\n");
	     switch(choice3)
	     {
	       case 1:withdraw();
		      clrscr();
		      break;
	       case 2:deposit();
		      clrscr();
		      break;
	       case 3:display();
		      clrscr();
		      break;
	       case 4:change();
		      clrscr();
		      break;
	       case 5:flag=2;
		      break;


	       default:printf("Invalid choice\n");
	     }
	     }
	     break;
      case 3:clrscr();
	     fp=fopen("customer.txt","w");
	     for(l=0;l<i;l++)
	     {
		fprintf(fp,"%s ",cust[l].fname);
		fprintf(fp,"%s ",cust[l].lname);
		fprintf(fp,"%d ",cust[l].age);
		fprintf(fp,"%s ",cust[l].gender);
		fprintf(fp,"%s ",cust[l].phno);
		fprintf(fp,"%s ",cust[l].occupation);
		fprintf(fp,"%d ",cust[l].salary);
		fprintf(fp,"%s ",cust[l].cardno);
		fprintf(fp,"%d ",cust[l].pin);
		fprintf(fp,"%d\n",cust[l].balance);
	     }
	     fclose(fp);
	     printf("\nYour data is stored securely!!");
	     printf("\n\nATM machine by Ashwin N");
	     printf("\n\nVersion:1.1.1\n");
	     printf("\nThank you\nDo come again");
	     getch();
	     exit(0);
      default:printf("Invalid choice");
      }
    }while(1);
}
