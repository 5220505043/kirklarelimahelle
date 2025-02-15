//
//  main.cpp
//  kirklarelimahelleanalizi
//
//  Created by mavlyuda almazova on 15.02.2025.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Softmax fonksiyonunu kullanalım
vector<double> softmax(vector<double> &values) {
    vector<double> exp_values(values.size());
    double max_val = *max_element(values.begin(), values.end());
    double sum_exp = 0.0;
    
    for (size_t i = 0; i < values.size(); i++) {
        exp_values[i] = exp(values[i] - max_val);
        sum_exp += exp_values[i];
    }
    
    for (size_t i = 0; i < values.size(); i++) {
        exp_values[i] /= sum_exp;
    }
    
    return exp_values;
}

// Mahalle struct tanımını yapalım
struct Mahalle {
    string isim;
    double nufus_yogunlugu;
    double ulasim_alt_yapisi;
    double maliyet;
    double cevresel_etki;
    double sosyal_fayda;
    double skoru;
};

int main() {
    vector<Mahalle> mahalleler = {
        {"Merkez", 9000, 8.0, 450000, 3.5, 9.0, 0.0},
        {"Demirköy", 5000, 5.5, 250000, 4.0, 6.5, 0.0},
        {"Lüleburgaz", 11000, 9.0, 600000, 3.8, 8.5, 0.0}
    };

    // Kriter ağırlıkları belirleyelim (ölçeklendirme için ters çevrilen maliyet ve çevresel etki)
    vector<double> kriter_skorlari;
    for (auto &m : mahalleler) {
        double skor = m.nufus_yogunlugu * 0.35 + m.ulasim_alt_yapisi * 0.2 +
                      (1 / m.maliyet) * 100000 * 0.1 + (1 / m.cevresel_etki) * 10 * 0.15 + m.sosyal_fayda * 0.2;
        kriter_skorlari.push_back(skor);
    }

    // Softmax ile normalize yapalım
    vector<double> softmax_skorlari = softmax(kriter_skorlari);
    
    // Mahallelere softmax skorlarını atamalarını girelim
    for (size_t i = 0; i < mahalleler.size(); i++) {
        mahalleler[i].skoru = softmax_skorlari[i];
    }
    
    // En uygun güzergahı belirliyoruz
    Mahalle en_uygun = mahalleler[0];
    for (auto &m : mahalleler) {
        if (m.skoru > en_uygun.skoru) {
            en_uygun = m;
        }
    }
    
    // Sonuçları girelim
    cout << fixed << setprecision(4);
    cout << "Mahalle Skorları:\n";
    for (auto &m : mahalleler) {
        cout << m.isim << " - Softmax Skoru: " << m.skoru << endl;
    }
    cout << "\nEn uygun güzergah: " << en_uygun.isim << endl;
    
    return 0;
}
