#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::string;

int MCD (int, int);
void calculadoraPrimos(int* );
void printArray(int*, int);	
void freeArray(int* );
string ReglaAritmetica(int, int*);

int main()
{
	int respuesta=1;
	int opcion;
	while(respuesta==1)
	{
		cout<<"Ingrese la opcion que desea ingresar: "<<endl;
		cout<<"Ejercicio 1"<<endl;
		cout<<"Ejercicio 2"<<endl;
		cout<<"Ejercicio 3"<<endl;
		cin>>opcion;
		while(opcion<0 || opcion>3)
		{
			cout<<"Ingrese una opcion entre 1 y 3"<<endl;
			cin>>opcion;
		}
		int numero1=0;
		int numero2=0;
		int ejercicio1=0; 
		int n1;
		int ejercicio2=0;
		int* primos=new int[25];
		switch(opcion)
		{
			case 1:
			       cout<<"Ingrese el primer numero: "<<endl;
		       		cin>>numero1;
		 		cout<<"Ingrese el segundo numero: "<<endl;
				cin>>numero2;
			while(numero1<=numero2 || numero1<0 || numero2<0)
				{
					cout<<"Los numeros no son validos"<<endl;
					cout<<"Ingrese el primer numero: "<<endl;
	                                cin>>numero1;
        	                        cout<<"Ingrese el segundo numero: "<<endl;
                	                cin>>numero2;
				}
				ejercicio1=MCD(numero1, numero2);
				cout<<"El maximo comun divisor de ambos numeros es "<<ejercicio1<<endl;
			break;
			case 2: 
				calculadoraPrimos(primos);
				cout<<"Ingrese el numero que desea: "<<endl;
				cin>>ejercicio2;
				cout<<"La cadena resultante es: "<<ReglaAritmetica(ejercicio2, primos);
				freeArray(primos);
			break;

		}
		cout<<endl<<"Desea repetir el programa? 1. Si  2. No"<<endl;
		cin>>respuesta;		
	}

	return 0;
}

int MCD (int numero1, int numero2)
{

	if(numero2==0)
	{
		return numero1;
	}	
	else
	{
		int residuo=0;
		residuo=numero1%numero2;
		numero1=numero2;
		numero2=residuo;
		MCD(numero1, numero2);
	}	
}
	

void  calculadoraPrimos(int* primos)
{
	primos[0]=2;
	primos[1]=3;
	primos[2]=5;
	primos[3]=7;
	primos[4]=11;
	primos[5]=13;
	primos[6]=17;
	primos[7]=19;
	primos[8]=23;
	primos[9]=29;
	primos[10]=31;
	primos[11]=37;
	primos[12]=41;
	primos[13]=43;
	primos[14]=47;
	primos[15]=53;
	primos[16]=59;
	primos[17]=61;
	primos[18]=67;
	primos[19]=71;
	primos[20]=73;
	primos[21]=79;
	primos[22]=83;
	primos[23]=89;
	primos[24]=97;
}

void freeArray(int * array)
{
        if(array!=NULL)
        {
                delete[]array;
                array=NULL;
        }
}

void printArray(int* array, int size)
{
        cout<<"El contenido del arreglo es: ";
                for(int i=0; i<size; i++)
                {
                                cout<<array[i]<<" ";
                }

}

string ReglaAritmetica(int numero, int* primos)
{
	stringstream cadena;
	int contador=0;	
	for(int i=0; i<25;i++)
	{
		while(numero%primos[i]==0)
		{
			cout<<primos[i]<<" - "<<endl;
			contador=contador+1;
			numero=numero/primos[i];
		}
		if(contador>0)
		{
			cadena<<"("<<primos[i]<<"^"<<contador<<")*";
			
		}
		if (numero==1)
		{
			i=1000;
		}	
		contador=0;
	}
	return cadena.str();

}

