#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



void vnesiStudenti(STUDENTI *pStudent, int n)
{
    for(int i=0;i<n;i++)
     {   
         cout<<"STUDENT #"<<i<<endl;
         
         cout<<"Vnesi Broj na Indeks: "; cin>>pStudent[i].brojIndeks;        
         cout<<"           Vnesi Ime: "; cin>>pStudent[i].ime;         
         cout<<"       Vnesi Prezime: "; cin>>pStudent[i].prezime;          
         cout<<" Vnesi Godina Studii: "; cin>>pStudent[i].godinaStudii;        
         cout<<"        Vnesi Prosek: "; cin>>pStudent[i].prosek;         
         
         cout<<endl;         
     }    
}

int main(int argc, char *argv[])
{   
    

    system("PAUSE");
    return EXIT_SUCCESS;
}

