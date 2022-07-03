#include <iostream>
#include <vector>
#include <algorithm>

class Ilistable
{
public:

    virtual void list(int depth) = 0;
    

};


class IcomposableOflistable
{  private:
    
    public:
        virtual ~IcomposableOflistable(){};
        virtual void add(Ilistable* component) = 0;
        virtual void remove(Ilistable* component) = 0;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////COMPOSITE///////////////////////////////////////////////////////


class Folder : public IcomposableOflistable, public Ilistable
{
    private:
        std::string m_nodeName;
        std::vector<Ilistable*> m_children;

    public:
        Folder(std::string nodeName)
        {
            this->m_nodeName = nodeName;
        }

        virtual ~Folder(){}
        
        void list(int depth)//operation
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

        void add(Ilistable* component)
        {
            m_children.push_back(component);
        }

        void remove(Ilistable* component)
        {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////LEAF////////////////////////////////////////////////////////
class File : public Ilistable
{
    private:
        std::string m_nodeName;
        std::vector<Ilistable*> m_children;

    public:
        File(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~File(){}

        void list(int depth)//operation
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

       
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////
int main()
{
    Folder* folder_01 = new Folder("folder_01");

    Folder* folder_02 = new Folder("folder_02");
    folder_01->add(folder_02);

    Folder* folder_03 = new Folder("folder_03");
    File* fileA = new File("file A");
    folder_03->add(fileA);
    folder_03->add(new File("file B"));
    folder_02->add(folder_03);

    
    folder_01->list(1);

    delete folder_03;
    delete folder_02;
    delete folder_01;
    return 0;
}