# Weatherproject - Filip, Robert, Dennis

https://docs.google.com/document/d/1JL4eCt8dDbwsfjsmIgi8dvCsfmfYcanKNR7fyFdFYA0/edit

Definition:
Inbyggt system för att samla data av temperaturen vid varje timme dygnet runt. Vi ska använda en Arduino Uno för att koppla samman de sensorer som är nödvändiga för projektet med strömförsörjning och realtidsklocka. Om vi har tid och kunskap är ett ytterligare mål att få utrustningen att fungera utomhus vid vanligt svenskt vårväder. 

Med den data som samlas in kan man jämföra temperaturen mot tidigare dagar vid samma klockslag, men även för att få en medeltemperatur, kan i framtiden utökas till att jämföra temperaturen med tidigare år, för att upptäcka en eventuell global uppvärmning. 


Metod:
Läsa av temperaturen en gång i timmen och spara detta i en loggfil för senare jämförelser och sorteringar. Vi börjar med att koppla samman alla komponenter på en breadboard för bra översikt och lätt modifiering. Börja tidigt med testning i små steg, då ingen i gruppen har arbetat med varken temperatursensorn eller realtidsklockan innan. 

En Arduino Uno 328p innehåller 32 KB flash-minne, något vi tror kommer räcka för den lagring vi ska göra. Skulle inte det fungera får vi använda en SD-kortläsare för uthämtning av data. 
På något sätt ska data hämtas ut, helst i en färdig .txt-fil innehållandes de värden som är intressanta för granskning. 

Tanken är att placera den data vi samlar in i en array av typedef-typ, där vi lägger in temperatur och klockslag(eventuellt fukt om tid finns). Här finns möjlighet att utöka med ytterligare en struct innehållandes sekunder, minuter, timmar och dagar för att kunna anpassa utdatan efter användarens behov. 

Placera värden i en typedef-array, temp, fukt och [tid]
Typedef-array [tid] för sekund, minut, timme, dag


Utrustning som krävs:
Arduino UNO 328p
Batteri för trådlöst användande
Gyro med inbyggd temperatursensor (MPU6050), alternativt temperatur- och fuktsensor(DHT11)
Realtidsklocka över I2C (DS3023?) med bibliotek
Lagring, ex inbyggt flashminne, minneskort, USB-minne
Mjukvarukrav:
Systemet ska kunna vara igång i minst 24h utan underhåll.
De värden som samlas in ska vara pålitliga.
Resultaten ska redovisas prydligt i en textfil vid uthämtning av data.
Väldokumenterad kod som ska vara lätt att sätta sig in i. 
24 insamlade värden på en 24h mätning
Optimerad och kompakt kod
Väl valda variabelnamn
Använda en algoritm för sortering


Test och verifikation:

Vi kommer dela upp vårt projekt i fyra stycken milstolpar där varje utgör ett lyckat test. Testen kommer vara fokuserade på projektets huvudsakliga funktion, och kan eventuellt utökas med fler test om fler funktioner tillkommer(ex fuktsensor och struct.tid).

[-] Test1: Temperatursensorn ger ett för oss korrekt värde och den data som samlas in visas efter genomfört test i en textfil.
[-] Test2: Ett test som pågår 30 min, där ett värde ska hämtas varannan minut, d.v.s. 15 insamlade värden sparade i en textfil med tillhörande klockslag.
[-] Test3: Sluttest för inomhusmätning i 24tim, där ett värde hämtas varje timme och sparas. 
[-] Test4: Utomhus 30min för att testa hållbarhet i den miljön produkten är tänkt att användas.


Om tid finns: 

Lägga till en fuktsensor som komplement till temperaturen. 
Skapa en typedef-struct som innehåller mer detaljerad tid, och som är länkad till fukt- och temperatur-värdena. 
LCD-skärm för momentan visning av temperatur och fuktighet, alternativt även klockslag. 

