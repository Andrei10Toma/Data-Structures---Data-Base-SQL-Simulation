/*TOMA Andrei-311CB*/
#include "structures.h"

/*determina cuvantul dupa primul spatiu dupa comanda s*/
char *first_space(char *s)
{
	char *r=strchr(s, ' ');
	r=r+1;
	*(r+strlen(r)-1)='\0';
	return r;
}

int main()
{
	t_db *db=NULL; char *r=NULL, s[MAX_CMD_LEN]; *s='\0';
	while (strncmp("DELETE_DB", s, strlen("DELETE_DB"))!=0)
	{
		int ok_cmd=0; //variabila pentru determinarea corectitudinii comenzii
		//citire fiecare comanda si apelarea functiei respective comandei
		fgets(s, MAX_CMD_LEN, stdin);
		if (strncmp(s, "INIT_DB", strlen("INIT_DB"))==0)
		{ 
			ok_cmd=1;
			r=first_space(s);
			db=init_db(r);
		}
		if (strncmp(s, "CREATE", strlen("CREATE"))==0)
		{
			ok_cmd=1;
			create_table(db, s);
		}
		if (strncmp(s, "PRINT_DB", strlen("PRINT_DB"))==0)
		{
			print_db(db);
			ok_cmd=1;
		}
		if (strncmp(s, "ADD", strlen("ADD"))==0)
		{
			ok_cmd=1;
			add_line(db, s);
		}
		if (strncmp(s, "DELETE ", strlen("DELETE "))==0 )
		{
			ok_cmd=1;
			char *p=strtok(s, " ");
			p=strtok(NULL, " ");
			char *col=strtok(NULL, " ");
			if (col==NULL) //stergere un tabel
			{
				*(p+strlen(p)-1)='\0';
				delete_table (db, p);
			}
			else //stergere selectiva dupa un anumit criteriu
			{
				char *relation=strtok(NULL, " "); char *val=strtok(NULL, " ");
				t_table *t=cauta_tabel(db, p);
				delete_table_lines (t, col, relation, val, p);
			}
		}
		if (strncmp(s, "PRINT", strlen("PRINT"))==0 && ok_cmd==0)
		{
			ok_cmd=1;
			r=first_space(s);
			t_table *t=cauta_tabel(db, r);
			print_table(t, r);
		}
		if (strncmp(s, "CLEAR", strlen("CLEAR"))==0)
		{
			ok_cmd=1;
			r=first_space(s);
			t_table *t=cauta_tabel(db, r);
			clear_lines(t, r);
		}
		if (strncmp(s, "SEARCH", strlen("SEARCH"))==0)
		{
			ok_cmd=1;
			char *col, *relation, *val, *p;
			p=strtok(s, " ");
			p=strtok(NULL, " ");
			col=strtok(NULL, " ");
			relation=strtok(NULL, " ");
			val=strtok(NULL, " ");
			t_table *t=cauta_tabel(db, p);
			search_db (t, col, relation, val, p);
		}
		if (ok_cmd==0 && strncmp(s, "DELETE_DB", strlen("DELETE_DB"))!=0)
			printf("Unknown command: %s\n", s); //comanda incorecta
	}
	delete_db(&db); //stergere intreaga baza de date
	return 0;
}
