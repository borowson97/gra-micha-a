---

```md
# 🎮 Szósty Zmysł Liczb

Konsolowa gra w zgadywanie liczb napisana w języku **C++**.  
Twoim zadaniem jest odgadnięcie wylosowanej liczby w jak najmniejszej liczbie prób i zapisanie się w **TOP 5 najlepszych wyników** 🏆

---

## 📌 Opis gry

Program losuje liczbę z wybranego zakresu, a gracz próbuje ją odgadnąć.  
Po każdej próbie wyświetlana jest podpowiedź:

- 🔽 *Za mało*
- 🔼 *Za dużo*
- ✅ *Trafiłeś!*

Wynik (liczba prób) zapisywany jest do pliku tekstowego i porównywany z najlepszymi rezultatami.

---

## ⚙️ Funkcje programu

✅ trzy poziomy trudności  
✅ losowanie liczb  
✅ zliczanie liczby prób  
✅ zapisywanie wyników do pliku  
✅ ranking **TOP 5 najlepszych graczy**  
✅ obsługa błędnych danych wejściowych  
✅ czytelne menu tekstowe  

---

## 🎚 Poziomy trudności

| Poziom | Zakres liczb |
|------|--------------|
| 🟢 Łatwy | 1 – 10 |
| 🟡 Średni | 1 – 50 |
| 🔴 Trudny | 1 – 150 |

---

## 🏆 System TOP 5

- Wyniki zapisywane są w pliku **`top5.txt`**
- Sortowanie odbywa się według najmniejszej liczby prób
- Przechowywane jest maksymalnie **5 najlepszych wyników**

Przykład zawartości pliku:

```

Adam 3
Kasia 4
Tomek 5
Ola 6
Bartek 7

```

---

## 📂 Struktura projektu

```

📁 Szosty_Zmysl_Liczb
│
├── main.cpp
├── top5.txt
└── README.md

````

---

## ▶️ Jak uruchomić

### Kompilacja (np. g++)

```bash
g++ main.cpp -o gra
````

### Uruchomienie

```bash
./gra
```

> Program przeznaczony jest głównie dla systemu **Windows**
> (użycie `system("cls")` do czyszczenia ekranu).

---

## 🧠 Wykorzystane elementy C++

* `iostream`
* `vector`
* `string`
* `fstream`
* `algorithm`
* `ctime`
* `cstdlib`
* struktury (`struct`)
* przeciążenie operatora `<`
* obsługa błędów wejścia (`cin.fail()`)

---

## 📸 Podgląd menu

```
+=====================================+
|          <<< MENU GŁÓWNE >>>         |
+=====================================+
| 1. 🎮  GRAJ W ZGADYWANIE LICZB       |
| 2. 🏆  WYŚWIETL TOP 5 WYNIKÓW        |
| 3. 🚪  WYJŚCIE Z GRY                 |
+=====================================+
```

---

## 🚀 Możliwe rozszerzenia

* 🔊 dźwięki
* 🧩 tryb limitu prób
* 🧠 podpowiedzi typu „ciepło–zimno”
* 💾 zapis daty wyniku
* 🎨 wersja graficzna (SFML / SDL)
* 🌍 wersja wielojęzyczna

---

## 👨‍💻 Autor

Projekt wykonany jako gra edukacyjna w języku **C++**
do nauki:

* obsługi plików
* struktur danych
* pętli
* sortowania
* interakcji z użytkownikiem

---

## 📜 Licencja

Projekt do użytku edukacyjnego i niekomercyjnego.
Możesz go dowolnie modyfikować i rozwijać.

---

🎯 **Miłej zabawy i powodzenia w biciu rekordów!** 🏆

```

---

Jeśli chcesz, mogę też:

- ✨ skrócić README (np. pod GitHuba)
- 🇵🇱 / 🇬🇧 zrobić wersję po angielsku
- 🎨 dodać badge (C++, version, license)
- 📘 przygotować README „na ocenę do szkoły”
- 🧾 napisać dokumentację techniczną do projektu

Wystarczy powiedzieć 👍
```
