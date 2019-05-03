#include <iostream>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int MCD (int, int);


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

		}
		cout<<"Desea repetir el programa? 1. Si  2. No"<<endl;
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
	


