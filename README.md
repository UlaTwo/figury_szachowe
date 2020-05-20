# figury_szachowe
projekt: Szachy-rekurencyjne ustawianie figur na planszy
    
    Opis programu: 
    W argumentach wywołania programu zostaje przekazana nazwa pliku teskstowego,
    w którym zapisane są dane wejściowe programu: wymiary planszy 
    oraz ilość poszczególnych figur zadanaych do ustawienia na planszy.
    Zostaje sprawdzona poprawność pliku (możliwy jest tylko jeden sposób wpisania danych według szablonu).
    Utworzona jest tablica w której zapisane są informacje o wymiarach planszy oraz ilości poszczególnych figur.
    Na jej podstawie tworzona jest tablica wskaźników na figury 
    (figury są tworzone i wpisywane do tablicy na podstawie wcześniej utworzonej tablicy).
    Następnie dla tablicy wskaźników do figur wywoływana jest funkcja rekurencyjna,
    która szuka poprawnego ustawienia na planszy.
    Poprawne rozwiązanie wpisywane jest do tablicy dwuwymiarowej i jest następnie wyświetlane.
