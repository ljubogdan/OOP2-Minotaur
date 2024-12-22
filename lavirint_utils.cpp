#include "lavirint_utils.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

void randomWalk(Lavirint& lavirint, int startX, int startY, int endX, int endY) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int x = startX, y = startY;
    Element tempElement(x, y, ' ');
    lavirint.setElement(x, y, tempElement);

    while (x != endX || y != endY) {
        std::vector<int> directions = {0, 1, 2, 3};
        std::random_shuffle(directions.begin(), directions.end());

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[directions[i]];
            int ny = y + dy[directions[i]];

            if (nx > 0 && ny > 0 && nx < lavirint.getBrojRedova() - 1 && ny < lavirint.getBrojKolona() - 1 &&
                lavirint.getElement(nx, ny).getSimbol() == '#') {
                Element tempElement(nx, ny, ' ');
                lavirint.setElement(nx, ny, tempElement);
                Element midElement((x + nx) / 2, (y + ny) / 2, ' ');
                lavirint.setElement((x + nx) / 2, (y + ny) / 2, midElement);
                x = nx;
                y = ny;
                moved = true;
                break;
            }
        }

        if (!moved) {
            // Ako je put zaglavljen, poveži direktno prema cilju
            if (x < endX) x++;
            else if (x > endX) x--;
            else if (y < endY) y++;
            else if (y > endY) y--;
            Element tempElement(x, y, ' ');
            lavirint.setElement(x, y, tempElement);
        }
    }
}

    

void LavirintUtils::generisiLavirint(Lavirint& lavirint, int brojPredmeta) {
    srand(time(nullptr)); 

    int brojRedova = lavirint.getBrojRedova();
    int brojKolona = lavirint.getBrojKolona();

    for (int i = 0; i < brojRedova; i++) { // postavi sve elemente na prazno polje
        for (int j = 0; j < brojKolona; j++) {
            Element element(i, j, '#');
            lavirint.setElement(i, j, element);
        }
    }

    for (int i = 0; i < brojRedova; i++) { // postavi sve elemente na prazno polje
        for (int j = 0; j < brojKolona; j++) {
            Element element(i, j, '#');
            lavirint.setElement(i, j, element);
        }
    }

    int randomKolona_U = rand() % (brojKolona - 2) + 1; // postavljamo ulaz i izlaz
    Element element(0, randomKolona_U, 'U');
    lavirint.setElement(0, randomKolona_U, element);

    int randomKolona_I = rand() % (brojKolona - 2) + 1;
    element = Element(brojRedova - 1, randomKolona_I, 'I');
    lavirint.setElement(brojRedova - 1, randomKolona_I, element);

    randomWalk(lavirint, 1, randomKolona_U, brojRedova - 2, randomKolona_I);

    int brojDodavanja = (brojRedova * brojKolona) / 5; // 20% zida pretvori u prolaze
    for (int i = 0; i < brojDodavanja; i++) {
        int x = rand() % (brojRedova - 2) + 1;
        int y = rand() % (brojKolona - 2) + 1;
        if (lavirint.getElement(x, y).getSimbol() == '#') {
            Element tempElement(x, y, ' ');
            lavirint.setElement(x, y, tempElement);
        }
    }
    
    for (int i = 0; i < brojRedova; i++) {
        for (int j = 0; j < brojKolona; j++) {
            std::cout << lavirint.getElement(i, j).getSimbol();
        }
        std::cout << std::endl;
    }
}
