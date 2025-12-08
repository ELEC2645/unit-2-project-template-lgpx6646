// ELEC2645 Unit 2 Project
// Power Electronics Calculator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcs.h"

/* Prototypes mirroring the C++ version */
static converter_type main_menu(converter_type c);            /* runs in the main loop */
static void print_main_menu(void);      /* output the main menu description */
static int  get_user_input(void);       /* get a valid integer menu choice */
static converter_type select_menu_item(int input, converter_type c);/* run code based on user's choice */
static void go_back_to_main(void);      /* wait for 'b'/'B' to continue */
static int  is_integer(const char *s);  /* validate integer string */


int main(void)
{
    /*Select converter type initially*/
    converter_type users_conv = converter_selector();
    
    /* this will run forever until we call exit(0) in select_menu_item() */
    for(;;) {
       users_conv = main_menu(users_conv);
    }

    /* not reached */
    return 0;
}

static converter_type main_menu(converter_type c)
{
    print_main_menu();
    {
        int input = get_user_input();
        select_menu_item(input, c);
    }
}

static int get_user_input(void)
{
    enum { MENU_ITEMS = 6 };   /* 1..5 = items, 6 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

static converter_type select_menu_item(int input, converter_type c)
{
    switch (input) {
        case 1:
            if (c == BUCK){ //checks if buck was selected
                inductor_selector_buck();//runs inductor selector function for buck
            }
            else { //checks if boost was selected
                inductor_selector_boost(); //runs inductor selector function for boost
            }
            go_back_to_main();
            break;
        case 2:
            if (c == BUCK){ //checks if buck was selected
                capacitor_selector_buck();//runs capacitor selector function for buck
            }
            else { //checks if boost was selected
                capacitor_selector_boost(); //runs capacitor selector function for boost
            }
            go_back_to_main();
            break;
        case 3:
            if (c == BUCK){ //checks if buck was selected
                boundary_current_buck();//runs boundary current function for buck
            }
            else { //checks if boost was selected
                boundary_current_boost(); //runs boundary current function for boost
            }
            go_back_to_main();
            break;
        case 4:
            menu_item_4();
            go_back_to_main();
            break;
        case 5:
            converter_type new_conv = change_converter();//lets user change between buck or boost converter
            return new_conv;
            go_back_to_main();
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}

static void print_main_menu(void)
{
    printf("\n----------- Main Menu -----------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Inductor Selector\t\t\n"
           "\t2. Output Capacitor Selector\t\n"
           "\t3. Boundary Current Calculator\n"
           "\t4. CCM or DCM Calculator\t\t\n"
           "\t5. Change Converter Type\t\t\n"
           "\t6. Exit\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("-------------------------------------------------\n");
}

static void go_back_to_main(void)
{
    char buf[64];
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');
}

/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
static int is_integer(const char *s)
{

    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}