#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::string;
using std::vector;
int MCD (int, int);
void calculadoraPrimos(int* );
void printArray(int*, int);	
void freeArray(int* );
string ReglaAritmetica(int, int*);
string Busqueda(string);
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
		int opcion3=0;
		int op3=0;
		int o=0;
		string temporal;
		string codigo;
		string nombre;
	       	string inicio;
		string fin;
		string pais;
		string continente;
		int paises=0;	
		stringstream a;
		std::vector<string>guerras;
		string buscar;
		stringstream insertar;
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
			case 3:
				cout<<"1. Insertar guerra"<<endl;
				cout<<"2. Buscar guerra"<<endl;
				cout<<"3. Eliminar Guerra"<<endl;
				cout<<"4. Listar Guerra"<<endl;
				cin>>opcion3;
				switch(opcion3)
				{
					case 1:
						cout<<"Ingrese su cogigo: "<<endl;
						cin>>codigo;
						insertar<<codigo<<";";
						cout<<"Ingrese su nombre: "<<endl;
						cin>>nombre;
						insertar<<nombre<<";";
						cout<<"Ingrese ano de inicio: "<<endl;
						cin>>inicio;
						insertar<<inicio<<";";
						cout<<"Ingrese ano de fin: "<<endl;
						cin>>fin;
						insertar<<fin<<";";
						cout<<"Cuantos paises participaron?";
						cin>>paises;
						for(int i=0; i<paises;i++)
						{
							cout<<"Ingrese el pais: "<<endl;
							cin>>pais;
							insertar<<pais<<",";
						}
						insertar<<";";
						cout<<"Ingrese el continente"<<endl;
						cin>>continente;
						insertar<<continente;	
						guerras.push_back(insertar.str());
						cout<<"Guerra ingresada exitosamente "<<endl;
						break;
					case 2:
						cout<<"Ingrese el codigo de la guerra que desea ingresar: ";
						cin>>buscar;
						for(int i=0; i<guerras.size();i++)
						{
							temporal=guerras.at(i);
							for(int j=0; j<temporal.length();j++)
							{
								if(temporal[j]==';')
								{	
									j=1000;
								}
								else
								{
									a<<temporal[j];
								}
							}
							if(a.str()==buscar)
							{

							}
						}
						break;
					case 3:
						break;
					case 4:
						cout<<"1. Listar guerras"<<endl;
						cout<<"2. Listar por continente"<<endl;
						cin>>op3;
						break;	
				}	

		}
		cout<<endl<<"Desea repetir el programa? 1. Si  2. No"<<endl;
		cin>>respuesta;		
	}

	return 0;
}
string Busqueda (string temporal)
{
	stringstream acum;
	for(int i=0; i<temporal.length();i++)
	{
		if(temporal[i]!=';')
		{
			i=1000;	
		
		}	
		else
		{
			acum<<temporal[i];
		}
		
	}
	return acum.str();
	
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

