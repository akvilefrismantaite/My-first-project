#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using std::string;
using std::vector;

struct studentas{
    string vardas, pavarde;
    vector <int> paz;
    int exam;
};

void printas(studentas &A);
double vidurkis(studentas A);
double galutinisVid(studentas A);
int main()
{
    int k;
    std::vector<studentas> grupe;
    studentas A;
    std::cout<<"Kiek studentu yra sarase: ";
    int n;
    std::cin>>n;
    for (int j=0;j<n;j++)
    {
        std::cout<<"Iveskite per tarpa studento varda ir pavarde: ";
        std::cin>>A.vardas>>A.pavarde;
        std::cout<<"Iveskite semestro paz. kieki: ";
        std::cin>>k;
        for (int i=0;i<k;i++){
            //cin>>A.paz[i];
            std::cout<<"Iveskite "<<i+1 <<"paz.: ";
            int a;
            std::cin>>a;
            A.paz.push_back(a);
        }
        std::cout<<"Iveskite semestro Egzamino paz.: ";
        std::cin>>A.exam;
        grupe.push_back(A);
        A.pavarde.clear();
        A.vardas.clear();
        A.paz.clear();
    }

    std::cout << "Studento duom.: \n";

std::cout << std::left
          << std::setw(15) << "Pavarde"
          << std::setw(15) << "Vardas"
          << std::setw(20) << "Galutinis (Vid.)"
          << "\n";

std::cout << "--------------------------------------------------\n";

for (studentas &B : grupe)
{
    printas(B);
}
    return 0;
}
void printas(studentas &A)
{
    std::cout << std::left<< std::setw(15) << A.pavarde<< std::setw(15) << A.vardas<< std::fixed<< std::setprecision(2)<< galutinisVid(A)<< "\n";
}
double vidurkis(studentas A)
{
    double suma = 0;
    for (int p : A.paz)
    {
        suma += p;
    }
    return suma / A.paz.size();
}
double galutinisVid(studentas A)
{
    return 0.4 * vidurkis(A) + 0.6 * A.exam;
}
