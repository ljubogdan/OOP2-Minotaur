/**
 * @file igra.hpp
 * @brief Klasa Igra
 * @version 1.0
 * 
 * Klasa koja predstavlja igru.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 03:08:07 
 */

#ifndef IGRA_HPP
#define IGRA_HPP

#include <iostream>
#include "lavirint.hpp"
#include "lavirint_utils.hpp"
#include <thread>
#include <chrono>
#include <termio.h>
#include <unistd.h>
#include "upis_stanja.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#define BOLDRED "\033[1m\033[31m"
#define BOLDDARKBLUE "\033[1m\033[34m"
#define BOLDPINK "\033[1m\033[35m"
#define BOLDGREEN "\033[1m\033[32m"

/**
 * @class Igra
 * @brief Klasa koja predstavlja igru
 * 
 * @param lavirint pokazivač na objekat klase Lavirint
 * @param brojPredmeta broj predmeta
 * @param krajIgre indikator kraja igre
 * @param robotPobedio indikator pobede robota
 * @param minotaurPobedio indikator pobede minotaura
 * @param minotaurZiv indikator života minotaura
 * @param trajanjeEfekta trajanje efekta
 * @param trenutniEfekat trenutni efekat
 * @param robotX x koordinata robota
 * @param robotY y koordinata robota
 * @param minotaurX x koordinata minotaura
 * @param minotaurY y koordinata minotaura
 * 
 * @version 1.0
 */


class Igra {
    private:
        Lavirint* lavirint;
        int brojPredmeta;
        bool krajIgre;
        bool robotPobedio;
        bool minotaurPobedio;
        bool minotaurZiv;
        int trajanjeEfekta;

        std::string trenutniEfekat;

        int robotX, robotY;
        int minotaurX, minotaurY;

    public:
        Igra(int brojRedova, int brojKolona, int brojPredmeta);
        ~Igra();
        void pokreniIgru();
        void zavrsiIgru();

        Lavirint* getLavirint() const;
        int getBrojPredmeta() const;
        bool getKrajIgre() const;
        int getTrajanjeEfekta() const;
        void setLavirint(Lavirint* lavirint);
        void setBrojPredmeta(int brojPredmeta);
        void setKrajIgre(bool krajIgre);
        void setTrajanjeEfekta(int trajanjeEfekta);
        std::string getTrenutniEfekat() const;
        void setTrenutniEfekat(std::string trenutniEfekat);


        void prikaziLavirint();

        int getRobotX() const;
        int getRobotY() const;
        int getMinotaurX() const;
        int getMinotaurY() const;
        void setRobotX(int robotX);
        void setRobotY(int robotY);
        void setMinotaurX(int minotaurX);
        void setMinotaurY(int minotaurY);

        void pomeriRobota(int x, int y);
        void pomeriMinotauraRandom();

        bool getRobotPobedio() const;
        bool getMinotaurPobedio() const;
        void setRobotPobedio(bool robotPobedio);
        void setMinotaurPobedio(bool minotaurPobedio);
        bool getMinotaurZiv() const;
        void setMinotaurZiv(bool minotaurStatus);

        int procenaStanja(); // 1 - robot pobedio, 2 - minotaur pobedio, 3 - prekid igre (Q), 0 - nastavak igre

        void porukaRobotPobedio();
        void porukaMinotaurPobedio();
        void porukaKrajIgre();

        void prikaziLavirintZamagljen();
};

#endif // IGRA_HPP


