#pragma once
#include <list>
class Obstaculo;
class Slime;
class Entidade;
using namespace std;

namespace Gerenciadores {
	class Gerenciador_Colisoes
	{
	private:
		list<Obstaculo*> LObs;
		Slime *jog1;
		Slime *jog2;
		bool vertical;
		bool horizontal;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();
		void trocaFase();
		void setJogadores(Slime* j1, Slime* j2);
		void includeObstaculo(Obstaculo* obs);
		bool veriColisao(Entidade* ent,Slime* sl);
		void verificaObs();
		void executar();
	};
}
