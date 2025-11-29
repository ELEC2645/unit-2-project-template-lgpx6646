#include <stdio.h>
#include "funcs.h"


converter_type converter_selector(void) { //asks user to input their converter type
    while(1){ 
        int choice;
        printf("\n\tChoose your converter type:\n"
               "\n\t1. Buck\n"
               "\n\t2. Boost\n"
               "\nEnter choice: \n");
    
        if(scanf("%d",&choice) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {} //clears invalid input to prevent infinite loop
            continue;
        }


        switch (choice) {
            case 1: return BUCK;
            case 2: return BOOST;
            default: printf("Invalid choice! Please enter 1 or 2.\n"); //makes sure user can only input 1 or 2

        }
    }
    
}


void inductor_selector_buck(void) { //performs a calculation to find correct inductor values for a buck converter
    printf("\n>> Inductor Selector Boost\n");
    printf("\nWORKS BUCK\n");
    
}

void inductor_selector_boost(void){ //performs a calculation to find correct inductor values for a boost converter
    printf("\n>> Inductor Selector\n");
    printf("\nWORKS BOOST\n");
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

void change_converter(void) { //Allows user to change converter type, between buck and boost
    printf("\n>> Change Converter Type\n");
    converter_type users_conv = converter_selector();
}