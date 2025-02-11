#pragma once
#include <list>
#include "../Obstaculos/Obstaculo.h"
#include "../Obstaculos/Plataforma.h"
#include "../Personagens/Inimigo.h"
#include "../Personagens/Heroi.h"
#include "../Entidade.h"
#include "../Projetil.h"

using namespace std;

namespace Gerenciadores {
	class Gerenciador_Colisoes
	{
	private:
		list<Obstaculos::Obstaculo*> LObst;
		list<Personagens::Inimigo*> LIni;
		list<Projetil*> LProjetil;
		Personagens::Heroi *jog1;
		Personagens::Heroi *jog2;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();
		void trocaFase();
		void setJogadores(Personagens::Heroi* j1, Personagens::Heroi* j2);
		Personagens::Heroi* getJogador2() { return jog2; }
		void includeEntidade(Entidade* ent);
		void removeEntidade(Entidade* ent);
		int veriColisao(Entidade* ent,Entidade* sl);
		void verificaObs();
		void verificaIni();
		void veriProjetil();
		void verificaObsIni();
		void verificaObsProjetil();
		void executar();
	}; 
}
