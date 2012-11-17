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
    //vcituvanje na zacuvanata lista so studenti od datoteka
    STUDENTI **mainStudenti = vcitajStudenti();
      
    do
    {
        cout<<"------------ MENI OPCII ---------------"<<endl;	
		cout<<"[1] Vnes na novi Studenti"<<endl;
		cout<<"[2] Pecatenje na lista na Studenti"<<endl;
		cout<<"[3] Prebaruvanje na Studenti"<<endl;	
		cout<<"[4] Izlez od programa"<<endl;
		cout<<endl;  
		
        switch(getchar())
        {
			case '1':                  
                 int brStudenti;
                 cout<<"Broj na studenti: ";
                 cin>>brStudenti;
                 
                 STUDENTI *std;                 
                 std = (STUDENTI*) malloc( sizeof(STUDENTI) * brStudenti );          
                 
                 vnesiStudenti(std, brStudenti);                 
                 cout<<"Zacuvuvanje na studenti ...";                
                 snimiStudenti(std, brStudenti);                 
			 break;			 
			 
             case '2':                  
                 cout<<"-----LISTA NA STUDENTI------------------------- "<<endl; 
                 pecatiStudenti(mainStudenti, BROJ_ZAPISI);                 
             break;	 
             
             case '3':
                 cout<<"-----PREBARUVANJE NA STUDENTI------------------ "<<endl;
                 pronajdiStudent(mainStudenti); 
             break;	 
                 
		     case '4': exit(1);      
	              
	     } 
	     
      }while(getchar()!='4');
    
    //osoboduvanje na zafatenata memorija
    for(int i = 0; i < BROJ_ZAPISI; i++)
    {    
      free(mainStudenti[i]);
    }
    free(mainStudenti);
    

    system("PAUSE");
    return EXIT_SUCCESS;
}

