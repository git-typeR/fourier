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

#include "fourier_transform.h"

/**********************************************************************************//**
*                          MACRO
*************************************************************************************/
#define MAX_TIMES 10000
#define PI 3.1415926
#define INPUT_FILENAME  "sawtooth.data"
#define OUTPUT_FILENAME "fourier.data"

void ft(double* pInputData, int ftIndex, double* pReal, double* pImag)
{
    printf("*** 4 ***\n");

    int k;
    int n;

    ftIndex = ftIndex - 1;
    printf("%d\n", ftIndex);

    /* Fourier Transform */
    for (n = 0; n < ftIndex; n++){  
       *pReal = *pImag = 0.0;
       for (k = 0; k < ftIndex; k++){
           pReal[n] +=  pInputData[k] * cos(2 * PI * k * n / ftIndex);
           pImag[n] += -pInputData[k] * sin(2 * PI * k * n / ftIndex);
       }
    }

}
