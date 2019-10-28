#include <stdio.h>
#include <string.h>

exec sql include sqlca;
	
exec sql begin declare section;
	char *identity = "fedora/oracle";
	char statement[1024];
exec sql end declare section;


void catchOracleError();

int main(){
	exec sql connect :identity;
	if (sqlca.sqlcode < 0){
		printf("Could not connect to oracle!\n");
		exit(1);
	}
	else{
		printf("Connected to Oracle\n");
	}

	exec sql set transaction read write;

	//Drop tables if they exist..
	exec sql execute immediate "DROP TABLE Supplier";
	exec sql execute immediate "DROP TABLE Part";
	exec sql execute immediate "DROP TABLE SP";
	

	//Creat Tables
	//Create the Supplier table
	strcpy(statement,"CREATE TABLE Supplier (S# varchar2(2) primary key, sname varchar2(10), status int, city varchar(10))");
	
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create Supplier table\n");
		exit(1);
	}
	else{
		printf("Created Supplier table!\n");
	}

	//Create the Part table
	strcpy(statement,"CREATE TABLE Parts (P# varchar2(2) primary key, pname varchar2(8), color varchar2(8), weight float, city varchar(10))");
	
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create Part table\n");
		exit(1);
	}
	else{
		printf("Created Part table!\n");
	}

	//Create the SP lookup table
	strcpy(statement,"CREATE TABLE SP (S# varchar2(2), P# varchar2(2), quantity int, constraint PK_D primary key (S#, P#))");
	
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create SP lookup table\n");
		exit(1);
	}
	else{
		printf("Created SP table!\n");
	}
exec sql commit release;
exit(0);	 
}