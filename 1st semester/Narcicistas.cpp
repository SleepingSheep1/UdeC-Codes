/*
Numeros narcicistas 
Un número narcisista es un número de n dígitos, que coincide con la suma de las potencias n-ésimas de sus dígitos

by: SleepingSheep1
*/
#include <iostream>
#include <math.h> 

using namespace std;

int main(){
	/*Varibles declaradas
		n -> Cantidad de numeros a mostrar;
		num -> Variable que se ira sumando, representa todos los numeros y en cada ejecucion del ciclo externo se le suma uno
		numaux -> numero que guarda a num, pero este se modificara en la ejecucion		
		i -> Variable para contar los numeros narcicistas encontrados
		cont_dig -> Varible para saber cuantos digitos tiene la variable narcicista(Sera el exponente)
		suma -> suma los valores de cada potencia en los numeros
		digit -> Es un vector entero en el cual se van guardando todos los digitos para luego poder aplicarle la potencia
	
	*/
	int n,num=1,numaux,i=0,cont_dig;
	int suma,digit[50];
	
	//Pedimos la cantidad de numeros que desea ver el usuario
	cout << "Cuantos numeros desea ver: " << endl;
	cin >> n;
	
	//Ejecutamos un ciclo que se seguira ejecutando hasta que se halle la cantidad pedida
	while(i<n){
		//Se guarda el numero que tenemos en numaux y se reinicializan los contadores que son requeridos
		numaux=num;
		cont_dig=0;
		suma=0;
		//Ciclo interno que calcula la cantidad de digitos, guardando cada digito en un lugar del vector 
		do{
			digit[cont_dig]=numaux%10;
			numaux=numaux/10;
			cont_dig++;	
		}while(numaux>0);
		
		//ciclo que aplica la formula digito^cont_dig a cada digito para saber la suma
		for(int j=1;j<=cont_dig;j++){
			suma+=pow(digit[j-1],cont_dig);
		}
		
		//Si la suma y el num es igual es un numero narcicista asi que se le muestra al usuario y ademas se le suma 1 a i entendiendo que 
		//se encontro un numero narcicista
		if(suma==num){
			cout << num << "\t";
			i++;
		}
		
		//Se suma 1 al numero para que siga aumentado ej: (1,2,3,4,5,...) asi se recorren los numeros hasta que se tengan los narcicistas pedidos
		num++;
	}
	
	return 0;
}
