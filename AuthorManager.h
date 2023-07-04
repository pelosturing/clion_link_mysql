//
// Created by admin on 2023/7/4.
//

#ifndef TESTENV_AUTHORMANAGER_H
#define TESTENV_AUTHORMANAGER_H

#include <vector>
#include <string>
#include <mysql.h>
#include <iostream>

using std::string,std::vector;

// your table in database
struct Author{
    int author_id{0};
    string name;
    string country;
    explicit Author() = default;
    explicit Author(int id): author_id(id) {};
    Author(int id, string s1, string s2):
            author_id(id),name(std::move(s1)),country(std::move(s2)) {};
};

class AuthorManager
{
private:
    MYSQL* mysql;
    const char* HOST = "localhost";
    const char* USER = "root";  //your mysql user name
    const char* PASSWORD = "*******";  //your password
    const char* DATABASE_NAME ="test01";    //your database name
    const int PORT = 3306;
public:
    static AuthorManager* GetInstance() //单例模式
    {
        static AuthorManager AuthorManager;
        return &AuthorManager;
    }
public:
    AuthorManager();
    ~AuthorManager();
    void insertAuthor(Author& a);
    void updateAuthor(Author& a);
    bool deleteAuthor(int author_id);
    vector<Author> getAuthor(const string& condition = "");
};


#endif //TESTENV_AUTHORMANAGER_H
