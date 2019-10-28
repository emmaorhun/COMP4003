#include <stdio.h>
#include <string.h>

exec sql include sqlca;
	
exec sql begin declare section;
	char *identity = "fedora/oracle";
	char statement[1024];
exec sql end declare section;

void populatePartTable(){
  char *input;
	char partInput[1024];
	
	while(1){
		printf("Enter a part using this format: P# name colour weight city.  (enter exit when done):\n");
		fgets(partInput, 1024, stdin);
		printf("Attemping to create Part: -%s\n", partInput);
		
		if( strcmp(partInput, "exit") == 0){
			printf("Exitting\n");
			break;
		}
		char *partID = strtok(partInput, " \n");
printf("Extracted ID: --%s--\n", partID);
		char *partName = strtok(NULL, " \n");
printf("Extracted Name: --%s--\n", partName);
		char *partColour = strtok(NULL, " \n");
printf("Extracted Color: --%s--\n", partColour);
		float weight = atof(strtok(NULL, " \n"));
printf("Extracted weight: --%f--\n", weight);
		char *city = strtok (NULL, " \n");
printf("Extracted city: --%s--\n", city);
		
		strcpy(statement, "INSERT INTO part VALUES (:v1, :v2, :v3, :v4, :v5)");
		exec sql prepare s from :statement;
		if (sqlca.sqlcode < 0){
			printf("Statement not prepared!\n");
			break;
		}
		
		exec sql execute s using :partID, :partName, :partColour, :weight, :city;
		if (sqlca.sqlcode < 0){
			printf("Population not complete!\n");
		}
		else {
			printf("Population completed\n");
		}
	}
}

void populateSupplierTable(){
	char *input;
  char supplierInput[1024];
	
	while(1){
		printf("Enter a supplier using this format:  S# name status city. (enter 'exit' when done):\n ");
		fgets(supplierInput, 1024, stdin);
		printf("Attemping to create Supplier: -%s\n", supplierInput);
		supplierInput[strlen(supplierInput) - 1] = 0;
		
		if( strcmp(supplierInput, "exit") == 0){
			printf("Exitting\n");
			break;
		}
		char *supplierID = strtok(supplierInput, " \n");
printf("Supplier ID: --%s--\n", supplierID);
		char *supplierName = strtok(NULL, " \n");
printf("Supplier name: --%s--\n", supplierName);
		int status = atoi(strtok(NULL, " \n"));
printf("Supplier status: --%d--\n", status);
		char *city = strtok(NULL, " \n");
printf("Supplier city: --%s--\n", city);
		
		strcpy(statement, "INSERT INTO supplier VALUES (:v1, :v2, :v3, :v4)");
		exec sql prepare s from :statement;
		if (sqlca.sqlcode < 0){
			printf("Statement not prepared!\n");
			break;
		}
		
		exec sql execute s using :supplierID, :supplierName, :status, :city;
		if (sqlca.sqlcode < 0){
			printf("Population not complete!\n");
		}
		else {
			printf("Population completed\n");
		}
	}	
}

void populateSPTable(){
  char *input;
	char entryInput[1024];
	
	while(1){
		printf("Enter an entry using this format: S# P# quantity. (enter 'exit' when done)\n");
		fgets(entryInput, 1024, stdin);
		printf("Attemping to create Entry from:: -%s-\n", entryInput);
		
		if( strcmp(userInput, "exit") == 0){
			printf("Exitting\n");
			break;
		}
		char *supplierID = strtok(entryInput, " \n");
printf("user input ID: --%s--\n", supplierID);
		char *partID = strtok(NULL, " \n");
printf("user input part ID: --%s--\n");
		int quantity = atoi(strtok(NULL, " \n"));
printf("user input quantity: --%d--\n", quantity);
		
		strcpy(statement, "INSERT INTO sp VALUES (:v1, :v2, :v3)");
		exec sql prepare s from :statement;
		if (sqlca.sqlcode < 0){
			printf("Statement not prepared!\n");
			break;
		}
		
		exec sql execute s using :supplierID, :partID, :quantity;
		if (sqlca.sqlcode < 0){
			printf("Insert not complete!\n");
		}
		else {
			printf("Insertion completed\n");
		}
	}
}


int main(){
	char userInput[100];
	exec sql connect :identity;
	if (sqlca.sqlcode < 0){
		printf("Could not connect to oracle!\n");
		exit(1);
	}
	else{
		printf("Connected to Oracle\n");
	}

	exec sql set transaction read write;
	while (1){
		printf("Let's add some table entries!\n\nEnter table name to add to (or 'exit'):");
		printf(" ");
		fgets(userInput, 100, stdin);
		//set the last character to null, instead of a newline character
		userInput[strlen(userInput) - 1] = 0;

		printf("\nValue entered was -%s-...\n", userInput);
	 	
		//If the user enters 'quit' then quit the program and commit changes
		if (strcmp(userInput, "exit") == 0){
			printf("Exitting\n");
			break;
		}
		
		if ( strcmp(userInput, "Supplier") == 0){
			populateSupplierTable();
		}
		else if ( strcmp(userInput, "Part") == 0){
			populatePartTable();
		}
		else if ( strcmp(userInput, "SP") == 0){
			populateSPTable();
		}
	}
exec sql commit release;
exit(0);	 
}

