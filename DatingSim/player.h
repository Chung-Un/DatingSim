#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>

class Player
{
public:
    enum class Ruta {NERD, FASHION, MUSIC, FILO, CHEM};
    Player();

    int setPfp(QPixmap pixmap);
    QPixmap getPfp() const  {return pfp;}

    int getCorazonesPrimeraFase ();
    void aumentarCorazonesPrimeraFase(Ruta ruta);

    int getCorazonesRuta() const {return corazonesRuta;}
    void aumentarCorazonesRuta();

    int getCorazonesTotales();

    Ruta seleccionarRuta();
    Ruta getRutaActual()const {return ruta;}

private:
    QPixmap pfp;
    Ruta ruta;
    int corazonesPrimeraFase[5]={0,0,0,0,0};
    int corazonesRuta=0;
    int corazonesTotales[5]={0,0,0,0,0};
};

#endif // PLAYER_H
