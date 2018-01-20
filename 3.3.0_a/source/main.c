/**
* \brief Fourier transform from any data
* \author Ryota Nakao
* \version 2.0.0
* \date 2017-
* \warning As this program is being developed, the specification may change.
*/


/**********************************************************************************//**
*                         INCLUDE
*************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fourier_transform.h"

/**********************************************************************************//**
*                         MACRO
*************************************************************************************/
#define UPPER_LIMIT_X     10     //xの上限
#define DELTA_X           0.01    //xの増分
#define EXP_FACTORIAL_NUM 200     //eの項数
#define ERROR_ACRCY       1e-20   //精度

/**********************************************************************************//**
*                         GLOBAL VARIABLE
*************************************************************************************/

/**********************************************************************************//**
*                         PROTOTYPE
*************************************************************************************/




/**********************************************************************************//**
*                          MACRO
*************************************************************************************/
#define MAX_TIMES 10000
#define RING_BUF_LEN 2100
#define PI 3.1415926
#define INPUT_FILENAME  "sawtooth.data"
#define OUTPUT_FILENAME "fourier.data"


/**********************************************************************************//**
*                         MAIN
*************************************************************************************/
int main(void)
{

    printf("*** 0 ***\n");

    int    index;
    int    dataIndex;
    int    n;
    double  re_val[RING_BUF_LEN];  //リングバッファを作ってください。
    double  im_val[RING_BUF_LEN];
    double input_data_buf[RING_BUF_LEN];
 
    
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
    // ここでリングバッファ状にしてデータを渡したい。RING_BUF_LEN
    while ((fscanf(fpInputData, "%lf", &input_data_buf[index])) != EOF){
        index++;
    }
    dataIndex = index;
    
   

    ft(input_data_buf, dataIndex, re_val, im_val);

    /* Output data */
    for (n = 0; n < 2100; n++){
//        printf("%d %f %f\n", n, re_val[n], im_val[n]);
        fprintf(fpOutputData, "%d %f %f\n", n, re_val[n], im_val[n]);
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
