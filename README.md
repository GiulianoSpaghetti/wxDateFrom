# wxDateFrom
Un programma per calcolare quanto tempo è passato da una determinata data in wxwidgets.

# Installazione

# Tramite flatpak (consigliato perché ci sono le wxwidgets 3.2 invece che 3.0)
Date i seguenti comandi:

sudo apt install flatpak

flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

flatpak remote-add --if-not-exists numeronesoft http://numeronesoft.ddns.net:8080/numeronesoft.flatpakrepo

flatpak install --user org.altervista.numerone.wxdatefrom (è importante il --user, l'app viene installata in userspace, così si possono salvare le opzioni)

flatpak run org.altervista.numerone.wxdatefrom

# Compilazione con Flatpak
Installate flatpak con apt, aggiungete il repository uficiale, installate flatpakbuilder con flatpak poi installateflathub org.gnome.Platform//43
flathub org.gnome.Sdk//43
con flatpak e poi date il comando

flatpak run org.flatpak.Builder --repo=./repo ./build org.numerone.altervista.wxdatefrom.yml 
A questo punto il programma scaricherà e compilerà le ultime wxwidgets e l'ultimo wxdatfrom.

Infine dare il comando
flatpak run org.flatpak.Builder --user --install --force-clean ./build/ org.altervista.numerone.wxdaterom.yml 


# Donazioni

[![paypal](https://www.paypalobjects.com/it_IT/IT/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=H4ZHTFRCETWXG)

Puoi donare anche tramite carta Hype a patto di avere il mio numero di cellulare nella rubrica. Sai dove lo puoi trovare? Sul mio curriculum.
Apri l'app Hype, fai il login, seleziona PAGAMENTI, INVIA DENARO, seleziona il mio numero nella rubrica, imposta l'importo, INSERISCI LA CAUSALE e segui le istruzioni a video.

