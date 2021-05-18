#include "Rope.hpp"
#include<sys/time.h>
int RAND(size_t num)
{
    return   rand()%num;
}
char * Get(std::vector<char>&v)
{
    char* p = new char[v.size()+3];
    for(size_t i = 0; i < v.size();i++)
    {
        *(p+i)=v[i];
    }
    return p;
}
int main()
{
    std::vector<char>buf;
    auto buft = LoadRepo("text.txt",buf);
    double sum;
    int n =1000;
    for(int i =0;i<n;i++)
    {
    struct timeval tv1, tv2;
    double elapsed;
   
    gettimeofday(&tv1, NULL);
    // test repo
  //  buft.insert_(buft.get_count(),'s');
//   auto p =buft.GetKByte(RAND(buf.size()));
//   *p = '2';
    // std::cout<<buft.GetInterval(20,200)<<std::endl;
    buft.WriteToFile("out.txt");
    //----------------------------------------------------------------
    // test naive string
    //  char* str=Get(buf);
    //  *(str+buf.size())='s';
    gettimeofday(&tv2, NULL);
    elapsed = (double) (tv2.tv_usec - tv1.tv_usec)/1000 + 
    (double) (tv2.tv_sec - tv1.tv_sec)*1000;
    sum+=elapsed;
    
    }
    //std::cout<<sum << std::endl;
    std::cout<<"Time is : "<<sum/n<<std::endl;

    buft.WriteToFile("out.txt");
    return 0;
}
