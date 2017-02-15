# Weatherproject
Create a weatherstation that reads wind every hour for every day, to compare different days.


https://docs.google.com/document/d/1JL4eCt8dDbwsfjsmIgi8dvCsfmfYcanKNR7fyFdFYA0/edit?usp=sharing


Projektbeskrivning

Defininition:
Inbyggt system f�r att samla data av v�dret. Anv�nda en Arduino f�r att koppla samman de sensorer 
som �r n�dv�ndiga f�r projektet. 


Metod:
L�sa av vind och temperatur en g�ng i timmen, spara i en loggfil f�r att j�mf�ra varje timme och olika tidpunkter p� dagen.
Placera v�rden i en typedef-array, temp, **fukt** och [tid]
***Typedef-array [tid] f�r sekund, minut, timme, dag


Hur:
Samla in data och spara det. Skicka datan till ett ex. USB-minne. Behandla datan. L�sa av varje timme. 


Utrustning:
Arduino
Batteri f�r tr�dl�shet
Temperatur-sensor
Realtidsklocka(I2C) med bibliotek
Lagring, ex minneskort, USB-minne


Test och verifikation:

Avgr�nsa sig

[-] Test1: Se om vi f�r n�gon data �verhuvudtaget.
[-] Test2: 30 min test, f� v�rden varannan minut.
[-] Test3: Utomhus 30min.
[-] Test4: Sluttest 24tim, v�rde varje timme.

