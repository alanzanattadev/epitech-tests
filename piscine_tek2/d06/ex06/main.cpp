#include <iostream>
#include <string>
#include <cstdlib>
#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"
#include "sickkoalalist.h"
#include "koalanurselist.h"
#include "koaladoctorlist.h"
#include "hopital.h"

void testOfficiel(void) {
    KoalaDoctor cox("Cox");
    KoalaDoctor house("House");
    KoalaDoctor tired("Boudur-Oulot");
    KoalaDoctorList doc1(&cox);
    KoalaDoctorList doc2(&house);
    KoalaDoctorList doc3(&tired);

    KoalaNurse a(1);
    KoalaNurse b(2);
    KoalaNurseList nurse1(&a);
    KoalaNurseList nurse2(&b);

    SickKoala cancer("Ganepar");
    SickKoala gangrene("Scarface");
    SickKoala rougeole("RedFace");
    SickKoala variole("Varia");
    SickKoala fracture("Falter");
    SickKoalaList sick1(&cancer);
    SickKoalaList sick2(&gangrene);
    SickKoalaList sick3(&rougeole);
    SickKoalaList sick4(&variole);
    SickKoalaList sick5(&fracture);

    Hospital stAnne;

    stAnne.addDoctor(&doc1);
    stAnne.addDoctor(&doc2);
    stAnne.addDoctor(&doc3);

    stAnne.addSick(&sick1);
    stAnne.addSick(&sick2);
    stAnne.addSick(&sick3);
    stAnne.addSick(&sick4);
    stAnne.addSick(&sick5);

    stAnne.addNurse(&nurse1);
    stAnne.addNurse(&nurse2);

    stAnne.addSick(&sick4);

    stAnne.run();

    if (nurse1.isEnd() && sick1.isEnd() && doc1.isEnd())
        std::cout << "Lists cleaned up." << std::endl;
    else
        std::cerr << "You fail ! Boo !" << std::endl;
}

void (*testSets)(void)[] = {
    &testOfficiel
}

int main(int argc, char **argv)
{
    std::stringstream ss;
    unsigned int randomSeed = 42;
    unsigned int test = 0;

    switch (argc) {
    default:
    case 3:
        ss.str(argv[2]);
        ss >> randomSeed;
    case 2:
        ss:str(argv[1]);
        ss >> test;
    case 1:
    }

    srandom(randomSeed);

    return (0);
}
