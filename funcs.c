#include <stdio.h>
#include "funcs.h"


converter_type converter_selector(void) { //asks user to input their converter type
    while(1){ 
        int choice;
        printf("\nChoose your converter type:\n"); 
        printf("\n1. Buck\n");
        printf("\n2. Boost\n");
        printf("\nEnter choice: \n");
    
        if(scanf("%d",&choice) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {} //clears invalid input to prevent infinite loop
            continue;
        }


        switch (choice) {
            case 1: return buck_converter;
            case 2: return boost_converter;
            default: printf("Invalid choice! Please enter 1 or 2.\n"); //makes sure user can only input 1 or 2

        }
    }
    
}


void menu_item_1(void) {
    printf("\n>> Buck Converter\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 1 */
}

void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}

void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}

void menu_item_5(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}