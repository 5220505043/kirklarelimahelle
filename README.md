Kırklareli Mahalle Analizi
Bu proje, Kırklareli'nde toplu taşıma güzergahlarını optimize etmek için geliştirilmiştir. Farklı mahallelerin çeşitli kriterlere göre değerlendirilerek en uygun güzergahın belirlenmesini amaçlar. Softmax algoritması kullanılarak mahallelerin skoru hesaplanır ve en iyi seçenek belirlenir.

📌 Özellikler
Softmax Algoritması ile mahalle skorlarının normalize edilmesi
Farklı kriterlere göre değerlendirme:
Nüfus Yoğunluğu
Ulaşım Altyapısı
Maliyet
Çevresel Etki
Sosyal Fayda
En uygun güzergahın belirlenmesi
🚀 Kurulum ve Çalıştırma
1️⃣ Kaynak kodu klonlayın:
bash
Kopyala
Düzenle
git clone https://github.com/kullanici/kirklarelimahelleanalizi.git
cd kirklarelimahelleanalizi
2️⃣ C++ kodunu derleyin:
bash
Kopyala
Düzenle
g++ main.cpp -o kirklareli_analiz
3️⃣ Çalıştırın:
bash
Kopyala
Düzenle
./kirklareli_analiz
🛠 Kullanılan Teknolojiler
C++: Yüksek performanslı hesaplamalar için
Softmax Algoritması: Verileri normalize etmek ve mahalleler arasında adil bir karşılaştırma yapmak için
📊 Çıktı Örneği
bash
Kopyala
Düzenle
Mahalle Skorları:
Merkez - Softmax Skoru: 0.2500
Demirköy - Softmax Skoru: 0.1500
Lüleburgaz - Softmax Skoru: 0.6000

En uygun güzergah: Lüleburgaz
