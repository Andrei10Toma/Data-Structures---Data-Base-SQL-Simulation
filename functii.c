/*TOMA Andrei-311CB*/
#include "structures.h"

/*initializare baza de date*/

t_db *init_db(char *name)
{
	t_db *DB;
	//alocare baza de date
	DB=(t_db *)calloc(sizeof(t_db), 1);
	if (!DB)
		return NULL;
	strcpy (DB->name, name);
	return DB;
}

/*alocari si adaugari la sfarsit pentru linii si celule de tip int*/

t_intCell *alloc_intCell(int value)
{
	t_intCell *cell;
	//alocare celula
	cell=(t_intCell *)malloc(sizeof(t_intCell));
	//verificare alocare
	if (!cell)
		return NULL;
	cell->value=value;
	cell->next=NULL;
	return cell;
}

t_intLine *alloc_intLinie ()
{
	t_intLine *line;
	//alocare linie
	line=(t_intLine *)calloc(sizeof(t_intLine), 1);
	//verificare alocare
	if (!line)
		return NULL;
	line->next=NULL;
	line->cells=NULL;
	return line;
}

int adauga_intLinieSf (t_intLine *line, t_table **table)
{
	if (line==NULL)
		return 0;
	if ((*table)==NULL)
		return 0;
	t_intLine *ultim, *p;
	//parcurgere lista de linii pentru a determina ultimul element din aceasta
	for (p=(t_intLine *)(*table)->lines, ultim=NULL;p!=NULL;
			ultim=p, p=p->next);
	//adaugare la sfarsit
	if (ultim==NULL)
		(*table)->lines=line;
	else
		ultim->next=line;
	return 1;
}

int adauga_intLinie (t_intLine **line, t_intCell *cell)
{
	if ((*line)==NULL)
		return 0;
	if (cell==NULL)
		return 0;
	t_intCell *l, *ultim;
	//determinare ulltim element din celula
	for (l=(*line)->cells, ultim=NULL;l!=NULL;ultim=l, l=l->next);
	//adaugare la sfarsit
	if (ultim==NULL)
		(*line)->cells=cell;
	else
		ultim->next=cell;
	return 1;
}

/*alocari si adaugari la sfarsit pentru linii si celule de tip float*/

t_floatCell *alloc_floatCell(float value)
{
	t_floatCell *cell;
	//alocare celula
	cell=(t_floatCell *)malloc(sizeof(t_floatCell));
	//verificare alocare celula
	if (!cell)
		return NULL;
	cell->value=value;
	cell->next=NULL;
	return cell;
}

t_floatLine *alloc_floatLine ()
{
	t_floatLine *line;
	//alocare linie
	line=(t_floatLine *)calloc(1, sizeof(t_floatLine));
	//verificare alocare linie
	if (!line)
		return NULL;
	line->next=NULL;
	line->cells=NULL;
	return line;
}

int adauga_floatLinieSf (t_floatLine *line, t_table **table)
{
	if (line==NULL)
		return 0;
	if ((*table)==NULL)
		return 0;
	t_floatLine *ultim, *p;
	//parcurgere pentru a determina ultimul element din lista de linii
	for (p=(t_floatLine *)(*table)->lines, ultim=NULL;p!=NULL;
		ultim=p, p=p->next);
	//adaugare la sfarsit
	if (ultim==NULL)
		(*table)->lines=line;
	else
		ultim->next=line;
	return 1;
}

int adauga_floatLinie (t_floatLine **line, t_floatCell *cell)
{
	if ((*line)==NULL)
		return 0;
	if (cell==NULL)
		return 0;
	t_floatCell *l, *ultim;
	//parcurgere pentru a determina ultimul element
	for (l=(*line)->cells, ultim=NULL;l!=NULL;ultim=l, l=l->next);
	//adaugare la sfarsit
	if (ultim==NULL)
		(*line)->cells=cell;
	else
		ultim->next=cell;
	return 1;
}

/*alocari si adaugari la sfarsit pentru linii si celule de tip string*/

t_stringCell *alloc_stringCell(char *value)
{
	t_stringCell *cell=NULL;
	//alocare celula
	cell=(t_stringCell *)malloc(sizeof(t_stringCell));
	//verificare alocare
	if (!cell)
		return NULL;
	//alocare pentru celula value
	cell->value=(char *)malloc(sizeof(char)*strlen(value)+1);
	//verificare alocare
	if (!cell->value)
	{
		free(cell);
		return NULL;
	}
	//copiere a valorii value in cell->value
	memset(cell->value, 0, strlen(value)+1);
	strncpy(cell->value, value, strlen(value));
	cell->next=NULL;
	return cell;
}

t_stringLine *alloc_stringLine()
{
	t_stringLine *line;
	//alocare linie
	line=(t_stringLine *)calloc(sizeof(t_stringLine), 1);
	//verificare linie
	if (!line)
		return NULL;
	line->next=NULL;
	line->cells=NULL;
	return line;
}

int adauga_stringLinieSf (t_stringLine *line, t_table **table)
{
	if (line==NULL)
		return 0;
	if ((*table)==NULL)
		return 0;
	t_stringLine *ultim, *p;
	//determinarea ultimului element din lista de linii
	for (p=(t_stringLine *)(*table)->lines, ultim=NULL;p!=NULL;
		ultim=p, p=p->next);
	//adaugare la sfarsit
	if (ultim==NULL)
		(*table)->lines=line;
	else
		ultim->next=line;
	return 1;
}

int adauga_stringLinie (t_stringLine **line, t_stringCell *cell)
{
	if ((*line)==NULL)
		return 0;
	if (cell==NULL)
		return 0;
	t_stringCell *s, *ultim;
	//parcurgere lista de celule pentru a determina ultimul element
	for (s=(*line)->cells, ultim=NULL;s!=NULL;ultim=s, s=s->next);
	//adaugare la sfarsit
	if (ultim==NULL)
		(*line)->cells=cell;
	else
		ultim->next=cell;
	return 1;
}

/*alocare lista de coloane si adaugare la finalul listei de coloane*/

t_column *alloc_column (char *name)
{
	t_column *col;
	//alocare coloana
	col=(t_column *)malloc(sizeof(t_column));
	if (!col)
		return NULL;
	strcpy(col->name, name);
	col->next=NULL;
	return col;
}

int adaugare_col_final (t_table **table, t_column *col)
{
	t_column *p, *ultim;
	if ((*table)==NULL)
		return 0;
	//determinare a ultimului element din lista de coloane
	for (p=(*table)->columns, ultim=NULL;p!=NULL;ultim=p, p=p->next);
	//adaugare la sfarsit
	if (ultim==NULL)
		(*table)->columns=col;
	else
		ultim->next=col;
	return 1;
}

//adaugare tabel la finalul listei de tabele
int adaugare_tabel_final (t_db **a, t_table *table)
{
	t_table *t, *ultim;
	if ((*a)==NULL)
		return 0;
	//determinare a ultimului tabel din lista de tabele
	for (t=(*a)->tables, ultim=NULL;t!=NULL;ultim=t, t=t->next);
	//adaugare la final
	if (ultim==NULL)
		(*a)->tables=table;
	else
		ultim->next=table;
	return 1;
}

//creare tabel
int create_table(t_db *a, char *s)
{
	*(s+strlen(s)-1)='\0'; //eliminare '\n'
	int ok=0; char *p=strtok(s, " ");
	t_table *tables;
	if (!a)
		return 0;
	//alocare memorie pentru tabel
	tables=(t_table *)calloc(sizeof(t_table), 1);
	if (!tables)
		return 0;
	t_table *t=NULL;
	p=strtok(NULL, " "); //determinare nume tabel
	t=cauta_tabel(a, p); //cautare in lista de tabele a numelui dat
	if (t!=NULL)
	{
		free(tables);
		printf("Table %s already exists.\n", p); 
		return 0;
	}
	strcpy(tables->name, p); //salveaza in campul name valoarea p
	p=strtok(NULL, " "); //determinare tip de date
	if (strcmp(p,"INT")==0)
	{
		ok=1;
		tables->type=INT;
	}
	if (strcmp(p, "FLOAT")==0)
	{
		ok=1;
		tables->type=FLOAT;
	}
	if (strcmp(p, "STRING")==0)
	{
		ok=1;
		tables->type=STRING;
	}
	if (ok==0)
	{
		free(tables);
		printf("Unknown data type: %s\n", p);
		return 0;
	}
	p=strtok(NULL, " ");
	while (p!=NULL) //citire coloane
	{
		t_column *col=alloc_column (p); //alocare spatiu pentru coloane
		if (!col)
			return 0;
		adaugare_col_final (&tables, col); //adaugare a coloanei la final
		p=strtok(NULL, " ");
	}
	adaugare_tabel_final (&a, tables); //adaugarea tabelului la final
	return 1;
}

//cautare tabel dupa nume
t_table *cauta_tabel(t_db *a, char *nume)
{
	if (a==NULL)
		return NULL;
	t_table *t;
	for (t=a->tables;t!=NULL;t=t->next)
		if (strcmp(nume, t->name)==0)
			break;
	return t; //returneaza pointer catre tabelul care are numele nume
}

//adauga linie de informatii in tabel
int add_line(t_db *a, char *s)
{
	*(s+strlen(s)-1)='\0';
	t_table *t=NULL; char *p=strtok(s, " ");
	t_intLine *li=NULL; t_floatLine *lf=NULL; t_stringLine *ls=NULL;
	t_intCell *ci=NULL; t_floatCell *cf=NULL; t_stringCell *cs=NULL;
	p=strtok(NULL, " ");
	t=cauta_tabel(a, p); 
	if (t==NULL)
	{
		printf("Table \"%s\" not found in database.\n", p);
		return 0;
	}
	if (t->type==0) //adaugare linie de tip INT si celule de tip int
	{
		li=alloc_intLinie();
		adauga_intLinieSf(li, &t);
		p=strtok(NULL, " ");
		while (p!=NULL)
		{
			ci=alloc_intCell(atoi(p));
			if (ci==NULL)
				return 0;
			adauga_intLinie(&li, ci);
			p=strtok(NULL, " ");
		}
	}
	if (t->type==1) //adaugare linie de tip FLOAT si celule de tip float
	{
		lf=alloc_floatLine();
		adauga_floatLinieSf(lf, &t);
		p=strtok(NULL, " ");
		while (p!=NULL)
		{
			cf=alloc_floatCell(atof(p));
			if (cf==NULL)
				return 0;
			adauga_floatLinie(&lf, cf);
			p=strtok(NULL, " ");
		}
	}
	if (t->type==2) //adaugare linie de tip STRING si celule de tip string
	{
		ls=alloc_stringLine();
		adauga_stringLinieSf(ls, &t);
		p=strtok(NULL, " ");
		while (p!=NULL)
		{
			p[strlen(p)]='\0';
			cs=alloc_stringCell(p);
			if (cs==NULL)
				return 0;
			adauga_stringLinie(&ls, cs);
			p=strtok(NULL, " ");
		}
	}
	return 1;
}

//sterge toate liniile din tabelul t de tip int
int clear_lines_int (t_table *t)
{
	if (t==NULL)
		return 0;
	t_intLine *li; t_intCell *ci;
	for (li=(t_intLine *)t->lines;li!=NULL;)
	{
		for (ci=li->cells;ci!=NULL;)
		{
			//eliberare memorie pentru fiecare celula de pe linia li
			t_intCell *auxc;
			auxc=ci;
			ci=ci->next;
			free(auxc);
		}
		//eliberare memorie pentru linia li
		t_intLine *auxl;
		auxl=li;
		li=li->next;
		free(auxl);
	}
	t->lines=NULL;
	return 1;
}

//sterge toate liniile din tabelul t de tip float
int clear_lines_float (t_table *t)
{
	if (t==NULL)
		return 0;
	t_floatLine *lf; t_floatCell *cf;
	for (lf=(t_floatLine *)t->lines;lf!=NULL;)
	{
		for (cf=lf->cells;cf!=NULL;)
		{
			//eliberare memorie pentru fiecare celula de pe linia lf
			t_floatCell *auxc;
			auxc=cf;
			cf=cf->next;
			free(auxc);
		}
		//eliberare memorie pentru linia lf
		t_floatLine *auxl;
		auxl=lf;
		lf=lf->next;
		free(auxl);
	}
	t->lines=NULL;
	return 1;
}

//sterge toate liniile din tabelul t de tip string
int clear_lines_string (t_table *t)
{
	if (t==NULL)
		return 0;
	t_stringLine *ls; t_stringCell *cs;
	for (ls=(t_stringLine *)t->lines;ls!=NULL;)
	{
		for (cs=ls->cells;cs!=NULL;)
		{
			//eliberare memorie pentru fiecare celula de pe linia ls
			t_stringCell *auxc;
			auxc=cs;
			cs=cs->next;
			free(auxc->value);
			free(auxc);
		}
		//eliberare memorie de pe linia ls
		t_stringLine *auxl;
		auxl=ls;
		ls=ls->next;
		free(auxl);
	}
	t->lines=NULL;
	return 1;
}

//sterge liniile dintr-un tabel t
int clear_lines (t_table *t, char *r)
{
	if (t==NULL)
	{
		printf("Table \"%s\" not found in database.\n", r);
		return 0;
	}
	if (t->type==0) //tabela de tip INT
		clear_lines_int(t);
	if (t->type==1) //tabela de tip FLOAT
		clear_lines_float(t);
	if (t->type==2) //tabela de tip STRING
		clear_lines_string(t);
	return 1;
}

//sterge un tabel de tip int
void delete_table_int (t_table **t)
{
	for (;(*t)->columns!=NULL;) //eliberare memorie pentru fiecare coloana
	{
		t_column *aux=(*t)->columns;
		(*t)->columns=(*t)->columns->next;
		free(aux);
	}
	t_intLine *li=(t_intLine *)(*t)->lines;
	t_intCell *ci;
	for (;li!=NULL;)
	{
		//eliberare memorie pentru fiecare linie si celula
		for (ci=li->cells;ci!=NULL;)
		{
			t_intCell *auxc;
			auxc=ci;
			ci=ci->next;
			free(auxc);
		}
		t_intLine *auxl;
		auxl=li;
		li=li->next;
		free(auxl);
	}
}

//sterge un tabel de tip float
void delete_table_float (t_table **t)
{
	for (;(*t)->columns!=NULL;) //eliberare memorie pentru fiecare celula
	{
		t_column *aux=(*t)->columns;
		(*t)->columns=(*t)->columns->next;
		free(aux);
	}
	t_floatLine *lf=(t_floatLine *)(*t)->lines;
	t_floatCell *cf;
	for (;lf!=NULL;)
	{
		//eliberare memorie pentru fiecare linie si fiecare celula
		for (cf=lf->cells;cf!=NULL;)
		{
			t_floatCell *auxc;
			auxc=cf;
			cf=cf->next;
			free(auxc);
		}
		t_floatLine *auxl;
		auxl=lf;
		lf=lf->next;
		free(auxl);
	}
}

//sterge un tabel de tip string
void delete_table_string (t_table **t)
{
	for (;(*t)->columns!=NULL;)
	{
		//eliberare spatiu pentru coloane
		t_column *aux=(*t)->columns;
		(*t)->columns=(*t)->columns->next;
		free(aux);
	}
	t_stringLine *ls=(t_stringLine *)(*t)->lines;
	t_stringCell *cs;
	for (;ls!=NULL;)
	{
		//eliberare memorie pentru fiecare linie si fiecare celula
		for (cs=ls->cells;cs!=NULL;)
		{
			t_stringCell *auxc;
			auxc=cs;
			cs=cs->next;
			free(auxc->value);
			free(auxc);
		}
		t_stringLine *auxl;
		auxl=ls;
		ls=ls->next;
		free(auxl);
	}
}

//sterge tabelul cu numele nume din baza de date
int delete_table (t_db *a, char *nume)
{
	t_table *t=a->tables, *ultim=NULL;
	for (t=a->tables, ultim=NULL;t!=NULL;ultim=t, t=t->next)
		if (strcmp(nume, t->name)==0)
			break;
	if (t==NULL)
	{
		printf("Table \"%s\" not found in database.\n", nume);
		return 0;
	}
	if (ultim==NULL)
		a->tables=a->tables->next;
	else
		ultim->next=t->next;
	if (t->type==0) //tabel de tip INT
		delete_table_int(&t);
	if (t->type==1) //tabel de tip FLOAT
		delete_table_float(&t);
	if (t->type==2) //tabel de tip STRING
		delete_table_string(&t);
	free(t);
	return 1;
}

//sterge lista de celule de tip string si elibereaza memoria
void delete_string_line_cells (t_stringCell **cell)
{
	t_stringCell *cs;
	for (cs=(*cell);cs!=NULL;)
	{
		//elibereaza memoria pentru lista de celule
		t_stringCell *auxC;
		auxC=cs;
		cs=cs->next;
		free(auxC->value);
		free(auxC);
	}
}

//sterge liniile din tabel dupa un criteriu dat si elibereaza memoria ocupata
void delete_table_lines_string (t_table *t, char *relation, char *val, int nr)
{
	int cont=0, ok=0;
	t_stringLine *ls, *antl, *auxl; t_stringCell *cs;
	for (ls=(t_stringLine *)t->lines, antl=NULL;ls!=NULL;)
	{
		ok=0;
		t_stringCell *auxc=ls->cells;
		cont=0;
		for (cs=ls->cells;cs!=NULL;cs=cs->next)
		{	
			//verifica relatia si daca valoarea de pe coloana o respecta
			cont++;
			if (strcmp(relation, "==")==0)
				if (cont==nr && strcmp(cs->value, val)==0)
					ok=1;
			if (strcmp(relation, "<")==0)
				if (cont==nr && strcmp(cs->value, val)<0)
					ok=1;
			if (strcmp(relation, "<=")==0)
				if (cont==nr && strcmp(cs->value, val)<=0)
					ok=1;
			if (strcmp(relation, "!=")==0)
				if (cont==nr && strcmp(cs->value, val)!=0)
					ok=1;
			if (strcmp(relation, ">=")==0)
				if (cont==nr && strcmp(cs->value, val)>=0)
					ok=1;
			if (strcmp(relation, ">")==0)
				if (cont==nr && strcmp(cs->value, val)>0)
					ok=1;
			if (ok==1)
			{
				//sterge linia daca realtia este respectata
				delete_string_line_cells(&auxc); 
				auxl=ls;
				if (antl==NULL)
					t->lines=ls->next;
				else
					antl->next=ls->next;
				ls=ls->next;
				free(auxl);
				break;
			}
		}
		if (ok==0)
		{
			//incrementare anterior si linie daca nu trebuie eliminat
			antl=ls;
			ls=ls->next;
		}
	}
}

//sterge o lista de celule de tip float si elibereaza memoria pentru acestea
void delete_float_line_cells (t_floatCell **cell)
{
	t_floatCell *cf;
	for (cf=(*cell);cf!=NULL;)
	{
		//elibereaza memoria pentru fiecare celula float
		t_floatCell *auxc;
		auxc=cf;
		cf=cf->next;
		free(auxc);
	}
}

//sterge liniile din tabel dupa un criteriu dat si elibereaza memoria ocupata
void delete_table_lines_float (t_table *t, char *relation, char *val, int nr)
{
	float x=atof(val); //transformare val in float
	int cont=0, ok=0;
	t_floatLine *lf, *antl, *auxl; t_floatCell *cf;
	for(lf=(t_floatLine *)t->lines, antl=NULL;lf!=NULL;)
	{
		ok=0;
		t_floatCell *auxc=lf->cells;
		cont=0;
		for (cf=lf->cells;cf!=NULL;cf=cf->next)
		{	
			//verificare conditie pentru fiecare celula de pe coloana data
			cont++;
			if (strcmp(relation, "==")==0)
				if (cont==nr && cf->value==x)
					ok=1;
			if (strcmp(relation, "<")==0)
				if (cont==nr && cf->value<x)
					ok=1;
			if (strcmp(relation, "<=")==0)
				if (cont==nr && cf->value<=x)
					ok=1;
			if (strcmp(relation, "!=")==0)
				if (cont==nr && cf->value!=x)
					ok=1;
			if (strcmp(relation, ">=")==0)
				if (cont==nr && cf->value>=x)
					ok=1;
			if (strcmp(relation, ">")==0)
				if (cont==nr && cf->value>x)
					ok=1;
			if (ok==1) //eliminare linie daca a respectat relatia
			{
				delete_float_line_cells(&auxc);
				auxl=lf;
				if (antl==NULL)
					t->lines=lf->next;
				else
					antl->next=lf->next;
				lf=lf->next;
				free(auxl);
				break;
			}
		}
		if (ok==0)
		{
			//incrementare anterior si lf daca nu a fost respectata relatia
			antl=lf;
			lf=lf->next;
		}
	}
}

//sterge lista de celule de tip int si elibereaza memoria pentru acestea
void delete_int_line_cells (t_intCell **cell)
{
	t_intCell *ci;
	for (ci=(*cell);ci!=NULL;)
	{
		//eliberare memorie pentru lista de celule
		t_intCell *auxc;
		auxc=ci;
		ci=ci->next;
		free(auxc);
	}
}

//sterge liniile din tabel dupa un criteriu dat si elibereaza memoria ocupata
void delete_table_lines_int(t_table *t, char *relation, char *val, int nr)
{
	int x=atoi(val); //transformare val in int
	int cont=0, ok=0;
	t_intLine *li, *antl, *auxl; t_intCell *ci;
	for(li=(t_intLine *)t->lines, antl=NULL;li!=NULL;)
	{
		ok=0;
		t_intCell *auxc=li->cells;
		cont=0;
		for (ci=li->cells;ci!=NULL;ci=ci->next)
		{	
			//verificare conditie pentru fiecare celula de pe coloana data
			cont++;
			if (strcmp(relation, "==")==0)
				if (cont==nr && ci->value==x)
					ok=1;
			if (strcmp(relation, "<")==0)
				if (cont==nr && ci->value<x)
					ok=1;
			if (strcmp(relation, "<=")==0)
				if (cont==nr && ci->value<=x)
					ok=1;
			if (strcmp(relation, "!=")==0)
				if (cont==nr && ci->value!=x)
					ok=1;
			if (strcmp(relation, ">=")==0)
				if (cont==nr && ci->value>=x)
					ok=1;
			if (strcmp(relation, ">")==0)
				if (cont==nr && ci->value>x)
					ok=1;
			if (ok==1) //daca a fost respectata conditia elimina linia
			{
				delete_int_line_cells(&auxc);
				auxl=li;
				if (antl==NULL)
					t->lines=li->next;
				else
					antl->next=li->next;
				li=li->next;
				free(auxl);
				break;
			}
		}
		if (ok==0)
		{
			//incrementare anterior si li daca nu a fost repsectata relatia
			antl=li;
			li=li->next;
		}
	}
}

//sterge liniile din tabel dupa un criteriu dat 
int delete_table_lines(t_table *t, char *col, char *relation, char *val, 
	char *r)
{
	*(val+strlen(val)-1)='\0';
	int gasit=0, nr=0;
	t_column *c;
	if (t==NULL)
	{
		printf("Table \"%s\" not found in database.\n", r);
		return 0;
	}
	for (c=t->columns;c!=NULL;c=c->next)
	{
		nr++;
		if (strcmp(col, c->name)==0)
		{
			//coloana gasita
			gasit=1;
			break;
		}
	}
	if (gasit==0) //coloana nu a fost gasita
	{
		printf("Table \"%s\" does not contain column \"%s\".\n", t->name, col);
		return 0;
	}
	if (gasit==1 && t->type==0) //coloana gasita si tip INT
		delete_table_lines_int(t, relation, val, nr);
	if (gasit==1 && t->type==1) //coloana gasita si tip FLOAT
		delete_table_lines_float(t, relation, val, nr);
	if (gasit==1 && t->type==2) //coloana gasit si tip STRING
		delete_table_lines_string(t, relation, val, nr);
	return 1;
}

//sterge intreaga baza de date
void delete_db (t_db **a)
{
	for (;(*a)->tables!=NULL;)
	{
		//eliberare fiecare tabel pe rand
		t_table *aux=(*a)->tables;
		delete_table(*a, aux->name);
	}
	//eliberare baza de date
	free(*a);
}

//numarul de cifre al unui intreg
int numar_cifre_int (int n)
{
	int nr=0;
	if (n==0)
		return 1;
	while (n!=0)
	{
		nr++;
		n/=10;
	}
	return nr;
}

//numarul de caractere al unui numar real
int digit_float (float n)
{
	int nr=0;
	double x=floor(n);
	if (n<10)
		return (1+F_DIGITS+DOT_DIGIT);
	while (x>=1)
	{
		//numar de cifre a partii intregi a numarului real
		nr++;
		x=x/10;
	}
	return (nr+F_DIGITS+DOT_DIGIT);
}

//printeaza coloanele tabelului t
void print_table_column (t_table *t)
{
	t_column *c; int nr=0;
	for (c=t->columns;c!=NULL;c=c->next)
	{
		nr++;
		printf("%s", c->name);
		for (int i=0;i<MAX_COLUMN_NAME_LEN-strlen(c->name)+1;i++)
			printf(" "); //afisare spatii pana la urmatoarea coloana
	}
	printf("\n");
	for (int i=0;i<nr;i++)
	{
		for (int j=0;j<MAX_COLUMN_NAME_LEN;j++)
			printf("-"); //afisare linie intre coloane si lista de linii
		printf(" "); //padding
	}
}

//printeaza un tabel de tip int
void print_table_int (t_table *t)
{
	t_intLine *li;
	for (li=(t_intLine *)t->lines;li!=NULL;li=li->next)
	{
		t_intCell *ci;
		for (ci=li->cells;ci!=NULL;ci=ci->next)
		{
			//afisare fiecare celula
			printf("%d", ci->value);
			for (int i=0;i<MAX_COLUMN_NAME_LEN-numar_cifre_int(ci->value)+1;
				i++)
				printf(" "); //afisare spatii intre celule
		}
		printf("\n");
	}
}

//printeaza un tabel de tip float
void print_table_float (t_table *t)
{
	t_floatLine *lf;
	for (lf=(t_floatLine *)t->lines;lf!=NULL;lf=lf->next)
	{
		t_floatCell *cf;
		for (cf=lf->cells;cf!=NULL;cf=cf->next)
		{
			//afisare fiecare celula
			printf("%f", cf->value);
			for (int i=0;i<MAX_COLUMN_NAME_LEN-	digit_float(cf->value)+1;i++)
				printf(" "); //afisare spatii intre celule
		}
		printf("\n");
	}
}

//printeaza un tabel de tip string
void print_table_string (t_table *t)
{
	t_stringLine *ls=NULL;
	int i=0; int x=0;
	for (ls=(t_stringLine*)t->lines;ls!=NULL;ls=ls->next)
	{
		t_stringCell *cs=NULL;
		for (cs=ls->cells;cs!=NULL;cs=cs->next)
		{
			x=strlen(cs->value);
			cs->value[x]='\0';
			//afisare fiecare celule
			printf("%s", cs->value);
			for (i=0;i<MAX_COLUMN_NAME_LEN-x+1;i++)
				printf(" "); //afisare spatii intre celule
		}
		printf("\n");
	}
}

//printeaza un tabel dupa numele lui
void print_table (t_table *t, char *r)
{
	if (t==NULL)
		printf("Table \"%s\" not found in database.\n", r);
	else
	{
		printf("TABLE: %s\n", t->name);
		if (t->columns!=NULL)
			print_table_column(t);
		printf("\n");
		if (t->lines!=NULL)
		{
			if (t->type==0)
				print_table_int(t);
			if (t->type==1)
				print_table_float(t);
			if (t->type==2)
				print_table_string(t);
			printf("\n");
		}
		else
			printf("\n");
	}
}

//printeaza o linie dintr-un tabel de tip int
void print_int_line (t_intLine *li)
{
	t_intCell *ci;
	for (ci=li->cells;ci!=NULL;ci=ci->next)
	{
		//afisare linie de care contine lista de celule
		printf("%d", ci->value);
		for (int i=0;i<MAX_COLUMN_NAME_LEN-numar_cifre_int(ci->value)+1;i++)
			printf(" ");
	}
	printf("\n");
}

//printeaza o linie dintr-un tabel de tip float
void print_float_line (t_floatLine *lf)
{
	t_floatCell *cf;
	for (cf=lf->cells;cf!=NULL;cf=cf->next)
	{
		//afisare linie care contine lista de celule
		printf("%f", cf->value);
		for (int i=0;i<MAX_COLUMN_NAME_LEN-digit_float(cf->value)+1;i++)
			printf(" ");
	}
	printf("\n");
}

//printeaza o linie dintr-un tabel de tip string
void print_string_line (t_stringLine *ls)
{
	t_stringCell *cs;
	for (cs=ls->cells;cs!=NULL;cs=cs->next)
	{
		//afisare linie care contine lista de celule
		printf("%s", cs->value);
		for (int i=0;i<MAX_COLUMN_NAME_LEN-strlen(cs->value)+1;i++)
			printf(" "); //afisare spatii intre celule
	}
	printf("\n");
}

//printeaza doar liniile dintr-un tabel de tip int care respecta o conditie
void search_cmp_int (t_table *t, char *relation, char *val, int nr)
{
	printf("TABLE: %s\n", t->name);
	print_table_column(t);
	printf("\n");
	int x=atoi(val), cont=0;
	t_intLine *li; t_intCell *ci;
	for (li=(t_intLine *)t->lines;li!=NULL;li=li->next)
	{
		cont=0;
		for (ci=li->cells;ci!=NULL;ci=ci->next)
		{
			//afisare linie de celule care respecta relatia pe coloana data
			cont++;
			if (strcmp(relation, "==")==0)
				if (cont==nr && ci->value==x)
				{
					print_int_line (li);
					break;
				}
			if (strcmp(relation, "<")==0)
				if (cont==nr && ci->value<x)
				{
					print_int_line(li);
					break;
				}
			if (strcmp(relation, "<=")==0)
				if (cont==nr && ci->value<=x)
				{
					print_int_line(li);
					break;
				}
			if (strcmp(relation, "!=")==0)
				if (cont==nr && ci->value!=x)
				{
					print_int_line(li);
					break;
				}
			if (strcmp(relation, ">=")==0)
				if (cont==nr && ci->value>=x)
				{
					print_int_line(li);
					break;
				}
			if (strcmp(relation, ">")==0)
				if (cont==nr && ci->value>x)
				{
					print_int_line(li);
					break;
				}
		}
	}
	printf("\n");
}

//printeaza doar liniile dintr-un tabel de tip float care respecta o conditie
void search_cmp_float (t_table *t, char *relation, char *val, int nr)
{
	printf("TABLE: %s\n", t->name);
	print_table_column(t);
	printf("\n");
	float x=atof(val); int cont=0;
	t_floatLine *lf; t_floatCell *cf;
	for (lf=(t_floatLine *)t->lines;lf!=NULL;lf=lf->next)
	{
		//afisare linie de celule care respecta conditia date pe coloana data
		cont=0;
		for (cf=lf->cells;cf!=NULL;cf=cf->next)
		{
			cont++;
			if (strcmp(relation, "==")==0)
				if (cont==nr && cf->value==x)
				{
					print_float_line(lf);
					break;
				}
			if (strcmp(relation, "<")==0)
				if (cont==nr && cf->value<x)
				{
					print_float_line(lf);
					break;
				}
			if (strcmp(relation, "<=")==0)
				if (cont==nr && cf->value<=x)
				{
					print_float_line(lf);
					break;
				}
			if (strcmp(relation, "!=")==0)
				if (cont==nr && cf->value!=x)
				{
					print_float_line(lf); 
					break;
				}
			if (strcmp(relation, ">=")==0)
				if (cont==nr && cf->value>=x)
				{
					print_float_line(lf);
					break;
				}
			if (strcmp(relation, ">")==0)
				if (cont==nr && cf->value>x)
				{
					print_float_line(lf);
					break;
				}
		}
	}
	printf("\n");
}

//printeaza doar liniile dintr-un tabel de tip string care respecta o conditie
void search_cmp_string (t_table *t, char *relation, char *val, int nr)
{
	printf("TABLE: %s\n", t->name);
	print_table_column(t);
	printf("\n");
	*(val+strlen(val)-1)='\0';
	int cont=0;
	t_stringLine *ls; t_stringCell *cs;
	for (ls=(t_stringLine *)t->lines;ls!=NULL;ls=ls->next)
	{
		//afisare linie care respecta conditia pe coloana data
		cont=0;
		for (cs=ls->cells;cs!=NULL;cs=cs->next)
		{
			cont++;
			if (strcmp(relation, "==")==0)
				if (cont==nr && strcmp(cs->value, val)==0)
				{
					print_string_line(ls);
					break;
				}
			if (strcmp(relation, "<")==0)
				if (cont==nr && strcmp(cs->value, val)<0)
				{
					print_string_line(ls);
					break;
				}
			if (strcmp(relation, "<=")==0)
				if (cont==nr && strcmp(cs->value, val)<=0)
				{
					print_string_line(ls);
					break;
				}
			if (strcmp(relation, "!=")==0)
				if (cont==nr && strcmp(cs->value, val)!=0)
				{
					print_string_line(ls);
					break;
				}
			if (strcmp(relation, ">=")==0)
				if (cont==nr && strcmp(cs->value, val)>=0)
				{
					print_string_line(ls);
					break;
				}
			if (strcmp(relation, ">")==0)
				if (cont==nr && strcmp(cs->value, val)>0)
				{
					print_string_line(ls);
					break;
				}
		}
	}
	printf("\n");
}

//cauta in tabelul dat liniile care respecta o anumita conditie
void search_db (t_table *t, char *col, char *relation, char *val, char *r)
{
	if (t==NULL)
		printf("Table \"%s\" not found in database.\n", r);
	else
	{
		t_column *c; int gasit=0, nr=0;
		for (c=t->columns;c!=NULL;c=c->next)
		{
			//cautare coloana si incrementare nr pentru a retine poz coloanei
			nr++;
			if (strcmp(c->name, col)==0)
			{
				gasit=1;
				break;
			}
		}
		if (gasit==0) //coloana nu este gasita in tabel
			printf("Table \"%s\" does not contain column \"%s\".\n", t->name, 
				col);
		if (gasit==1 && t->type==0) //coloana gasita si tip INT
			search_cmp_int(t, relation, val, nr);
		if (gasit==1 && t->type==1) //coloana gasita si tip INT
			search_cmp_float(t, relation, val, nr);
		if (gasit==1 && t->type==2) //coloana gasita si tip INT
			search_cmp_string (t, relation, val, nr);
	}
}

//afiseaza intreaga baza de date
void print_db (t_db *a)
{
	t_table *t;
	printf("DATABASE: %s\n\n", a->name);
	{
		//afisare intreaga baza de date parcurgand fiecare tabel
		for (t=a->tables;t!=NULL;t=t->next)
		{
			printf("TABLE: %s\n", t->name);
			if (t->columns!=NULL)
				print_table_column(t);
			printf("\n");
			if (t->lines!=NULL)
			{
				if (t->type==0)
					print_table_int(t);
				if (t->type==1)
					print_table_float(t);
				if (t->type==2)
					print_table_string(t);
			}
			printf("\n");
		}
	}
}
