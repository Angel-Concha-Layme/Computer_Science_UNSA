#ifndef SQUARE_H
#define SQUARE_H

class Square{
private:
    int matrix[14][14];
    int get_num_square_base(int i);
    void propagate(int index);
    int calculateAnswer(int i, int n);
public:
    Square();
    int get_num_square(int i, int j);
};

Square::Square(){
    for (int i = 0; i < 14; i++){
        for (int j = 0; j < 14; j++){
            matrix[i][j] = 0;
        }
    }
    matrix[13][13] = 1;
}

void Square::propagate(int index){
    for (int i = index+1; i < 14; i++)
        matrix[i][index] = matrix[index][index];

    for (int j = index+1; j < 14; j++)
        matrix[index][j] = matrix[index][index];
}

int Square::calculateAnswer(int i, int n){
    if (matrix[i+1][i+1] == 0)
        matrix[i+1][i+1] = get_num_square_base(i+1);

    return matrix[i+1][i+1] + (n*n);
}

int Square::get_num_square_base(int i){
    int answer = calculateAnswer(i, 13-i+1);
    matrix[i][i] = answer;
    propagate(i);
    return matrix[i][i];
}

int Square::get_num_square(int i, int j){
    if (matrix[i][j] != 0)
        return matrix[i][j];

    int indice = (i < j)? ( i) : (j);    
    return get_num_square_base(indice);
}

#endif 