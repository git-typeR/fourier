/**********************************************************************

    \brief     This program is to make the sawtooth wave and 
               output the data.

    \atuthor   Ryota

    \version   1.0.0

    \date      09/07/2017 11:28:10 

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMES 100

int main(){

    int i, m, n;
    double sawtooth_period, sawtooth_val[MAX_TIMES];

    n = 0;
    
    FILE *fp;

    if ((fp = fopen("sawtooth.data", "w")) == NULL){
        remove("sawtooth.data");
    }

    fp = fopen ("sawtooth.data", "w");

    for (sawtooth_period = -1.0; sawtooth_period < 1.0; sawtooth_period += 0.1){
        sawtooth_val[n] = sawtooth_period;
        n++;
    }

    for (i = 0; i < MAX_TIMES; i++){
        for (m = 0; m < n; m++){
            fprintf(fp,"%f\n",sawtooth_val[m]);
        }
    }

    fclose(fp);
    return 0;
}
