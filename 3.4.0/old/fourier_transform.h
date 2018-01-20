#ifndef FOURIER_TRANSFORM_H
#define FOURIER_TRANSFORM_H


#define DATA_LEN 2101

/**********************************************************************************//**
*                          DATA TYPE
*************************************************************************************/
typedef struct {
    double real;   //param1
    double imag;   //param2
}TYPE_FT;

TYPE_FT* ft_val;


//ft_val->real
//ft_val->imag

/**********************************************************************************//**
*                          PROTOTYOPE DECLARTION
*************************************************************************************/
void ft(double* pInputData, int ftIndex, double* ft_val.real, double* ft_val.imag);

#endif
