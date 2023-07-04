//
// Created by admin on 2023/7/4.
//


#include "AuthorManager.h"


AuthorManager::AuthorManager()
{
    mysql = mysql_init(nullptr);
    //set character code
    mysql_options(mysql,MYSQL_SET_CHARSET_NAME,"utf8");
    if(!mysql_real_connect(mysql,this->HOST,this->USER, this->PASSWORD,
                           this->DATABASE_NAME,this->PORT,nullptr,0)){
        std::cerr<<"connect failed"<<std::endl;
    } else {
        std::cout<<"connect success"<<std::endl;
    }
}

AuthorManager::~AuthorManager()
{
    mysql_close(mysql);
}

void AuthorManager::insertAuthor(Author &a)
{
    string sql = "insert into test01.author (author_id, name, country) values ("
                 + std::to_string(a.author_id) + ", "
                 +"'" + a.name + "'" + ", "
                 +"'" + a.country + "'" + ")";
    if (mysql_query(mysql,sql.c_str())){
        std::cerr<<"insert failed"<<std::endl;
    } else {
        std::cout<<"insert success"<<std::endl;
    }
}

void AuthorManager::updateAuthor(Author &a)
{
    string sql = "UPDATE author SET name = '"+a.name + "'"
            + ", country = '"+a.country + "' WHERE author_id = "
            + std::to_string(a.author_id);
    if (mysql_query(mysql,sql.c_str())){
        std::cerr<<"update failed"<<std::endl;
    } else {
        std::cout<<"update success"<<std::endl;
    }
}

bool AuthorManager::deleteAuthor(int author_id)
{
    string sql = "DELETE FROM author WHERE author_id = " + std::to_string(author_id);
    if (mysql_query(mysql,sql.c_str())){
        std::cerr<<"delete failed"<<std::endl;
        return false;
    } else {
        std::cout<<"delete success"<<std::endl;
        return true;
    }
}


vector<Author> AuthorManager::getAuthor(const string& condition)
{
    vector<Author> author_list;
    string sql = "SELECT * FROM author " + condition;

    if (mysql_query(mysql,sql.c_str())){
        std::cerr<<"select failed"<<std::endl;
        return {};
    }
    std::cout<<"select success"<<std::endl;
    MYSQL_RES* res = mysql_store_result(mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))){
        Author aut;
        aut.author_id = atoi(row[0]);
        aut.name = row[1];
        aut.country = row[2];
        author_list.emplace_back(aut);
    }
    return author_list;
}
