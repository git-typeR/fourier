/**
* \brief Fourier transform from any data
* \author Ryota Nakao
* \version 2.0.0
* \date 2017-
* \warning As this program is being developed, the specification may change.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//#include "fourier_transform.h"



/**********************************************************************************//**
*                          MACRO
/*************************************************************************************/
#define MAX_TIMES 10000
#define PI 3.1415926
#define INPUT_FILENAME  "sawtooth.data"
#define OUTPUT_FILENAME "fourier.data"




typedef struct {

    double re_val;   //param1
    double im_val;   //param2

}TYPE_FT;

static TYPE_FT FtOutput;


/**********************************************************************************//**
*                          MAIN
/*************************************************************************************/
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


    /* File open */
    if ((fpInputData = fopen(INPUT_FILENAME, "r")) == (FILE*) NULL){
        fprintf(stderr, "Can't open INPUT_FILENAME\n");
        return (-1);
    } 
    if ((fpOutputData = fopen(OUTPUT_FILENAME, "w")) == (FILE*) NULL){
        fprintf(stderr, "Can't open OUTPUT_FILENAME\n");
        return (-1);
    }

    printf("*** 2 ***\n");

    /* Initialize input_data_buf */
    memset(input_data_buf, 0, sizeof(input_data_buf));

    /* Read data file into input_data_buf */
    while ((fscanf(fpInputData, "%lf", &input_data_buf[i])) != EOF){

        ++i;
    }

    ftIndex = i - 1; //配列のインデックスがずれているので、一つずらす。ところで、なぜずれるのか。


    /* Fourier Transform */
    for (n = 0; n < ftIndex; n++){
       FtOutput.re_val = FtOutput.im_val = 0.0;
       for (k = 0; k < ftIndex; k++){
           FtOutput.re_val +=  input_data_buf[k] * cos(2 * PI * k * n / ftIndex);
           FtOutput.im_val += -input_data_buf[k] * sin(2 * PI * k * n / ftIndex);
       }
       fprintf(fpOutputData, "%d %f %f\n", n, FtOutput.re_val, FtOutput.im_val);
    }


    /* File colse */
    if (fpInputData){
        fclose(fpInputData);
    }

    if (fpOutputData){
        fclose(fpOutputData);
    }

    printf("*** 3 ***\n");

    return (0);
}
