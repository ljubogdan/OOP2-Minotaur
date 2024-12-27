/**
 * @file lavirint_utils.hpp
 * 
 * @brief Deklaracija funkcija za generisanje lavirinta, postavljanje robota, minotaura i predmeta
 * 
 * Funkcije za generisanje lavirinta, postavljanje robota, minotaura i predmeta
 * 
 * @version 1.0
 * @date 27.12.2024 19:18:00
 * @author Bogdan Ljubinković SV2/2023
 */

#ifndef LAVIRINT_UTILS_HPP
#define LAVIRINT_UTILS_HPP

#include "lavirint.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <chrono>
#include <random>
#include "robot.hpp"
#include "minotaur.hpp"

/**
 * @brief Klasa LavirintUtils
 * 
 * Klasa koja sadrži funkcije za generisanje lavirinta, postavljanje robota, minotaura i predmeta
 * Koristićemo je isključivo kao statičku klasu
 * 
 * @version 1.0
 * 
 * @see lavirint.hpp
 * @see element.hpp
 * @see robot.hpp
 * @see minotaur.hpp
 * @see predmeti.hpp
 * @see lavirint_utils.cpp
 */

class LavirintUtils {
    public:
        static void generisiLavirint(Lavirint& lavirint, int brojPredmeta);
        static void postaviRobota(Lavirint& lavirint);
        static void postaviMinotaura(Lavirint& lavirint);
        static void postaviPredmete(Lavirint& lavirint, int brojPredmeta);
};

/**
 * @class DisjunktniSkup
 * @brief Klasa koja implementira strukturu disjunktnih skupova (Union-Find) sa optimizacijama za brzo spajanje i pronalaženje.
 * 
 * Struktura disjunktnih skupova omogućava efikasno upravljanje grupama elemenata
 * koje se mogu spojiti ili proveravati na pripadnost istom skupu.
 * Koristi se, na primer, u algoritmima za generisanje lavirinata i grafova.
 * 
 * @version 1.0
 * 
 * @param roditelj vektor koji čuva roditelje svakog elementa
 * @param rang vektor koji čuva rang svakog elementa
 * 
 * @see lavirint_utils.hpp
 */

class DisjunktniSkup {
    private:
        std::vector<int> roditelj;
        std::vector<int> rang;
    public:
        DisjunktniSkup(int velicina);
        int pronadji(int x);
        bool spojiSkupove(int x, int y);
};

#endif // LAVIRINT_UTILS_HPP