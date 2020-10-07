# include <iostream>
void f1(void);
void f2(void);
void f3(void);
void f4(void);
int main()
{
f1();
f2();
f3();
f4();
return 0;
}
void f1(void)
{
//double b =1;
double *z = nullptr; //se declara la variable primero. Valgrind detecta error
z = new double [100] {0.0}; //se reserva la memoria despues
 //cambio de char a double. Detectado con g++. Se deja el array tipo double
//double a = 2;
z[1] = 25; //el array tiene elementos de 0 a 99, no -1. Detectado con valgrind
delete [] z;
}
void f2(void)
{
char *y = nullptr; //se declara la variable primero. valgrind detecta error
y = new char [100] {}; //se reserva memoria despues.
//la inicializacion de char no puede ser un double. Detectado con g++
y[10] = 'a';
delete [] y; //valgrind detecta memory leak porque no se uso delete.
}
void f3(void)
{
int x=0; //el if que sigue depende de x que no se ha inicializado. Valgrind detecta
if(x == 0) //la condicion de igualdad es ==, no =. Detectado con gdb
{
std::cout << "X is zero: " << x <<"\n";
}
}
void f4(void)
{
int x=0; //x no se ha inicializado. Valgrind detecta
std::cout << "x = " << x << "\n";
int i, j=0; //j se usa despues pero no se inicializa. Detectado con valgrind despues de usar std::cout << j;
int a[10] = {0}; //b[10]; //a se  usa despues pero no se inicializa. Valgrind detecta
for ( i = 0; i < 10; i++ ) {//i solo puede ir hasta 9 pues es contador de a[]. Detectado con gdb
j += a[i];
}
if ( j == 77 ) //La condicion de igualdad es ==. Detectado corriendo codigo
std::cout << "hello there\n"; // no se puso << detectado con g++

}
