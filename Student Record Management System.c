#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

#define CLR_RED "\033[91m"
#define CLR_GREEN "\033[92m"
#define CLR_YELLOW "\033[93m"
#define CLR_BLUE "\033[94m"
#define CLR_PINK "\033[95m"
#define CLR_CYAN "\033[96m"
#define CLR_PUR "\033[35m"

struct Student {
	int id;
	char studentName[50];
	char fatherName[50];
	char motherName[50];
	char className[50];
	char dob[50];
	char degreeType[50];
	char category[50];
	char nationality[50];
	char fathersOccupation[50];
	char fatherPhoneNumber[20];
	char studentPhoneNumber[20];
	char address[50];
	char emailId[50];
	char gender[50];
};
struct MarksheetInfo {
	int id;
	int itMark;
	int pcPackageMark;
	int cLanguageMark;
	int cEnglishMark;
	int dElectronicsMark;
};

COORD coordination = {0, 0};
void goxy(int x, int y) {
	coordination.X = x;
	coordination.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordination);
}
void welcome() {
	goxy(45, 7);
	printf("%s-----------------------------------------------------------------", CLR_CYAN);
	goxy(45, 18);
	printf("%s-----------------------------------------------------------------", CLR_CYAN);
	goxy(45,8);
	printf("|");
	goxy(45,9);
	printf("|");
	goxy(45,10);
	printf("|");
	goxy(45,11);
	printf("|");
	goxy(45,12);
	printf("|");
	goxy(45,13);
	printf("|");
	goxy(45,14);
	printf("|");
	goxy(45,15);
	printf("|");
	goxy(45,16);
	printf("|");
	goxy(45,17);
	printf("|");
	goxy(109,8);
	printf("|");
	goxy(109,9);
	printf("|");
	goxy(109,10);
	printf("|");
	goxy(109,11);
	printf("|");
	goxy(109,12);
	printf("|");
	goxy(109,13);
	printf("|");
	goxy(109,14);
	printf("|");
	goxy(109,15);
	printf("|");
	goxy(109,16);
	printf("|");
	goxy(109,17);
	printf("|");
	goxy(50, 10);
	printf("%s:::::: WELCOME TO OUR STUDENT MANAGEMENT SYSTEM ::::::",CLR_RED);
	goxy(60, 14);
	printf("Press any key to login.........");
	getch();
	system("cls");
}
void login();
void printHomePage();
int chooseOption(int value);
void registerStudent();
int findLastId();
void showStudentInfo();
void showAllStudent();
void showSingleStudent();
void updateStudent();
void updateAllInfo();
void updateBasisOnChoice();
void deleteStudent();
void createMarksheet();
void showMarksheet();
int isStudentExist(int id)
{
	FILE *fp;
	struct Student std;

	fp = fopen("StudentInfo.dat", "rb");
	if(fp == NULL) {
		printf("error");
		return 0;
	}
	while(fread(&std, sizeof(std), 1, fp))
	{
		if(std.id == id)
		{			
			return 1;
		}
		
	}
	return 0;
}


int main() {

	system("COLOR F0");
	welcome();
	login();
	system("clear");
	printHomePage();
	int option;
	while(1) {
		scanf("%d", &option);
		chooseOption(option);
		printHomePage();
	}
	return 1;
}

void login() {
	int a=0, i=0;
	char userName[] = "admin";
	char userPassword[] = "admin123";
	char c, code[10];
	char uname[10], upass[10];

	do {
		goxy(60, 10);
		printf("%s------------------------------------\n", CLR_CYAN);
		goxy(60, 11);
		printf("%s|%s            LOGIN FORM            %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
		goxy(60, 12);+
		printf("%s------------------------------------\n", CLR_CYAN);
		goxy(60, 15);
		printf("%sEnter user name : ",CLR_BLUE);
		scanf("%s", &uname);
		goxy(60, 17);
		printf("Enter user password : ");
		while(i<10) {
			upass[i] = getch();
			c=upass[i];
			if(c==13) break;
			else printf("*");
			i++;
		}
		upass[i]='\0';
		i=0;
		if(strcmp(uname, userName) == 0 && strcmp(upass, userPassword) == 0) {
			goxy(60,20);
			printf("%sYou have login successfully\n", CLR_PUR);
			goxy(60,21);
			printf(" press any key to continue......");
			getch();

			for(int j=0; j<3; j++) {
				system("cls");
				goxy(70, 20);
				printf("%sLoading", CLR_RED);
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
			}

			break;

		} else {
			goxy(55,20);
			printf("%sSorry!!! login is unsuccessful", CLR_RED);
			goxy(55,21);
			printf("%sPress any key to try again...", CLR_BLUE);
			getch();
			system("cls");
			a++;

		}
	} while(a<=2);
	if(a>2) {
		goxy(70, 8);
		printf("%sOOPS!!!!!", CLR_RED);
		goxy(40, 10);
		printf("You have entered the wrong user name and passwor more than three times");
		getch();
		system("cls");
		main();
	}
}

void printHomePage() {

	goxy(56, 0);
	printf("%s----------------------------------------\n", CLR_CYAN);
	goxy(56, 1);
	printf("%s|%s   STUDENT RECORD MANAGEMENT SYSTEM   %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
	goxy(56, 2);
	printf("%s----------------------------------------\n", CLR_CYAN);
	goxy(64, 3);
	printf("%sHere is list of operations: \n",CLR_PUR);
	goxy(64, 4);
	printf("%s--------------------------\n", CLR_CYAN);
	goxy(64, 5);
	printf("%s    1. Register student\n", CLR_BLUE);
	goxy(64, 6);
	printf("%s--------------------------\n", CLR_CYAN);
	goxy(64, 7);
	printf("%s    2. Student information\n", CLR_BLUE);
	goxy(64, 8);
	printf("%s--------------------------\n", CLR_CYAN);
	goxy(64, 9);
	printf("%s    3. Update student\n", CLR_BLUE);
	goxy(64, 10);
	printf("%s--------------------------\n", CLR_CYAN);
	goxy(64, 11);
	printf("%s    4. Delete student\n", CLR_BLUE);
	goxy(64, 12);
	printf("%s--------------------------\n", CLR_CYAN);
	goxy(64, 13);
	printf("%s    5. Create markSheet\n", CLR_BLUE);
	goxy(64, 14);
	printf("%s--------------------------\n", CLR_CYAN);
	goxy(64, 15);
	printf("%s    6. Show markSheet\n", CLR_BLUE);
	goxy(64, 16);
	printf("%s--------------------------\n", CLR_CYAN);
	goxy(64, 17);
	printf("%s    7. Exit\n", CLR_BLUE);
	goxy(64, 18);
	printf("%s--------------------------\n", CLR_CYAN);
	printf("\n%sChoose the number of your operation(1 to 7) :------------------------ \n",CLR_PUR);

}

int chooseOption(int value) {
	switch(value) {
		case 1:
			registerStudent();
			break;
		case 2:
			system("cls");
			showStudentInfo();
			system("cls");
			break;
		case 3:
			system("cls");
			updateStudent();
			system("cls");
			getch();
			break;
		case 4:
			deleteStudent();
			break;
		case 5:
			createMarksheet();
			break;
		case 6:
			showMarksheet();
			break;
		case 7:
			printf("Thanks for coming!!!!!\n");
			exit(0);
			break;
		default:
			printf("\nPlease enter valid operation number\n");
			break;
	}
	return 0;
}
int findLastId() {
	FILE *fp;
	struct Student std;

	fp = fopen("StudentInfo.dat", "rb");
	if(fp == NULL) {
		printf("error");
		return 0;
	}

	fseek(fp, -sizeof(std), SEEK_END);

	fread(&std, sizeof(std), 1, fp);
	int id = std.id;

	fclose(fp);
	return id;
}

void registerStudent() {
	FILE *fp;
	struct Student std;
	char another ='y';
	system("cls");
		
	fp = fopen("StudentInfo.dat","ab");
	if(fp == NULL) {
		printf("Error opening file");
		exit(1);
	}
	//fflush(stdin);
	do {
		system("cls");
		goxy(60, 1);
		printf("%s------------------------------------\n", CLR_CYAN);
		goxy(60, 2);
		printf("%s|%s         Register Student         %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
		goxy(60, 3);
		printf("%s------------------------------------\n", CLR_CYAN);
		int id = findLastId();
		goxy(64, 4);
		printf("%sLast Student's Id = %d",CLR_RED, id);
		goxy(65, 6);
		printf("%sStudent Id = ", CLR_BLUE);
		scanf("%d", &std.id);
		if(isStudentExist(std.id))
		{
			goxy(60, 10);
			printf("%sthis Id already existed Please enter again......", CLR_RED);
			getch();
			system("cls");
			fclose(fp);
			return;
		}
		goxy(65, 8);
		fflush(stdin);
		printf("Student Name = ");
		//scanf("%s", &std.studentName);
		fgets(std.studentName, 50, stdin);
		fflush(stdin);
		goxy(65, 10);
		printf("Student's father name = ");
		//scanf("%s", &std.fatherName);
		fgets(std.fatherName, 50, stdin);
		goxy(65,12);
		fflush(stdin);
		printf("Student's mother name = ");
		//scanf("%s", &std.motherName);
		fgets(std.motherName, 50, stdin);
		goxy(65, 14);
		fflush(stdin);
		printf("Student's date of birth = ");
		//scanf("%s", &std.dob);
		fgets(std.dob, 50, stdin);
		goxy(65, 16);
		fflush(stdin);
		printf("Student's category = ");
		//scanf("%s", &std.category);
		fgets(std.category, 50, stdin);
		goxy(65, 18);
		fflush(stdin);
		printf("Stduent's nationality = ");
		//scanf("%s", &std.nationality);
		fgets(std.nationality, 50, stdin);
		fflush(stdin);
		goxy(65, 20);
		printf("Father's occupation = ");
		//scanf("%s", &std.fathersOccupation);
		fgets(std.fathersOccupation, 50, stdin);
		fflush(stdin);
		goxy(65, 22);
		printf("Student's address = ");
		//scanf("%s", &std.address);
		fgets(std.address, 50, stdin);
		fflush(stdin);
		goxy(65, 24);
		printf("Student's phone number = ");
		//scanf("%d", &std.phoneNumber);
		fgets(std.studentPhoneNumber, 20, stdin);
		fflush(stdin);
		goxy(65, 26);
		printf("Student's 2nd phone number(Optional) = ");
		//scanf("%d", &std.phoneNumber);
		fgets(std.fatherPhoneNumber, 20, stdin);
		fflush(stdin);
		goxy(65, 28);
		printf("Student's email id = ");
		//scanf("%s", &std.emailId);
		fgets(std.emailId, 50, stdin);
		goxy(65, 30);
		fflush(stdin);
		printf("Student's gender = ");
		//scanf("%s", &std.gender);
		fgets(std.gender, 50, stdin);
		goxy(65, 32);
		fflush(stdin);
		printf("Student's Class = ");
		//scanf("%s", &std.className);
		fgets(std.className, 50, stdin);
		fflush(stdin);
		goxy(65, 34);
		printf("Degree Type = ");
		fgets(std.degreeType, 50, stdin);
		fflush(stdin);
		fwrite(&std, sizeof(std), 1, fp);

		fflush(stdin);
		//getch();
		goxy(60, 36);
		printf("%sRegistration completed successfully.....", CLR_PUR);
		goxy(52, 37);
		printf("if you want to enter more records please press y/n = ");
		scanf("%c", &another);
	} while(another == 'y');
	fclose(fp);
	system("cls");
	goxy(55, 15);
	printf("%sRecord successfully inserted!!!!", CLR_RED);
	goxy(57, 16);
	printf("press any key to continue...");
	getch();
	system("cls");
}

void showStudentInfo() 
{
	int option;
	char condition = 'y';
	
	do
	{
		goxy(60, 1);
		printf("%s------------------------------------\n", CLR_CYAN);
		goxy(60, 2);
		printf("%s|%s       Students Information       %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
		goxy(60, 3);
		printf("%s------------------------------------\n", CLR_CYAN);
		goxy(60, 5);
		printf("%s1. Show all student list", CLR_PUR);
		goxy(60, 6);
		printf("2. Show particular student informaiton");
		goxy(58, 8);
		printf("%sChoose any option.......", CLR_RED);
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			showAllStudent();
			break;
		case 2:
			showSingleStudent();
			break;
		default:
			printf("choose correct option......");	
		}
		system("cls");
		goxy(60, 5);
		printf("Still want to read information of Student!!!");
		fflush(stdin);
		goxy(60, 6);
		printf("press y/n : ");
		scanf("%c", &condition);
		system("cls");
	}
	while(condition == 'y');
}
void showSingleStudent()
{
	system("cls");
	FILE *fp;
	struct Student std;
	int givenId;
	
	fp = fopen("StudentInfo.dat", "rb");
	if(fp == NULL)
	{
		goxy(60, 5);
		printf("%serror in file opening......", CLR_RED);
		return;
	}
	goxy(65, 5);
	printf("%sEnter your id : ", CLR_RED);
	scanf("%d", &givenId);
	
	while(fread(&std, sizeof(std), 1, fp))
	{
		if(std.id == givenId)
		{
			goxy(60, 7);
			printf("%s------------------------------------\n", CLR_CYAN);
			goxy(60, 8);
			printf("%s|%s       Student Information       %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
			goxy(60, 9);
			printf("%s------------------------------------\n", CLR_CYAN);
			goxy(60, 10);
			printf("%sStudent Name", CLR_PUR);
			goxy(80, 10);
			printf(":    %s", std.studentName);
			goxy(60, 11);
			printf("Father Name");
			goxy(80, 11);
			printf(":    %s", std.fatherName);
			goxy(60, 12);
			printf("Mother Name");
			goxy(80, 12);
			printf(":    %s", std.motherName);
			goxy(60, 13);
			printf("Date Of Birth");
			goxy(80, 13);
			printf(":    %s", std.dob);
			goxy(60, 14);
			printf("Gender");
			goxy(80, 14);
			printf(":    %s", std.gender);
			goxy(60, 15);
			printf("Category");
			goxy(80, 15);
			printf(":    %s", std.category);
			goxy(60, 16);
			printf("Nationality");
			goxy(80, 16);
			printf(":    %s", std.nationality);
			goxy(60, 17);
			printf("Phone Nubmer");
			goxy(80, 17);
			printf(":    %s", std.studentPhoneNumber);
			goxy(60, 18);
			printf("Alternate Phone no.");
			goxy(80, 18);
			printf(":    %s", std.studentPhoneNumber);
			goxy(60, 19);
			printf("Address");
			goxy(80, 19);
			printf(":    %s", std.address);
			goxy(60, 20);
			printf("Student Email");
			goxy(80, 20);
			printf(":    %s", std.emailId);
			goxy(60, 21);
			printf("Father Occupation");
			goxy(80, 21);
			printf(":    %s", std.fathersOccupation);
			goxy(60, 22);
			printf("Branch");
			goxy(80, 22);
			printf(":    %s", std.className);
			goxy(60, 22);
			printf("Degree Type");
			goxy(80, 22);
			printf(":    %s", std.degreeType);
			goxy(58, 25);
			printf("%sPress any key to continue.....", CLR_RED);
			getch();
			system("cls");
			return;
		}
		
	}
	goxy(60, 7);
	printf("%syou have inserted wrong id......", CLR_RED);
	goxy(60, 8);
	printf("Press any key to continue.....");
	getch();
	system("cls");
}
void showAllStudent()
{
	system("cls");
	FILE *fp;
	struct Student std;

	fp = fopen("StudentInfo.dat", "rb");
	if(fp == NULL) {
		printf("error");
		return;
	}
	goxy(50, 1);
	printf("%s------------------------------------\n", CLR_CYAN);
	goxy(50, 2);
	printf("%s|%s        All Student Record        %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
	goxy(50, 3);
	printf("%s------------------------------------\n", CLR_CYAN);
	goxy(11, 5);
	printf("---------------------------------------------------------------------------------------------------------");
	goxy(11, 6);
	printf("|");
	goxy(27, 6);
	printf("|");
	goxy(43, 6);
	printf("|");
	goxy(52, 6);
	printf("|");
	goxy(69, 6);
	printf("|");
	goxy(83, 6);
	printf("|");
	goxy(98, 6);
	printf("|");
	goxy(11, 7);
	printf("---------------------------------------------------------------------------------------------------------");
	goxy(15, 6);
	printf("%sStudent Id",CLR_PUR);
	goxy(30, 6);
	printf("Student Name ");
	goxy(45, 6);
	printf("Branch");
	goxy(54, 6);
	printf("Date of Birth");
	goxy(72, 6);
	printf("Phone No.");
	goxy(87, 6);
	printf("Address");
	goxy(100, 6);
	printf("Email Address %s |", CLR_CYAN);

	int i = 8;
	while(fread(&std, sizeof(struct Student), 1, fp)) 
	{
		printf("%s", CLR_PUR);
		goxy(15, i);
		printf("%d" ,std.id);
		goxy(30, i);
		printf("%s", std.studentName);
		goxy(45, i);
		printf("%s", std.className);
		goxy(54, i);
		printf("%s", std.dob);
		goxy(72, i);
		printf("%s", std.studentPhoneNumber);
		goxy(85, i);
		printf("%s", std.address);
		goxy(100, i);
		printf("%s", std.emailId);
		i++;
    }
	fclose(fp);
	printf("\n\n\n%sPress any key to go back......",CLR_RED);
	getch();
	system("cls");
}

void updateBasisOnChoice() 
{
	FILE *fp;
	struct Student std;
	int givenId;
	int found;

	fp = fopen("StudentInfo.dat", "rb+");
	if(fp == NULL) {
		printf("error");
		return;
	}
	system("cls");
	goxy(60, 5);
	printf("%s------------------------------------------\n", CLR_CYAN);
	goxy(60, 6);
	printf("%s|%s       Update Student Information       %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
	goxy(60, 7);
	printf("%s------------------------------------------\n", CLR_CYAN);
	goxy(71, 8);
	printf("%sEnter your id : ", CLR_RED);
	scanf("%d", &givenId);
	
	while(fread(&std, sizeof(std), 1, fp)) {
		if(std.id == givenId) {
			goxy(60, 10);
			printf("%sStudent Name", CLR_PUR);
			goxy(80, 10);
			printf(":    %s", std.studentName);
			goxy(60, 11);
			printf("Father Name");
			goxy(80, 11);
			printf(":    %s", std.fatherName);
			goxy(60, 12);
			printf("Mother Name");
			goxy(80, 12);
			printf(":    %s", std.motherName);
			goxy(60, 13);
			printf("Date Of Birth");
			goxy(80, 13);
			printf(":    %s", std.dob);
			goxy(60, 14);
			printf("Gender");
			goxy(80, 14);
			printf(":    %s", std.gender);
			goxy(60, 15);
			printf("Category");
			goxy(80, 15);
			printf(":    %s", std.category);
			goxy(60, 16);
			printf("Phone Number");
			goxy(80, 16);
			printf(":    %s", std.studentPhoneNumber);
			goxy(60, 17);
			printf("Alternet Phone No.");
			goxy(80, 17);
			printf(":    %s", std.fatherPhoneNumber);
			goxy(60, 18);
			printf("Address");
			goxy(80, 18);
			printf(":    %s", std.address);
			goxy(60, 19);
			printf("Student Email");
			goxy(80, 19);
			printf(":    %s", std.emailId);
			goxy(60, 20);
			printf("Father Occupation");
			goxy(80, 20);
			printf(":    %s", std.fathersOccupation);
			goxy(60, 21);
			printf("Branch");
			goxy(80, 21);
			printf(":    %s", std.className);
			goxy(60, 22);
			printf("Degree Type");
			goxy(80, 22);
			printf(":    %s", std.degreeType);
			goxy(60, 23);
			printf("Nationality");
			goxy(80, 23);
			printf(":    %s", std.nationality);
			goxy(58, 25);
			printf("%sPress any key to update information.....", CLR_RED);
			getch();
			system("cls");
			
			goxy(60, 5);
			printf("%s------------------------------------------\n", CLR_CYAN);
			goxy(60, 6);
			printf("%s|%s       Update Student Information       %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
			goxy(60, 7);
			printf("%s------------------------------------------\n", CLR_CYAN);
			int choice;
			int i=25;
			do 
			{
				goxy(60, 8);
				printf("%sWhich field you want to update",CLR_BLUE);
				goxy(60, 10);
				printf("%s1. Student name", CLR_PUR);
				goxy(60, 11);
				printf("2. Father name");
				goxy(60, 12);
				printf("3. Mother name");			
				goxy(60, 13);
				printf("4. Date of birth");		
				goxy(60, 14);
				printf("5. Gender");				
				goxy(60, 15);
				printf("6. Category");			
				goxy(60, 16);
				printf("7. Phone number");			
				goxy(60, 17);
				printf("8. Alternet phone no.");			
				goxy(60, 18);
				printf("9. Address");			
				goxy(60, 19);
				printf("10. Student email");			
				goxy(60, 20);
				printf("11. Father occupation");			
				goxy(60, 21);
				printf("12. Branch");			
				goxy(60, 22);
				printf("13. Degree type");			
				goxy(60, 23);
				printf("14. Nationality");
				goxy(60, 24);
				printf("15. Exit");
				goxy(60, i);
				printf("%sEnter your choice -> ",CLR_BLUE);
				scanf("%d", &choice);
				printf("%s", CLR_PUR);
				
				switch(choice) 
				{
					
					case 1:
						goxy(60, ++i);
						printf("Student name : ");
                        getchar(); // To consume newline left by scanf
                        fgets(std.studentName, sizeof(std.studentName), stdin);
                        std.studentName[strcspn(std.studentName, "\n")] = '\0'; // Remove newline
                        break;
                    case 2:
                    	goxy(60, ++i);
                    	printf("Father name : ");
                        getchar(); 
                        fgets(std.fatherName, sizeof(std.fatherName), stdin); 
                        break;
                    case 3:
                    	goxy(60, ++i);
                    	printf("Mother name : ");
                        getchar(); 
                        fgets(std.motherName, sizeof(std.motherName), stdin);
                        break;
                    case 4:
                    	goxy(60, ++i);
                    	printf("Date Of Birth : ");
                        getchar(); 
                        fgets(std.dob, sizeof(std.dob), stdin);
                        break;
                    case 5:
                    	goxy(60, ++i);
                    	printf("Gender : ");
                        getchar(); 
                        fgets(std.gender, sizeof(std.gender), stdin); 
                        break;
                    case 6:
                    	goxy(60, ++i);
                    	printf("Category : ");
                        getchar(); 
                        fgets(std.category, sizeof(std.category), stdin); 
                        break;
                    case 7:
                    	goxy(60, ++i);
                    	printf("Phone number : ");
                        getchar(); 
                        fgets(std.studentPhoneNumber, sizeof(std.studentPhoneNumber), stdin);
                        break;
                    case 8:
                    	goxy(60, ++i);
                    	printf("Alternet phone no. : ");
                        getchar(); 
                        fgets(std.fatherPhoneNumber, sizeof(std.fatherPhoneNumber), stdin);
                        break;
                    case 9:
                    	goxy(60, ++i);
                    	printf("Address : ");
                        getchar(); 
                        fgets(std.address, sizeof(std.address), stdin);
                        break;
                    case 10:
                    	goxy(60, ++i);
                    	printf("Student email : ");
                        getchar(); 
                        fgets(std.emailId, sizeof(std.emailId), stdin);
                        break;
                    case 11:
                    	goxy(60, ++i);
                    	printf("Father occupation : ");
                        getchar(); 
                        fgets(std.fathersOccupation, sizeof(std.fathersOccupation), stdin); 
                        break;
                    case 12:
                    	goxy(60, ++i);
                    	printf("Branch : ");
                        getchar(); 
                        fgets(std.className, sizeof(std.className), stdin);
                        break;
                    case 13:
                    	goxy(60, ++i);
                    	printf("Degree Type: ");
                    	getchar(); 
                        fgets(std.degreeType, sizeof(std.degreeType), stdin);
                        break;
                    case 14:
                    	goxy(60, ++i);
                    	printf("Nationality: ");
                    	getchar(); 
                        fgets(std.nationality, sizeof(std.nationality), stdin);
                        break;
                    case 15:
                    	goxy(60, ++i);
                    	printf("Exiting update...\n");
                    	break;
                    default:
                    	goxy(60, ++i);
                    	printf("%sPlease choose correct field........", CLR_RED);
				}
				i++;
			}
			while(choice != 15);
			
			fflush(stdin);
			// Move the file pointer back to overwrite the record
            fseek(fp, -sizeof(std), SEEK_CUR);
            fwrite(&std, sizeof(std), 1, fp);
            system("cls");
            goxy(60, 6);
            printf("Student information updated successfully.\n");
            fclose(fp);
            getch();
		}
	}
}
			

void updateAllInfo()
{
	FILE *fp;
	struct Student std;
	int givenId;

	fp = fopen("StudentInfo.dat", "rb+");
	if(fp == NULL) {
		printf("error");
		return;
	}
	system("cls");
	goxy(60, 5);
	printf("%s------------------------------------------\n", CLR_CYAN);
	goxy(60, 6);
	printf("%s|%s       Update Student Information       %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
	goxy(60, 7);
	printf("%s------------------------------------------\n", CLR_CYAN);
	goxy(71, 8);
	printf("%sEnter your id : ", CLR_RED);
	scanf("%d", &givenId);

	while(fread(&std, sizeof(std), 1, fp)) {
		if(std.id == givenId) {
			goxy(60, 10);
			printf("%sStudent Name", CLR_PUR);
			goxy(80, 10);
			printf(":    %s", std.studentName);
			goxy(60, 11);
			printf("Father Name");
			goxy(80, 11);
			printf(":    %s", std.fatherName);
			goxy(60, 12);
			printf("Mother Name");
			goxy(80, 12);
			printf(":    %s", std.motherName);
			goxy(60, 13);
			printf("Date Of Birth");
			goxy(80, 13);
			printf(":    %s", std.dob);
			goxy(60, 14);
			printf("Gender");
			goxy(80, 14);
			printf(":    %s", std.gender);
			goxy(60, 15);
			printf("Category");
			goxy(80, 15);
			printf(":    %s", std.category);
			goxy(60, 16);
			printf("Phone Number");
			goxy(80, 16);
			printf(":    %s", std.studentPhoneNumber);
			goxy(60, 17);
			printf("Alternet Phone No.");
			goxy(80, 17);
			printf(":    %s", std.fatherPhoneNumber);
			goxy(60, 18);
			printf("Address");
			goxy(80, 18);
			printf(":    %s", std.address);
			goxy(60, 19);
			printf("Student Email");
			goxy(80, 19);
			printf(":    %s", std.emailId);
			goxy(60, 20);
			printf("Father Occupation");
			goxy(80, 20);
			printf(":    %s", std.fathersOccupation);
			goxy(60, 21);
			printf("Branch");
			goxy(80, 21);
			printf(":    %s", std.className);
			goxy(60, 22);
			printf("Degree Type");
			goxy(80, 22);
			printf(":    %s", std.degreeType);
			goxy(60, 23);
			printf("Nationality");
			goxy(80, 23);
			printf(":    %s", std.nationality);
			goxy(58, 25);
			printf("%sPress any key to fill new Record.....", CLR_RED);
			getch();
			system("cls");

			goxy(60, 5);
			printf("%s------------------------------------------\n", CLR_CYAN);
			goxy(60, 6);
			printf("%s|%s       Update Student Information       %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
			goxy(60, 7);
			printf("%s------------------------------------------\n", CLR_CYAN);
			goxy(60, 9);
			printf("%sStudent Id = %d",CLR_PUR, std.id);
			fflush(stdin);
			goxy(60, 10);
			printf("Enter name = ");
			//scanf("%s", &std.studentName);
			fgets(std.studentName, 50, stdin);
			fflush(stdin);
			goxy(60, 11);
			printf("Enter father name = ");
			//scanf("%s", &std.fatherName);
			fgets(std.fatherName, 50, stdin);
			fflush(stdin);
			goxy(60,12);
			printf("Enter Mother name = ");
			//scanf("%s", &std.motherName);
			fgets(std.motherName, 50, stdin);
			fflush(stdin);
			goxy(60, 13);
			printf("Student's date of birth = ");
			//scanf("%s", &std.dob);
			fgets(std.dob, 50, stdin);
			fflush(stdin);
			goxy(60, 14);
			printf("Student's category = ");
			//scanf("%s", &std.category);
			fgets(std.category, 50, stdin);
			fflush(stdin);
			goxy(60, 15);
			printf("Stduent's nationality = ");
			//scanf("%s", &std.nationality);
			fgets(std.nationality, 50, stdin);
			fflush(stdin);
			goxy(60, 16);
			printf("Father's occupation = ");
			//scanf("%s", &std.fathersOccupation);
			fgets(std.fathersOccupation, 50, stdin);
			fflush(stdin);
			goxy(60, 17);
			printf("Student's address = ");
			//scanf("%s", &std.address);
			fgets(std.address, 50, stdin);
			fflush(stdin);
			goxy(60, 18);
			printf("Student's phone number = ");
			//scanf("%d", &std.phoneNumber);
			fgets(std.studentPhoneNumber, 20, stdin);
			fflush(stdin);
			goxy(60, 19);
			printf("Alternate phone number = ");
			//scanf("%d", &std.phoneNumber);
			fgets(std.fatherPhoneNumber, 20, stdin);
			fflush(stdin);
			goxy(60, 20);
			printf("Student's email id = ");
			//scanf("%s", &std.emailId);
			fgets(std.emailId , 50, stdin);
			fflush(stdin);
			goxy(60, 21);
			printf("Student's gender = ");
			//scanf("%s", &std.gender);
			fgets(std.gender , 50, stdin);
			fflush(stdin);
			goxy(60, 22);
			printf("Branch = ");
			//scanf("%s", &std.className);
			fgets(std.className, 50, stdin);
			fflush(stdin);
			goxy(60, 22);
			printf("Degree Type = ");
			//scanf("%s", &std.className);
			fgets(std.degreeType, 50, stdin);
			fflush(stdin);

			fseek(fp, -sizeof(std), SEEK_CUR);

			fwrite(&std, sizeof(std), 1, fp);
			//fflush(stdin);
			fclose(fp);
			goxy(60, 23);
			printf("%s-::::Information updated::::-", CLR_RED);
			goxy(60, 24);
			printf("Press any key to continue.....");
			getch();
			system("cls");
			return;
		}

	}
	goxy(60, 10);
	printf("%syou have inserted wrong id......", CLR_RED);
	goxy(60, 11);
	printf("Press any key to continue.....");
	getch();
	system("cls");
} 

void updateStudent() 
{
	int option;
	char condition = 'y';
	
	do
	{
		goxy(60, 1);
		printf("%s------------------------------------\n", CLR_CYAN);
		goxy(60, 2);
		printf("%s|%s       Update Information       %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
		goxy(60, 3);
		printf("%s------------------------------------\n", CLR_CYAN);
		goxy(60, 5);
		printf("%s1. Update all information", CLR_PUR);
		goxy(60, 6);
		printf("2. Update particular informaiton");
		goxy(58, 8);
		printf("%sChoose any option.......", CLR_RED);
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			updateAllInfo();
			break;
		case 2:
			updateBasisOnChoice();
			break;
		default:
			printf("choose correct option......");	
		}
		system("cls");
		goxy(60, 5);
		printf("Still want to update information of Student!!!");
		fflush(stdin);
		goxy(60, 6);
		printf("press y/n : ");
		scanf("%c", &condition);
		system("cls");
	}
	while(condition == 'y');
}

void deleteStudent() 
{
	system("cls");
	struct Student student;
	FILE *file, *tempFile;
	int id;
	int found = 0;
	// Open the original file for reading in binary mode
	file = fopen("StudentInfo.dat", "rb");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// Open a temporary file for writing in binary mode
	tempFile = fopen("temp.dat", "wb");
	if (tempFile == NULL) {
		printf("Error creating temporary file.\n");
		fclose(file);
		return;
	}

	// Ask the user for the id of the student to delete
	goxy(45, 5);
	printf("%sEnter Id number of the student to delete : ", CLR_PUR);
	scanf("%d", &id);

	// Read from the original file and write to the temporary file
	while (fread(&student, sizeof(struct Student), 1, file)) {
		if (student.id == id) {
			found = 1;
			system("cls");
			goxy(45, 7);
			printf("%sRecord with Id %d deleted successfully.",CLR_RED, id);
			goxy(45, 8);
			printf("Wait for a moment.....");
			getch();
		} else {
			// Write the record to the temporary file if it is not the one to be deleted
			fwrite(&student, sizeof(struct Student), 1, tempFile);
		}
	}
	
	if (!found) {
		fflush(stdin);
		goxy(45, 7);
		printf("%sStudent with id %d not found.\n",CLR_RED, id);
		fclose(file);
		fclose(tempFile);
		goxy(45, 8);
		printf("Press any key to continue...");
		getch();
		system("cls");
		return;
	}

	// Close both files
	fclose(file);
	fclose(tempFile);

	// Delete the original file
	remove("StudentInfo.dat");

	// Rename the temporary file to the original file name
	rename("temp.dat", "StudentInfo.dat");
	
	Sleep(200);
	system("cls");
	goxy(55, 8);
	printf("Press any key to continue.....");
	getch();
	system("cls");
}

void createMarksheet() 
{
	system("cls");

	struct MarksheetInfo mkInfo;
	FILE *fp;
	int id;
	char condition = 'n';
	
	fp = fopen("MarkSheets.dat", "ab");
	if (fp == NULL) {
		printf("Error creating temporary file.\n");
		fclose(fp);
		return;
	}
	
	do
	{
		system("cls");
		goxy(60, 5);
		printf("%s--------------------------------------\n", CLR_CYAN);
		goxy(60, 6);
		printf("%s|%s       MarkSheet Information        %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
		goxy(60, 7);
		printf("%s--------------------------------------\n", CLR_CYAN);
		goxy(68, 9);
		printf("%sEnter Student Id : ", CLR_PUR);
		scanf("%d", &mkInfo.id);
		if(isStudentExist(mkInfo.id) == 0)
		{
			goxy(60, 11);
			printf("%sThis student doesn't exist in system", CLR_RED);
			goxy(60, 12);
			printf("Enter correct student id and try again.....");
			getch();
			system("cls");
			fclose(fp);
			return;
		}
		goxy(65, 11);
		printf("%s----::::::Enter Marks::::::----", CLR_RED);
		goxy(62, 13);
		printf("%sInformation Technology : ", CLR_PUR);
		scanf("%d", &mkInfo.itMark);
		goxy(62, 15);
		printf("Digital Electronics : ");
		scanf("%d", &mkInfo.dElectronicsMark);
		fflush(stdin);
		goxy(62, 17);
		printf("PC Package : ");
		scanf("%d", &mkInfo.pcPackageMark);
		fflush(stdin);
		goxy(62, 19);
		printf("C Language : ");
		scanf("%d", &mkInfo.cLanguageMark);
		goxy(62, 21);
		printf("Communicative English : ");
		scanf("%d", &mkInfo.cEnglishMark);
		
		fwrite(&mkInfo, sizeof(mkInfo), 1, fp);
		fflush(stdin);
		goxy(60, 23);
		printf("Information successfully submited");
		goxy(60, 24);
		printf("Press y/n if you want to fill more information or not : ");
		scanf("%c", &condition);
	}
	while(condition == 'y');
	fclose(fp);
	system("cls");
	goxy(60, 5);
	printf("%sAll information submitted", CLR_RED);
	goxy(60, 6);
	printf("Press any key to continue.....");
	getch();
	system("cls");
}

void showMarksheet() 
{
	system("cls");
	struct MarksheetInfo mkInfo;
	struct Student std;
	FILE *mfp, *sfp;
	int id;
	char condition = 'n';
	int givenId;
	int found1, found2;
	int supplyCount = 0;
	
	mfp = fopen("MarkSheets.dat", "rb");
	if (mfp == NULL) {
		printf("Error opening file.\n");
		fclose(mfp);
		return;
	}
	sfp = fopen("StudentInfo.dat", "rb");
	if(sfp == NULL)
	{
		printf("Error opening file.\n");
		fclose(sfp);
		return;
	}
	
	goxy(60, 5);
	printf("%sEnter student id : ", CLR_RED);
	scanf("%d", &givenId);
	
	while(fread(&std, sizeof(struct Student), 1, sfp))
	{
		if(std.id == givenId)
		{
			found1 = 1;
			break;
		}
	}
	while(fread(&mkInfo, sizeof(mkInfo), 1, mfp))
	{
		if(mkInfo.id == givenId)
		{
			found2 = 1;
			break;
		}
	}
	if(found1 == 1 && found2 == 1)
	{
	system("cls");
	goxy(56, 0);
	printf("%s--------------------------------------------\n", CLR_CYAN);
	goxy(56, 1);
	printf("%s|%s   MAKHANLAL CHATURVEDI VISHWAVIDHYALAYA  %s|\n",CLR_CYAN, CLR_BLUE,CLR_CYAN);
	goxy(56, 2);
	printf("%s--------------------------------------------\n", CLR_CYAN);
	goxy(34, 4);
	printf("%sStudent Name : ",CLR_PUR);
	goxy(50, 4);
	printf("%s", std.studentName);
	goxy(34, 5);
	printf("Branch : ");
	goxy(50, 5);
	printf("%s", std.className);
	goxy(34, 6);
	printf("Semester : ");
	goxy(50, 6);
	printf("1st");
	goxy(90, 4);
	printf("Father Name : ");
	goxy(105, 4);
	printf("%s", std.fatherName);
	goxy(90, 5);
	printf("Session : ");
	goxy(105, 5);
	printf("2024");
	goxy(90, 6);
	printf("Year : ");
	goxy(105, 6);
	printf("1st");
	goxy(32, 8);
	printf("%s-----------------------------------------------------------------------------------------", CLR_CYAN);
	goxy(32, 11);
	printf("-----------------------------------------------------------------------------------------");
	goxy(32, 19);
	printf("-----------------------------------------------------------------------------------------");
	goxy(32, 22);
	printf("-----------------------------------------------------------------------------------------");
	goxy(38, 10);
	printf("%sS.NO.", CLR_RED);
	goxy(54, 10);
	printf("SUBJECT");
	goxy(78, 10);
	printf("MIN");
	goxy(94, 10);
	printf("MAX");
	goxy(105, 10);
	printf("OBTAINED");
	goxy(38, 13);
	printf("%s1. ", CLR_PUR);
	goxy(38, 14);
	printf("2. ");
	goxy(38, 15);
	printf("3. ");
	goxy(38, 16);
	printf("4. ");
	goxy(38, 17);
	printf("5. ");
	goxy(48, 13);
	printf("%sDigital Electronics", CLR_PUR);
	goxy(48, 14);
	printf("Information Technology");
	goxy(48, 15);
	printf("PC Package");
	goxy(48, 16);
	printf("C Language");
	goxy(48, 17);
	printf("Communicative English");
	goxy(78, 13);
	printf("27");
	goxy(78, 14);
	printf("27");
	goxy(78, 15);
	printf("27");
	goxy(78, 16);
	printf("27");
	goxy(78, 17);
	printf("27");
	goxy(94, 13);
	printf("80");
	goxy(94, 14);
	printf("80");
	goxy(94, 15);
	printf("80");
	goxy(94, 16);
	printf("80");
	goxy(94, 17);
	printf("80");
	if(mkInfo.dElectronicsMark < 27) 
	{
		supplyCount = supplyCount + 1;
		goxy(105, 13);
		printf("%d *", mkInfo.dElectronicsMark);
	} 
	else 
	{
		goxy(105, 13);
		printf("%d", mkInfo.dElectronicsMark);
	}
	if(mkInfo.itMark < 27) {
		supplyCount = supplyCount + 1;
		goxy(105, 14);
		printf("%d *", mkInfo.itMark);
	} else {
		goxy(105, 14);
		printf("%d", mkInfo.itMark);
	}
	if(mkInfo.pcPackageMark < 27) {
		supplyCount = supplyCount + 1;
		goxy(105, 15);
		printf("%d *", mkInfo.pcPackageMark);
	} else {
		goxy(105, 15);
		printf("%d", mkInfo.pcPackageMark);
	}
	if(mkInfo.cLanguageMark < 27) {
		supplyCount = supplyCount + 1;
		goxy(105, 16);
		printf("%d *", mkInfo.cLanguageMark);
	} else {
		goxy(105, 16);
		printf("%d", mkInfo.cLanguageMark);
	}
	if(mkInfo.cEnglishMark < 27) {
		supplyCount = supplyCount + 1;
		goxy(105, 17);
		printf("%d *", mkInfo.cEnglishMark);
	} else {
		goxy(105, 17);
		printf("%d", mkInfo.cEnglishMark);
	}
	goxy(78, 21);
	printf("TOTAL");
	float total = mkInfo.dElectronicsMark + mkInfo.itMark + mkInfo.pcPackageMark + mkInfo.cLanguageMark + mkInfo.cEnglishMark;
	goxy(105, 21);
	printf("%.0f", total);
	goxy(94, 21);
	printf("400");
	float percent = (total/400) * 100;
	float cgpa = percent/9.5;
	goxy(38, 24);
	printf("Percentage : %.2f", percent);
	goxy(94, 24);
	printf("CGPA : ");
	goxy(105, 24);
	printf("%.1f", cgpa);
	if(supplyCount == 0) {
		goxy(94, 26);
		printf("Result : Pass");
	} else if(supplyCount <= 2) {
		goxy(94, 26);
		printf("Result : Supply");
	} else {
		goxy(94, 26);
		printf("Result : %sFail", CLR_RED);
	}
	getch();
	system("cls");
	}
	else
	{
		goxy(60, 5);
		printf("You have inserted wrong id!!!");
		goxy(60, 6);
		printf("Press any key to continue....");
		getch();
		system("cls");
	}
}