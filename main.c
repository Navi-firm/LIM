#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "student.h"    // Includes the student function file
#include "book.h"       // Includes the book function file
#include "borrow.h"
#define MAXCHAR 1024

// Declare global variables
char menuoption, borrowoption, addoption;
int admission_number, no_students, snn, no_books;
char first_name[30];
char last_name[30];
char school[50];
char end_date[12];
char title[50];
char author[50];
char category[50];
FILE *studentsf;
FILE *booksf;
char str[MAXCHAR];

// Program main function
int main()
{
    // Main Menu user display
    mainmenu();
    // End of Main Menu

    // main menu choice function
    menuchoice();
    // end of main menu choice function

    return 0;
}
// End of Main function

    // Main menu function
    void mainmenu()
    {
    printf("\n\t ----------------------------------------------------------- \n");
    printf("\n\t \t Welcome to the Library Information System \n");
    printf("\n\t ----------------------------------------------------------- \n");
    printf("\n\t *********************** MAIN MENU ************************* \n\n");
    printf("\n\t ********** Please Choose an Option to continue ************ \n\n");
    printf("\n\t 1.	Add/Remove Book \n");
    printf("\n\t 2.	Display all Students. \n");
    printf("\n\t 3.	Register new Student. \n");
    printf("\n\t 4.	Search book. \n");
    printf("\n\t 5.	Borrow or Return book. \n");
    printf("\n\t 0.	Exit program. \n\n");
    printf("\n\t ----------------------------------------------------------- \n");

    // Ask user for menu option
    printf("\n\t Enter menu option to continue: ");
    scanf("%s", &menuoption);
    }
    // End of main menu function

    void bye(void)
    {
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t Thank You for using the Library Information System ");
            printf("\n\t\t*****************************************************\n\n");
    }
    // interprets user input and performs necessary execution
    void menuchoice()
    {
        switch(menuoption)
        {
        case '1':
            // Clear screen before executing
            system("cls");
            // Call the display all books functions
            books();
            break;
        case '2':
            // Clear screen before executing
            system("cls");
            // Call the display all books functions
            students();
            break;
        case '3':
            // Clear screen before executing
            system("cls");
            // Register new student
            register_student();
            break;
        case '4':
            // Clear screen before executing
            system("cls");
            // Call the display all books functions
            search_book();
            break;
        case '5':
            // Clear screen before executing
            system("cls");
            // Borrow return menu
            borrow_return_menu();
            break;
        case '0':
            // Clear screen before executing
            system("cls");
            // Exit the program with a goodbye message
            atexit(bye);
            exit(EXIT_SUCCESS);
            break;
        default:
            // Clear screen before executing
            system("cls");
            // Display error message
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t Sorry INVALID CHOICE, please use 1, 2, 3, 4, 5 or 0 ");
            printf("\n\t\t*****************************************************\n\n");
            // Display main menu
            main();
        }
    }
    // End of menu option functions

    // Register student function
    void register_student()
    {

        // Clear screen first below continuing
        system("cls");

        // Ask user for student details
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t \t Student Registration Module \n");
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t ********************** STUDENT DETAILS ********************* \n\n\n");
        printf("\n\t How many students do you want to register: ");
        scanf("%d", &no_students);
        printf("\n\n\t ----------------------------------------------------------- \n");

        // Store student details in file
        studentsf = fopen("C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\students.txt", "r+");
        if(studentsf)
        {
            // Read and Save new student to existing student list
            for(int i = 0; i < no_students; ++i)
            {
                // Read text file before completing
                printf("\n\t ********** Provide Student Details as follows ************ \n\n");
                printf("\t List of students: #%d\n", i + 1);
                printf("\n\t 1.	Student Admission Number: ");
                scanf("%d", &admission_number);
                printf("\n\t 2.	Student First Name: ");
                scanf("%s", &first_name);
                printf("\n\t 3.	Student Last Name: ");
                scanf("%s", &last_name);
                printf("\n\t 4.	School of: ");
                scanf("%s", &school);
                printf("\n\t 5.	Exit date: ");
                scanf("%s", &end_date);
                printf("\n");

                // Save details to the student files
                fprintf(studentsf, "\n%d\t%s\t%s\t%s\t%s\t\n", admission_number, first_name, last_name, school, end_date);

                // success message
                printf("\n\n\t\t*****************************************************");
                printf("\n\t\t\t Records SUCCESSFULLY SAVED ");
                printf("\n\t\t*****************************************************\n\n");
            }

        }else{
            // Error Message
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t\t Sorry student FILE NOT FOUND ");
            printf("\n\t\t*****************************************************\n\n");
        }
        fclose(studentsf);
    }
    // End of student function

    // Display all students
    void students()
    {
        // Display all  students
        // Clear screen first below continuing
        system("cls");
        // Store student details in file
        studentsf = fopen("C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\students.txt", "r");
        if(studentsf)
        {
            printf("\n\t\t LIST OF ALL STUDENTS \n", "C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\students.txt");
            printf("\n\n************************************************************************************");
            printf("\n\n No# \t FirstName \t LastName \t School \t End Date");
            char stlist = fgetc(studentsf);
            while(stlist != EOF)
            {
                printf("%c", stlist);
                stlist = fgetc(studentsf);
            }
            printf("\n\n*************************************************************************************");
            printf("\n\n");
            fclose(studentsf);
            return 0;
        }
        else
        {
            // Error Message is file not found
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t\t Sorry student FILE NOT FOUND ");
            printf("\n\t\t*****************************************************\n\n");

            exit(1);

        }
    }

    // Display all books
    void books()
    {
         // Display Borrow Return Menu
            printf("\n\t ----------------------------------------------------------- \n");
            printf("\n\t \t Welcome to the Library Information System \n");
            printf("\n\t ----------------------------------------------------------- \n");
            printf("\n\t ******************* ADDREMOVE BOOK ******************** \n\n");
            printf("\n\t ********** Please Choose an Option to continue ************ \n\n");
            printf("\n\t 1.	Add Book \n");
            printf("\n\t 2.	Remove Book \n");
            printf("\n\t 3.	Return to Main Menu \n");
            printf("\n\t 0.	Exit program. \n\n");
            printf("\n\t ----------------------------------------------------------- \n");

            // Ask user for menu option
            printf("\n\t Enter menu option to continue: ");
            scanf("%s", &borrowoption);

            switch (borrowoption)
            {
            case '1':
                // Clear screen
                system("cls");
                // Call borrow book function
                new_book();
            break;
            case '2':
                // Clear screen
                system("cls");
                // Call borrow book function
                return_book();
            break;
            case '3':
                // Clear screen
                system("cls");
                // Call borrow book function
                main();
            break;
            case '0':
                // Clear screen
                system("cls");
                // Exit the program
                atexit(bye);
                exit(EXIT_SUCCESS);
            break;
            default:
            // Clear screen before executing
            system("cls");
            // Display error message
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t Sorry INVALID CHOICE, please use 1, 2, 3 or 0 ");
            printf("\n\t\t*****************************************************\n\n");
            }
    }
    // End of Display all books function

    // Add new book
    void new_book()
    {

        // Ask user for student details
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t \t BOOK Management Module \n");
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t ********************** BOOK DETAILS ********************* \n\n\n");
        printf("\n\t How many boos do you want to add: ");
        scanf("%d", &no_books);
        printf("\n\n\t ----------------------------------------------------------- \n");
        // Store student details in file
        booksf = fopen("C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\books.txt", "r+");
        if(booksf)
        {
            // Read and Save new student to existing student list
            for(int i = 0; i < no_books; ++i)
            {
                // Read text file before completing
                printf("\n\t ********** Provide Books Details as Follows ************ \n\n");
                printf("\t List of Books: #%d\n", i + 1);
                printf("\n\t 1.	Book SN number: ");
                scanf("%d", &snn);
                printf("\n\t 2.	Title: ");
                scanf("%s", &title);
                printf("\n\t 3.	author: ");
                scanf("%s", &author);
                printf("\n\t 4.	category: ");
                scanf("%s", &category);
                printf("\n");

                // Save details to the student files
                fprintf(booksf, "\n%d\t%s\t%s\t%s\n", snn, title, author, category);

                // success message
                printf("\n\n\t\t*****************************************************");
                printf("\n\t\t\t Records SUCCESSFULLY SAVED ");
                printf("\n\t\t*****************************************************\n\n");
            }

        }else{
            // Error Message
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t\t Sorry books FILE NOT FOUND ");
            printf("\n\t\t*****************************************************\n\n");
        }
        fclose(booksf);
    }
    // end of add new book function

    //Search for book
    void search_book()
    {
        // Ask user for book details to search
        system("cls");
        // Store student details in file
        booksf = fopen("C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\books.txt", "r");
        if(booksf)
        {
            printf("\n\t\t SEARCH RESULTS \n", "C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\books.txt");
            printf("\n\n************************************************************************************");
            printf("\n\n No# \t SSN \t title \t author \t Category");
            char stlist = fgetc(booksf);
            while(stlist != EOF)
            {
                printf("%c", stlist);
                stlist = fgetc(booksf);
            }
            printf("\n\n*************************************************************************************");
            printf("\n\n");
            fclose(booksf);
            return 0;
        }
        else
        {
            // Error Message is file not found
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t\t Sorry Book FILE NOT FOUND ");
            printf("\n\t\t*****************************************************\n\n");

            exit(1);

        }
    }
    // End of search book

    void borrow_return_menu()
    {
        // Display Borrow Return Menu
            printf("\n\t ----------------------------------------------------------- \n");
            printf("\n\t \t Welcome to the Library Information System \n");
            printf("\n\t ----------------------------------------------------------- \n");
            printf("\n\t ******************* BORROW RETURN MENU ******************** \n\n");
            printf("\n\t ********** Please Choose an Option to continue ************ \n\n");
            printf("\n\t 1.	Borrow Book \n");
            printf("\n\t 2.	Return Book \n");
            printf("\n\t 3.	Return to Main Menu \n");
            printf("\n\t 0.	Exit program. \n\n");
            printf("\n\t ----------------------------------------------------------- \n");

            // Ask user for menu option
            printf("\n\t Enter menu option to continue: ");
            scanf("%s", &addoption);

            switch (addoption)
            {
            case '1':
                // Clear screen
                system("cls");
                // Call borrow book function
                borrow();
            break;
            case '2':
                // Clear screen
                system("cls");
                // Call borrow book function
                remove_book();
            break;
            case '3':
                // Clear screen
                system("cls");
                // Call borrow book function
                main();
            break;
            case '0':
                // Clear screen
                system("cls");
                // Exit the program
                atexit(bye);
                exit(EXIT_SUCCESS);
            break;
            default:
            // Clear screen before executing
            system("cls");
            // Display error message
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t Sorry INVALID CHOICE, please use 1, 2, 3 or 0 ");
            printf("\n\t\t*****************************************************\n\n");
            }
    }

    // Borrow book(s)
    void borrow()
    {
        // Ask user for book and student detail
        // Ask user for student details
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t \t BOOK Management Module \n");
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t ********************** BOOK DETAILS ********************* \n\n\n");
        printf("\n\t How many boos do you want to add: ");
        scanf("%d", &no_books);
        printf("\n\n\t ----------------------------------------------------------- \n");
        // Store student details in file
        booksf = fopen("C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\books.txt", "r+");
        if(booksf)
        {
            // Read and Save new student to existing student list
            for(int i = 0; i < no_books; ++i)
            {
                // Read text file before completing
                printf("\n\t ********** Provide Books Details as Follows ************ \n\n");
                printf("\t List of Books: #%d\n", i + 1);
                printf("\n\t 1.	Book SN number: ");
                scanf("%d", &snn);
                printf("\n\t 2.	Title: ");
                scanf("%s", &title);
                printf("\n\t 3.	author: ");
                scanf("%s", &author);
                printf("\n\t 4.	category: ");
                scanf("%s", &category);
                printf("\n");

                // Save details to the student files
                fprintf(booksf, "\n%d\t%s\t%s\t%s\n", snn, title, author, category);

                // success message
                printf("\n\n\t\t*****************************************************");
                printf("\n\t\t\t Records SUCCESSFULLY SAVED ");
                printf("\n\t\t*****************************************************\n\n");
            }

        }else{
            // Error Message
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t\t Sorry books FILE NOT FOUND ");
            printf("\n\t\t*****************************************************\n\n");
        }
        fclose(booksf);
    }
    // End of borrow book function

    // Return book(s)
    void return_book()
    {
        // Ask user for book and student detail
        // Ask user for student details
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t \t RETURN BOOKS \n");
        printf("\n\t ----------------------------------------------------------- \n");
        printf("\n\t ********************** BOOK DETAILS ********************* \n\n\n");
        printf("\n\t How many books do you want to return: ");
        scanf("%d", &no_books);
        printf("\n\n\t ----------------------------------------------------------- \n");
        // Store student details in file
        booksf = fopen("C:\\Users\\Jovicorp Studio\\Documents\\Programming\\Code Blocks\\C\\Library Information System\\borrow.txt", "r+");
        if(booksf)
        {
            // Read and Save new student to existing student list
            for(int i = 0; i < no_books; ++i)
            {
                // Read text file before completing
                printf("\n\t ********** Provide Return Books Details as Follows ************ \n\n");
                printf("\t List of Books: #%d\n", i + 1);
                printf("\n\t 1.	Book SN number: ");
                scanf("%d", &snn);
                printf("\n\t 2.	Student Number: ");
                scanf("%s", &admission_number);
                printf("\n\t 3.	Borrowing Date: ");
                scanf("%s", &start_date);
                printf("\n\t 4.	Return Date: ");
                scanf("%s", &end_date);
                printf("\n");

                // Save details to the student files
                fprintf(booksf, "\n%d\t%s\t%s\t%s\n", snn, admission_number, start_date, end_date);

                // success message
                printf("\n\n\t\t*****************************************************");
                printf("\n\t\t\t BOOKS SUCCESSFULLY RETURNED ");
                printf("\n\t\t*****************************************************\n\n");
            }

        }else{
            // Error Message
            printf("\n\n\t\t*****************************************************");
            printf("\n\t\t\t Sorry books FILE NOT FOUND ");
            printf("\n\t\t*****************************************************\n\n");
        }
        fclose(booksf);
    }
    // End of borrow book function
