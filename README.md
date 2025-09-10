<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <title>Nenem Barbearia</title>
  <style>
    body {
      background-color: #111; /* Preto Escuro */
      color: #eee;            /* Branco Claro */
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 0;
    }
    .container {
      padding: 20px;
      max-width: 800px;
      margin: auto;
    }
    header, footer {
      background-color: #333; /* Preto Claro */
      padding: 15px;
      text-align: center;
    }
    h1 {
      color: #fff;
      margin-bottom: 10px;
    }
    .services {
      display: flex;
      flex-wrap: wrap;
    }
    .service {
      flex: 1 1 45%;
      margin: 10px;
      background-color: #222;
      padding: 10px;
      border-radius: 8px;
    }
    .service img {
      max-width: 100%;
      border-radius: 5px;
    }
    .social-buttons a {
      margin: 0 5px;
      color: #eee;
      text-decoration: none;
      font-size: 1.2em;
    }
    .chat-container, .email-form {
      margin-top: 20px;
      background-color: #222;
      padding: 15px;
      border-radius: 8px;
    }
    input[type="email"], button {
      padding: 8px;
      margin: 5px 0;
      width: 100%;
      box-sizing: border-box;
      border: none;
      border-radius: 4px;
    }
    input[type="email"] {
      background-color: #333;
      color: #fff;
    }
    button {
      background-color: #555;
      color: #fff;
      cursor: pointer;
    }
    button:hover {
      background-color: #666;
    }
    #map {
      width: 100%;
      height: 300px;
      margin-top: 20px;
      border-radius: 8px;
    }
    #google_translate_element {
      text-align: right;
      margin: 10px;
    }
  </style>
</head>
<body>
  <header>
    <h1>Nenem Barbearia</h1>
    <div id="google_translate_element"></div>
  </header>

  <div class="container">
    <section class="services">
      <div class="service">
        <h2>Corte Tradicional</h2>
        <img src="corte-tradicional.jpg" alt="Corte Tradicional">
        <p>Descrição do corte tradicional – R$XX,00</p>
      </div>
      <div class="service">
        <h2>Baldeado</h2>
        <img src="baldeado.jpg" alt="Baldeado">
        <p>Descrição do baldeado – R$YY,00</p>
      </div>
      <!-- Adicione mais serviços conforme necessário -->
    </section>

    <div class="social-buttons">
      <a href="#"><strong>WhatsApp</strong></a>
      <a href="#"><strong>Instagram</strong></a>
      <a href="#"><strong>Facebook</strong></a>
      <a href="#"><strong>Twitter</strong></a>
      <a href="#"><strong>Kwai</strong></a>
      <a href="#"><strong>Telegram</strong></a>
      <a href="#"><strong>TikTok</strong></a>
    </div>

    <div class="chat-container">
      <h3>Chat de Atendimento Online</h3>
      <p>Espaço para chat com gravação de áudio (implemente via JavaScript / servidor)</p>
      <button>Gravar Mensagem de Áudio</button>
    </div>

    <div class="email-form">
      <h3>Cadastre seu E-mail</h3>
      <form>
        <input type="email" placeholder="Seu e-mail">
        <button type="submit">Cadastrar</button>
      </form>
    </div>

    <div id="map">
      <!-- Mapa Google embed será carregado aqui -->
      <iframe
        src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d... coloque aqui o código _embed_ referente ao endereço completo"
        width="100%" height="100%" style="border:0;" allowfullscreen="" loading="lazy">
      </iframe>
    </div>

  </div>

  <footer>
    <p>Localização: Av. Raimundo Canuto, Nº 803 – Exu‑PE</p>
  </footer>

  <!-- SCRIPT do Google Tradutor (widget simples) -->
  <script type="text/javascript">
    function googleTranslateElementInit() {
      new google.translate.TranslateElement({pageLanguage: 'pt', layout: google.translate.TranslateElement.InlineLayout.SIMPLE}, 'google_translate_element');
    }
  </script>
  <script src="//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit"></script>
</body>
</html>
