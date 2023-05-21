// ProgramowanieRównoległe.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <chrono>
#include "functions.h"

using namespace std;


void execution_time(double (*function)(int[], int), int observations[], int size) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    auto t1 = high_resolution_clock::now();
    std::cout << function(observations, size) << std::endl;
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";

}

int main()
{

    const int size = 1500;
    int observations[size];

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        observations[i] = i + 1;
    }

    execution_time(sampling_variance_seq, observations, size);
    execution_time(sampling_variance_openmp, observations, size);
    execution_time(sampling_variance_multithreaded, observations, size);
    

    return 0;

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
