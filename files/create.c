#include <stdio.h>

int main(){
    FILE *fp = fopen("example.txt", "a");
   
    // ######## fputc ###############

        // for(int i=1; i<=100; i++){
        //     fputc('a', fp);
        //     fputc('\n', fp);
        // }

    // ######### fputs ##############

        // fputs("The quick brown fox jumps over the lazy dog!", fp);

    // ######### fprintf ############
    
        // fprintf(fp,"2+2 = %d\n", 2+2);

    // ######## Always close a file ###############

        // fclose(fp);
        // getchar();


    return 0;
}