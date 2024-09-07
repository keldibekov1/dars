from os import system
system("cls")
fayl = open("natijadavlat.txt", "r", encoding="utf-8")

davlatlar = fayl.read().split("\n")

countries = []

for i in range(len(davlatlar)):
    davlat = davlatlar[i].split(',')

    country= {
        'city': davlat[0],
        'aholi': davlat[1],
        'tili': davlat[2]

    }
    countries.append(country)

