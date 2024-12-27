/**
 * @file igra.cpp
 * @brief Implementacija metoda klase Igra
 * @version 1.0
 * 
 * Implementacija svih metoda klase Igra.
 * 
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024. 03:08:07 
 */

#include "igra.hpp"

/**
 * @brief Konstruktor klase Igra
 * 
 * Konstruktor klase Igra koji prima broj redova, broj kolona i broj predmeta.
 * 
 * @param brojRedova broj redova
 * @param brojKolona broj kolona
 * @param brojPredmeta broj predmeta
 * 
 * Postavlja vrednosti atributa klase Igra.
 * 
 * @return 
 * 
 * @example Igra igra(15, 15, 3);
 * 
 * @see Lavirint
 * @see Lavirint::Lavirint
 * @see Lavirint::~Lavirint
 * @see Lavirint::generisiLavirint
 * @see Lavirint::getMatrica
 * @see Lavirint::getBrojRedova
 * @see Lavirint::getBrojKolona
 * @see Element
 * @see Element::getSimbol
 * @see Element::setSimbol
 * @see Robot
 * @see Robot::Robot
 * @see Minotaur
 * @see Minotaur::Minotaur
 * @see Predmet
 * @see Predmet::getEfekat
 * @see Predmet::setEfekat
 * @see Igra::brojPredmeta
 * @see Igra::krajIgre
 * @see Igra::trajanjeEfekta
 * @see Igra::trenutniEfekat
 * @see Igra::robotX
 * @see Igra::robotY
 * @see Igra::minotaurX
 * @see Igra::minotaurY
 * @see Igra::robotPobedio
 * @see Igra::minotaurPobedio
 * @see Igra::minotaurZiv
 */

Igra::Igra(int brojRedova, int brojKolona, int brojPredmeta) 
    : brojPredmeta(brojPredmeta), krajIgre(false), trajanjeEfekta(0),
    lavirint(new Lavirint(brojRedova, brojKolona)), trenutniEfekat(""), 
    robotX(0), robotY(0), minotaurX(0), minotaurY(0),
    robotPobedio(false), minotaurPobedio(false), minotaurZiv(true) {
}

/**
 * @brief Destruktor klase Igra
 * 
 * Destruktor klase Igra koji oslobađa resurse.
 * 
 * @return 
 * 
 * @example Igra::~Igra();
 */

Igra::~Igra() {
    delete lavirint;
    lavirint = nullptr;
}

/**
 * @brief Metoda getLavirint
 * 
 * Metoda koja vraća vrednost atributa lavirint.
 * 
 * @return Lavirint*
 * 
 * @example Lavirint* lavirint = igra.getLavirint();
 */

Lavirint* Igra::getLavirint() const {
    return lavirint;
}

/**
 * @brief Metoda getBrojPredmeta
 * 
 * Metoda koja vraća vrednost atributa brojPredmeta.
 * 
 * @return int
 * 
 * @example int brojPredmeta = igra.getBrojPredmeta();
 */

int Igra::getBrojPredmeta() const {
    return brojPredmeta;
}

/**
 * @brief Metoda getKrajIgre
 * 
 * Metoda koja vraća vrednost atributa krajIgre.
 * 
 * @return bool
 * 
 * @example bool krajIgre = igra.getKrajIgre();
 */

bool Igra::getKrajIgre() const {
    return krajIgre;
}

/**
 * @brief Metoda getTrajanjeEfekta
 * 
 * Metoda koja vraća vrednost atributa trajanjeEfekta.
 * 
 * @return int
 * 
 * @example int trajanjeEfekta = igra.getTrajanjeEfekta();
 */

int Igra::getTrajanjeEfekta() const {
    return trajanjeEfekta;
}

/**
 * @brief Metoda setLavirint
 * 
 * Metoda koja postavlja vrednost atributa lavirint.
 * 
 * @param lavirint pokazivač na objekat klase Lavirint
 * 
 * @return 
 * 
 * @example igra.setLavirint(lavirint);
 */

void Igra::setLavirint(Lavirint* lavirint) {
    this->lavirint = lavirint;
}

/**
 * @brief Metoda setBrojPredmeta
 * 
 * Metoda koja postavlja vrednost atributa brojPredmeta.
 * 
 * @param brojPredmeta broj predmeta
 * 
 * @return 
 * 
 * @example igra.setBrojPredmeta(3);
 */

void Igra::setBrojPredmeta(int brojPredmeta) {
    this->brojPredmeta = brojPredmeta;
}

/**
 * @brief Metoda setKrajIgre
 * 
 * Metoda koja postavlja vrednost atributa krajIgre.
 * 
 * @param krajIgre indikator kraja igre
 * 
 * @return 
 * 
 * @example igra.setKrajIgre(true);
 */

void Igra::setKrajIgre(bool krajIgre) {
    this->krajIgre = krajIgre;
}

/**
 * @brief Metoda setTrajanjeEfekta
 * 
 * Metoda koja postavlja vrednost atributa trajanjeEfekta.
 * 
 * @param trajanjeEfekta trajanje efekta predmeta
 * 
 * @return 
 * 
 * @example igra.setTrajanjeEfekta(3);
 */

void Igra::setTrajanjeEfekta(int trajanjeEfekta) {
    this->trajanjeEfekta = trajanjeEfekta;
}

/**
 * @brief Metoda getTrenutniEfekat
 * 
 * Metoda koja vraća vrednost atributa trenutniEfekat.
 * 
 * @return std::string
 * 
 * @example std::string trenutniEfekat = igra.getTrenutniEfekat();
 */

std::string Igra::getTrenutniEfekat() const {
    return trenutniEfekat;
}

/**
 * @brief Metoda setTrenutniEfekat
 * 
 * Metoda koja postavlja vrednost atributa trenutniEfekat.
 * 
 * @param trenutniEfekat trenutni efekat predmeta
 * 
 * @return 
 * 
 * @example igra.setTrenutniEfekat("Magla rata");
 */

void Igra::setTrenutniEfekat(std::string trenutniEfekat) {
    this->trenutniEfekat = trenutniEfekat;
}

/**
 * @brief Metoda getRobotX
 * 
 * Metoda koja vraća vrednost atributa robotX.
 * 
 * @return int
 * 
 * @example int robotX = igra.getRobotX();
 */

int Igra::getRobotX() const {
    return robotX;
}

/**
 * @brief Metoda getRobotY
 * 
 * Metoda koja vraća vrednost atributa robotY.
 * 
 * @return int
 * 
 * @example int robotY = igra.getRobotY();
 */

int Igra::getRobotY() const {
    return robotY;
}

/**
 * @brief Metoda getMinotaurX
 * 
 * Metoda koja vraća vrednost atributa minotaurX.
 * 
 * @return int
 * 
 * @example int minotaurX = igra.getMinotaurX();
 */

int Igra::getMinotaurX() const {
    return minotaurX;
}

/**
 * @brief Metoda getMinotaurY
 * 
 * Metoda koja vraća vrednost atributa minotaurY.
 * 
 * @return int
 * 
 * @example int minotaurY = igra.getMinotaurY();
 */

int Igra::getMinotaurY() const {
    return minotaurY;
}

/**
 * @brief Metoda setRobotX
 * 
 * Metoda koja postavlja vrednost atributa robotX.
 * 
 * @param robotX x koordinata robota
 * 
 * @return 
 * 
 * @example igra.setRobotX(1);
 */

void Igra::setRobotX(int robotX) {
    this->robotX = robotX;
}

/**
 * @brief Metoda setRobotY
 * 
 * Metoda koja postavlja vrednost atributa robotY.
 * 
 * @param robotY y koordinata robota
 * 
 * @return 
 * 
 * @example igra.setRobotY(1);
 */

void Igra::setRobotY(int robotY) {
    this->robotY = robotY;
}

/**
 * @brief Metoda setMinotaurX
 * 
 * Metoda koja postavlja vrednost atributa minotaurX.
 * 
 * @param minotaurX x koordinata minotaura
 * 
 * @return 
 * 
 * @example igra.setMinotaurX(1);
 */

void Igra::setMinotaurX(int minotaurX) {
    this->minotaurX = minotaurX;
}

/**
 * @brief Metoda setMinotaurY
 * 
 * Metoda koja postavlja vrednost atributa minotaurY.
 * 
 * @param minotaurY y koordinata minotaura
 * 
 * @return 
 * 
 * @example igra.setMinotaurY(1);
 */

void Igra::setMinotaurY(int minotaurY) {
    this->minotaurY = minotaurY;
}

/**
 * @brief Metoda getRobotPobedio
 * 
 * Metoda koja vraća vrednost atributa robotPobedio.
 * 
 * @return bool
 * 
 * @example bool robotPobedio = igra.getRobotPobedio();
 */

bool Igra::getRobotPobedio() const {
    return robotPobedio;
}

/**
 * @brief Metoda getMinotaurPobedio
 * 
 * Metoda koja vraća vrednost atributa minotaurPobedio.
 * 
 * @return bool
 * 
 * @example bool minotaurPobedio = igra.getMinotaurPobedio();
 */

bool Igra::getMinotaurPobedio() const {
    return minotaurPobedio;
}

/**
 * @brief Metoda setRobotPobedio
 * 
 * Metoda koja postavlja vrednost atributa robotPobedio.
 * 
 * @param robotPobedio indikator pobede robota
 * 
 * @return 
 * 
 * @example igra.setRobotPobedio(true);
 */

void Igra::setRobotPobedio(bool robotPobedio) {
    this->robotPobedio = robotPobedio;
}

/**
 * @brief Metoda setMinotaurPobedio
 * 
 * Metoda koja postavlja vrednost atributa minotaurPobedio.
 * 
 * @param minotaurPobedio indikator pobede minotaura
 * 
 * @return 
 * 
 * @example igra.setMinotaurPobedio(true);
 */

void Igra::setMinotaurPobedio(bool minotaurPobedio) {
    this->minotaurPobedio = minotaurPobedio;
}

/**
 * @brief Metoda getMinotaurZiv
 * 
 * Metoda koja vraća vrednost atributa minotaurZiv.
 * 
 * @return bool
 * 
 * @example bool minotaurZiv = igra.getMinotaurZiv();
 */

bool Igra::getMinotaurZiv() const {
    return minotaurZiv;
}

/**
 * @brief Metoda setMinotaurZiv
 * 
 * Metoda koja postavlja vrednost atributa minotaurZiv.
 * 
 * @param minotaurStatus indikator života minotaura
 * 
 * @return 
 * 
 * @example igra.setMinotaurZiv(true);
 */

void Igra::setMinotaurZiv(bool minotaurStatus) {
    minotaurZiv = minotaurStatus;
}

/**
 * @brief Metoda prikaziLavirint
 * 
 * Metoda koja prikazuje lavirint.
 * Prolazimo kroz matricu lavirinta i u zavisnosti od simbola elementa ispisujemo odgovarajuću boju.
 * Pravimo razliku između robota, minotaura, predmeta i prepreka.
 * 
 * @return
 * 
 * @example igra.prikaziLavirint();
 */

void Igra::prikaziLavirint() {
    Element*** matrica = lavirint->getMatrica();
    for (int i = 0; i < lavirint->getBrojRedova(); i++) {
        std::cout << "    ";
        for (int j = 0; j < lavirint->getBrojKolona(); j++) {
            if (matrica[i][j]->getSimbol() == 'R') {
                std::cout << BOLDDARKBLUE << matrica[i][j]->getSimbol() << RESET;
            } else if (matrica[i][j]->getSimbol() == 'M') {
                std::cout << BOLDRED << matrica[i][j]->getSimbol() << RESET;
            } else if (matrica[i][j]->getSimbol() == 'U' || matrica[i][j]->getSimbol() == 'I') {
                std::cout << BOLDGREEN << matrica[i][j]->getSimbol() << RESET;
            } else if (matrica[i][j]->getSimbol() == 'P') {
                std::cout << BOLDPINK << matrica[i][j]->getSimbol() << RESET;
            } else {
                std::cout << matrica[i][j]->getSimbol();
            }
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Metoda prikaziLavirintZamagljen
 * 
 * Metoda koja prikazuje lavirint sa zamagljenim delom oko robota.
 * Vidljiva je samo matrica 3x3 oko robota.
 * Metoda se poziva kada je aktiviran efekat "Magla rata".
 * Ostatak lavirinta je sive boje i simbolizuje maglu.
 * 
 * @return
 * 
 * @example igra.prikaziLavirintZamagljen();
 */

void Igra::prikaziLavirintZamagljen() {
    char simbol = 'X';
    Element*** matrica = lavirint->getMatrica();
    for (int i = 0; i < lavirint->getBrojRedova(); i++) {
        std::cout << "    ";
        for (int j = 0; j < lavirint->getBrojKolona(); j++) {
            if (i >= robotX - 1 && i <= robotX + 1 && j >= robotY - 1 && j <= robotY + 1) {
                if (matrica[i][j]->getSimbol() == 'R') {
                    std::cout << BOLDDARKBLUE << matrica[i][j]->getSimbol() << RESET;
                } else if (matrica[i][j]->getSimbol() == 'M') {
                    std::cout << BOLDRED << matrica[i][j]->getSimbol() << RESET;
                } else if (matrica[i][j]->getSimbol() == 'U' || matrica[i][j]->getSimbol() == 'I') {
                    std::cout << BOLDGREEN << matrica[i][j]->getSimbol() << RESET;
                } else if (matrica[i][j]->getSimbol() == 'P') {
                    std::cout << BOLDPINK << matrica[i][j]->getSimbol() << RESET;
                } else {
                    std::cout << matrica[i][j]->getSimbol();
                }
            } else {
                std::cout << "\033[2m\033[37m" << simbol << "\033[0m";
            }
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Metoda getKarakter
 * 
 * Ova funkcija postavlja terminal u "raw" ili "nekanonski" režim, što znači da se karakteri neće čekati na Enter.
 * Nakon očitavanja karaktera vraća se u normalni režim.
 * 
 * @details
 * Funkcija koristi "termios" strukturu za modifikaciju parametara terminala.
 * Onemogućava kanonski režim i echo da bi se omogućio direktan pristum unetim parametrima.
 * 
 * @return char
 * 
 * @note Funkcija može da ispiše grešku ukoliko dođe do problema sa terminalom.
 * 
 * @example char komanda = getKarakter();
 * 
 * @see termios
 * @see tcgetattr
 * @see tcsetattr
 * @see read
 */

char getKarakter() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
}

/**
 * @brief Metoda pokreni Igru
 * 
 * Metoda koja pokreće igru i gde se nalazi glavna logika igre.
 * 
 * @details
 * Prvo se generiše lavirint sa određenim brojem predmeta.
 * Zatim se prolazi kroz matricu lavirinta i postavljaju se koordinate robota i minotaura.
 * Igra počinje nakon 3 sekunde.
 * 
 * @details
 * U beskonačnoj petlji se prikazuje lavirint.
 * Ukoliko je aktiviran efekat "Magla rata", prikazuje se zamagljen deo oko robota.
 * U suprotnom, prikazuje se ceo lavirint.
 * 
 * @details
 * Ukoliko je aktiviran efekat, ispisuje se poruka o trajanju efekta.
 * 
 * @details
 * Ukoliko je pritisnuta komanda "q" ili "Q", igra se prekida.
 * 
 * @details
 * Ukoliko je pritisnuta komanda "w" ili "W", robot se pomeri na gore.
 * Ukoliko je pritisnuta komanda "s" ili "S", robot se pomeri na dole.
 * Ukoliko je pritisnuta komanda "a" ili "A", robot se pomeri na levo.
 * Ukoliko je pritisnuta komanda "d" ili "D", robot se pomeri na desno.
 * 
 * @details
 * Ukoliko je pritisnuta nepoznata komanda, ispisuje se poruka o grešci.
 * 
 * @details
 * Ukoliko je robot pobedio, ispisuje se poruka o pobedi robota.
 * Ukoliko je minotaur pobedio, ispisuje se poruka o pobedi minotaura.
 * Ukoliko je igra prekinuta, ispisuje se poruka o kraju igre.
 * 
 * @details
 * Nakon svakog poteza robota, minotaur odigra svoj potez.
 * 
 * @note Biće objašnjeno naknadno u izveštaju.
 * 
 * @return
 * 
 * @example igra.pokreniIgru();
 */

void Igra::pokreniIgru() {
    lavirint->generisiLavirint(brojPredmeta);

    Element*** matrica = lavirint->getMatrica();
    for (int i = 0; i < lavirint->getBrojRedova(); i++) {
        for (int j = 0; j < lavirint->getBrojKolona(); j++) {
            if (matrica[i][j]->getSimbol() == 'R') {
                setRobotX(i);
                setRobotY(j);
            } else if (matrica[i][j]->getSimbol() == 'M') {
                setMinotaurX(i);
                setMinotaurY(j);
            }
        }
    }

    int brojac = 3;
    while (brojac > 0) {
        std::cout << "\r" << BOLDDARKBLUE << "Igra počinje za " << BOLDGREEN << brojac << RESET << " " << std::flush;
        brojac--;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    system("clear"); // ili system("cls") za Windows

    while (true) {
        if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Magla rata") {
            prikaziLavirintZamagljen();
        } else {
            prikaziLavirint();
        }
        if (getTrajanjeEfekta() > 0) {
            std::cout << BOLDPINK << "\nEfekat " << getTrenutniEfekat() << " traje još " << getTrajanjeEfekta() << " runde" << RESET << std::endl;
        }

        int stanje = 0;
        char komanda = getKarakter();
        if (komanda == 'q' || komanda == 'Q') {
            setKrajIgre(true);
            porukaKrajIgre();
            break;
        } else if (komanda == 'w' || komanda == 'W') {
            pomeriRobota(getRobotX() - 1, getRobotY());
            stanje = procenaStanja();
            if (stanje == 1) {
                porukaRobotPobedio();
                break;
            } else if (stanje == 2) {
                porukaMinotaurPobedio();
                break;
            } else if (stanje == 3) {
                porukaKrajIgre();
                break;
            }
        } else if (komanda == 's' || komanda == 'S') {
            pomeriRobota(getRobotX() + 1, getRobotY());
            stanje = procenaStanja();
            if (stanje == 1) {
                porukaRobotPobedio();
                break;
            } else if (stanje == 2) {
                porukaMinotaurPobedio();
                break;
            } else if (stanje == 3) {
                porukaKrajIgre();
                break;
            }
        } else if (komanda == 'a' || komanda == 'A') {
            pomeriRobota(getRobotX(), getRobotY() - 1);
            stanje = procenaStanja();
            if (stanje == 1) {
                porukaRobotPobedio();
                break;
            } else if (stanje == 2) {
                porukaMinotaurPobedio();
                break;
            } else if (stanje == 3) {
                porukaKrajIgre();
                break;
            }
        } else if (komanda == 'd' || komanda == 'D') {
            pomeriRobota(getRobotX(), getRobotY() + 1);
            stanje = procenaStanja();
            if (stanje == 1) {
                porukaRobotPobedio();
                break;
            } else if (stanje == 2) {
                porukaMinotaurPobedio();
                break;
            } else if (stanje == 3) {
                porukaKrajIgre();
                break;
            }
        } else {
            std::cout << BOLDPINK << "\nNepoznata komanda!" << RESET << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            system("clear"); // ili system("cls") za Windows
            continue;
        }

        system("clear"); // ili system("cls") za Windows
        if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Magla rata") {
            prikaziLavirintZamagljen();
        } else {
            prikaziLavirint();
        }
        if (getTrajanjeEfekta() > 0) {
            std::cout << BOLDPINK << "\nEfekat " << getTrenutniEfekat() << " traje još " << getTrajanjeEfekta() << " runde" << RESET << std::endl;
        }        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        pomeriMinotauraRandom();
        system("clear"); // ili system("cls") za Windows
        if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Magla rata") {
            prikaziLavirintZamagljen();
        } else {
            prikaziLavirint();
        }
        if (getTrajanjeEfekta() > 0) {
            std::cout << BOLDPINK << "\nEfekat " << getTrenutniEfekat() << " traje još " << getTrajanjeEfekta() << " runde" << RESET << std::endl;
        }

        stanje = procenaStanja();
        if (stanje == 1) {
            porukaRobotPobedio();
            break;
        } else if (stanje == 2) {
            porukaMinotaurPobedio();
            break;
        } else if (stanje == 3) {
            porukaKrajIgre();
            break;
        }

        setTrajanjeEfekta(getTrajanjeEfekta() - 1);

        system("clear"); // ili system("cls") za Windows
    }

    UpisStanja::upisiUFajl(*lavirint, procenaStanja());
}

/**
 * @brief Metoda zavrsiIgru
 * 
 * Metoda koja završava igru.
 * 
 * @details
 * Uništava se objekat klase Lavirint koji je dinamički alociran.
 * Postavlja se pokazivač na nullptr.
 * 
 * @return
 * 
 * @example igra.zavrsiIgru();
 */

void Igra::zavrsiIgru() {
    delete lavirint;
    lavirint = nullptr;
}

/**
 * @brief Metoda procena Stanja
 * 
 * Metoda koja procenjuje trenutno stanje igre.
 * 
 * @details
 * Ukoliko je robot pobedio, vraća se 1.
 * Ukoliko je minotaur pobedio, vraća se 2.
 * Ukoliko je igra prekinuta, vraća se 3.
 * U suprotnom, vraća se 0.
 * 
 * @return int
 * 
 * @example int stanje = igra.procenaStanja();
 */

int Igra::procenaStanja() {
    if (getRobotPobedio() == true) {
        return 1;
    } else if (getMinotaurPobedio() == true) {
        return 2;
    } else if (getKrajIgre() == true) {
        return 3;
    } else {
        return 0;
    }
}

/**
 * @brief Metoda porukaRobotPobedio
 * 
 * Metoda koja ispisuje poruku o pobedi robota.
 * 
 * @note Uvek se osvežava terminal pre ispisivanja poruke.
 * 
 * @return
 * 
 * @example igra.porukaRobotPobedio();
 */

void Igra::porukaRobotPobedio() {
    system("clear"); // ili system("cls") za Windows
    prikaziLavirint();
    std::cout << BOLDGREEN << "\nRobot je pobedio!" << RESET << std::endl;
}

/**
 * @brief Metoda porukaMinotaurPobedio
 * 
 * Metoda koja ispisuje poruku o pobedi minotaura.
 * 
 * @note Uvek se osvežava terminal pre ispisivanja poruke.
 * 
 * @return
 * 
 * @example igra.porukaMinotaurPobedio();
 */

void Igra::porukaMinotaurPobedio() {
    system("clear"); // ili system("cls") za Windows
    prikaziLavirint();
    std::cout << BOLDRED << "\nMinotaur je pobedio!" << RESET << std::endl;
}

/**
 * @brief Metoda porukaKrajIgre
 * 
 * Metoda koja ispisuje poruku o kraju igre.
 * Specijalna metoda koja se koristi kada je igra prekinuta.
 * 
 * @note Uvek se osvežava terminal pre ispisivanja poruke.
 * 
 * @return
 * 
 * @example igra.porukaKrajIgre();
 */

void Igra::porukaKrajIgre() {
    system("clear"); // ili system("cls") za Windows
    prikaziLavirint();
    std::cout << BOLDPINK << "\nIgra je prekinuta! (Q)" << RESET << std::endl;
}

/**
 * @brief Metoda pomeri Robota
 * 
 * Metoda koja pomeri robota na određenu poziciju.
 * 
 * @details
 * 
 * @param x x koordinata na koju se pomera robot
 * @param y y koordinata na koju se pomera robot
 * 
 * @return
 * 
 * @details
 * Ukoliko je simbol na poziciji (x, y) jednak "I", robot je pobedio.
 * Ukoliko je simbol na poziciji (x, y) jednak "#", proverava se da li je aktiviran efekat "Čekić".
 * Ukoliko je simbol na poziciji (x, y) jednak "U", robot se ne može pomeriti.
 * Ukoliko je simbol na poziciji (x, y) jednak "M", proverava se da li je aktiviran efekat "Mač" ili "Štit".
 * Ukoliko je simbol na poziciji (x, y) jednak "P", postavlja se trajanje efekta i trenutni efekat.
 * Ukoliko je simbol na poziciji (x, y) jednak " ", robot se pomeri na tu poziciju.
 * 
 * @details
 * Ukoliko je simbol na poziciji (x, y) jednak "M" i robot ima aktiviran efekat "Mač", minotaur je mrtav.
 * Ukoliko je simbol na poziciji (x, y) jednak "M" i robot ima aktiviran efekat "Štit", robot se ne može pomeriti.
 * Ukoliko je simbol na poziciji (x, y) jednak "M" i robot nema aktiviran efekat, minotaur je pobedio.
 * 
 * @details
 * Rad sa pointerima:
 * 1. Briše se element na trenutnoj poziciji robota.
 * 2. Postavljaju se nove koordinate robota.
 * 3. Postavlja se novi element na novu poziciju robota (robot).
 * 
 * @note Čekić ne može biti aktiviran na ivicama lavirinta.
 * 
 * @example igra.pomeriRobota(1, 1); 
 */

void Igra::pomeriRobota(int x, int y) {
    if (lavirint->getElement(x, y).getSimbol() == 'I') {
        setRobotPobedio(true);
        setKrajIgre(true);
        Element* element = new Element(' ');
        lavirint->setElement(getRobotX(), getRobotY(), element);
        setRobotX(x);
        setRobotY(y);
        return;
    } else if (lavirint->getElement(x, y).getSimbol() == '#') {
        if (getTrajanjeEfekta() == 0) {
            return;
        } else if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() != "Čekić") {
            return;
        } else if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Čekić") {
            if (x == 0 || x == lavirint->getBrojRedova() - 1 || y == 0 || y == lavirint->getBrojKolona() - 1) {
                return;
            } else {
                Element* element = new Element(' ');
                lavirint->setElement(getRobotX(), getRobotY(), element);
                setRobotX(x);
                setRobotY(y);
                Robot* robot = new Robot('R');
                lavirint->setElement(x, y, robot);
                return;
            }
        }
    } else if (lavirint->getElement(x, y).getSimbol() == 'U') {
        return;
    } else if (lavirint->getElement(x, y).getSimbol() == 'M') {
        if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Mač") {
            setMinotaurZiv(false);
            Element* element = new Element(' ');
            lavirint->setElement(getRobotX(), getRobotY(), element);
            setRobotX(x);
            setRobotY(y);
            Robot* robot = new Robot('R');
            lavirint->setElement(x, y, robot);
            return;
        } else if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Štit") {
            return;
        } else {
            setRobotPobedio(false);
            setMinotaurPobedio(true);
            setKrajIgre(true);
            Element* element = new Element(' ');
            lavirint->setElement(getRobotX(), getRobotY(), element);
            setRobotX(x);
            setRobotY(y);
            return;
        }
    } else if (lavirint->getElement(x, y).getSimbol() == 'P') {
        setTrajanjeEfekta(3);
        Predmet* predmet = dynamic_cast<Predmet*>(lavirint->getMatrica()[x][y]);
        setTrenutniEfekat(predmet->getEfekat());
        Element* element = new Element(' ');
        lavirint->setElement(getRobotX(), getRobotY(), element);
        setRobotX(x);
        setRobotY(y);
        Robot* robot = new Robot('R');
        lavirint->setElement(x, y, robot);
        return;
    } else if (lavirint->getElement(x, y).getSimbol() == ' ') {
        Element* element = new Element(' ');
        lavirint->setElement(getRobotX(), getRobotY(), element);
        setRobotX(x);
        setRobotY(y);
        Robot* robot = new Robot('R');
        lavirint->setElement(x, y, robot);
        return;
    }
}

/**
 * @brief Metoda pomeri Minotaura Random
 * 
 * Metoda koja pomeri minotaura na nasumičnu poziciju.
 * 
 * @details
 * Prvo se proverava da li je minotaur živ.
 * Zatim se generiše niz brojeva od 1 do 4.
 * Niz se meša kako bi se dobio nasumičan redosled pomoću funkcije std::shuffle koja koristi std::default_random_engine.
 * Seed se generiše pomoću std::chrono::system_clock::now().time_since_epoch().count(). tako da se svaki put dobije različit redosled.
 * 
 * @details
 * Prvo se proverava da li je robot u blizini minotaura.
 * Ukoliko je aktiviran efekat "Mač", minotaur je mrtav.
 * Ukoliko je aktiviran efekat "Štit", minotaur se ne može pomeriti.
 * Ukoliko je minotaur u blizini robota, a robot nema aktiviran efekat ili je aktiviran efekat "Čekić", minotaur je pobedio.
 * 
 * @details
 * Ukoliko minotaur stane na predmet, uništava se predmet.
 * 
 * @details
 * Ukoliko je simbol na poziciji (x, y) jednak " ", minotaur se pomeri na tu poziciju, bez posledica.
 * 
 * @note Prolazimo kroz niz i proveravamo svaki element, jer mora biti moguć barem jedan potez.
 * 
 * @return
 * 
 * @example igra.pomeriMinotauraRandom();
 * 
 * @see std::shuffle
 * @see std::default_random_engine
 * @see std::chrono::system_clock::now().time_since_epoch().count()
 * @see std::begin
 * @see std::end
 */

void Igra::pomeriMinotauraRandom() {
    if (getMinotaurZiv() == false) {
        return;
    }

    int x = getMinotaurX();
    int y = getMinotaurY();

    int niz[] = {1, 2, 3, 4};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(niz), std::end(niz), std::default_random_engine(seed));

    if (lavirint->getElement(x-1, y).getSimbol() == 'R' || lavirint->getElement(x+1, y).getSimbol() == 'R' || 
        lavirint->getElement(x, y-1).getSimbol() == 'R' || lavirint->getElement(x, y+1).getSimbol() == 'R') {
            if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Mač") {
                setMinotaurZiv(false);
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                return;
            } else if (getTrajanjeEfekta() > 0 && getTrenutniEfekat() == "Štit") {
                return;
            } else {
                setRobotPobedio(false);
                setMinotaurPobedio(true);
                setKrajIgre(true);
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getRobotX(), getRobotY(), minotaur);
                return;
            }
    }

    for (int i = 0; i < 4; i++) {
        if (niz[i] == 1) {
            if (lavirint->getElement(x-1, y).getSimbol() == ' ') {
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurX(x-1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            } else if (lavirint->getElement(x-1, y).getSimbol() == 'P') {
                // uništava predmet
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurX(x-1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            }

        } else if (niz[i] == 2) {
            if (lavirint->getElement(x+1, y).getSimbol() == ' ') {
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurX(x+1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            } else if (lavirint->getElement(x+1, y).getSimbol() == 'P') {
                // uništava predmet
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurX(x+1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            }
        } else if (niz[i] == 3) {
            if (lavirint->getElement(x, y-1).getSimbol() == ' ') {
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurY(y-1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            } else if (lavirint->getElement(x, y-1).getSimbol() == 'P') {
                // uništava predmet
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurY(y-1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            }
        } else if (niz[i] == 4) {
            if (lavirint->getElement(x, y+1).getSimbol() == ' ') {
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurY(y+1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            } else if (lavirint->getElement(x, y+1).getSimbol() == 'P') {
                // uništava predmet
                Element* element = new Element(' ');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), element);
                setMinotaurY(y+1);
                Minotaur* minotaur = new Minotaur('M');
                lavirint->setElement(getMinotaurX(), getMinotaurY(), minotaur);
                return;
            }
        }
    }
}
