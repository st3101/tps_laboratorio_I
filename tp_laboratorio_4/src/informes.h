/*
 * informes.h
 *
 *  Created on: 21 jun. 2021
 *      Author: santi
 */

typedef struct
{
	char descripcion[64];
	float valoFob;
	float valorArgMartimo;
	float valorArgAereo;
}Informe;

#ifndef SRC_INFORMES_H_
#define SRC_INFORMES_H_

Informe* inf_new(void);
Informe* inf_newParams(char* descripcion,float fob,float maritimo,float aereo);
int inf_delete(Informe* this);

int inf_setDescripcion(Informe* this,char* descripcion);
int inf_getDescripcion(Informe* this,char* descripcion);

int inf_setValorFob(Informe* this,float valorFob);
int inf_getValorFob(Informe* this,float* valorFob);

int inf_setValorMaritimo(Informe* this,float valorMar);
int inf_getValorMaritimo(Informe* this,float* valorMar);

int inf_setValorAereo(Informe* this,float valorAer);
int inf_getValorAereo(Informe* this,float* valorAer);

int inf_infomar(Dictionary* art,Dictionary* ara,Maritimo esMaritimo,Aereo esAereo);
int inf_informarOrd(Dictionary* art,Dictionary* ara,Maritimo esMaritimo,Aereo esAereo,Dictionary* dictInf);

int inf_calCostoArgentino(float baseImponible,Arancel* pAracel,float* resultado);

int inf_calBaseImponible(Articulo* art,Arancel* ara,float flete,float* resultado);
int inf_calFleteMaritimo(Articulo* art,Maritimo esMaritimo,float* resultado);

int inf_claFleteAereo(Articulo* art,Aereo esAereo,float* resultado);
int inf_ordenarPorValorMaritimo(void* p1, void* p2);

Arancel* inf_getArancelDeUnArticulo(Articulo* pArticulo,Dictionary* ara);

#endif /* SRC_INFORMES_H_ */
