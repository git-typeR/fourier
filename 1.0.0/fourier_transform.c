/**
* \brief Fourier transform from any data
* \author Ryota Nakao
* \version 1.0.0
* \date 2017-
* \warning As this program is being developed, the specification may change.
*/



#include <stdio.h>
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

}TypeFT;

static TypeFT FtOutput;



int main(void)
{

    printf("*** 0 ***\n");

    int    k;
    int    n;
    int    nIndex;    //input_data_len
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

   for(nIndex = 0; nIndex < MAX_TIMES; nIndex++){
        /*一行ごとにsawtooth.dataの値をf[]へ格納していく。
        fscanfは配列の個数を返す。エラーはEOFを返す。
        データを一行ずつ格納していくときEOFはエラー。
        */
        if(fscanf(fpInputData, "%lf", &input_data_buf[nIndex]) == EOF){
            nIndex--;
            break;
        }
    }


    for(n = 0; n < nIndex; n++){
       FtOutput.re_val = FtOutput.im_val = 0.0;
       for(k = 0; k < nIndex; k++){
           FtOutput.re_val +=  input_data_buf[k] * cos(2 * PI * k * n / nIndex);
           FtOutput.im_val += -input_data_buf[k] * sin(2 * PI * k * n / nIndex);
       }
       printf("%d %f %f\n", n, FtOutput.re_val, FtOutput.im_val);
       fprintf(fpOutputData, "%d %f %f\n", n, FtOutput.re_val, FtOutput.im_val);
    }

    printf("*** 2 ***\n");


    if (fpInputData){
        fclose(fpInputData);
    }

    if (fpOutputData){
        fclose(fpOutputData);
    }

    printf("*** 3 ***\n");

    return (0);
}
