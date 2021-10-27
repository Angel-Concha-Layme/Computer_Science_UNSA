#include<bits/stdc++.h>
#include <fstream>
using namespace std;

//print clauses with iterator
void print_clauses(vector<set<int>>&clauses){
    int rows = clauses.size();
    cout<<"##START##"<<endl;
    for(int i=0;i<rows;i++)
    {
        for (auto it=clauses[i].begin(); it != clauses[i].end(); ++it) 
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<"##END##"<<endl;
    return;
}




//print literals answer
void print_assignmnet(vector<int> &assignment){
    for(int i=0;i<assignment.size();i++)
        cout<<assignment[i]<<" ";
    cout<<endl;
}

int check_empty_clause(vector<set<int>> &clauses){
    int rows = clauses.size();
    for(int i=0;i<rows;i++)
    {
        if(clauses[i].size()==0)
            return 1;
    }
    return 0;
}

void remove_new_p(vector<set<int>>&clauses, vector<int> &assignment){
    int new_p = assignment.back();
    for(int i=0;i<clauses.size();i++)
    {
        if(clauses[i].find(new_p) != clauses[i].end()){
            clauses.erase(clauses.begin()+i);
            i--;
        }
        else if(clauses[i].find(-1*new_p)!=clauses[i].end()){
            clauses[i].erase(clauses[i].find(-1*new_p));
        }
    }
    return;
}

void unit_prop(vector<set<int>> &clauses,vector<int> &assignment){
    int flag=1;
    while(flag==1){
        flag=0;
        int rows = clauses.size();
        for(int i=0;i<rows;i++){
            if(clauses[i].size()==1){
                flag=1;
                set<int>::iterator it = clauses[i].begin();
                clauses.erase(clauses.begin()+i);
                assignment.push_back(*it);
                remove_new_p(clauses,assignment);
                break;
            }
        }
    }
    return;
}

void pure_literal_assign(vector<set<int>> &clauses, vector<int> &assignment, int literals){
    vector<int> check(literals+1, 0);
    int curr_rows = clauses.size();
    for(int i=0;i<curr_rows;i++)
    {
        for (auto it=clauses[i].begin(); it != clauses[i].end(); ++it) 
        {
            int val = *it;
            if(val<0){
                if(check[-1*val]==1)
                    check[-1*val]=2;
                else if(check[-1*val]==0)
                    check[-1*val]=-1;
                else if(check[-1*val]==2)
                    check[-1*val]=2;
            }
            else{
                if(check[val]==-1)
                    check[val]=2;
                else if(check[val]==0)
                    check[val]=1;
                else if(check[val]==2)
                    check[val]=2;
            }
        }
    }
    for(int i=1;i<=literals;i++)
    {
        if(check[i]==1 || check[i]==-1){
            assignment.push_back(check[i]*i);
            remove_new_p(clauses,assignment);
        }
    }
    return;
}

void print_ans(vector<int> &assignment, int literals){
    int size = assignment.size();
    vector<int> solution(literals+1,1);
    for(int i=0;i<size;i++)
    {
        int val = assignment[i];
        if(val<0)
        {
            solution[val*-1]=-1;
        }
    }
    for(int i=1;i<=literals;i++)
    {
        cout<<i*solution[i]<<" ";
    }
    cout<<endl;
    return;
}



bool DPLL_algo(vector<set<int>>clauses,vector<int> assignment,int new_p, int literals){
    
    assignment.push_back(new_p);
    remove_new_p(clauses,assignment);
    unit_prop(clauses,assignment);
    pure_literal_assign(clauses,assignment,literals);
    if(clauses.size()==0){
        // print_ans(assignment,literals);
        return true;
    }
    if(check_empty_clause(clauses)==1){
        return false;
    }
    int  newp = *(clauses[0].begin());
    return DPLL_algo(clauses, assignment,newp, literals) || DPLL_algo(clauses,assignment,-1*newp,literals);
}

bool SAT_SOLVER(vector<set<int>> &clauses, int literals){
    bool answer;
    vector<int> assignment;
   
    unit_prop(clauses,assignment);
    pure_literal_assign(clauses,assignment,literals);
    if(clauses.size()==0){
        
        cout<<"SATISFIABLE"<<endl;
        answer = true;
        return 1;

    }
    if(check_empty_clause(clauses)==1){
        cout<<"UNSATISFIABLE"<<endl;
        answer= false;
        return 0;
    }
    int  new_p = *(clauses[0].begin());
    answer =  DPLL_algo(clauses, assignment,new_p, literals) || DPLL_algo(clauses,assignment,-1*new_p,literals);
    if(answer){
        cout<<"SATISFIABLE"<<endl;
        return 1;}
        // print_clauses(clauses);
    else {  
        cout<<"UNSATISFIABLE"<<endl;
        return 0;
        }

}


void contraction(vector<set<int>>&clauses,vector<set<int>> &nclauses,int literals ){
    int rows = clauses.size();
    // nclauses = clauses;
    // print_clauses(nclauses);
    for(int i = 0; i < rows ;i++)
    {
        for (auto j = clauses[i].begin(); j != clauses[i].end(); j++)
        {          
            for (auto it=nclauses[i].begin(); it != nclauses[i].end(); ++it) 
            {
              auto temp = *j;
              if(*it == *j){
                clauses[i].erase(clauses[i].find(temp));
                cout << "some2\n";
                bool check = SAT_SOLVER(clauses, literals);
                if(check_empty_clause(clauses))
                  cout<<"UNSATISFIABLE"<<endl;
                  
                else{
                  cout<<"SATISFIABLE\n";
                }

                cout << "some\n";                
              }
                
            }
        }
        
    }
}

void add_claus(vector<set<int>> &clauses, int literals){

  clauses.resize(literals+1);
  literals++;
  vector<int> curr_temp;
  for(int i = 0; i < literals; i++){
    int n;
    cin >> n;
    while(literals !=0){
      clauses[i].insert(n);
    }
  }


}


void comb(int N, int K,vector<vector<int>> &ex_all_literals){
    std::string bitmask(K, 1); 
    bitmask.resize(N, 0); 
    do {
        vector<int> temporal;
        for (int i = 0; i < N; ++i){
            if (bitmask[i]) std::cout << " " << i+1;
            temporal.push_back(i+1);
        }
        ex_all_literals.push_back(temporal);
        temporal.clear();
        cout<<endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

void add_negation(vector<vector<int>> &ex_all_literals){
    for (auto i = 0; i < ex_all_literals.size(); i++){
        for (auto j = 0; j < ex_all_literals.size() ; j++){
            cout<<ex_all_literals[i][j];
        }
    }
}

void expansion(int &literals){
    vector<vector<int>> expansion_all_literals;
    for (auto i = 2; i <= literals; i++){
        comb(literals, i,expansion_all_literals);    
    }
    add_negation(expansion_all_literals);
}







int main()
{
    ifstream inFile;
    string v,v1;
    string name;
    cout<<"Enter name of file: "<<endl;
    cin>>name;
    inFile.open(name);
    inFile>>v;
    inFile>>v1;
    while(v!="p" || v1!="cnf"){
        v=v1;
        inFile>>v1;
    }    

    int literals;
    int rows;
    inFile>>literals;
    inFile>>rows;
    cout<<"No of literals "<<literals<<endl;
    cout<<"No of rows (cnf) "<<rows<<endl;
    vector<set<int>> clauses(rows);
    int num;
    int i=0;
    for(;i<rows;i++)
    {
        inFile>>num;
        while(num!=0)
        {
            //cout<<" entro " <<endl;
            clauses[i].insert(num);
            inFile>>num;
        }
    }
    cout<< " valor i = "<< i <<endl;
    cout<<" inicial vector ";
    print_clauses(clauses);
    cout<<endl;

    expansion(literals);



    /* clauses[2].insert(5);
    cout<<" final vector ";
    print_clauses(clauses); */
   // agregar 
    // ifstream inFile2;
    // string v2,v12;
    // string name2;
    // cout<<"Enter name of  new file: "<<endl;
    // cin>>name;
    // inFile.open(name);
    // inFile>>v2;
    // inFile>>v12;
    // while(v2!="p" || v12!="cnf"){
    //     v2=v12;
    //     inFile>>v12;
    // }    

    // int literals2;
    // int rows2;
    // inFile>>literals2;
    // inFile>>rows2;
    // cout<<"No of literals "<<literals2<<endl;
    // cout<<"No of rows (cnf) "<<rows2<<endl;
    // vector<set<int>> clauses2(rows);
    // int num2;
    // int i2;
    // for(int j=0;i2<rows2;i2++,j++)
    // {
    //     inFile2>>num2;
    //     while(num2!=0)
    //     {
    //         //cout<<" entro " <<endl;
    //         clauses[i2].insert(num2);
    //         inFile2>>num2;
    //     }
    // }
    
    

    // inFile.close();


    /* ifstream inFile2;
    string v2,v3;
    string name2;
    cout << "Enter file name file name for second:\n";
    cin>>name2;
    inFile2.open(name2);
    inFile2>>v2;
    inFile2>>v3;
    while(v2!="p" || v3!="cnf"){
        v2=v3;
        inFile2>>v3;
    }    

    int literals2;
    int rows2;
    inFile2>> literals2;
    inFile2>>rows2;
    cout<<"No of literals "<<literals2<<endl;
    cout<<"No of rows (cnf) "<<rows2<<endl;
    vector<set<int>> nclauses(rows2);
    
    int num2;
    for(int i=0;i<rows2;i++)
    {
        inFile2>>num2;
        while(num2!=0)
        {
            
            nclauses[i].insert(num2);
            inFile2>>num2;
        }
    } */

    //inFile2.close();


    // agregar 
    ifstream inFile2;
    string v2,v3;
    string name2;
    cout << "Enter file name file name for second:\n";
    cin>>name2;
    inFile2.open(name2);
    inFile2>>v2;
    inFile2>>v3;
    while(v2!="p" || v3!="cnf"){
        v2=v3;
        inFile2>>v3;
    }    

    int literals2;
    int rows2;
    inFile2>> literals2;
    inFile2>>rows2;
    cout<<"No of literals "<<literals2<<endl;
    cout<<"No of rows (cnf) "<<rows2<<endl;
    clauses.resize(rows+rows2);
    int newRows=rows2+rows;
    int num2;
    for(int j=i;j<rows2+i;j++){
        inFile2>>num2;
        while(num2!=0)
        {
            clauses[j].insert(num2);
            inFile2>>num2;
        }
    }
    cout<<" vector final\n ";
    print_clauses(clauses);
    if(SAT_SOLVER(clauses,literals))
      cout << "lafe papu\n";
    else{
      cout <<"sera el fin del hombre araña :v ?\n";
    }






    // contraction(clauses,nclauses,literals);

    // expansion(clauses, nclauses, literals);
    // cout<<"No of literals "<<literals<<endl;
    // cout<<"No of rows (cnf) "<<rows<<endl;
    //add_claus(clauses, literals);
    
    // vector<int> assignment;
    // //Algorithm
    // unit_prop(clauses,assignment);
    // pure_literal_assign(clauses,assignment,literals);
    // if(clauses.size()==0){
    //     print_ans(assignment,literals);
    //     cout<<"SATISFIABLE"<<endl;
    //     return 0;
    // }
    // if(check_empty_clause(clauses)==1){
    //     cout<<"UNSATISFIABLE"<<endl;
    //     return 0;
    // }
    // int  new_p = *(clauses[0].begin());
    // bool answer =  DPLL_algo(clauses, assignment,new_p, literals) || DPLL_algo(clauses,assignment,-1*new_p,literals);
    // if(answer)
    //     cout<<"SATISFIABLE"<<endl;
    //     // print_clauses(clauses);
    // else   
    //     cout<<"UNSATISFIABLE"<<endl;



    return 0;
}






