/*
 * informes.c
 *
 *  Created on: 21 jun. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include "articulo.h"
#include "maritimo.h"
#include "arancel.h"
#include "aereo.h"
#include "informes.h"
#include "string.h"
#include "utn.h"
#include "collections/LinkedList.h"
#include "collections/Dictionary.h"

Informe* inf_new(void)
{
	return (Informe*) malloc(sizeof(Informe));
}
int inf_calBaseImponible(Articulo* art,Arancel* ara,float flete,float* resultado)
{
	int retorno=1;

	float bufferValorFob;
	float bufferSeguro;
	if(art != NULL && ara != NULL && flete > 0)
	{

		if(!art_getValorFob(art, &bufferValorFob) && !ara_getSeguro(ara, &bufferSeguro))
		{
			*resultado=bufferValorFob+((bufferValorFob*bufferSeguro)/100)+flete;
			retorno = 0;
		}
	}

	return retorno;
}
Informe* inf_newParams(char* descripcion,float fob,float maritimo,float aereo)
{
	Informe* pArticulo = inf_new();

	if(pArticulo != NULL && descripcion != NULL && fob > 0 &&  maritimo > 0  && aereo >0)
	{
		if(inf_setDescripcion(pArticulo,descripcion) || inf_setValorFob(pArticulo, fob) || inf_setValorMaritimo(pArticulo,maritimo) || inf_setValorAereo(pArticulo,aereo))
		{
			inf_delete(pArticulo);
			pArticulo=NULL;
		}
	}
	return pArticulo;
}
int inf_delete(Informe* this)
{
	int retorno=1;

	if(this != NULL)
	{
		free(this);
		retorno=0;
	}
	return retorno;
}

int inf_setDescripcion(Informe* this,char* descripcion)
{
		int retorno = 1;

		if(this != NULL)
		{
			strcpy(this->descripcion,descripcion);
			retorno = 0;
		}

		return retorno;
}
int inf_getDescripcion(Informe* this,char* descripcion)
{
	int retorno = 1;
	if(this != NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 0;
	}
	return retorno;
}
int inf_setValorFob(Informe* this,float valorFob)
{
	int retorno = 1;
	if(this != NULL)
	{
		this->valoFob = valorFob;
		retorno = 0;
	}
	return retorno;
}
int inf_getValorFob(Informe* this,float* valorFob)
{
	int retorno = 1;
	if(this != NULL)
	{
		*valorFob = this->valoFob;
		retorno = 0;
	}
	return retorno;
}
int inf_setValorMaritimo(Informe* this,float valorMar)
{
	int retorno = 1;
	if(this != NULL)
	{
		this->valorArgMartimo = valorMar;
		retorno = 0;
	}
	return retorno;
}
int inf_getValorMaritimo(Informe* this,float* valorMar)
{
	int retorno = 1;
	if(this != NULL)
	{
		*valorMar = this->valorArgMartimo;
		retorno = 0;
	}
	return retorno;
}

int inf_setValorAereo(Informe* this,float valorAer)
{
	int retorno = 1;
	if(this != NULL)
	{
		this->valorArgAereo = valorAer;
		retorno = 0;
	}
	return retorno;
}

int inf_getValorAereo(Informe* this,float* valorAer)
{
	int retorno = 1;
	if(this != NULL)
	{
		*valorAer = this->valorArgAereo;
		retorno = 0;
	}
	return retorno;
}


int inf_claFleteAereo(Articulo* art,Aereo esAereo,float* resultado)
{
	int retorno=1;

	float pesoReal;
	float pesoVolumetrico;

	float pesoEnKilosArt;
	float valorPorKiloAer;

	float anchoCmArt;
	float altoCmArt;
	float profundidadCmArt;

	float constanteVolumetricaAer;

	if(art != NULL)
	{
		if(!art_getPesoEnKilos(art, &pesoEnKilosArt) && !aer_getvalorPorKilor(&esAereo, &valorPorKiloAer) && !art_getAnchoCm(art, &anchoCmArt) && !art_getAltoCm(art, &altoCmArt) && !art_getProfundidaCm(art, &profundidadCmArt) && !aer_getconstanteVolumetrica(&esAereo, &constanteVolumetricaAer))
		{
			pesoReal=(pesoEnKilosArt) *valorPorKiloAer; //POSIBLE ERROR PROFE AL CALCULAR

			pesoVolumetrico=((anchoCmArt*altoCmArt*profundidadCmArt)/6000) *valorPorKiloAer;

			retorno = 0;
			if(pesoReal>pesoVolumetrico)
			{
				*resultado=pesoReal;

			}else
			{
				*resultado=pesoVolumetrico;
			}

		}


	}
	return retorno;
}
int inf_calFleteMaritimo(Articulo* art,Maritimo esMaritimo,float* resultado)
{
	int retorno = 1;

	float bufferAncho;
	float bufferAlto;
	float bufferProfundidad;

	float bufferMcubicos;
	float bufferValorContenedor;

	if(art != NULL)
	{
		if(!art_getAnchoCm(art, &bufferAncho) && !art_getAltoCm(art, &bufferAlto) && !art_getProfundidaCm(art, &bufferProfundidad) && !mar_getMcubicos(&esMaritimo, &bufferMcubicos) && ! mar_getValorDelcontenedor(&esMaritimo, &bufferValorContenedor))
		{
			*resultado= ((bufferAncho * bufferAlto * bufferProfundidad) / 1000000) * (bufferValorContenedor / bufferMcubicos);
			retorno = 0;
		}
	}
	return retorno;
}

Arancel* inf_getArancelDeUnArticulo(Articulo* pArticulo,Dictionary* ara)
{
	Arancel* pArancel;
	char auxPosicionArancelari[64];

	if(pArticulo != NULL && ara != NULL && !art_getPosicionAranceleria(pArticulo, auxPosicionArancelari))
	{
		pArancel=dict_get(ara, auxPosicionArancelari);
	}
	return pArancel;
}
int inf_calCostoArgentino(float baseImponible,Arancel* pAracel,float* resultado)
{
	int retorno=1;
	float porcentajeDeImportacion;
	float tasaEstadistica;

	if(baseImponible > 0 && pAracel != NULL)
	{
		if(!ara_getPorcentajeDeImportacion(pAracel, &porcentajeDeImportacion) && !ara_getTasaEstadistica(pAracel, &tasaEstadistica))
		{
			*resultado=baseImponible + (baseImponible*(porcentajeDeImportacion/100))+ (baseImponible*(tasaEstadistica/100));
			retorno = 0;
		}
	}
	return retorno;
}
int inf_infomar(Dictionary* DicArt,Dictionary* DicAra,Maritimo esMaritimo,Aereo esAereo)
{
	int retono = 1;
	LinkedList* listArticulos;
	Articulo* pArticulo;
	Arancel* pArancel;

	float fleteMaritimo;
	float fleteAereo;
	float baseImponibleMartimo;
	float baseImponibleAereo;
	float costoArgentinoMaritimo;
	float costoArgentinoAereo;


	if(DicArt != NULL && DicAra != NULL)
	{
		listArticulos=dict_getValues(DicArt);

		if(listArticulos != NULL)
		{
			for(int i=0;i<ll_len(listArticulos);i++)
			{
				pArticulo=ll_get(listArticulos, i);

				if(pArticulo != NULL)
				{
					pArancel=inf_getArancelDeUnArticulo(pArticulo, DicAra);

					if(pArancel != NULL)
					{
						printf("%-15s%-20s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","CODIGO","DESCIPCION","ORIGEN","FOB","PESO","AMCHO","ALTO","PROFUNDIDAD","POSICION ARANCELARIA");

						if(!art_ListUno(pArticulo) && !inf_calFleteMaritimo(pArticulo, esMaritimo, &fleteMaritimo) && !inf_calBaseImponible(pArticulo, pArancel, fleteMaritimo, &baseImponibleMartimo) && !inf_claFleteAereo(pArticulo, esAereo, &fleteAereo) && !inf_calBaseImponible(pArticulo, pArancel, fleteAereo, &baseImponibleAereo))
						{
							if(!inf_calCostoArgentino(baseImponibleMartimo, pArancel, &costoArgentinoMaritimo) && !inf_calCostoArgentino(baseImponibleAereo, pArancel, &costoArgentinoAereo))
							{
								printf("COSTO ARGENTINA    Maritimo: %-20fAereo: %f \n-------------------------------------------------------------------------------------------------------------------------------------------------\n",costoArgentinoMaritimo,costoArgentinoAereo);
								retono = 0;
							}
						}
					}
				}
			}
		}
	} //descipcion valorFob nacionali Maritimo 20fAereo

	return retono;
}
int inf_ordenarPorValorMaritimo(void* p1, void* p2)
{
    float fob1;
    float fob2;
    int retorno = 0;

    Informe* pArticulo1;
    Informe* pArticulo2;

    pArticulo1=(Informe*)p1;
    pArticulo2=(Informe*)p2;

    fob1=pArticulo1->valorArgMartimo;
    fob2=pArticulo2->valorArgMartimo;

    if(fob1 > fob2)
    {
        retorno = 1;
    }
    else if(fob1 < fob2)
    {
        retorno = -1;
    }

    return retorno;
}
int inf_informarOrd(Dictionary* DicArt,Dictionary* DicAra,Maritimo esMaritimo,Aereo esAereo,Dictionary* dictInf)
{
	int retono = 1;
	LinkedList* listArticulos;
	LinkedList* listaInformes;
	Articulo* pArticulo;
	Arancel* pArancel;
	Informe* pInforme;
	Informe* pInforme2;

	Articulo auxAr;
	Informe auxIn;
	float fleteMaritimo;
	float fleteAereo;
	float baseImponibleMartimo;
	float baseImponibleAereo;
	float costoArgentinoMaritimo;
	float costoArgentinoAereo;


	if(DicArt != NULL && DicAra != NULL)
	{
		listArticulos=dict_getValues(DicArt);

		if(listArticulos != NULL)
		{
			for(int i=0;i<ll_len(listArticulos);i++)
			{
				pArticulo=ll_get(listArticulos, i);

				if(pArticulo != NULL)
				{
					pArancel=inf_getArancelDeUnArticulo(pArticulo, DicAra);


					if(pArancel != NULL)
					{
						if(!inf_calFleteMaritimo(pArticulo, esMaritimo, &fleteMaritimo) && !inf_claFleteAereo(pArticulo, esAereo, &fleteAereo)
								&& !inf_calBaseImponible(pArticulo, pArancel, fleteMaritimo, &baseImponibleMartimo) && !inf_calBaseImponible(pArticulo, pArancel, fleteAereo, &baseImponibleAereo)
								&& !inf_calBaseImponible(pArticulo, pArancel, fleteAereo, &baseImponibleAereo) && !inf_calCostoArgentino(baseImponibleAereo, pArancel, &costoArgentinoAereo)
								&& !inf_calCostoArgentino(baseImponibleMartimo, pArancel, &costoArgentinoMaritimo))
						{
							if(!art_getDescripcion(pArticulo, auxAr.descripcion) && !art_getValorFob(pArticulo, &auxAr.valorFob))
							{
								pInforme=inf_newParams(auxAr.descripcion, auxAr.valorFob, costoArgentinoMaritimo, costoArgentinoAereo);

								if(pInforme != NULL)
								{
									dict_insert(dictInf,pInforme->descripcion, pInforme);

								}
							}

						}
					}
				}
			}

			listaInformes=dict_getValues(dictInf);

			ll_sort(listaInformes,inf_ordenarPorValorMaritimo, 0);

			for(int i=0;i<ll_len(listaInformes);i++)
			{
				pInforme2=ll_get(listaInformes, i);

				if(!inf_getDescripcion(pInforme2, auxIn.descripcion) && !inf_getValorFob(pInforme2, &auxIn.valoFob) && !inf_getValorMaritimo(pInforme2, &auxIn.valorArgMartimo) && !inf_getValorAereo(pInforme2, &auxIn.valorArgAereo))
				{
					printf("%-6s %-15f\nValor Maritimo:%f\nValor Aereo:%f\n-------------------------------------------------------\n",auxIn.descripcion,auxIn.valoFob,auxIn.valorArgMartimo,auxIn.valorArgAereo);
					retono=0;
				}

				//printf("%-6s %-15f\nValor Maritimo:%f\nValor Aereo:%f\n-------------------------------------------------------\n",pInforme2->descripcion,pInforme2->valoFob,pInforme2->valorArgMartimo,pInforme2->valorArgAereo);
			}
		}
	} //descipcion valorFob nacionali Maritimo 20fAereo

	return retono;
}
