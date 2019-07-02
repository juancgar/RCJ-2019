void setup() {
  Serial3.begin(9600);
}

void loop() {
  /*if (Serial3.available()  > 0)
  {
    int clave = Serial3.read();
    if (clave == 'a')
    {
      robot.Forward(100);
    } else
    {
      robot.Stop();
    }
  }*/
  Serial3.write('A');
}
