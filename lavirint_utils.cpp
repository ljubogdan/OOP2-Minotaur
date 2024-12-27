/**
 * @file lavirint_utils.cpp
 * 
 * @brief Implementacija funkcija za generisanje lavirinta, postavljanje robota, minotaura i predmeta
 * 
 * @date 27.12.2024 19:18:00
 * @author Bogdan Ljubinković SV2/2023
 * 
 * @see lavirint_utils.hpp
 */

#include "lavirint_utils.hpp"

#define BOLDGREEN "\033[1m\033[32m"   
#define RESET "\033[0m"

/**
 * @struct Ivica
 * @brief Struktura koja predstavlja ivicu (granu) u lavirintu.
 * 
 * Ivica povezuje dve ćelije u lavirintu definisane svojim koordinatama.
 * Koristi se za generisanje lavirinta kao grafa.
 */
struct Ivica {
    int x1; /**< Koordinata reda prve ćelije. */
    int y1; /**< Koordinata kolone prve ćelije. */
    int x2; /**< Koordinata reda druge ćelije. */
    int y2; /**< Koordinata kolone druge ćelije. */
};

/**
 * @brief Konstruktor klase DisjunktniSkup.
 * 
 * Inicijalizuje strukturu disjunktnih skupova sa zadatom veličinom.
 * Svaki element je inicijalno u svom zasebnom skupu.
 * 
 * @param velicina Broj elemenata u početnom skupu.
 */

DisjunktniSkup::DisjunktniSkup(int velicina) {
    roditelj.resize(velicina);
    rang.resize(velicina, 0);
    for (int i = 0; i < velicina; i++) roditelj[i] = i;
};

/**
 * @brief Pronalazi koren skupa kojem pripada dati element.
 * 
 * Implementira optimizaciju kompresije puta, tako da se svi elementi na putu do korena direktno povežu sa korenom,
 * čime se ubrzavaju naredne operacije.
 * 
 * @param x Element za koji se traži koren.
 * @return int Indeks korena skupa kojem element pripada.
 */

int DisjunktniSkup::pronadji(int x) {
    if (roditelj[x] != x) roditelj[x] = pronadji(roditelj[x]);
    return roditelj[x];
};

/**
 * @brief Spaja dva skupa u jedan.
 * 
 * Skupovi se spajaju na osnovu ranga (dubine). Ako su elementi već u istom skupu,
 * spajanje se ne vrši. Ako nisu, koren skupa sa manjim rangom postaje podskup
 * skupa sa većim rangom. Ako su rangi jednaki, rang novog korena se povećava.
 * 
 * @param x Indeks prvog elementa.
 * @param y Indeks drugog elementa.
 * @return bool Vraća true ako su skupovi uspešno spojeni, false ako su već spojeni.
 */

bool DisjunktniSkup::spojiSkupove(int x, int y) {
    int korenX = pronadji(x);
    int korenY = pronadji(y);
    if (korenX == korenY) return false;

    if (rang[korenX] < rang[korenY]) {
        roditelj[korenX] = korenY;
    } else if (rang[korenX] > rang[korenY]) {
        roditelj[korenY] = korenX;
    } else {
        roditelj[korenY] = korenX;
        rang[korenX]++;
    }
    return true;
};

/**
 * @brief Generiše lavirint u obliku matrice koristeći Kruskalov algoritam.
 * 
 * Na osnovu zadate veličine lavirinta, kreira mrežu povezivanja i koristi disjunktne skupove 
 * da generiše razapeti graf koji predstavlja lavirint. Sve ćelije počinju kao zidovi (1), 
 * a hodnici (0) se postavljaju nasumično uz održavanje povezanosti.
 * 
 * @param lavirint Referenca na 2D vektor koji predstavlja lavirint. 
 * Svaka ćelija sadrži 1 za zid ili 0 za hodnik.
 */

void generisiVektorLavirint(std::vector<std::vector<int>>& lavirint) {
    int redovi = lavirint.size();
    int kolone = lavirint[0].size();
    srand(time(0));

    std::vector<Ivica> ivice;
    for (int i = 1; i < redovi; i += 2) {
        for (int j = 1; j < kolone; j += 2) {
            if (i + 2 < redovi) ivice.push_back({i, j, i + 2, j});
            if (j + 2 < kolone) ivice.push_back({i, j, i, j + 2});
        }
    }

    for (size_t i = 0; i < ivice.size(); i++) {
        int nasumicniIndeks = rand() % ivice.size();
        std::swap(ivice[i], ivice[nasumicniIndeks]);
    }

    DisjunktniSkup skup((redovi / 2) * (kolone / 2));
    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            lavirint[i][j] = 1;
        }
    }

    for (auto& ivica : ivice) {
        int celija1 = (ivica.x1 / 2) * (kolone / 2) + (ivica.y1 / 2);
        int celija2 = (ivica.x2 / 2) * (kolone / 2) + (ivica.y2 / 2);

        if (skup.spojiSkupove(celija1, celija2)) {
            lavirint[ivica.x1][ivica.y1] = 0;
            lavirint[ivica.x2][ivica.y2] = 0;
            lavirint[(ivica.x1 + ivica.x2) / 2][(ivica.y1 + ivica.y2) / 2] = 0;
        }
    }
};

/**
 * @brief Postavlja robota na početnu poziciju u lavirintu.
 * 
 * Robot se postavlja na prvu slobodnu poziciju ispod ulaza ('U') u lavirint.
 * Ako se pronađe ulaz, stara ćelija se briše, a na njeno mesto se postavlja robot ('R').
 * 
 * @param lavirint Referenca na objekat klase Lavirint u kojem se postavlja robot.
 */

void LavirintUtils::postaviRobota(Lavirint& lavirint) {
    int brojKolona = lavirint.getBrojKolona();
    Element*** matrica = lavirint.getMatrica();
    for (int i = 0; i < brojKolona; i++) {
        if (matrica[0][i]->getSimbol() == 'U') {
            delete matrica[1][i];
            matrica[1][i] = new Robot('R');
            break;
        }
    }
}

/**
 * @brief Postavlja predmete na slučajne pozicije u lavirintu.
 * 
 * Predmeti ('P') se postavljaju na nasumične slobodne pozicije unutar lavirinta.
 * Svaki predmet ima nasumično dodeljen efekat iz unapred definisanog skupa efekata.
 * 
 * @param lavirint Referenca na objekat klase Lavirint u kojem se postavljaju predmeti.
 * @param brojPredmeta Broj predmeta koji treba postaviti u lavirint.
 */

void LavirintUtils::postaviPredmete(Lavirint& lavirint, int brojPredmeta) {
    int brojRedova = lavirint.getBrojRedova();
    int brojKolona = lavirint.getBrojKolona();
    Element*** matrica = lavirint.getMatrica();

    std::string efekti[] = {"Magla rata", "Mač", "Štit", "Čekić"};

    for (int i = 0; i < brojPredmeta; i++) {
        while (true) {
            int randomRed = rand() % (brojRedova - 2) + 1;
            int randomKolona = rand() % (brojKolona - 2) + 1;
            if (matrica[randomRed][randomKolona]->getSimbol() == ' ') {
                int randomEfekat = rand() % 4;
                delete matrica[randomRed][randomKolona];
                matrica[randomRed][randomKolona] = new Predmet('P', efekti[randomEfekat]);
                break;
            }
        }
    }
}

/**
 * @brief Postavlja minotaura na slučajnu poziciju u donjoj polovini lavirinta.
 * 
 * Minotaur ('M') se postavlja na nasumičnu slobodnu poziciju u donjoj polovini lavirinta.
 * Pozicija se bira tako da ne remeti postojeće hodnike i predmete.
 * 
 * @param lavirint Referenca na objekat klase Lavirint u kojem se postavlja minotaur.
 */

void LavirintUtils::postaviMinotaura(Lavirint& lavirint) {
    int brojRedova = lavirint.getBrojRedova();
    int brojKolona = lavirint.getBrojKolona();
    Element*** matrica = lavirint.getMatrica();

    while (true) {
        int randomRed = rand() % (brojRedova - 2) + 1;
        int randomKolona = rand() % (brojKolona - 2) + 1;
        if (matrica[randomRed][randomKolona]->getSimbol() == ' ' && randomRed >= brojRedova / 2) {
            delete matrica[randomRed][randomKolona];
            matrica[randomRed][randomKolona] = new Minotaur('M');
            break;
        }
    }
}

/**
 * @brief Generiše kompletan lavirint, uključujući zidove, hodnike, ulaz, izlaz, robota, predmete i minotaura.
 * 
 * Koristi generisani vektor lavirinta za popunjavanje matrice lavirinta.
 * Dodaje ulaz ('U') na gornji red i izlaz ('I') na donji red. 
 * Na kraju, poziva funkcije za postavljanje robota, predmeta i minotaura.
 * 
 * @param lavirint Referenca na objekat klase Lavirint koji treba da se generiše.
 * @param brojPredmeta Broj predmeta koji treba postaviti u lavirint.
 */

void LavirintUtils::generisiLavirint(Lavirint& lavirint, int brojPredmeta) {
    auto start = std::chrono::high_resolution_clock::now();
    
    int brojRedova = lavirint.getBrojRedova();
    int brojKolona = lavirint.getBrojKolona();

    std::vector<std::vector<int>> vektorLavirint(brojRedova, std::vector<int>(brojKolona, 1));
    generisiVektorLavirint(vektorLavirint);


    auto matrica = lavirint.getMatrica();

    for (int i = 0; i < brojRedova; i++) {
        for (int j = 0; j < brojKolona; j++) {
            if (vektorLavirint[i][j] == 1) {
                matrica[i][j] = new Element('#');
            } else {
                matrica[i][j] = new Element(' ');
            }
        }
    }

    while (true) {
        int randomKolona_U = rand() % (brojKolona - 2) + 1;
        if (vektorLavirint[1][randomKolona_U] == 0) {
            delete matrica[0][randomKolona_U];
            matrica[0][randomKolona_U] = new Element('U');
            break;
        }
    }

    while (true) {
        int randomKolona_I = rand() % (brojKolona - 2) + 1;
        if (vektorLavirint[brojRedova - 2][randomKolona_I] == 0) {
            delete matrica[brojRedova - 1][randomKolona_I];
            matrica[brojRedova - 1][randomKolona_I] = new Element('I');
            break;
        }
    }

    postaviRobota(lavirint);
    postaviPredmete(lavirint, brojPredmeta);
    postaviMinotaura(lavirint);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> vreme = end - start;

    std::cout << BOLDGREEN << "\nLavirint generisan za " << vreme.count() << " sekundi\n" << RESET << std::endl;
}