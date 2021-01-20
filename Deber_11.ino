/*
 * CAPITULO : APRENDIZAJE DE MAQUINA- REGRESION LINEAL
 * PROGRAMA: 30, REGRESION LINEAL SIMPLE
 * OBJETIVO: GENERAR MODELO DE REGRESION LINEAL que ingrese datos por cx
 */
int matriz[14][2]={   //Ingreso de matriz de datos
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};
int col = 0; //Moverse en columnas
int fil = 0; //Moverse en filas
float Ex=0;   //Sumatoria x
float Yp=0;   //Y prima
float Eyp=0;   //Sumatoria y prima  
float Exyp=0;     //Sumatoria xyprima
float Ex2=0;   //Sumatoria x^2
float Ex_2=0;    //(Sumatoria x)^2
int n = 14; //tam muestras
float Bo; //ordenada en el origen
float m; //pendiente
String dato; //Recibir estatura
int estatura; //Convertir dato
float peso;   //Dato para el peso
float m1; //aux
void setup() {
    Serial.begin(9600); //Inicio cx
    //Creacion del modelo
    for(;fil<n;fil++){    //Creacion for para el modelo
      Ex=Ex+matriz[fil][0];     //Realizacion sumatoria de x
      Yp=(log(matriz[fil][1]));   //Realizacion logaritmo de variable y
      Eyp=Eyp+Yp;                 //Sumatoria de logaritmo de y
      Exyp=Exyp+(matriz[fil][0]*Yp);    //Sumatoria de x * yp
      Ex2=Ex2+pow(matriz[fil][0],2);     //Sumatoria de x ^2
    }
    Ex_2=pow(Ex,2);                     //Sumatoria de x y luego elevado al cuadrado
    Bo=(float(n*Exyp)-float(Ex*Eyp))/(float(n*Ex2-Ex_2)); //Formula para obtencion Bo
    m1=(Eyp/14)-(Bo*(Ex/14)); //Formula obtencion auxliar 
    m=float(exp(m1));         //Obtencion de dato m para la formula
    Serial.println("El modelo es :");     //Mensaje de impresion
    Serial.println(String("y = ")+String(m)+String("* exp(")+String(Bo)+String("* x)"));    //Mensaje de impresion
    Serial.println("Ingrese su estatura: ");      //Mensaje de impresion
}

void loop() {
  if(Serial.available()>0){     //Activacion puerto serial
    dato=Serial.readString();   //Lecutra de dato por cx
    estatura = dato.toInt();    //Conversion de dato a entero
    peso = m*exp(estatura*Bo);  // Aplicacion de formula para regresion exporencial 
    Serial.println("");       //Mensaje de impresion
    Serial.println(String("Su peso es : ")+String(peso)+String("Kg")); //Mensaje de impresion
    Serial.println("Ingrese su estatura: "); //Mensaje de impresion
  }
}
