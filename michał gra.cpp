#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <algorithm>

using namespace std;

void czysc_ekran() {
    system("cls");
}

struct Wynik {
    string imie;
    int proby;

    bool operator<(const Wynik& inny) const {
        return proby < inny.proby;
    }
};

void zapisz_wynik(const string& imie, int proby) {
    vector<Wynik> top5;
    Wynik nowy_wynik = { imie, proby };
    string linia;

    ifstream plik_czytaj("top5.txt");
    while (plik_czytaj >> linia) {
        Wynik w;
        w.imie = linia;
        if (plik_czytaj >> w.proby) {
            top5.push_back(w);
        }
    }
    plik_czytaj.close();

    top5.push_back(nowy_wynik);

    sort(top5.begin(), top5.end());

    if (top5.size() > 5) {
        top5.resize(5);
    }

    ofstream plik_zapisz("top5.txt");
    for (const auto& w : top5) {
        plik_zapisz << w.imie << " " << w.proby << endl;
    }
    plik_zapisz.close();
}

void wyswietl_top5() {
    czysc_ekran();
    vector<Wynik> top5;
    string linia;

    ifstream plik_czytaj("top5.txt");
    while (plik_czytaj >> linia) {
        Wynik w;
        w.imie = linia;
        if (plik_czytaj >> w.proby) {
            top5.push_back(w);
        }
    }
    plik_czytaj.close();

    cout << "\n======================================" << endl;
    cout << "           🏆 TOP 5 NAJLEPSZYCH 🏆       " << endl;
    cout << "======================================" << endl;

    if (top5.empty()) {
        cout << "Brak zapisanych wynikow." << endl;
    }
    else {
        sort(top5.begin(), top5.end());

        for (size_t i = 0; i < top5.size(); ++i) {
            cout << i + 1 << ". " << top5[i].imie << " - " << top5[i].proby << " prob" << endl;
        }
    }
    cout << "======================================" << endl;
    cout << "Nacisnij [ENTER], aby wrocic do menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void graj_w_zgadywanie(string& imie) {
    czysc_ekran();
    char zagrajPonownie;

    do {
        int poziom;
        int maxLiczba;
        int liczba;
        int strzal;
        int liczbaProb = 0;

        cout << "\n=== Wybierz poziom trudnosci ===\n";
        cout << "1. Latwy (1 - 10)\n";
        cout << "2. Sredni (1 - 50)\n";
        cout << "3. Trudny (1 - 150)\n";
        cout << "Podaj numer poziomu: ";

        if (!(cin >> poziom)) {
            cout << "Niepoprawny format wejscia! Ustawiam poziom 1.\n";
            poziom = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (poziom == 1) maxLiczba = 10;
        else if (poziom == 2) maxLiczba = 50;
        else if (poziom == 3) maxLiczba = 150;
        else {
            cout << "Nie ma takiego poziomu! Ustawiam poziom 1.\n";
            maxLiczba = 10;
            poziom = 1;
        }

        liczba = rand() % maxLiczba + 1;
        cout << "\nZgadnij liczbe od 1 do " << maxLiczba << ":\n";

        do {
            liczbaProb++;

            cout << "--- Proba #" << liczbaProb << " ---" << endl;
            cout << "Podaj liczbe: ";

            if (!(cin >> strzal)) {
                cout << "Niepoprawny format wejscia! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                liczbaProb--;
                continue;
            }

            if (strzal < liczba) cout << "Za malo!\n" << endl;
            else if (strzal > liczba) cout << "Za duzo!\n" << endl;
            else cout << "\n**Brawo! Trafiles!**\n" << endl;

        } while (strzal != liczba);

        if (imie.empty()) {
            cout << "Jak masz na imie? ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> imie;
            cout << endl;
        }

        cout << imie << ", udalo ci sie odgadnac liczbe w **"
            << liczbaProb << " probach!**\n";

        zapisz_wynik(imie, liczbaProb);

        cout << "\n-------------------------------------\n";
        cout << "Czy chcesz zagrac jeszcze raz? (t/n): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> zagrajPonownie;

    } while (zagrajPonownie == 't' || zagrajPonownie == 'T');

    czysc_ekran();
}

int main() {
    srand(time(nullptr));
    string imie = "";
    int wybor;

    do {
        czysc_ekran();

        cout << "\n\n";
        cout << "=============================================================+" << endl;
        cout << "|                                                            |" << endl;
        cout << "|        + S Z O S T Y   Z M Y S L   L I C Z B +             |" << endl;
        cout << "|                                                            |" << endl;
        cout << "+------------------------------------------------------------+" << endl;
        cout << "|                                                            |" << endl;
        cout << "|      . . . . P O C Z U J   L I C Z B E . . . .             |" << endl;
        cout << "|                                                            |" << endl;
        cout << "+============================================================+" << endl;

        cout << "\n\n";
        cout << "+=====================================+" << endl;
        cout << "|          <<< MENU GLOWNE >>>        |" << endl;
        cout << "+=====================================+" << endl;
        cout << "|                                     |" << endl;
        cout << "| 1. 🎮 -> GRAJ W ZGADYWANIE LICZB    |" << endl;
        cout << "|                                     |" << endl;
        cout << "| 2. 🏆 -> WYSWIETL TOP 5 WYNIKOW     |" << endl;
        cout << "|                                     |" << endl;
        cout << "| 3. 🚪 -> WYJSCIE Z GRY              |" << endl;
        cout << "|                                     |" << endl;
        cout << "+=====================================+" << endl;
        cout << "Wybierz opcje: ";

        if (!(cin >> wybor)) {
            cout << "Niepoprawny format wejscia! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (wybor) {
        case 1:
            graj_w_zgadywanie(imie);
            break;
        case 2:
            wyswietl_top5();
            break;
        case 3:
            cout << "\nDziekuje za gre, " << (imie.empty() ? "Graczu" : imie) << "! Do zobaczenia!\n";
            break;
        default:
            cout << "Nieznana opcja. Sprobuj ponownie.\n";
            break;
        }

    } while (wybor != 3);

    return 0;
}