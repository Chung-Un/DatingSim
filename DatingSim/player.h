#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>
#include <QString>

class Player
{
public:
    enum class Ruta {NERD, FASHION, MUSIC, FILO, CHEM,NINGUNO};
    Player(QString nombre);

    void setPfp(QPixmap pixmap);
    QPixmap getPfp() const  {return pfp;}

    int getCorazonesPrimeraFase ();
    void aumentarCorazonesPrimeraFase(Ruta ruta);

    int getCorazonesRuta() const {return corazonesRuta;}
    void aumentarCorazonesRuta();

    int getCorazonesTotales();

    Ruta seleccionarRuta();
    Ruta getRutaActual()const {return ruta;}

    QString getNombre() const { return nombre; }
    void setNombre(QString nombre);

    Ruta getRutabyIndex(int index);
    int getIndicebyRuta(Ruta ruta);

private:
    QPixmap pfp;
    Ruta ruta;
    int corazonesPrimeraFase[5]={0,0,0,0,0};
    int corazonesRuta=0;
    int corazonesTotales[5]={0,0,0,0,0};
    int index=-1;
    QString nombre;
};

#endif // PLAYER_H
