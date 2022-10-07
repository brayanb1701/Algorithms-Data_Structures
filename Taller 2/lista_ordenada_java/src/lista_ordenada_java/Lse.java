
package lista_ordenada_java;



import java.util.Scanner;

public class Lse {
    Scanner tec = new Scanner(System.in);
    
	private Nodo  inicial;
	private Nodo  buscarLista(int clave)
{
	Nodo anterior;
	anterior = null;
	if (inicial == null) {
		return anterior;
	}
	else {
		if (clave < inicial.dato)return anterior;
		else
		{
			anterior = inicial;
			while ((anterior.sig != null) && (clave >= anterior.sig.dato))
				anterior = anterior.sig;
			return anterior;
		}
	}
}
Lse()
{
	inicial = null;
}

void desplegarLista()
{
	
	if (inicial == null)
	{
		System.out.println("La lista esta vacia" );
	}
	else
	{
		Nodo apunt;
		apunt = inicial;
		while (apunt != null)
		{
			System.out.println(apunt.dato );
			apunt = apunt.sig;
		}
	}
	
}

void agregar()
{
	Nodo nuevo, anterior;
	char resp;
	
	do
	{
		nuevo = new Nodo();
		System.out.println("Entre clave del Nodo a agregar" );
		nuevo.dato=tec.nextInt();
                tec.nextLine();
		if (inicial == null)
		{
			inicial = nuevo;
			nuevo.sig = null;
		}
		else
		{
			anterior = buscarLista(nuevo.dato);
				if (anterior == null)
				{
					nuevo.sig = inicial;
					inicial = nuevo;
				}
				else
				{
					if (anterior.dato == nuevo.dato) {
						System.out.println("El Nodo a agregar ya existe" );
					}
					else {
						if (anterior.sig != null)
						{
							nuevo.sig = anterior.sig;
							anterior.sig = nuevo;
						}
						else
						{
							nuevo.sig = null;
							anterior.sig = nuevo;
						}
					}
				}
		}
		System.out.println("Desea agregar otro Nodo? (s/n)" );
		resp= tec.nextLine().charAt(0);
                
                
	} while (resp == 's');
	
}

void eliminar() {
	char resp;
	
	do
	{
		int clave;
		System.out.println("Entre clave del Nodo a eliminar" );
		clave=tec.nextInt();
                tec.nextLine();;

		Nodo eliminar;
		eliminar = buscarLista(clave);
		if (eliminar == null) {
			System.out.println("El Nodo no ha sido encontrado" );
		}
		else if (eliminar.dato != clave) {
			System.out.println("El Nodo no ha sido encontrado" );
		}
		else {
			if (eliminar == inicial) {
				inicial = eliminar.sig;
				
			}
			else {
				Nodo aux;
				aux = inicial;
				while (aux.sig != eliminar) {
					aux = aux.sig;
				}
				aux.sig = eliminar.sig;
				

			}
		}

		System.out.println("Desea eliminar otro Nodo? (s/n)" );
		resp= tec.nextLine().charAt(0);
		
	} while (resp == 's');
	
}

}
