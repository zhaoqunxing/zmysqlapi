#include <stdio.h>
#include <mysql.h>
#include <string>
#include"zmysqlapi.h"
using namespace std;

#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD ""
#define DATABASE "test"

void insert_sql(char * sql);
void query_sql(char* sql);

int main(int argc,char *argv[])
{
    string strsql = "insert into test values('user','423457')";
    CZMysqlapi oCZMysqlapi;
    oCZMysqlapi.query(strsql);

    return 0;
}