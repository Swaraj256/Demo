/*Write a C program (name it "filecopy. c") that copies the contents of one file to a destination
 file. This program will read data from one file and copy them to another. The first input that 
 the program will need is the names of the two files: input file ("input.txt") and output file 
 ("output.txt"). Once the two file names have been obtained, the program must open the input file 
 and create and open the output file*/


#include <stdio.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[50], destName[50];
    char ch;
    printf("Enter the source file name: ");
    scanf("%s", sourceName);

    printf("Enter the destination file name: ");
    scanf("%s", destName);
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file %s\n", sourceName);
        return 1;
    }
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file %s\n", destName);
        fclose(sourceFile);
        return 1;
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    printf("\nFile copied successfully from %s to %s\n", sourceName, destName);
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
