#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

static int i=0;
void add(void);
void display_record(void);
void menu(void);

void savings_record(void);
void search_record(void);
void delete_record(void);

struct log
{
char name[30],pass[30];
}e[99];


struct expense
{
float salary,house,personal, save, transport,edu;
float diff;
float totalexp;
int dd, mm, yy;
} ;

int n;
void login(void);
void reg(void);

int main()
{
	system("cls");
	char enter[50];
printf("\n\n\n\n\t\t\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
printf("\n\t\t\t\t.................................................\n");
printf("\t\t\t\t.\t\t\t\t\t\t.\n");
printf("\t\t\t\t.\t\t\t\t\t\t.\n");
printf("\t\t\t\t.\t\t\t\t\t\t.\n");
   printf("\t\t\t\t.\tWELCOME TO EXPENSE MANAGEMENT SYSTEM\t. \n ");  
printf("\t\t\t\t.\t\t\t\t\t\t.\n");
printf("\t\t\t\t.\t\t\t\t\t\t.\n");
printf("\t\t\t\t.\t\t\t\t\t\t.\n");
printf("\t\t\t\t.................................................\n");
printf("\n\t\t\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>\n");

         printf("\n\t\t\t\t\t press any key to continue\n");
   scanf("%c",&enter);
   if (enter==NULL)
   {
   	printf("\n please press a key to continue\n ");
   }
system("cls");
if(getch()==13)

XY:
	              printf("\t\t\t---------------------------------------------------");
 printf("\n\n\t\t\t\t USER LOG-IN AND REGISTERATION\n");
 printf("\t\t\t---------------------------------------------------\n");
printf("\n\n\n\t\t\t1. LOGIN\n\t\t\t2. REGISTER");
printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&n);
switch(n)
  {
    case 1: 
        login();
        break;
    case 2: 
        reg();
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if(getch()==13)
   
        goto XY;
  }
  return 0;
}
void reg()
  {
  	system("cls");
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("loginregister.txt","ab+");

              printf("\t\t\t---------------------------------------------------");
 printf("\n\n\t\t\t\t REGISTER A NEW USER\n");
 printf("\t\t\t---------------------------------------------------\n");
   

    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&e[i],sizeof(e[i]),1,fp);
          if(strcmp(checker,e[i].name)==0)
            {
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
  
            reg();
            }
          else
          {
            strcpy(e[i].name,checker);
            break;
          }
        }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          e[i].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&e[i],sizeof(e[i]),1,fp);
      fclose(fp);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
 
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&n);
        switch(n)
          {
              case 1:
                    login();
                    break;
              case 2:
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        break;
      }
    getch();
  }
  void login()
    {
    	system("cls");
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("loginregister.txt","rb");
   
           printf("\t\t\t---------------------------------------------------");
 printf("\n\n\t\t\t\t\tUSER LOG-IN\n");
 printf("\t\t\t---------------------------------------------------\n");
  
    
      for(i=0;i<1000;i++)
      {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&e[i],sizeof(e[i]),1,fp);
          checku=strcmp(name,e[i].name);
          checkp=strcmp(pass,e[i].pass);
          if(checku==0&&checkp==0)
          {
            
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            menu();
            break;
          }
        else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if(getch()==13)
          
            reg();
          }
        }
        break;
      }
      getch();
    }
    
    
    void menu()
{
	system("cls");
char op;
	 int ch;
float totalexp;
  	fflush(stdin);
       printf("\n \t\t\t<><><><><><><><><><><><><><><><><><><><>\n");
       printf("\t\t\t\tWELCOME TO EXPENSE MANAGER");
       
       printf("\n \t\t\t<><><><><><><><><><><><><><><><><><><><>\n\n\n");
     printf(" \t\t....... DASHBOARD.........\n\n")  ;
    fflush(stdin);
      printf("\t\t1: Add Expenses\n");
      fflush(stdin);
        printf("\t\t2: View Expenses\n");
        fflush(stdin);
printf("\t\t3: Delete Expenses\n");
        fflush(stdin);
        printf("\t\t4: Search Expenses\n");
        fflush(stdin);
                printf("\t\t5: Savings Expenses\n");
        fflush(stdin);
                printf("\t\t6: Exit\n\n");
        fflush(stdin);
        printf("\t\tEnter your choice : ");
        	fflush(stdin);
       
    
 scanf("%d",&ch);
if(ch<=6)
    {
  
        switch(ch)
        {
    case 1:
        add();
        break;

    case 2:
        display_record();
        break;
     
     case 3:
        delete_record();
        break;
            
      case 4:
        search_record();
        break;
      case 5:
        savings_record();
        break;
      case 6:
		printf("\n thankyou for keeping your expense record with us \n ");
		exit(0);
		fflush(stdin);
        default:
                printf("\n\t\tWrong choice Entered");
                menu();
        }
}
else
{
	printf("\n please enter a valid input\n ");
}

	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche();  
	if(op=='y' || op=='Y')
	{
	menu();
	}
	if(op=='n' || op=='N')
    {
	printf("\n thankyou for using expense manager\n");
	exit(0);
    }
    else
    {
    	printf("\n please enter a valid input\n ");
    	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche(); 
	}
getch();

}



void add(){
	
	system("cls");
    FILE *fp,*ft;
    int p;
    int found=0;
    int datee,mon,year;
    	char ch='y';
    	char op='y';
    struct expense e;
    fp = fopen("file1.txt","ab+");
    ft = fopen("save1.txt","ab+");

if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
      exit(1);
    }
    if(ft==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
      exit(1);
    }
    fflush(stdin);
 	
	while(ch=='y')
{
      printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("\t\t\t\t\tADD NEW EXPENSE\n");
  printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
			printf("Enter date (dd/mm/yy) format: ");
    scanf("%d/%d/%d", &datee, &mon, &year);

    printf(" ----------------------------------------------------------------------------------\n");

      if( (datee>0 && datee<=31) && (mon>0 && mon<=12) && (year>=2000 && year<=2022) )
	{
			printf("Enter date (dd/mm/yy) format: ");
    scanf("%d/%d/%d", &e.dd, &e.mm, &e.yy);
	

     printf(" ----------------------------------------------------------------------------------\n");
			printf("enter monthly income: ");
		     scanf("%f",&e.salary);
            fflush(stdin);
		printf("enter amount spent on housing: ");
		     scanf("%f",&e.house);
            fflush(stdin);
			printf("enter amount spent on education: ");
		     scanf("%f",&e.edu);
            fflush(stdin);
			printf("enter amount spent on transportation: ");
		     scanf("%f",&e.transport);
            fflush(stdin);
				printf("enter amount spent on personal: ");
		     scanf("%f",&e.personal);
                       fflush(stdin);
		
printf("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
 e.totalexp= (e.house+e.edu+e.transport+e.personal);

e.save=(e.salary-e.totalexp);
		    printf("\n total expense = %f\n",e.totalexp);
		    printf("\n monthly salary= %f\n",e.salary);
		    if (e.save>0)
		    {
		    		     printf("\n monthly savings= %f\n",e.save);
			}
			else
			{
				e.save=0;
			    printf("\n monthly savings= %f\n",e.save);
			}
		   
		    float diff= (e.totalexp-e.salary);
		 if( e.salary >= e.totalexp)
		 {
		 	 printf("\n good job budget is in control");
		 
		 }
		 else
		 {
		 	printf("\n expense is more than salary by = %f ", diff);
		 }	
fseek(fp,0,SEEK_END);	
    fwrite(&e,sizeof(e),1,fp);
       fwrite(&e,sizeof(e),1,ft);
}

	else
	{
		printf("\n invalid data\n");
	}
printf("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("\n do u want to print another record\n (y/n) \n");
	ch=getche();
		if(ch=='y')
	{
		add();
	}	
	}
system("cls");
	 	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche();  
	if(op=='y' || op=='Y')
	{
	menu();
	}
	if(op=='n' || op=='N')
    {
	printf("\n thankyou for using expense manager\n");
	exit(0);
    }
    else
    {
    	printf("\n please enter a valid input\n ");
   		printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche(); 
   }

  fclose(fp);
getch();
}



void display_record()
{	
char op;
system("cls");
	struct expense e;
    FILE *fp;
    fp=fopen("file1.txt","rb+");
float totalexp;
    fflush(stdin);
  
  	system("cls");
  	if( fp == NULL )
        {
                printf("Cannot open file.\n");
               exit(0);
         }

	
  printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("\t\t\t\t\tYOUR EXPENSES ARE AS FOLLOWS\n");
  printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
      printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");
     	 printf("DATE\t \t HOUSING \tEDUCATION\t TRANSPORT\tPERSONAL\t SAVINGS\t SALARY\t\t TOTALEXPENSE\n");	
 printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");

     fflush(stdin);
    fseek(fp,0,SEEK_SET);
    while(fread(&e,sizeof(e),1,fp)==1)
    {  
         printf ( "\n %02d/%02d/%04d \t %.2f\t  %.2f \t %.2f\t%.2f\t %.2f\t %.2f\t %.2f\n",e.dd,e.mm,e.yy,e.house,e.edu,e.transport,e.personal,e.save,e.salary,e.totalexp);	
        fflush(stdin);
    }
    fclose(fp);
   
	 	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche();  
		if(op=='y' || op=='Y')
	{
	menu();
	}
	if(op=='n' || op=='N')
    {
	printf("\n thankyou for using expense manager\n");
	exit(0);
    }
    else
    {
    	printf("\n please enter a valid input\n ");
    	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche(); 
	}

getch();
}

void savings_record()
{

	system("cls");
	int flag=0;
	struct expense e;
	
	 char op;
	int i=1;
	 FILE *ft;
	ft = fopen("save1.txt","rb+");
    if(ft == NULL){
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
  
      printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("\t\t\t\t\t SAVINGS HISTORY\n");
  printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
 printf(" -----------------------------------------------------------\n");
  printf(" DATE\t\t SAVINGS\n");
   printf(" ----------------------------------------------------------\n");
 fflush(stdin);  
  fseek(ft,0,SEEK_SET);	
 
 while(fread(&e,sizeof(e),1,ft)==1)
  
        {
        	  printf ( " %02d/%02d/%04d\t: %.2f\n",e.dd,e.mm,e.yy,e.save);
        	     fflush(stdin); 
        } 
  
       fclose ( ft);
 
	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche();  
		if(op=='y' || op=='Y')
	{
	menu();
	}
	if(op=='n' || op=='N')
    {
	printf("\n thankyou for using expense manager\n");
	exit(0);
    }
    else
    {
    	printf("\n please enter a valid input\n ");
    	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche(); 
	}
	getch(); 
}

void search_record()
{
	system("cls");	
    FILE *fp;
    fp=fopen("file1.txt","rb+");
    int datee,mon, year;
	int month;
      printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("\t\t\t\t\tSEARCH A EXPENSE RECORD\n");
  printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
	 struct expense e;
	float totalexp;
	char op;
	fflush(stdin);
   	int found = 0;
   		
    fflush(stdin);	
     if(fp==NULL){
    	printf("File can not open");
	}
 fseek(fp,0,SEEK_SET);	
 printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");
	   	printf("Enter date (dd/mm/yy) format: ");
    scanf("%d/%d/%d", &datee, &mon, &year);

      printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");
 while( fread(&e, sizeof(e), 1, fp)== 1)
 { 
 found=1;
     if((datee,mon,year) == (e.dd,e.mm,e.yy))
     {
     	

     	 printf("\n RECORD FOUND\n");
   printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");	
 printf("DATE\t \t HOUSING \tEDUCATION\t TRANSPORT\tPERSONAL\t SAVINGS\t SALARY\t\t TOTALEXPENSE\n");	
  printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");
         printf ( "\n %02d/%02d/%04d \t %.2f\t  %.2f \t %.2f\t%.2f\t %.2f\t %.2f\t %.2f\n",e.dd,e.mm,e.yy,e.house,e.edu,e.transport,e.personal,e.save,e.salary,e.totalexp);	
        fflush(stdin); 
		 
	 }
else
{
		 printf("\n no such record\n");
}
}

fflush(stdin);

   	printf("\n do u want to return to main menu \n (y/n) \n");	op=getche();  
		if(op=='y' || op=='Y')
	{
	menu();
	}
	if(op=='n' || op=='N')
    {
	printf("\n thankyou for using expense manager\n");
	exit(0);
    }
    else
    {
    	printf("\n please enter a valid input\n ");
    	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche(); 
	}
	getch(); 	op=getche();  
	if(op=='y')
	{
main();
	}
	else
{
	printf("\n thankyou for using expense manager\n");
	exit(0);
}
fclose(fp);
getch();
}

void delete_record()
{
system("cls");
    struct expense e;
	FILE *fp1,*fp2, *ft1, *ft2;
	char op;
    int datee,mon, year;
		int found=0;
		int foound = 0;
   fp1 = fopen("file1.txt", "rb+");
   fp2= fopen("del.txt", "ab+");
      ft1 = fopen("save1.txt", "rb+");
   ft2= fopen("save.txt", "ab+");
  if( fp1 == NULL && ft1 == NULL )
        {
        
                printf("\n cannot open file\n");
         }
         
      printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("\t\t\t\t\tDELETE EXPENSE RECORD\n");
  printf("\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
  printf(" ----------------------------------------------------------------------------------\n");
	   	printf("Enter date (dd/mm/yy) format: ");
    scanf("%d/%d/%d", &datee, &mon, &year);
     printf(" ----------------------------------------------------------------------------------\n");
        fseek(fp1,0,SEEK_SET);
 while( fread(&e, sizeof(e), 1, fp1)== 1)
        {
        	
                if((datee,mon,year) == (e.dd,e.mm,e.yy))
                    	{
                    		found=1;
				}
				else{
				
				    fwrite(&e,sizeof(struct expense),1,fp2);
				  
					     }		
		}
			 if(found=1)
	 {
	 	printf("record deleted successfully");
	 }
		
	 else
{
		 printf("\n no such record\n");
}
	 
	 
	  while( fread(&e, sizeof(e), 1, ft1)== 1)
        {
        	foound=1;	
                if((datee,mon,year) == (e.dd,e.mm,e.yy))
                    	{
                    	
				}
				else{
				
				    fwrite(&e,sizeof(struct expense),1,ft2);
				  
					     }		
		}
			 if(foound=1)
	 {
	 	printf("record deleted successfully");
	 }
		
	 if(foound=0)
	 {
	 	 printf("\n no such record");
	 }
	     
		fclose(fp1);
		fclose(fp2);
			fclose(ft1);
		fclose(ft2);
		remove("file1.txt");
		rename("del.txt","file1.txt");
		fclose(ft1);
		fclose(ft2);
			remove("save1.txt");
		rename("save.txt","save1.txt");

		printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche();  
		if(op=='y' || op=='Y')
	{
	menu();
	}
	if(op=='n' || op=='N')
    {
	printf("\n thankyou for using expense manager\n");
	exit(0);
    }
    else
    {
    	printf("\n please enter a valid input\n ");
    	printf("\n do u want to return to main menu \n (y/n) \n");
	op=getche(); 
	}
	getch(); 
	
}



