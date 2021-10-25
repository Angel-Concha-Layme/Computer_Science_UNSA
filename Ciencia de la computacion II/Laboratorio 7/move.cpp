#include <string>
#include <iostream>
#include <utility>
 
struct A{
    std::string s;
    A() : s("test") { }
    A(const A& o) : s(o.s) { std::cout << "move failed!\n"; }
    A(A&& o) : s(std::move(o.s)) { }
    A& operator=(const A& other)
    {
         s = other.s;
         std::cout << "copy assigned\n";
         return *this;
    }
    A& operator=(A&& other)
    {
         s = std::move(other.s);
         std::cout << "move assigned\n";
         return *this;
    }
};
 
A f(A a) { return a; }
 
struct B : A{
     std::string s2; 
     int n;
    // operador de asignación de movimiento implícito B & B :: operator = (B &&) 
     // llama al operador de asignación de movimiento de A 
     // llama al operador de asignación de movimiento de s2 
     // y realiza una copia en bits de n 
};
 
struct C : B{
    ~C() { } // destructor evita la asignación de movimiento implícita 
};
 
struct D : B{
    D() { }
    ~D() { } // el destructor evitaría la asignación de movimiento implícita
    D& operator=(D&&) = default; // forzar una asignación de movimiento de todos modos  
};
 
int main(){
    A a1, a2;
    std::cout << "Intentando mover-asignar A desde rvalue temporary \n ";
    a1 = f(A());  // mover-asignación desde rvalue temporary
    std::cout << "Intentando mover-asignar A desde xvalue \n ";
    a2 = std::move(a1); // mover-asignar desde xvalue 
 
    std::cout << "Intentando mover-asignar B \n ";
    B b1, b2;
    std::cout << "Antes de mover, b1.s = \" " << b1.s << "\"\n";
    b2 = std::move(b1); // llama a la asignación de movimiento implícita
    std::cout << "Después del movimiento, b1.s = \"" << b1.s << "\"\n";
 
    std::cout << "Intentando mover-asignar C\n";
    C c1, c2;
    c2 = std::move(c1); // llama al operador de asignación de copias 
 
    std::cout << "Intentando mover-asignar D \n";
    D d1, d2;
    d2 = std::move(d1);
    return 0;
}