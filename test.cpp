
#include<iostream> 
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{ 
    FILE *myFile;
    myFile = fopen(argv[1], "r");

    //read file into array
    int numberArray[16];
    int i;

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < 16; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
        if (numberArray[i] > 15){
            printf("out of range\n");
            break;

        }
    }


    fclose(myFile);

    return 0;
  
} 