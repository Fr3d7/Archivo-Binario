#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;
	//int contador;
	//int lineas;
};
 void ingresar_estudiante();
void abrir_estudiante();
 void modificar_estudiante();
 //void eliminar_estudiante();
 
int main (){
	abrir_estudiante();
 ingresar_estudiante();
	modificar_estudiante();
   //eliminar_estudiante();

	//eliminar ();         //_estudiante();
	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Estudiante estudiante;
	
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		
		do{
			
			if (estudiante.codigo == cod){
			pos = indice;
			}
	
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );

    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
	
	Estudiante estudiante;
	
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"_______________________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" | "<<"APELLIDO"<<" |"<<"TELEFONO"<<"| "<<endl;	
		do{
		cout<<"___________________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" | "<<estudiante.apellido<<"| "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();
	//buscar_indice();	
	buscar_codigo();

}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );

     
	 /*
	 void eliminar_estudiante(){
	

	
	ifstream fs("../archivo.dat");
	ofstream fstemp("../archivo.dat");
    string palabra, linea;
    bool bandera = false;
    int contador = 0, lineas = 0;
    
    cin.ignore();
    
    cout<<"Ingrese el codigo a eliminar: ";
    getline(cin, codigo);

    while(getline(fs, linea)){
    	
    	lineas++;
    	
    	if(!bandera && lineas == getNumeroLineas()-4){
    		fstemp<<linea;
    		codigo = true;
    		break;
		}
    
		if(linea == codigo){
      		contador = 4;
      		codigo = true;
    	}
    	
    	if(contador <= 0){
    		if(lineas < getNumeroLineas()) fstemp<<linea<<endl;
    		else fstemp<<linea;
		}else{
			contador--;	
		} 
		
  	}
  	
  	fs.close();
  	fstemp.close();
  	remove("../archivo.dat");
  	rename("../archivo.dat", "../archivo.dat");
	
	if(bandera){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
		cout<<"\nPalabra eliminada con éxito\n";
	}else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),207);
		cout<<"\nLa palabra ingresada no existe\n";
	} 
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
}

	*/


	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
     
}


