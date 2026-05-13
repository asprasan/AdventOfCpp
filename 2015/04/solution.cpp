// md5.h and md5.cpp used from https://www.zedwood.com/article/cpp-md5-function
// g++ solution.cpp  md5.cpp -o solution
#include "md5.h"

int main(){
    std::string secret="ckczppom";
    std::string md5_output="", md5_input="";
    int counter = 0;

    while (1){
        std::string counter_str=std::to_string(counter);
        std::string md5_input = secret + counter_str;

        md5_output = md5(md5_input);
        // std::cout<<"Solution for part 1: "<<md5_input<<std::endl;
        if (md5_output.substr(0,5) == "00000"){
            std::cout<<"Solution for part 1: "<<counter<<std::endl;
            break;
        }
        counter++;
    }

    while (1){
        std::string counter_str=std::to_string(counter);
        std::string md5_input = secret + counter_str;

        md5_output = md5(md5_input);
        if (md5_output.substr(0,6) == "000000"){
            std::cout<<"Solution for part 2: "<<counter<<std::endl;
            break;
        }
        counter++;
    }
}
