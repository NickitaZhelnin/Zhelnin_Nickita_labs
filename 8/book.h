#pragma once
#include "print.h"
//#include <string>
class Book :
    public Print
{
public:
    Book(void);
    Book(string, string, int, string);
    Book(const Book&);
    ~Book(void);
    int Get_pages() { return pages; }
    void Set_pages(int P) { pages = P; }
    string Get_name() { return name; }
    string Get_izdat() {return izdat; }
    void Set_izdat(string I) { izdat = I; }
    void Show();
    void Input();
    Book& operator=(const Book&);
protected:
    int pages;
    string izdat;
};