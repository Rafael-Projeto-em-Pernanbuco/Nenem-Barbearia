
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <title>Nenem Barbearia</title>
  <style>
    body {
      background-color: #111; /* Preto Escuro */
      color: #fff;            /* Texto branco padrão */
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 0;
    }
    .container {
      max-width: 900px;
      margin: auto;
      padding: 20px;
    }
    header, footer {
      background-color: #333; /* Preto Claro */
      text-align: center;
      padding: 15px;
    }
    h1 {
      margin: 0;
      color: #fff;
    }
    #google_translate_element {
      text-align: right;
      margin-top: 5px;
    }
    .services {
      margin-top: 20px;
    }
    .service {
      background-color: #222;
      margin-bottom: 20px;
      padding: 15px;
      border-radius: 6px;
      display: flex;
      align-items: center;
    }
    .service img {
      width: 150px;
      height: auto;
      margin-right: 15px;
      border-radius: 4px;
    }
    .service-info {
      color: #000; /* Texto preto para serviços */
    }
    .service-info h2 {
      margin-top: 0;
      color: #000;
    }
    .social-buttons {
      margin: 20px 0;
      text-align: center;
    }
    .social-buttons a {
      margin: 0 8px;
      color: #fff;
      text-decoration: none;
      font-size: 1.3em;
    }
    .email-form, .chat-container {
      background-color: #222;
      padding: 15px;
      border-radius: 6px;
      margin-bottom: 20px;
    }
    .email-form input[type="email"], .email-form button {
      width: 100%;
      padding: 10px;
      margin: 8px 0;
      border: none;
      border-radius: 4px;
      box-sizing: border-box;
    }
    .email-form input[type="email"] {
      background-color: #333;
      color: #fff;
    }
    .email-form button {
      background-color: #555;
      color: #fff;
      cursor: pointer;
    }
    .email-form button:hover {
      background-color: #666;
    }
    #map {
      width: 100%;
      height: 300px;
      border-radius: 6px;
      margin-bottom: 20px;
    }
    .chat-container h3 {
      margin-top: 0;
      color: #fff;
    }
    .chat-container button {
      padding: 10px;
      background-color: #555;
      color: #fff;
      border: none;
      border-radius: 4px;
      cursor: pointer;
    }
    .chat-container button:hover {
      background-color: #666;
    }
    audio {
      margin-top: 10px;
      width: 100%;
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
        <img src="corte-homem.jpg" alt="Corte Masculino">
        <div class="service-info">
          <h2>Corte Masculino</h2>
          <p>Descrição: Corte simples, aparo de barba e finalização. Preço: R$ 35,00</p>
        </div>
      </div>
      <div class="service">
        <img src="barba.jpg" alt="Aparar Barba">
        <div class="service-info">
          <h2>Aparar Barba</h2>
          <p>Descrição: Alinhamento, contorno e hidratação. Preço: R$ 25,00</p>
        </div>
      </div>
      <div class="service">
        <img src="degrade.jpg" alt="Degradê">
        <div class="service-info">
          <h2>Degradê</h2>
          <p>Descrição: Degradê nas laterais com finalização. Preço: R$ 45,00</p>
        </div>
      </div>
    </section>

    <div class="social-buttons">
      <a href="#" title="WhatsApp">WhatsApp</a>
      <a href="#" title="Instagram">Instagram</a>
      <a href="#" title="Facebook">Facebook</a>
      <a href="#" title="Twitter">Twitter</a>
      <a href="#" title="Kwai">Kwai</a>
      <a href="#" title="Telegram">Telegram</a>
      <a href="#" title="TikTok">TikTok</a>
    </div>

    <div class="email-form">
      <h3>Cadastre seu e-mail</h3>
      <form>
        <input type="email" placeholder="Seu melhor e-mail" required>
        <button type="submit">Cadastrar</button>
      </form>
    </div>

    <div id="map">
      <iframe
        src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d..."
        width="100%" height="100%" style="border:0;" allowfullscreen="" loading="lazy">
      </iframe>
    </div>

    <div class="chat-container">
      <h3>Chat de Atendimento</h3>
      <button id="recordBtn">Gravar Mensagem de Áudio</button>
      <audio id="audioPlayback" controls hidden></audio>
    </div>

  </div>

  <footer>
    <p style="color: #fff;">Localização: Av. Raimundo Canuto, Nº 803 – Exu‑PE</p>
  </footer>

  <script>
    /** Google Tradutor */
    function googleTranslateElementInit() {
      new google.translate.TranslateElement({
        pageLanguage: 'pt',
        layout: google.translate.TranslateElement.InlineLayout.SIMPLE
      }, 'google_translate_element');
    }
  </script>
  <script src="//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit"></script>

  <script>
    // Gravação de áudio no chat
    const recordBtn = document.getElementById('recordBtn');
    const audioPlayback = document.getElementById('audioPlayback');
    let mediaRecorder, audioChunks = [];

    recordBtn.addEventListener('click', () => {
      if (!mediaRecorder || mediaRecorder.state === 'inactive') {
        navigator.mediaDevices.getUserMedia({ audio: true })
          .then(stream => {
            mediaRecorder = new MediaRecorder(stream);
            mediaRecorder.start();
            recordBtn.textContent = 'Parar Gravação';
            audioChunks = [];

            mediaRecorder.ondataavailable = event => audioChunks.push(event.data);

            mediaRecorder.onstop = () => {
              const audioBlob = new Blob(audioChunks, { type: 'audio/mp3' });
              const audioURL = URL.createObjectURL(audioBlob);
              audioPlayback.src = audioURL;
              audioPlayback.hidden = false;
            };
          })
          .catch(err => alert('Erro ao acessar microfone: ' + err));
      } else {
        mediaRecorder.stop();
        recordBtn.textContent = 'Gravar Mensagem de Áudio';
      }
    });
  </script>

</body>
</html>
