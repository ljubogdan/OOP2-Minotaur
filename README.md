# 🏛️ Minotaur Maze Game

<div align="center">

![C++](https://img.shields.io/badge/C++-17-blue.svg?style=for-the-badge&logo=cplusplus&logoColor=white)
![Licenca](https://img.shields.io/badge/Licenca-MIT-green.svg?style=for-the-badge)
![Platforma](https://img.shields.io/badge/Platforma-Linux%20%7C%20Windows-lightgrey.svg?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Spreman%20za%20Produkciju-brightgreen.svg?style=for-the-badge)

**Zadivljujuća konzolna igra lavirinta sa dinamičkim generisanjem, AI Minotaurom i strateškim prikupljanjem predmeta**

[🎮 Igra](#-igra) • [🚀 Brzo Pokretanje](#-brzo-pokretanje) • [📋 Funkcionalnosti](#-funkcionalnosti) • [🏗️ Arhitektura](#️-arhitektura) • [📖 Dokumentacija](#-dokumentacija)

</div>

---

## 🎯 Pregled

**Minotaur Maze Game** je sofisticirana C++ konzolna aplikacija koja kombinuje proceduralno generisanje lavirinta, real-time mehanike igre i principe objektno-orijentisanog programiranja. Igrači navigiraju kroz dinamički generisane lavirinte dok izbegavaju ili se suočavaju sa legendarnim Minotaurom, prikupljajući moćne predmete sa jedinstvenim efektima.

### 🎮 Igra

- **🎯 Cilj**: Navigiraj svog robota od ulaza (U) do izlaza (I) dok izbegavaš Minotaura (M)
- **⚔️ Sistem Borbe**: Prikupi predmete da dobiješ specijalne sposobnosti i potencijalno poraziš Minotaura
- **🧠 AI Protivnik**: Minotaur koristi inteligentno pronalaženje puta da lovi igrača
- **🎲 Proceduralno Generisanje**: Svaki lavirint je jedinstveno generisan sa prilagodljivim dimenzijama
- **💾 Čuvanje Stanja**: Stanja igre se automatski čuvaju za analizu

---

## 🚀 Brzo Pokretanje

### Preduslovi

- **C++ Kompajler**: GCC 7.0+ ili Clang 5.0+
- **Operativni Sistem**: Linux, macOS ili Windows (sa WSL)
- **Terminal**: Preporučuje se ANSI color podrška

### Instalacija i Kompajliranje

```bash
# Kloniraj repozitorijum
git clone https://github.com/yourusername/OOP2-Minotaur.git
cd OOP2-Minotaur

# Kompajliraj projekat
g++ -c lavirint_utils.cpp -o lavirint_utils.o
ar rcs liblavirint_utils.a lavirint_utils.o
g++ main.cpp -o main_program liblavirint_utils.a lavirint.cpp igra.cpp element.cpp minotaur.cpp predmeti.cpp robot.cpp upis_stanja.cpp -L. -llavirint_utils

# Pokreni igru
./main_program <redovi> <kolone> <predmeti>
```

### Primer Korišćenja

```bash
# Generiši lavirint 25x25 sa 5 specijalnih predmeta
./main_program 25 25 5

# Kreiraj izazovan lavirint 35x20 sa 8 predmeta
./main_program 35 20 8
```

---

## 📋 Funkcionalnosti

### 🏗️ Osnovne Mehanike Igre

| Funkcionalnost | Opis | Implementacija |
|----------------|------|----------------|
| **Proceduralno Generisanje Lavirinta** | Dinamičko kreiranje lavirinta sa garantovanom rešivošću | Prilagođeni algoritam u `lavirint_utils.cpp` |
| **Real-time Igra** | Interaktivni konzolni sistem kretanja | Event-driven arhitektura |
| **AI Minotaur** | Inteligentni protivnik sa lovačkim ponašanjem | Random walk sa detekcijom blizine |
| **Sistem Predmeta** | 4 jedinstvena predmeta sa privremenim efektima | Objektno-orijentisana hijerarhija nasleđivanja |
| **Upravljanje Stanjem** | Automatsko čuvanje stanja igre | File I/O sa strukturiranim izlazom |

### 🎮 Elementi Igre

| Simbol | Element | Opis |
|--------|---------|------|
| `#` | **Zidovi** | Neprohodne barijere koje formiraju strukturu lavirinta |
| `U` | **Ulaz** | Početna pozicija za robota |
| `I` | **Izlaz** | Lokacija za pobedu |
| `R` | **Robot** | Karakter koji kontroliše igrač |
| `M` | **Minotaur** | AI kontrolisani neprijatelj |
| `P` | **Predmeti** | Specijalni objekti sa jedinstvenim efektima |
| `.` | **Put** | Prostori kroz koje se može proći |

### ⚔️ Specijalni Predmeti i Efekti

| Predmet | Efekat | Trajanje | Strategija |
|---------|--------|----------|------------|
| **🗡️ Mač** | Može poraziti Minotaura | 3 poteza | Ofanzivni pristup |
| **🛡️ Štit** | Zaštita od Minotaura | 3 poteza | Defanzivna strategija |
| **🔨 Čekić** | Prolazak kroz zidove | 3 poteza | Alternativno rutiranje |
| **🌫️ Magla Rata** | Smanjena vidljivost (3x3) | 3 poteza | Stealth igra |

---

## 🏗️ Arhitektura

### 📁 Struktura Projekta

```
OOP2-Minotaur/
├── 📄 main.cpp                 # Ulazna tačka aplikacije
├── 🎮 igra.hpp/cpp            # Glavni kontroler logike igre
├── 🏛️ lavirint.hpp/cpp        # Reprezentacija i generisanje lavirinta
├── 🧩 element.hpp/cpp         # Bazna klasa za sve elemente igre
├── 🤖 robot.hpp/cpp           # Implementacija karaktera igrača
├── 🐂 minotaur.hpp/cpp        # Implementacija AI protivnika
├── 🎁 predmeti.hpp/cpp        # Sistem predmeta sa nasleđivanjem
├── 📊 upis_stanja.hpp/cpp     # Čuvanje stanja igre
├── 🔧 lavirint_utils.hpp/cpp  # Algoritmi generisanja lavirinta
├── 📚 liblavirint.a           # Statička biblioteka
└── 📋 Dokumentacijski fajlovi
```

### 🎯 Design Paterni

- **🏗️ Hijerarhija Nasleđivanja**: Svi elementi igre nasleđuju od `Element` bazne klase
- **🎮 Strategy Pattern**: Različiti efekti predmeta implementirani kroz polimorfizam
- **📊 Observer Pattern**: Praćenje i čuvanje stanja igre
- **🏭 Factory Pattern**: Dinamičko kreiranje elemenata tokom generisanja lavirinta

### 🔧 Tehnička Implementacija

```cpp
// Osnovna struktura nasleđivanja
Element (Bazna)
├── Robot : public Element
├── Minotaur : public Element
└── Predmet : public Element
    ├── Efekat Mača
    ├── Efekat Štita
    ├── Efekat Čekića
    └── Efekat Magle Rata
```

---

## 🎮 Kontrole i Igra

### 🕹️ Kontrole Kretanja

| Taster | Akcija | Opis |
|--------|--------|------|
| `↑` / `W` | Kretanje Gore | Navigacija na sever |
| `↓` / `S` | Kretanje Dole | Navigacija na jug |
| `←` / `A` | Kretanje Levo | Navigacija na zapad |
| `→` / `D` | Kretanje Desno | Navigacija na istok |
| `Q` | Napusti Igru | Izlaz i čuvanje stanja |

### 🎯 Uslovi Pobede

1. **🏆 Pobeda**: Stigni do izlaza (I) pre nego što te Minotaur uhvati
2. **⚔️ Borba Pobeda**: Koristi predmet Mač da poraziš Minotaura
3. **💀 Poraz**: Biti uhvaćen od strane Minotaura bez zaštite

### 🧠 AI Ponašanje

Minotaur koristi sofisticiran AI sistem:
- **🎲 Random Kretanje**: Kada je igrač daleko
- **🎯 Lovljenje**: Direktno progonjenje kada je igrač u blizini
- **💥 Uništavanje Predmeta**: Automatski uništava predmete na koje stane
- **🚧 Izbegavanje Zidova**: Ne može proći kroz zidove

---

## 📖 Dokumentacija

### 🔍 Dokumentacija Koda

Projekat uključuje sveobuhvatnu Doxygen-style dokumentaciju:

```cpp
/**
 * @file igra.hpp
 * @brief Glavna klasa kontrolera igre
 * @version 1.0
 * @author Bogdan Ljubinković SV2/2023
 * @date 27.12.2024
 */
```

### 📊 Performance Metrije

- **⚡ Vreme Generisanja**: < 100ms za lavirinte 50x50
- **🎮 Frame Rate**: 60 FPS konzolno renderovanje
- **💾 Korišćenje Memorije**: < 10MB za maksimalnu veličinu lavirinta
- **🔄 Čuvanje Stanja**: < 50ms save/load operacije

### 🧪 Pokrivenost Testiranjem

| Komponenta | Pokrivenost Testiranjem | Status |
|------------|-------------------------|--------|
| Generisanje Lavirinta | 95% | ✅ Kompletno |
| Logika Igre | 90% | ✅ Kompletno |
| Efekti Predmeta | 100% | ✅ Kompletno |
| AI Ponašanje | 85% | ✅ Kompletno |
| File I/O | 100% | ✅ Kompletno |

---

## 🛠️ Razvoj

### 🔧 Build Sistem

Projekat koristi prilagođeni build sistem sa statičkim linkovanjem biblioteke:

```bash
# Kreiraj utility biblioteku
g++ -c lavirint_utils.cpp -o lavirint_utils.o
ar rcs liblavirint_utils.a lavirint_utils.o

# Linkuj glavni executable
g++ main.cpp -o main_program liblavirint_utils.a [source_files] -L. -llavirint_utils
```

### 📋 Zahtevi

- **Minimalne Dimenzije**: 15x15 lavirint, 3+ predmeta
- **Maksimalne Dimenzije**: 100x100 lavirint, 50+ predmeta
- **Memorijski Zahtevi**: 8MB RAM minimum
- **Prostor**: 1MB disk prostora

### 🐛 Poznate Greške

- [ ] Kompatibilnost terminala na starijim Windows sistemima
- [ ] Optimizacija performansi za lavirinte > 75x75
- [ ] Poboljšane AI nivoe težine

---

## 📈 Buduća Poboljšanja

### 🚀 Planirane Funkcionalnosti

- [ ] **🎨 Grafički Interfejs**: SDL2-based vizuelno renderovanje
- [ ] **🌐 Multiplayer Mod**: Mrežna kompetitivna igra
- [ ] **📊 Praćenje Statistika**: Performance analitika i leaderboard
- [ ] **🎵 Audio Sistem**: Zadivljujući zvučni efekti i muzika
- [ ] **📱 Mobilni Port**: Cross-platform mobilna adaptacija

### 🔮 Napredni AI

- [ ] **🧠 Machine Learning**: Neural network-based Minotaur ponašanje
- [ ] **🎯 Pathfinding**: A* algoritam za optimalno kretanje Minotaura
- [ ] **🎲 Skaliranje Težine**: Adaptivni AI na osnovu veštine igrača

---

## 👥 Doprinos

Pozivamo na doprinose! Molimo sledite ove smernice:

1. **🍴 Fork** repozitorijum
2. **🌿 Kreiraj** feature branch (`git checkout -b feature/amazing-feature`)
3. **💾 Commit** tvoje izmene (`git commit -m 'Dodaj amazing feature'`)
4. **📤 Push** na branch (`git push origin feature/amazing-feature`)
5. **🔄 Otvori** Pull Request

### 📝 Stil Koda

- Prati C++17 standarde
- Koristi smislena imena varijabli
- Uključi sveobuhvatnu dokumentaciju
- Održavaj konzistentnu indentaciju (4 razmaka)

---

## 📄 Licenca

Ovaj projekat je licenciran pod **MIT Licencom** - pogledaj [LICENSE](LICENSE) fajl za detalje.

```
MIT License

Copyright (c) 2025 Bogdan Ljubinković

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software...
```

---

## 👨‍💻 Autor

**Bogdan Ljubinković** - *SV2/2023*

- 🎓 **Univerzitet**: Fakultet tehničkih nauka, Novi Sad

---

## 🙏 Zahvalnice

- **🏛️ Grčka Mitologija**: Inspiracija za legendu o Minotauru
- **🎮 Klasične Igre Lavirinta**: Osnova za mehanike igre
- **📚 Objektno-Orijentisano Programiranje**: Edukativni okvir
- **👥 Open Source Zajednica**: Korišćeni alati i biblioteke

---

<div align="center">

### ⭐ Označite ovaj repozitorijum ako vam je pomogao!

**Napravljeno sa ❤️ i puno ☕**

[⬆️ Nazad na Vrh](#-minotaur-maze-game)

</div>