#include "player.h"
using std::max_element;
using std::distance;

Player::Player(QString nombre) {}

void Player::setPfp(QPixmap pixmap)
{
    this->pfp = pixmap;
}

int Player::getCorazonesPrimeraFase()
{
    return corazonesPrimeraFase[this->index];
}

void Player::aumentarCorazonesPrimeraFase(Ruta ruta)
{
    corazonesPrimeraFase[getIndicebyRuta(ruta)] ++;
}

void Player::aumentarCorazonesRuta()
{
    this->corazonesRuta++;
}

int Player::getCorazonesTotales()
{
    return getCorazonesPrimeraFase() + corazonesRuta;
}

void Player::setNombre(QString nombre)
{
    this->nombre = nombre;
}

int Player::getIndicebyRuta(Ruta ruta)
{
    switch(ruta){
    case Ruta::NERD:
        return 0;
    case Ruta::FASHION:
        return 1;
    case Ruta::MUSIC:
        return 2;
    case Ruta::FILO:
        return 3;
    case Ruta::CHEM:
        return 4;
    default:
        return -1;
    }
}

Player::Ruta Player::getRutabyIndex(int index)
{
    switch(index){
    case 0:
        return Ruta::NERD;
        break;
    case 1:
        return Ruta::FASHION;
        break;
    case 2:
        return Ruta::MUSIC;
        break;
    case 3:
        return Ruta::FILO;
        break;
    case 4:
        return Ruta::CHEM;
        break;
    }

    return Ruta::NINGUNO;
}

Player::Ruta Player::seleccionarRuta()
{
    auto max_iterador = std::max_element(corazonesPrimeraFase,corazonesPrimeraFase+5);
    this->index = std::distance(corazonesPrimeraFase,max_iterador);

    this->ruta = getRutabyIndex(this->index);
    return this->ruta;

}
