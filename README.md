# wxDateFrom
Il primo programma per pc dedicato alle donne che non è un videogioco .
Serve per rompere il ghiaccio durante una relazione interpersonale, ossia per approcciare.
## Installazione

## Tramite repository
Seguite le istruzioni su http://numeronesoft.ddns.net

Poi installate il wxdatefrom.

## Tramite flatpak (sconsigliato)

Seguite le istruziomni su http://numeronesoft.ddns.net:8080

flatpak install --user org.altervista.numerone.wxdatefrom (è importante il --user, l'app viene installata in userspace, così si possono salvare le opzioni)

flatpak run org.altervista.numerone.wxdatefrom


## Su snap store

[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-black.svg)](https://snapcraft.io/wxdatefrom)

## Compilazione con Flatpak
Installate flatpak con apt, aggiungete il repository uficiale, installate flatpakbuilder con flatpak poi installateflathub org.gnome.Platform//43
flathub org.gnome.Sdk//43
con flatpak e poi date il comando

flatpak run org.flatpak.Builder --repo=./repo ./build org.numerone.altervista.wxdatefrom.yml 
A questo punto il programma scaricherà e compilerà le ultime wxwidgets e l'ultimo wxdatfrom.

Infine dare il comando
flatpak run org.flatpak.Builder --user --install --force-clean ./build/ org.altervista.numerone.wxdaterom.yml 


# Donazione

http://numerone.altervista.org/donazioni.php
