#include <stdio.h>
int main() {

FILE *f = fopen("numbers.txt", "r"); int num;
fscanf(f, "%d", &num);
printf("%d", num * 2); fclose(f);
return 0;

}
