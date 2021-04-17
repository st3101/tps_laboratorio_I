/*
 * calculos.c
 *
 *  Created on: 17 abr. 2021
 *      Author: santi
 */

int cal_suma(float numero1,float numero2,float* resultado)
{
	*resultado = numero1 + numero2;
	return 1;
}

int cal_resta(float numero1,float numero2,float* resultado)
{
	*resultado = numero1 - numero2;
	return 1;
}

int cal_multiplicacion(float numero1,float numero2,float* resultado)
{
	*resultado = numero1 * numero2;
	return 1;
}

int cal_divicion(float numero1,float numero2,float* resultado)
{
	int retorno = 0;

	if(numero2 != 0)
	{
		*resultado = numero1 / numero2;
		retorno = 1;
	}

	return retorno;
}

int cal_factorial(float numero,float* resultado)
{
    int i;
    int retorno = 0;
    float axuliar=1;

    if(numero >= 0)
    {
    	for(i=1;i<=numero;i++)
    	{
    		axuliar=axuliar*i;
    	}

    	retorno = 1;
    }

    *resultado = axuliar;
    return retorno;
}
