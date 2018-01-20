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
*************************************************************************************/
#define MAX_TIMES 10000
#define PI 3.1415926
#define INPUT_FILENAME  "sawtooth.data"
#define OUTPUT_FILENAME "fourier.data"

/*
typedef struct {

    double re_val;   //param1
    double im_val;   //param2

}TYPE_FT;

static TYPE_FT FtOutput;
*/


//void ft(double* pInputData, int* ftIndex, double* real, double* imag);


/**********************************************************************************//**
*                          MAIN
*************************************************************************************/
int main(void)
{

    printf("*** 0 ***\n");

    int    i;
    int    k;  //k倍角を表す。
    int    n;  //
    int*   ftIndex;    //input_data_len -> ftIndex?
    double re_val;
    double im_val;
    double real[MAX_TIMES + 1];
    double imag[MAX_TIMES + 1];
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

//    ft(input_data_buf, i, &re_val, &im_val);

    ftIndex = &(i); //配列のインデックスがずれているので、一つずらす。ところで、なぜずれるのか。
    *ftIndex = *ftIndex - 1;

    /* Fourier Transform */
    for (n = 0; n < *ftIndex; n++){  
       *real = *imag = 0.0;
       for (k = 0; k < *ftIndex; k++){
           real[n] +=  input_data_buf[k] * cos(2 * PI * k * n / *ftIndex);
           imag[n] += -input_data_buf[k] * sin(2 * PI * k * n / *ftIndex);
       }
    }
    

    /* Output data */
    for (n = 0; n < *ftIndex; n++){
        printf("%d %f %f\n", n, real[n], imag[n]);
        fprintf(fpOutputData, "%d %f %f\n", n, real[n], imag[n]);
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
