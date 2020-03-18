// Carlos Daniel Orozco Bravo 351285 441 L2
//**************************************************LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**************************************************PROTOTIPO DE FUNCIONES
int MENU() ;
void PUSH( int pila[] , int *cabeza , int num );
void POP( int pila[] , int *cabeza );
int leenum( int InfLim , int SupLim , char *msg , char *msgError );
void servicio( int num );
void Problema( );
void SACARAUTO( int pila[] , int *cabeza );
void IMPRIMIRPILA( int pila[] );

//**************************************************MAIN
int main()
{
	MENU();
	return 0;
}

//**************************************************MENU
int MENU()
{
	int opcion=0 , cabeza=0 , cabezaautos=0 , auxcabezaautos=0 , num=0 , i , x ;
	int pila[ 10 ]={0} , aux[ 10 ]={0} , pilaautos[ 10 ]={0} ;
	do{
			system( "cls" ) ;
			printf( "M   E   N   U\n\n" ) ;
			printf( "a).\n" ) ;
			printf( "\t1- PUSH.\n" ) ;
			printf( "\t2- POP.\n" ) ;
			printf( "b).\n" ) ;
			printf( "\t3- Un restaurante de comida china cuenta\n" ) ;
			printf( "\tcon un estacionamiento para un maximo\n" ) ;
			printf( "\tde 6 autos, los autos son estacionados en\n" ) ;
			printf( "\tlinea, por orden de llegada.\n" ) ;
			printf( "\tBuscar una solucion usando 1 o 2 pilas.\n" ) ;
			printf( "\n4- Salir.\n" ) ;
			printf("\n\nESCOGE UNA OPCION.\t");
			opcion=leenum( 1 , 4 , "Dame un numero.\t" , "Error.." );
			switch( opcion )
				{
					case 1 :
									system( "cls" );
									if( cabeza <10 )
										{
											num=leenum( 0 , 100 , "Dame un numero.\t" , "Error.." );
                           		PUSH( pila , &cabeza , num );
										}
										else
											{
												printf("Pila llena.\n\n");
												system( "pause" );
											}
									break;
					case 2:
									system( "cls" );
									POP( pila , &cabeza );
									break;
					case 3:
									do{
											system( "cls" ) ;
											printf( "ESTACIONAMIENTO\n\n" ) ;
											printf( "1- Agregar autos\n" ) ;
											printf( "2- Sacar autos\n" ) ;
											printf( "3- Salir a MENU.\n" ) ;
											printf("\n\nESCOGE UNA OPCION.\t");
											opcion=leenum( 1 , 3 , "Dame un numero.\t" , "Error.." );
											switch( opcion )
												{
													case 1 :
																	system( "cls" );
																	if( cabezaautos <10 )
																		{
																			num=leenum( 0 , 100 , "Dame un numero.\t" , "Error.." );
                           										PUSH( pilaautos , &cabezaautos , num );
                           										auxcabezaautos=cabezaautos;
																		}
																		else
																			{
																				printf("Pila llena.\n\n");
																				system( "pause" );
																			}
																	break;
													case 2:
																	system( "cls" );
																	printf("Que auto quieres sacar?.\n");
																	IMPRIMIRPILA( pilaautos );
																	num=leenum( 0 , 9 , "Dame el numero de la posicion de tu auto.\t" , "Error.. Esta posicion no existe." );
																	for( i=cabezaautos ; i>num ; i-- )
																		{
																			aux[ i ]=pilaautos[ i ];
																			POP( pilaautos , &cabezaautos );
																		}
																	IMPRIMIRPILA( aux );
																	for( i=num ; i<auxcabezaautos ; i++ )
																		{
																			pilaautos[ i ]=aux[ i+1 ];
																			x=aux[ i+1 ];
																			PUSH( pilaautos , &cabezaautos , x );
																		}
																	IMPRIMIRPILA( pilaautos );
																	break;
												}
    									}while( opcion !=3 );
									break;
				}
    	}while( opcion !=4 );
}

//**************************************************PUSH
void PUSH( int pila[] , int *cabeza , int num )
{
	pila[ (*cabeza) ]=num;
	(*cabeza)++;
	servicio( num );
}

//**************************************************POP
void POP( int pila[] , int *cabeza )
{
	int num=0 ;
	printf( "POP.\n\n" ) ;
	(*cabeza)--;
	if( (*cabeza)>=0 )
		{
			num=pila[ (*cabeza) ];
			servicio( num );
		}
		else
			{
				printf("Pila vacia.\n\n");
				system( "pause" );
			}
}

//**************************************************VALIDAR NUMERO
int leenum( int InfLim , int SupLim , char *msg , char *msgError )
{
	char strnum[30] ;
	int num ;
	do
		{
			puts( msg ) ;
			fflush( stdin ) ;
			gets( strnum ) ;
			num=atoi( strnum ) ;
			if( num<InfLim || num>SupLim )
				{
					puts( msgError ) ;
					system( "pause" ) ;
				}
		}while( num<InfLim || num>SupLim ) ;
	return num ;
}

//**************************************************SERVICIO
void servicio( int num )
{
	system( "cls" );
	printf( "El numero contenido en esta posicion de la pila es: %d\n\n" , num );
	system( "pause" );
}

//**************************************************SERVICIO
void IMPRIMIRPILA( int pila[] )
{
	system( "cls" );
	int i ;
	for( i=0 ; i<10 ; i++ )
		{
			printf( "posicion %d ---> | %3d |\n" , i , pila[ i ] );
		}
	system( "pause" );
}
