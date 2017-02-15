# Weatherproject
Create a weatherstation that reads wind every hour for every day, to compare different days.


https://docs.google.com/document/d/1JL4eCt8dDbwsfjsmIgi8dvCsfmfYcanKNR7fyFdFYA0/edit?usp=sharing


Projektbeskrivning

Defininition:
Inbyggt system för att samla data av vädret. Använda en Arduino för att koppla samman de sensorer 
som är nödvändiga för projektet. 


Metod:
Läsa av vind och temperatur en gång i timmen, spara i en loggfil för att jämföra varje timme och olika tidpunkter på dagen.
Placera värden i en typedef-array, temp, **fukt** och [tid]
***Typedef-array [tid] för sekund, minut, timme, dag


Hur:
Samla in data och spara det. Skicka datan till ett ex. USB-minne. Behandla datan. Läsa av varje timme. 


Utrustning:
Arduino
Batteri för trådlöshet
Temperatur-sensor
Realtidsklocka(I2C) med bibliotek
Lagring, ex minneskort, USB-minne


Test och verifikation:

Avgränsa sig

[-] Test1: Se om vi får någon data överhuvudtaget.
[-] Test2: 30 min test, få värden varannan minut.
[-] Test3: Utomhus 30min.
[-] Test4: Sluttest 24tim, värde varje timme.

