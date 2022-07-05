#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int M = 3, N = 5;

void view_file(char* name)
{
char s[100]; FILE* f;
f = fopen(name, "rt"); 
if (f == NULL) { puts("Cannot open file to veiw"); return; }
cout << "\n" << " \n Перегляд файлу " << name  << endl;
while (fgets(s, 100, f))
{ 
s[strlen(s) - 1 ] = '\0';
puts(s);
}
fclose(f);
}

void create_matrix(double matr[M][N], char* name)
{
FILE* f;
char s[100], * t;
int i = 0, j;
f = fopen(name, "rt"); 
if (f == NULL) { puts("Cannot open file to veiw"); return; }
while (fgets(s, 100, f))
{ j = 0;
t = strtok(s, " \t");
while (t != NULL)
{ matr[i][j] = atof(t);
t = strtok(NULL, " \t");
j++;
}
i++;
}
fclose(f);
return;
}

void output_matrix(double matr[M][N], char* name2)
{
int i, j;
FILE* f2;
f2 = fopen(name2, "wt"); 
if (f2 == NULL) { puts("Cannot open file"); return; }
printf("\n\nПерегляд матрицi:\n");
fprintf(f2, "Перегляд матрицi:\n");
for (i = 0; i < M; i++)
{
for (j = 0; j < N; j++)
{ 
printf("%7.1f\t", matr[i][j] );
fprintf(f2, "%7.1f\t", matr[i][j]);
}
puts("");
fprintf(f2, "%s", "\n");
}
fclose(f2);
return;
}

void create_vector(double matr[M][N], double vekt[M], char* name2)
{
FILE* f2;
f2 = fopen(name2, "at"); 
if (f2 == NULL)
{
puts("Cannot open file to append data\n"); return;
}
puts("\nВектор максимальних елементів рядків матриці:");
fprintf(f2, "\nВектор максимальних елементів рядків матриці:\n");
double max;
for (int i = 0; i < M; i++)
{
max = matr[i][0];
for (int j = 0; j < N; j++)
{
if (matr[i][j] > max) max = matr[i][j];
}
vekt[i] = (max);
printf("%7.1f\t", vekt[i]) ; 
fprintf(f2, "%7.1f\t", vekt[i]); 
}
fclose(f2);
}

void sum(double matr[M][N], char* name2)
{
FILE* f2;
f2 = fopen(name2, "at"); 
if (f2 == NULL)
{ puts("Cannot open file to append data\n"); return; }
double sum = 0;
int kol = 0;
for (int j = 0; j < 5; j++)
for (int i = 0; i < 3; i++)
if (i%2==1 && j%2==1)
{sum += matr[i][j];
kol++;
}
sum/=kol;
printf("\n\nСереднє арифметичне елементів матриці з парними індексами = %7.1f\n", sum );
fprintf(f2, "\n\nСереднє арифметичне елементів \nматриці з парними індексами= %7.1f\n", sum);
fclose(f2);
}


void number(char* name3, char* name2)
{
FILE* f3, * f2; 
f3 = fopen(name3, "rt"); 
if (f3 == NULL) { puts("Cannot open file to veiw"); return; }
f2 = fopen(name2, "at"); 
if (f2 == NULL) { puts("Cannot open file to append\n"); return; }
char s[100], * t = new char[100];
puts( "\n Індекси цифр:");
fputs("\n Індекси цифр:\n", f2);
while (fgets(s, 100, f3))
{
   for (int i=0; i<strlen(s); i++)
     
     if (s[i]>47 && s[i]<58)
    {
     cout<<" "<<i;
    fprintf(f2, "%i ", i);
     }
}
fclose(f2); 
fclose(f3);
}


int main()
{
double A[M][N], B[N];
char name1[] = "F1.txt";
char name2[] = "F2.txt";
char name3[] = "F3.txt";
view_file(name1); 
create_matrix(A, name1); 
output_matrix(A, name2); 
create_vector(A, B, name2);
sum(A, name2);
number(name3, name2); 
view_file(name3); 
view_file(name2);
return 0;
}
