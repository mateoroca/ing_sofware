
#include "../include/Folder.h"

 Folder::Folder(std::string nodeName)
        {
            this->m_nodeName = nodeName;
        }
        
Folder::~Folder()
{

}
void Folder::list(int depth)//operation
        {
            std::string newStr(depth, '-');
            std::cout << newStr << m_nodeName << " depth: " << depth << std::endl;
            for(std::vector<Ilistable*>::const_iterator it = m_children.begin(); it != m_children.end(); ++it)
            {
                if(*it != 0)
                {
                    (*it)->list(depth + 1);
                }
            }
        }      
        
 void Folder::add(Ilistable* component)
        {
            m_children.push_back(component);
        }

void Folder::remove(Ilistable* component)
        {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }