Samoila Cristina Madalina
Bicu Dennis Andrei
Grupa 331AB, anul III
Facultatea de Automatica si Calculatoare, Universitatea Politehnica Bucuresti

Proiect la materia Sisteme cu Microprocesoare
Tema proiect: sistem embedded de hranire a animalelor de companie 
Titlu: JD's Pet Feeder


Introducere
	Motivul alegerii temei a fost reprezentat de faptul ca ambii membri ai echipei au in viata lor cel putin
un animal de companie. Mai mult decat atat, provocarea construirii unui sistem ce imbina mecanica, 
electrica si ingineria software a constituit un impuls in plus in realizarea deciziei.

Lista de componente hardware:
	1. Placuta de dezvoltare Arduino UNO
	2. Breadboard
	3. Telecomanda bazata pe tehnologia IR, alaturi de receiver
	4. Ecran LCD
	5. Un rezistor
	6. Fire conectoare
	7. Ansamblu mecanic
		a. 2 placi de lemn
		b. "teava" de plastic
		c. carcasa de metal
		d. dop de plastic
		e. castron colector

Descriere software:
	Pentru realizarea proiectului, am folosit urmatoarele biblioteci:
		1. IRremote
		3. LiquidCrystal
		4. Servo
	Functionalitatea implementata in codul sistemului se ramifica in 2 moduri de utilizare:
		a. Modul Automat - tasta '1' (hranire periodica)
			- in acest mod utilizatorul trebuie sa seteze o periodicitate cu care sistemul sa realizeze
			  dozarea hranei
			- ex.: la o apasare a cifrei 9, sistemul hraneste animalul o data la 9 minute
			- periodicitatea este exprimata in minute by default, dar poate fi schimbata in ore in cod
		b. Modul Manual - tasta '2' (hranire la comanda)
			- utilizatorul trebuie sa apese tasta 'OK' pentru ca sistemul sa execute cursa motorului
	Pentru a reveni la meniul principal, se poate oricand apasa tasta 'stanga' sau '*'.

