#pragma once
#pragma once
#include "Stdafx.h"
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlucode.h>


using namespace std;

//Displays possible errors that can occur when we use SQL function in c++
void showSQLErrorr(unsigned int handleType, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
		// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information
		cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;
}

void callInsert()
{
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	char SQLQuery[] = "SELECT * FROM Employe";
	//char SQLInsert[] = "insert into Employe(name,id,age) values ('tamim',210,20)";

	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment
			break;

		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			// Allocates the connection
			break;

		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections
			break;

		SQLCHAR retConString[1024]; // Conection string
		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=testdb; UID=myID; PWD=1234;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			// Establishes connections to a driver and a data source
		case SQL_SUCCESS:
			break;
		case SQL_SUCCESS_WITH_INFO:
			break;
		case SQL_NO_DATA_FOUND:
			showSQLErrorr(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLErrorr(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLErrorr(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			// Allocates the statement
			break;

		// for insert data
		//string name = "xyz";
		//int age = 20;
		//int id = 200;
		//char SQLInsertQury[] = "insert into Employe(name,id,age) values ('"+name+"',"+id+","+age+")";
		char SQLInsertQuery[] = "insert into Employe(name,id,age) values ('Node2200',1011,21)";
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLInsertQuery, SQL_NTS)) {
			// Executes a preparable statement
			showSQLErrorr(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else {

			cout << " AUV Sensor's Data Inserted Into Database Table____!!!\n"; 
			cout << " " << endl;
		}

		
	} while (FALSE);

	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	// Frees the resources and disconnects


}