#include <iostream>
#include <cstring> // string
#include <cstdlib> //rand()
using namespace std;
// **************************
// ** Programa Nro 6
// ** Sandra Parra 
// ** Ordenar Datos con Métodos Quicksort-Heapsort
// ** Inluye:
// ** 1.- Generación aleatoria de números de hasta 3 dígitos
// ** 2.- Imprimir Números Aleatorios
// ** 3.- Ordenar datos por método Quicksort
// ** 4.- Ordenar datos por método Heapsort
// ** 5.- Imprimir datos después de aplicar métodos
// **************************

// Declaraciones

int numerosal[20]; // arreglo de una dimensión para guardar los números de hasta 3 dígitos a ordenar
int numeroord[20]; // arrgelo de una dimensión para guardar los números de hasta 3 dígitos ordenados por Quicksort
int numeroord2[20]; // arrgelo de una dimensión para guardar los números de hasta 3 dígitos ordenados por Heapsort
int i; // contador de posiciones del arreglo


void CargaNumeros()
{
// *******************************
// * Procedimiento para:
// * 1.- Generación aleatoria de números de hasta 3 dígitos haciendo uso de función rand()
// *******************************
	srand ( time(NULL) );
	int aleatorio;
    for (i=0; i<20; i++)
    {
    aleatorio=rand()%1000;
	//cout << " aleatorio : " << aleatorio << endl;
	numerosal[i] = aleatorio;
	numeroord[i] = aleatorio;
	numeroord2[i] = aleatorio;
    }
}	

void intercambiar(int& x, int& y)
{
int aux = x;
x = y;
y = aux;
}

void Quicksort(int (&numeroord)[20], int primero, int ultimo)
{
// *******************************
// * Procedimiento para:
// * 3.- Ordenar datos por método Quicksort
// *******************************
int i, j, central;
double pivote;
central = (primero + ultimo) / 2;
pivote = numeroord[central];
i = primero;
j = ultimo;
do {
while (numeroord[i] < pivote) i++;
while (numeroord[j] > pivote) j--;
if (i <= j)
{
intercambiar(numeroord[i], numeroord[j]);
i++;
j--;
}
}while (i <= j);
if (primero < j)
Quicksort(numeroord, primero, j); // mismo proceso con sublista izqda
if (i < ultimo)
Quicksort(numeroord, i, ultimo); // mismo proceso con sublista drcha
}


void criba1( int (&numeroord2)[20], int raiz, int ultimo)
{
// Procedimiento para Ordenación Heapsort	
bool esMonticulo;
int hijo = 2 * raiz + 1;
esMonticulo = false;
while (hijo <= ultimo && !esMonticulo)
{
// determina el índice del hijo mayor
if (hijo < ultimo )
// único descendiente
if (numeroord2[hijo] < numeroord2[hijo + 1])
hijo++;
// compara raiz con el mayor de los hijos
if (numeroord2[hijo] > numeroord2[raiz])
{

int c = numeroord2[raiz];
numeroord2[raiz] = numeroord2[hijo];
numeroord2[hijo] = c;
raiz = hijo;
}
else
esMonticulo = true;
hijo = 2*raiz+1;
// continúa por la rama de claves mínimas
}
}


void Heapsort(int (&numeroord2)[20], int n)
{
// *******************************
// * Procedimiento para:
// * 4.- Ordenar datos por método Heapsort
// *******************************
{ // Para el arreglo: numeroord2 de n datos en las posiciones 0,1,...n-1
int j;
for (j = (n - 1) / 2; j >= 0; j--)
criba1(numeroord2, j, n-1 );
for (j = n - 1; j >= 1; j--)
{
int c;
c = numeroord2[0];
numeroord2[0] = numeroord2[j];
numeroord2[j] = c;
criba1(numeroord2, 0, j-1 );
}
}	

}

void ListarOrden(int a[], string titulo)
{
// *******************************
// * Procedimiento para:
// * ** 5.- Imprimir datos después de aplicar métodos
// *
// *******************************
 cout << " Listando Números Aleatorios Ordenados Aplicando Método: " << titulo << endl;
 for (i=0; i<20; i++)
 {
   	 cout << "|" << a[i] << "|" ;
 }
  cout << endl;
  cout << endl;
}

void ListarAleatorios()
{	
// *******************************
// * Procedimiento para:
// * ** 2.- Imprimir Números Aleatorios
// *
// *******************************
 cout << " Listando Números Aleatorios " <<  endl;
 for (i=0; i<20; i++)
 {
   	 cout << "|" << numerosal[i] << "|" ;
 }
 cout << endl;
 cout << endl;
 cout << endl;

}

void inicializarvar()
{
  for (i=0; i<20; i++)
  {
     numerosal[i] =0;
     numeroord[i] =0;
     numeroord2[i] =0;
   }  

}

int main()
{
  int seg = 0;
  while (seg != -1)
  {
    inicializarvar(); 
    cout << endl;
	cout << " Introduzca -1 para Salir u otro número para continuar ordenamiento Quicksort-Heapsort " << endl;
	cin  >> seg;
    if (seg != -1)
     {  
    CargaNumeros();
    ListarAleatorios();
    Quicksort(numeroord,0,19);
    ListarOrden(numeroord,"Quicksort");    
    Heapsort(numeroord2, 20);
    ListarOrden(numeroord2, "Heapsort"); 
     } else {
		cout << " Fin de programa Quicksort-Heapsort" ;}
  }  
  
return 0;
}
