#include "../headers/Exceptions.h"

eroare_font::eroare_font(const std::string& mesaj) :
    eroare_aplicatie("Nu a fost gasit un font (.ttl) la adresa: " + mesaj) {}

eroare_imagine::eroare_imagine(const std::string& mesaj) :
    eroare_aplicatie("Nu a fost gasita o imagine (.jpg/ .jpeg/ .png) la adresa:" + mesaj) {}
