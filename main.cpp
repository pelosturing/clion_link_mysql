#include <iostream>
#include "AuthorManager.h"

using namespace std;

void showDatabase(){
    vector<Author> authors =AuthorManager::GetInstance()->getAuthor();
    for (const auto& item:authors)
    {
        cout<<item.author_id<<" "<<item.name<<" "<<item.country<<"\n";
    }
}

int main(){
    Author author1(2,"guo yan","china");
    AuthorManager m1;
    // 增
    m1.insertAuthor(author1);
    showDatabase();
    // 改
    Author author2(2,"yuqian","china");
    m1.updateAuthor(author2);
    showDatabase();
    // 删
    m1.deleteAuthor(2);
    showDatabase();

    return  0;
}


