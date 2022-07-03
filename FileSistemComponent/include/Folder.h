#ifndef FOLDER_
#define FOLDER_

#include"./IcomposableOflistable.h"
#include"./Ilistable.h"

#include <iostream>
#include <vector>
#include <algorithm>


class Folder : public  Ilistable , public IcomposableOflistable
{
    private:
        std::string m_nodeName;
        std::vector<Ilistable*> m_children;

    public:
        Folder(std::string);
        ~Folder();
        void list(int);
        void add(Ilistable*);
        void remove(Ilistable*);
     
};

#endif