#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for atof
#include <string.h>
#include "funcs.h"
#define MAX_NUMBERS 100 // maximum numbers to process from input file
#define MAX_LINE 100 //maximum numbers to process in file

converter_type converter_selector(void) { //asks user to input their converter type
    while(1){ 
        int choice;
        printf("\n\tChoose your converter type:\n"
               "\n\t1. Buck\n"
               "\n\t2. Boost\n"
               "\nEnter choice: ");
    
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
    float Vin; //declare variables
    float Vout;
    float deltai;
    float fs;
    printf("\n>> Inductor Selector Buck\n");
    printf("\nInput Vout: \n");
    if(scanf("%f",&Vout) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput Vin: \n");
    if(scanf("%f",&Vin) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput current ripple: \n");
    if(scanf("%f",&deltai) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput switching frequency: \n");
    if(scanf("%f",&fs) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    float K = Vout/ Vin; //finds duty ratio
    float L = ((1-K)*Vout)/(fs*deltai); //finds inductance
    printf("Inductance = %f",L);
}

void inductor_selector_boost(void){ //performs a calculation to find correct inductor values for a boost converter
    float Vout; //declare variables
    float Vin;
    float deltai;
    float fs;
    printf("\n>> Inductor Selector Boost\n");
    printf("\nInput Vin: \n");
    if(scanf("%f",&Vin) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput Vout: \n");
    if(scanf("%f",&Vout) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput current ripple: \n");
    if(scanf("%f",&deltai) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput switching frequency: \n");
    if(scanf("%f",&fs) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    float K = 1 - (Vin/Vout); //finds duty ratio
    float L = (Vin * K)/(fs * deltai); //finds inductance
    printf("Inductance = %f",L);
}

void capacitor_selector_buck(void) {
     float Vout; //declare variables
    float Vin;
    float L;
    float deltav;
    float fs;
    printf("\n>> Capacitor Selector Buck\n");
    printf("\nInput Vin: \n");
    if(scanf("%f",&Vin) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput Vout: \n");
    if(scanf("%f",&Vout) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput voltage ripple: \n");
    if(scanf("%f",&deltav) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput switching frequency: \n");
    if(scanf("%f",&fs) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput inductance: \n");
    if(scanf("%f",&L) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    float K = Vout/ Vin;
    float C = (Vout/(8*pow(fs,2)*deltav*L))*(1-K);
    printf("Capacitance = %f",C);
}

void capacitor_selector_boost(void) {
    float Vout; //declare variables
    float Vin;
    float fs;
    float deltav;
    float R;
    printf("\n>> Capacitor Selector Boost\n");
    printf("\nInput Vin: \n");
    if(scanf("%f",&Vin) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput Vout: \n");
    if(scanf("%f",&Vout) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput voltage ripple: \n");
    if(scanf("%f",&deltav) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput switching frequency: \n");
    if(scanf("%f",&fs) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput load resistance: \n");
    if(scanf("%f",&R) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    float K = 1 - (Vin/ Vout);
    float C = (Vout*K)/(deltav*R*fs);
    printf("Capacitance = %f",C);
}

void boundary_current_buck(void) {
    printf("\n>> Boundary Current Calculator Buck\n");
     float Vout; //declare variables
    float Vin;
    float fs;
    float L;
    printf("\nInput Vin: \n");
    if(scanf("%f",&Vin) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput Vout: \n");
    if(scanf("%f",&Vout) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput switching frequency: \n");
    if(scanf("%f",&fs) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput inductance: \n");
    if(scanf("%f",&L) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    float K = Vout/Vin;
    float T = 1/fs;
    float I = ((Vin * T)/(2*L)) * K *(1-K);
    float Imax = (T * Vin)/ (8 * L);
    printf("\nBoundary Current = %f",I);
    printf("\nMaximum Boundary Current is: %f, when K=0.5", Imax);  
}

void boundary_current_boost(void) {
    printf("\n>> Boundary Current Calculator Boost\n");
    float Vout; //declare variables
    float Vin;
    float fs;
    float L;
    printf("\nInput Vin: \n");
    if(scanf("%f",&Vin) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput Vout: \n");
    if(scanf("%f",&Vout) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput switching frequency: \n");
    if(scanf("%f",&fs) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    printf("\nInput inductance: \n");
    if(scanf("%f",&L) != 1) { //checks user has inputted a number
            printf("Invalid input! Please enter a number.");
    }
    float K = 1 - Vin/Vout;
    float T = 1/fs;
    float I = ((Vin * T)/(2*L)) * K *(1-K);
    float Imax = (T * Vin)/ (8 * L);
    float IL = ((K*T)/(2*L)) * Vin;
    printf("\nOutput Boundary Current = %f",I);
    printf("\nInductor Boundary Current: %f", IL);
    printf("\nMaximum Boundary Current is: %f, when K=0.5", Imax); 
    
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}

Converter* read_file(const char *filename, int *count){ //function to read data from file inputted by user
    char line[256];
    FILE *input = fopen(filename, "r");
    //FILE *output = fopen("graph.txt", "w");

    if (input == NULL) { //checks for errors when opening file
        printf("Error opening file.\n");
        return NULL;
    }
    
    Converter *converters = malloc(100 * sizeof(Converter)); //assign data to a pointer, so can be used elsewhere (max lines=100)

    int read = 0;
    *count = 0;
    fgets(line, sizeof(line), input); //skips header 

    do
    {
        read = fscanf(input, //reads input from file into struct
                       "%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                        &converters[*count].Vin,
                        &converters[*count].Vout,
                        &converters[*count].L,
                        &converters[*count].fs,
                        &converters[*count].R,
                        &converters[*count].deltav,
                        &converters[*count].deltai);
        if (read == 7) (*count)++;
        if (read != 7 && !feof(input)) //checks if 7 values have been read
        {
                printf("File format incorrect.\n");
                return NULL;
        }
        if (ferror(input)){ //checks for errors when reading file
                printf("Error reading file.\n");
                return NULL;
        }
    } while(!feof(input)); //reads file until end of file
    
    fclose(input);

    for (int i=0; i<*count; i++){
        printf("%lf %lf %lf %lf %lf %lf %lf\n",
                converters[i].Vin,
                converters[i].Vout,
                converters[i].L,
                converters[i].fs,
                converters[i].R,
                converters[i].deltav,
                converters[i].deltai
        );
        printf("\n");
    }

    return converters; 
}

Converter* file_or_manual(){ //asks if the user wants to input a file 
        int count;
/*Returns file data if user wants to use a file*/
   char buf[64];
    do {
        printf("\nWould you like to use a file to input your data? (Please enter yes or no.) ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting."); //exits program if there is an error
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(strcmp(buf,"yes")==0 || strcmp(buf,"no")==0)); //checks if input is yes or no

    if (strcmp("yes",buf)==0){ //compares input to yes
        printf("Enter file name: \n");
        char name[64];
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\r\n")] = '\0';//strips trailing newline
        return read_file(name, &count); //reads file
    }
    else{
        printf("Manual input");
    }
    return NULL;
    //exits if user wants manual input
}


converter_type change_converter(void) { //allows user to change converter type, between buck and boost
    printf("\n>> Change Converter Type\n");
    converter_type users_conv = converter_selector();
    return users_conv;
}