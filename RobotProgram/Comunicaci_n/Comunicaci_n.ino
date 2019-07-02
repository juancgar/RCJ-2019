#include <Pixy2.h>
Pixy2 pixy;

 char mode = 'P';
 char clave;
void setup() {
Serial3.begin(9600);
Serial.begin(9600);

pixy.init();
}

void loop() {
  ///P = modo portero
  ///A = modo delantero
 
  int X;
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks) {
    X = pixy.ccc.blocks[0].m_x;

  }
  else {
    X = 0;
  }
  //comunication
  //Cuando el robot recibe el estado inicial
  //Inicia la comunicaciòn
  if(Serial3.available() > 0)
  {
    //Key encapsulation top side
    //A
     clave = Serial3.read();
    ///Si recibe que el delantero, no esta viendo
    ///la pelota y el robot si
    ///Protocolo: 
    // A1---significa que el portero cambio
    // A delantero, fuerza el cambio.
    if(clave == 'A' && X > 0 && mode == 'P')
    {
      mode = 'A';
      Serial3.write("B");
    }
    else if(clave == "B")
    {
      mode = 'P';
    }
  }

  if(mode == 'A')
  {
  //PROGRAMACION DEL DELANTERO
 if(X == 0)
 {
  Serial3.write('A');
 }
      Serial.print("Delantero:  ");
      Serial.print(clave);
      Serial.print("---");
      Serial.println(X);
    
  }
  else if(mode == 'P')
  {
    //PROGRAMACION DEL DEFENSA
      
      Serial.print("Portero:  ");
      Serial.print(clave);
      Serial.print("---");
      Serial.println(X);


  }
  
  
}
