#pragma once
#include <list>
#include "../Obstaculos/Obstaculo.h"
#include "../Obstaculos/Plataforma.h"
#include "../Personagens/Inimigo.h"
#include "../Personagens/Heroi.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Projetil.h"

using namespace std;

namespace Gerenciadores {
	class Gerenciador_Colisoes
	{
	private:
		list<Entidades::Obstaculos::Obstaculo*> LObst;
		list<Entidades::Personagens::Inimigo*> LIni;
		list<Entidades::Projetil*> LProjetil;
		Entidades::Personagens::Heroi *jog1;
		Entidades::Personagens::Heroi *jog2;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();
		void setJogadores(Entidades::Personagens::Heroi* j1, Entidades::Personagens::Heroi* j2);
		Entidades::Personagens::Heroi* getJogador2() { return jog2; }
		void includeEntidade(Entidades::Entidade* ent);
		void removeEntidade(Entidades::Entidade* ent);
		int veriColisao(Entidades::Entidade* ent,Entidades::Entidade* sl);
		void verificaObs();
		void verificaIni();
		void veriProjetil();
		void verificaObsIni();
		void verificaObsProjetil();
		void executar();
	}; 
}
