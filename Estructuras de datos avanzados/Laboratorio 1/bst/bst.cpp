#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

struct node{
    unsigned int data;
    int left;
    int right;
};

void constructor(std::vector<struct node> &v1, int dataF){
    struct node b1 = { dataF, -1, -1 };
    v1.push_back(b1);
}

void setleft(std::vector <struct node>&v1, int currIndex, int dataF){
    unsigned int leftIndex = v1.size();
    v1[currIndex].left = leftIndex;
    struct node b1 = { dataF, -1, -1 };
    v1.push_back(b1);
}

void setright(std::vector<struct node> &v1, int currIndex, int dataF){
    unsigned int rightIndex = v1.size();
    v1[currIndex].right = rightIndex;
    struct node b1 = { dataF, -1, -1 };
    v1.push_back(b1);
}

void Insert(std::vector<struct node> &v1, int dataF){
    if(v1.size() == 0){
        std::cout<<"F en el chat"<<std::endl;
        return;
    }
    unsigned int currentIdx = 0;
    while ( currentIdx < v1.size() ){
        if(dataF <= v1[currentIdx].data){
            if( v1[currentIdx].left == -1){
                setleft(v1, currentIdx, dataF);
                break;
            }
            else
                currentIdx = v1[currentIdx].left;
        }
        else{
            if(v1[currentIdx].right == -1){
                setright(v1, currentIdx, dataF);
                break;
            }
            else
                currentIdx = v1[currentIdx].right;
        }
    }
}


void InTrav(std::vector <struct node> &v1, unsigned int Idx){
    if(v1[Idx].left != -1)
        InTrav(v1,v1[Idx].left );
    std::cout<<v1[Idx].data<<std::endl;
    if( v1[Idx].right != -1)
        InTrav(v1, v1[Idx].right);
}

void PreTrav(std::vector <struct node> &v1, unsigned int Idx){
    std::cout<<v1[Idx].data<<std::endl;
    if(v1[Idx].left != -1)
        PreTrav(v1,v1[Idx].left );
    if( v1[Idx].right != -1)
        PreTrav(v1, v1[Idx].right);
}

void PostTrav(std::vector <struct node> &v1, unsigned int Idx){
    if(v1[Idx].left != -1)
        PostTrav(v1,v1[Idx].left );
    if( v1[Idx].right != -1)
        PostTrav(v1, v1[Idx].right);
    std::cout<<v1[Idx].data<<std::endl;
}




int main(){
    std::vector <struct node> v1;
    constructor(v1, 30);
    Insert(v1, 20);
    Insert(v1, 6);
    Insert(v1, 40);
    Insert(v1, 35);
    Insert(v1, 16);
    Insert(v1, 7);

    //InTrav(v1, 0);
    //PreTrav(v1,0);
    //PostTrav(v1,0);
    return 0;
}