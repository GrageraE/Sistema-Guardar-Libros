#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

string titulos[5] = {"", "", "", "",""};
string autores[5] = {"", "", "", "",""};
string coleccion[5] = {"", "", "", "",""};

int i = 0;
string op1;

int crearFichero();
int arranque();

int main()
{
  if(arranque()==0)
  {
    cout <<" Los ficheros estan donde deben estar" <<endl;
    system("PAUSE");
    return 0; //Exit(0);
  }
  i=1;
  cout <<" En los espacios para escribir, sustituye los espacios con guiones(-) " <<endl;
  cout <<" Si no hace esto, se producirá un error en la aplicacion" <<endl;
  cout <<" Por ejemplo, 'kk kk' ===> 'kk-kk' " <<endl;
  while(i<6)
  {
    cout <<" Libro " <<i <<":" <<endl;
    cout <<" Titulo ===> ";
    cin >> titulos[i-1];
    cout <<" Autor:";
    cout <<" ===> ";
    cin >> autores[i-1];
    cout <<" Coleccion ===> ";
    cin >> coleccion[i-1];
    cout <<" Desea salir ya? (s/n) ";
    cin >> op1;
    if(op1 == "s"){
      break;
    }
    else{
    i = i+1;
   }
 }
   if(i==6)
   {
     cout <<" Lo siento, solo se permiten 5 libros" <<endl;
   }
   cout <<" Guardando datos... " <<endl;
   if(crearFichero()==1)
   {
     cout <<" Se ha producido un error, la app se cierra" <<endl;
     system("PAUSE");
     exit(1);
   }
   cout <<" Se ha completado la operacion" <<endl;
   system("PAUSE");
   return 0;
}

int crearFichero()
{
  ofstream libros[5];
  system("MKDIR libros");
  libros[0].open("./libros/libro1.txt", ios::out);
  libros[1].open("./libros/libro2.txt", ios::out);
  libros[2].open("./libros/libro3.txt", ios::out);
  libros[3].open("./libros/libro4.txt", ios::out);
  libros[4].open("./libros/libro5.txt", ios::out);
  int j = 0;
  while(j<5){
    libros[j] <<" Titulo: " <<titulos[j] <<endl;
    libros[j] <<" Autor: " <<autores[j] <<endl;
    libros[j] <<" Coleccion: " <<coleccion[j] <<endl;
    j = j+1;
  }
  if(libros[0].fail()||libros[1].fail()||libros[2].fail()||libros[3].fail()||libros[4].fail())
  {
    return 1;
  }
  int k = 0;
  while(k<5)
  {
    libros[k].close();
    k=k+1;
  }
  return 0;
}

int arranque()
{
  ifstream prueba[5];
  prueba[0].open("./libros/libro1.txt", ios::in);
  prueba[1].open("./libros/libro2.txt", ios::in);
  prueba[2].open("./libros/libro3.txt", ios::in);
  prueba[3].open("./libros/libro4.txt", ios::in);
  prueba[4].open("./libros/libro5.txt", ios::in);
  if(prueba[0].fail()||prueba[1].fail()||prueba[2].fail()||prueba[3].fail()||prueba[4].fail())
  {
    return 1;
    //Se ha producido un error
  }
  int l = 0;
  while(l<5)
  {
    while(!prueba[l].eof())
    {
      string importaciones[5];
      getline(prueba[l], importaciones[l]);
      cout <<importaciones[0] <<endl;
    }
    l = l+1;
  }
  l = 0;
  while(l<5)
  {
    prueba[l].close();
    l = l+1;
  }
  return 0;
  //Parece que todo ha salido bien
}
