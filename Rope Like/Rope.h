#ifndef ROPE_H_
#define ROPE_H_
#include"Heads.hpp"
#include"RB_Tree.hpp"
#include"Hashfun.hpp"


// ReadFile to buffer
void ReadFileToBuffer(const std::string& filename,std::vector<char>&buffer)
{
    std::ifstream File(filename);
    if(!File.is_open())
    {
        std::cerr << "File not found: " << filename << std::endl;
        exit(0);
    }
	buffer.resize(File.seekg(0, std::ios::end).tellg());
	File.seekg(0, std::ios::beg).read(&buffer[0], static_cast<std::streamsize>(buffer.size()));
    std::cout<<"File size : "<< buffer.size()<<std::endl;
}
class Rope{

private:
    Node *root =NIL;
    int count =0;
    void Change_(int ks);
    std::list<char>buffer;
public:
    Rope()=default;
    //insert <k,v>
    void insert_(int k,char v);
    char*  GetKByte(int k);//Get kth byte
    std::string GetInterval(int m,int n);//Get (m,n) Bytes
    void insert_front(char v);//append front
    void WriteToFile(const std::string& filename);
    int get_count() const{return count;}
    int delete_(int p);
};
int Rope::delete_(int p){
    int pos = hash(p);
    char* c = new char;
 
    Node* n = find(root,pos);
       std::list<std::pair<int,char>>::iterator iter=n->val.value.end();
    if(n==NULL)
    {
        return 0;
    }
    else{
        
        for(auto it=n->val.value.begin();it!=n->val.value.end();it++)
        {
                if(it->first==pos)
                {
                    iter=it;
                    break;
                }
        }
    }
    if(iter!=n->val.value.end())
        n->val.value.erase(iter);
    return 1;
}
void Rope::WriteToFile(const std::string& filename)
{
    std::ofstream File(filename,std::ios::out);
    for(const auto& c:buffer)
    {
        File<<c;
    }
    File.close();
}
void Rope::Change_(int k )
{
    Node* node=find(root,hash(k));
    for(auto it=node->val.value.begin();it!=node->val.value.end();it++)
    {
        if(it->first==k)
        {
            it->first++;
        }
    }
}
void Rope::insert_front(char v){
      for(auto i=0;i<count;i++) 
      {
          Change_(i);
      } 
      insert_(0,v);
}
std::string Rope::GetInterval(int m,int n)
{
    std::string result = "";
    for(int i =m;i<=n;i++)
    {
        char* result1=GetKByte(i);
        if(result1!=NULL)
            result+=std::string();
    }
    return result;
}
char* Rope::GetKByte(int k)
{
    int pos = hash(k);
    char* c = new char;
    Node* n = find(root,pos);
    if(n==NULL)
    {
        return NULL;
    }
    else{
        
        for(const auto& it:n->val.value)
        {
                if(it.first==k)
                {
                    *c=it.second;
                    break;
                }
        }
    }
    return c;
}
void Rope::insert_(int k,char v){
    auto n = find(root,hash(k));
    if(n==NULL){
        struct Data d;
        d.index=hash(k);
        d.value.push_back({k,v});
        root = insert(root,d);
        buffer.push_back(v);
    }
    else{
        n->val.value.push_back({k,v});
        buffer.push_back(v);
    }
    count++;
}
//Construct Rope from file
Rope LoadRepo(const char* filename,std::vector<char>&buf)
{
    Rope result;
    ReadFileToBuffer(filename,buf);
    for(int i =0;i<(int)buf.size();i++)
    {
        result.insert_(i+1,buf[i]);
    }
    return result;
}
#endif
