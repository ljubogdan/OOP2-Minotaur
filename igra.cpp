/*    • На почетку програма потребно је кроз аргументе командне линије задати димензију лавиринта и број предмета са специјалним ефектима. Лавиринт је произвољна матрица где број колона и број редова морају бити веће од 15 (нпр. 20x20, 17x25, 30x20), а број предмета мора бити већи од 3.
    • На основу димензије потребно је генерисати поставку на следећи начин:
        ◦ ‘#’ - зидови
            ▪ спољашњи зидови морају попунити димензије матрице
            ▪ блокове унутрашњих зидова треба насумично распоредити, где је број блокова двострука вредност димензије лавиринта, а једини услов је да буду постављени тако да је пролаз могућ
        ◦ ‘U’ - улаз насумично распоређен на првом реду лавиринта
        ◦ ‘R’ – робот распоређен на поље које је тачно један ред испод улаза
        ◦ ‘I’ – излаз насумично распоређен на последњем реду лавиринта
        ◦ ‘.’ - пролаз представљен једним карактером размака, насумично распоређен тако да омогући кретање
        ◦ ‘M’ - Минотаур, насумично распоређен са јединим условом да буде могућ пролазак поред њега
        ◦ ‘P’ - предмет који нуди одређени ефекат (укупан број предмета је задат аругментом командне линије)
    • Затим, следи интерактивни део игре:
        ◦ Кретање робота
            ▪ корисник уносом са тастатуре врши кретање робота (горе, доле, лево и десно)
            ▪ команде за кретање су произвољне (могу бити стрелице или по жељи дефинисани карактери)
            ▪ Робот не може да прође кроз зид
        ◦ Кретање минотаура:
            ▪ насумично померање за једно поље (лево, десно, горе или доле)
            ▪ уколико се робот нађе на једно поље од Минотаура, Минотаур неће играти насумично већ ће појести робота
            ▪ Минотаур не може да прође кроз зид
            ▪ уколико стане на поље на ком је предмет, Минотаур тај предмет уништава
        ◦ Предмети и њихови специјални ефекти:
            ▪ Специјални ефекти сваког предмета трају 3 потеза
            ▪ Када робот стане на предмет, насумично се генерише ефекат који предмет доноси
            ▪ ‘Магла рата’ - смањује кориснику видљивост на подматрицу димензије 3x3
            ▪ ‘Мач’ - овим предметом је могуће уништити Минотаура
            ▪ ‘Штит’ - могућност одбране од Минотаура
            ▪ ‘Чекић’ - омогућава пролазак кроз зид

Пример генерисаног лавиринта дименција 51x31.

Функционални захтеви
Написати Це++ програм који омогућује следеће:
Учитавање димензије лавиринта и броја предмета као аргумената командне линије
Динамичко креирање лавиринта са свим задатим елементима
Алгоритам који прави поставку лавиринта на основу задатих димензија имплементирати у засебној библитеци
Мерење времена потребног за генерисање табеле лавиринта
Интеракција кроз конзолу 
Сва правила игре омогућена и испоштована
Коришћење наслеђивања приликом прављења предмета и њихових специјалних ефеката
На крају игре изгенерисати датотеку у којој ће бити приказан исход и слика лавиринта након последњег потеза. Крај игре подразумева:
команду са тастатуре (слово ‘Q’) за гашење програма
Долазак робота на финиш
Минотаур је уништио робота
Тестирање кода у слободној форми (сви случаји са којима је тестирано решење морају бити наведени у документацији)
Ток игре и руковање датотекама треба имплементирати као одвојене класе*/

#include "igra.hpp"

Igra::Igra(int brojRedova, int brojKolona, int brojPredmeta) 
    : brojPredmeta(brojPredmeta), krajIgre(false), trajanjeEfekta(0),
    lavirint(new Lavirint(brojRedova, brojKolona)), trenutniEfekat(""), 
    robotX(0), robotY(0), minotaurX(0), minotaurY(0),
    robotPobedio(false), minotaurPobedio(false), minotaurZiv(true) {
}

Igra::~Igra() {
    delete lavirint;
}

Lavirint* Igra::getLavirint() const {
    return lavirint;
}

int Igra::getBrojPredmeta() const {
    return brojPredmeta;
}

bool Igra::getKrajIgre() const {
    return krajIgre;
}

int Igra::getTrajanjeEfekta() const {
    return trajanjeEfekta;
}

void Igra::setLavirint(Lavirint* lavirint) {
    this->lavirint = lavirint;
}

void Igra::setBrojPredmeta(int brojPredmeta) {
    this->brojPredmeta = brojPredmeta;
}

void Igra::setKrajIgre(bool krajIgre) {
    this->krajIgre = krajIgre;
}

void Igra::setTrajanjeEfekta(int trajanjeEfekta) {
    this->trajanjeEfekta = trajanjeEfekta;
}

std::string Igra::getTrenutniEfekat() const {
    return trenutniEfekat;
}

void Igra::setTrenutniEfekat(std::string trenutniEfekat) {
    this->trenutniEfekat = trenutniEfekat;
}

int Igra::getRobotX() const {
    return robotX;
}

int Igra::getRobotY() const {
    return robotY;
}

int Igra::getMinotaurX() const {
    return minotaurX;
}

int Igra::getMinotaurY() const {
    return minotaurY;
}

void Igra::setRobotX(int robotX) {
    this->robotX = robotX;
}

void Igra::setRobotY(int robotY) {
    this->robotY = robotY;
}

void Igra::setMinotaurX(int minotaurX) {
    this->minotaurX = minotaurX;
}

void Igra::setMinotaurY(int minotaurY) {
    this->minotaurY = minotaurY;
}

bool Igra::getRobotPobedio() const {
    return robotPobedio;
}

bool Igra::getMinotaurPobedio() const {
    return minotaurPobedio;
}

void Igra::setRobotPobedio(bool robotPobedio) {
    this->robotPobedio = robotPobedio;
}

void Igra::setMinotaurPobedio(bool minotaurPobedio) {
    this->minotaurPobedio = minotaurPobedio;
}

bool Igra::getMinotaurZiv() const {
    return minotaurZiv;
}

void Igra::setMinotaurZiv(bool minotaurStatus) {
    minotaurZiv = minotaurStatus;
}

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
        prikaziLavirint();

        char komanda = getKarakter();
        if (komanda == 'q' || komanda == 'Q') {
            setKrajIgre(true);
            break;
        } else if (komanda == 'w' || komanda == 'W') {
            pomeriRobota(getRobotX() - 1, getRobotY());
        } else if (komanda == 's' || komanda == 'S') {
            pomeriRobota(getRobotX() + 1, getRobotY());
        } else if (komanda == 'a' || komanda == 'A') {
            pomeriRobota(getRobotX(), getRobotY() - 1);
        } else if (komanda == 'd' || komanda == 'D') {
            pomeriRobota(getRobotX(), getRobotY() + 1);
        } else {
            std::cout << "Nepoznata komanda!" << std::endl;
        }
    }

}

void Igra::zavrsiIgru() {
    std::cout << "Igra zavrsena!" << std::endl;
}

void Igra::pomeriRobota(int x, int y) {
    if (lavirint->getElement(x, y).getSimbol() == 'I') {
        return;
    }
    setRobotPobedio(true);
    setKrajIgre(true);
    Element* element = new Element(' ');
    lavirint->setElement(getRobotX(), getRobotY(), element);
    setRobotX(x);
    setRobotY(y);
    Robot* robot = new Robot('R');
    lavirint->setElement(x, y, robot);
}
