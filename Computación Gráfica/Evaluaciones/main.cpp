#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

    string C = "-0.71f, 0.08f, 0.0f,    0.0f,0.0f,0.0f,";
    string D = "-0.75f, -0.05f, 0.0f,   0.0f,0.0f,0.0f,";
    string F = "-0.56f, 0.02f, 0.0f,    0.0f,0.0f,0.0f,";
    string G = "-0.51f, 0.11f, 0.0f,    0.0f,0.0f,0.0f,";

    //input: CDG
    //output: "-0.71f, 0.08f, 0.0f,    0.0f,0.0f,0.0f,"; "-0.75f, -0.05f, 0.0f,   0.0f,0.0f,0.0f,"; "-0.51f, 0.11f, 0.0f,    0.0f,0.0f,0.0f,";

    vector<string> input;
    input.push_back(C);
    input.push_back(D);
    input.push_back(F);
    input.push_back(G);

    vector<string> output;
    output.push_back(C);
    output.push_back(D);
    output.push_back(G);
    output.push_back(G);

    for(int i = 0; i < input.size(); i++){
        cout << input[i] << endl;
    }



    return 0;
}

