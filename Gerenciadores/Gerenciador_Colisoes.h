#pragma once
#include <list>
#include "../Obstaculos/Obstaculo.h"
#include "../Obstaculos/Plataforma.h"
#include "../Personagens/Inimigo.h"
#include "../Personagens/Slime.h"
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
		Personagens::Slime *jog1;
		Personagens::Slime *jog2;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();
		void trocaFase();
		void setJogadores(Personagens::Slime* j1, Personagens::Slime* j2);
		Personagens::Slime* getJogador2() { return jog2; }
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
