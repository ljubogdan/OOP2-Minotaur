#include "lavirint_utils.hpp"

#define BOLDGREEN "\033[1m\033[32m"   
#define RESET "\033[0m"

struct Ivica {
    int x1, y1, x2, y2;
};

DisjunktniSkup::DisjunktniSkup(int velicina) {
    roditelj.resize(velicina);
    rang.resize(velicina, 0);
    for (int i = 0; i < velicina; i++) roditelj[i] = i;
};

int DisjunktniSkup::pronadji(int x) {
    if (roditelj[x] != x) roditelj[x] = pronadji(roditelj[x]);
    return roditelj[x];
};

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

void LavirintUtils::postaviMinotaura(Lavirint& lavirint) {
    // postavljamo minotaura na random poziciju na donju polovinu lavirinta
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