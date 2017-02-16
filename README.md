# Weatherproject
Create a weatherstation that reads wind every hour for every day, to compare different days.


https://docs.google.com/document/d/1JL4eCt8dDbwsfjsmIgi8dvCsfmfYcanKNR7fyFdFYA0/edit?usp=sharing


Definition:
Inbyggt system f�r att samla data av temperaturen vid varje timme dygnet runt. Vi ska anv�nda en Arduino Uno f�r 
att koppla samman de sensorer som �r n�dv�ndiga f�r projektet med str�mf�rs�rjning och realtidsklocka. Om vi har 
tid och kunskap �r ett ytterligare m�l att f� utrustningen att fungera utomhus vid vanligt svenskt v�rv�der. 

Med den data som samlas in kan man j�mf�ra temperaturen mot tidigare dagar vid samma klockslag, men �ven f�r att 
f� en medeltemperatur, kan i framtiden ut�kas till att j�mf�ra temperaturen med tidigare �r, f�r att uppt�cka en 
eventuell global uppv�rmning. 


Metod:
L�sa av temperaturen en g�ng i timmen och spara detta i en loggfil f�r senare j�mf�relser och sorteringar. Vi 
b�rjar med att koppla samman alla komponenter p� en breadboard f�r bra �versikt och l�tt modifiering. B�rja tidigt 
med testning i sm� steg, d� ingen i gruppen har arbetat med varken temperatursensorn eller realtidsklockan innan. 

En Arduino Uno 328p inneh�ller 32 KB flash-minne, n�got vi tror kommer r�cka f�r den lagring vi ska g�ra. 
Skulle inte det fungera f�r vi anv�nda en SD-kortl�sare f�r uth�mtning av data. 
P� n�got s�tt ska data h�mtas ut, helst i en f�rdig .txt-fil inneh�llandes de v�rden som �r intressanta f�r 
granskning. 

Tanken �r att placera den data vi samlar in i en array av typedef-typ, d�r vi l�gger in temperatur och 
klockslag(eventuellt fukt om tid finns). H�r finns m�jlighet att ut�ka med ytterligare en struct inneh�llandes 
sekunder, minuter, timmar och dagar f�r att kunna anpassa utdatan efter anv�ndarens behov. 

Placera v�rden i en typedef-array, temp, fukt och [tid]
Typedef-array [tid] f�r sekund, minut, timme, dag


Utrustning som kr�vs:
Arduino UNO 328p
Batteri f�r tr�dl�st anv�ndande
Gyro med inbyggd temperatursensor (MPU6050), alternativt temperatur- och fuktsensor(DHT11)
Realtidsklocka �ver I2C (DS3023?) med bibliotek
Lagring, ex inbyggt flashminne, minneskort, USB-minne


Mjukvarukrav:
Systemet ska kunna vara ig�ng i minst 24h utan underh�ll.
De v�rden som samlas in ska vara p�litliga.
Resultaten ska redovisas prydligt i en textfil vid uth�mtning av data.
V�ldokumenterad kod som ska vara l�tt att s�tta sig in i. 
24 insamlade v�rden p� en 24h m�tning
Optimerad och kompakt kod
V�l valda variabelnamn
Anv�nda en algoritm f�r sortering


Test och verifikation:

Vi kommer dela upp v�rt projekt i fyra stycken milstolpar d�r varje utg�r ett lyckat test. Testen kommer 
vara fokuserade p� projektets huvudsakliga funktion, och kan eventuellt ut�kas med fler test om fler 
funktioner tillkommer(ex fuktsensor och struct.tid).

[-] Test1: Temperatursensorn ger ett f�r oss korrekt v�rde och den data som samlas in visas efter genomf�rt 
test i en textfil.
[-] Test2: Ett test som p�g�r 30 min, d�r ett v�rde ska h�mtas varannan minut, d.v.s. 15 insamlade v�rden 
sparade i en textfil med tillh�rande klockslag.
[-] Test3: Sluttest f�r inomhusm�tning i 24tim, d�r ett v�rde h�mtas varje timme och sparas. 
[-] Test4: Utomhus 30min f�r att testa h�llbarhet i den milj�n produkten �r t�nkt att anv�ndas.


Om tid finns: 

L�gga till en fuktsensor som komplement till temperaturen. 
Skapa en typedef-struct som inneh�ller mer detaljerad tid, och som �r l�nkad till fukt- och temperatur-v�rdena. 
LCD-sk�rm f�r momentan visning av temperatur och fuktighet, alternativt �ven klockslag. 

