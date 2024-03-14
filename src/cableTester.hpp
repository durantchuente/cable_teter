#ifndef CableTester_HPP
#define CableTester_HPP

#include <string>

using namespace std;

//Definition de la classe Cabletester
class CableTester
{
    //Definition des differentes propriétés et fonctions de la classe
    private:
        static int orderPositionCross[8];
        static int orderPositionStraight[8];
    public:
        CableTester();

        void verifyCableType(int resultOrderSignalPosition[], int n);
};

#endif