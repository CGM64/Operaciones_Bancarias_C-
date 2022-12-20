#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct nodo{ 
	char dpi[14];
	char nombre[41];
	char tipoTransaccion[41];
	float cantidad;
	struct nodo *sigte;
}*Tlista;

void menu();
void insertarInicio(Tlista &lista);
void insertarFinal(Tlista &lista);
void insertarNodoXPosicion(Tlista &lista);
void eliminarNodo(Tlista &lista);
void buscarYModificarNodo(Tlista &lista);
void mostrarNodosLista(Tlista lista);
void reportes();
void reportesMonetarios(Tlista lista);
void reportesDeAhorros(Tlista lista);

int main() {
	setlocale (LC_CTYPE, "spanish");
		
    Tlista lista = NULL;
    
    int op;
    int op2;
    
    system("COLOR 9F");
    
    do {
    	system("cls");
        menu();
		cin>> op;
		
		fflush(stdin);
		
        switch(op) { 
            case 1:
                system("cls");
                
                insertarInicio(lista); 
			break;
			
            case 2:
            	system("cls");
            	
            	insertarFinal(lista);  
			break;
			
            case 3:
            	system("cls");
            	
            	insertarNodoXPosicion(lista);  
			break;
			
            case 4:
            	system("cls");
            	
                eliminarNodo(lista); 
			break;
			
            case 5:
            	system("cls");
            	
                buscarYModificarNodo(lista);  
			break;
			
            case 6:
            	system("cls");
            	
                mostrarNodosLista(lista); 
			break;
			
			case 7:
				system("cls");
				
				do{
					system("cls");
					
					reportes();
					cin>> op2;
					
					fflush(stdin);
					
					switch(op2){
						case 1:
							system("cls");
							
							reportesMonetarios(lista);
						break;
						
						case 2:
							system("cls");
							
							reportesDeAhorros(lista);
						break;
					};
					
					cout<<endl<<endl;
        
					system("pause");
				}while(op2 != 3);
			break;
        };
        
        cout<<endl<<endl;
        
		system("pause");
    } while ( op != 8 );
    
    system("cls");
    
    cout<<"Gracias por utilizar el sistema bancario de Banco Financieros Exitosos S. A.\n\t\t\t¡Vuelva pronto!" <<endl <<endl;
    
    return 0;  
}

void menu() {
    cout<<"\n   Banco Financieros Exitosos S. A." <<endl <<endl;
    cout<<" 1.Insertar al inicio"<<endl;
    cout<<" 2.Insertar al final"<<endl;
    cout<<" 3.Insertar en cualquier parte"<<endl;
    cout<<" 4.Eliminar"<<endl;
    cout<<" 5.Buscar y modificar"<<endl;
    cout<<" 6.Mostrar"<<endl;
    cout<<" 7.Reportes"<<endl;
    cout<<" 8.Salir del programa"<<endl <<endl;
    cout<<" Ingrese una opción: "; 
}

void insertarInicio(Tlista &lista) {
	Tlista buscarAgregar, aux;
	
	//
	Tlista q;
    q = new(struct nodo);
    
    string dpiA;
    string tipoTransaccion;
    
    cout<<"\t Buscar y agregar datos clientes al inicio" <<endl; 
	cout<< " DPI: "; 
	cin>> dpiA; 
	
	fflush(stdin);
         
    buscarAgregar = lista;
    
    while (buscarAgregar != NULL) {
    	if (buscarAgregar->dpi == dpiA) {
			cout << "\n\n\tCliente encontrado, proceda a llenar sus datos:" <<endl;
			cout << "  DPI Cliente" <<"\t\tNombre Cliente"  <<endl;
    	
			//Lista de datos pertenecientes a uno y/o varios clientes
    		cout<<" " <<lista->dpi <<"\t "<<lista->nombre <<endl <<endl;
        	
        	strcpy(q->dpi, lista->dpi);
        	strcpy(q->nombre, lista->nombre);
        	
    		q->sigte = lista;
			lista  = q;
			
			//Para mostrar los datos
			lista = lista->sigte;
        	
			cout << "\t =============================================" <<endl;
			
			fflush(stdin);
			
			do{
				cout<<" Tipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
				cin>> tipoTransaccion;
			
				if(tipoTransaccion == "DM"){
					strcpy(q->tipoTransaccion, "Depósito Monetario");
				}
				else if(tipoTransaccion == "RM"){
					strcpy(q->tipoTransaccion, "Retiro Monetario");
				}
				else if(tipoTransaccion == "DA"){
					strcpy(q->tipoTransaccion, "Depósito de Ahorros");
				}
				else if(tipoTransaccion == "RA"){
					strcpy(q->tipoTransaccion, "Retiro de Ahorros");
				}
				else{
					cout<<" \nValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
					system("pause");
			
					cout<<endl;
			
					//Limpia los datos almacenados en la variable tipoTransaccion
					fflush(stdin);
				}
			}while((tipoTransaccion != "DM" && tipoTransaccion != "RM") && (tipoTransaccion != "DA" && tipoTransaccion != "RA"));
	
			fflush(stdin);
	
			cout<<" Cantidad: Q.";
			cin >> q-> cantidad;

    		q->sigte = lista;
    		lista  = q;
				
			system("pause");
				
			return;
        }
        else {
	        aux = buscarAgregar;
	        buscarAgregar = aux->sigte;
	            
		}
    }
        
    cout << "\n El cliente con el No. de DPI  " <<dpiA << " buscado, no fue encontrado." <<endl;
    cout<<"\t\t  Proceda a llenar sus datos" <<endl <<endl;
	cout<< " DPI: ";
	cin.getline(q->dpi, 14, '\n');
	cout<< " Nombre: ";
	cin.getline(q->nombre, 41, '\n');
	
	do{
		cout<<" Tipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
		cin>> tipoTransaccion;
			
		if(tipoTransaccion == "DM"){
			strcpy(q->tipoTransaccion, "Depósito Monetario");
		}
		else if(tipoTransaccion == "RM"){
			strcpy(q->tipoTransaccion, "Retiro Monetario");
		}
		else if(tipoTransaccion == "DA"){
			strcpy(q->tipoTransaccion, "Depósito de Ahorros");
		}
		else if(tipoTransaccion == "RA"){
			strcpy(q->tipoTransaccion, "Retiro de Ahorros");
		}
		else{
			cout<<" \nValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
			system("pause");
			
			cout<<endl;
			
			//Limpia los datos almacenados en la variable tipoTransaccion
			fflush(stdin);
		}
	}while((tipoTransaccion != "DM" && tipoTransaccion != "RM") && (tipoTransaccion != "DA" && tipoTransaccion != "RA"));
	
	fflush(stdin);
	
	cout<<" Cantidad: Q.";
	cin >> q-> cantidad;

    q->sigte = lista;
    lista  = q;
	
}

void insertarFinal(Tlista &lista) {
   	Tlista t, q = new(struct nodo);
   	
   	Tlista buscarAgregar, aux;
   	
   	string dpiA;
   	string tipoTransaccion;
   	
   	cout<<"\t\t Insertar al final" <<endl <<endl;
   	cout<<"\t Buscar y agregar datos clientes al final" <<endl; 
	cout<< " DPI: "; 
	cin>> dpiA; 
	
	fflush(stdin);
         
    buscarAgregar = lista;
    
    while (buscarAgregar != NULL) {
    	if (buscarAgregar->dpi == dpiA) {
    		//No funciona bien
			cout << "\n\n\tCliente encontrado, proceda a llenar sus datos:" <<endl <<endl;
			cout << "\t\tDatos del cliente encontrado" <<endl <<endl;
			cout << "  DPI Cliente" <<"\t\tNombre Cliente"  <<endl;
    	
			//Lista de datos pertenecientes a uno y/o varios clientes
    		cout<<" " <<lista->dpi <<"\t "<<lista->nombre <<endl;
    		
    		//Copia  el DPI y nombre del cliente encontrado, en la siguiente lista enlazada, en los campos correspondientes a donde apunta el apuntador
    		strcpy(q->dpi, lista->dpi);
        	strcpy(q->nombre, lista->nombre);
    		
    		q->sigte = lista;
			lista  = q;
        	
			//Para mostrar los datos
			lista = lista->sigte;
        	
			cout << "\t =============================================" <<endl;
			
			fflush(stdin);
	
			do{
				cout<<" Tipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
				cin>> tipoTransaccion;
			
				if(tipoTransaccion == "DM"){
					strcpy(q->tipoTransaccion, "Depósito Monetario");
				}
				else if(tipoTransaccion == "RM"){
					strcpy(q->tipoTransaccion, "Retiro Monetario");
				}
				else if(tipoTransaccion == "DA"){
					strcpy(q->tipoTransaccion, "Depósito de Ahorros");
				}
				else if(tipoTransaccion == "RA"){
					strcpy(q->tipoTransaccion, "Retiro de Ahorros");
				}
				else{
					cout<<" \nValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
					system("pause");
			
					cout<<endl;
			
					//Limpia los datos almacenados en la variable tipoTransaccion
					fflush(stdin);
				}
			}while((tipoTransaccion != "DM" && tipoTransaccion != "RM") && (tipoTransaccion != "DA" && tipoTransaccion != "RA"));
	
			fflush(stdin);
	
			cout<<" Cantidad: Q.";
			cin >> q-> cantidad;

    		q->sigte = NULL;
 
    		if(lista==NULL) {
				lista = q;
			}
   		 	else {
        		t = lista;
        		while ( t->sigte != NULL) {
            		t = t->sigte;
        		}
        		t->sigte = q;
   			}
				
			system("pause");
				
			return;
        }
        else {
	        aux = buscarAgregar;
	        buscarAgregar = aux->sigte;
	            
		}
	}
	
	cout << "\n El cliente con el No. de DPI  " <<dpiA << " buscado, no fue encontrado." <<endl;
    cout<<"\t\t  Proceda a llenar sus datos" <<endl <<endl;
    
    //q->numero  = valor;
    cout<<"\t Datos clientes" <<endl;
	cout<< " DPI: ";
	cin.getline(q->dpi, 14, '\n');
	cout<< " Nombre: ";
	cin.getline(q->nombre, 41, '\n');
	
	fflush(stdin);
	
	do{
		cout<<" Tipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
		cin>> tipoTransaccion;
			
		if(tipoTransaccion == "DM"){
			strcpy(q->tipoTransaccion, "Depósito Monetario");
		}
		else if(tipoTransaccion == "RM"){
			strcpy(q->tipoTransaccion, "Retiro Monetario");
		}
		else if(tipoTransaccion == "DA"){
			strcpy(q->tipoTransaccion, "Depósito de Ahorros");
		}
		else if(tipoTransaccion == "RA"){
			strcpy(q->tipoTransaccion, "Retiro de Ahorros");
		}
		else{
			cout<<" \nValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
			system("pause");
			
			cout<<endl;
			
			//Limpia los datos almacenados en la variable tipoTransaccion
			fflush(stdin);
		}
	}while((tipoTransaccion != "DM" && tipoTransaccion != "RM") && (tipoTransaccion != "DA" && tipoTransaccion != "RA"));
	
	cout<<" Cantidad: Q.";
	cin >> q-> cantidad;

    q->sigte = NULL;
 
    if(lista == NULL) {
		lista = q;
	}
    else {
        t = lista;
        while (t->sigte != NULL) {
            t = t->sigte;
       	}
        t->sigte = q;
    }
}

int insertarAntesDespues() {
    int opcion, bandera=0;
    
    cout<<" 1.Antes de la posición" <<endl;
    cout<<" 2.Despues de la posición" <<endl <<endl;
    cout<< "Opción : "; 
	cin>> opcion;
 
    if(opcion == 1) 
		bandera = -1;

    	return bandera;
}

void insertarNodoXPosicion(Tlista &lista) {
	//Cuando se inserta un nodo en éste modo, se inserta antes o después, del último nodo registrado
	
    Tlista q, t;
    int i = 1, pos;
    
    q = new(struct nodo);
    
    Tlista buscarAgregar, aux;
    
    string dpiA;
    string tipoTransaccion;
    
    cout<<"\t Buscar y agregar datos clientes al inicio" <<endl; 
	cout<< " DPI: "; 
	cin>> dpiA; 
	
	fflush(stdin);
         
    buscarAgregar = lista;
    
    while (buscarAgregar != NULL) {
    	if (buscarAgregar->dpi == dpiA) {
			cout << "\n\n\tCliente encontrado, proceda a llenar sus datos:" <<endl;
			cout << "  DPI Cliente" <<"\t\tNombre Cliente"  <<endl;
    	
			//Lista de datos pertenecientes a uno y/o varios clientes
    		cout<<" " <<lista->dpi <<"\t "<<lista->nombre <<endl <<endl;
        	
        	strcpy(q->dpi, lista->dpi);
        	strcpy(q->nombre, lista->nombre);
        	
    		q->sigte = lista;
			lista  = q;
			
			//Para mostrar los datos
			lista = lista->sigte;
        	
			cout << "\t =============================================" <<endl;
			
			fflush(stdin);
			
			do{
				cout<<" Tipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
				cin>> tipoTransaccion;
			
				if(tipoTransaccion == "DM"){
					strcpy(q->tipoTransaccion, "Depósito Monetario");
				}
				else if(tipoTransaccion == "RM"){
					strcpy(q->tipoTransaccion, "Retiro Monetario");
				}
				else if(tipoTransaccion == "DA"){
					strcpy(q->tipoTransaccion, "Depósito de Ahorros");
				}
				else if(tipoTransaccion == "RA"){
					strcpy(q->tipoTransaccion, "Retiro de Ahorros");
				}
				else{
					cout<<" \nValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
					system("pause");
			
					cout<<endl;
			
					//Limpia los datos almacenados en la variable tipoTransaccion
					fflush(stdin);
				}
			}while((tipoTransaccion != "DM" && tipoTransaccion != "RM") && (tipoTransaccion != "DA" && tipoTransaccion != "RA"));
	
			fflush(stdin);
	
			cout<<" Cantidad: Q.";
			cin >> q-> cantidad;

    		cout<< "\n ¿En qué posicion de la lista?: "; 
			cin>> pos;

    		if(pos == 1) {
        		q->sigte = lista;
        		lista = q;
        
        		return;
    		}
    		else {
        		int x = insertarAntesDespues();
        		t = lista;
 		
 				while (t != NULL) {
            		if(i == pos + x) {
                		q->sigte = t->sigte;
                		t->sigte = q;
                
                		return;
            		}
            		
            		t = t->sigte;
            
            		i++;
				}
    		}
    		
    		cout<<"¡Error...posicion no encontrada..!"<<endl;
				
			system("pause");
				
			return;
        }
        else {
	        aux = buscarAgregar;
	        buscarAgregar = aux->sigte;
	            
		}
    }
    
    cout << "\n El cliente con el No. de DPI  " <<dpiA << " buscado, no fue encontrado." <<endl;
    cout<<"\t\t  Proceda a llenar sus datos" <<endl <<endl;
	cout<< " DPI: ";
	cin.getline(q->dpi, 14, '\n');
	cout<< " Nombre: ";
	cin.getline(q->nombre,41,'\n');
	
	do{
		cout<<" Tipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
		cin>> tipoTransaccion;
			
		if(tipoTransaccion == "DM"){
			strcpy(q->tipoTransaccion, "Depósito Monetario");
		}
		else if(tipoTransaccion == "RM"){
			strcpy(q->tipoTransaccion, "Retiro Monetario");
		}
		else if(tipoTransaccion == "DA"){
			strcpy(q->tipoTransaccion, "Depósito de Ahorros");
		}
		else if(tipoTransaccion == "RA"){
			strcpy(q->tipoTransaccion, "Retiro de Ahorros");
		}
		else{
			cout<<" \nValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
			system("pause");
			
			cout<<endl;
			
			//Limpia los datos almacenados en la variable tipoTransaccion
			fflush(stdin);
		}
	}while((tipoTransaccion != "DM" && tipoTransaccion != "RM") && (tipoTransaccion != "DA" && tipoTransaccion != "RA"));
	
	fflush(stdin);
	
	cout<<" Cantidad: Q.";
	cin >> q-> cantidad;
	
	cout<< "\n ¿En qué posicion de la lista?: "; 
	cin>> pos;

    if(pos == 1) {
        q->sigte = lista;
        lista = q;
        
        return;
    }
    else {
        int x = insertarAntesDespues();
        t = lista;
 		
 		while (t != NULL) {
            if(i == pos + x) {
                q->sigte = t->sigte;
                t->sigte = q;
                
                return;
            }
            t = t->sigte;
            
            i++;
		}
    }
    cout<<"¡Error...posicion no encontrada..!"<<endl;
}

void eliminarNodo(Tlista &lista) {
    Tlista borrar, aux;
    string dpiE;
    string tipoTransaccionE;
    float valorExactoE;
    
    cout<<"\t Eliminar datos clientes" <<endl;
	cout<< " DPI: "; 
	cin>> dpiE; 
	cout<< " Tipo de transacción: "; 
	cin>> tipoTransaccionE; 
	cout<< " Valor exacto: Q."; 
	cin>> valorExactoE;
         
    if ( lista != NULL) {
    	borrar = lista;
        while ( borrar != NULL ) {
            if ( borrar->dpi == dpiE && borrar->tipoTransaccion == tipoTransaccionE && borrar->cantidad == valorExactoE) {
            	//Verifica si es el primer nodo de la lista
                if ( borrar->dpi == lista->dpi && borrar->tipoTransaccion == tipoTransaccionE && borrar->cantidad == valorExactoE) {
                    lista = borrar->sigte;                	
				}
                else {
                    aux->sigte = borrar->sigte;                	
				}
				
                delete(borrar);
                
                cout<<"\n El cliente con el No. de DPI  " <<dpiE << ", tipo de transacción " <<tipoTransaccionE <<" y valor exacto Q." <<valorExactoE <<", fue eliminado satisfactoriamente." <<endl;
                
				return;
            }
            else {
	            aux = borrar;
	            borrar = aux->sigte;
			}
        }
        
        cout<<"\n El cliente con el No. de DPI  " <<dpiE << ", tipo de transacción " <<tipoTransaccionE <<" y valor exacto Q." <<valorExactoE <<" buscados, no fue encontrado." <<endl;
    }
    else
		cout <<"¡Lista vacia..!";
}

void buscarYModificarNodo(Tlista &lista) {
    Tlista buscarModificar, aux;
    
    string dpiBM;
    string tipoTransaccionB;
    string tipoTransaccionBM;
    float valorExactoBM;
    
    cout<<"\t Buscar y modificar datos clientes" <<endl; 
	cout<< " DPI: "; 
	cin>> dpiBM; 
	
	do{
		cout<<" Tipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
		cin>> tipoTransaccionB;
			
		if(tipoTransaccionB == "DM"){
			tipoTransaccionBM = "Depósito Monetario";
		}
		else if(tipoTransaccionB == "RM"){
			tipoTransaccionBM = "Retiro Monetario";
		}
		else if(tipoTransaccionB == "DA"){
			tipoTransaccionBM = "Depósito de Ahorros";
		}
		else if(tipoTransaccionB == "RA"){
			tipoTransaccionBM = "Retiro de Ahorros";
		}
		else{
			cout<<" \nValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
			system("pause");
			
			cout<<endl;
			
			//Limpia los datos almacenados en la variable tipoTransaccion
			fflush(stdin);
		}
	}while((tipoTransaccionB != "DM" && tipoTransaccionB != "RM") && (tipoTransaccionB != "DA" && tipoTransaccionB != "RA")); 
	
	cout<< " Valor exacto: Q."; 
	cin>> valorExactoBM; 
	
	fflush(stdin);
         
    if (lista != NULL) {
    	buscarModificar = lista;
        while (buscarModificar != NULL ) {
            if (buscarModificar->dpi == dpiBM && buscarModificar->tipoTransaccion == tipoTransaccionBM && buscarModificar->cantidad == valorExactoBM) {
            	cout << "\n\n\tCliente encontrado, proceda a llenar sus datos:" <<endl;
				cout << "  DPI Cliente" <<"\t\tNombre Cliente"  <<endl;
    			cout<<" " <<lista->dpi <<"\t "<<lista->nombre <<endl <<endl;
				cout << "\t=============================================" <<endl;
				
				lista = lista->sigte;
				
				cout<< "\n\tNuevo nombre: ";
				cin.getline(buscarModificar->nombre, 41,'\n');
				
				do{
					fflush(stdin);
					
					cout<<"\n\tTipo de transacción (DM= Depósito Monetario, RM= Retiro Monetario, \n DA= Depósito de Ahorros y RA= Retiro de Ahorros): ";
					cin>> tipoTransaccionBM;
			
					if(tipoTransaccionBM == "DM"){
						strcpy(buscarModificar->tipoTransaccion, "Depósito Monetario");
					}
					else if(tipoTransaccionBM == "RM"){
						strcpy(buscarModificar->tipoTransaccion, "Retiro Monetario");
					}
					else if(tipoTransaccionBM == "DA"){
						strcpy(buscarModificar->tipoTransaccion, "Depósito de Ahorros");
					}
					else if(tipoTransaccionBM == "RA"){
						strcpy(buscarModificar->tipoTransaccion, "Retiro de Ahorros");
					}
					else{
						cout<<" \n\tValor incorrecto. Inténtelo nuevamente" <<endl <<endl;
			
						system("pause");
			
						cout<<endl;
			
						//Limpia los datos almacenados en la variable tipoTransaccion
						fflush(stdin);
					}
				}while((tipoTransaccionBM != "DM" && tipoTransaccionBM != "RM") && (tipoTransaccionBM != "DA" && tipoTransaccionBM != "RA"));
				
				fflush(stdin);
				
				cout<< "\n\tNueva cantidad: Q.";
				cin>> buscarModificar->cantidad;
				cout << "\t============================================" <<endl;
				
				system("pause");
				
				return;
            }
            else {
	            aux = buscarModificar;
	            buscarModificar = aux->sigte;
			}
        }
        
        cout << "\n El cliente con el No. de DPI  " <<dpiBM << ", tipo de transacción " <<tipoTransaccionBM <<" y valor exacto Q." <<valorExactoBM <<" buscados, no fue encontrado." <<endl;
    }
    else
		cout <<"¡Lista vacia..!";
}

void mostrarNodosLista(Tlista lista) {
    int i = 1;
    float totalDM = 0.0;
    float totalRM = 0.0;
    float totalDA = 0.0;
    float totalRA = 0.0;
    
    cout << "\n\n\t\t\t\t\tLista clientes" <<endl <<endl;
    if (lista != NULL) {
    	cout << "  DPI Cliente" <<"\t\tNombre Cliente" <<"\t\tTipo transacción cliente" <<"  Cantidad de la transacción" <<endl;
    	
		while(lista != NULL) {
			//Lista de datos pertenecientes a uno y/o varios clientes
    		cout<<" " <<lista->dpi <<"\t "<<lista->nombre<<"\t   " <<lista->tipoTransaccion <<"\t\t Q." <<lista->cantidad <<endl;
    		
    		if(strcmp(lista->tipoTransaccion, "Depósito Monetario") == 0){
    			totalDM = totalDM + lista->cantidad;
			}
    		else if(strcmp(lista->tipoTransaccion, "Retiro Monetario") == 0){ 	
    			totalRM = totalRM + lista->cantidad;
			}
			else if(strcmp(lista->tipoTransaccion, "Depósito de Ahorros") == 0){
				totalDA = totalDA + lista->cantidad;
			}
			else if(strcmp(lista->tipoTransaccion, "Retiro de Ahorros") == 0){
				totalRA = totalRA + lista->cantidad;
			}
    		
        	lista = lista->sigte; 
			
			i++; 
		}
		
		cout<<endl;
		cout<<"==================================================" <<endl;
		cout<<" Total depósitos monetarios: Q." <<totalDM <<endl;
		cout<<" Total retiros monetarios: Q." <<totalRM <<endl;
		cout<<" Total depósitos de ahorros: Q." <<totalDA <<endl;
		cout<<" Total retiros de ahorros: Q." <<totalRA <<endl;
		cout<<"==================================================";
	}
    else cout <<"¡Lista vacia..!";
}

void reportes(){
    cout<<"\n\t  Reportes" <<endl <<endl;
    cout<<" 1.Monetarios"<<endl;
    cout<<" 2.Ahorros" <<endl;
    cout<<" 3.Regresar al menú principal"<<endl <<endl;
    cout<<" Ingrese una opción: ";
}

void reportesMonetarios(Tlista lista){
    int i = 1;
    float totalDM = 0.0;
    float totalRM = 0.0;
    
    Tlista aux;
    
    if (lista != NULL) {
    	cout << "\n\n\tReporte de transacciones monetarias" <<endl <<endl;
		cout<<" Tipo transacción cliente" <<"  Cantidad de la transacción" <<endl;
    	
    	while(lista != NULL) {
    		//Comparación de tipos de transacciones relacioadas con el tipo de transacciones monetarias
    		if(strcmp(lista->tipoTransaccion, "Depósito Monetario") == 0 || strcmp(lista->tipoTransaccion, "Retiro Monetario") == 0){
    			if(strcmp(lista->tipoTransaccion, "Depósito Monetario") == 0){
    				//Lista de datos pertenecientes a uno y/o varios clientes
    				cout<<"    " <<lista->tipoTransaccion <<"\t\t Q." <<lista->cantidad <<endl;
    				
    				totalDM = totalDM + lista->cantidad;
				}
    			else if(strcmp(lista->tipoTransaccion, "Retiro Monetario") == 0){ 
    				//Lista de datos pertenecientes a uno y/o varios clientes
    				cout<<"    " <<lista->tipoTransaccion <<"\t\t Q." <<lista->cantidad <<endl;
    				
    				totalRM = totalRM + lista->cantidad;
				}
				
        		lista = lista->sigte; 
			
				i++; 
			}
			else{
				aux = lista;
	            lista = aux->sigte;
			}
		}
		
		cout<<endl;
		cout<<"==================================================" <<endl;
		cout<<" Total depósitos monetarios: Q." <<totalDM <<endl;
		cout<<" Total retiros monetarios: Q." <<totalRM <<endl;
		cout<<"==================================================";
	}
    else cout <<"¡Lista vacia..!";
}

void reportesDeAhorros(Tlista lista){
    int i = 1;
    float totalDA = 0.0;
    float totalRA = 0.0;
    
    Tlista aux;
    
    if (lista != NULL) {
    	cout << "\n\n\tReporte de transacciones de ahorros" <<endl <<endl;
		cout<<" Tipo transacción cliente" <<"  Cantidad de la transacción" <<endl;
    	
    	while(lista != NULL) {
    		//Comparación de tipos de transacciones relacioadas con el tipo de transacciones de ahorros
    		if(strcmp(lista->tipoTransaccion, "Depósito de Ahorros") == 0 || strcmp(lista->tipoTransaccion, "Retiro de Ahorros") == 0){
    			if(strcmp(lista->tipoTransaccion, "Depósito de Ahorros") == 0){
    				//Lista de datos pertenecientes a uno y/o varios clientes
    				cout<<"    " <<lista->tipoTransaccion <<"\t\t Q." <<lista->cantidad <<endl;
    			
    				totalDA = totalDA + lista->cantidad;
				}
    			else if(strcmp(lista->tipoTransaccion, "Retiro de Ahorros") == 0){
					//Lista de datos pertenecientes a uno y/o varios clientes
    				cout<<"    " <<lista->tipoTransaccion <<"\t\t Q." <<lista->cantidad <<endl;
					 
    				totalRA = totalRA + lista->cantidad;
				}
				
				lista = lista->sigte;
			
				i++;  
			}
			else{
				aux = lista;
	            lista = aux->sigte;
			}
		}
		
		cout<<endl;
		cout<<"==================================================" <<endl;
		cout<<" Total depósitos de ahorros: Q." <<totalDA <<endl;
		cout<<" Total retiros de ahorros: Q." <<totalRA <<endl;
		cout<<"==================================================";
	}
    else cout <<"¡Lista vacia..!";
}
