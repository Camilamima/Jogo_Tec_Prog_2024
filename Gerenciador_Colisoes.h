#pragma once
#include <list>
class Plataforma;
class Slime;
class Inimigo;
class Entidade;
using namespace std;

namespace Gerenciadores {
	class Gerenciador_Colisoes
	{
	private:
		list<Plataforma*> LPlat;
		list<Inimigo*> LIni;
		Slime *jog1;
		Slime *jog2;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();
		void trocaFase();
		void setJogadores(Slime* j1, Slime* j2);
		void includeObstaculo(Plataforma* plat);
		void includeInimigo(Inimigo* ini);
		int veriColisao(Entidade* ent,Slime* sl);
		void verificaObs();
		void verificaIni();
		void executar();
	};
}
