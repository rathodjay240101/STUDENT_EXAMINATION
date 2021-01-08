#include<stdio.h>
#include<conio.h>
#include<string.h>

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

void Last_Page()

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("Last Page =>",254);
	gotoxy(9,9);
	printf("1%c Home Page",175);
	gotoxy(9,10);
	printf("2%c Exit",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			main();
			break;
		}
		case '2':
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Exit Successfully");
			getch();
			Clear_Screen();
			exit(0);
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,9);
			printf("Please Enter Valid Option !!");
			getch();
			Last_Page();
		}
	}
}

Teacher_Modify_Details()

{
	FILE *fp;
	char choice,oldname[30],newname[30];
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Teacher Details => Modify Details =>",254);
	gotoxy(9,9);
	printf("%c Select Subject :",175);
	gotoxy(11,11);
	printf("1%c Maths",175);
	gotoxy(11,12);
	printf("2%c Physics",175);
	gotoxy(11,13);
	printf("3%c Chemistry",175);
	gotoxy(11,22);
	printf("%c Enter Option : ",175);
	choice=getche();
	Clear_Internal_Screen();
	switch(choice)
	{
		case '1':
		{
			gotoxy(7,7);
			printf("%c Teacher Details => Modify Details =>",254);
			gotoxy(9,9);
			printf("%c Subject : Maths",175);
			fp=fopen("MA_DE.txt","r");
			fscanf(fp,"%[^\n]",oldname);
			fclose(fp);
			gotoxy(9,11);
			printf("%c Old Name : %s",175,oldname);
			gotoxy(9,13);
			printf("%c New Name : ",175);
			gets(newname);
			fp=fopen("MA_DE.txt","w");
			fprintf(fp,"%s",newname);
			break;
		}
		case '2':
		{
			gotoxy(7,7);
			printf("%c Teacher Details => Modify Details =>",254);
			gotoxy(9,9);
			printf("%c Subject : Physics",175);
			fp=fopen("PH_DE.txt","r");
			fscanf(fp,"%[^\n]",oldname);
			fclose(fp);
			gotoxy(9,11);
			printf("%c Old Name : %s",175,oldname);
			gotoxy(9,13);
			printf("%c New Name : ",175);
			gets(newname);
			fp=fopen("PH_DE.txt","w");
			fprintf(fp,"%s",newname);
			break;
		}
		case '3':
		{
			gotoxy(7,7);
			printf("%c Teacher Details => Modify Details =>",254);
			gotoxy(9,9);
			printf("%c Subject : Chemistry",175);
			fp=fopen("CH_DE.txt","r");
			fscanf(fp,"%[^\n]",oldname);
			fclose(fp);
			gotoxy(9,11);
			printf("%c Old Name : %s",175,oldname);
			gotoxy(9,13);
			printf("%c New Name : ",175);
			gets(newname);
			fp=fopen("CH_DE.txt","w");
			fprintf(fp,"%s",newname);
			break;
		}
		default:
		{
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Teacher_Modify_Details();
		}
	}
	Clear_Internal_Screen();
	gotoxy(9,7);
	printf("Modification Successfully Completed");
	getch();
	Last_Page();
}

Teacher_Enter_Details()

{
	FILE *fp;
	char mname[30],pname[30],cname[30];
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Teacher Details => Enter Details =>",254);
	gotoxy(9,9);
	printf("%c Subject : Maths",175);
	gotoxy(9,11);
	printf("%c Name of Faculty : ",175);
	gotoxy(9,13);
	printf("%c Subject : Physics",175);
	gotoxy(9,15);
	printf("%c Name of Faculty : ",175);
	gotoxy(9,17);
	printf("%c Subject : Chemistry",175);
	gotoxy(9,19);
	printf("%c Name of Faculty : ",175);
	gotoxy(29,11);
	gets(mname);
	gotoxy(29,15);
	gets(pname);
	gotoxy(29,19);
	gets(cname);
	fp=fopen("MA_DE.txt","w");
	fprintf(fp,"%s",mname);
	fclose(fp);
	fp=fopen("PH_DE.txt","w");
	fprintf(fp,"%s",pname);
	fclose(fp);
	fp=fopen("CH_DE.txt","w");
	fprintf(fp,"%s",cname);
	fclose(fp);
	Clear_Internal_Screen();
	gotoxy(9,7);
	printf("Teacher Data Stored Successfully");
	getch();
	Last_Page();
}

Student_Modify_Details()

{
	FILE *fp;
	char file[10],oldname[30],newname[30];
	int student,rn,j,k;
	Clear_Internal_Screen();
	fp=fopen("STUDENT.txt","r");
	if(fp==NULL)
	{
		fclose(fp);
		Clear_Internal_Screen();
		gotoxy(9,7);
		printf("You Haven't Entered Data Till Now \n\t\tSo You Can't Modify !!");
		getch();
		Student_Enter_Details();
	}
	else
	{
		fscanf(fp,"%d",&student);
		fclose(fp);
		gotoxy(7,7);
		printf("%c Student Details => Modify Details =>",254);
		gotoxy(9,9);
		printf("%c Roll No of Student : ",175);
		scanf("%d",&rn);
		if(rn>student)
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Enter Valid Roll No !!");
			getch();
			Student_Modify_Details();
		}
		else
		{
			if(rn<10)
			{
				j=rn;
				file[0]='0';
				file[1]=48+j;
				file[2]='\0';
			}
			else
			{
				j=rn;
				k=j%10;
				j=j/10;
				file[0]=48+j;
				file[1]=48+k;
				file[2]='\0';
			}
			strcat(file,".txt");
		}
	}
	fp=fopen(file,"r");
	fscanf(fp,"%[^\n]",oldname);
	fclose(fp);
	gotoxy(9,11);
	printf("%c Old Name : %s",175,oldname);
	gotoxy(9,13);
	fflush(stdin);
	printf("%c New Name : ",175);
	gets(newname);
	fp=fopen(file,"w");
	fprintf(fp,"%s",newname);
	fclose(fp);
	Clear_Internal_Screen();
	gotoxy(9,7);
	printf("Modification Successfully Completed");
	getch();
	Last_Page();
}

Student_Enter_Details()

{
	FILE *fp;
	int student,i,j,k;
	char name[30],file[10];
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Student Details => Enter Details =>",254);
	gotoxy(9,9);
	printf("%c Enter Total Number of Students : ",175);
	scanf("%d",&student);
	for(i=1;i<=student;i++)
	{
		Clear_Internal_Screen();
		gotoxy(7,7);
		printf("%c Student Details => Enter Details =>",254);
		gotoxy(9,9);
		printf("%c Roll No : %d",175,i);
		gotoxy(9,10);
		printf("%c Name : ",175);
		fflush(stdin);
		gets(name);
		if(i<10)
		{
			j=i;
			file[0]='0';
			file[1]=48+j;
			file[2]='\0';
		}
		else
		{
			j=i;
			k=j%10;
			j=j/10;
			file[0]=48+j;
			file[1]=48+k;
			file[2]='\0';
		}
		strcat(file,".txt");
		fp=fopen(file,"w");
		fprintf(fp,"%s",name);
		fclose(fp);
	}
	fp=fopen("STUDENT.txt","w");
    fprintf(fp,"%d",student);
	fclose(fp);
	Clear_Internal_Screen();
	gotoxy(9,7);
	printf("Student Data Stored Successfully");
	getch();
	Last_Page();
}

Teacher_Details()

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Teacher Details =>",254);
	gotoxy(9,9);
	printf("1%cEnter Details :",175);
	gotoxy(9,10);
	printf("2%cModify Details :",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Teacher_Enter_Details();
			break;
		}
		case '2':
		{
			Teacher_Modify_Details();
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Teacher_Details();
		}
	}
}

Student_Details()

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Student Details =>",254);
	gotoxy(9,9);
	printf("1%cEnter Details :",175);
	gotoxy(9,10);
	printf("2%cModify Details :",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Student_Enter_Details();
			break;
		}
		case '2':
		{
			Student_Modify_Details();
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Student_Details();
		}
	}
}

Selection_Page()

{
	char choice;
	Clear_Internal_Screen();
	gotoxy(7,7);
	printf("%c Home Page =>",254);
	gotoxy(9,9);
	printf("1%cStudent Details :",175);
	gotoxy(9,10);
	printf("2%cTeacher Details :",175);
	gotoxy(9,22);
	printf("%c Enter Option : ",175);
	choice=getche();
	switch(choice)
	{
		case '1':
		{
			Student_Details();
			break;
		}
		case '2':
		{
			Teacher_Details();
			break;
		}
		default:
		{
			Clear_Internal_Screen();
			gotoxy(9,7);
			printf("Please Enter Valid Option !!");
			getch();
			Selection_Page();
		}
	}
}

Home_Page()

{
	gotoxy(7,7);
	printf("THIS FILE IS TO MANAGE DETAILS OF STUDENTS AND FACULTIES =>");
	getch();
	Selection_Page();
}

main()

{
	clrscr();
	Clear_Screen();
	Heading();
	Home_Page();
	getch();
}

//End of Project Managment
