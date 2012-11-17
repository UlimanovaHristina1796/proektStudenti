#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//broj na studenti vo strukturata
int BROJ_ZAPISI = 0;

struct SPISOK
{
	int brojIndeks;
    char ime[30];
	char prezime[30];	
	char godinaStudii[15];
	float prosek;	
};

typedef struct SPISOK STUDENTI;

void snimiStudenti(STUDENTI *std, int n)
{
   ofstream izlez;
   izlez.open("studenti.txt", ios_base::app | ios_base::out ); 
   
   if(!izlez)
   {        
        cout << "Greska! Ne mozi da se procesira fjalot." << endl;
        exit(1);
   }
   
   for (int i = 0; i < n; i++)
   {   
       izlez<<std[i].brojIndeks<<";";    
       izlez<<std[i].ime<<";"; 
       izlez<<std[i].prezime<<";";       
       izlez<<std[i].godinaStudii<<";"; 
       izlez<<std[i].prosek;
      
       izlez<<endl;
       
       izlez.flush();
   }
   izlez.close();
}

void sortirajSpisok(STUDENTI **pStudent)
{
	int temp;
	
    for(int i=0;i<BROJ_ZAPISI;++i)
    {
		for(int j=0;j<BROJ_ZAPISI-1;++j)
        {
			if(pStudent[j]->brojIndeks > pStudent[j+1]->brojIndeks)
            {
				temp = pStudent[j]->brojIndeks;
				pStudent[j]->brojIndeks = pStudent[j+1]->brojIndeks;
				pStudent[j+1]->brojIndeks = temp;
			}
		}
	}
}

int linearnoPrebaruvanjeInteger(STUDENTI **a, int prv, int posleden, int kluc)
{      
   for (int i = prv; i <posleden; i++) 
   {      
        if (kluc == a[i]->brojIndeks) 
        {
            return i;
        }      
   }
   return -1; 
}

int linearnoPrebaruvanjeString(STUDENTI **a, int prv, int posleden, int kolona, char kluc[])
{      
   for (int i = prv; i <posleden; i++) 
   {
       if (kolona == 2)
       {
             if (strcmp(kluc,a[i]->ime)==0) 
             {
                 return i;
             }
       }
       if (kolona == 3)
       {
             if (strcmp(kluc,a[i]->prezime)==0) 
             {
                 return i;
             }
       }      
   }
   return -1; 
}


void pecatiStudent(STUDENTI **pStudent, int n)
{     
         cout<<"STUDENT #"<<n<<endl;
         
         cout<<"   Broj Indeks: "<<pStudent[n]->brojIndeks<<endl;
         cout<<"           Ime: "<<pStudent[n]->ime<<endl;
         cout<<"       Prezime: "<<pStudent[n]->prezime<<endl;
         cout<<" Godina Studii: "<<pStudent[n]->godinaStudii<<endl;
         cout<<"        Prosek: "<<pStudent[n]->prosek<<endl;
         
         cout<<endl;    
}

void pronajdiStudent(STUDENTI **pStudent)
{
     char izbor ;
    
     do{
          
        cout<<endl;	
        cout<<"[1] Prebaraj po Broj na Indeks"<<endl;
		cout<<"[2] Prebaraj po Ime"<<endl;
		cout<<"[3] Prebaraj po Prezime"<<endl;				
        cout<<"[4] Izlez od programa"<<endl;
		cout<<endl;		
		
		int indeks=0;
		char *naziv = new char[30];
	
    	izbor = getchar();
        int indeksStudent;
        
        switch(getchar())
        {
			case '1': 
                 
                 cout<<"Vnesi Broj na Indeks:"<<endl; cin>>indeks;
                 indeksStudent = linearnoPrebaruvanjeInteger(pStudent, 0, BROJ_ZAPISI, indeks);
                 if(indeksStudent>0)
                    pecatiStudent(pStudent, indeksStudent);
                 else
                    cout<<"Ne e pronajden student."<<endl;  
                                
                 break;
                 
            case '2': 
                 
                 cout<<"Vnesi Ime na Student:"; cin>>naziv;
                 indeksStudent = linearnoPrebaruvanjeString(pStudent, 0, BROJ_ZAPISI, 2, naziv);     
                 if(indeksStudent>0)
                    pecatiStudent(pStudent, indeksStudent);
                 else
                    cout<<"Ne e pronajden student.";  
                       
                 break;
                 
            case '3': 
                 
                 cout<<"Vnesi Prezime na Student:"; cin>>naziv;
                 indeksStudent = linearnoPrebaruvanjeString(pStudent, 0, BROJ_ZAPISI, 3, naziv);
                 if(indeksStudent>0)
                    pecatiStudent(pStudent, indeksStudent);
                 else
                    cout<<"Ne e pronajden student.";  
                        
                 break;
                 
            case '4': exit(1);	     
                     
	     } 
     }while(getchar()!='4');
}

void pecatiStudenti(STUDENTI **pStudent, int n)
{
    sortirajSpisok(pStudent);
     
    for(int i=0; i<n; i++)
    {
         cout<<endl;
         cout<<"STUDENT #"<<i<<endl;
         
         cout<<"   Broj Indeks: "<<pStudent[i]->brojIndeks<<endl;
         cout<<"           Ime: "<<pStudent[i]->ime<<endl;
         cout<<"       Prezime: "<<pStudent[i]->prezime<<endl;
         cout<<" Godina Studii: "<<pStudent[i]->godinaStudii<<endl;
         cout<<"        Prosek: "<<pStudent[i]->prosek<<endl;
         
         cout<<endl;
    } 
}

STUDENTI **vcitajStudenti()
{        
    STUDENTI zapisStudent, **zapisStudentArray = NULL;
     
    ifstream vlez;
    vlez.open("studenti.txt"); 
    
    if(!vlez)
    {
        cout << "Greska! Ne mozi da se procesira fajlot." << endl;
        exit(1);    
    }
    
    char zapis[500];  
    stringstream s;

    while( vlez.getline(zapis, 120) )
    { 
            s<<zapis;          
            
            s.getline(zapis, 15, ';');
            zapisStudent.brojIndeks = atoi(zapis);
            
            s.getline(zapis, 30, ';');
            strcpy(zapisStudent.ime, zapis);
            
            s.getline(zapis, 30, ';');
            strcpy(zapisStudent.prezime, zapis);
            
            s.getline(zapis, 15, ';');
            strcpy(zapisStudent.godinaStudii, zapis);
            
            s.getline(zapis, 30, ';');
            zapisStudent.prosek = atof(zapis);
            
            s<<"";
            s.clear();	
                      
            if(!vlez) break;//
            
            zapisStudentArray  = (STUDENTI **) realloc(zapisStudentArray ,(BROJ_ZAPISI+1) * sizeof(STUDENTI *));
            zapisStudentArray[BROJ_ZAPISI] = (STUDENTI *) malloc(sizeof(STUDENTI));
            *zapisStudentArray[BROJ_ZAPISI++] = zapisStudent;           
            
    }    
    vlez.close();
    
    return zapisStudentArray;   
}


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

