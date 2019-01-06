#include <stdio.h>
#include "zmysqlapi.h"
using namespace std;


CZMysqlapi::CZMysqlapi(){
    m_pMYSQL = NULL;
    init();
}

CZMysqlapi::~CZMysqlapi(){
    uninit();
}

int CZMysqlapi::init(){
    m_pMYSQL = new MYSQL;
    if(NULL != mysql_init(m_pMYSQL)){
        if(mysql_real_connect(m_pMYSQL,"localhost","root","2222","test",0,NULL,0)){
            printf("connect success!\n");
            return 0;
        }else{
        throw mysql_error(m_pMYSQL);
        return -1;
        }
    }else{
        throw mysql_error(m_pMYSQL);
        return -1;
    }
    return -1;
}

int CZMysqlapi::uninit(){
    delete m_pMYSQL;
    m_pMYSQL = NULL;
    mysql_close(m_pMYSQL);
    mysql_library_end();
    return 0;
}

int CZMysqlapi::query(const string & strStmt){
    int res=mysql_query(m_pMYSQL, strStmt.c_str());
    if(res){
        throw mysql_error(m_pMYSQL);
        return -1;
    }
    return 0;
}

  