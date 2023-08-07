#ifndef CLASESALUMNO_H
#define CLASESALUMNO_H
#include <string>

using namespace std;


class ClasesAlumno
{
    public:
        std::string Clase;
        ClasesAlumno *Abajo;
        ClasesAlumno(std::string clase);
        virtual ~ClasesAlumno();

    protected:

    private:
};

#endif // CLASESALUMNO_H
