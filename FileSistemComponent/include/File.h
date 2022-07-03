#ifndef FILE_H
#define FILE_H

#include "./Ilistable.h"
#include <vector>
#include <iostream>

class File : public Ilistable
{
private:
    std::string m_nodeName;
    std::vector<Ilistable*> m_children;
public:
    File(std::string nodeName);
    ~File();
    void list(int depth);
};
       



#endif