<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Yokai Slayer</title>
  <style>
    body {
      background-image: url('https://www.transparenttextures.com/patterns/wood-pattern.png'); /* leve textura */
      background-color: #fdf6e3;
      font-family: "Noto Serif JP", serif;
      color: #2c1f0f;
      margin: 0;
      padding: 0;
    }

    header {
      background-color: #9c2919;
      color: #fff;
      padding: 20px;
      text-align: center;
      font-size: 2.5em;
      letter-spacing: 2px;
      border-bottom: 5px solid #5e150d;
    }

    .container {
      max-width: 900px;
      margin: 40px auto;
      padding: 20px;
      background-color: rgba(255, 255, 255, 0.95);
      border: 3px solid #9c2919;
      border-radius: 12px;
      box-shadow: 0 0 20px rgba(156, 41, 25, 0.3);
    }

    h2 {
      color: #7b1c14;
      border-bottom: 2px dashed #d47a6a;
      padding-bottom: 5px;
    }

    ul {
      list-style-type: "⛩️ ";
      padding-left: 20px;
    }

    .creditos {
      background-color: #fbeee0;
      border-left: 5px solid #9c2919;
      padding: 15px;
      margin-top: 30px;
      font-style: italic;
    }

    a {
      color: #9c2919;
      text-decoration: none;
    }

    a:hover {
      text-decoration: underline;
    }

    footer {
      text-align: center;
      font-size: 0.9em;
      color: #666;
      padding: 20px 0;
    }
  </style>
  <link href="https://fonts.googleapis.com/css2?family=Noto+Serif+JP&display=swap" rel="stylesheet">
</head>
<body>

  <header>Yokai Slayer</header>

  <div class="container">
    <h2>Sobre o jogo</h2>
    <p><strong>Yokai Slayer</strong> é um jogo de plataforma 2D com temática folclórica japonesa, desenvolvido por estudantes de Engenharia de Computação e Sistemas de Informação da UTFPR. Com jogabilidade para um ou dois jogadores, você enfrentará inimigos místicos enquanto explora fases desafiadoras como a <em>Floresta Profunda</em> e a <em>Caverna Obscura</em>. O objetivo é derrotar todos os chefes e se tornar o verdadeiro caçador de yokais!</p>

    <p>Este projeto foi desenvolvido como trabalho final da disciplina de Técnicas de Programação, com foco em programação orientada a objetos em C++, utilizando a biblioteca gráfica SFML.</p>

    <h2>Destaques</h2>
    <ul>
      <li>Dois modos de jogo: 1 ou 2 jogadores simultâneos</li>
      <li>2 fases únicas: Floresta e Caverna, com inimigos e obstáculos distintos</li>
      <li>Inimigos variados: lobos, samurais espectrais e yokais chefões</li>
      <li>Sistema de salvamento e leaderboard</li>
      <li>Obstáculos interativos: rios, espinhos e plataformas</li>
      <li>Pontuação dinâmica com ranking entre jogadores</li>
    </ul>

    <h2>Tecnologias e conceitos aplicados</h2>
    <ul>
      <li>C++ com Orientação a Objetos</li>
      <li>Biblioteca gráfica SFML</li>
      <li>Diagrama de Classes em UML</li>
      <li>Herança múltipla e em vários níveis</li>
      <li>Classes abstratas e métodos virtuais</li>
      <li>Polimorfismo e sobrecarga de operadores</li>
      <li>Persistência de dados com arquivos JSON</li>
      <li>Templates (STL) com <code>std::vector</code>, <code>std::list</code> e <code>set</code></li>
      <li>Sistema de colisão e movimentação física com gravidade</li>
    </ul>

    <h2>📸 Imagens do Jogo</h2>
    <p><em>(Adicione aqui capturas de tela ou vídeos do jogo)</em></p>

    <h2>Desenvolvido por</h2>
    <p>
      Camila Miranda Marani – <a href="https://github.com/Camilamima">@Camilamima</a><br>
      Giulia de Souza Leite – <a href="https://github.com/giulia-souza">@giulia-souza</a>
    </p>

    <div class="creditos">
      <p>Agradecemos ao professor Dr. Jean M. Simão e aos monitores da disciplina, além do grupo PET-ECO (UTFPR) pelo suporte, materiais e oficinas.</p>
      <p>Sprites e recursos visuais foram retirados de fontes gratuitas e creditadas no relatório completo.</p>
    </div>
  </div>

  <footer>
    &copy; 2025 Yokai Slayer – UTFPR
  </footer>

</body>
</html>
