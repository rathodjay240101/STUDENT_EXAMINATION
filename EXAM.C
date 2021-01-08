#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Question_Paper

{
	char question[200],option1[30],option2[30],option3[30],option4[30],ans;
};

void Clear_Screen();
void Clear_Line(int line);
void Clear_Colour_Line(int line);
void Clear_Internal_Screen();
void Heading();
void Teacher_Last_Page(char name[],char option);
void Student_Last_Page(char name[],char rollno[]);
void Teacher_Result_Class(char name[],char option);
void Teacher_Result_Student(char name[],char option);
void Teacher_View_Question_Paper(char name[],char option);
void Teacher_Set_Question_Paper(char name[],char option);
void Student_Result_All(char name[],char rollno[]);
void Student_Result_Subject(char name[],char rollno[],char choice);
void Student_Exam_Subject(char name[],char rollno[],char choice);
void Teacher_Result(char name[],char option);
void Teacher_Question_Paper(char name[],char option);
void Student_Result(char name[],char rollno[]);
void Student_Exam(char name[],char rollno[]);
void Teacher_Home_Page(char name[],char option);
void Student_Home_Page(char name[],char rollno[]);
void Teacher_Login(char filep[],char filen[],char option);
void Teacher_Registration(char filep[],char filen[],char option);
void Student_Login(char filep[],char filen[],char rollno[]);
void Student_Registration(char filep[],char filen[],char rollno[]);
void Teacher_Page();
void Student_Page();
void Home_Page();

void main()

{
	clrscr();
	Clear_Screen();
	Heading();
	Home_Page();
	getch();
	Clear_Screen();
}

void Clear_Screen()

{
	int i,j;
	textbackground(0);	//0 stands for black colour
	for(i=1;i<=80;i++)
	{
		for(j=1;j<=25;j++)
		{
			cprintf(" ");
		}
	}
}

void Clear_Internal_Screen()

{
	int i,j;
	for(i=3;i<=78;i++)
	{
		for(j=6;j<=23;j++)
		{
			gotoxy(i,j);
			printf(" ");
		}
	}
}

void Clear_Line(int line)

{
	int i;
	for(i=3;i<=78;i++)
	{
		gotoxy(i,line);
		printf(" ");
	}
}

void Clear_Colour_Line(int line)

{
	int i;
	textbackground(0);
	for(i=3;i<=78;i++)
	{
		gotoxy(i,line);
		cprintf(" ");
	}
}

void Heading()

{
	int i;
	textbackground(7);	//7 stand for white colour
	textcolor(0);		//0 stand for black colour
	for(i=1;i<=80;i++)
	{
		gotoxy(i,1);
		cprintf(" ");
		gotoxy(i,5);
		cprintf(" ");
		gotoxy(i,24);
		cprintf(" ");
	}
	for(i=1;i<=24;i++)
	{
		gotoxy(1,i);
		cprintf("  ");
		gotoxy(79,i);
		cprintf("  ");
	}
	gotoxy(14,3);
	cprintf(" S T U D E N T   E X A M I N A T I O N   H S C ( Sci ) ");
	gotoxy(68,24);
	cprintf("%c> RATHOD JAY",240);
	textbackground(0);
	textcolor(7);
}

void Home_Page()

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Select Designation =>",254);
	gotoxy(9,9);
	printf("1%c Student",175);
	gotoxy(9,10);
	printf("2%c Teacher",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",254);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Student_Page();
			break;
		}
		case '2':
		{
			Teacher_Page();
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Home_Page();
		}
	}
}

void Student_Page()

{
	char filep[10],filen[10],rollno[3];
	int rn,student,j,k;
	FILE *fp;
	Clear_Internal_Screen();
	fp=fopen("STUDENT.txt","r");
	fscanf(fp,"%d",&student);
	fclose(fp);
	gotoxy(7,7);
	printf("%c Student =>",254);
	gotoxy(9,9);
	printf("Enter Roll No : ");
	scanf("%d",&rn);
	if(rn>student)
	{
		Clear_Internal_Screen();
		gotoxy(9,7);
		printf("Enter Valid Roll No !!");
		getch();
		Student_Page();
	}
	else
	{
		if(rn<10)
		{
			j=rn;
			filen[0]='0';
			filen[1]=48+j;
			filen[2]='\0';
		}
		else
		{
			j=rn;
			k=j%10;
			j=j/10;
			filen[0]=48+j;
			filen[1]=48+k;
			filen[2]='\0';
		}
		strcpy(rollno,filen);
		strcpy(filep,filen);
		strcat(filen,".txt");
		strcat(filep,"_PW.txt");
	}
	fp=fopen(filep,"r");
	if(fp==NULL)
	{
		Student_Registration(filep,filen,rollno);
	}
	else
	{
		Student_Login(filep,filen,rollno);
	}
	fclose(fp);
}

void Teacher_Page()

{
	char choice,filep[10],filen[10];
	FILE *fp;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Teacher => ",254);
	gotoxy(9,9);
	printf("%c Select Subject :",175);
	gotoxy(11,11);
	printf("1%c Maths",175);
	gotoxy(11,12);
	printf("2%c Physics",175);
	gotoxy(11,13);
	printf("3%c Chemistry",175);
	gotoxy(11,22);
	printf("%c Enter Option : ",254);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			strcpy(filen,"MA_DE.txt");
			strcpy(filep,"MA_PW.txt");
			break;
		}
		case '2':
		{
			strcpy(filen,"PH_DE.txt");
			strcpy(filep,"PH_PW.txt");
			break;
		}
		case '3':
		{
			strcpy(filen,"CH_DE.txt");
			strcpy(filep,"CH_PW.txt");
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Teacher_Page();
		}
	}
	fp=fopen(filep,"r");
	if(fp==NULL)
	{
		Teacher_Registration(filep,filen,choice);
	}
	else
	{
		Teacher_Login(filep,filen,choice);
	}
	fclose(fp);
}

void Student_Registration(char filep[],char filen[],char rollno[])

{
	FILE *fp;
	int i=0;
	char ch,name[30],password[21];
	Clear_Internal_Screen();
	fp=fopen(filen,"r");
	fscanf(fp,"%[^\n]",name);
	fclose(fp);
	gotoxy(7,7);
	printf("%c %s => Registration =>",254,name);
	gotoxy(9,9);
	printf("%c Roll No : %s",175,rollno);
	gotoxy(39,22);
	printf("(Password should less than 20 character)");
	gotoxy(9,11);
	printf("%c Password : ",175);
	fflush(stdin);
	while((ch=getch())!='\r' && i<20)
	{
		printf("*");
		password[i]=ch;
		i++;
	}
	password[i]='\0';
	fp=fopen(filep,"w");
	fprintf(fp,"%s",password);
	fclose(fp);
	Clear_Internal_Screen();
	gotoxy(9,7);
	printf("%s Your Registration Is Done Successfully",name);
	getch();
	Student_Home_Page(name,rollno);
}

void Student_Login(char filep[],char filen[],char rollno[])

{
	FILE *fp;
	int i=0;
	char name[30],filename[10],ch,password_written[21],password_file[21];
	Clear_Internal_Screen();
	gotoxy(7,7);
	fp=fopen(filen,"r");
	fscanf(fp,"%[^\n]",name);
	fclose(fp);
	fp=fopen(filep,"r");
	fscanf(fp,"%s",password_file);
	fclose(fp);
	printf("%c %s => Login =>",254,name);
	gotoxy(9,9);
	printf("%c Roll No : %s",175,rollno);
	gotoxy(9,11);
	printf("%c Password : ",175);
	while((ch=getch())!='\r')
	{
		printf("*");
		password_written[i]=ch;
		i++;
	}
	password_written[i]='\0';
	if(strcmp(password_written,password_file))
	{
		Clear_Internal_Screen();
		gotoxy(9,11);
		printf("!! Error Password Did Not Match\n\t!! Reenter Password");
		getch();
		Student_Login(filep,filen,rollno);
	}
	Student_Home_Page(name,rollno);
}

void Teacher_Registration(char filep[],char filen[],char option)

{
	FILE *fp;
	int i=0;
	char ch,name[30],password[21];
	Clear_Internal_Screen();
	fp=fopen(filen,"r");
	fscanf(fp,"%[^\n]",name);
	fclose(fp);
	gotoxy(7,7);
	printf("%c %s => Registration =>",254,name);
	gotoxy(9,9);
	printf("%c Subject : ",175);
	switch(option)
	{
		case '1':
		{
			printf("Maths");
			break;
		}
		case '2':
		{
			printf("Physics");
			break;
		}
		case '3':
		{
			printf("Chemistry");
			break;
		}
	}
	gotoxy(39,22);
	printf("(Password should less than 20 character)");
	gotoxy(9,11);
	printf("%c Password : ",175);
	fflush(stdin);
	while((ch=getch())!='\r' && i<20)
	{
		printf("*");
		password[i]=ch;
		i++;
	}
	password[i]='\0';
	fp=fopen(filep,"w");
	fprintf(fp,"%s",password);
	fclose(fp);
	Clear_Internal_Screen();
	gotoxy(9,7);
	printf("%s Your Registration Is Done Successfully",name);
	getch();
	Teacher_Home_Page(name,option);
}

void Teacher_Login(char filep[],char filen[],char option)

{
	FILE *fp;
	int i=0;
	char name[30],filename[10],ch,password_written[21],password_file[21];
	Clear_Internal_Screen();
	gotoxy(7,7);
	fp=fopen(filen,"r");
	fscanf(fp,"%[^\n]",name);
	fclose(fp);
	fp=fopen(filep,"r");
	fscanf(fp,"%s",password_file);
	fclose(fp);
	printf("%c %s => Login =>",254,name);
	gotoxy(9,9);
	printf("%c Subject : ",175);
	switch(option)
	{
		case '1':
		{
			printf("Maths");
			break;
		}
		case '2':
		{
			printf("Physics");
			break;
		}
		case '3':
		{
			printf("Chemistry");
			break;
		}
	}
	gotoxy(9,11);
	printf("%c Password : ",175);
	while((ch=getch())!='\r')
	{
		printf("*");
		password_written[i]=ch;
		i++;
	}
	password_written[i]='\0';
	if(strcmp(password_written,password_file))
	{
		Clear_Internal_Screen();
		gotoxy(9,11);
		printf("!! Error Password Did Not Match\n\t!! Reenter Password");
		getch();
		Teacher_Login(filep,filen,option);
	}
	Teacher_Home_Page(name,option);
}

void Student_Home_Page(char name[],char rollno[])

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s =>",254,name);
	gotoxy(9,9);
	printf("1%c Exam",175);
	gotoxy(9,10);
	printf("2%c Result",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",254);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Student_Exam(name,rollno);
			break;
		}
		case '2':
		{
			Student_Result(name,rollno);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Student_Home_Page(name,rollno);
		}
	}
}

void Teacher_Home_Page(char name[],char option)

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s =>",254,name);
	gotoxy(9,9);
	printf("1%c Question Paper",175);
	gotoxy(9,10);
	printf("2%c Result",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",254);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Teacher_Question_Paper(name,option);
			break;
		}
		case '2':
		{
			Teacher_Result(name,option);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Teacher_Home_Page(name,option);
		}
	}
}

void Student_Exam(char name[],char rollno[])

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Exam =>",254,name);
	gotoxy(9,9);
	printf("%c Select Subject :",175);
	gotoxy(11,11);
	printf("1%c Maths",175);
	gotoxy(11,12);
	printf("2%c Physics",175);
	gotoxy(11,13);
	printf("3%c Chemistry",175);
	gotoxy(11,22);
	printf("%c Enter Option : ",254);
	choice=getche();
	switch(choice)
	{
		case '1':
		case '2':
		case '3':
		{
			Student_Exam_Subject(name,rollno,choice);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Student_Exam(name,rollno);
		}
	}
}

void Student_Result(char name[],char rollno[])

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Result =>",254,name);
	gotoxy(9,9);
	printf("%c Select Subject :",175);
	gotoxy(11,11);
	printf("1%c Maths",175);
	gotoxy(11,12);
	printf("2%c Physics",175);
	gotoxy(11,13);
	printf("3%c Chemistry",175);
	gotoxy(11,14);
	printf("4%c All Subject",175);
	gotoxy(11,22);
	printf("%c Enter Option : ",254);
	choice=getche();
	switch(choice)
	{
		case '1':
		case '2':
		case '3':
		{
			Student_Result_Subject(name,rollno,choice);
			break;
		}
		case '4':
		{
			Student_Result_All(name,rollno);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Student_Result(name,rollno);
		}
	}
}

void Teacher_Question_Paper(char name[],char option)

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s =>Question Paper =>",254,name);
	gotoxy(9,9);
	printf("1%c Set Question Paper",175);
	gotoxy(9,10);
	printf("2%c View Question Paper",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Teacher_Set_Question_Paper(name,option);
			break;
		}
		case '2':
		{
			Teacher_View_Question_Paper(name,option);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Teacher_Question_Paper(name,option);
		}
	}
}

void Teacher_Result(char name[30],char option)

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s =>Result =>",254,name);
	gotoxy(9,9);
	printf("1%c Student's Result",175);
	gotoxy(9,10);
	printf("2%c Class's Result",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Teacher_Result_Student(name,option);
			break;
		}
		case '2':
		{
			Teacher_Result_Class(name,option);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Teacher_Result(name,option);
		}
	}
}

void Student_Exam_Subject(char name[],char rollno[],char choice)

{
	FILE *f1,*f2;
	char ans,file[10];
	struct Question_Paper Q[50];
	int i,j,res=0,temp;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Exam =>",254,name);
	strcpy(file,rollno);
	switch(choice)
	{
		case '1':
		{
			printf(" Maths =>");
			strcat(file,"_RM.txt");
			f1=fopen("MA_QP.txt","r");
			f2=fopen(file,"r");
			break;
		}
		case '2':
		{
			printf(" Physics =>");
			strcat(file,"_RP.txt");
			f1=fopen("PH_QP.txt","r");
			f2=fopen(file,"r");
			break;
		}
		case '3':
		{
			printf(" Chemistry =>");
			strcat(file,"_RC.txt");
			f1=fopen("CH_QP.txt","r");
			f2=fopen(file,"r");
			break;
		}
	}
	if(f1==NULL)
	{
		gotoxy(9,9);
		printf("Question Paper is Not Created Yet !!");
		getch();
		Student_Last_Page(name,rollno);
	}
	else if(f2==NULL)
	{
		fclose(f2);
		gotoxy(9,9);
		printf("Tap To Begin Exam : ");
		Clear_Internal_Screen();
		for(i=0;i<50;i++)
		{
			fscanf(f1,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%c\n",Q[i].question,Q[i].option1,Q[i].option2,Q[i].option3,Q[i].option4,&Q[i].ans);
		}
		for(i=0;i<50;i++)
		{
			gotoxy(7,7);
			printf("%c Question %d out of 50 =>",254,i+1);
			gotoxy(9,8);
			temp=8;
			for(j=0;j<strlen(Q[i].question);j++)
			{
				printf("%c",Q[i].question[j]);
				if((j+1)%64==0)
				{
					gotoxy(9,++temp);
				}
			}
			gotoxy(7,12);
			printf("%c Option A : %s",254,Q[i].option1);
			gotoxy(7,14);
			printf("%c Option B : %s",254,Q[i].option2);
			gotoxy(7,16);
			printf("%c Option C : %s",254,Q[i].option3);
			gotoxy(7,18);
			printf("%c Option D : %s",254,Q[i].option4);
			top:
			gotoxy(68,22);
			printf("(A/B/C/D)");
			gotoxy(7,20);
			printf("%c Enter Option : ",254);
			gotoxy(24,20);
			ans=toupper(getche());
			if(ans!='A' && ans!='B' && ans!='C' && ans!='D')
			{
				Clear_Line(22);
				gotoxy(7,22);
				printf("!! Please Enter Valid Option");
				getch();
				Clear_Line(20);
				Clear_Line(22);
				goto top;
			}
			Clear_Line(22);
			gotoxy(7,22);
			if(ans==Q[i].ans)
			{
				printf("Correct Answer");
				res++;
			}
			else
			{
				printf("Wrong Answer\tCorrect Answer = %c",Q[i].ans);
			}
			getch();
			Clear_Internal_Screen();
		}
		f2=fopen(file,"w");
		fprintf(f2,"%d",res);
		gotoxy(9,9);
		printf("Your Exam is Completed.\n\tTap To Check Result :");
		getch();
	}
	else
	{
		gotoxy(9,9);
		printf("!! Your Have Already Appeared Exam.\n\t!! Tap To Check Result :");
		getch();
	}
	fclose(f1);
	fclose(f2);
	Student_Result_Subject(name,rollno,choice);
}

void Student_Result_Subject(char name[],char rollno[],char choice)

{
	int res;
	FILE *fp;
	char file[10];
	Clear_Internal_Screen();
	strcpy(file,rollno);
	gotoxy(7,7);
	printf("%c %s => Result => ",254);
	switch(choice)
	{
		case '1':
		{
			printf("Maths=>");
			strcat(file,"_RM.txt");
			break;
		}
		case '2':
		{
			printf("Physics=>");
			strcat(file,"_RP.txt");
			break;
		}
		case '3':
		{
			printf("Chemistry =>");
			strcat(file,"_RC.txt");
			break;
		}
	}
	fp=fopen(file,"r");
	gotoxy(9,9);
	if(fp==NULL)
	{
		printf("You Haven't Appeared Exam !!");
	}
	else
	{

		fscanf(fp,"%d",&res);
		printf("Result : %d / 50",res);
	}
	fclose(fp);
	getch();
	Student_Last_Page(name,rollno);
}

void Student_Result_All(char name[],char rollno[])

{
	FILE *fp;
	int resm,resp,resc;
	char file[10];
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Result => All Subject =>",254,name);
	gotoxy(9,9);
	printf("%c Maths : ",175);
	strcpy(file,rollno);
	strcat(file,"_RM.txt");
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("Haven't Appeared!!");
	}
	else
	{
		fscanf(fp,"%d",&resm);
		printf("%d / 50",resm);
	}
	fclose(fp);
	gotoxy(9,11);
	printf("%c Physics : ",175);
	strcpy(file,rollno);
	strcat(file,"_RP.txt");
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("Haven't Appeared!!");
	}
	else
	{
		fscanf(fp,"%d",&resp);
		printf("%d / 50",resp);
	}
	fclose(fp);
	gotoxy(9,13);
	printf("%c Chemistry : ",175);
	strcpy(file,rollno);
	strcat(file,"_RC.txt");
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("Haven't Appeared!!");
	}
	else
	{
		fscanf(fp,"%d",&resc);
		printf("%d / 50",resc);
	}
	getch();
	Student_Last_Page(name,rollno);
}

void Teacher_Set_Question_Paper(char name[],char option)

{
	struct Question_Paper Q[50];
	char ch;
	FILE *fp;
	int i,j,temp;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Question Paper => Set =>",254,name);
	gotoxy(9,9);
	printf("Tap To Set Question Paper :");
	getch();
	for(i=0;i<50;i++)
	{
		Clear_Internal_Screen();
		gotoxy(7,7);
		printf("%c Question %d out of 50 :",254,i+1);
		gotoxy(7,9);
		printf("%c Enter Question =>",254);
		gotoxy(7,14);
		printf("%c Option A : ",254);
		gotoxy(7,16);
		printf("%c Option B : ",254);
		gotoxy(7,18);
		printf("%c Option C : ",254);
		gotoxy(7,20);
		printf("%c Option D : ",254);
		gotoxy(7,22);
		printf("%c Correct Option : ",254);
		gotoxy(9,10);
		temp=10;
		j=0;
		fflush(stdin);
		while((ch=getche())!='\r')
		{
			Q[i].question[j]=ch;
			j++;
			if(j%64==0)
			{
				gotoxy(9,++temp);
			}
		}
		Q[i].question[j]='\0';
		gotoxy(20,14);
		fflush(stdin);
		gets(Q[i].option1);
		gotoxy(20,16);
		fflush(stdin);
		gets(Q[i].option2);
		gotoxy(20,18);
		fflush(stdin);
		gets(Q[i].option3);
		gotoxy(20,20);
		fflush(stdin);
		gets(Q[i].option4);
		gotoxy(68,22);
		printf("(A/B/C/D)");
		gotoxy(26,22);
		fflush(stdin);
		Q[i].ans=toupper(getchar());
	}
	switch(option)
	{
		case '1':
		{
			fp=fopen("MA_QP.txt","w");
			break;
		}
		case '2':
		{
			fp=fopen("PH_QP.txt","w");
			break;
		}
		case '3':
		{
			fp=fopen("CH_QP.txt","w");
			break;
		}
	}
	for(i=0;i<50;i++)
	{
		fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%c\n",Q[i].question,Q[i].option1,Q[i].option2,Q[i].option3,Q[i].option4,Q[i].ans);
	}
	Clear_Internal_Screen();
	gotoxy(9,9);
	printf("Question Paper Saved Successfully");
	getch();
	fclose(fp);
	Teacher_Last_Page(name,option);
}

void Teacher_View_Question_Paper(char name[],char option)


{
	struct Question_Paper Q[50];
	FILE *fp;
	int i,j,temp;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Question Paper => View =>",254,name);
	gotoxy(9,9);
	switch(option)
	{
		case '1':
		{
			fp=fopen("MA_QP.txt","r");
			break;
		}
		case '2':
		{
			fp=fopen("PH_QP.txt","r");
			break;
		}
		case '3':
		{
			fp=fopen("CH_QP.txt","r");
			break;
		}
	}
        if(fp==NULL)
        {
                printf("You Haven't Set Question Paper Yet!!\n\tTap To Set Question Paper : ");
                getch();
                Teacher_Set_Question_Paper(name,option);
        }
        else
        {
            printf("Tap to View Question Paper");
            getch();
        }
	for(i=0;i<50;i++)
	{
		fscanf(fp,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%c\n",Q[i].question,Q[i].option1,Q[i].option2,Q[i].option3,Q[i].option4,&Q[i].ans);
	}
	for(i=0;i<50;i++)
	{
		Clear_Internal_Screen();
		gotoxy(7,7);
		printf("%c Question %d out of 50 :",254,i+1);
		gotoxy(7,9);
		printf("%c Enter Question =>",254);
		gotoxy(9,10);
		temp=10;
		for(j=0;j<strlen(Q[i].question);j++)
		{
			printf("%c",Q[i].question[j]);
			if((j+1)%64==0)
			{
				gotoxy(9,++temp);
			}
		}
		gotoxy(7,14);
		printf("%c Option A : %s",254,Q[i].option1);
		gotoxy(7,16);
		printf("%c Option B : %s",254,Q[i].option2);
		gotoxy(7,18);
		printf("%c Option C : %s",254,Q[i].option3);
		gotoxy(7,20);
		printf("%c Option D : %s",254,Q[i].option4);
		gotoxy(7,22);
		printf("%c Correct Option : %c",254,Q[i].ans);
		getch();
	}
	fclose(fp);
	Clear_Internal_Screen();
	gotoxy(9,9);
	printf("Question Paper is Completed");
	Teacher_Last_Page(name,option);
}

void Teacher_Result_Student(char name[],char option)

{
	FILE *fp;
	int res,rn,student,j,k;
	char rollno[3],file[10];
	Clear_Internal_Screen();
	fp=fopen("STUDENT.txt","r");
	fscanf(fp,"%d",&student);
	fclose(fp);
	gotoxy(7,7);
	printf("%c %s => Result => Student =>",254,name);
	gotoxy(9,9);
	printf("%c Roll No : ",175);
	scanf("%d",&rn);
	if(rn>student)
	{
		Clear_Internal_Screen();
		gotoxy(9,7);
		printf("Enter Valid Roll No !!");
		getch();
		Teacher_Result_Student(name,option);
	}
	else
	{
		if(rn<10)
		{
			j=rn;
			rollno[0]='0';
			rollno[1]=48+j;
			rollno[2]='\0';
		}
		else
		{
			j=rn;
			k=j%10;
			j=j/10;
			rollno[0]=48+j;
			rollno[1]=48+k;
			rollno[2]='\0';
		}
	}
	strcpy(file,rollno);
	switch(option)
	{
		case '1':
		{
			strcat(file,"_RM.txt");
			break;
		}
		case '2':
		{
			strcat(file,"_RP.txt");
			break;
		}
		case '3':
		{
			strcat(file,"_RC.txt");
			break;
		}
	}
	gotoxy(9,11);
	printf("Result = ");
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("Haven't Appeared !!");
	}
	else
	{
		fscanf(fp,"%d",&res);
		printf("%d / 50",res);
	}
	fclose(fp);
	getch();
	Teacher_Last_Page(name,option);
}

void Teacher_Result_Class(char name[],char option)

{
	FILE *fp;
	int res,i,j,k,l,rn=1,student;
	char rollno[3],file[10];
	Clear_Internal_Screen();
	fp=fopen("STUDENT.txt","r");
	fscanf(fp,"%d",&student);
	fclose(fp);
	gotoxy(7,7);
	printf("%c %s => Result => Class =>",254,name);
	gotoxy(9,9);
	printf("Tap To View Results");
	getch();
	for(i=1;i<=((student-1)/10)+1;i++)
	{
		Clear_Internal_Screen();
		gotoxy(7,7);
		printf("%c %s => Result => Class =>");
		gotoxy(9,9);
		printf("Roll No");
		gotoxy(20,9);
		printf("Result");
		for(l=1;(l<=10 && rn<=student);l++)
		{
			if(rn<10)
			{
				j=rn;
				rollno[0]='0';
				rollno[1]=48+j;
				rollno[2]='\0';
			}
			else
			{
				j=rn;
				k=j%10;
				j=j/10;
				rollno[0]=48+j;
				rollno[1]=48+k;
				rollno[2]='\0';
			}
			rn++;
			strcpy(file,rollno);
			switch(option)
			{
				case '1':
				{
					strcat(file,"_RM.txt");
					break;
				}
				case '2':
				{
					strcat(file,"_RP.txt");
					break;
				}
				case '3':
				{
					strcat(file,"_RC.txt");
					break;
				}
			}
			gotoxy(9,l+10);
			printf("%s",rollno);
			gotoxy(20,l+10);
			fp=fopen(file,"r");
			if(fp==NULL)
			{
				printf("Haven't Appeared");
			}
			else
			{
				fscanf(fp,"%d",&res);
				printf("%d",res);
			}
			fclose(fp);
		}
		gotoxy(9,22);
		printf("Tap For Jump To Next Page :");
		fflush(stdin);
		getch();
	}
	Teacher_Last_Page(name,option);
}

void Student_Last_Page(char name[],char rollno[])

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Last Page =>",254,name);
	gotoxy(9,9);
	printf("1%c Home Page",175);
	gotoxy(9,10);
	printf("2%c Exit",175);
	gotoxy(9,22);
	printf("%c Enter Choice : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Student_Home_Page(name,rollno);
			break;
		}
		case '2':
		{
			Clear_Screen();
			exit(0);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Student_Last_Page(name,rollno);
		}
	}
}

void Teacher_Last_Page(char name[],char option)

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c %s => Last Page =>",254,name);
	gotoxy(9,9);
	printf("1%c Home Page",175);
	gotoxy(9,10);
	printf("2%c Exit",175);
	gotoxy(9,22);
	printf("%c Enter Choice : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Teacher_Home_Page(name,option);
			break;
		}
		case '2':
		{
			Clear_Screen();
			exit(0);
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Teacher_Last_Page(name,option);
		}
	}
}

//End Of The Project Name Examination

