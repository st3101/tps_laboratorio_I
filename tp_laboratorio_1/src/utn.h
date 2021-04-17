/*
 * utn.h
 *
 *  Created on: 15 abr. 2021
 *      Author: santi
 */

#ifndef SRC_UTN_H_
#define SRC_UTN_H_

int utn_getString(char* string,char* mensaje,char* mensajeError);
int utn_getInt(int* pEntero,char* mensaje,char* mensajeError);
int utn_getfloat(float* pFloat,char* mensaje,char* mensajeError);

int utn_validarNumero(char* array);
int utn_validarFloat(char* array);


int utn_getNumeroEntero(int* numero,char* mensaje, char* mensajeError,int reintetos);
int utn_getNumeroFloat(float* numero,char* mensaje, char* mensajeError,int reintetos);

#endif /* SRC_UTN_H_ */
