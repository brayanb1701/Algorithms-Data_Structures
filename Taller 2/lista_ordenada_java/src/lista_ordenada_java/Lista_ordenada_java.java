
package lista_ordenada_java;

import java.util.Scanner;


public class Lista_ordenada_java {

    
    public static void main(String[] args) {
        Scanner tec = new Scanner(System.in);
        Lse lista= new Lse();
	Nodo anterior, nuevo, apun;
	char resp;
	anterior = null;
	int opc;

	do {
		System.out.println();
		System.out.println("1. Agregar elementos a la lista  ");
		System.out.println("2. Mostrar lista actual");
		System.out.println("3. Eliminar elementos de la lista");
		System.out.println("4. Salir ");
		System.out.println("Escoja la opcion deseada del anterior menu: ");
		opc=tec.nextInt();
                tec.nextLine();
		System.out.println();
		
		switch (opc)
		{
			case 1:
				lista.agregar();
			break;
			case 2:
				lista.desplegarLista();
			break;
			case 3:
				lista.eliminar();
			break;

		case 4:
			
			break;

		case  5:

			break;
		}

	}while(opc != 4);
    }
    
}
