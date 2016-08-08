/*
                                                        My CodeBase For A Library Management System

                                                                Coded strictly using .C                                                                   */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void welcomeScreen();
void writeToFile();
void readFromFile();
void deleteFile();


int main(){

    welcomeScreen();
    getch();
    return 0;
}


// function of the welcome screen

void welcomeScreen(){

    int option;

printf("    :::          :::  ::::::::  :::       :::::::::   ::::::::::  ::::     ::::  ::::::::\n"
       "     :::   ::   :::   :::       :::       :::         :::    :::  ::::     ::::  :::           \n"
       "      :::  ::  :::    :::       :::       :::         :::    :::  :::::   :::::  :::::::::          \n"
       "       ::: :: :::     ::::::::  :::       :::         :::    :::  :::::: ::::::  :::::::::   \n"
       "        :::::::       :::       :::       :::         :::    :::  ::: ::::: :::  :::          \n"
       "         :::          ::::::::  ::::::::: :::::::::   ::::::::::  :::  :::  :::  :::::::::   \n\n\n");



printf("                                       ----- L I B R A R Y  M A N A G E M E N T  S Y S T E M--------       \n\n");
            printf("                                                   ----- MAIN  MENU--------       \n\n");
            printf("\n                                                 -----1. Add Books    --------                         \n\n");
            printf("\n                                                 -----2. Delete Books  --------                          \n\n");
            printf("\n                                                 -----3. View Book List -------                          \n\n");
            printf("\n                                                 -----0. About-----                          \n\n");
            printf("\n                                           ---Enter any of the options listed above----          \n\n");

                                                                        scanf("\t\t%i",&option);

switch(option){

case 1:system("cls"); writeToFile(); break;

case 2:system("cls"); deleteFile(); break;

case 3:system("cls"); readFromFile(); break;

case 0:
    system("cls");

    printf("\t\tAbout the author\n\n\n");

    printf("\t-------------------------------------\n"
          "\t                                     \n"
"\t   DEVELOPED BY MIRACLE ANYANWU\n                   \n"
"\t          © 2016\n                    \n"
"\t    Email: anyanwumiracle78@gmail.com                              \n"
          "\t-------------------------------------\n");

    break;

default:
    printf("Error, please check your options again.\nThank you.\n\n\n\tApplication brought to you by MapleCon Technologies");
    break;
}
}

void writeToFile(){

    FILE *booksIn = fopen("Library.txt","a");

    if(booksIn == NULL){
        printf("Error was noticed while opening file.\n");
        exit(1);
    }

    char *list[100];
    int option;

    /* The do while acts as a means of accepting values until a exit key is pressed */

    do{
    printf("\nEnter the name of the book you wish to add:\n");
    scanf("%s",list);

    fprintf(booksIn,"%s\n",list);

    printf("Enter 1 to continue or 0 to terminate:\t");
    scanf("%i",&option);

    }while (option == 1);

    fclose(booksIn);


}

void readFromFile(){

    FILE *booksOut = fopen("Library.txt","r");

   int c;

   booksOut = fopen("Library.txt","r");
   while(1)
   {
      c = fgetc(booksOut);
      if( feof(booksOut) )
      {
         break;
      }
      printf("%c", c);
   }

   fclose(booksOut);

}

void deleteFile(){

FILE *fileptr1, *fileptr2;
    char filename[40];
    char ch;
    int delete_line, temp = 1;

    printf("Enter file name: ");
    scanf("%s", filename);

    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
   while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }

    rewind(fileptr1);
    printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);

    fileptr2 = fopen("Library.txt", "w");
    ch = getc(fileptr1);

    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
            temp++;

            if (temp != delete_line)
            {

                putc(ch, fileptr2);
            }
    }

    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);

    rename("Library.txt", filename);
    printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen("Library.txt", "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }

    fclose(fileptr1);
    return 0;
}

/*

            Written By Miracle Anyanwu

            © 2016

                                                */
