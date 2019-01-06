#pragma once
#include <string>
#include <mysql.h>

class CZMysqlapi{
public:
    CZMysqlapi();
    ~CZMysqlapi();

    int query(const std::string & strStmt);
private:
    int init();
    int uninit();

public:
    MYSQL* m_pMYSQL;
};