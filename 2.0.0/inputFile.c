#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//#include "fourier_transform.h"

#define MAX_TIMES 10000
#define PI 3.1415926
#define INPUT_FILENAME  "sawtooth.data"
#define OUTPUT_FILENAME "fourier.data"




typedef struct {

    double re_val;   //param1
    double im_val;   //param2

}TYPE_FT;

static TYPE_FT FtOutput;



int main(void)
{

    printf("*** 0 ***\n");

    int    i;
    int    k;
    int    n;
    int    ftIndex;    //input_data_len -> ftIndex?
    double input_data_buf[MAX_TIMES + 1];
 
    FILE *fpInputData  = (FILE*) NULL;
    FILE *fpOutputData = (FILE*) NULL;
    printf("*** 1 ***\n");


    if ((fpInputData = fopen(INPUT_FILENAME, "r")) == (FILE*) NULL){
        fprintf(stderr, "Can't open INPUT_FILENAME\n");
        return (-1);
    } 
    if ((fpOutputData = fopen(OUTPUT_FILENAME, "w")) == (FILE*) NULL){
        fprintf(stderr, "Can't open OUTPUT_FILENAME\n");
        return (-1);
    }

/*
   for(ftIndex = 0; ftIndex < MAX_TIMES; ftIndex++){
        if(fscanf(fpInputData, "%lf", &input_data_buf[ftIndex]) == EOF){
            ftIndex--;
            break;
        }
    }
*/
    printf("*** 2 ***\n");

    memset(input_data_buf, 0, sizeof(input_data_buf));
//    printf("%d\n", sizeof(input_data_buf));
//    k = 1;
    while ((fscanf(fpInputData, "%lf", &input_data_buf[i])) != EOF){
//        printf("%f\n", input_data_buf[i]);
        ++i;
    }

    for (i = 0; i < 10; i++){
        printf("%f\n", input_data_buf[i]);
    }

/*
    for (n = 0; n < ftIndex; n++){
       FtOutput.re_val = FtOutput.im_val = 0.0;
       for (k = 1; k < ftIndex; k++){
           FtOutput.re_val +=  input_data_buf[k] * cos(2 * PI * k * n / ftIndex);
           FtOutput.im_val += -input_data_buf[k] * sin(2 * PI * k * n / ftIndex);
       }
       fprintf(fpOutputData, "%d %f %f\n", n, FtOutput.re_val, FtOutput.im_val);
    }
*/
    if (fpInputData){
        fclose(fpInputData);
    }

    if (fpOutputData){
        fclose(fpOutputData);
    }

    printf("*** 3 ***\n");

    return (0);
}
