#include <stdio.h>
#include <stdlib.h>

int main() {
    char sourceFileName[100], targetFileName[100];
    FILE *sourceFile, *targetFile;
    char ch;

    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    printf("Enter the target file name: ");
    scanf("%s", targetFileName);

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
      printf("Cannot open source file %s\n", sourceFileName);
      exit(1);
    }

    targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
      printf("Cannot open target file %s\n", targetFileName);
      fclose(sourceFile);
      exit(1);
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
      fputc(ch, targetFile);
    }

    printf("File copied successfully from %s to %s.\n", sourceFileName, targetFileName);

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
