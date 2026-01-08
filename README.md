[🇬🇧 English](README.en.md)
# Wprowadzenie
Program ten służy do analizy struktury danych wysyłanych przez obiektyw z bagnetem A-Mount.
Po modyfikacjach może posłużyć do analizy dowolnych synchronicznych transmisji szeregowych.
# Sprzęt
Wymagana jest dowolna płytka kompatybilna z Arduino.
# Działanie
Mikrokontroler wysyła do obiektywu sygnał zegarowy. Obiektyw wysyła dane szeregowe, które odbierane są przez mikrokontroler.
Z każdą transmisją nowej ramki przez obiektyw mikrokontroler drukuje jej zawartość w terminalu szeregowym.
