#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>




class BOILER
{ protected : char *denumire;
	      int capacitate,presiune,temperatura;
  public  :  BOILER();
	     BOILER(char*,int,int,int);
	    ~BOILER();
	     virtual void afisare();
	     friend int get_presiune(BOILER&);
	     void set_presiune(int);
	     void set_temperatura(BOILER&);
	     friend int get_temperatura(BOILER&);
};

BOILER :: BOILER()
{ capacitate=0;
  presiune=0;
  temperatura=0;
}

void BOILER::BOILER(char *Denum,int C,int P,int T)
{  denumire= new char[strlen(Denum)+1];
   strcpy(denumire,Denum);
   capacitate=C;
   presiune=P;
   temperatura=T;
}

BOILER :: ~BOILER()
{ delete denumire; }

void BOILER::afisare()
{ cout<<"\n Denumire : "<<denumire;
  cout<<"\n Capacitate : "<<capacitate<<" l ";
  cout<<"\n Presiunea la care a fost testat boilerul : "<<presiune<<" bar ";
}

void BOILER::set_presiune(int pres)   //siguranta presiune
{ int presiune_retea;
cout<<"\n Presiunea apei in retea :"; cin>>presiune_retea;
 if( presiune_retea>=pres)
     cout<<"\n Atentie presiune peste limita admisa !!!";
   else { cout<<"\n Presiune admisa";
	  presiune=presiune_retea;
	}
}

int get_temperatura(BOILER&y)
{ return y.temperatura; }

int get_presiune(BOILER&x)
{
    return x.presiune;
}

void BOILER::set_temperatura(BOILER&x)          // siguranta temperatura
{ int Temp_apa ;
  cout<<"\n Temperatura apa :";cin>>Temp_apa;// temperatura  apei
  if(Temp_apa>=x.temperatura)
    cout<<"\n Temperatura apei a depasit pragul admis !!!";
  else  cout<<"\n Temperatura apei nu a depasit limita admisa ";
  if(Temp_apa>=30&&Temp_apa<=60)
    cout<<"\n Temperatura apei este ideala pentru a fii utilizata ";
  temperatura=Temp_apa;
}

class BOILER_ELECTRIC:public BOILER
{ protected  : char*clasa_energetica;
	      int timp_incalzire,tensiune_alimentare;
  public : BOILER_ELECTRIC();
	   BOILER_ELECTRIC(char*,int,int,int,char*,int,int);
	   void afisare();
	   void set_tens_alim(BOILER_ELECTRIC&,int);
	   void set_timp_incalzire(BOILER_ELECTRIC&);
	   int get_timp_incalzire(BOILER_ELECTRIC&);
};

BOILER_ELECTRIC::BOILER_ELECTRIC()
{ timp_incalzire=0;
  tensiune_alimentare=0;
}

BOILER_ELECTRIC::BOILER_ELECTRIC(char*Denum,int C,int P,int T,char*clasa_energe,int timp_incalz,int tens_alim):BOILER(Denum,C,P,T)
{ clasa_energetica=new char[strlen(clasa_energe)+1];
  strcpy(clasa_energetica,clasa_energe);
  timp_incalzire=timp_incalz;
  tensiune_alimentare=tens_alim;
}

void BOILER_ELECTRIC::afisare()
{ BOILER::afisare();
  cout<<"\n Clasa energetica : "<<clasa_energetica;
  cout<<"\n Timpul de incalizre a apei la 45 de grade Celsius : "<<timp_incalzire<<" minute ";
  cout<<"\n Tensiunea de alimentare : "<<tensiune_alimentare<<" V ";
}

void BOILER_ELECTRIC::set_tens_alim(BOILER_ELECTRIC&x,int y)
{ int tens_retea;
  cout<<"\n Tensiunea de la retea :";cin>>tens_retea;
  if(tens_retea>x.tensiune_alimentare)
    cout<<"\n Atentie!!! Tensiune prea mare !!!";
  else  if(tens_retea>=y&&tens_retea<=x.tensiune_alimentare)
	  cout<<"\n Tensiune in limitele admise ";
  if(tens_retea<y)
    cout<<"\n Tensiunea de la retea este prea mica pentru a putea asigura incalzirea apei ";
}

void BOILER_ELECTRIC::set_timp_incalzire(BOILER_ELECTRIC&z)
{ int T_incalz;
  cout<<"\n Timpul pentru incalzirea apei :";cin>>T_incalz;
  z.timp_incalzire=T_incalz;
}

int BOILER_ELECTRIC::get_timp_incalzire(BOILER_ELECTRIC&x)
{ return x.timp_incalzire; }

class BE_CU_ACUMULARE: public BOILER_ELECTRIC
{ protected :float dispersie_termica;
	     char *facilitati;
	     int putere_rezistenta;
  public : BE_CU_ACUMULARE();
	   BE_CU_ACUMULARE(char*,int,int,int,char*,int,int,float,char*,int);
	   void afisare();
	   inline set_facilitati(char*);

};

BE_CU_ACUMULARE::BE_CU_ACUMULARE()
{ dispersie_termica=0;
  putere_rezistenta=0;
}

BE_CU_ACUMULARE::BE_CU_ACUMULARE(char*Denum,int C,int P,int T,char*clasa_energe,int timp_incalz,int tens_alim,float disp_term,char*facil,int P_rez):BOILER_ELECTRIC(Denum,C,P,T,clasa_energe,timp_incalz,tens_alim)
{ dispersie_termica=disp_term;
  putere_rezistenta=P_rez;
  facilitati=new char[strlen(facil)+1];
  strcpy(facilitati,facil);
}

void BE_CU_ACUMULARE::afisare()
{ BOILER_ELECTRIC::afisare();
  cout<<"\n Disperisie termica :"<<dispersie_termica<<" kWh/24h ";
  cout<<"\n Facilitati :"<<facilitati;
  cout<<"\n Putere rezistentei :"<<putere_rezistenta<<" kW ";
}

BE_CU_ACUMULARE::set_facilitati(char*facil)
{  facilitati=facil;
   return *facilitati;
}
class BOILER_GAZ:public BOILER
{ protected : float consum_gaze,debit_gaze_evacuate,continut_CO2;
	      int timp_incalzire;
  public :  BOILER_GAZ();
	    BOILER_GAZ(char*,int,int,int,float,float,float,int);
	    void afisare();
	    int set_timp_incalzire(BOILER_GAZ&);
	    friend int get_timp_incalzire(BOILER_GAZ&)
	    float set_consum_gaze(BOILER_GAZ&);
	    friend float get_consum_gaze(BOILER_GAZ&);
	    float set_debit_gaze(BOILER_GAZ&);
	    friend float get_debit_gaze(BOILER_GAZ&);
	    float set_CO2(BOILER_GAZ&);
	    friend float get_CO2(BOILER_GAZ&);
};

BOILER_GAZ::BOILER_GAZ()
{
  consum_gaze=0;
  debit_gaze_evacuate=0;
  continut_CO2=0;
  timp_incalzire=0;
}

BOILER_GAZ::BOILER_GAZ(char*Denum,int C,int P,int T,float C_gaz,float debit_g_evac,float CO2,int timp_incalz):BOILER(Denum,C,P,T)
{
  consum_gaze=C_gaz;
  debit_gaze_evacuate=debit_g_evac;
  continut_CO2=CO2;
  timp_incalzire=timp_incalz;
}

void BOILER_GAZ :: afisare()
{ BOILER::afisare();
  cout<<"\n Conusum gaze naturale : "<<consum_gaze<<" m3/h ";
  cout<<"\n Debit gaze evacuate : "<<debit_gaze_evacuate<<" kg/h ";
  cout<<"\n Continut de CO2 : "<<continut_CO2<<" % ";
  cout<<"\n Timpul de incalzire al apei la 45 grade Celsius : "<<timp_incalzire<<" minute ";
}

int BOILER_GAZ::set_timp_incalzire(BOILER_GAZ&w)
{ int T;
  cout<<"\n Timp incalizre : ";cin>>T; //timp de incalzire citit de la tastatura
  w.timp_incalzire=T;
  return timp_incalzire;
}

int get_timp_incalzire(BOILER_GAZ&z)
{ return  z.timp_incalzire; }

float BOILER_GAZ::set_consum_gaze(BOILER_GAZ&t)
{  float C;
   cout<<"\n Consum gaze : ";cin>>C; //modificare consumului de gaze ( in practica folosim robinetul )
   t.consum_gaze=C;
   return consum_gaze;
}

float get_consum_gaze(BOILER_GAZ&q)
{ return q.consum_gaze; }

float BOILER_GAZ::set_debit_gaze(BOILER_GAZ&r)
{ float DG;
  cout<<"\n Debit gaze : ";cin>>DG; //debit gaze dupa modificarea consumului de gaze
  r.debit_gaze_evacuate=DG;
  return debit_gaze_evacuate;
}

float get_debit_gaze(BOILER_GAZ&w)
{ return w.debit_gaze_evacuate; }

float BOILER_GAZ::set_CO2(BOILER_GAZ&x)
{ float CO2;
  cout<<"\n CO2 : ";cin>>CO2; //contiunut de CO2 dupa modificare consumului de gaze
  x.continut_CO2=CO2;
  return continut_CO2;
}

float get_CO2(BOILER_GAZ&p)
{ return p.continut_CO2; }

class BG_CU_TIRAJ_FORTAT:public BOILER_GAZ
{ protected : int putere_termica,consum_GPL;
  public : BG_CU_TIRAJ_FORTAT();
	   BG_CU_TIRAJ_FORTAT(char*,int,int,int,int,int,int,int,int,int);
	   void afisare();
	   int set_consum_GPL(BG_CU_TIRAJ_FORTAT&);
	   friend int get_consum_GPL(BG_CU_TIRAJ_FORTAT&);

};

BG_CU_TIRAJ_FORTAT::BG_CU_TIRAJ_FORTAT()
{ putere_termica=0;
  consum_GPL=0;
}

BG_CU_TIRAJ_FORTAT::BG_CU_TIRAJ_FORTAT(char*Denum,int C,int P,int T,int C_gaz,int debit_g_evac,int CO2,int timp_incalz,int P_term,int cons_GPL):BOILER_GAZ(Denum,C,P,T, C_gaz, debit_g_evac, CO2,timp_incalz)
{ putere_termica=P_term;
  consum_GPL=cons_GPL;
}

void BG_CU_TIRAJ_FORTAT::afisare()
{ BOILER_GAZ::afisare();
  cout<<"\n Putere termica :"<<putere_termica<<" W ";
  cout<<"\n Consum GPL :"<<consum_GPL<<" g/h ";
}

int BG_CU_TIRAJ_FORTAT::set_consum_GPL(BG_CU_TIRAJ_FORTAT&c)
{ int CG;
  cout<<"\n Consum GPL: ";cin>>CG; //consumul de gaze
  c.consum_GPL=CG;
  return consum_GPL;
}

int get_consum_GPL(BG_CU_TIRAJ_FORTAT&x)
{ return x.consum_GPL; }

class BOILER_COMBUSTIBIL_SOLID:public BOILER
{ protected : char *tiraj;
	      int debit_caloric;
	      float volum_focar,suprafata_focar;
  public : BOILER_COMBUSTIBIL_SOLID() ;
	   BOILER_COMBUSTIBIL_SOLID(char*,int,int,int,char*,int,float,float);
	   void afisare();
	   int set_debit_caloric(BOILER_COMBUSTIBIL_SOLID&);
	   friend get_debit_caloric(BOILER_COMBUSTIBIL_SOLID&);
};

BOILER_COMBUSTIBIL_SOLID::BOILER_COMBUSTIBIL_SOLID()
{ debit_caloric=0;
  volum_focar=0.0;
  suprafata_focar=0.0;
}

BOILER_COMBUSTIBIL_SOLID::BOILER_COMBUSTIBIL_SOLID(char*Denum,int C,int P,int T,char*Tiraj,int deb_cal,float V_focar,float S_focar):BOILER(Denum,C,P,T)
{
  tiraj=new char[strlen(Tiraj)+1];
  strcpy(tiraj,Tiraj);
  debit_caloric=deb_cal;
  volum_focar=V_focar;
  suprafata_focar=S_focar;
}

void BOILER_COMBUSTIBIL_SOLID::afisare()
{ BOILER::afisare();
  cout<<"\n Traj : "<<tiraj;
  cout<<"\n Debit caloric : "<<debit_caloric<<" W ";
  cout<<"\n Volumul focarului : "<<volum_focar<<" m3 ";
  cout<<"\n Suprafata focarului : "<<suprafata_focar<<" m2 ";
}

int BOILER_COMBUSTIBIL_SOLID::set_debit_caloric(BOILER_COMBUSTIBIL_SOLID&v)
{ int DC;
  cout<<"\n Debit caloric : ";cin>>DC; //debit caloric citit de la tastautra
  v.debit_caloric=DC;
  return debit_caloric;
}

int get_debit_caloric(BOILER_COMBUSTIBIL_SOLID&c)
{ return c.debit_caloric; }

void main()
{  clrscr();
   BOILER a("Ariston CL80",100,8,90);
   a.afisare();
   a.set_presiune(10);
   cout<<"\n Presiudnea din boiler este :"<<get_presiune(a)<<" bari "<<endl;
   a.set_temperatura(a);
   cout<<"\n Temperatura apei din boiler este :"<<get_temperatura(a)<<endl;
   BOILER_ELECTRIC b("Ariston PRO R 80V",90,10,85,"B",45,220);
   b.afisare();
   b.set_tens_alim(b,200);
   b.set_timp_incalzire(b);
   cout<<"\n Timpul setat pentru incalzire apei :"<<b.get_timp_incalzire(b)<<endl;
   BE_CU_ACUMULARE c("ELDOM EXTRA",95,9,100,"A",30,240,1.22,"Supape de siguranta",2);
   c.afisare();
   c.set_facilitati("Supape de presiune");
   c.afisare();
   BOILER_GAZ d("HEIZER-G1",110,7,80,1,3,4,50);
   d.afisare();
   d.set_timp_incalzire(d);
   cout<<"\n Timpul pentru incalzirea apei dupa setare este : "<<get_timp_incalzire(d)<<" minute "<<endl;
   d.set_consum_gaze(d);
   cout<<"\n Consumul de gaze dupa setare este : "<<get_consum_gaze(d)<<" m3/h ";
   d.set_debit_gaze(d);
   cout<<"\n Debitul de gaze dupa modificarea consumului de gaze : "<<get_debit_gaze(d)<<" kg/h "<<endl;
   d.set_CO2(d);
   cout<<"\n Continutul de CO2 dupa modificare consumului de gaze : "<<get_CO2(d)<<" % "<<endl;
   BG_CU_TIRAJ_FORTAT e("Ariston S/SGA",120,10,70,2,4,5,60,5,1000);
   e.afisare();
   e.set_consum_GPL(e);
   cout<<"\n Consumul de GPL dupa setare : "<<get_consum_GPL(e)<<" g/h "<<endl;
   BOILER_COMBUSTIBIL_SOLID f("Omega",70,9,90,"natural",2000,0.2,0.1);
   f.afisare();
   f.set_debit_caloric(f);
   cout<<"\n Debitul caloric dupa setare : "<<get_debit_caloric(f)<<" W "<<endl;

}
