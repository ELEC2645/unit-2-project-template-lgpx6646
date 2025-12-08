#include <stdio.h>
#include "funcs.h"   

int main(void) {
    if(file_or_manual()){
        printf("Enter file name: \n");
        char name[20];
        scanf("%s",name);
        read_file(name);
        
    }
    else {
        (printf("manual input\n"));
    } 

    return 0;
}
