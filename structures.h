/*TOMA Andrei-311CB*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef __STRUCTURES__
#define __STRUCTURES__

#define MAX_COLUMN_NAME_LEN 30
#define MAX_TABLE_NAME_LEN  30
#define MAX_DB_NAME_LEN     30
#define MAX_CMD_LEN         300
#define F_DIGITS            6 //numarul de zecimale din numarul real
#define DOT_DIGIT			1 //caracterul punct din numarul real

// int
typedef struct intCell {
	int    value;
	struct intCell* next;
} t_intCell;

typedef struct intLine {
	t_intCell*      cells;
	struct intLine* next;
} t_intLine;

// float
typedef struct floatCell {
	float  value;
	struct floatCell* next;
} t_floatCell;

typedef struct floatLine {
	t_floatCell*      cells;
	struct floatLine* next;
} t_floatLine;

// string
typedef struct stringCell {
	char*  value;
	struct stringCell* next;
} t_stringCell;

typedef struct stringLine {
	t_stringCell*       cells;
	struct stringLine* next;
} t_stringLine;

// cell type
typedef enum {
	INT,
	FLOAT,
	STRING
} t_cellType;

// column
typedef struct column {
	char name[MAX_COLUMN_NAME_LEN];
	struct column* next;
} t_column;

// table
typedef struct table {
	char name[MAX_TABLE_NAME_LEN];
	t_cellType    type;
	t_column*     columns;
	void*         lines;  // t_intLine* | t_floatLine* | t_stringLine*
	struct table* next;
} t_table;

// database
typedef struct db {
	char name[MAX_DB_NAME_LEN];
	t_table* tables;
} t_db;

t_db *init_db(char *name);
/*initializeaza baza de date*/
t_intCell *alloc_intCell(int value);
/*aloca o celula de tip t_intCell si in campul value retine value*/
t_intLine *alloc_intLinie ();
/*aloca o linie de tip t_intLine*/
int adauga_intLinieSf (t_intLine *line, t_table **table);
/*functie care adauga o linie de tip t_intLine la sfatsitul listei de linii
din tabelul *table; returneaza 1 daca adugarea a fost facuta cu succes si 
0 in caz contrar*/
int adauga_intLinie (t_intLine **line, t_intCell *cell);
/*adauga la finalul listei de celule de pe linia *line celula cell; 
returneaza 1 daca adaugarea a fost facuta cu succes si 0 in caz contrar*/
t_floatCell *alloc_floatCell(float value);
/*aloca o celula de tip t_floatCell si in campul value retine value*/
t_floatLine *alloc_floatLine ();
/*aloca o linie de tip t_floatLine*/
int adauga_floatLinieSf (t_floatLine *line, t_table **table);
/*adauga o linie de tip t_floatLine la sfaristul la sfarsitul liste de linii
din tabelul *table; returneaza 1 daca adaugarea a fost facuta cu succes si 
0 in caz contrar*/
int adauga_floatLinie (t_floatLine **line, t_floatCell *cell);
/*adauga la sfarsitul listei de celule de pe linia *line celula cell;
returneaza 1 daca adaugarea a fost facuta cu succes si 0 in caz contrar*/
t_stringCell *alloc_stringCell(char *value);
/*aloca o celul de tip t_strinCell si in campul value retine value*/
t_stringLine *alloc_stringLine();
/*aloca o linie de tip t_strinLine*/
int adauga_stringLinieSf (t_stringLine *line, t_table **table);
/*adauga o linie de tip t_strinLine la sfarsitul listei de linii din tabelul 
*table; returneaza 1 daca adaugarea a fost facuta cu succes si 0 in caz contrar
*/
int adauga_stringLinie (t_stringLine **line, t_stringCell *cell);
/*adauga la linia line la sfarsitul listei de celule celula cell;
returneaza 1 daca adaugarea a fost facuta cu succes si 0 in caz contrar*/
t_column *alloc_column (char *name);
/*aloca o coloana care retine in campul name valoare lui name*/
int adaugare_col_final (t_table **table, t_column *col);
/*adauga la finalul listei de coloane din tabelul *table coloana col;
intoarce 1 daca adaugarea a fost facut cu succes si 0 in caz contrar*/
int adaugare_tabel_final (t_db **a, t_table *table);
/*adauga la finalul listei de tabele tabelul table; returneaza 1 daca adaugarea
a fost facuta cu succes si 0 in caz contrar*/
int create_table(t_db *a, char *s);
/*creeaza un tabel in care se retine tipul de date retinute in el, numele
tabelului si lista de celule, iar in final este legat la sfarsitul listei de
tabele*/
t_table *cauta_tabel(t_db *a, char *nume);
/*cauta un tabel in baza de date a dupa nume*/
int add_line(t_db *a, char *s);
/*adauga o linie de date intr-un tabel*/
int clear_lines_int (t_table *t);
/*sterge toate liniile din tabelul t de tip INT*/
int clear_lines_float (t_table *t);
/*sterge toate liniile din tabelul t de tip FLOAT*/
int clear_lines_string (t_table *t);
/*sterge toate liniile din tabelul t de tip STRING*/
int clear_lines (t_table *t, char *r);
/*sterge toate liniile dintr-un tabel t*/
void delete_table_int (t_table **t);
/*sterge tabelul *t de tip INT*/
void delete_table_float (t_table **t);
/*sterge tabelul *t de tup FLOAT*/
void delete_table_string (t_table **t);
/*sterge tabelul *t de tip STRING*/
int delete_table (t_db *a, char *nume);
/*sterge tabelul cu numele nume din baza de date a*/
void delete_string_line_cells (t_stringCell **cell);
/*elibereaza memoria pentru lista de celule cell de tip STRING*/
void delete_table_lines_string (t_table *t, char *relation, char *val, int nr);
/*elimina linia de tip STRING din tabelul t daca valoarea de pe coloana data 
respecta  conditia <relation> val*/
void delete_float_line_cells (t_floatCell **cell);
/*elibereaza memoria pentru lista de ceule cell de tip FLOAT*/
void delete_table_lines_float (t_table *t, char *relation, char *val, int nr);
/*sterge linia de tip FLOAT din tabelul t daca valoarea de pe coloana data 
respecta conditia <relation> val*/
void delete_int_line_cells (t_intCell **cell);
/*elibereaza memoria pentru lista de celule de tip INT cell*/
void delete_table_lines_int(t_table *t, char *relation, char *val, int nr);
/*sterge linia de tip INT din tabelul t daca valoarea de pe coloana data
respecta conditia <relation> val*/
int delete_table_lines(t_table *t, char *col, char *relation, char *val, 
	char *r);
/*sterge liniile din tabela t daca valorea de pe coloana col din tabela t
respecta conditia <relation> val*/
void delete_db (t_db **a);
/*sterge intreaga baza de date*/
int numar_cifre_int (int n);
/*determina numarul de cifre ale unui intreg*/
int digit_float (float n);
/*determina numarul de caractere ale unui numar real*/
void print_table_column (t_table *t);
/*printeaza lista de coloane ale tabelului t*/
void print_table_int (t_table *t);
/*afiseaza datele unui tabel t de tip INT*/
void print_table_float (t_table *t);
/*afiseaza datele unui tabel t de tip FLOAT*/
void print_table_string (t_table *t);
/*afiseaza datele unui tabel t de tip STRING*/
void print_table (t_table *t, char *r);
/*afiseaza un tabel t cu numele r*/
void print_int_line (t_intLine *li);
/*afiseaza o linie de tip int*/
void print_float_line (t_floatLine *lf);
/*afiseaza o linie de tip float*/
void print_string_line (t_stringLine *ls);
/*afiseaza o linie de tip string*/
void search_cmp_int (t_table *t, char *relation, char *val, int nr);
/*cauta si compara valorile de tip int din tabela t si daca respecta relatia ca 
valoarea de pe coloana col <relatie> val afiseaza linia respectiva*/
void search_cmp_float (t_table *t, char *relation, char *val, int nr);
/*cauta si compara valorile de tip float din tabel t si dca respecta relatia
ca valoarea de pe coloana col <relatie> val afiseaza linia respectiva*/
void search_cmp_string (t_table *t, char *relation, char *val, int nr);
/*cauta si compara valorile de tip STRING din tabel t si daca respecta relatia
ca valoarea de pe coloana col <relatie> val afiseaza linia respectiva*/
void search_db (t_table *t, char *col, char *relation, char *val, char *r);
/*cauta in tabelul t liniile care respecta conditia ca valorile de pe coloana
col <relation> val si le afiseaza*/
void print_db (t_db *a);
/*afiseaza intreaga baza de date*/
#endif
