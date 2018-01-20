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


typedef struct {
 
     double re[2100];   //param1
     double im[2100];   //param2
 
}TYPE_FT;




void ft(double inputData[], int ftIndex, TYPE_FT* pFt);


/**********************************************************************************//**
*                          MAIN
*************************************************************************************/
int main(void)
{

    TYPE_FT* complex_val = {0};

    printf("*** 0 ***\n");

    int    i;
 //   int    k;  //k倍角を表す。
    int    n;  //
//    int*   ftIndex;    //input_data_len -> ftIndex?
//    TYPE_FT* pVal;

//    double* pOutReal;
//    double* pOutImag;
//    double real[MAX_TIMES + 1];
//    double imag[MAX_TIMES + 1];
    double input_data_buf[2100];
 
    
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
        i++;
    }

    for (n = 0; n < 2100; n++){
        printf("%f\n", input_data_buf[n]);
    }

    printf("*** 3 ***\n");

//    ftIndex = &(i); //配列のインデックスがずれているので、一つずらす。ところで、なぜずれるのか。

//    real = &re_val;
//    imag = &im_val;

    ft(input_data_buf, i, complex_val);

    /* Output data */
    for (n = 0; n < 2100; n++){
//        printf("%d %f %f\n", n, re_val[n], im_val[n]);
        fprintf(fpOutputData, "%d %f %f\n", n, complex_val->re[n], complex_val->im[n]);
    }

    printf("*** 5 ***\n");

    /* File colse */
    if (fpInputData){
        fclose(fpInputData);
    }

    if (fpOutputData){
        fclose(fpOutputData);
    }

    printf("*** 6 ***\n");

    return (0);
}

void ft(double inputData[], int ftIndex, TYPE_FT* pFt)
{

    printf("*** 4 ***\n");

    int k;
    int n;

    ftIndex = ftIndex - 1;
    printf("%d\n", ftIndex);

    /* Fourier Transform */
    for (n = 0; n < ftIndex; n++){  
    
       for (k = 0; k < ftIndex; k++){
           pFt->re[n] +=  inputData[k] * cos(2 * PI * k * n / ftIndex);
           pFt->im[n] += -inputData[k] * sin(2 * PI * k * n / ftIndex);
       }
    }

}
