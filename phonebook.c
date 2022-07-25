#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<string.h>
void menu(void);
void password(void);
void namefun(void);
void searchfun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);
void gotoxy(int x,int y){
	COORD c;//COORD is a pre defined structure to hold screen's COORDinates X and Y
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main(){
	system("color B");
	password();
	getch();	
}

void namefun(){
	system("cls");
	gotoxy(31,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	FILE *fptr;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	fptr=fopen("kaif.txt","ab+");//ab+ gives us the ability of writing the function and add the second data in the existing one...
	if(fptr==NULL){
		printf("Failed to create the required file.");
	}
	else{
		gotoxy(31,6);
		printf("Name:\t");
		gotoxy(52,6);
		gets(name);
		gotoxy(31,7);
		printf("Address:\t");
		gotoxy(52,7);
		gets(address);
		gotoxy(31,8);
		printf("Gender:\t");
		gotoxy(52,8);
		gets(gender);
		gotoxy(31,9);
		printf("Gmail:\t");
		gotoxy(52,9);
		gets(gmail);
		gotoxy(31,10);
		printf("Phone Number:\t");
		gotoxy(52,10);
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
	}
	fclose(fptr);
	system("cls");
	char ch;
	gotoxy(31,4);
	printf("Add successfully.");
	gotoxy(31,6);
	printf("Press y for menu");
	Sleep(1000);
	fflush(stdin);
	while((ch=getch())=='y'){
		menu();
	}
}

void searchfun(){
	FILE *fptr;
	int flag=0;
	int res;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	char name1[100];
	system("cls");
	fflush(stdin);
	gotoxy(12,2);
	printf("\xDB\xDB\xDB Enter the name of the person you want to see the detail:: ");
	gets(name1);
	fptr=fopen("kaif.txt","r");
	//fflush(stdin);
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0){
			gotoxy(39,4);
			printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			gotoxy(28,5);
			printf("----------------------------------------");
		gotoxy(31,6.5);
		printf("\xB3\xB2\xB2\xB2 Name:\t%s",name);
		gotoxy(31,7);
		printf("\xB3\xB2\xB2\xB2 Address:\t%s",address);
			gotoxy(31,8);
		printf("\xB3\xB2\xB2\xB2 Gender:\t%s",gender);
		gotoxy(31,9);
		printf("\xB3\xB2\xB2\xB2 Gmail:\t%s",gmail);
		gotoxy(31,10);
		printf("\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf",phone);
		gotoxy(31,11);
			printf("----------------------------------------");
		flag=1;
		Sleep(1000);
			gotoxy(18,12);
			printf("Enter y for menu option.");
	while(getch()=='y'){
		menu();
	}
	}
}
	if(flag==0){
		system("cls");
		system("color c");
		gotoxy(30,4);
		printf("No record found.");;
		gotoxy(21,6);
		printf("Returning in main menu section...");
		Sleep(3000);
		system("color B");
		menu();
		if(getch()=='a'){
			system("cls");
			searchfun();
		}
	
	}
	

	fclose(fptr);
}
void listfun(){
		FILE *fptr;
	char name[100],address[100],gmail[100],gender[8];
	double phone;
	int f;
	fptr=fopen("kaif.txt","r");
	system("cls");
	gotoxy(31,2);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	printf("\n");
	while(fscanf(fptr,"%s %s %s %s %lf",name,address,gender,gmail,&phone)!=EOF){
		
			printf("------------------------------------------\n");
		printf("Name:%s\n",name);
		printf("Address:%s\n",address);
		printf("Gender:%s\n",gender);
		printf("Gmail:%s\n",gmail);
		printf("Phone:%.0lf\n",phone);
			f=1;
				printf("------------------------------------------");
				printf("\n\n");
		}
		Sleep(1000);
		printf("Enter  y for menu section:");
		while(getch()=='y'){
			menu();
		}
			fclose(fptr);
			}



void modifyfun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8],gender1[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("kaif.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(31,4);
	printf("Enter the name: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			gotoxy(31,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			gotoxy(31,6);
			printf("Enter the new address:");
			scanf("%s",address1);
				gotoxy(31,7);
			printf("Enter the gender:");
			scanf("%s",gender1);
			gotoxy(31,8);
			printf("Enter the new gmail:");
			scanf("%s",gmail1);
			gotoxy(31,9);
			printf("Enter the new phone number:");
			scanf("%lf",&phone1);
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address1,gender1,gmail1,phone1);
			
		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("kaif.txt","w");
	fclose(fptr);
	fptr=fopen("kaif.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		
	}
	
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	}
}
void deletefun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("kaif.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(15,4);
	printf("ENTER THE CONTACT NAME THAT YOU WANT TO DELETE: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			gotoxy(22,10);
			printf("Deleted successfully");
			
		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		gotoxy(30,5);
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("kaif.txt","w");
	fclose(fptr);
	fptr=fopen("kaif.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		printf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		
	}
	
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	gotoxy(5,20);
	printf("Press y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	};
}
void exitfun(){
	system("cls");
	gotoxy(31,4);
	printf("\xDB\xDB\xDB\xDB TEAM MEMBERS \xDB\xDB\xDB\xDB");
	gotoxy(31,6);
	printf("\xDB KyriOsNox.");
	gotoxy(31,8);
	printf("\xDB NoiR.");
	printf("\n\n\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(31,14);
	printf("\xB3\xB2\xB2\xB2\xB2 ALL THE BEST\xB2\xB2\xB2\xB2\xB3");
	gotoxy(32,17);
	printf("ENTER ANY KEY TO EXIT");
}
void password(void){
	char passwords[20]={"suzie"};
	gotoxy(22,2);
	int j;
	int B;
	char welcome[50]="YOU ARE ENTERED IN KYRIOSNOX'S WORLD";
	B=strlen(welcome);

	for(j=0;j<=B;j++){
		Sleep(50);
		printf("%c",welcome[j]);
	}

	gotoxy(21,4);
	printf(" PASSWORD:");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0){
		system("cls");
		gotoxy(30,8);
		printf("CORRECT PASSWORD");
		gotoxy(20,10);
		system("color a");
		printf("NOW YOU ARE MEMBER OF KYRIOSNOX'S WORLD");
		Sleep(3500);
		menu();
	}
	else{
		system("cls");
		gotoxy(18,8);
		system("color c");
		printf("IF YOU WANT TO BE A MEMBER OF KYRIOSNOX'S WORLD");
		gotoxy(24,12);
		printf("PLEASE ENTER A CORRECT PASSWORD");
		Sleep(2500);
		system("cls");
		system("color B");
		password();
}
	
}
	
void menu(){
	system("cls");
	gotoxy(20,1);
	printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ PHONEBOOK DIRECTORY \xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1.Add New");
	gotoxy(20,7);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2.Search");
	gotoxy(20,10);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3.List");
	gotoxy(20,13);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4.Modify");
	gotoxy(20,16);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5.Delete");
	gotoxy(20,19);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6.Exit");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			searchfun();
			break;
		case '3':
			listfun();
			break;
		case '4':
			modifyfun();
			break;
		case '5':
			deletefun();
			break;
		case '6':
			exitfun();
			break;
		default:
			system("cls");
			system("color c");
			gotoxy(30,10);
			printf("INVALID ENTER");
			Sleep(2000);
			system("cls");
			system("color B");
			menu();
}
}
