#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct studentinfo{
        char name[50];
        char id[50];
        char phone[16];
        char email[500];
        char address[100];
        int attendance;
        int absent;


};
int main(){
    system("color 1a");
    welcome();

    ExitProject();

    return 0;
}
  // welcome Function Start here.

  welcome(){
      char username[50];
      char userpassword[50];
      char user[50]="admin";
      char password[50]="admin";

      printf("\n\n\n\n\n\n");
      printf("                                      |=========================================================|\n");
      printf("                                      |         Please, Enter your username & password          |\n");
      printf("                                      |                    For Login Our System                 |\n");
      printf("                                      |=========================================================|\n");
      printf("\n\n");

      for(int i=1; i>0; i++){
            printf("                                                       UserName : ");
            gets(username);
            printf("                                                       Password : ");
            int index = 0;
        while (1) {
            char c = _getch();
            if (c == '\r') {
                break;
            } else if (c == '\b' && index > 0) {
                index--;
                printf("\b \b");
            } else {
                userpassword[index++] = c;
                printf("*");
            }
        }





      if(strcmp(username, user)==0){
            if(strcmp(userpassword, password)==0){
                system("cls");
                mainpage();
                break;
            }
            else{
                printf("\n\n                                                       Please, Enter currect username & password.\n");
            }

      }

        else{
                printf("\n\n                                                       Please, Enter currect username & password.\n");

      }

  } }
  // Welcome Function End here.


  // Main Page Function Start here.
  // Main Page Function Start here.
  mainpage(){
      printf("\n\n\n\n\n\n");
      printf("                                      |=========================================================|\n");
      printf("                                      |           Welcome to Our Management Software            |\n");
      printf("                                      |=========================================================|\n");
      printf("\n\n");
      printf("                                                 ********   Choose Your Number   ********\n");
      printf("                                                       [1]= Add a New Student. \n");
      printf("                                                       [2]= Show all Student. \n");
      printf("                                                       [3]= Edit Students. \n");
      printf("                                                       [4]= Delete Student. \n");
      printf("                                                       [5]= Taking Attendance. \n");
      printf("                                                       [6]= Check attendance.\n");
      printf("                                                       [7]= Change attendance.\n");
      printf("                                                       [8]= About Us. \n");
      printf("                                                       [0]= Exit the Program. \n");


      char reg[30];
      for(int i=1; i>0; i++){
            printf("                                             Your Choose :  ");
      gets(reg);
      if(strcmp(reg, "1")==0){
            system("cls");
            addstudent();
        break;
      }
      else if(strcmp(reg, "2")==0){
            system("cls");
            allstudent();
            break;
      }
      else if(strcmp(reg, "3")==0){
            system("cls");
            editstudent();
            break;
      }
      else if(strcmp(reg, "4")==0){
            system("cls");
            deletestudent();
            break;
      }
      else if(strcmp(reg, "5")==0){
            system("cls");
            takingattendance();
            break;
      }
      else if(strcmp(reg, "6")==0){
            system("cls");
            checkattendance();
            break;
      }
      else if(strcmp(reg, "7")==0){
            system("cls");
            editattendance();
            break;

      }
      else if(strcmp(reg, "8")==0){
            system("cls");
            about();
            break;
      }
      else if(strcmp(reg, "0")==0){
            system("cls");
            break;
      }
        else{
            printf("                                                       Please, Input correct number.\n");


        }
      }

  }

    // Main page Function End here.
    // back page Function start here.
    void backpage(){
        printf("\n\n");
      printf("                                                 ********   Choose Your Number   ********\n");
      printf("                                                       [b]= Back? \n");
      printf("                                                       [0]= Exit. \n\n");
      char reg[30];
      for(int i=1; i>0; i++){
            printf("                                             Your Choose :  ");
      gets(reg);
      if(strcmp(reg, "b")==0){
            system("cls");
            mainpage();

        break;
      }
      else if(strcmp(reg, "0")==0){
            system("cls");
            break;
      }
        else{
            printf("                                                       Please, Input correct number.\n");


        }
      }

    }
    //back page function end here.

    //add student page function start here
    void addstudent(){
        printf("\n\n\n");
         printf("                                      |=========================================================|\n");
         printf("                                      |                      Add A New Student                  |\n");
         printf("                                      |=========================================================|\n");
         printf("\n\n");


        FILE *sfile;
        struct studentinfo std;


        sfile = fopen("studentList.txt","ab+");
        if(sfile == NULL){
        printf("Error opening file\n");
        backpage();
        }

        printf("                                                  <--:ADD RECORD:-->\n");
        printf("                                               Enter details of student.\n");

         printf("\n\n                                                  Name : ");
         gets(std.name);
         printf("\n                                            Student ID : ");
         gets(std.id);
         printf("\n                                          Phone Number : ");
         gets(std.phone);
         printf("\n                                         Email Address : ");
         gets(std.email);
         printf("\n                                               Address : ");
         gets(std.address);
         system("cls");
         printf("\n\n\n                                        Successfully Added");
         printf("\n                                                  Name : %s", std.name);
         printf("\n                                                    ID : %s", std.id);
         printf("\n                                                 Email : %s", std.email);
         printf("\n                                                 Phone : %s", std.phone);
         printf("\n                                               Address : %s", std.address);
         printf("\n\n\n");



        fwrite(&std,sizeof(std),1,sfile);
        //fprintf(sfile, %s %s %s %s %s, std.name, std.phone, std.id, std.email, std.address);
        fclose(sfile);



         backpage();

    }

    //add student page function end here.

    //Show all student function start here

    void allstudent(){
        printf("\n\n\n");
         printf("                                      |=========================================================|\n");
         printf("                                      |                      Show All Student                   |\n");
         printf("                                      |=========================================================|\n");
         printf("\n\n");

         struct studentinfo std;
         FILE *sfile;
         int i=1,j;
        sc(10,0);
        printf("S.No   Name of Student       Mobile No         Student Id         Email                          Address\n");
        sc(10,0);
        printf("---------------------------------------------------------------------------------------------------------------\n");
        sfile = fopen("studentList.txt","rb+");

        if(sfile == NULL){
        printf("Error opening file.");
        backpage();
        }

        while(fread(&std,sizeof(std),1,sfile) == 1){
        sc(10, 0);
        printf("%-7d%-21s %-17s %-18s %-30s %-25s",i,std.name,std.phone,std.id,std.email,std.address);
        printf("\n");
        i++;

    }
    fclose(sfile);

         backpage();

    }

    //Show all student function end here.

    //Edit student information function start here
    void editstudent() {
    printf("\n\n\n");
    printf("                                      |=========================================================|\n");
    printf("                                      |                 Edit Student Information                |\n");
    printf("                                      |=========================================================|\n");
    printf("\n\n");

    FILE *sfile, *tempfile;
    struct studentinfo std;
    int found = 0;
    char editId[50];

    sc(40,2);
    printf("Enter the student ID to edit: ");
    gets(editId);

    sfile = fopen("studentList.txt", "rb");
    tempfile = fopen("tempfile.txt", "wb");

    if (sfile == NULL || tempfile == NULL) {
        printf("Error opening files.\n");

        fclose(sfile);
        fclose(tempfile);
        backpage();
    }

    while (fread(&std, sizeof(std), 1, sfile) == 1) {
        if (strcmp(std.id, editId) == 0) {

         printf("                                                  <--:Edit RECORD:-->\n");
         printf("                                               Enter New details of student.\n");
         printf("\n\n                                                  Name : ");
         gets(std.name);
         printf("\n                                          Phone Number : ");
         gets(std.phone);
         printf("\n                                         Email Address : ");
         gets(std.email);
         printf("\n                                               Address : ");
         gets(std.address);
            found = 1;
        }
        fwrite(&std, sizeof(std), 1, tempfile);
    }

    fclose(sfile);
    fclose(tempfile);

    if (found) {
        remove("studentList.txt");
        rename("tempfile.txt", "studentList.txt");
        sc(40, 2);
        printf("Student with ID %s has been edited.\n", editId);
        sc(40, 2);
        printf("      >>>>>  Successfully Edited  <<<<<   ");
    } else {
        sc(40, 2);
        printf("      >>>>>  Sorry  <<<<<   ");
        sc(40, 2);
        printf("Student ID '%s' not found.\n", editId);
        remove("tempfile.txt");
    }

    backpage();
}


    //Edit Student information function end here.
    //Delete student function start here
    void deletestudent(){
        printf("\n\n\n");
         printf("                                      |=========================================================|\n");
         printf("                                      |                Delete Student From Database             |\n");
         printf("                                      |=========================================================|\n");
         printf("\n\n");

 FILE *sfile, *tempfile;
    struct studentinfo std;
    int found = 0;
    char deleteId[50];
    sc(40, 0);
    printf("You want to delete any Student? \n");
    sc(40, 0);
    printf("Enter the student ID : ");
    gets(deleteId);

    sfile = fopen("studentList.txt", "rb");
    if (sfile == NULL) {
        printf("Error opening file.\n");
        backpage();

    }

    tempfile = fopen("tempfile.txt", "wb");
    if (tempfile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(sfile);
        backpage();

    }

    while (fread(&std, sizeof(std), 1, sfile) == 1) {
        if (strcmp(std.id, deleteId) == 0) {
            found = 1;
            continue;
        }
        fwrite(&std, sizeof(std), 1, tempfile);
    }

    fclose(sfile);
    fclose(tempfile);

    if (found) {
        remove("studentList.txt");
        rename("tempfile.txt", "studentList.txt");
        sc(40,2);
        printf("Student with ID %s has been deleted.\n", deleteId);
    } else {
        sc(40,2);
        printf("      >>>>>  Sorry  <<<<<   ");
        sc(40,2);
        printf("Student ID ' %s ' not found.\n", deleteId);
        remove("tempfile.txt");
    }

    backpage();
}
// Delete student function end here.




    //Taking Student Attendance function start here
 // Taking Student Attendance function
void takingattendance() {
    printf("\n\n\n");
    printf("                                      |=========================================================|\n");
    printf("                                      |                  Taking Student Attendance              |\n");
    printf("                                      |=========================================================|\n");
    printf("\n\n");

    FILE *sfile, *tempfile;
    struct studentinfo std;
    sc(40,0);
    printf("Give Attendance using 'p' or 'a' \n");
    sc(40,2);
    printf("S.L    Name of Student      Student ID        Attendance        \n");
    sc(40,0);
    printf("-------------------------------------------------------------");
    sfile = fopen("studentList.txt", "rb");
    tempfile = fopen("tempfile.txt", "wb");

    if (sfile == NULL || tempfile == NULL) {
        printf("Error opening files.\n");

        fclose(sfile);
        fclose(tempfile);
        backpage();
    }
    int p=0, ab=0, t=0;

    while (fread(&std, sizeof(std), 1, sfile) == 1) {
         t++;
         char atten[15];
         for(int i=0; i<1; i++){
         sc(40,2);
         printf("%-7d%-21s%-18s",t,std.name, std.id);
         scanf("%s", atten);
         if(strcmp(atten, "p") == 0){
            std.attendance++;
            p++;
         }
         else if(strcmp(atten, "a") == 0){
            std.absent++;
            ab++;
         }
         else{
            sc(40,2);
            printf("Please Enter Right Key......... 'p' or 'a' ");
            i--;
         }
         }
        fwrite(&std, sizeof(std), 1, tempfile);
    }

    fclose(sfile);
    fclose(tempfile);


        remove("studentList.txt");
        rename("tempfile.txt", "studentList.txt");
        sc(40, 2);
        printf("   >>>>>  Successfully Completed Your Attendance  <<<<<   \n");
        sc(55,0);
        printf("Today Total Present : %d", p);
        sc(55,1);
        printf("Today Total Absent : %d", ab);
        sc(0,1);
        int i=0;
        backpage();
}



    //Taking Student Attendance  function end here.

    //Check Student Attendance function start here
    void checkattendance(){
         printf("\n\n\n");
         printf("                                      |=========================================================|\n");
         printf("                                      |                  Check Student Attendance               |\n");
         printf("                                      |=========================================================|\n");
         printf("\n\n");

         struct studentinfo std;
         FILE *sfile;
         int i=1;
         sc(10,0);
         printf("S.No   Name of Student        Student Id         Total Class    Present Day    Absent Day    Marks       \n");
         sc(10,0);
         printf("---------------------------------------------------------------------------------------------------------\n");
         sfile = fopen("studentList.txt","rb+");

         if(sfile == NULL){
         printf("Error opening file.");
         backpage();
         }

         while(fread(&std,sizeof(std),1,sfile) == 1){
                if(std.attendance==NULL){
                    std.attendance=0;
                }
                if(std.absent==NULL){
                    std.absent=0;
                }
             int totalclass=std.attendance+std.absent;
             float totalmarks=std.attendance;
             totalmarks/=totalclass;
             totalmarks*=10;
             sc(10, 0);
             printf("%-7d%-23s%-19s%-15d%-15d%-14d%-12.1f",i,std.name,std.id,totalclass,std.attendance,std.absent,totalmarks);
             printf("\n");
             i++;

        }
    fclose(sfile);

         backpage();

    }



    //Check Student Attendance  function end here.
    //edit student attendance function start here.
void editattendance() {
    printf("\n\n\n");
    printf("                                      |=========================================================|\n");
    printf("                                      |                 Change Student Attendance               |\n");
    printf("                                      |=========================================================|\n");
    printf("\n\n");

    FILE *sfile, *tempfile;
    struct studentinfo std;
    int found = 0;
    char editId[50];

    sc(40,2);
    printf("Enter the student ID to Change Attendance: ");
    gets(editId);

    sfile = fopen("studentList.txt", "rb");
    tempfile = fopen("tempfile.txt", "wb");

    if (sfile == NULL || tempfile == NULL) {
        printf("Error opening files.\n");

        fclose(sfile);
        fclose(tempfile);
        backpage();
    }

    while (fread(&std, sizeof(std), 1, sfile) == 1) {
        if (strcmp(std.id, editId) == 0) {

         char atten[15];
         for(int k=0; k<1; k++){
            sc(40,1);
            printf("Give Attendance using 'p' or 'a' \n");
            sc(40,2);
            printf("Name of Student      Student ID        Attendance        \n");
            sc(40,0);
            printf("-----------------------------------------------------");
            sc(40,2);
            printf("%-21s%-18s",std.name, std.id);
            scanf("%s", atten);
            if(strcmp(atten, "p") == 0){
            std.attendance++;
            std.absent--;
            }
         else if(strcmp(atten, "a") == 0){
            std.absent++;
            std.attendance--;
         }
         else{
            sc(40,2);
            printf("Please Enter Right Key......... 'p' or 'a' ");
            k--;
         }
         }
            found = 1;
        }
        fwrite(&std, sizeof(std), 1, tempfile);
    }

    fclose(sfile);
    fclose(tempfile);

    if (found) {
        remove("studentList.txt");
        rename("tempfile.txt", "studentList.txt");
        sc(40, 2);
        printf("Student with ID %s has been change attendance.\n", editId);
        sc(40, 2);
        printf("      >>>>>  Successfully Change Attendance  <<<<<   ");
    } else {
        sc(40, 2);
        printf("      >>>>>  Sorry  <<<<<   ");
        sc(40, 2);
        printf("Student ID '%s' not found.\n", editId);
        remove("tempfile.txt");
    }

    backpage();
}





    // About Function Start here.
    void about(){
         printf("\n\n\n");
         printf("                                      |=========================================================|\n");
         printf("                                      |               All About Us and Our system               |\n");
         printf("                                      |=========================================================|\n");
         printf("\n\n");
         printf("                   ");
         printf("Northern University Bangladesh is proud to present its innovative student management software, \n");
         printf("                   ");
         printf("designed to streamline administrative tasks  and enhance the  overall educational  experience. \n");
         printf("                   ");
         printf("Developed  by  Md Sawal Hossen,  a talented  student of  the  university,  this   cutting-edge \n");
         printf("                   ");
         printf("software offers a comprehensive solution for managing student records and attendance. ");
         printf("\n\n\n");
         printf("                   ");
         printf("Our student management software incorporates advanced  features that  simplify the process  of \n");
         printf("                   ");
         printf("tracking attendance, enabling  teachers  and  administrators to  efficiently  monitor  student \n");
         printf("                   ");
         printf("participation. With its user-friendly interface and intuitive  design,  the  software  ensures \n");
         printf("                   ");
         printf("effortless data entry and retrieval, making it an indispensable tool for educational institutions.");
         printf("\n\n\n");
         printf("                   ");
         printf("Furthermore, this software provides administrators with valuable insights through customizable \n");
         printf("                   ");
         printf("reports and analytics, enabling them  to  make  data-driven  decisions  for  enhancing student \n");
         printf("                   ");
         printf("engagement and performance.  With its  robust  security  measures, the  software  ensures  the \n");
         printf("                   ");
         printf("confidentiality and privacy of student information. ");
         printf("\n\n\n");
         printf("                   ");
         printf("Northern University Bangladesh takes pride in empowering its students to develop groundbreaking \n");
         printf("                   ");
         printf("solutions that address real-world challenges. The student management  software  developed by Md \n");
         printf("                   ");
         printf("Sawal Hossen exemplifies our commitment to fostering innovation and excellence in our  academic \n");
         printf("                   ");
         printf("community. \n\n");
         printf("\n\n\n");
         printf("                   ");
         printf("Developer Contact Information.\n\n");
         printf("                   ");
         printf("Name : Md Sawal Hossen \n");
         printf("                   ");
         printf("Student ID : 42230100463 \n");
         printf("                   ");
         printf("Section : 2C \n");
         printf("                   ");
         printf("Department : ECSE \n");
         printf("                   ");
         printf("Phone : +8801770-225576 \n");
         printf("                   ");
         printf("Email : sawalhossen@gmail.com \n");
         printf("                   ");
         printf("Address : Sector-18, Uttara, Dhaka-1230. \n");
         printf("                   ");
         printf("Website : https://sawalhossen.com \n");

         backpage();

    }
    // About Function End here.


void ExitProject()
{
    system("cls");
    int i;
    char ThankYou[100]     = " ========= Thank You =========\n";
    char SeeYouSoon[100]   = " ========= See You Soon ======\n";
    printf("\n\n\n\n\n\n\n                                      ");
    for(i=0; i<strlen(ThankYou); i++)
    {
        printf("%c",ThankYou[i]);
        Sleep(60);
    }
    printf("                                      ");
    for(i=0; i<strlen(SeeYouSoon); i++)
    {
        printf("%c",SeeYouSoon[i]);
        Sleep(60);
    }
    exit(0);
}
void sc(int c, int r){
    for(int ro=0; ro<r; ro++){
        printf("\n");
    }
    for(int co=0; co<c; co++){
        printf(" ");
    }

}
