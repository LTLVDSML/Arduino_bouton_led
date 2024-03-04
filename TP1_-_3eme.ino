// définition de la broche 2 de la carte en tant que variable
const int Port_Led[] = {2,4,6} ;
const int Port_Bouton = 8 ;
boolean etat[]={LOW,HIGH,HIGH};
int on=0;

// fonction d'initialisation de la carte
void setup ( )
{
// initialisation de la broche 2 comme étant une sortie
for(int i = 0; i<3;i++){
    pinMode(Port_Led[i],OUTPUT);
    }
pinMode ( Port_Bouton, INPUT_PULLUP );
for(int i = 0; i<3;i++){
  digitalWrite(Port_Led[i], etat[i]);
}
}

// fonction principale, elle se répète (s'exécute) à l'infini
void loop ( ){
if (digitalRead(Port_Bouton)==LOW){
  while (digitalRead(Port_Bouton)==LOW){;}
  etat[on]=!etat[on];
  if (on<2){
    etat[on+1]=!etat[on+1];
    on++;
  }
  else if (on==2){
    etat[0]=!etat[0];
    on=0;    
  }
  for(int i = 0; i<3;i++){
  digitalWrite(Port_Led[i], etat[i]); 
}
}
}
